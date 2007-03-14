/*
 * $Id: XMLReaderReader.java,v 1.5 2004/07/11 09:37:37 yuvalo Exp $
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
 * A Reader for XML documents and streams. This class prepares a Reader
 * source for XML processing by converting CR/LF patterns to LF and by
 * checking for illegal XML characters.
 *
 * @author Yuval Oren, yuval@bluecast.com
 * @version $Revision: 1.5 $
 */
final public class XMLReaderReader extends XMLInputReader {
    private static final int BUFFER_SIZE = 8192;
    private Reader in;
    private boolean rewindDeclaration;
    private char[] cbuf = new char[BUFFER_SIZE];
    private int cbufPos = 0, cbufEnd = 0;
    private boolean eofReached = false;
    private boolean sawCR = false;

    private char[] oneCharBuf = new char[1];

    /**
     * Create an XMLReaderReader without providing an input Reader yet.
     * You must call reset() before using.
     */
    public XMLReaderReader () { }

    /**
     * Creates an XMLReaderReader and resets the reader position
     * after reading the XML declaration.
     *
     * @param     in the input source
     */

    public XMLReaderReader (Reader in) throws IOException {
        this(in,true);
    }

    /**
     * Creates an XMLReaderReader.
     *
     * @param     in the input source
     * @param     rewindDeclaration a value of false will skip past any
     *            XML declaration. True will dish out the entire document.
     */
    public XMLReaderReader (Reader in, boolean rewindDeclaration)
    throws IOException {
        reset(in,rewindDeclaration);
    }

    public void reset(Reader in, boolean rewindDeclaration)
    throws IOException {

        super.resetInput();
        this.in = in;
        this.rewindDeclaration = rewindDeclaration;
        cbufPos = cbufEnd = 0;
        sawCR = false;
        eofReached = false;
        fillCharBuffer();
        processXMLDecl();
    }

    public void close () throws IOException {
        eofReached = true;
        cbufPos = cbufEnd = 0;
        if (in != null)
            in.close();
    }

    public void mark (int readAheadLimit) throws IOException {
        throw  new UnsupportedOperationException("mark() not supported");
    }

    public boolean markSupported () {
        return  false;
    }

    public int read () throws IOException {
        int n = read(oneCharBuf,0,1);
        if (n <= 0)
            return n;
        else
            return oneCharBuf[0];
    }

    public int read (char[] destbuf) throws IOException {
        return  read(destbuf, 0, destbuf.length);
    }

    public int read (char[] destbuf, int off, int len) throws IOException {
        int charsRead = 0;
        char c;

        while (charsRead < len) {
            if (cbufPos < cbufEnd)
                c = cbuf[cbufPos++];
            else 
            if (eofReached)
                break;
            else
            // Only fill the buffer once per call to avoid unintentional blocking
            // However, always read at least one character
            if (charsRead == 0 || in.ready()) {
                fillCharBuffer();
                continue;
            }
            else {
                // Reading any more would block. 
                break;
            }

            if (c >= 0x20) {
                if ((c <= 0xD7FF) ||
                    (c >= 0xE000 && c <= 0xFFFD) ||
                    (c >= 0x10000 && c <= 0x10FFFF) ) {

                    sawCR = false;
                    destbuf[off+ (charsRead++)] = c;
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
                            destbuf[off+ (charsRead++)] = '\n';
                        break;

                    case '\r':
                        sawCR = true;
                        destbuf[off+ (charsRead++)] = '\n';
                        break;

                    case '\t':
                        destbuf[off+ (charsRead++)] = '\t';
                        break;

                    default:
                        throw new IllegalCharException(
                        "Illegal XML character: 0x"
                            + Integer.toHexString(c));
                }
            }
        }
        return  ((charsRead == 0 && eofReached) ? -1 : charsRead);
    }

    public boolean ready () throws IOException {
        return  ((cbufEnd - cbufPos > 0) || in.ready() );
    }

    public void reset () throws IOException {
        super.resetInput();
        in.reset();
        cbufPos = cbufEnd = 0;
        sawCR = false;
        eofReached = false;
    }

    public long skip (long n) throws IOException {
        int charsRead = 0;
        char c;

        while (charsRead < n) {
            if (cbufPos < cbufEnd)
                c = cbuf[cbufPos++];
            else {
                if (eofReached)
                  break;
                fillCharBuffer();
                continue;
            }

            if (c >= 0x20) {
                if ((c <= 0xD7FF) ||
                    (c >= 0xE000 && c <= 0xFFFD) ||
                    (c >= 0x10000 && c <= 0x10FFFF) ) {

                    sawCR = false;
                    charsRead++;
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
                            charsRead++;
                        break;

                    case '\r':
                        sawCR = true;
                        charsRead++;
                        break;

                    case '\t':
                        charsRead++;
                        break;

                    default:
                        throw new IllegalCharException(
                        "Illegal XML character: 0x"
                            + Integer.toHexString(c));
                }
            }
        }
        return  ((charsRead == 0 && eofReached) ? -1 : charsRead);
    }

    private void fillCharBuffer () throws IOException {
        cbufPos = 0;
        cbufEnd = in.read(cbuf,0,BUFFER_SIZE);
        if (cbufEnd <= 0)
            eofReached = true;
    }


    /* Read [max] characters, parse the <?xml...?> tag
     * push it back onto the stream. Create a reader. Then, if there was
     * no error parsing the declaration, eat up the declaration.
     */
    private void processXMLDecl () throws IOException {
        int numCharsParsed = parseXMLDeclaration(cbuf,0,cbufEnd);

        if (numCharsParsed > 0) {
            // Declaration found and parsed

            // Skip the XML declaration unless told otherwise
            if (!rewindDeclaration)
                cbufPos += numCharsParsed;
        }
    }
}



