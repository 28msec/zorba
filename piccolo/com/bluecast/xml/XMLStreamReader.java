/*
 * $Id: XMLStreamReader.java,v 1.7 2004/07/11 09:37:37 yuvalo Exp $
 *
 * (C) Copyright 2002-2004 by Yuval Oren. All rights reserved.
 *
 *  Licensed under the Apache License, Version 2.0 (the "License");
 *  you may not use this file except in compliance with the License.
 *  You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 *  Unless required by applicable law or agreed to in writing, software
 *  distributed under the License is distributed on an "AS IS" BASIS,
 *  WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 *  See the License for the specific language governing permissions and
 *  limitations under the License.
 */


package  com.bluecast.xml;

import  java.io.*;
import  com.bluecast.io.*;
import  java.util.*;


/**
 * A Reader for XML documents and streams. This class automatically determines
 * the proper character set to use based on Byte Order Marks and XML
 * declarations.
 *
 * @author Yuval Oren, yuval@bluecast.com
 * @version $Revision: 1.7 $
 */
final public class XMLStreamReader extends XMLInputReader {
    private static final int BYTE_BUFFER_SIZE = 8192;
    private XMLDecoder decoder;
    private int minBytesPerChar,maxBytesPerChar;
    private InputStream in;
    private int[] decodeResult = new int[2];
    private String encoding;
    private boolean useDeclaredEncoding;
    private boolean rewindDeclaration;
    private char[] cbuf = new char[MAX_XML_DECL_CHARS];
    private byte[] bbuf = new byte[BYTE_BUFFER_SIZE];
    private int cbufPos, cbufEnd, bbufPos, bbufEnd;
    private boolean eofReached;
    // How many characters we should read to parse the <?xml...?> declaration
    private static final int MAX_XML_DECL_CHARS = 100;

    private FastStreamDecoder fastStreamDecoder = new FastStreamDecoder();
    private JavaStreamDecoder javaStreamDecoder = null;

    private XMLStreamDecoder activeStreamDecoder;

    /**
     * Create an XMLStreamReader without providing an InputStream yet.
     * You must call reset() before using.
     */
    public XMLStreamReader () {
    }

    /**
     * Creates an XMLStreamReader.
     *
     * @param     in the InputStream
     * @param     rewindDeclaration a value of false will skip past any
     *            XML declaration. True will dish out the entire document.
     */
    public XMLStreamReader (InputStream in, boolean rewindDeclaration) throws IOException
    {
        this(in, null, rewindDeclaration);
    }

    /**
     * Creates an XMLStreamReader while specifying a character encoding.
     */
    public XMLStreamReader (InputStream in, String encoding,
                            boolean rewindDeclaration) throws IOException
    {
        reset(in, encoding, rewindDeclaration);
    }

    /**
     * Reuses this XMLStreamReader for a different InputStream.
     */
    public void reset (InputStream in, String encoding,
                       boolean rewindDeclaration) throws IOException {
        super.resetInput();
        this.in = in;
        eofReached = false;
        this.rewindDeclaration = rewindDeclaration;
        useDeclaredEncoding = false;
        bbufPos = bbufEnd = 0;
        cbufPos = cbufEnd = 0;
        activeStreamDecoder = fastStreamDecoder;
        fillByteBuffer();
        // If we've been given a character set, use it.
        if (encoding != null) {
            this.encoding = getJavaCharset(encoding);

            // If it's Unicode we need to find out which-endian
            // Per the unicode.org FAQ, default to big-endian
            if (this.encoding.equals("Unicode")) {
              this.encoding = guessEncoding();
              if (this.encoding == null
                  || !(this.encoding.equals("UnicodeLittle")))
                this.encoding = "UnicodeBig";
            }
        }
        else {
            this.encoding = guessEncoding();
            if (this.encoding == null) {
                useDeclaredEncoding = true;
                this.encoding = "UTF-8";        // Default to UTF-8
            }
        }
        setEncoding(this.encoding);
        processXMLDecl();
    }

    /** Returns the character set being used by the reader. Note that the
     *  encoding in the XML declaration is ignored if it is not needed to
     *  determine the character set.
     */
    public String getEncoding () {
        return  encoding;
    }


    public void close () throws IOException {
        eofReached = true;
        bbufPos = bbufEnd = cbufPos = cbufEnd = 0;
        if (in != null)
            in.close();
    }

    public void reset () throws IOException {
        super.resetInput();
        in.reset();
        bbufPos = bbufEnd = cbufPos = cbufEnd = 0;
    }


    public void mark (int readAheadLimit) throws IOException {
        throw  new UnsupportedOperationException("mark() not supported");
    }

    public boolean markSupported () {
        return  false;
    }

    public int read () throws IOException {
        return activeStreamDecoder.read();
    }

    public int read (char[] destbuf) throws IOException {
        return  read(destbuf, 0, destbuf.length);
    }

    public int read (char[] destbuf, int off, int len) throws IOException {
        return activeStreamDecoder.read(destbuf,off,len);
    }

    public boolean ready() throws IOException {
        return activeStreamDecoder.ready();
    }

    public long skip (long n) throws IOException {
        return activeStreamDecoder.skip(n);
    }


    private void setEncoding (String encoding) throws IOException {
        try {
            this.encoding = encoding;
            decoder = XMLDecoderFactory.createDecoder(encoding);
            minBytesPerChar = decoder.minBytesPerChar();
            maxBytesPerChar = decoder.maxBytesPerChar();
        }
        catch (UnsupportedEncodingException e) {
            // We don't have a decoder; try Java's built-in one
            if (javaStreamDecoder == null)
                javaStreamDecoder = new JavaStreamDecoder();
            activeStreamDecoder = javaStreamDecoder;
        }

        activeStreamDecoder.reset();
    }

    private int fillByteBuffer () throws IOException {
        int bytesLeft = bbufEnd - bbufPos;
        if (bytesLeft > 0)
            System.arraycopy(bbuf, bbufPos, bbuf, 0, bytesLeft);

        bbufPos = 0;
        bbufEnd = bytesLeft;


        // Don't block I/O;  only get as many bytes as are available
        int bytesAvailable = in.available();

        if (bytesAvailable == 0 && bytesLeft == 0) {
            bytesAvailable = 1; // But always get at least 1 byte
        }

        int bytesToRead = Math.min(BYTE_BUFFER_SIZE-bbufEnd,bytesAvailable);
        int bytesRead = 0;

        if (bbufEnd < BYTE_BUFFER_SIZE && (bytesRead = in.read(bbuf, bbufEnd,
                bytesToRead)) != -1) {
            bbufEnd += bytesRead;
        }
        if (bytesRead == -1)
            eofReached = true;
        return  bytesRead;
    }
    static private HashMap charsetTable = new HashMap(31);
    static {
        charsetTable.put("EBCDIC-CP-US", "Cp037");
        charsetTable.put("EBCDIC-CP-CA", "Cp037");
        charsetTable.put("EBCDIC-CP-NL", "Cp037");
        charsetTable.put("EBCDIC-CP-WT", "Cp037");
        charsetTable.put("EBCDIC-CP-DK", "Cp277");
        charsetTable.put("EBCDIC-CP-NO", "Cp277");
        charsetTable.put("EBCDIC-CP-FI", "Cp278");
        charsetTable.put("EBCDIC-CP-SE", "Cp278");
        charsetTable.put("EBCDIC-CP-IT", "Cp280");
        charsetTable.put("EBCDIC-CP-ES", "Cp284");
        charsetTable.put("EBCDIC-CP-GB", "Cp285");
        charsetTable.put("EBCDIC-CP-FR", "Cp297");
        charsetTable.put("EBCDIC-CP-AR1", "Cp420");
        charsetTable.put("EBCDIC-CP-GR", "Cp423");
        charsetTable.put("EBCDIC-CP-HE", "Cp424");
        charsetTable.put("EBCDIC-CP-BE", "Cp500");
        charsetTable.put("EBCDIC-CP-CH", "Cp500");
        charsetTable.put("EBCDIC-CP-ROECE", "Cp870");
        charsetTable.put("EBCDIC-CP-YU", "Cp870");
        charsetTable.put("EBCDIC-CP-IS", "Cp871");
        charsetTable.put("EBCDIC-CP-TR", "Cp905");
        charsetTable.put("EBCDIC-CP-AR2", "Cp918");
        charsetTable.put("UTF-16", "Unicode");
        charsetTable.put("ISO-10646-UCS-2", "Unicode");

        charsetTable.put("ANSI_X3.4-1986", "ASCII");
        charsetTable.put("ASCII", "ASCII");
        charsetTable.put("CP367", "ASCII");
        charsetTable.put("CSASCII", "ASCII");
        charsetTable.put("IBM-367", "ASCII");
        charsetTable.put("IBM367", "ASCII");
        charsetTable.put("ISO-IR-6", "ASCII");
        charsetTable.put("ISO646-US", "ASCII");
        charsetTable.put("ISO_646.IRV:1991", "ASCII");
        charsetTable.put("US", "ASCII");
        charsetTable.put("US-ASCII", "ASCII");
        charsetTable.put("BIG5", "BIG5");
        charsetTable.put("CSBIG5", "BIG5");
        charsetTable.put("CP037", "CP037");
        charsetTable.put("CSIBM037", "CP037");
        charsetTable.put("IBM-37", "CP037");
        charsetTable.put("IBM037", "CP037");
        charsetTable.put("CP1026", "CP1026");
        charsetTable.put("CSIBM1026", "CP1026");
        charsetTable.put("IBM-1026", "CP1026");
        charsetTable.put("IBM1026", "CP1026");
        charsetTable.put("CP1047", "CP1047");
        charsetTable.put("IBM-1047", "CP1047");
        charsetTable.put("IBM1047", "CP1047");
        charsetTable.put("CCSID01140", "CP1140");
        charsetTable.put("CP01140", "CP1140");
        charsetTable.put("IBM-1140", "CP1140");
        charsetTable.put("IBM01140", "CP1140");
        charsetTable.put("CCSID01141", "CP1141");
        charsetTable.put("CP01141", "CP1141");
        charsetTable.put("IBM-1141", "CP1141");
        charsetTable.put("IBM01141", "CP1141");
        charsetTable.put("CCSID01142", "CP1142");
        charsetTable.put("CP01142", "CP1142");
        charsetTable.put("IBM-1142", "CP1142");
        charsetTable.put("IBM01142", "CP1142");
        charsetTable.put("CCSID01143", "CP1143");
        charsetTable.put("CP01143", "CP1143");
        charsetTable.put("IBM-1143", "CP1143");
        charsetTable.put("IBM01143", "CP1143");
        charsetTable.put("CCSID01144", "CP1144");
        charsetTable.put("CP01144", "CP1144");
        charsetTable.put("IBM-1144", "CP1144");
        charsetTable.put("IBM01144", "CP1144");
        charsetTable.put("CCSID01145", "CP1145");
        charsetTable.put("CP01145", "CP1145");
        charsetTable.put("IBM-1145", "CP1145");
        charsetTable.put("IBM01145", "CP1145");
        charsetTable.put("CCSID01146", "CP1146");
        charsetTable.put("CP01146", "CP1146");
        charsetTable.put("IBM-1146", "CP1146");
        charsetTable.put("IBM01146", "CP1146");
        charsetTable.put("CCSID01147", "CP1147");
        charsetTable.put("CP01147", "CP1147");
        charsetTable.put("IBM-1147", "CP1147");
        charsetTable.put("IBM01147", "CP1147");
        charsetTable.put("CCSID01148", "CP1148");
        charsetTable.put("CP01148", "CP1148");
        charsetTable.put("IBM-1148", "CP1148");
        charsetTable.put("IBM01148", "CP1148");
        charsetTable.put("CCSID01149", "CP1149");
        charsetTable.put("CP01149", "CP1149");
        charsetTable.put("IBM-1149", "CP1149");
        charsetTable.put("IBM01149", "CP1149");
        charsetTable.put("WINDOWS-1250", "CP1250");
        charsetTable.put("WINDOWS-1251", "CP1251");
        charsetTable.put("WINDOWS-1252", "CP1252");
        charsetTable.put("WINDOWS-1253", "CP1253");
        charsetTable.put("WINDOWS-1254", "CP1254");
        charsetTable.put("WINDOWS-1255", "CP1255");
        charsetTable.put("WINDOWS-1256", "CP1256");
        charsetTable.put("WINDOWS-1257", "CP1257");
        charsetTable.put("WINDOWS-1258", "CP1258");
        charsetTable.put("CP273", "CP273");
        charsetTable.put("CSIBM273", "CP273");
        charsetTable.put("IBM-273", "CP273");
        charsetTable.put("IBM273", "CP273");
        charsetTable.put("CP277", "CP277");
        charsetTable.put("CSIBM277", "CP277");
        charsetTable.put("IBM-277", "CP277");
        charsetTable.put("IBM277", "CP277");
        charsetTable.put("CP278", "CP278");
        charsetTable.put("CSIBM278", "CP278");
        charsetTable.put("IBM-278", "CP278");
        charsetTable.put("IBM278", "CP278");
        charsetTable.put("CP280", "CP280");
        charsetTable.put("CSIBM280", "CP280");
        charsetTable.put("IBM-280", "CP280");
        charsetTable.put("IBM280", "CP280");
        charsetTable.put("CP284", "CP284");
        charsetTable.put("CSIBM284", "CP284");
        charsetTable.put("IBM-284", "CP284");
        charsetTable.put("IBM284", "CP284");
        charsetTable.put("CP285", "CP285");
        charsetTable.put("CSIBM285", "CP285");
        charsetTable.put("IBM-285", "CP285");
        charsetTable.put("IBM285", "CP285");
        charsetTable.put("CP290", "CP290");
        charsetTable.put("CSIBM290", "CP290");
        charsetTable.put("EBCDIC-JP-KANA", "CP290");
        charsetTable.put("IBM-290", "CP290");
        charsetTable.put("IBM290", "CP290");
        charsetTable.put("CP297", "CP297");
        charsetTable.put("CSIBM297", "CP297");
        charsetTable.put("IBM-297", "CP297");
        charsetTable.put("IBM297", "CP297");
        charsetTable.put("CP420", "CP420");
        charsetTable.put("CSIBM420", "CP420");
        charsetTable.put("IBM-420", "CP420");
        charsetTable.put("IBM420", "CP420");
        charsetTable.put("CP424", "CP424");
        charsetTable.put("CSIBM424", "CP424");
        charsetTable.put("IBM-424", "CP424");
        charsetTable.put("IBM424", "CP424");
        charsetTable.put("437", "CP437");
        charsetTable.put("CP437", "CP437");
        charsetTable.put("CSPC8CODEPAGE437", "CP437");
        charsetTable.put("IBM-437", "CP437");
        charsetTable.put("IBM437", "CP437");
        charsetTable.put("CP500", "CP500");
        charsetTable.put("CSIBM500", "CP500");
        charsetTable.put("IBM-500", "CP500");
        charsetTable.put("IBM500", "CP500");
        charsetTable.put("CP775", "CP775");
        charsetTable.put("CSPC775BALTIC", "CP775");
        charsetTable.put("IBM-775", "CP775");
        charsetTable.put("IBM775", "CP775");
        charsetTable.put("850", "CP850");
        charsetTable.put("CP850", "CP850");
        charsetTable.put("CSPC850MULTILINGUAL", "CP850");
        charsetTable.put("IBM-850", "CP850");
        charsetTable.put("IBM850", "CP850");
        charsetTable.put("852", "CP852");
        charsetTable.put("CP852", "CP852");
        charsetTable.put("CSPCP852", "CP852");
        charsetTable.put("IBM-852", "CP852");
        charsetTable.put("IBM852", "CP852");
        charsetTable.put("855", "CP855");
        charsetTable.put("CP855", "CP855");
        charsetTable.put("CSIBM855", "CP855");
        charsetTable.put("IBM-855", "CP855");
        charsetTable.put("IBM855", "CP855");
        charsetTable.put("857", "CP857");
        charsetTable.put("CP857", "CP857");
        charsetTable.put("CSIBM857", "CP857");
        charsetTable.put("IBM-857", "CP857");
        charsetTable.put("IBM857", "CP857");
        charsetTable.put("CCSID00858", "CP858");
        charsetTable.put("CP00858", "CP858");
        charsetTable.put("IBM-858", "CP858");
        charsetTable.put("IBM00858", "CP858");
        charsetTable.put("860", "CP860");
        charsetTable.put("CP860", "CP860");
        charsetTable.put("CSIBM860", "CP860");
        charsetTable.put("IBM-860", "CP860");
        charsetTable.put("IBM860", "CP860");
        charsetTable.put("861", "CP861");
        charsetTable.put("CP-IS", "CP861");
        charsetTable.put("CP861", "CP861");
        charsetTable.put("CSIBM861", "CP861");
        charsetTable.put("IBM-861", "CP861");
        charsetTable.put("IBM861", "CP861");
        charsetTable.put("862", "CP862");
        charsetTable.put("CP862", "CP862");
        charsetTable.put("CSPC862LATINHEBREW", "CP862");
        charsetTable.put("IBM-862", "CP862");
        charsetTable.put("IBM862", "CP862");
        charsetTable.put("863", "CP863");
        charsetTable.put("CP863", "CP863");
        charsetTable.put("CSIBM863", "CP863");
        charsetTable.put("IBM-863", "CP863");
        charsetTable.put("IBM863", "CP863");
        charsetTable.put("CP864", "CP864");
        charsetTable.put("CSIBM864", "CP864");
        charsetTable.put("IBM-864", "CP864");
        charsetTable.put("IBM864", "CP864");
        charsetTable.put("865", "CP865");
        charsetTable.put("CP865", "CP865");
        charsetTable.put("CSIBM865", "CP865");
        charsetTable.put("IBM-865", "CP865");
        charsetTable.put("IBM865", "CP865");
        charsetTable.put("866", "CP866");
        charsetTable.put("CP866", "CP866");
        charsetTable.put("CSIBM866", "CP866");
        charsetTable.put("IBM-866", "CP866");
        charsetTable.put("IBM866", "CP866");
        charsetTable.put("CP-AR", "CP868");
        charsetTable.put("CP868", "CP868");
        charsetTable.put("CSIBM868", "CP868");
        charsetTable.put("IBM-868", "CP868");
        charsetTable.put("IBM868", "CP868");
        charsetTable.put("CP-GR", "CP869");
        charsetTable.put("CP869", "CP869");
        charsetTable.put("CSIBM869", "CP869");
        charsetTable.put("IBM-869", "CP869");
        charsetTable.put("IBM869", "CP869");
        charsetTable.put("CP870", "CP870");
        charsetTable.put("CSIBM870", "CP870");
        charsetTable.put("IBM-870", "CP870");
        charsetTable.put("IBM870", "CP870");
        charsetTable.put("CP871", "CP871");
        charsetTable.put("CSIBM871", "CP871");
        charsetTable.put("IBM-871", "CP871");
        charsetTable.put("IBM871", "CP871");
        charsetTable.put("CP918", "CP918");
        charsetTable.put("CSIBM918", "CP918");
        charsetTable.put("IBM-918", "CP918");
        charsetTable.put("IBM918", "CP918");
        charsetTable.put("CCSID00924", "CP924");
        charsetTable.put("CP00924", "CP924");
        charsetTable.put("EBCDIC-LATIN9--EURO", "CP924");
        charsetTable.put("IBM-924", "CP924");
        charsetTable.put("IBM00924", "CP924");
        charsetTable.put("CSEUCPKDFMTJAPANESE", "EUCJIS");
        charsetTable.put("EUC-JP", "EUCJIS");
        charsetTable.put("EXTENDED_UNIX_CODE_PACKED_FORMAT_FOR_JAPANESE", "EUCJIS");
        charsetTable.put("GB18030", "GB18030");
        charsetTable.put("CSGB2312", "GB2312");
        charsetTable.put("GB2312", "GB2312");
        charsetTable.put("ISO-2022-CN", "ISO2022CN");
        charsetTable.put("CSISO2022KR", "ISO2022KR");
        charsetTable.put("ISO-2022-KR", "ISO2022KR");
        charsetTable.put("CP819", "ISO8859_1");
        charsetTable.put("CSISOLATIN1", "ISO8859_1");
        charsetTable.put("IBM-819", "ISO8859_1");
        charsetTable.put("IBM819", "ISO8859_1");
        charsetTable.put("ISO-8859-1", "ISO8859_1");
        charsetTable.put("ISO-IR-100", "ISO8859_1");
        charsetTable.put("ISO_8859-1", "ISO8859_1");
        charsetTable.put("L1", "ISO8859_1");
        charsetTable.put("LATIN1", "ISO8859_1");
        charsetTable.put("CSISOLATIN2", "ISO8859_2");
        charsetTable.put("ISO-8859-2", "ISO8859_2");
        charsetTable.put("ISO-IR-101", "ISO8859_2");
        charsetTable.put("ISO_8859-2", "ISO8859_2");
        charsetTable.put("L2", "ISO8859_2");
        charsetTable.put("LATIN2", "ISO8859_2");
        charsetTable.put("CSISOLATIN3", "ISO8859_3");
        charsetTable.put("ISO-8859-3", "ISO8859_3");
        charsetTable.put("ISO-IR-109", "ISO8859_3");
        charsetTable.put("ISO_8859-3", "ISO8859_3");
        charsetTable.put("L3", "ISO8859_3");
        charsetTable.put("LATIN3", "ISO8859_3");
        charsetTable.put("CSISOLATIN4", "ISO8859_4");
        charsetTable.put("ISO-8859-4", "ISO8859_4");
        charsetTable.put("ISO-IR-110", "ISO8859_4");
        charsetTable.put("ISO_8859-4", "ISO8859_4");
        charsetTable.put("L4", "ISO8859_4");
        charsetTable.put("LATIN4", "ISO8859_4");
        charsetTable.put("CSISOLATINCYRILLIC", "ISO8859_5");
        charsetTable.put("CYRILLIC", "ISO8859_5");
        charsetTable.put("ISO-8859-5", "ISO8859_5");
        charsetTable.put("ISO-IR-144", "ISO8859_5");
        charsetTable.put("ISO_8859-5", "ISO8859_5");
        charsetTable.put("ARABIC", "ISO8859_6");
        charsetTable.put("ASMO-708", "ISO8859_6");
        charsetTable.put("CSISOLATINARABIC", "ISO8859_6");
        charsetTable.put("ECMA-114", "ISO8859_6");
        charsetTable.put("ISO-8859-6", "ISO8859_6");
        charsetTable.put("ISO-IR-127", "ISO8859_6");
        charsetTable.put("ISO_8859-6", "ISO8859_6");
        charsetTable.put("CSISOLATINGREEK", "ISO8859_7");
        charsetTable.put("ECMA-118", "ISO8859_7");
        charsetTable.put("ELOT_928", "ISO8859_7");
        charsetTable.put("GREEK", "ISO8859_7");
        charsetTable.put("GREEK8", "ISO8859_7");
        charsetTable.put("ISO-8859-7", "ISO8859_7");
        charsetTable.put("ISO-IR-126", "ISO8859_7");
        charsetTable.put("ISO_8859-7", "ISO8859_7");
        charsetTable.put("CSISOLATINHEBREW", "ISO8859_8");
        charsetTable.put("HEBREW", "ISO8859_8");
        charsetTable.put("ISO-8859-8", "ISO8859_8");
        charsetTable.put("ISO-8859-8-I", "ISO8859_8");
        charsetTable.put("ISO-IR-138", "ISO8859_8");
        charsetTable.put("ISO_8859-8", "ISO8859_8");
        charsetTable.put("CSISOLATIN5", "ISO8859_9");
        charsetTable.put("ISO-8859-9", "ISO8859_9");
        charsetTable.put("ISO-IR-148", "ISO8859_9");
        charsetTable.put("ISO_8859-9", "ISO8859_9");
        charsetTable.put("L5", "ISO8859_9");
        charsetTable.put("LATIN5", "ISO8859_9");
        charsetTable.put("CSISO2022JP", "JIS");
        charsetTable.put("ISO-2022-JP", "JIS");
        charsetTable.put("CSISO13JISC6220JP", "JIS0201");
        charsetTable.put("X0201", "JIS0201");
        charsetTable.put("CSISO87JISX0208", "JIS0208");
        charsetTable.put("ISO-IR-87", "JIS0208");
        charsetTable.put("X0208", "JIS0208");
        charsetTable.put("X0208DBIJIS_X0208-1983", "JIS0208");
        charsetTable.put("CSISO159JISX02121990", "JIS0212");
        charsetTable.put("ISO-IR-159", "JIS0212");
        charsetTable.put("X0212", "JIS0212");
        charsetTable.put("CSKOI8R", "KOI8_R");
        charsetTable.put("KOI8-R", "KOI8_R");
        charsetTable.put("EUC-KR", "KSC5601");
        charsetTable.put("CSWINDOWS31J", "MS932");
        charsetTable.put("WINDOWS-31J", "MS932");
        charsetTable.put("CSSHIFTJIS", "SJIS");
        charsetTable.put("MS_KANJI", "SJIS");
        charsetTable.put("SHIFT_JIS", "SJIS");
        charsetTable.put("TIS-620", "TIS620");
        charsetTable.put("UTF-16BE", "UNICODEBIG");
        charsetTable.put("UTF-16LE", "UNICODELITTLE");
        charsetTable.put("UTF-8", "UTF8");
    }

    // Get the java name for a possibly standard character set name.
    private String getJavaCharset (String charset) {
        if (charset == null)
            return  null;
        String xlated = (String)charsetTable.get(charset.toUpperCase());
        if (xlated != null)
            return  xlated;
        else
            return  charset;
    }

    // Guesses the encoding of a stream from the first 4 bytes
    // All bytes read will be "unread" back into the stream
    // Returns an encoding name or null if unknown
    private String guessEncoding ()  {
        if (bbufEnd < 4)
            return  null;
        switch (bbuf[0]) {
            case (byte)0xEF:
                if (bbuf[1] == (byte)0xBB && bbuf[2] == (byte)0xBF) {
                    bbufPos = 3;                // Skip the Byte Order Mark
                    return  "UTF-8";
                }
                else
                    return  null;
            case (byte)'<':                     // UTF-8/ASCII/etc, UTF-16LE, or UCS-4
                switch (bbuf[1]) {
                    case (byte)'?':
                        // UTF-8/ASCII/etc, but we're not sure which
                        if (bbuf[2] == (byte)0x78 && bbuf[3] == (byte)0x6D) {
                            useDeclaredEncoding = true;
                            return  "UTF-8";
                            // there are many other charsets that
                            // would fall into this
                        }
                        else
                            return  null;
                    case (byte)0x00:
                        if (bbuf[2] == (byte)'?' && bbuf[3] == (byte)0x00)
                            return  "UnicodeLittleUnmarked";
                        else if (bbuf[2] == (byte)0x00 && bbuf[3] == (byte)0x00)
                            return  "UCS-4";
                        else
                            return  null;
                    default:
                        return  null;
                }
            case (byte)0xFE:                    // UTF-16BE or UCS-4 unusual (3412)
                if (bbuf[1] == (byte)0xFF) {
                    if (bbuf[2] == (byte)0x00 && bbuf[3] == (byte)0x00) {
                        bbufPos = 4;            // Skip the Byte Order Mark
                        return  "UCS-4";        // Not supported by Java
                    }
                    else {
                        bbufPos = 2;            // Skip the Byte Order Mark
                        return  "UnicodeBig";
                    }
                }
                else
                    return  null;
            case (byte)0xFF:                    // UTF-16LE or UCS-4LE
                if (bbuf[1] == (byte)0xFE) {
                    if (bbuf[2] == (byte)0x00 && bbuf[3] == (byte)0x00) {
                        bbufPos = 4;            // Skip the Byte Order Mark
                        return  "UCS-4";        // LE, not supported by Java
                    }
                    else {
                        bbufPos = 2;            // Skip the Byte Order Mark
                        return  "UnicodeLittle";
                    }
                }
                else
                    return  null;
            case (byte)0x00:                    // UCS-4BE or UCS-4 unusual (2143),
                // or if there's no BOM, UTF-16BE or UCS-4
                switch (bbuf[1]) {
                    case (byte)0x00:
                        if (bbuf[2] == (byte)0xFE && bbuf[3] == (byte)0xFF) {
                            bbufPos = 4;        // Skip the Byte Order Mark
                            return  "UCS-4";                    // BE, unsupported by Java
                        }
                        else if (bbuf[2] == (byte)0xFF && bbuf[3] == (byte)0xFE) {
                            bbufPos = 4;        // Skip the Byte Order Mark
                            return  "UCS-4";                    // Unusual (2143)
                        }
                        // UCS-4 without a byte order mark
                        else if ((bbuf[2] == (byte)'<' && bbuf[3] == (byte)0x00)
                                || (bbuf[2] == (byte)0x00 && bbuf[3] == (byte)'<'))
                            return  "UCS-4";
                        else
                            return  null;
                    case (byte)'<':             // UCS-4 or UTF-16BE
                        if (bbuf[2] == (byte)0x00 && bbuf[3] == (byte)'?')
                            return  "UnicodeBigUnmarked";
                        else if (bbuf[2] == (byte)0x00 && bbuf[3] == (byte)0x00)
                            return  "UCS-4";
                        else
                            return  null;
                    default:
                        return  null;
                }
            case (byte)0x4C:                    // EBCDIC
                if (bbuf[1] == (byte)0x6F && bbuf[2] == (byte)0xA7 && bbuf[3]
                        == (byte)0x94) {
                    useDeclaredEncoding = true;
                    return  "Cp037";
                }
                else
                    return  null;
            default:            // Unknown
                useDeclaredEncoding = true;
                return  null;
        }
    }

    /* Read [max] characters, parse the <?xml...?> tag
     * push it back onto the stream. Create a reader. Then, if there was
     * no error parsing the declaration, eat up the declaration.
     */
    private void processXMLDecl () throws IOException {
        int initialBBufPos = bbufPos;
        // Convert the byte buffer to characters
        decoder.decodeXMLDecl(bbuf, bbufPos, bbufEnd - bbufPos,
                       cbuf, cbufPos, cbuf.length,
                decodeResult);
        bbufPos += decodeResult[0];
        cbufEnd = decodeResult[1];

        int numCharsParsed = parseXMLDeclaration(cbuf,0,cbufEnd);

        if (numCharsParsed > 0) {
            // Declaration found and parsed

            String declaredEncoding = getJavaCharset(getXMLDeclaredEncoding());

            // Skip the XML declaration unless told otherwise
            if (!rewindDeclaration)
                cbufPos += numCharsParsed;

            // If another encoding was specified, use it instead of the guess.
            if (useDeclaredEncoding
                && (declaredEncoding != null)
                && !declaredEncoding.equalsIgnoreCase(encoding)) {

                cbufPos = cbufEnd = 0;
                decoder.reset();


                if (rewindDeclaration)
                    bbufPos = initialBBufPos;
                else
                    bbufPos = numCharsParsed*minBytesPerChar;

                setEncoding(declaredEncoding);
            }
        }
    }


    private interface XMLStreamDecoder {
        public int read() throws IOException;
        public int read(char[] destbuf,int off, int len) throws IOException;
        public boolean ready() throws IOException;
        public long skip(long n) throws IOException;
        public void reset() throws IOException;
    }

    private class FastStreamDecoder implements XMLStreamDecoder {
        public FastStreamDecoder() { }

        public void reset() { }

        public int read () throws IOException {
            if (cbufEnd - cbufPos > 0)
                return  (int)cbuf[cbufPos++];
            else {
                cbufPos = cbufEnd = 0;
                cbufEnd = read(cbuf, cbufPos, MAX_XML_DECL_CHARS);
                if (cbufEnd > 0)
                    return  (int)cbuf[cbufPos++];
                else
                    return  -1;
            }
        }


        public int read (char[] destbuf, int off, int len) throws IOException {
            int charsRead = 0;
            // First copy any characters from the character buffer
            if (cbufEnd - cbufPos > 0) {
                int numToRead = Math.min(cbufEnd - cbufPos, len - charsRead);
                if (numToRead > 0) {
                    System.arraycopy(cbuf, cbufPos, destbuf, off, numToRead);
                    charsRead += numToRead;
                    cbufPos += numToRead;
                }
            }
            if (charsRead < len) {
                if (bbufEnd - bbufPos < maxBytesPerChar) {
                    fillByteBuffer();
                    if (bbufEnd - bbufPos < minBytesPerChar)
                        return  (charsRead <=0? -1 : charsRead);
                }
                decoder.decode(bbuf, bbufPos, bbufEnd - bbufPos, destbuf, off +
                        charsRead, len - charsRead, decodeResult);
                bbufPos += decodeResult[0];
                charsRead += decodeResult[1];
            }
            return  ((charsRead == 0 && eofReached) ? -1 : charsRead);
        }

        public boolean ready () throws IOException {
            return  ((cbufEnd - cbufPos > 0) || (bbufEnd - bbufPos > maxBytesPerChar)
                    || (in.available() > 0));
        }

        public long skip (long n) throws IOException {
            long skipped = 0;
            if (cbufEnd - cbufPos > 0) {
                skipped = Math.min((long)cbufEnd - cbufPos, n);
                cbufPos += skipped;
            }
            while (skipped < n) {
                cbufPos = 0;
                cbufEnd = read(cbuf, 0, MAX_XML_DECL_CHARS);
                if (cbufEnd > 0) {
                    cbufPos = (int)Math.min((long)cbufEnd, n - skipped);
                    skipped += cbufPos;
                }
                else {
                    cbufEnd = 0;
                    return  skipped;
                }
            }
            return  skipped;
        }
    }


    private class JavaStreamDecoder implements XMLStreamDecoder {
        private Reader reader;
        char[] oneCharBuffer = new char[1];
        boolean sawCR;

        public JavaStreamDecoder() throws IOException {
        }

        public void reset() throws IOException {
            sawCR = false;

            if (bbufEnd - bbufPos > 0) {
                PushbackInputStream pbIn = new PushbackInputStream(in,bbufEnd-bbufPos);
                pbIn.unread(bbuf,bbufPos,bbufEnd-bbufPos);
                reader = new InputStreamReader(pbIn,encoding);
            }
            else {
                reader = new InputStreamReader(in,encoding);
            }
        }

        public int read() throws IOException {
            while (true) {
                int c = read(oneCharBuffer,0,1);
                if (c > 0)
                    return oneCharBuffer[0];
                else
                if (c < 0)
                    return c;
            }
        }

        public int read(char[] destbuf,int off, int len) throws IOException {
            int numChars = reader.read(destbuf,off,len);
            int outpos = off;
            int inpos;
            char c;

            if (numChars < 0)
                return numChars;

            for (int i=0; i < numChars; i++) {
                inpos = i + off;
                c = destbuf[inpos];

                if (c >= 0x20) {
                    if ((c <= 0xD7FF) ||
                       (c >= 0xE000 && c <= 0xFFFD) ||
                       (c >= 0x10000 && c <= 0x10FFFF)) {
                        sawCR = false;
                        if (inpos != outpos)
                            destbuf[outpos] = c;

                        outpos++;
                    }
                    else
                        throw new IllegalCharException(
                            "Illegal XML Character: 0x"+Integer.toHexString(c));
                }
                else {
                    switch (c) {
                        case '\n':
                            if (sawCR) {
                                sawCR = false;
                            }
                            else
                                destbuf[outpos++] = '\n';
                            break;

                        case '\r':
                            sawCR = true;
                            destbuf[outpos++] = '\n';
                            break;

                        case '\t':
                            destbuf[outpos++] = '\t';
                            break;

                        default:
                            System.out.println("Char: " + c + " [" + (int)c + "]");

                            throw new IllegalCharException(
                            "Illegal XML character: 0x"
                                + Integer.toHexString(c));
                    }
                }
            }

            return outpos - off;
        }
        public boolean ready() throws IOException {
            return reader.ready();
        }

        public long skip(long n) throws IOException {
            long skipped = 0;
            while (skipped < n) {
                cbufEnd = read(cbuf, 0, (int)Math.min(n,MAX_XML_DECL_CHARS));
                if (cbufEnd > 0)
                    skipped += cbufEnd;
                else
                    return  skipped;
            }
            return  skipped;
        }
    }
}



