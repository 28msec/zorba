package com.bluecast.xml;

import org.xml.sax.*;
import org.xml.sax.helpers.*;
import com.bluecast.util.*;
import com.bluecast.io.*;
import java.util.*;
import java.io.*;

/*
 * $Id: PiccoloLexer.flex,v 1.7 2004/07/11 09:38:00 yuvalo Exp $
 *
 * 2003-06-10 - MODIFIED to provide access to <?xml?> definition
 *              and better track line numbers.
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


%%


%byaccj
%class PiccoloLexer
%final

%unicode

%yylexthrow{
  org.xml.sax.SAXException,
  FatalParsingException
%yylexthrow}


ws = [ \t\r\n]*

// XML Definitions

// VersionNum = [a-zA-Z0-9_.:\-]+
// EncName = [A-Za-z][A-Za-z0-9._\-]*
// S    =    [ \t\r\n]+
// Names    =    {Name} ({S} {Name})*
// Char    =    [\u9\uA\uD\u20-\uD7FF\uE000-\uFFFD\u10000-\u10FFFF]


NameChar    =    {Letter} | {Digit} | [\.\-_:] | {CombiningChar} | {Extender}
Name        =    ({Letter} | [_:]){NameChar}*
Nmtoken     =    ({NameChar})+

// For namespace handling
NCName = ({Letter} | "_"){NCNameChar}* // has no prefix
NCNameChar    =    {Letter} | {Digit} | [\.\-_] | {CombiningChar} | {Extender}


PubidChar = [\u0020\u000D\u000Aa-zA-Z0-9\-()+,./:=?;!*#@$_%]

Letter    =    {BaseChar} | {Ideographic}
BaseChar  =    [\u0041-\u005A\u0061-\u007A\u00C0-\u00D6\u00D8-\u00F6\u00F8-\u00FF\u0100-\u0131\u0134-\u013E\u0141-\u0148\u014A-\u017E\u0180-\u01C3\u01CD-\u01F0\u01F4-\u01F5\u01FA-\u0217\u0250-\u02A8\u02BB-\u02C1\u0386\u0388-\u038A\u038C\u038E-\u03A1\u03A3-\u03CE\u03D0-\u03D6\u03DA\u03DC\u03DE\u03E0\u03E2-\u03F3\u0401-\u040C\u040E-\u044F\u0451-\u045C\u045E-\u0481\u0490-\u04C4\u04C7-\u04C8\u04CB-\u04CC\u04D0-\u04EB\u04EE-\u04F5\u04F8-\u04F9\u0531-\u0556\u0559\u0561-\u0586\u05D0-\u05EA\u05F0-\u05F2\u0621-\u063A\u0641-\u064A\u0671-\u06B7\u06BA-\u06BE\u06C0-\u06CE\u06D0-\u06D3\u06D5\u06E5-\u06E6\u0905-\u0939\u093D\u0958-\u0961\u0985-\u098C\u098F-\u0990\u0993-\u09A8\u09AA-\u09B0\u09B2\u09B6-\u09B9\u09DC-\u09DD\u09DF-\u09E1\u09F0-\u09F1\u0A05-\u0A0A\u0A0F-\u0A10\u0A13-\u0A28\u0A2A-\u0A30\u0A32-\u0A33\u0A35-\u0A36\u0A38-\u0A39\u0A59-\u0A5C\u0A5E\u0A72-\u0A74\u0A85-\u0A8B\u0A8D\u0A8F-\u0A91\u0A93-\u0AA8\u0AAA-\u0AB0\u0AB2-\u0AB3\u0AB5-\u0AB9\u0ABD\u0AE0\u0B05-\u0B0C\u0B0F-\u0B10\u0B13-\u0B28\u0B2A-\u0B30\u0B32-\u0B33\u0B36-\u0B39\u0B3D\u0B5C-\u0B5D\u0B5F-\u0B61\u0B85-\u0B8A\u0B8E-\u0B90\u0B92-\u0B95\u0B99-\u0B9A\u0B9C\u0B9E-\u0B9F\u0BA3-\u0BA4\u0BA8-\u0BAA\u0BAE-\u0BB5\u0BB7-\u0BB9\u0C05-\u0C0C\u0C0E-\u0C10\u0C12-\u0C28\u0C2A-\u0C33\u0C35-\u0C39\u0C60-\u0C61\u0C85-\u0C8C\u0C8E-\u0C90\u0C92-\u0CA8\u0CAA-\u0CB3\u0CB5-\u0CB9\u0CDE\u0CE0-\u0CE1\u0D05-\u0D0C\u0D0E-\u0D10\u0D12-\u0D28\u0D2A-\u0D39\u0D60-\u0D61\u0E01-\u0E2E\u0E30\u0E32-\u0E33\u0E40-\u0E45\u0E81-\u0E82\u0E84\u0E87-\u0E88\u0E8A\u0E8D\u0E94-\u0E97\u0E99-\u0E9F\u0EA1-\u0EA3\u0EA5\u0EA7\u0EAA-\u0EAB\u0EAD-\u0EAE\u0EB0\u0EB2-\u0EB3\u0EBD\u0EC0-\u0EC4\u0F40-\u0F47\u0F49-\u0F69\u10A0-\u10C5\u10D0-\u10F6\u1100\u1102-\u1103\u1105-\u1107\u1109\u110B-\u110C\u110E-\u1112\u113C\u113E\u1140\u114C\u114E\u1150\u1154-\u1155\u1159\u115F-\u1161\u1163\u1165\u1167\u1169\u116D-\u116E\u1172-\u1173\u1175\u119E\u11A8\u11AB\u11AE-\u11AF\u11B7-\u11B8\u11BA\u11BC-\u11C2\u11EB\u11F0\u11F9\u1E00-\u1E9B\u1EA0-\u1EF9\u1F00-\u1F15\u1F18-\u1F1D\u1F20-\u1F45\u1F48-\u1F4D\u1F50-\u1F57\u1F59\u1F5B\u1F5D\u1F5F-\u1F7D\u1F80-\u1FB4\u1FB6-\u1FBC\u1FBE\u1FC2-\u1FC4\u1FC6-\u1FCC\u1FD0-\u1FD3\u1FD6-\u1FDB\u1FE0-\u1FEC\u1FF2-\u1FF4\u1FF6-\u1FFC\u2126\u212A-\u212B\u212E\u2180-\u2182\u3041-\u3094\u30A1-\u30FA\u3105-\u312C\uAC00-\uD7A3]
Ideographic =  [\u4E00-\u9FA5\u3007\u3021-\u3029]
CombiningChar= [\u0300-\u0345\u0360-\u0361\u0483-\u0486\u0591-\u05A1\u05A3-\u05B9\u05BB-\u05BD\u05BF\u05C1-\u05C2\u05C4\u064B-\u0652\u0670\u06D6-\u06DC\u06DD-\u06DF\u06E0-\u06E4\u06E7-\u06E8\u06EA-\u06ED\u0901-\u0903\u093C\u093E-\u094C\u094D\u0951-\u0954\u0962-\u0963\u0981-\u0983\u09BC\u09BE\u09BF\u09C0-\u09C4\u09C7-\u09C8\u09CB-\u09CD\u09D7\u09E2-\u09E3\u0A02\u0A3C\u0A3E\u0A3F\u0A40-\u0A42\u0A47-\u0A48\u0A4B-\u0A4D\u0A70-\u0A71\u0A81-\u0A83\u0ABC\u0ABE-\u0AC5\u0AC7-\u0AC9\u0ACB-\u0ACD\u0B01-\u0B03\u0B3C\u0B3E-\u0B43\u0B47-\u0B48\u0B4B-\u0B4D\u0B56-\u0B57\u0B82-\u0B83\u0BBE-\u0BC2\u0BC6-\u0BC8\u0BCA-\u0BCD\u0BD7\u0C01-\u0C03\u0C3E-\u0C44\u0C46-\u0C48\u0C4A-\u0C4D\u0C55-\u0C56\u0C82-\u0C83\u0CBE-\u0CC4\u0CC6-\u0CC8\u0CCA-\u0CCD\u0CD5-\u0CD6\u0D02-\u0D03\u0D3E-\u0D43\u0D46-\u0D48\u0D4A-\u0D4D\u0D57\u0E31\u0E34-\u0E3A\u0E47-\u0E4E\u0EB1\u0EB4-\u0EB9\u0EBB-\u0EBC\u0EC8-\u0ECD\u0F18-\u0F19\u0F35\u0F37\u0F39\u0F3E\u0F3F\u0F71-\u0F84\u0F86-\u0F8B\u0F90-\u0F95\u0F97\u0F99-\u0FAD\u0FB1-\u0FB7\u0FB9\u20D0-\u20DC\u20E1\u302A-\u302F\u3099\u309A]
Digit    =     [\u0030-\u0039\u0660-\u0669\u06F0-\u06F9\u0966-\u096F\u09E6-\u09EF\u0A66-\u0A6F\u0AE6-\u0AEF\u0B66-\u0B6F\u0BE7-\u0BEF\u0C66-\u0C6F\u0CE6-\u0CEF\u0D66-\u0D6F\u0E50-\u0E59\u0ED0-\u0ED9\u0F20-\u0F29]
Extender    =  [\u00B7\u02D0\u02D1\u0387\u0640\u0E46\u0EC6\u3005\u3031-\u3035\u309D-\u309E\u30FC-\u30FE]

%state XML_TAG
%state YYINITIAL_DIRECT ENTITYREF PI PI_WS
%state TAG TAG_START TAG_NS TAG_START_NS
%state TAG_VALUE TAG_VALUE_ENTITY TAG_VALUE_ENTITYREF
%state TAG_QSTRING_CDATA_BUFFERED TAG_SQSTRING_CDATA_BUFFERED
%state TAG_QSTRING_NORMALIZE TAG_SQSTRING_NORMALIZE
%state TAG_QSTRING_NORMALIZE_BUFFERED TAG_SQSTRING_NORMALIZE_BUFFERED
%state CLOSE_TAG CLOSE_TAG_NS

%state DTD
%state DTD_ATTLIST_ELEMENT DTD_ATT_NAME DTD_ATT_TYPE DTD_ENTITY_DECL DTD_NMTOKENS
%state DTD_COMMENT DTD_IGNORE DTD_PUBLIC_ID
%state DTD_TAG DTD_TAG_START DTD_TAG_VALUE_ENTITY DTD_TAG_VALUE_EXTERNAL_ENTITY
%state DTD_TAG_QSTRING_BUFFERED DTD_TAG_SQSTRING_BUFFERED
%state DTD_TAG_VALUE_STD_ENTITYREF DTD_TAG_VALUE_PARAM_ENTITYREF

%{

    // Variables accessible to parser class
    Piccolo parser = null;
    Entity currentEntity = null;
    CharStringConverter stringConverter = new CharStringConverter(200);
    EntityManager entityManager = new EntityManager();
    Stack entityStack = new Stack();
    AttributesHolder attribs = new AttributesHolder();

    // Generic character buffer, usually for attribute values
    char[] cbuf = new char[1024];
    int cbuflen;


    // Variables used to hold token values for the parser
    String stringValue;
    char[] oneCharBuffer = new char[1];
    char[] cdataBuffer;
    int cdataStart, cdataLength;

    // Variables used to maintain lexing and parsing states
    private LongStack entityStateStack = new LongStack(5);
    private StringStack entityNameStack = new StringStack(2);
    private String currentEntityName;
    private int prevEntityLexState;
    private boolean returnEntityEndToken;
    private boolean isParamEntity;
    private int entityBaseDepth;
    private boolean isEntityBeingParsed;
    private boolean inCdataSection;

    private int baseState; // Used for reporting CDATA directly from lexer
    private int prevState, piPrevState;
    private boolean isNamespaceDeclaration;
    private boolean entityWasSkipped;
    private int tagState;
    private int tagStartState;

    private boolean tokenizeInput;
    private StringStack tagStack = new StringStack(20);
    private boolean bypassPERefs;
    private boolean bypassGERefs;
    private boolean needsNormalization;
    private int tagType; // Piccolo.OPEN_TAG,EMPTY_TAG,CLOSE_TAG
    private boolean endOfTag;

    private HashMap elementMap = new HashMap();

    // Variables to hold element and attribute name components
    private ElementDefinition elementDefinition = null;
    private String elementURI;
    private String elementLocalName;
    private String elementQName;
    private String attributeURI;
    private String attributeLocalName;
    private String attributeQName;
    private String attributeValueType;

    // this is used for tracking the start line of the first character of a token
    // only works for start element for now
    //
    int tokenStartLine;

    // An array for marking whether we've seen an attribute as we parse the tag.
    // This is used to "fill in the holes" with default values specified in the DTD.
    private boolean[] defaultAttributeSpecified = new boolean[4];
    private int numAttributesDefined;

    private FastNamespaceSupport nsSupport = new FastNamespaceSupport();

    static private boolean[] asciiNameStartChars;
    static private boolean[] asciiNameStartCharsNS;
    static private boolean[] asciiNameChars;
    static private boolean[] asciiNameCharsNS;

    /************************************************************************
     * Initialization code
     ************************************************************************/

    static {
        calcAsciiTables();
    }

    public PiccoloLexer (Piccolo parser) {
        this.parser = parser;
        enableNamespaces(true);
    }

    /* Prepare the lexer to parse the given Entity. */
    public void reset(Entity entity) throws IOException, SAXException {
        try {
            setTokenize(true);
            tagStack.clear();

            // clear out any residual attributes from last parse
            attribs.clear();

            entityStack.clear();
            clearEntityState();
            elementMap.clear();
            currentEntity = entity;

            entityManager.clear();
            elementDefinition = null;
            if (!entity.isOpen())
                entity.open();

            if (parser.fNamespaces) {
                nsSupport.reset();
            }
            isNamespaceDeclaration=false;

            bypassPERefs=bypassGERefs=false;
            needsNormalization = false;
            entityWasSkipped = false;
            inCdataSection = false;
            cbuflen = cdataStart = cdataLength = 0;
            tagType = 0;
            prevState = piPrevState = 0;
            endOfTag = false;
            tokenStartLine=0;
            numAttributesDefined=0;

            yy_reader = null; // Don't close the reader as we reuse it.
            yyreset(entity.getReader());
        } catch (RecursionException e) {}
    }

    /************************************************************************
     * End Initialization code
     ************************************************************************/



    /************************************************************************
     * Methods providing service to Piccolo
     ************************************************************************/

    void enableNamespaces(boolean value) {
        if (value) {
            tagState = TAG_NS;
            tagStartState = TAG_START_NS;
        }
        else {
            tagState = TAG;
            tagStartState = TAG_START;
            elementURI = elementLocalName = "";
            attributeURI = attributeLocalName = "";
        }
    }

    /* Define an element as specified within a DTD */
    void defineElement (String name, ElementDefinition elem) {
        elementMap.put(name, elem);
    }

    ElementDefinition getElement (String name) {
        return  (ElementDefinition)elementMap.get(name);
    }

    public int getLineNumber () {
        return  yyline + 1;
    }

    public int getColumnNumber () {
        // return  yycolumn + 1;
        return -1;
    }

    /* Returns the public identified of the current entity */
    String getPublicID () {
        if (currentEntity != null)
            return  currentEntity.getPublicID();
        else
            return null;
    }

    /* Returns the system identifier of the current entity */
    String getSystemID () {
        if (currentEntity != null)
            return  currentEntity.getSystemID();
        else
            return null;
    }

    // give access to the info in the XML declaration
    String getVersion () {
        if (currentEntity != null)
            return  currentEntity.getXMLVersion();
        else
            return null;
    }

    String getEncoding () {
        if (currentEntity != null)
            return  currentEntity.getDeclaredEncoding();
        else
            return null;
    }

    /* Whether or not text and tags should be returned as tokens to
     * Piccolo or directly reported.
     * Note: when tokenization is on, tags are still reported to the
     * content handler, while text is left to the Piccolo class.
     */
    void setTokenize(boolean tokenize) {
        tokenizeInput = tokenize;
        baseState = (tokenize? YYINITIAL : YYINITIAL_DIRECT);
        int state = yystate();
        if (state == YYINITIAL || state == YYINITIAL_DIRECT)
            yybegin(baseState);
    }

    String normalizeValue(String s) {
        if (s == null || s.length() == 0)
            return s;

        char[] inbuf = s.toCharArray();
        int in_len = inbuf.length;
        int inpos = 0;

        char[] outbuf = new char[in_len];
        int outpos = 0;

        // Eliminate the leading whitespace
        while (inpos < in_len) {
            switch (inbuf[inpos]) {
                case ' ':
                case '\t':
                case '\n':
                case '\r':
                    inpos++;
                    continue;
                default:
                    break;
            }
            break;
        }

        while (inpos < in_len) {
            // Read a name token
            do {
                char c = inbuf[inpos++];
                switch (c) {
                    case ' ':
                    case '\t':
                    case '\n':
                    case '\r':
                        break;

                    default:
                        outbuf[outpos++] = c;
                        continue;
                }
                break;
            } while (inpos < in_len);

            // Condense the whitespace
            while (inpos < in_len) {
                char c = inbuf[inpos++];
                switch (c) {
                    case ' ':
                    case '\t':
                    case '\n':
                    case '\r':
                        continue;

                    default:
                        outbuf[outpos++] = ' ';
                        outbuf[outpos++] = c;
                        break;
                }
                break;
            }
        }

        return new String(outbuf,0,outpos);
    }

    void startCdata() throws SAXException {
        if (parser.lexHandler != null) {
            parser.lexHandler.startCDATA();
            inCdataSection = true;
        }
    }

    void endCdata() throws SAXException {
        if (parser.lexHandler != null) {
            parser.lexHandler.endCDATA();
            inCdataSection = false;
        }
    }


    /************************************************************************
     * End Methods providing service to Piccolo
     ************************************************************************/




    /************************************************************************
     * Methods used to return text and tokens to Piccolo
     ************************************************************************/

    // Append a character to our character buffer
    private void appendToCbuf (char c) {
        if (cbuf.length - cbuflen < 1) {
            char[] newcbuf = new char[2*(cbuf.length + 1)];
            System.arraycopy(cbuf, 0, newcbuf, 0, cbuflen);
            cbuf = newcbuf;
        }
        cbuf[cbuflen++] = c;
    }

    // Append a character array to our character buffer
    private void appendToCbuf (char[] ch, int start, int length) {
        if (length > 0) {
            if (cbuf.length - cbuflen < length) {
                char[] newcbuf = new char[2*(cbuf.length + length)];
                System.arraycopy(cbuf, 0, newcbuf, 0, cbuflen);
                cbuf = newcbuf;
            }
            System.arraycopy(ch, start, cbuf, cbuflen, length);
            cbuflen += length;
        }
    }

    // Clear the character buffer
    private void clearCbuf () {
        cbuflen = 0;
    }


    // Return a token with a String value to Piccolo
    private int stringToken (int token, String value) {
        stringValue = value;
        return  token;
    }

    // Return a token with a char[] value to Piccolo
    private int cdataToken (char[] buf, int start, int length) {
        return  cdataToken(Piccolo.CDATA, buf, start, length);
    }

    private int cdataToken (int token, char[] buf, int start, int length) {
        cdataBuffer = buf;
        cdataStart = start;
        cdataLength = length;
        return  token;
    }

    private int cdataToken (char c) {
        oneCharBuffer[0] = c;
        cdataBuffer = oneCharBuffer;
        cdataStart = 0;
        cdataLength = 1;
        return  Piccolo.CDATA;
    }

    /************************************************************************
     * End Methods used to return text and tokens to Piccolo
     ************************************************************************/



    /************************************************************************
     * Code used to parse XML without JFlex's help. We use this code to
     * parse the non-DTD portion of an XML document when namespaces is
     * turned off, because that parsing is simple enough that it is faster
     * to use hand-crafted switch statements than JFlex's transition tables.
     ************************************************************************/


    /* The driver for our non-JFlex XML parsing.
     * Return values:
     *      0 = break out of non-JFlex mode but do not return a token to
     *          Piccolo.
     *      non-zero = return this token value to Piccolo
     */
    private int parseXML() throws SAXException, IOException {

        if (parser.fNamespaces)
            return parseXMLNS();

        while(true) {
            parseCdata();
            parser.reportCdata(cdataBuffer,cdataStart,cdataLength);
            yynextAction();
            if (yystate() == tagStartState) {
                int token = parseTag();
                switch (token) {
                    case -1:
                        return 0;
                    case 0:
                        yynextAction();
                        break;
                    default:
                        return token;
                }
            }
            else
                return 0;
        }
    }


    // Same as parseXML but with namespaces
    private int parseXMLNS() throws SAXException, IOException {

        while(true) {
            parseCdata();
            parser.reportCdata(cdataBuffer,cdataStart,cdataLength);
            yynextAction();
            if (yystate() == tagStartState) { // No namespaces!
                int token = parseTagNS();
                switch (token) {
                    case -1:
                        return 0;
                    case 0:
                        yynextAction();
                        break;
                    default:
                        return token;
                }
            }
            else
                return 0;
        }
    }





    /* Parses an XML element when namespace processing is turned off.
     * Return values:
     *     -1  = we can't handle this tag. Break out of non-JFlex mode.
     *      0  = we finished processing this tag.
     *      Piccolo.CLOSE_TAG = this is the last ending tag. Return
     *         this token value to Piccolo.
     */
    private int parseTag() throws SAXException, IOException {

        int token;

        // Check the first character
        if ((yy_endRead-yy_markedPos) > 0) {
            int c = yy_buffer[yy_markedPos];
            switch (c) {
                case '?':
                case '!':
                    yybegin(tagStartState);
                    return -1; // Leave special tags for lex

                case '/':
                    return parseCloseTag();

                default:
                    return parseOpenTag();
            }
        }
        else
            return -1;
    }

    // Same as parseTag but with namespaces
    private int parseTagNS() throws SAXException, IOException {

        int token;

        // Check the first character
        if ((yy_endRead-yy_markedPos) > 0) {
            int c = yy_buffer[yy_markedPos];
            switch (c) {
                case '?':
                case '!':
                    yybegin(tagStartState);
                    return -1; // Leave special tags for lex

                case '/':
                    return parseCloseTagNS();

                default:
                    return parseOpenTagNS();
            }
        }
        else
            return -1;
    }




    private int parseOpenTag() throws SAXException, IOException  {
        // Get the element name first
        stringValue = parseElementName();
        if (stringValue == null) {
            yybegin(tagStartState);
            return -1;
        }


        for (int c = yy_buffer[yy_markedPos++];true;c = yynextChar()) {
            while (true) {

                if (c == '>') {
                    // yycolumn_next++;
//                    if (parser.fNamespaces) {
//                        nsSupport.pushContext();
//                        elementURI = nsSupport.getURI(elementURI);
//                    }
                    yybegin(baseState);
                    processSimpleElement(stringValue);
                    parser.reportStartTag(elementURI,elementLocalName,stringValue);
                    attribs.clear();
                    tagStack.push(stringValue);
                    tagType = Piccolo.OPEN_TAG;
                    if (tokenizeInput)
                        return Piccolo.OPEN_TAG;
                    else
                        return 0;
                }
                else
                if (c == '/') {
                    // yycolumn_next++;
                    c = yynextChar();
                    if (c  != '>')
                        throw fatalError("'/' should be followed by '>'");

                    // yycolumn_next++;
                    yybegin(baseState);

//                    if (parser.fNamespaces)
//                        elementURI = nsSupport.getURI(elementURI);

                    processSimpleElement(stringValue);
                    parser.reportStartTag(elementURI,elementLocalName,stringValue);
                    parser.reportEndTag(elementURI,elementLocalName,stringValue);
                    attribs.clear();

                    tagType = Piccolo.EMPTY_TAG;
                    if (tokenizeInput)
                        return Piccolo.EMPTY_TAG;
                    else
                        return 0;
                }
                else
                if (c == ' ' || c == '\t') {
                    // yycolumn_next++;
                }
                else
                if (c == '\n') {
                    yyline_next++;
                    // yycolumn_next = 0;
                }
                else {
                        yy_markedPos--;
                        prepareComplexElement(stringValue);

//                        if (parser.fNamespaces)
//                            nsSupport.pushContext();

                        return parseAttributes();
                }

                if ((yy_endRead-yy_markedPos) > 0)
                    c = yy_buffer[yy_markedPos++];
                else
                    break;
            }
        }
    }

    // Same as parseOpenTag but with namespaces
    private int parseOpenTagNS() throws SAXException, IOException  {
        // Get the element name first
        stringValue = parseElementNameNS();
        if (stringValue == null) {
            yybegin(tagStartState);
            return -1;
        }


        for (int c = yy_buffer[yy_markedPos++];true;c = yynextChar()) {
            while (true) {

                if (c == '>') {
                    // yycolumn_next++;
//                    if (parser.fNamespaces) {
                        nsSupport.pushContext();
                        elementURI = nsSupport.getURI(elementURI);
//                    }
                    yybegin(baseState);
                    processSimpleElement(stringValue);
                    parser.reportStartTag(elementURI,elementLocalName,stringValue);
                    attribs.clear();
                    tagStack.push(stringValue);
                    tagType = Piccolo.OPEN_TAG;
                    if (tokenizeInput)
                        return Piccolo.OPEN_TAG;
                    else
                        return 0;
                }
                else
                if (c == '/') {
                    // yycolumn_next++;
                    c = yynextChar();
                    if (c  != '>')
                        throw fatalError("'/' should be followed by '>'");

                    // yycolumn_next++;
                    yybegin(baseState);

//                    if (parser.fNamespaces)
                        elementURI = nsSupport.getURI(elementURI);

                    processSimpleElement(stringValue);
                    parser.reportStartTag(elementURI,elementLocalName,stringValue);
                    parser.reportEndTag(elementURI,elementLocalName,stringValue);
                    attribs.clear();
                    tagType = Piccolo.EMPTY_TAG;
                    if (tokenizeInput)
                        return Piccolo.EMPTY_TAG;
                    else
                        return 0;
                }
                else
                if (c == ' ' || c == '\t') {
                    // yycolumn_next++;
                }
                else
                if (c == '\n') {
                    yyline_next++;
                    // yycolumn_next = 0;
                }
                else {
                        yy_markedPos--;
                        prepareComplexElement(stringValue);

//                        if (parser.fNamespaces)
                            nsSupport.pushContext();

                        return parseAttributesNS();
                }

                if ((yy_endRead-yy_markedPos) > 0)
                    c = yy_buffer[yy_markedPos++];
                else
                    break;
            }
        }
    }






    /* Parse the attributes and remainder of an open (or empty) tag.
     * Return values:
     *     -1  = we can't handle this tag. Break out of non-JFlex mode.
     *      0  = we finished processing this tag.
     *      Piccolo.CLOSE_TAG = this is the last ending tag. Return
     *         this token value to Piccolo.
     */
    private int parseAttributes() throws SAXException, IOException {
        String name,value;
        yybegin(tagState);

        // loop through sets of Name, '=', Value
        int c = 0;

        endOfTag = false; // set to true when [/>] is hit after a literal
        while(!endOfTag) {
            if ((yy_endRead-yy_markedPos) > 0) {
                // Name
                parseAttributeName();
                if (attributeQName == null)
                    break;

                // '='
                int bufferLeft = (yy_endRead-yy_markedPos);
                loop_eq:
                while (bufferLeft-- > 0) {
                    switch (yy_buffer[yy_markedPos++]) {
                        case '=':
                            break loop_eq;

                        case ' ':
                        case '\t':
                            // yycolumn_next++;
                            break;

                        case '\n':
                            yyline_next++;
                            // yycolumn_next = 0;
                            break;

                        default:
                            // hit something weird; kick back to lex
                            yy_markedPos--;
                            yybegin(TAG_VALUE);
                            return -1;
                    }
                }
                if (bufferLeft < 0) {
                    yybegin(TAG_VALUE);
                    return -1;
                }


                // Whitespace, ' or " (to begin the value)
                value_loop:
                for (c = yynextChar(); c != YYEOF; c = yynextChar()) {
                    switch (c) {
                        case '"':
                            // yycolumn_next++;
                            parseQuotedTagValue();
                            if (yystate() != tagState)
                                return -1;
                            break value_loop;

                        case '\'':
                            // yycolumn_next++;
                            parseSingleQuotedTagValue();
                            if (yystate() != tagState)
                                return -1;
                            break value_loop;

                        case ' ':
                        case '\t':
                            // yycolumn_next++;
                            break;

                        case '\n':
                            yyline_next++;
                            // yycolumn_next = 0;
                            break;

                        default:
                            throw fatalError("Unexpected character encountered: '"
                                + (char)c + "'");
                    }
                }
                if (c == YYEOF)
                    throw fatalError("Unexpected end of file");
            }
            else {
                // ran out of buffer; kick back to lex
                return -1;
            }
        }


        // No more attributes; parse the end of the tag
        while ((yy_endRead-yy_markedPos) > 0) {
            switch (yy_buffer[yy_markedPos++]) {
                case '>':
                    // yycolumn_next++;
                    yybegin(baseState);
                    processComplexElement();

//                    if (parser.fNamespaces) {
//                        resolveNamespacePrefixes();
//                    }

                    parser.reportStartTag(elementURI,elementLocalName,stringValue);
                    tagStack.push(stringValue);
                    attribs.clear();
                    tagType = Piccolo.OPEN_TAG;
                    if (tokenizeInput)
                        return Piccolo.OPEN_TAG;
                    else
                        return 0;

                case '/':
                    // yycolumn_next++;
                    if ( (yynextChar()) != '>')
                        throw fatalError("'/' should be followed by '>'");
                    // yycolumn_next++;

                    yybegin(baseState);
                    processComplexElement();

//                    if (parser.fNamespaces) {
//                        resolveNamespacePrefixes();
//                        parser.reportStartTag(elementURI,elementLocalName,stringValue);
//                        parser.reportEndTag(elementURI,elementLocalName,stringValue);
//                        processNSContextEnd();
//                    }
//                    else {
                        parser.reportStartTag(elementURI,elementLocalName,stringValue);
                        parser.reportEndTag(elementURI,elementLocalName,stringValue);
//                    }


                    attribs.clear();
                    tagType = Piccolo.EMPTY_TAG;
                    if (tokenizeInput)
                        return Piccolo.EMPTY_TAG;
                    else
                        return 0;

                case ' ':
                case '\t':
                    // yycolumn_next++;
                    break;

                case '\n':
                    yyline_next++;
                    // yycolumn_next = 0;
                    break;

                default:
                    throw fatalError("Unexpected character: " + (char)c);
            }
        }
        // hit the end of the buffer
        return -1;
    }


  // Same as parseAttributes but with namespaces
  private int parseAttributesNS() throws SAXException, IOException {
        String name,value;
        yybegin(tagState);

        // loop through sets of Name, '=', Value
        int c = 0;

        endOfTag = false; // set to true when [/>] is hit after a literal
        while(!endOfTag) {
            if ((yy_endRead-yy_markedPos) > 0) {
                // Name
                parseAttributeNameNS();
                if (attributeQName == null)
                    break;

                // '='
                int bufferLeft = (yy_endRead-yy_markedPos);
                loop_eq:
                while (bufferLeft-- > 0) {
                    switch (yy_buffer[yy_markedPos++]) {
                        case '=':
                            break loop_eq;

                        case ' ':
                        case '\t':
                            // yycolumn_next++;
                            break;

                        case '\n':
                            yyline_next++;
                            // yycolumn_next = 0;
                            break;

                        default:
                            // hit something weird; kick back to lex
                            yy_markedPos--;
                            yybegin(TAG_VALUE);
                            return -1;
                    }
                }
                if (bufferLeft < 0) {
                    yybegin(TAG_VALUE);
                    return -1;
                }


                // Whitespace, ' or " (to begin the value)
                value_loop:
                for (c = yynextChar(); c != YYEOF; c = yynextChar()) {
                    switch (c) {
                        case '"':
                            // yycolumn_next++;
                            parseQuotedTagValue();
                            if (yystate() != tagState)
                                return -1;
                            break value_loop;

                        case '\'':
                            // yycolumn_next++;
                            parseSingleQuotedTagValue();
                            if (yystate() != tagState)
                                return -1;
                            break value_loop;

                        case ' ':
                        case '\t':
                            // yycolumn_next++;
                            break;

                        case '\n':
                            yyline_next++;
                            // yycolumn_next = 0;
                            break;

                        default:
                            throw fatalError("Unexpected character encountered: '"
                                + (char)c + "'");
                    }
                }
                if (c == YYEOF)
                    throw fatalError("Unexpected end of file");
            }
            else {
                // ran out of buffer; kick back to lex
                return -1;
            }
        }

        // No more attributes; parse the end of the tag
        while ((yy_endRead-yy_markedPos) > 0) {
            switch (yy_buffer[yy_markedPos++]) {
                case '>':
                    // yycolumn_next++;
                    yybegin(baseState);
                    processComplexElement();

//                    if (parser.fNamespaces) {
                        resolveNamespacePrefixes();
//                    }

                    parser.reportStartTag(elementURI,elementLocalName,stringValue);
                    tagStack.push(stringValue);
                    attribs.clear();
                    tagType = Piccolo.OPEN_TAG;
                    if (tokenizeInput)
                        return Piccolo.OPEN_TAG;
                    else
                        return 0;

                case '/':
                    // yycolumn_next++;
                    if ( (yynextChar()) != '>')
                        throw fatalError("'/' should be followed by '>'");
                    // yycolumn_next++;

                    yybegin(baseState);
                    processComplexElement();

//                    if (parser.fNamespaces) {
                        resolveNamespacePrefixes();
                        parser.reportStartTag(elementURI,elementLocalName,stringValue);
                        parser.reportEndTag(elementURI,elementLocalName,stringValue);
                        processNSContextEnd();
//                    }
//                    else {
//                        parser.reportStartTag(elementURI,elementLocalName,stringValue);
//                        parser.reportEndTag(elementURI,elementLocalName,stringValue);
//                    }


                    attribs.clear();
                    tagType = Piccolo.EMPTY_TAG;
                    if (tokenizeInput)
                        return Piccolo.EMPTY_TAG;
                    else
                        return 0;

                case ' ':
                case '\t':
                    // yycolumn_next++;
                    break;

                case '\n':
                    yyline_next++;
                    // yycolumn_next = 0;
                    break;

                default:
                    throw fatalError("Unexpected character: " + (char)c);
            }
        }
        // hit the end of the buffer
        return -1;
    }



    private void parseAttributeName() throws SAXException, IOException {

//        if (parser.fNamespaces) {
//            attributeURI = null;
//            isNamespaceDeclaration = false;
//        }


        // Skip leading whitespace and get the first char
        int c = yy_buffer[yy_markedPos++];
//        int localNameOffset=0;
        ws_loop:
        for (; true;
             c = yynextChar()) {

            while (true) {
                if (c==' '||c=='\t') {
                    // yycolumn_next++;
                }
                else
                if (c=='\n') {
                    yyline_next++;
                    // yycolumn_next = 0;
                }
                else
                if (c == '/') {
                    yy_markedPos--;
                    attributeQName = null;
                    return;
                }
                else
                if (c == '>') {
                    yy_markedPos--;
                    attributeQName = null;
                    return;
                }
                else if (isASCIINameStartChar(c)) {
                    // yycolumn_next++;
                    yy_startRead = yy_markedPos-1;
                    break ws_loop;
                }
//                else
//                if (c == ':') {
//                    if (parser.fNamespaces) {
//                        localNameOffset = yy_markedPos - yy_startRead;
//                        attributeURI = "";
//                    }
//                    break ws_loop;
//                }
                else {
                    // Something weird. unread the char and return
                    yy_markedPos--;
                    attributeQName = "";
                    return;
                }

                if ((yy_endRead-yy_markedPos) > 0)
                    c = yy_buffer[yy_markedPos++];
                else
                    break;
            }
        }

        // Read attribute name
        for (; true;
             c = yynextChar()) {

            while (true) {
                if (isASCIINameChar(c)) {
                    // yycolumn_next++;
                }
/*
                else
                if (c == ':') {
                    // yycolumn_next++;
                    if (parser.fNamespaces && attributeURI == null) {
                        // only the first ':' separates
                        attributeURI = stringConverter.convert(yy_buffer,
                                        yy_startRead,
                                        (yy_markedPos-1)-yy_startRead);
                        localNameOffset = yy_markedPos-yy_startRead;
                    }
                }
 */
                else {
                    yy_markedPos--;

/*
                    if (parser.fNamespaces) {
                        if (attributeURI == null)
                            attributeURI = "";

                        attributeLocalName
                            = yytext2(localNameOffset,
                                yy_markedPos-(yy_startRead+localNameOffset));
                        if (attributeURI == "xmlns" ||
                            attributeLocalName == "xmlns")
                            isNamespaceDeclaration = true;
                    }
 */
                    attributeQName = yytext2();
                    return;
                }

                if ((yy_endRead-yy_markedPos) > 0)
                    c = yy_buffer[yy_markedPos++];
                else
                    break;
            }
        }
    }


    // Same as parseAttributeName but with namespaces
    private void parseAttributeNameNS() throws SAXException, IOException {

//        if (parser.fNamespaces) {
            attributeURI = null;
            isNamespaceDeclaration = false;
//        }


        // Skip leading whitespace and get the first char
        int c = yy_buffer[yy_markedPos++];
        int localNameOffset=0;
        int bufferLeft = (yy_endRead-yy_markedPos);
        ws_loop:
        for (; true;
             c = yynextChar()) {

            while (true) {
                if (c==' '||c=='\t') {
                    // yycolumn_next++;
                }
                else
                if (c=='\n') {
                    yyline_next++;
                    // yycolumn_next = 0;
                }
                else
                if (c == '/') {
                    yy_markedPos--;
                    attributeQName = null;
                    return;
                }
                else
                if (c == '>') {
                    yy_markedPos--;
                    attributeQName = null;
                    return;
                }
                else if (isASCIINameStartChar(c)) {
                    // yycolumn_next++;
                    yy_startRead = yy_markedPos-1;
                    break ws_loop;
                }
                else
                if (c == ':') {
//                    if (parser.fNamespaces) {
                        localNameOffset = yy_markedPos - yy_startRead;
                        attributeURI = "";
//                    }
                    break ws_loop;
                }
                else {
                    // Something weird. unread the char and return
                    yy_markedPos--;
                    attributeQName = "";
                    return;
                }

                if ((yy_endRead-yy_markedPos) > 0)
                    c = yy_buffer[yy_markedPos++];
                else
                    break;
            }
        }

        // Read attribute name
        for (; true;
             c = yynextChar()) {

            while (true) {
                if (isASCIINameCharNS(c)) {
                    // yycolumn_next++;
                }
                else
                if (c == ':') {
                    // yycolumn_next++;
//                    if (parser.fNamespaces && attributeURI == null) {
                    if (attributeURI == null) {
                        // only the first ':' separates
                        attributeURI = stringConverter.convert(yy_buffer,
                                        yy_startRead,
                                        (yy_markedPos-1)-yy_startRead);
                        localNameOffset = yy_markedPos-yy_startRead;
                    }
                }
                else {
                    yy_markedPos--;

//                    if (parser.fNamespaces) {
                        if (attributeURI == null)
                            attributeURI = "";

                        attributeLocalName
                            = yytext2(localNameOffset,
                                yy_markedPos-(yy_startRead+localNameOffset));
                        if (attributeURI == "xmlns" ||
                            attributeLocalName == "xmlns")
                            isNamespaceDeclaration = true;
//                    }

                    attributeQName = yytext2();
                    return;
                }

                if ((yy_endRead-yy_markedPos) > 0)
                    c = yy_buffer[yy_markedPos++];
                else
                    break;
            }
        }
    }



    /* Parse a close tag. The element name starts at yy_buffer[yy_markedPos].
     * Return values:
     *     -1  = we can't handle this tag. Break out of non-JFlex mode.
     *      0  = we finished processing this tag.
     *      Piccolo.CLOSE_TAG = this is the last ending tag. Return
     *         this token value to Piccolo.
     */
    private int parseCloseTag() throws SAXException, IOException {
        yy_markedPos++; // skip the "/"
        // yycolumn_next++;

        stringValue = parseElementName();
        if (stringValue == null) {
            // We ran into trouble; kick it back to lex
            yybegin(tagStartState);
            yy_markedPos--; // unread the "/"
            // yycolumn_next--;
            return -1;
        }

        while ((yy_endRead-yy_markedPos) > 0) {
            char c = yy_buffer[yy_markedPos++];

            switch (c) {
                case '>':
                    // yycolumn_next++;
                    checkEndTag(stringValue);

//                    if (parser.fNamespaces) {
//                        parser.reportEndTag(elementURI,elementLocalName,stringValue);
//                        processNSContextEnd();
//                    }
//                    else {
                        parser.reportEndTag(elementURI,elementLocalName,stringValue);
//                    }

                    yybegin(baseState);
                    tagType = Piccolo.CLOSE_TAG;
                    if (tokenizeInput)
                        return Piccolo.CLOSE_TAG;
                    else
                        return 0;

                case ' ':
                case '\t':
                    // yycolumn_next++;
                    break;

                case '\n':
                    yyline_next++;
                    // yycolumn_next = 0;
                    break;

                default:
                    // Something that shouldn't be here
                    throw fatalError("Unexpected character encountered while in a closing tag: '"
                                    + c + "'");
            }
        }

        // We hit the end of the buffer; let lex continue
        yybegin(parser.fNamespaces? CLOSE_TAG_NS : CLOSE_TAG);
        return -1;
    }


  // Same as parseCloseTag but with namespaces
  private int parseCloseTagNS() throws SAXException, IOException {
        yy_markedPos++; // skip the "/"
        // yycolumn_next++;

        stringValue = parseElementNameNS();
        if (stringValue == null) {
            // We ran into trouble; kick it back to lex
            yybegin(tagStartState);
            yy_markedPos--; // unread the "/"
            // yycolumn_next--;
            return -1;
        }

        while ((yy_endRead-yy_markedPos) > 0) {
            char c = yy_buffer[yy_markedPos++];

            switch (c) {
                case '>':
                    // yycolumn_next++;
                    checkEndTag(stringValue);

//                    if (parser.fNamespaces) {
                            elementURI = nsSupport.getURI(elementURI);
                        parser.reportEndTag(elementURI,elementLocalName,stringValue);
                        processNSContextEnd();
//                    }
//                    else {
//                        parser.reportEndTag(elementURI,elementLocalName,stringValue);
//                    }

                    yybegin(baseState);
                    tagType = Piccolo.CLOSE_TAG;
                    if (tokenizeInput)
                        return Piccolo.CLOSE_TAG;
                    else
                        return 0;

                case ' ':
                case '\t':
                    // yycolumn_next++;
                    break;

                case '\n':
                    yyline_next++;
                    // yycolumn_next = 0;
                    break;

                default:
                    // Something that shouldn't be here
                    throw fatalError("Unexpected character encountered while in a closing tag: '"
                                    + c + "'");
            }
        }

        // We hit the end of the buffer; let lex continue
        yybegin(parser.fNamespaces? CLOSE_TAG_NS : CLOSE_TAG);
        return -1;
    }


    private String parseElementName() throws SAXException, IOException {
        yy_startRead = yy_markedPos;
//        int localNameOffset = 0;

//        if (parser.fNamespaces)
//            elementURI = null;


        // First character
        int c = yynextChar();

        if (isASCIINameStartChar(c)) {
            // yycolumn_next++;
        }
/*
        else
        if (c == ':') {
            // yycolumn_next++;
            if (parser.fNamespaces) {
                localNameOffset = 1;
                elementURI = "";
            }
        }
 */
        else {
            yybegin(tagStartState);
            yy_markedPos--;
            return null;
        }

        // The rest of the element name
        element_loop:
        while(true) {

            while ( (yy_endRead-yy_markedPos) > 0) {
                c = yy_buffer[yy_markedPos++];

                if (isASCIINameChar(c)) {
                    // yycolumn_next++;
                }
                else
                if (c == '>' || c == ' ' || c == '/')
                    break element_loop;
/*
                else
                if (c == ':') {
                    if (parser.fNamespaces && elementURI == null) { // only the first ':' separates
                        elementURI = stringConverter.convert(yy_buffer,
                                        yy_startRead,(yy_markedPos-yy_startRead)-1);
                        localNameOffset = (yy_markedPos-yy_startRead);
                    }
                }
 */
                else
                if (c == '\n' || c == '\t')
                    break element_loop;
                else {
                    yy_markedPos = yy_startRead;
                    return null;
                }
            }

            c = yynextChar();
            if (c < 0)
                throw fatalError("Unexpected end of file");
            yy_markedPos--;
        }
        yy_markedPos--;

//        if (parser.fNamespaces) {
//            elementLocalName = yytext2(localNameOffset,
//                                yy_markedPos-(yy_startRead+localNameOffset));
//        }

        return yytext2();
    }


    // Same as parseElementName but with namespaces enabled
    private String parseElementNameNS() throws SAXException, IOException {
        yy_startRead = yy_markedPos;
        int localNameOffset = 0;

//        if (parser.fNamespaces)
            elementURI = null;


        // First character
        int c = yynextChar();

        if (isASCIINameStartCharNS(c)) {
            // yycolumn_next++;
        }
        else
        if (c == ':') {
            // yycolumn_next++;
//            if (parser.fNamespaces) {
                localNameOffset = 1;
                elementURI = "";
//            }
        }
        else {
            yybegin(tagStartState);
            yy_markedPos--;
            return null;
        }

        // The rest of the element name
        element_loop:
        while (true) {

            while ( (yy_endRead-yy_markedPos) > 0) {
                c = yy_buffer[yy_markedPos++];

                if (isASCIINameCharNS(c)) {
                    // yycolumn_next++;
                }
                else
                if (c == '>' || c == ' ' || c == '/')
                    break element_loop;
                else
                if (c == ':') {
//                    if (parser.fNamespaces && elementURI == null) { // only the first ':' separates
                    if (elementURI == null) {
                        elementURI = stringConverter.convert(yy_buffer,
                                        yy_startRead,(yy_markedPos-yy_startRead)-1);
                        localNameOffset = (yy_markedPos-yy_startRead);
                    }
                }
                else
                if (c == '\n' || c == '\t')
                    break element_loop;
                else {
                    yy_markedPos = yy_startRead;
                    return null;
                }
            }
            c = yynextChar();
            if (c < 0)
                throw fatalError("Unexpected end of file");
            yy_markedPos--;

        }
        yy_markedPos--;

//        if (parser.fNamespaces) {
            elementLocalName = yytext2(localNameOffset,
                                yy_markedPos-(yy_startRead+localNameOffset));
//        }

        // TEMP
        if (localNameOffset == 0)
            return elementLocalName;
        else
            return yytext2();
    }


    // Build an array of booleans to tell us quickly if characters are valid "name" characters
    static private void calcAsciiTables() {
        asciiNameStartChars = new boolean[0x100];
        asciiNameStartCharsNS = new boolean[0x100];
        asciiNameChars = new boolean[0x100];
        asciiNameCharsNS = new boolean[0x100];

        for (int c=0; c < 0x100; c++) {
            asciiNameStartChars[c] =
                    ( (c>=0x61&&c<=0x7A)||(c==':')||(c>=0x41&&c<=0x5A)
                        ||(c=='_')
                        ||(c>=0xC0&&c<=0xD6)||(c>=0xD8&&c<=0xF6)
                        ||(c>=0xF8&&c<=0xFF) );

            asciiNameStartCharsNS[c] =
                    (c != ':' && asciiNameStartChars[c]);

            asciiNameChars[c] =
                    ( (c>=0x61&&c<=0x7A)||(c==':')||(c>=0x41&&c<=0x5A)
                        ||(c == '.')||(c=='-')||(c=='_')
                        ||(c == 0xB7)
                        ||(c>=0x30&&c<=0x39)||(c>=0xC0&&c<=0xD6)
                        ||(c>=0xD8&&c<=0xF6)||(c>=0xF8&&c<=0xFF) );

            asciiNameCharsNS[c] =
                    (c != ':' && asciiNameChars[c]);
        }
    }

    // Is this a valid name start character when not in namespace mode
    static private boolean isASCIINameStartChar(int c) {
        return ( c <= 0xFF && asciiNameStartChars[c]);
    }

    // Same but excludes the colon
    static private boolean isASCIINameStartCharNS(int c) {
        return ( c <= 0xFF && asciiNameStartCharsNS[c]);
    }


    // Is this a valid name character when not in namespace mode
    static private boolean isASCIINameChar(int c) {
        return ( c <= 0xFF && asciiNameChars[c]);
    }

    // Same but excludes the colon
    static private boolean isASCIINameCharNS(int c) {
        return ( c <= 0xFF && asciiNameCharsNS[c]);
    }



    /* Parses what may be whitespace.
     * Returns the token Piccolo.CDATA or Piccolo.WHITESPACE
     */
    private int parseWhitespace() throws SAXException, IOException {

        cdataBuffer = yy_buffer;
        cdataStart = yy_startRead;
        while ((yy_endRead-yy_markedPos) > 0) {

            int c = yy_buffer[yy_markedPos++];

            switch (c) {
                case ' ':
                case '\t':
                    //yycolumn_next++;
                    break;

                case '<':
                    tokenStartLine = yyline_next + 1;
                    // Report the CDATA and begin the tag
                    //yycolumn_next++;
                    yybegin(tagStartState);
                    cdataLength = (yy_markedPos-1) - yy_startRead;
                    yybegin(tagStartState);
                    return Piccolo.WHITESPACE;

                case '\n':
                    yyline_next++;
                    //yycolumn_next = 0;
                    break;

                case '&':
                    // An entity is not whitespace. Report as
                    // CDATA and go parse the entity reference.
                    //yycolumn_next++;
                    yybegin(ENTITYREF);
                    cdataLength = (yy_markedPos-1) - yy_startRead;
                    return Piccolo.CDATA;

                default:
                    // Got a character. Continue parsing as CDATA
                    //yycolumn_next++;
                    parseCdata();
                    return Piccolo.CDATA;
            }
        }

        // Getting here means we hit the end of the character buffer
        cdataLength = yy_markedPos - yy_startRead;
        return Piccolo.WHITESPACE;
    }


    /* Parses some CDATA (text content) */
    private void parseCdata() throws SAXException, IOException {

        cdataBuffer = yy_buffer;
        cdataStart = yy_startRead;
        while (yy_endRead > yy_markedPos) {

            int c = yy_buffer[yy_markedPos++];

            switch (c) {
                case '<':
                    // Report the CDATA and begin the tag
                    //yycolumn_next++;
                    yybegin(tagStartState);
                    cdataLength = (yy_markedPos-1) - yy_startRead;
                    tokenStartLine = yyline_next + 1;
                    return;

                case '\n':
                    yyline_next++;
                    //yycolumn_next = 0;
                    break;

                case '&':
                    // Report the CDATA and go parse the entity reference.
                    //yycolumn_next++;
                    yybegin(ENTITYREF);
                    cdataLength = (yy_markedPos-1) - yy_startRead;
                    return;

                case ']':
                    for (int numBrackets=1; true; ) {
                        if ((yy_endRead-yy_markedPos) >= 1)
                            c = yy_buffer[yy_markedPos++];
                        else {
                            parser.reportCdata(cdataBuffer,cdataStart,yy_markedPos-yy_startRead);
                            yynextAction();
                            c = yynextChar();
                            cdataBuffer = yy_buffer;
                            cdataStart = yy_startRead;
                        }

                        if (c == ']')
                            numBrackets++;
                        else
                        if (c == '>' && numBrackets >= 2)
                            throw fatalError("Illegal ']]>' construct in character data");
                        else {
                            if (c != YYEOF) {
                                yy_markedPos--;
                            }
                            break;
                        }
                    }
                    break;

                default:
                    //yycolumn_next++;
                    break;
            }
        }

        // Getting here means we hit the end of the character buffer
        cdataLength = yy_markedPos - yy_startRead;
    }


    /* Parses a <![CDATA[...]]> section */
    private void parseCdataSection() throws SAXException, IOException {

        yynextAction();

        while (true) {
            while (yy_endRead > yy_markedPos) {
                int c = yy_buffer[yy_markedPos++];

                switch (c) {
                    case ']':
                        bracket_loop:
                        for (int numBrackets=1; true; ) {
                            if (yy_endRead > yy_markedPos)
                                c = yy_buffer[yy_markedPos++];
                            else {
                                // Report everything up to the last 2 brackets, because they could be
                                // the end marker
                                int bracketsToKeep = Math.min(2,numBrackets);
                                yy_markedPos -= bracketsToKeep;
                                parser.reportCdata(yy_buffer,yy_startRead,yy_markedPos-yy_startRead);
                                yynextAction();
                                yy_markedPos += bracketsToKeep;
                                c = yynextChar();
                            }

                            if (c == ']')
                                numBrackets++;
                            else
                            if (c == '>' && numBrackets >= 2) {
                                int len = (yy_markedPos-3)-yy_startRead;
                                if (len > 0)
                                    parser.reportCdata(yy_buffer,yy_startRead,len);
                                return;
                            }
                            else if (c == YYEOF)
                                throw fatalError("Unexpected end of file in CDATA section");
                            else {
                                // this wasn't a closing CDATA marker
                                yy_markedPos--; // rescan the last character for linefeeds
                                break bracket_loop;
                            }
                        }
                        break;

                    case '\n':
                        yyline_next++;
                        //yycolumn_next = 0;
                        break;

                    default:
                        //yycolumn_next++;
                        break;
                }
            }
            if (yynextChar() == YYEOF)
                throw fatalError("Unexpected end of file in CDATA section");
            yy_markedPos--;
        }
    }





    /************************************************************************
     * End Code used to parse XML without JFlex's help.
     ************************************************************************/




    /************************************************************************
     * Methods to handle the parsing of parsed entities
     ************************************************************************/

    /*
     * Starts parsing the given external entity. When
     * the entity is fully parsed, the ENTITY_END token
     * will be returned, and parsing of the current entity will continue.
     */

    void pushEntity (String name, Entity entity, boolean isParamEntity, boolean returnEndToken)
    throws SAXException, IOException {
        pushEntity(name,entity,isParamEntity,returnEndToken,0);
    }

    void pushEntity (String name, Entity entity, boolean isParamEntity, boolean returnEndToken, int resumeLexState)
    throws SAXException, IOException {
        try {
            if (name != null)
                parser.reportStartEntity(name);


            entity.open();

            if (entity.isInternal()) {
                char[] valueBuffer = entity.charArrayValue();
                yypushBuffer(valueBuffer, 0, valueBuffer.length);
            }
            else {
                yypushStream(entity.getReader());
            }

            entityStack.push(currentEntity);
            currentEntity = entity;
            pushEntityState(name,isParamEntity,returnEndToken,resumeLexState);

        } catch (RecursionException e) {
            throw  fatalError("Recursive reference to entity '"
                + entity.getSystemID() + "'");
        }
    }

    void pushEntity (String name, String pubID, String sysID, boolean isParamEntity, boolean returnEndToken)
    throws SAXException, IOException {
        pushEntity(name,pubID,sysID,isParamEntity,returnEndToken,0);
    }

    void pushEntity (String name, String pubID, String sysID, boolean isParamEntity,
                     boolean returnEndToken, int resumeLexState) throws SAXException, IOException {
        Entity en = entityManager.getByID(currentEntity,pubID,sysID);
        pushEntity(name,en,isParamEntity,returnEndToken,resumeLexState);
    }


    // Should we parse external entities of type entityType?
    boolean parseExternalEntities(int entityType) {
        if (currentEntity.isStandalone()) {
            return false;
        }
        switch (entityType) {
            case EntityManager.PARAMETER:
                return parser.fExternalParameterEntities;

            case EntityManager.GENERAL:
            default:
                return parser.fExternalGeneralEntities;
        }
    }


    private void pushEntityState(String entityName, boolean newIsParamEntity, boolean newReturnEndToken)
    throws SAXException {
        pushEntityState(entityName,newIsParamEntity,newReturnEndToken,0);
    }

    private void pushEntityState(String entityName,boolean newIsParamEntity, boolean newReturnEndToken, int newReturnLexState)
    throws SAXException {
        long entityState = (entityBaseDepth << 11)
                        | ( (prevEntityLexState & 0xFF) << 3)
                        | (returnEntityEndToken? 4 : 0)
                        | (isParamEntity? 2 : 0)
                        | (isEntityBeingParsed? 1 : 0);

        entityStateStack.push(entityState);
        entityBaseDepth = tagStack.size();

        entityNameStack.push(currentEntityName);
        currentEntityName = entityName;

        isParamEntity = newIsParamEntity;
        returnEntityEndToken = newReturnEndToken;
        isEntityBeingParsed = true;
        prevEntityLexState = newReturnLexState;
    }

    private void popEntityState() throws SAXException {
        if (prevEntityLexState != 0)
            yybegin(prevEntityLexState);

        long entityState = entityStateStack.pop();
        returnEntityEndToken = ((entityState & 4) == 4);
        isParamEntity = ((entityState & 2) == 2);
        isEntityBeingParsed = ((entityState & 1) == 1);
        entityBaseDepth =  (int) ((entityState >> 11) & 0xFFFF);
        prevEntityLexState = (int) ((entityState >> 3) & 0xFF);

        if (currentEntityName != null)
            parser.reportEndEntity(currentEntityName);

        currentEntityName = entityNameStack.pop();

        if (tagStack.size() > entityBaseDepth)
            setTokenize(false);
    }

    private void clearEntityState() {
        entityStateStack.clear();
        entityNameStack.clear();
        returnEntityEndToken = true;
        isParamEntity = false;
        entityBaseDepth = 0;
        isEntityBeingParsed = true;
        prevEntityLexState = 0;
        currentEntityName = null;
    }




    /* Handles an entity reference, either general or paramter.
     * Returns a token which should be passed on to Piccolo,
     * or zero if no token should be returned.
     */
    private int handleEntityRef (String name, int entityType)
    throws IOException, SAXException {
        Entity entity = entityManager.getByName(name, entityType);

        if (entity == null) {
            handleUnknownEntityRef(name,entityType);
            return 0;
        }

        boolean isParam = (entityType == EntityManager.PARAMETER);
        String entityReportedName;

        // We only report the start/end of parameter entities
        // if they're at the "top level" and not within a declaration
        if (isParam) {
            if (yystate() == DTD)
                entityReportedName = "%"+name;
            else
                entityReportedName = null;
        }
        else
            entityReportedName = name;

        if (entity.isInternal()) {
            pushEntity(entityReportedName,entity,isParam,true);
            setTokenize(true);
            return  Piccolo.INTERNAL_ENTITY_REF;
        }
        else if (name == "[dtd]" || parseExternalEntities(entityType)) {
            pushEntity(entityReportedName,entity,isParam,true);
            setTokenize(true);
            return  Piccolo.EXTERNAL_ENTITY_REF;
        }
        else {
             entityWasSkipped = true;
             parser.reportSkippedEntity(entityReportedName);
             return 0;
        }
    }


    /* Handles an entity reference within a quoted string.
     * Returns true if the entity was replaced, or false if the
     * entity was skipped.
     */
    private boolean handleLiteralEntityRef (String name, int entityType)
    throws IOException, SAXException {
        Entity entity = entityManager.getByName(name, entityType);
        boolean isParam = false;
        if (entityType == EntityManager.PARAMETER)
            isParam = true;

        if (entity == null) {
            if (! (isParam || (!currentEntity.isStandalone() && entityWasSkipped)) )
                throw fatalError("Reference to undefined entity: " + name);
            else
                return false;
        }
        else if (entity.isInternal()) {
            pushEntity(null,entity,isParam,false,prevState);
            yybegin( (isParam? DTD_TAG_VALUE_ENTITY
                             : TAG_VALUE_ENTITY) );
            return  true;
        }
        else if (!isParam) {
            throw fatalError("Referencing an external entity within an " +
                             "attribute value is illegal");
        }
        else if (parseExternalEntities(entityType)) {
            // Reference to external entity within DTD literal
            yybegin(DTD_TAG_VALUE_EXTERNAL_ENTITY);
            pushEntity(null,entity,isParam,false,prevState);
            return true;
        }
        else {
            entityWasSkipped = true;
            return  false;
        }
    }


    private void handleUnknownEntityRef(String name, int type) throws SAXException {
        boolean isParam = (type == EntityManager.PARAMETER);
        String reportedName = (isParam? "%" : "") + name;

        if (!currentEntity.isStandalone() && entityWasSkipped)
            parser.reportSkippedEntity(reportedName);
        else
            throw fatalError("Reference to undefined entity: " + reportedName);
    }




    private boolean isTopEntity() {
        return !(yymoreStreams());
    }

    /************************************************************************
     * End Methods to handle the parsing of parsed entities
     ************************************************************************/




    /************************************************************************
     * Methods used by this class for parsing, both by the JFlex-based
     * code and by parseXML().
     ************************************************************************/

    /* Parse the attribute value of a double-quoted string and add the
     * attribute.
     */
    private void parseQuotedTagValue () throws SAXException, IOException {
        if (elementDefinition == null) {
            parseCdataLiteral('\"',TAG_QSTRING_CDATA_BUFFERED);
        }
        else {
            IndexedObject o = elementDefinition.getIndexedAttribute(attributeQName);
            if (o == null) {
                attributeValueType = "CDATA";
                parseCdataLiteral('\"',TAG_QSTRING_CDATA_BUFFERED);
            }
            else {
                defaultAttributeSpecified[o.getIndex()] = true;
                int type = ((AttributeDefinition)o.getObject()).getValueType();
                if (type == AttributeDefinition.CDATA) {
                    attributeValueType = "CDATA";
                    parseCdataLiteral('\"',TAG_QSTRING_CDATA_BUFFERED);
                }
                else {
                    attributeValueType = AttributeDefinition.getValueTypeString(type);
                    yybegin(TAG_QSTRING_NORMALIZE);
                }
            }
        }
    }

    /* Same, but for a single-quoted value */
    private void parseSingleQuotedTagValue () throws SAXException, IOException {
        if (elementDefinition == null) {
            parseCdataLiteral('\'',TAG_SQSTRING_CDATA_BUFFERED);
        }
        else {
            IndexedObject o = elementDefinition.getIndexedAttribute(attributeQName);
            if (o == null) {
                attributeValueType = "CDATA";
                parseCdataLiteral('\'',TAG_SQSTRING_CDATA_BUFFERED);
            }
            else {
                defaultAttributeSpecified[o.getIndex()] = true;
                int type = ((AttributeDefinition)o.getObject()).getValueType();
                if (type == AttributeDefinition.CDATA) {
                    attributeValueType = "CDATA";
                    parseCdataLiteral('\'',TAG_SQSTRING_CDATA_BUFFERED);
                }
                else {
                    attributeValueType = AttributeDefinition.getValueTypeString(type);
                    yybegin(TAG_SQSTRING_NORMALIZE);
                }
            }
        }
    }


    /*
     * Parses a double- or single-quoted string. If we hit the end of the
     * input buffer or encounter an entity reference, put JFlex into
     * the state supplied in "bufferedState".
     */
    private void parseCdataLiteral(char closingQuote, int bufferedState)
    throws SAXException, IOException {
        // We parse this ourselves so we can translate whitespace
        // inline without copying to a buffer
        int startPos = yy_markedPos;

        while ((yy_endRead-yy_markedPos) > 0) {
            char c = yy_buffer[yy_markedPos++];

            if (c == '&') {
                //yycolumn_next++;
                clearCbuf();
                appendToCbuf(yy_buffer, startPos, (yy_markedPos-1) - startPos);
                prevState = bufferedState;
                yybegin(TAG_VALUE_ENTITYREF);
                return;
            }
            else if (c == '<') {
                throw  fatalError(
                  "Illegal '<' found in attribute value. Use '&lt;' instead.");
            }

            // Check common characters as early as possible
            else if (c > '\'') {
                //yycolumn_next++;
            }

            else if (c == closingQuote) {
                //yycolumn_next++;
                String value;
                int valueLen = (yy_markedPos-1) - startPos;

                // Cache and intern short strings and all URIs
                if (valueLen < 4 || isNamespaceDeclaration)
                    value = stringConverter.convert(yy_buffer,startPos,valueLen);
                else
                    value = new String(yy_buffer,startPos,valueLen);

                addAttribute(attributeURI,attributeLocalName,attributeQName,
                             attributeValueType, value);


                // Next character must be a space, ">" or "/"
                int n;
                if ((yy_endRead-yy_markedPos) <= 0) {
                    n = yynextChar();
                }
                else {
                    n = yy_buffer[yy_markedPos++];
                }

                switch (n) {
                    case ' ':
                    case '\t':
                        //yycolumn_next++;
                        break;

                    case '\n':
                        yyline_next++;
                        //yycolumn_next = 0;
                        break;

                    case '/':
                    case '>':
                        yy_markedPos--;
                        endOfTag = true;
                        return;

                    default:
                        throw fatalError("Whitespace missing after attribute value");
                }

                // Discard any trailing whitespace
                while ((yy_endRead-yy_markedPos) > 0) {
                    switch (yy_buffer[yy_markedPos]) {
                        case ' ':
                        case '\t':
                            yy_markedPos++;
                            //yycolumn_next++;
                            break;

                        case '\n':
                            yy_markedPos++;
                            yyline_next++;
                            //yycolumn_next = 0;
                            break;

                        default:
                            return;
                    }
                }

                return;
            }

            else if (c == '\t') {
                //yycolumn_next++;
                yy_buffer[yy_markedPos-1] = ' ';
            }
            else if (c == '\n') {
                yyline_next++;
                //yycolumn_next = 0;
                yy_buffer[yy_markedPos-1] = ' ';
            }
            else {
                //yycolumn_next++;
            }
        }

        // we hit the end of the read buffer and so need to buffer this string
        clearCbuf();
        appendToCbuf(yy_buffer, startPos, yy_markedPos - startPos);
        prevState = bufferedState;
        yybegin(bufferedState);
    }


    // Parses a character entity and appends it to the character buffer.
    // A character entity reference can produce 1 or 2 characters.
    private void parseEncodedChar(char[] buf, int off, int len, int radix)
    throws CharConversionException {
        try {
            int result=0;
            for (int i=0; i < len; i++)
                result = (result*radix) + Character.digit(buf[off+i],radix);

            if (result >= 0x110000)
                throw new IllegalCharException("Character reference to illegal XML character");


            if (result >= 0x10000) { // This is a 2-character entity
                result -= 0x10000;

                appendToCbuf((char) ((result >> 10) + 0xD800) );
                appendToCbuf((char) ((result & ((1 << 10) - 1)) + 0xDC00) );
            }
            else
            if ((result < 0x20 && result != '\t' && result != '\r' && result != '\n')
                || (result >= 0xD800 && result < 0xE000)
                || result >= 0xFFFE)
                throw new IllegalCharException(
                    "Character reference to illegal XML character");
            else
                appendToCbuf((char)result);
        }
        catch (ClassCastException e) {
            throw new CharConversionException();
        }
    }


    // Prepare an element that may have attributes
    // Call this before any attributes are read for the current element
    private void prepareComplexElement(String elementQName) {

        isNamespaceDeclaration = false;

        elementDefinition = getElement(elementQName);
        // if necessary, resize the array of attribute default specified flags
        if (elementDefinition != null) {
            numAttributesDefined = elementDefinition.getAttributeCount();
            int currentSize = defaultAttributeSpecified.length;
            if (currentSize < numAttributesDefined) {
                defaultAttributeSpecified = new boolean[Math.max(2*currentSize,numAttributesDefined)];
            }

            for (int i=0; i < numAttributesDefined; i++) {
                defaultAttributeSpecified[i] = false;
            }
        }
        else {
            attributeValueType = "CDATA";
        }
    }

    // Call this after completing the parsing of an element with attributes
    private void processComplexElement() throws SAXException, IOException {
        if (elementDefinition != null) {
            AttributeDefinition[] attributes = elementDefinition.getAttributes();
            for (int i=0; i < numAttributesDefined; i++) {
                if (!defaultAttributeSpecified[i]) {
                    AttributeDefinition ad = attributes[i];
                    String defaultValue = ad.getDefaultValue();
                    if (defaultValue != null) {
                        attribs.addAttribute(ad.getPrefix(),ad.getLocalName(),
                                             ad.getQName(),ad.getValueTypeString(),
                                             defaultValue);
                    }
                }
            }
        }
    }

    private void processNSContextEnd() throws SAXException {
        int mappings = nsSupport.getContextSize();
        for (int i=0; i < mappings; i++) {
            parser.reportEndPrefixMapping(nsSupport.getContextPrefix(i));
        }
        nsSupport.popContext();
    }

    // Add an attribute to the current element
    private void addAttribute(String prefix, String localName, String qName,
                         String type, String value)
    throws SAXException {

        // If we saw an entity within a non-CDATA value, we need to normalize
        // it again.
        if (needsNormalization) {
            value = normalizeValue(value);
            needsNormalization = false;
        }

        if (isNamespaceDeclaration && parser.fNamespaces) {
            if (parser.fNamespacePrefixes)
                attribs.addAndCheckAttribute(
                    prefix,localName,qName,type,value);

            if (prefix == "") {
                if (localName == "xmlns")
                    localName = "";
                nsSupport.declarePrefix(localName,value);
                parser.reportStartPrefixMapping(localName,value);
            }
            else if (prefix != "xml") {
                nsSupport.declarePrefix(localName,value);
                parser.reportStartPrefixMapping(localName,value);
            }
        }
        else
            attribs.addAndCheckAttribute(
                prefix,localName,qName,type,value);
    }



    // Call this after parsing an element with no attributes
    private void processSimpleElement(String elementQName) throws SAXException, IOException {
        elementDefinition = getElement(elementQName);

        if (elementDefinition != null) {
            AttributeDefinition[] defaults = elementDefinition.getAttributes();
            int numDefaults = elementDefinition.getAttributeCount();
            for (int i=0; i < numDefaults; i++) {
                AttributeDefinition ad = defaults[i];
                String defaultValue = ad.getDefaultValue();

                if (defaultValue != null) {
                    attribs.addAttribute(ad.getPrefix(),ad.getLocalName(),
                                         ad.getQName(),ad.getValueTypeString(),
                                         defaultValue);
                }
            }
        }
    }


    String rescanAttributeValue(String defaultValue) throws SAXException, IOException {
        clearCbuf();
        char[] valbuf = defaultValue.toCharArray();
        yypushBuffer(valbuf,0,valbuf.length);
        pushEntityState(null,false,true,yystate());
        yybegin(TAG_VALUE_ENTITY);
        isEntityBeingParsed = false;
        if (yylex() != Piccolo.ENTITY_END)
            throw fatalError("Unexpected element while parsing attribute default value");
        isEntityBeingParsed = true;

        // We need to internalize values for namespace declarations. Not much
        // harm in just internalizing all attribute defaults.
        return stringConverter.convert(cbuf,0,cbuflen);
    }


    // Resolves the element and attribute prefixes for the element we just parsed
    // into URIs
    private void resolveNamespacePrefixes() {
        elementURI = nsSupport.getURI(elementURI);
        int numAttributes = attribs.getLength();
        for (int i=0; i < numAttributes; i++) {
            String prefix = attribs.getURI(i);
            if (prefix != "") {
                String uri = nsSupport.getURI(prefix);
                if (uri != "")
                    attribs.setURI(i,uri);
            }

        }
    }

    // Ensures that the end tag we just parsed properly closes a start tag.
    // If we've just hit the top-level end tag, turn tokenization back on
    // so we return a token to Piccolo.
    private void checkEndTag(String endQName) throws SAXException {
        String properEnd = tagStack.pop();
        if (tagStack.size() == entityBaseDepth) {
            setTokenize(true);
        }

        if (properEnd != endQName)
            throw fatalError("</"+endQName+"> does not close tag <"+properEnd+">.");
    }


    /************************************************************************
     * End Methods used by this class for parsing.
     ************************************************************************/







    /************************************************************************
     * Miscellaneous methods used internally to this class
     ************************************************************************/


    // Like JFlex's yytext(), but the String returned is internalized.
    private String yytext2 () {
        return  stringConverter.convert(yy_buffer, yy_startRead, yy_markedPos
                - yy_startRead);
    }


    // Like yytext(int start, int length), but the String returned is internalized
    private String yytext2 (int start, int length) {
        return  stringConverter.convert(yy_buffer, yy_startRead + start, length);
    }



    // Throws a fatal SAXException
    private FatalParsingException fatalError (String msg) {
        return new FatalParsingException(msg);
    }

    // Same but with an embedded exception
    private FatalParsingException fatalError (String msg, Exception e) {
        return new FatalParsingException(msg,e);
    }

    // backup one character mentaining the corect line number
    private void safeBacktrack()
    {
        if (yy_buffer[--yy_markedPos] == '\n')
            yyline_next--;
        // todo: have to reset yycolumn_next to previous line's value as well?
    }

    /************************************************************************
     * End Miscellaneous methods
     ************************************************************************/

%}


%%

// ***************************** LEXICAL RULES **************************


/************************************************************************
 * Rules matched at the base state, either before or after a DTD
 ************************************************************************/

// Do the whole content input loop ourselves
// so we don't have to grow the buffer to handle large chunks of CDATA
//
// CDATA starting off with whitespace: could be whitespace or text

<YYINITIAL,YYINITIAL_DIRECT>"<" {
    int result;

    tokenStartLine = yyline_next + 1;

    yybegin(tagStartState);

    if (parser.fNamespaces)
        result = parseTagNS();
    else
        result = parseTag();

    if (result != -1) {
        if (tokenizeInput) {
            if (tagType == Piccolo.OPEN_TAG)
                setTokenize(false);
            return tagType;
        }
    }

}

<YYINITIAL> {
    [ \t\n\r] {
        int token = parseWhitespace();
        if (token == Piccolo.CDATA) {
            parser.reportCdata();
        }

        return token;
    }

    "&" {
        yybegin(ENTITYREF);
    }

    [^&<] {
        safeBacktrack();
        parseCdata();
        parser.reportCdata();

        return Piccolo.CDATA;
    }
}

<YYINITIAL_DIRECT> {
    "&" {
        yybegin(ENTITYREF);

    }

    // Since this is not a validating parser, anything inside a tag
    // (as is all direct reporting) is always considered CDATA
    [^&<] {
        /* Instead of making flex deal with the simple parsing,
         * we use a handwritten loop that can handle simple text and
         * tags more efficiently.
         *
         * parseCdata();
         * parser.reportCdata(cdataBuffer,cdataStart,cdataLength);
         */

        safeBacktrack();
        int token = parseXML();

        if (token != 0)
            return token;
    }

}


/************************************************************************
 * End Rules matched at the base state
 ************************************************************************/



/************************************************************************
 * XML declarations and processing instructions
 ************************************************************************/

<DTD_TAG_START>"?xml"/[ \t\n\?] {
    prevState = DTD;
    yybegin(XML_TAG);
}

<TAG_START,TAG_START_NS>"?xml"/[ \t\n\?] {
    prevState = baseState;
    yybegin(XML_TAG);
}

<DTD_TAG_START,TAG_START,TAG_START_NS>"?"[Xx][Mm][Ll]/[ \t\n\r\?] {
    throw fatalError("'?xml' is a reserved processing instruction target and must be in lower case.");
}

<TAG_START,TAG_START_NS>"?"{Name}  {
    piPrevState = baseState;
    elementQName = yytext2(1,yylength()-1);
    yybegin(PI_WS);
}

<DTD_TAG_START>"?"{Name}  {
    piPrevState = DTD;
    yybegin(PI_WS);
    elementQName = yytext2(1,yylength()-1);
}




/* XML declaration rules:

xml_decl: XML_DECL_START VERSION XML_DECL_END
        | XML_DECL_START VERSION ENCODING XML_DECL_END
        | XML_DECL_START VERSION STANDALONE XML_DECL_END
        | XML_DECL_START VERSION ENCODING STANDALONE XML_DECL_END
        | /* empty */
;

xml_text_decl: XML_DECL_START VERSION ENCODING XML_DECL_END
             | XML_DECL_START ENCODING XML_DECL_END
;

*/

<XML_TAG>~"?>" {
    if (currentEntity.isInternal())
        throw fatalError("XML declarations are not allowed in internal entities");

    yybegin(prevState);

    if (currentEntity.getXMLVersion() != null) {
        if (currentEntity.getDeclaredEncoding() == null)
            return Piccolo.XML_DOC_DECL;
        else
        if (currentEntity.isStandaloneDeclared())
            return Piccolo.XML_DOC_DECL;
        else
            return Piccolo.XML_DOC_OR_TEXT_DECL;
    }
    else
    if (currentEntity.getDeclaredEncoding() != null
            && !currentEntity.isStandaloneDeclared())
            return Piccolo.XML_TEXT_DECL;
    else
        throw fatalError("XML declaration is not well-formed");
}




/*
<XML_TAG> {
    [ \t\n]+"standalone"{ws}"="{ws}"'yes'" |
    [ \t\n]+"standalone"{ws}"="{ws}"\"yes\"" {
        currentEntity.setStandalone(true);
        return Piccolo.STANDALONE;
    }

    [ \t\n]+"standalone"{ws}"="{ws}"'no'" |
    [ \t\n]+"standalone"{ws}"="{ws}"\"no\"" {
        currentEntity.setStandalone(false);
        return Piccolo.STANDALONE;
    }

    [ \t\n]+"encoding"{ws}"="{ws}"\'"{EncName}"\'" |
    [ \t\n]+"encoding"{ws}"="{ws}"\""{EncName}"\"" {
        return Piccolo.ENCODING;
    }

    [ \t\n]+"version"{ws}"="{ws}"\'"{VersionNum}"\'" |
    [ \t\n]+"version"{ws}"="{ws}"\""{VersionNum}"\"" {
        return Piccolo.VERSION;
    }

    {ws}"?>" {
        yybegin(prevState);
        return Piccolo.XML_DECL_END;
    }
}
*/

// Processing Instructions
<PI_WS>{ws} { yybegin(PI); }

<PI_WS>"?>" {
    yybegin(piPrevState);
    parser.reportPI(elementQName,"");
    if (piPrevState != DTD_TAG_VALUE_EXTERNAL_ENTITY && tokenizeInput) {
        return Piccolo.PI;
    }
}

<PI>~"?>" {
    yybegin(piPrevState);
    parser.reportPI(elementQName,yytext(0,yylength()-2));
    if (tokenizeInput) {
        return Piccolo.PI;
    }
}

/************************************************************************
 * End XML declarations and processing instructions
 ************************************************************************/










// States for which we want to skip whitespace
<TAG,TAG_NS>{ws} {}

// States for which whitespace should be tokenized
<DTD,DTD_ENTITY_DECL,DTD_TAG,DTD_ATT_NAME,DTD_ATTLIST_ELEMENT,DTD_ATT_TYPE,DTD_NMTOKENS,DTD_PUBLIC_ID>{ws} {
    return Piccolo.WHITESPACE;
}


/************************************************************************
 * Rules to parse a DTD
 ************************************************************************/

<DTD> {
    "%"{Name}";" {
        int token = handleEntityRef(yytext2(1,yylength()-2),EntityManager.PARAMETER);
        if (token != 0) {
            returnEntityEndToken = false;
            return token;
        }
    }

    "<" { yybegin(DTD_TAG_START); bypassPERefs=bypassGERefs=false; }
    "]]>" { return Piccolo.DOUBLE_RBRACKET_END; }
    "]"{ws}">" { return Piccolo.RBRACKET_END; }
}


/************************************************************************
 * Identify a tag within a DTD
 ************************************************************************/

<DTD_TAG_START> {
    "!ENTITY" { yybegin(DTD_ENTITY_DECL); return Piccolo.ENTITY_DECL_START; }
    "!ATTLIST" { yybegin(DTD_ATTLIST_ELEMENT); return Piccolo.ATTLIST_START; }
    "!NOTATION" { yybegin(DTD_TAG); return Piccolo.NOTATION_START; }
    "!ELEMENT" { yybegin(DTD_TAG); return Piccolo.ELEMENT_DECL_START; }

    "!--" { yybegin(DTD_COMMENT); }

    "![" {
        yybegin(DTD_TAG);
        if (isTopEntity())
            throw fatalError("'<![' constructs are not allowed in the internal DTD subset");

        return Piccolo.CONDITIONAL_START;
    }
}


/************************************************************************
 * Rules for handling DTD IGNORE and INCLUDE sections
 ************************************************************************/

// Everything except conditional starts and ends is ignored within a
// <![IGNORE[...]]> section.
<DTD_IGNORE> {
    "<![" { return Piccolo.IGNORED_CONDITIONAL_START; }
    "]]>" { return Piccolo.DOUBLE_RBRACKET_END; }

    // Everything else
    [^<\]]*|"<"|"]" {}
}


/************************************************************************
 * Rules for parsing tags within the DTD
 ************************************************************************/

<DTD_COMMENT>([^\-]*"-"[^\-])*[^\-]*"-->" {
    yybegin(DTD);
    parser.reportComment(yy_buffer,yy_startRead,(yy_markedPos-3)-yy_startRead);

    // Comments are never important in the DTD
//    if (tokenizeInput)
//        return Piccolo.COMMENT;
}

<DTD_ENTITY_DECL> {
    "%"[ \t\n]+ { return Piccolo.PERCENT; }
    {Name} { yybegin(DTD_TAG); return stringToken(Piccolo.NAME,yytext2()); }
}


<DTD_ATTLIST_ELEMENT>{Name} {
    yybegin(DTD_ATT_NAME);
    bypassPERefs=true;
    return stringToken(Piccolo.NAME,yytext2());
}

// The name of the attribute within a <!ATTLIST> tag
<DTD_ATT_NAME> {
    {NCName}":"{NCName} {
        yybegin(DTD_ATT_TYPE);
        return stringToken(Piccolo.PREFIXED_NAME,yytext2());
    }
    {Name} {
        yybegin(DTD_ATT_TYPE);
        return stringToken(Piccolo.UNPREFIXED_NAME,yytext2());
    }
}

// The type of attribute value
<DTD_ATT_TYPE> {
    "CDATA" { yybegin(DTD_TAG); return Piccolo.CDATA; }
    "ID" { yybegin(DTD_TAG); return Piccolo.ID; }
    "IDREF" { yybegin(DTD_TAG); return Piccolo.IDREF; }
    "IDREFS" { yybegin(DTD_TAG); return Piccolo.IDREFS; }
    "ENTITY" { yybegin(DTD_TAG); return Piccolo.ENTITY; }
    "ENTITIES" { yybegin(DTD_TAG); return Piccolo.ENTITIES; }
    "NMTOKEN" { yybegin(DTD_TAG); return Piccolo.NMTOKEN; }
    "NMTOKENS" { yybegin(DTD_TAG); return Piccolo.NMTOKENS; }
    "NOTATION" { return Piccolo.NOTATION; }
    "(" { yybegin(DTD_NMTOKENS); return Piccolo.LPAREN; }
}

<DTD_TAG> {
    // Keywords used within DTD tags
    "SYSTEM" { bypassPERefs = bypassGERefs = true; return Piccolo.SYSTEM; }
    "NOTATION" { return Piccolo.NOTATION; }
    "PUBLIC" { bypassPERefs = bypassGERefs = true; yybegin(DTD_PUBLIC_ID); return Piccolo.PUBLIC; }
    "#REQUIRED" { return Piccolo.REQUIRED; }
    "#IMPLIED" { return Piccolo.IMPLIED; }
    "#FIXED" { return Piccolo.FIXED; }
    "NDATA" { return Piccolo.NDATA; }
    "EMPTY" { return Piccolo.EMPTY; }
    "ANY" { return Piccolo.ANY; }
    "#PCDATA" { return Piccolo.PCDATA; }

    // For conditionals
    "INCLUDE" { return Piccolo.INCLUDE; }
    "IGNORE"  { return Piccolo.IGNORE; }

    {Name} { return stringToken(Piccolo.NAME,yytext2()); }

    {ws}"["{ws} { yybegin(DTD); return Piccolo.LBRACKET; }

    "(" { return Piccolo.LPAREN; }
    ")" { return Piccolo.RPAREN; }

    [\*]  { return Piccolo.STAR; }
    [\?]  { return Piccolo.QUESTION; }
    [\+]  { return Piccolo.PLUS; }
    [\,]  { return Piccolo.COMMA; }

    <DTD_NMTOKENS>"|" { return Piccolo.PIPE; }

    <DTD_ATT_NAME>">" { yybegin(DTD); return Piccolo.TAG_END; }
}


<DTD_NMTOKENS> {
    {Nmtoken} { return stringToken(Piccolo.NAME,yytext2()); }
    ")" { yybegin(DTD_TAG); return Piccolo.RPAREN; }
}

<DTD_PUBLIC_ID> {
    "\""({PubidChar}|"'")*"\"" |
    "\'"{PubidChar}*"\'" {
        yybegin(DTD_TAG);
        return stringToken(Piccolo.STRING,yytext(1,yylength()-2));
    }
}

// Parameter entities can appear practically anywhere
// We won't tell Piccolo about this external entity to make the grammar simpler
<DTD_TAG,DTD_ATT_NAME,DTD_ATT_TYPE,DTD_ENTITY_DECL,DTD_ATTLIST_ELEMENT,DTD_NMTOKENS> {
    "%"{Name}";" {
        if (isTopEntity())
            throw fatalError("Parameter entities may not appear in the internal subset");

        if (handleEntityRef(yytext2(1,yylength()-2),EntityManager.PARAMETER) != 0)
            returnEntityEndToken = false;
        return Piccolo.WHITESPACE;
    }
}


/************************************************************************
 * Rules for parsing quoted string literals within a DTD
 ************************************************************************/

<DTD_TAG> {
      "\""[^\"%&]*"\"" |
      "\'"[^\'%&]*"\'" {
        return stringToken(Piccolo.STRING,yytext(1,yylength()-2));
    }

      "\""[^\"%&]* {
        prevState = DTD_TAG_QSTRING_BUFFERED;
        clearCbuf();
        appendToCbuf(yy_buffer,yy_startRead+1,yylength()-1);
        yybegin(prevState);
    }

      "\'"[^\'%&]* {
        prevState = DTD_TAG_SQSTRING_BUFFERED;
        clearCbuf();
        appendToCbuf(yy_buffer,yy_startRead+1,yylength()-1);
        yybegin(prevState);
    }
}

<DTD_TAG_QSTRING_BUFFERED> {
    [^\"%&]* {
        appendToCbuf(yy_buffer,yy_startRead,yylength());
    }

    <DTD_TAG_SQSTRING_BUFFERED> {
        "&" {
            if (bypassGERefs)
                appendToCbuf('&');
            else
                yybegin(DTD_TAG_VALUE_STD_ENTITYREF);
        }

        "%" {
            if (bypassPERefs)
                appendToCbuf('%');
            else
                yybegin(DTD_TAG_VALUE_PARAM_ENTITYREF);
        }
    }

    "\"" {
        yybegin(DTD_TAG);
        return stringToken(Piccolo.STRING,new String(cbuf,0,cbuflen));
    }
}



<DTD_TAG_SQSTRING_BUFFERED> {
    [^\'%&]* {
        appendToCbuf(yy_buffer,yy_startRead,yylength());
    }

    "\'" {
        yybegin(DTD_TAG);
        return stringToken(Piccolo.STRING,new String(cbuf,0,cbuflen));
    }
}


/************************************************************************
 * End of DTD parsing rules
 ************************************************************************/




/************************************************************************
 * Rules for parsing tags not withn the DTD
 ************************************************************************/

<TAG_START,TAG_START_NS> {
    "!--"([^\-]*"-"[^\-])*[^\-]*"-->" {
        yybegin(baseState);
        parser.reportComment(yy_buffer,yy_startRead+3,(yy_markedPos-yy_startRead)-6);
        if (tokenizeInput)
            return Piccolo.COMMENT;
    }


    "![CDATA[" {
        yybegin(baseState);
        startCdata();
        parseCdataSection();
        if (tokenizeInput)
            return Piccolo.CDATA;
        endCdata();
    }


    "!DOCTYPE"[ \t\n]+ {
        yybegin(DTD_TAG);
        if (parseExternalEntities(EntityManager.GENERAL))
            return Piccolo.DTD_START;
        else
            return Piccolo.DTD_START_SKIPEXTERNAL;
    }
}


/************************************************************************
 * Rules for parsing the first Name within a tag
 ************************************************************************/

// Non-namespace
<TAG_START> {
/* Including these extra rules seem to put us over an optimizing threshold
   and slow the parser down by more than 20%

    {Name}">"  {
        yybegin(baseState);
        stringValue = yytext2(0,yylength()-1);
        processSimpleElement(stringValue);
        parser.reportStartTag(elementURI,elementLocalName,stringValue);
        attribs.clear();
        tagStack.push(stringValue);
        if (tokenizeInput) {
            setTokenize(false);
            return Piccolo.OPEN_TAG;
        }
    }

    {Name}"/>"  {
        yybegin(baseState);
        stringValue = yytext2(0,yylength()-2);
        processSimpleElement(stringValue);
        parser.reportStartTag(elementURI,elementLocalName,stringValue);
        parser.reportEndTag(elementURI,elementLocalName,stringValue);
        attribs.clear();
        if (tokenizeInput)
            return Piccolo.EMPTY_TAG;
    }

    "/"{Name}">"  {
        yybegin(baseState);
        stringValue = yytext2(1,yylength()-2);
        parser.reportEndTag(elementURI,elementLocalName,stringValue);
        checkEndTag(stringValue);
        if (tokenizeInput)
            return Piccolo.CLOSE_TAG;
    }
*/

    "/"{Name}  {
        yybegin(CLOSE_TAG);
        stringValue = yytext2(1,yylength()-1);
    }

    {Name}  {
        yybegin(TAG);
        stringValue = yytext2();
        prepareComplexElement(stringValue);
    }
}


// Namespaces enabled
<TAG_START_NS> {
/* Including these extra rules seem to put us over an optimizing threshold
   and slow the parser down by more than 20%

    {NCName}":"{NCName}">"  {
        nsSupport.pushContext();
        yybegin(baseState);
        stringValue = yytext2(0,yylength()-1);
        int colon = stringValue.indexOf(':');
        elementURI = nsSupport.getURI(yytext2(0,colon));
        elementLocalName = yytext2(colon+1,(yylength()-1)-(colon+1));
        processSimpleElement(stringValue);
        parser.reportStartTag(elementURI,elementLocalName,stringValue);
        attribs.clear();
        tagStack.push(stringValue);
        if (tokenizeInput) {
            setTokenize(false);
            return Piccolo.OPEN_TAG;
        }
    }

    {NCName}">"  {
        nsSupport.pushContext();
        yybegin(baseState);
        elementURI = nsSupport.getDefaultURI();
        elementLocalName = stringValue = yytext2(0,yylength()-1);
        processSimpleElement(stringValue);
        parser.reportStartTag(elementURI,elementLocalName,stringValue);
        attribs.clear();
        tagStack.push(stringValue);
        if (tokenizeInput) {
            setTokenize(false);
            return Piccolo.OPEN_TAG;
        }
    }

    {NCName}":"{NCName}"/>"  {
        // This is an empty tag; don't push the namespace context
        yybegin(baseState);
        stringValue = yytext2(0,yylength()-2);
        int colon = stringValue.indexOf(':');
        elementURI = nsSupport.getURI(yytext2(0,colon));
        elementLocalName = yytext2(colon+1,(yylength()-2)-(colon+1));
        processSimpleElement(stringValue);
        parser.reportStartTag(elementURI,elementLocalName,stringValue);
        parser.reportEndTag(elementURI,elementLocalName,stringValue);
        attribs.clear();
        if (tokenizeInput)
            return Piccolo.EMPTY_TAG;
    }

    {NCName}"/>"  {
        yybegin(baseState);
        elementURI = nsSupport.getDefaultURI();
        elementLocalName = stringValue = yytext2(0,yylength()-2);
        processSimpleElement(stringValue);
        parser.reportStartTag(elementURI,elementLocalName,stringValue);
        parser.reportEndTag(elementURI,elementLocalName,stringValue);
        attribs.clear();
        if (tokenizeInput)
            return Piccolo.EMPTY_TAG;
    }


    "/"{NCName}":"{NCName}">"  {
        yybegin(baseState);
        stringValue = yytext2(1,yylength()-2);
        int colon = stringValue.indexOf(':') + 1;
         elementURI = nsSupport.getURI(yytext2(1,colon-1));
        elementLocalName = yytext2(colon+1,(yylength()-2)-colon);
        checkEndTag(stringValue);
        parser.reportEndTag(elementURI,elementLocalName,stringValue);
        processNSContextEnd();
        if (tokenizeInput)
            return Piccolo.CLOSE_TAG;
    }

    "/"{Name}">"  {
        yybegin(baseState);
        stringValue = yytext2(1,yylength()-2);
        elementURI = nsSupport.getDefaultURI();
        elementLocalName = stringValue;
        checkEndTag(stringValue);
        parser.reportEndTag(elementURI,elementLocalName,stringValue);
        processNSContextEnd();
        if (tokenizeInput)
            return Piccolo.CLOSE_TAG;
    }
*/

    "/"{NCName}":"{NCName}  {
        yybegin(CLOSE_TAG_NS);
        stringValue = yytext2(1,yylength()-1);
        int colon = stringValue.indexOf(':') + 1;
        elementURI = nsSupport.getURI(yytext2(1,colon-1));
        elementLocalName = yytext2(colon+1,(yylength()-1)-colon);
    }

    "/"{Name}  {
        yybegin(CLOSE_TAG_NS);
        elementURI = nsSupport.getDefaultURI();
        stringValue = elementLocalName = yytext2(1,yylength()-1);
    }

    {NCName}":"{NCName}  {
        nsSupport.pushContext();
        yybegin(TAG_NS);
        stringValue = yytext2();
        int colon = stringValue.indexOf(':');
        elementURI = yytext2(0,colon);
        elementLocalName = yytext2(colon+1,yylength()-(colon+1));
        prepareComplexElement(stringValue);
    }


    {Name}  {
        nsSupport.pushContext();
        yybegin(TAG_NS);
        elementURI = "";
        elementLocalName = stringValue = yytext2();
        prepareComplexElement(stringValue);
    }
}


<CLOSE_TAG>{ws}">"    {
    yybegin(baseState);
    checkEndTag(stringValue);
    parser.reportEndTag(elementURI,elementLocalName,stringValue);
    if (tokenizeInput)
        return Piccolo.CLOSE_TAG;
}

<CLOSE_TAG_NS>{ws}">"    {
    yybegin(baseState);
    checkEndTag(stringValue);
    parser.reportEndTag(elementURI,elementLocalName,stringValue);
    processNSContextEnd();
    if (tokenizeInput)
        return Piccolo.CLOSE_TAG;
}



/************************************************************************
 * Rules for parsing the rest of a tag not within the DTD
 ************************************************************************/

// Namespaces disabled
<TAG> {
/*
    {Name}"=\"" {
        attributeQName = yytext2(0,yylength()-2);
        parseQuotedTagValue();
    }

    {Name}"=\'" {
        attributeQName = yytext2(0,yylength()-2);
        parseSingleQuotedTagValue();
    }
 */

    {Name} {
        attributeQName = yytext2();
        yybegin(TAG_VALUE);
    }

    ">" {
        yybegin(baseState);
        tagStack.push(stringValue);
        processComplexElement();
        parser.reportStartTag(elementURI,elementLocalName,stringValue);
        attribs.clear();
        if (tokenizeInput) {
            setTokenize(false);
            return Piccolo.OPEN_TAG;
        }
    }

    "/>" {
        yybegin(baseState);
        processComplexElement();
        parser.reportStartTag("","",stringValue);
        parser.reportEndTag("","",stringValue);
        attribs.clear();
        if (tokenizeInput)
            return Piccolo.EMPTY_TAG;
    }
}


// Namespaces enabled
<TAG_NS> {
    "xmlns"{ws}={ws}"\"" {
        attributeURI = "xmlns";
        attributeLocalName = "";
        attributeQName = "xmlns";
        isNamespaceDeclaration = true;
        parseCdataLiteral('\"',TAG_QSTRING_CDATA_BUFFERED);
    }

    "xmlns"{ws}={ws}"\'" {
        attributeURI = "xmlns";
        attributeLocalName = "";
        attributeQName = "xmlns";
        isNamespaceDeclaration = true;
        parseCdataLiteral('\'',TAG_SQSTRING_CDATA_BUFFERED);
    }


/* Including these two states puts the Java optimizer over the threshold
   for fast switch statement optimization. Effect: 4x slower!

    "xmlns:"{NCName}"=\"" {
        attributeURI = "xmlns";
        attributeLocalName = yytext2(6,yylength()-8);
        attributeQName = yytext2(0,yylength()-2);
        isNamespaceDeclaration = true;
        parseCdataLiteral('\"',TAG_QSTRING_CDATA_BUFFERED);
    }

    "xmlns:"{NCName}"=\'" {
        attributeURI = "xmlns";
        attributeLocalName = yytext2(6,yylength()-8);
        attributeQName = yytext2(0,yylength()-2);
        isNamespaceDeclaration = true;
        parseCdataLiteral('\'',TAG_SQSTRING_CDATA_BUFFERED);
    }
*/

    "xmlns:"{NCName} {
        attributeURI = "xmlns";
        attributeLocalName = yytext2(6,yylength()-6);
        attributeQName = yytext2();
        isNamespaceDeclaration = true;
        yybegin(TAG_VALUE);
    }

/*
    {NCName}":"{NCName}"=\"" {
        isNamespaceDeclaration = false;
        attributeQName = yytext2(0,yylength()-2);
        int colon = attributeQName.indexOf(':');
        attributeURI = yytext2(0,colon);
        attributeLocalName = yytext2(colon+1,(yylength()-2)-(colon+1));
        parseQuotedTagValue();
    }

    {NCName}"=\"" {
        isNamespaceDeclaration = false;
        attributeQName = attributeLocalName = yytext2(0,yylength()-2);
        attributeURI = "";
        parseQuotedTagValue();
    }

    {NCName}":"{NCName}"=\'" {
        isNamespaceDeclaration = false;
        attributeQName = yytext2(0,yylength()-2);
        int colon = attributeQName.indexOf(':');
        attributeURI = yytext2(0,colon);
        attributeLocalName = yytext2(colon+1,(yylength()-2)-(colon+1));
        parseSingleQuotedTagValue();
    }

    {NCName}"=\'" {
        isNamespaceDeclaration = false;
        attributeQName = attributeLocalName = yytext2(0,yylength()-2);
        attributeURI = "";
        parseSingleQuotedTagValue();
    }
 */
    {NCName}":"{NCName} {
        isNamespaceDeclaration = false;
        attributeQName = yytext2();
        int colon = attributeQName.indexOf(':');
        attributeURI = yytext2(0,colon);
        // fixing bug when computing localname
        attributeLocalName = yytext2(colon+1,(yylength()-colon-1));
        yybegin(TAG_VALUE);
    }

    {Name} {
        isNamespaceDeclaration = false;
        attributeLocalName = attributeQName = yytext2();
        attributeURI = "";
        yybegin(TAG_VALUE);
    }

    ">" {
        yybegin(baseState);
        processComplexElement();
        resolveNamespacePrefixes();
        parser.reportStartTag(elementURI,elementLocalName,stringValue);
        attribs.clear();
        tagStack.push(stringValue);
        if (tokenizeInput) {
            setTokenize(false);
            return Piccolo.OPEN_TAG;
        }
    }

    "/>" {
        yybegin(baseState);
        processComplexElement();
        resolveNamespacePrefixes();
        parser.reportStartTag(elementURI,elementLocalName,stringValue);
        parser.reportEndTag(elementURI,elementLocalName,stringValue);
        processNSContextEnd();
        attribs.clear();
        if (tokenizeInput)
            return Piccolo.EMPTY_TAG;
    }
}


<TAG_VALUE> {
    {ws}"="{ws}"\"" { yybegin(tagState); parseQuotedTagValue(); }
    {ws}"="{ws}"\'" { yybegin(tagState); parseSingleQuotedTagValue(); }
}




/************************************************************************
 * Rules for parsing quoted string literals within non-DTD tags
 ************************************************************************/

<TAG_QSTRING_CDATA_BUFFERED>[^&\t\n\r\"<]* |
<TAG_SQSTRING_CDATA_BUFFERED>[^&\t\n\r\'<]* |
<TAG_QSTRING_NORMALIZE_BUFFERED>[^& \t\r\n<\"]* |
<TAG_SQSTRING_NORMALIZE_BUFFERED>[^& \t\r\n<\']* {
    appendToCbuf(yy_buffer,yy_startRead,yy_markedPos-yy_startRead);
}


<TAG_QSTRING_CDATA_BUFFERED,TAG_SQSTRING_CDATA_BUFFERED>[\t\n\r]* {
    for (int i=0; i < yylength(); i++) {
        appendToCbuf(' ');
    }
}

<TAG_QSTRING_CDATA_BUFFERED>"&" |
<TAG_SQSTRING_CDATA_BUFFERED>"&" {
    // prevState is already set from the <TAG>"\"" or <TAG>"\'" rule
    yybegin(TAG_VALUE_ENTITYREF);
}

<TAG_QSTRING_NORMALIZE_BUFFERED>"&" |
<TAG_SQSTRING_NORMALIZE_BUFFERED>"&" {
    needsNormalization = true;

    // prevState is already set from the <TAG>"\"" or <TAG>"\'" rule
    yybegin(TAG_VALUE_ENTITYREF);
}

<TAG_QSTRING_CDATA_BUFFERED>"\""/[ \t\n\r>/] |
<TAG_SQSTRING_CDATA_BUFFERED>"\'"/[ \t\n\r>/] {
      yybegin(tagState);
      String value;

      // Cache and internalize short strings and all URIs
      if (cbuflen < 4 || attributeQName == "xmlns")
        value = stringConverter.convert(cbuf,0,cbuflen);
      else
        value = new String(cbuf,0,cbuflen);

      addAttribute(attributeURI,attributeLocalName,attributeQName,
                   attributeValueType, value);
}


<TAG_QSTRING_NORMALIZE>{ws}"\""/[ \t\n\r>/] |
<TAG_SQSTRING_NORMALIZE>{ws}"\'"/[ \t\n\r>/] {
    yybegin(tagState);
    addAttribute(attributeURI,attributeLocalName,
                 attributeQName,attributeValueType,"");
}

/* The unlikely chance that the string is already normalized.
 * We comment it to save some states.
<TAG_QSTRING_NORMALIZE>[^& \t\r\n<\"]+(" "[^&\t\r\n<\"]+)*"\""/[ \t\n\r>/] |
<TAG_SQSTRING_NORMALIZE>[^& \t\r\n<\']+(" "[^&\t\r\n<\']+)*"\'"/[ \t\n\r>/] {
    yybegin(tagState);
    addAttribute(attributeURI,attributeLocalName,
                 attributeQName,attributeValueType,
                 yytext(0,yylength()-1));
}
*/

<TAG_QSTRING_NORMALIZE> {
    [^& \t\r\n<\"]+ {
        clearCbuf();
        prevState = TAG_QSTRING_NORMALIZE_BUFFERED;
        yybegin(prevState);
        appendToCbuf(yy_buffer,yy_startRead,yy_markedPos-yy_startRead);
    }

    "&" {
        clearCbuf();
        prevState = TAG_QSTRING_NORMALIZE_BUFFERED;
        needsNormalization = true;
        yybegin(TAG_VALUE_ENTITYREF);
    }

    {ws} {
        clearCbuf();
        prevState = TAG_QSTRING_NORMALIZE_BUFFERED;
        yybegin(prevState);
    }
}

<TAG_SQSTRING_NORMALIZE> {
    [^& \t\r\n<\']+ {
        clearCbuf();
        prevState = TAG_SQSTRING_NORMALIZE_BUFFERED;
        yybegin(prevState);
        appendToCbuf(yy_buffer,yy_startRead,yy_markedPos-yy_startRead);
    }

    "&" {
        clearCbuf();
        prevState = TAG_SQSTRING_NORMALIZE_BUFFERED;
        needsNormalization = true;
        yybegin(TAG_VALUE_ENTITYREF);
    }


    {ws} {
        clearCbuf();
        prevState = TAG_SQSTRING_NORMALIZE_BUFFERED;
        yybegin(prevState);
    }
}


<TAG_QSTRING_NORMALIZE_BUFFERED>{ws}"\""/[ \t\n\r>/] |
<TAG_SQSTRING_NORMALIZE_BUFFERED>{ws}"\'"/[ \t\n\r>/] {
    yybegin(tagState);
    addAttribute(attributeURI,attributeLocalName,
                 attributeQName,attributeValueType,
                 new String(cbuf,0,cbuflen));
}

<TAG_QSTRING_NORMALIZE_BUFFERED,TAG_SQSTRING_NORMALIZE_BUFFERED> {
    // Replace multiple spaces with one space in normalized values
    {ws} { appendToCbuf(' '); }
}

/************************************************************************
 * End of rules for parsing non-DTD tags
 ************************************************************************/






/************************************************************************
 * Rules for parsing entity references within DTD tags as well as elements
 ************************************************************************/

// Entity replacement within CDATA
<ENTITYREF> {
    "amp;"  { yybegin(baseState); parser.reportCdata('&'); }
    "quot;" { yybegin(baseState); parser.reportCdata('"'); }
    "apos;" { yybegin(baseState); parser.reportCdata('\''); }
    "lt;"   { yybegin(baseState); parser.reportCdata('<'); }
    "gt;"   { yybegin(baseState); parser.reportCdata('>'); }

    "#"[0-9]+";" {
        yybegin(baseState);
        try {
            clearCbuf();
            parseEncodedChar(yy_buffer,yy_startRead+1,yylength()-2,10);
            parser.reportCdata(cbuf,0,cbuflen);
        }
        catch (IllegalCharException e) {
            throw fatalError("Invalid character entity reference: &"+yytext());
        }
    }


    "#x"[0-9a-fA-F]+";"   {
        yybegin(baseState);
        try {
            clearCbuf();
            parseEncodedChar(yy_buffer,yy_startRead+2,yylength()-3,16);
            parser.reportCdata(cbuf,0,cbuflen);
        }
        catch (IllegalCharException e) {
            throw fatalError("Invalid character entity reference: &"+yytext());
        }
    }

    {Name}";" {
        yybegin(baseState);

        int token = handleEntityRef(yytext2(0,yylength()-1),EntityManager.GENERAL);
        if (token != 0)
            return token;
    }
}


/* Entity replacement within an attribute value */
<TAG_VALUE_ENTITYREF> {
    "amp;" { appendToCbuf('&'); yybegin(prevState); }
    "quot;" { appendToCbuf('\"'); yybegin(prevState); }
    "apos;" { appendToCbuf('\'');  yybegin(prevState); }
    "lt;" { appendToCbuf('<');  yybegin(prevState); }
    "gt;" { appendToCbuf('>');  yybegin(prevState); }
}


<TAG_VALUE_ENTITYREF,DTD_TAG_VALUE_STD_ENTITYREF> {
    "#"[0-9]+";" {
        yybegin(prevState);
        try {
            parseEncodedChar(yy_buffer,yy_startRead+1,yylength()-2,10);
        }
       catch (ClassCastException e) {
            throw fatalError("Invalid character entity reference: &"+yytext());
       }
    }

    "#x"[0-9a-fA-F]+";"   {
        yybegin(prevState);
         try {
             parseEncodedChar(yy_buffer,yy_startRead+2,yylength()-3,16);
         }
         catch (ClassCastException e) {
             throw fatalError("Invalid character entity reference: &"+yytext());
         }
     }
}


<TAG_VALUE_ENTITYREF>{Name}";" {
    if (!handleLiteralEntityRef(yytext2(0,yylength()-1),EntityManager.GENERAL)) {
        appendToCbuf('&');
        appendToCbuf(yy_buffer,yy_startRead,yy_markedPos-yy_startRead);
        yybegin(prevState);
    }
 }


// Ignore general entity references in DTD literal.
<DTD_TAG_VALUE_STD_ENTITYREF>{Name}";" {
    appendToCbuf('&');
    appendToCbuf(yy_buffer,yy_startRead,yylength());
    yybegin(prevState);
}

<DTD_TAG_VALUE_PARAM_ENTITYREF>{Name}";" {
    if (isTopEntity())
        throw fatalError("Parameter entities may not appear in the internal subset");

    if (!handleLiteralEntityRef(yytext2(0,yylength()-1),EntityManager.PARAMETER)) {
        appendToCbuf('%');
        appendToCbuf(yy_buffer,yy_startRead,yy_markedPos-yy_startRead);
        yybegin(prevState);
    }
}




/************************************************************************
 * Rules for parsing entities within an attribute value or DTD literal
 ************************************************************************/

<TAG_VALUE_ENTITY> {
    [^&<\t\n\r]* {
        appendToCbuf(yy_buffer,yy_startRead,yy_markedPos-yy_startRead);
    }

    "&"    {
        yybegin(TAG_VALUE_ENTITYREF);
    }

    [\t\n\r] {
        appendToCbuf(' ');
    }
}



/* External literal within a DTD:
 * 1) Report processing instructions
 * 2) On EOF, continue parsing the literal
*/
<DTD_TAG_VALUE_EXTERNAL_ENTITY>{
    {ws} { yybegin(DTD_TAG_VALUE_ENTITY); }

    [^ \t\n][^&%]* {
        appendToCbuf(yy_buffer,yy_startRead,yy_markedPos-yy_startRead);
        yybegin(DTD_TAG_VALUE_ENTITY);
    }
}

<DTD_TAG_VALUE_ENTITY> {
    <DTD_TAG_VALUE_EXTERNAL_ENTITY> {
        "&"    { yybegin(DTD_TAG_VALUE_STD_ENTITYREF); }
        "%" { yybegin(DTD_TAG_VALUE_PARAM_ENTITYREF); }
    }

    // Anything else is considered text for the literal
    [^&%]*       { appendToCbuf(yy_buffer,yy_startRead,yy_markedPos-yy_startRead); }
}





/************************************************************************
 * Returning from the end of a parsed entity
 ************************************************************************/

<TAG_VALUE_ENTITYREF,DTD_COMMENT,ENTITYREF,PI,PI_WS,TAG_NS,TAG_START_NS,TAG_VALUE,CLOSE_TAG,CLOSE_TAG_NS><<EOF>> {
    throw fatalError("Entity is not well-formed (ending lex state: " + yystate() + ")");
}


<<EOF>> {

    if (yymoreStreams()) {
        yypopStream();

        if (isEntityBeingParsed) {
            if (currentEntity != null)
                currentEntity.close();
            currentEntity = (Entity) entityStack.pop();
        }

        boolean prevReturnEndToken = returnEntityEndToken;
        boolean prevIsParamEntity = isParamEntity;

        popEntityState();


        if (prevReturnEndToken)
            return Piccolo.ENTITY_END;
        else if (prevIsParamEntity)
            return Piccolo.WHITESPACE;
    }
    else
        return 0;
}




// Catch-all
.|\n          {
    throw fatalError("Unexpected character encountered (lex state " + yystate() + "): '" + yytext() + "'");
}
