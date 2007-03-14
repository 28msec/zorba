/*
 * $Id: XMLDecoderFactory.java,v 1.4 2004/07/08 08:03:04 yuvalo Exp $
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
import com.bluecast.io.CharsetDecoder;
import  java.io.UnsupportedEncodingException;
import  java.util.HashMap;


/**
 * Factory class for creating CharsetDecoders that also
 * convert carriage returns to linefeeds and check for invalid XML characters,
 * as per the XML 1.0 specification.
 *
 * @author Yuval Oren, yuval@bluecast.com
 * @version $Revision: 1.4 $
 */
public class XMLDecoderFactory {
    private static HashMap decoders = new HashMap();
    static {
        UTF8XMLDecoder utf8 = new UTF8XMLDecoder();
        ASCIIXMLDecoder ascii = new ASCIIXMLDecoder();
        ISO8859_1XMLDecoder iso8859 = new ISO8859_1XMLDecoder();
        UnicodeBigXMLDecoder utf16be = new UnicodeBigXMLDecoder();
        UnicodeLittleXMLDecoder utf16le = new UnicodeLittleXMLDecoder();
        decoders.put("UTF-8", utf8);
        decoders.put("UTF8", utf8);
        decoders.put("US-ASCII", ascii);
        decoders.put("ASCII", ascii);
        decoders.put("ISO-8859-1", iso8859);
        decoders.put("ISO8859_1", iso8859);
        decoders.put("UTF-16LE", utf16le);
        decoders.put("UNICODELITTLE", utf16le);
        decoders.put("UNICODELITTLEUNMARKED", utf16le);
        decoders.put("UTF-16BE", utf16be);
        decoders.put("UTF-16", utf16be);
        decoders.put("UNICODEBIG", utf16be);
        decoders.put("UNICODEBIGUNMARKED", utf16be);
    }

    static public XMLDecoder createDecoder (String encoding) throws UnsupportedEncodingException {
        XMLDecoder d = (XMLDecoder)decoders.get(encoding.toUpperCase());
        if (d != null)
            return  d.newXMLDecoder();
        else
            throw  new UnsupportedEncodingException("Encoding '" + encoding
                    + "' not supported");
    }
}



