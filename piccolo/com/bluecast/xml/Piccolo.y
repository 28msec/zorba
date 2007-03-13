%{
package com.bluecast.xml;

import org.xml.sax.*;
import org.xml.sax.helpers.*;
import org.xml.sax.ext.*;
import java.io.*;
import java.net.MalformedURLException;
import com.bluecast.util.*;
import com.bluecast.io.*;
import java.util.*;

/*
 * $Id: Piccolo.y,v 1.10 2004/07/11 09:37:37 yuvalo Exp $
 *
 * 2003-06-10 - MODIFIED to provide access to <?xml?> definition
 *              and startLocator
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

 /**
  * Piccolo is a small, high-performance SAX1 and SAX2 XML parser.
  * As per the SAX2 specification, namespace handling is on by
  * default. You can improve performance by turning it off.
  *
  * Note that if used in SAX1 mode, namespace handling is
  * automatically turned off.
  */
%}

/* YACC generation options */
%Jclass Piccolo
%Jsemantic String
%Jnorun
%Jnodebug
%Jthrows SAXException, IOException
%Jimplements org.xml.sax.Parser,org.xml.sax.Locator,org.xml.sax.XMLReader
%Jnoconstruct
%Jfinal

/* YACC Declarations */
%token CDATA TAG_END
%token PI NAME STRING EQ
%token OPEN_TAG CLOSE_TAG EMPTY_TAG
%token WHITESPACE
%token DTD_START DTD_START_SKIPEXTERNAL SYSTEM PUBLIC REQUIRED IMPLIED FIXED LPAREN RPAREN LBRACKET
%token PIPE ENTITY_DECL_START ATTLIST_START NOTATION_START
%token RBRACKET_END DOUBLE_RBRACKET_END PERCENT
%token ENUMERATION NOTATION CDATA ID IDREF IDREFS ENTITY ENTITIES NMTOKEN
%token NMTOKENS ENTITY_REF ENTITY_END
%token INTERNAL_ENTITY_REF EXTERNAL_ENTITY_REF SKIPPED_ENTITY_REF
%token PREFIXED_NAME UNPREFIXED_NAME NDATA COMMENT
%token CONDITIONAL_START IGNORED_CONDITIONAL_START INCLUDE IGNORE
%token MODIFIER PCDATA ELEMENT_DECL_START EMPTY ANY
%token STAR COMMA QUESTION PLUS
/* %token XML_DECL_START XML_DECL_END VERSION ENCODING STANDALONE */
%token XML_DOC_DECL XML_TEXT_DECL XML_DOC_OR_TEXT_DECL

/* Grammar follows */
%%

document: xml_decl dtd body epilog
         | xml_decl body epilog
;


xml_decl: XML_DOC_DECL | XML_DOC_OR_TEXT_DECL | /* empty */
;

xml_text_decl: XML_TEXT_DECL | XML_DOC_OR_TEXT_DECL
;

body:   EMPTY_TAG
        | OPEN_TAG content CLOSE_TAG
        | misc body
;

epilog: misc epilog
        | /* empty */
;


misc: WHITESPACE
    | PI
    | COMMENT
;

ws: WHITESPACE
  | ws WHITESPACE
;

opt_ws: /* empty */
      | ws
;



dtd:
    /* Internal/Name only */
    DTD_START NAME opt_ws TAG_END {
        dtdName = $2;
        lexer.yybegin(0);
        reportStartDTD(dtdName,null,null);
        reportEndDTD();
    }
    | dtd_only_internal_start dtd_content RBRACKET_END {
        // Internal subset only
        lexer.yybegin(0);
        reportEndDTD();
    }
    | dtd_with_external xml_text_decl dtd_content ENTITY_END {
        // Internal+External or External only with an <?xml?> declaration
        lexer.yybegin(0);
        reportEndDTD();
    }
    | dtd_with_external dtd_content ENTITY_END {
        // Internal+External or External only with no <?xml?> declaration
        lexer.yybegin(0);
        reportEndDTD();
    }
    | DTD_START_SKIPEXTERNAL NAME ws external_id opt_ws TAG_END {
        // External subset with no internal subset. Skip external
        dtdName = $2;
        lexer.yybegin(0);
        reportStartDTD(dtdName,pubID,sysID);
        reportEndDTD();
    }
    | misc dtd
;

dtd_with_external: dtd_with_external_start TAG_END {
        // External subset with no internal subset
        lexer.pushEntity("[dtd]",dtdPubID,dtdSysID,false,true);
        lexer.yybegin(lexer.DTD);
    }

    | dtd_with_external_start LBRACKET dtd_content RBRACKET_END {
        // Both external and internal subsets. Internal comes first.
        lexer.pushEntity("[dtd]",dtdPubID,dtdSysID,false,true);
        lexer.yybegin(lexer.DTD);
    }
;


dtd_with_external_start:
    DTD_START NAME ws SYSTEM ws STRING opt_ws {
        dtdName = lexer.normalizeValue($2);
        dtdPubID = null;
        dtdSysID = lexer.normalizeValue($6);
        reportStartDTD(dtdName,dtdPubID,dtdSysID);
    }

    | DTD_START NAME ws PUBLIC ws STRING ws STRING opt_ws {
        dtdName = $2;
        dtdPubID = lexer.normalizeValue($6);
        dtdSysID = lexer.normalizeValue($8);
        reportStartDTD(dtdName,dtdPubID,dtdSysID);
    }
;

dtd_only_internal_start:
    DTD_START NAME LBRACKET {
        dtdName = $2;
        reportStartDTD(dtdName,null,null);
    }
    | DTD_START_SKIPEXTERNAL NAME LBRACKET {
        dtdName = $2;
        reportStartDTD(dtdName,null,null);
    }
    | DTD_START_SKIPEXTERNAL NAME ws external_id LBRACKET {
        dtdName = $2;
        reportStartDTD(dtdName,pubID,sysID);
    }
;


external_id: SYSTEM ws STRING { pubID=null; sysID=lexer.normalizeValue($3); }
      | PUBLIC ws STRING ws STRING {
            pubID=lexer.normalizeValue($3);
            sysID=lexer.normalizeValue($5);
        }
;

dtd_content: /* empty */
  | dtd_content dtd_conditional
  | dtd_content dtd_entity
  | dtd_content dtd_attlist
  | dtd_content dtd_notation
  | dtd_content misc
  | dtd_content dtd_element
  | dtd_content INTERNAL_ENTITY_REF dtd_content
  | dtd_content EXTERNAL_ENTITY_REF dtd_content
  | dtd_content EXTERNAL_ENTITY_REF xml_text_decl dtd_content
;

dtd_conditional:
    CONDITIONAL_START dtd_include dtd_content DOUBLE_RBRACKET_END
  | CONDITIONAL_START dtd_ignore ignored_dtd_content DOUBLE_RBRACKET_END {
        lexer.yybegin(lexer.DTD);
  }



dtd_include: INCLUDE opt_ws LBRACKET {
    lexer.yybegin(lexer.DTD);
}
    | ws dtd_include
;

dtd_ignore: IGNORE opt_ws LBRACKET {
    lexer.yybegin(lexer.DTD_IGNORE);
}
    | ws dtd_ignore
;

ignored_dtd_content: /* empty */
        | ignored_dtd_content IGNORED_CONDITIONAL_START ignored_dtd_content DOUBLE_RBRACKET_END
;



dtd_entity:
    ENTITY_DECL_START ws NAME ws STRING opt_ws TAG_END {
        lexer.entityManager.putInternal($3,$5,EntityManager.GENERAL);
        if (declHandler != null)
            declHandler.internalEntityDecl($3,$5);
    }
    | ENTITY_DECL_START ws NAME ws external_id opt_ws TAG_END {
        try {
            lexer.entityManager.putExternal(lexer.currentEntity,$3,pubID,sysID,EntityManager.GENERAL);
            if (declHandler != null)
                declHandler.externalEntityDecl($3,pubID,resolveSystemID(sysID));
        }
        catch (MalformedURLException e) {
            reportFatalError("Invalid system identifier: "
                         + sysID + "; " + e.getMessage());
        }
    }
    | ENTITY_DECL_START ws NAME ws external_id ws NDATA ws NAME opt_ws TAG_END {
        try {
            lexer.entityManager.putUnparsed(lexer.currentEntity,$3,pubID,sysID,$9,EntityManager.GENERAL);
            reportUnparsedEntityDecl($3,pubID,sysID,$9);

        }
        catch (MalformedURLException e) {
            reportFatalError("Invalid system identifier: "
                         + sysID + "; " + e.getMessage());
        }
    }
    | ENTITY_DECL_START ws PERCENT NAME ws STRING opt_ws TAG_END {
        lexer.entityManager.putInternal($4,$6,EntityManager.PARAMETER);
        if (declHandler != null)
            declHandler.internalEntityDecl("%"+$4,$6);
    }
    | ENTITY_DECL_START ws PERCENT NAME ws external_id opt_ws TAG_END {
        try {
            lexer.entityManager.putExternal(lexer.currentEntity,$4,pubID,sysID,EntityManager.PARAMETER);
            if (declHandler != null)
                declHandler.externalEntityDecl("%"+$4,pubID,resolveSystemID(sysID));
        }
        catch (MalformedURLException e) {
            reportFatalError("Invalid system identifier: "
                         + sysID + "; " + e.getMessage());
        }
    }
    | ENTITY_DECL_START ws PERCENT NAME external_id ws NDATA ws NAME opt_ws TAG_END {
        try {
            lexer.entityManager.putUnparsed(lexer.currentEntity,$4,pubID,sysID,$9,EntityManager.PARAMETER);
            reportUnparsedEntityDecl($4,pubID,sysID,$9);

        }
        catch (MalformedURLException e) {
            reportFatalError("Invalid system identifier: "
                         + sysID + "; " + e.getMessage());
        }
    }
;


dtd_notation: NOTATION_START ws NAME ws external_id opt_ws TAG_END {
                reportNotationDecl($3,pubID,sysID);
              }
            | NOTATION_START ws NAME ws PUBLIC ws STRING opt_ws TAG_END {
                reportNotationDecl($3,lexer.normalizeValue($7),null);
              }
;


dtd_attlist: attlist_start att_def_list opt_ws TAG_END {
	lexer.defineElement(elementDefinition.getName(),elementDefinition);
}
;

attlist_start: ATTLIST_START ws NAME {
	// Look up this element. If we've seen previous ATTLIST definitions for it, we'll add these to it.
	elementDefinition = lexer.getElement($3);
	if (elementDefinition == null)
		elementDefinition = new ElementDefinition($3);
}


att_def_list: /* empty */
			| att_def_list ws att_def
;


att_def:
    PREFIXED_NAME ws att_type ws REQUIRED {
        lexer.yybegin(lexer.DTD_ATT_NAME);
        addPrefixedAttributeDefinition($1,attributeType,AttributeDefinition.REQUIRED,null);
    }
    | UNPREFIXED_NAME ws att_type ws REQUIRED {
        lexer.yybegin(lexer.DTD_ATT_NAME);
        addAttributeDefinition($1,attributeType,AttributeDefinition.REQUIRED,null);
    }
    | PREFIXED_NAME ws att_type ws IMPLIED {
        lexer.yybegin(lexer.DTD_ATT_NAME);
        addPrefixedAttributeDefinition($1,attributeType,AttributeDefinition.IMPLIED,null);
    }
    | UNPREFIXED_NAME ws att_type ws IMPLIED {
        lexer.yybegin(lexer.DTD_ATT_NAME);
        addAttributeDefinition($1,attributeType,AttributeDefinition.IMPLIED,null);
    }
    | PREFIXED_NAME ws att_type ws FIXED ws STRING {
        lexer.yybegin(lexer.DTD_ATT_NAME);
        addPrefixedAttributeDefinition($1,attributeType,AttributeDefinition.FIXED,$7);
    }
    | UNPREFIXED_NAME ws att_type ws FIXED ws STRING {
        lexer.yybegin(lexer.DTD_ATT_NAME);
        addAttributeDefinition($1,attributeType,AttributeDefinition.FIXED,$7);
    }
    | PREFIXED_NAME ws att_type ws STRING {
        lexer.yybegin(lexer.DTD_ATT_NAME);
        addPrefixedAttributeDefinition($1,attributeType,0,$5);
    }
    | UNPREFIXED_NAME ws att_type ws STRING {
        lexer.yybegin(lexer.DTD_ATT_NAME);
        addAttributeDefinition($1,attributeType,0,$5);
    }
;


att_type: CDATA		{ attributeType = AttributeDefinition.CDATA; }
		  | ID			{ attributeType = AttributeDefinition.ID; }
		  | IDREF		{ attributeType = AttributeDefinition.IDREF; }
		  | IDREFS		{ attributeType = AttributeDefinition.IDREFS; }
		  | ENTITY		{ attributeType = AttributeDefinition.ENTITY; }
		  | ENTITIES	{ attributeType = AttributeDefinition.ENTITIES; }
		  | NMTOKEN		{ attributeType = AttributeDefinition.NMTOKEN; }
		  | NMTOKENS	{ attributeType = AttributeDefinition.NMTOKENS; }
		  | LPAREN opt_ws word_list opt_ws RPAREN {
                attributeType = AttributeDefinition.ENUMERATION;
          }
		  | NOTATION ws LPAREN opt_ws word_list opt_ws RPAREN	{
                attributeType = AttributeDefinition.NOTATION;
          }
;

word_list:
    NAME {
        if (declHandler != null)
            modelBuffer.append($1);
    }
    | word_list opt_ws PIPE opt_ws NAME {
        if (declHandler != null) {
            modelBuffer.append('|');
            modelBuffer.append($5);
        }
    }
;


dtd_element: ELEMENT_DECL_START ws NAME ws element_spec opt_ws TAG_END {
    if (declHandler != null)
        declHandler.elementDecl($3,$5);
}
;

element_spec:
      EMPTY {
        if (declHandler != null)
            $$ = "EMPTY";
      }
    | ANY {
        if (declHandler != null)
            $$ = "ANY";
    }
    | element_spec_mixed {
        if (declHandler != null)
            $$ = $1;
    }
    | element_spec_children {
        if (declHandler != null)
            $$ = $1;
    }
;

element_spec_mixed:
    LPAREN opt_ws PCDATA opt_ws RPAREN STAR {
        if (declHandler != null)
            $$ = "(#PCDATA)*";
    }
    | LPAREN opt_ws PCDATA opt_ws RPAREN {
        if (declHandler != null)
            $$ = "(#PCDATA)";
    }
    | LPAREN opt_ws PCDATA opt_ws PIPE opt_ws word_list opt_ws RPAREN STAR {
        if (declHandler != null)
            $$ = "(#PCDATA|" + modelBuffer.toString() + ")*";
    }
    | WHITESPACE element_spec_mixed {
        if (declHandler != null)
            $$ = $2;
    }
;

element_spec_children:
    element_choice element_modifier {
        if (declHandler != null)
            $$ = $1 + $2;
    }
    | element_seq element_modifier {
        if (declHandler != null)
            $$ = $1 + $2;
    }
    | WHITESPACE element_spec_children {
        if (declHandler != null)
            $$ = $2;
    }
;

element_cp_pipe_list:
    element_cp opt_ws PIPE opt_ws element_cp {
        if (declHandler != null)
            $$ = $1 + "|" + $5;
    }
    | element_cp opt_ws PIPE opt_ws element_cp_pipe_list {
        if (declHandler != null)
            $$ = $1 + "|" + $5;
    }
;

element_cp_comma_list:
    element_cp {
        if (declHandler != null)
            $$ = $1;
    }
    | element_cp opt_ws COMMA element_cp_comma_list {
        if (declHandler != null)
            $$ = $1 + "," + $4;
    }
;

element_cp:
    NAME element_modifier opt_ws {
        if (declHandler != null)
            $$ = $1 + $2;
    }
    | element_choice element_modifier opt_ws {
        if (declHandler != null)
            $$ = $1 + $2;
    }
    | element_seq element_modifier opt_ws {
        if (declHandler != null)
            $$ = $1 + $2;
    }
    | WHITESPACE element_cp {
        if (declHandler != null)
            $$ = $2;
    }
;


element_choice:
    LPAREN element_cp_pipe_list opt_ws RPAREN {
        if (declHandler != null)
            $$ = "(" + $2 + ")";
    }
    | WHITESPACE element_choice {
        if (declHandler != null)
            $$ = $2;
    }
;

element_seq:
    LPAREN element_cp_comma_list opt_ws RPAREN {
        if (declHandler != null)
            $$ = "(" + $2 + ")";
    }
    | WHITESPACE element_seq {
        if (declHandler != null)
            $$ = $2;
    }
;

element_modifier:
    QUESTION {
        if (declHandler != null)
            $$ = "?";
    }
    | STAR {
        if (declHandler != null)
            $$ = "*";
    }
    | PLUS {
        if (declHandler != null)
            $$ = "+";
    }
    | /* empty */ {
        if (declHandler != null)
            $$ = "";
    }
;


// All content except for entity references is not tokenized but
// instead is handled within the lexer.
content: /* empty */
          | content INTERNAL_ENTITY_REF content ENTITY_END {
                lexer.setTokenize(false);
          }

          | content EXTERNAL_ENTITY_REF content ENTITY_END {
                lexer.setTokenize(false);
          }

          | content EXTERNAL_ENTITY_REF xml_text_decl content ENTITY_END {
                lexer.setTokenize(false);
          }
          | content OPEN_TAG content CLOSE_TAG
          | content EMPTY_TAG
          | content PI
          | content COMMENT
          | content WHITESPACE {
                reportWhitespace();
          }
          | content CDATA
;



%%

DocumentHandler documentHandler = null;
DTDHandler dtdHandler = null;
ErrorHandler errorHandler = null;
ContentHandler contentHandler = null;
int saxVersion = 0;
int attributeType=-1;
StringBuffer modelBuffer = new StringBuffer(100);
ElementDefinition elementDefinition=null;
String pubID=null,sysID=null;
String dtdName=null,dtdPubID=null,dtdSysID=null;
PiccoloLexer lexer = new PiccoloLexer(this);
DocumentEntity docEntity = new DocumentEntity();
LexicalHandler lexHandler = null;
DeclHandler declHandler = null;
boolean parsingInProgress = false;

/// Create an instance of the Piccolo parser
public Piccolo() { }

/**
 * Create an instance with the same configuration
 * as the given instance. ContentHandler, DTDHandler, etc.
 * will not be copied.
 */
public Piccolo(Piccolo template) {
    fNamespaces = template.fNamespaces;
    fNamespacePrefixes = template.fNamespacePrefixes;
    fExternalGeneralEntities = template.fExternalGeneralEntities;
    fExternalParameterEntities = template.fExternalParameterEntities;
    fLexicalParameterEntities = template.fLexicalParameterEntities;
    lexer.enableNamespaces(fNamespaces);
    fResolveDTDURIs = template.fResolveDTDURIs;
}

private void reset() {
    modelBuffer.setLength(0);
    pubID = sysID = dtdName = dtdPubID = dtdSysID = null;
    elementDefinition = null;
}

// Make sure it's okay to start parsing
private void validateParseState() throws SAXException {
    if (!fNamespaces && !fNamespacePrefixes) {
        throw new FatalParsingException("The 'namespaces' and 'namespace-prefixes' features must not both be false");
    }
}
public void setDebug(boolean debug) {
    yydebug = debug;
}


/************************************************************************
 * Methods common to both SAX1 and SAX2
 ************************************************************************/

public void parse(InputSource source) throws IOException, SAXException {
    try {
        reset();
        validateParseState();
        try {
            docEntity.reset(source);
            lexer.reset(docEntity);
        }
        finally {
            reportStartDocument();
        }
        yyparse();
    }
    catch (IllegalCharException e) {
        reportFatalError(e.getMessage(),e);
    }
    catch (FileFormatException e) {
        reportFatalError(e.getMessage(),e);
    }
    catch (FatalParsingException e) {
        reportFatalError(e.getMessage(),e.getException());
    }
    finally {
        reportEndDocument();
    }
}



public void parse(String sysID) throws IOException, SAXException {
    try {
        reset();
        validateParseState();
        try {
            docEntity.reset(sysID);
            lexer.reset(docEntity);
        }
        finally {
            reportStartDocument();
        }
        yyparse();
    }
    catch (IllegalCharException e) {
        reportFatalError(e.getMessage(),e);
    }
    catch (FileFormatException e) {
        reportFatalError(e.getMessage(),e);
    }
    catch (FatalParsingException e) {
        reportFatalError(e.getMessage(),e.getException());
    }
    finally {
        reportEndDocument();
    }
}


/************************************************************************
 * SAX1 methods
 ************************************************************************/

public void setDocumentHandler(DocumentHandler handler) {
    documentHandler = handler;
    if (documentHandler != null) {
      saxVersion = 1;
      fNamespaces = false;
      lexer.enableNamespaces(false);
      fNamespacePrefixes = true;
      documentHandler.setDocumentLocator(this);
    }
    else
      saxVersion = 0;
}


public void setDTDHandler(DTDHandler handler) {
    dtdHandler = handler;
}

public void setEntityResolver(EntityResolver resolver) {
    lexer.entityManager.setResolver(resolver);
}

public void setErrorHandler(ErrorHandler handler) {
    errorHandler = handler;
}

public void setLocale(java.util.Locale locale) 
throws SAXException {
    if (!("en".equals(locale.getLanguage())))
        throw new SAXException("Only English (EN) locales are supported");
}

// Locator
public int getColumnNumber() { return lexer.getColumnNumber(); }
public int getLineNumber() { return lexer.getLineNumber(); }
public String getPublicId() { return lexer.getPublicID(); }
public String getSystemId() { return lexer.getSystemID(); }

// Locator which returns line/col info for the start of the token
private class StartLocator implements org.xml.sax.Locator
{
    public int getLineNumber ( ) { return Piccolo.this.lexer.tokenStartLine; }
    public int getColumnNumber ( ) { return -1; }
    public String getPublicId ( ) { return null; }
    public String getSystemId ( ) { return null; }
}

private StartLocator startLocator;

public Locator getStartLocator ( )
{
    if (startLocator == null)
        startLocator = new StartLocator();

    return startLocator;
}

public String getVersion ( )
{
    return lexer.getVersion();
}

public String getEncoding ( )
{
    return lexer.getEncoding();
}

/************************************************************************
 * SAX2 methods
 ************************************************************************/

public ContentHandler getContentHandler() { return contentHandler; }

public void setContentHandler(ContentHandler handler) {
    contentHandler = handler;

    if (contentHandler != null) {
      // Are we switching from SAX1? If so, turn namespace processing on
      if (saxVersion == 1) {
          fNamespaces = true;
          lexer.enableNamespaces(true);
          fNamespacePrefixes = false;
      }

      saxVersion = 2;
      contentHandler.setDocumentLocator(this);
    }
    else
        saxVersion = 0;
}

public DTDHandler getDTDHandler() { return dtdHandler; }
public EntityResolver getEntityResolver() { return lexer.entityManager.getResolver(); }
public ErrorHandler getErrorHandler() { return errorHandler; }


// SAX2 Features
boolean fNamespaces=true,fNamespacePrefixes=false,fResolveDTDURIs=true;
boolean fExternalGeneralEntities=true,fExternalParameterEntities=true;
boolean fLexicalParameterEntities = true;

public boolean getFeature(String name)
    throws SAXNotSupportedException,SAXNotRecognizedException {
    if (name.equals("http://xml.org/sax/features/namespaces"))
        return fNamespaces;
    else if (name.equals("http://xml.org/sax/features/namespace-prefixes"))
        return fNamespacePrefixes;
    else if (name.equals("http://xml.org/sax/features/external-general-entities"))
        return fExternalGeneralEntities;
    else if (name.equals("http://xml.org/sax/features/external-parameter-entities"))
        return fExternalGeneralEntities;
    else if (name.equals("http://xml.org/sax/features/lexical-handler/parameter-entities"))
        return fLexicalParameterEntities;
    else if (name.equals("http://xml.org/sax/features/string-interning"))
        return true;
    else if (name.equals("http://xml.org/sax/features/is-standalone"))
        return docEntity.isStandalone();
    else if (name.equals("http://xml.org/sax/features/resolve-dtd-uris"))
        return fResolveDTDURIs;
    else if (name.equals("http://xml.org/sax/features/use-attributes2")
          || name.equals("http://xml.org/sax/features/validation")
          || name.equals("http://xml.org/sax/features/use-locator2")
          || name.equals("http://xml.org/sax/features/use-entity2")
          || name.equals("http://xml.org/sax/features/use-locator2"))
          return false;
    else
        throw new SAXNotRecognizedException(name);
}

public void setFeature(String name, boolean value)
throws SAXNotSupportedException,SAXNotRecognizedException {
    if (name.equals("http://xml.org/sax/features/namespaces")) {
        if (parsingInProgress) {
            throw new SAXNotSupportedException("Can't change namespace settings while parsing");
        }
        fNamespaces = value;
        lexer.enableNamespaces(value);
    }
    else if (name.equals("http://xml.org/sax/features/namespace-prefixes")) {
        if (parsingInProgress) {
            throw new SAXNotSupportedException("Can't change namespace settings while parsing");
        }
        fNamespacePrefixes = value;
    }
    else if (name.equals("http://xml.org/sax/features/external-general-entities")) {
        fExternalGeneralEntities = value;
    }
    else if (name.equals("http://xml.org/sax/features/external-parameter-entities")) {
        fExternalParameterEntities = value;
    }
    else if (name.equals("http://xml.org/sax/features/lexical-handler/parameter-entities")) {
        fLexicalParameterEntities = value;
    }
    else if (name.equals("http://xml.org/sax/features/resolve-dtd-uris")) {
        fResolveDTDURIs = value;
    }
    else if (name.equals("http://xml.org/sax/features/validation")) {
        if (value)
            throw new SAXNotSupportedException("validation is not supported");
    }
    else if (name.equals("http://xml.org/sax/features/string-interning")) {
        if (!value)
            throw new SAXNotSupportedException("strings are always internalized");
    }
    else if (name.equals("http://xml.org/sax/features/use-attributes2")
          || name.equals("http://xml.org/sax/features/validation")
          || name.equals("http://xml.org/sax/features/use-locator2")
          || name.equals("http://xml.org/sax/features/use-entity2")
          || name.equals("http://xml.org/sax/features/use-locator2")) {
        if (value)
            throw new SAXNotSupportedException(name);
    }
    else
        throw new SAXNotRecognizedException(name);
}

public Object getProperty(String name)
throws SAXNotRecognizedException, SAXNotSupportedException {
    if (name.equals("http://xml.org/sax/properties/declaration-handler"))
        return declHandler;
    else
    if (name.equals("http://xml.org/sax/properties/lexical-handler"))
        return lexHandler;
    else
        throw new SAXNotRecognizedException(name);
}

public void setProperty(String name,Object value)
throws SAXNotRecognizedException, SAXNotSupportedException {
    if (name.equals("http://xml.org/sax/properties/declaration-handler")) {
        try {
            declHandler = (DeclHandler) value;
        }
        catch (ClassCastException e) {
            throw new SAXNotSupportedException("property value is not a DeclHandler");
        }
    }
    else
    if (name.equals("http://xml.org/sax/properties/lexical-handler")) {
        try {
            lexHandler = (LexicalHandler) value;
        }
        catch (ClassCastException e) {
            throw new SAXNotSupportedException("property value is not a LexicalHandler");
        }
    }
    else
        throw new SAXNotRecognizedException(name);
}


/************************************************************************
 * Methods used to call ContentHandlers or DocumentHandlers
 ************************************************************************/

void reportCdata() throws SAXException {
    reportCdata(lexer.cdataBuffer,lexer.cdataStart,lexer.cdataLength);
}

private char[] oneCharBuffer = new char[1];
void reportCdata(char c) throws SAXException {
    oneCharBuffer[0] = c;
    reportCdata(oneCharBuffer,0,1);
}

void reportCdata(char[] buf, int off, int len) throws SAXException {
    switch (saxVersion) {
        case 2:
            contentHandler.characters(buf,off,len);
            break;
        case 1:
            documentHandler.characters(buf,off,len);
            break;
    }
}


void reportWhitespace() throws SAXException {
    reportWhitespace(lexer.cdataBuffer,lexer.cdataStart,lexer.cdataLength);
}

void reportWhitespace(char[] buf, int off, int len)  throws SAXException {
    switch (saxVersion) {
      case 2:
        contentHandler.characters(buf,off,len);
        break;
      case 1:
        documentHandler.characters(buf,off,len);
        break;
    }
}


void reportError(String msg)  throws SAXException {
    if (errorHandler != null) {
      errorHandler.error(new SAXParseException(msg,getPublicId(),getSystemId(),getLineNumber(),getColumnNumber()));
    }
}


void reportFatalError(String msg)  throws SAXException {
  reportFatalError(msg,null);
}

void reportFatalError(String msg, Exception e)  throws SAXException {
  if (e != null) {
    StringWriter stackTrace = new StringWriter();
    e.printStackTrace(new PrintWriter(stackTrace));
    if (msg != null)
        msg += "\n" + stackTrace.toString();
    else
        msg = stackTrace.toString();
  }

  SAXParseException spe = 
       new SAXParseException(msg,getPublicId(),
                    getSystemId(),getLineNumber(),getColumnNumber(),e);

  if (errorHandler != null)
        errorHandler.fatalError(spe);
  else
        throw spe;
}


void reportSkippedEntity(String entity)  throws SAXException {
    if (saxVersion == 2) {
      contentHandler.skippedEntity(entity);
    }
}


void reportPI(String entity, String data)  throws SAXException {
    switch (saxVersion) {
        case 2:
            contentHandler.processingInstruction(entity,data);
            break;
        case 1:
            documentHandler.processingInstruction(entity,data);
            break;
    }
}

void reportUnparsedEntityDecl(String entity, String pubID, String sysID, String notation)  throws SAXException {
    if (dtdHandler != null) {
      dtdHandler.unparsedEntityDecl(entity,pubID,resolveSystemID(sysID),notation);
    }
}

void reportNotationDecl(String name, String pubID, String sysID)  throws SAXException {
    if (dtdHandler != null)
        dtdHandler.notationDecl(name,pubID,resolveSystemID(sysID));
}


void reportStartTag(String ns, String entity, String qEntity)  throws SAXException {
    switch (saxVersion) {
      case 2:
        contentHandler.startElement(ns,entity,qEntity,lexer.attribs);
        break;
      case 1:
        documentHandler.startElement(qEntity,lexer.attribs);
        break;
    }
}


void reportEndTag(String ns, String entity, String qEntity)  throws SAXException {
    switch (saxVersion) {
      case 2:
        contentHandler.endElement(ns,entity,qEntity);
        break;
      case 1:
        documentHandler.endElement(qEntity);
        break;
    }
}


void reportStartPrefixMapping(String prefix, String uri)  throws SAXException {
    if (saxVersion == 2) {
        contentHandler.startPrefixMapping(prefix,uri);
    }
}

void reportEndPrefixMapping(String prefix)  throws SAXException {
    if (saxVersion == 2) {
        contentHandler.endPrefixMapping(prefix);
    }
}



void reportStartDocument()  throws SAXException {
    parsingInProgress = true;
    switch (saxVersion) {
      case 2:
        contentHandler.startDocument();
        break;
      case 1:
        documentHandler.startDocument();
        break;
    }
}

void reportEndDocument()  throws SAXException {
    parsingInProgress = false;
    switch (saxVersion) {
      case 2:
        contentHandler.endDocument();
        break;
      case 1:
        documentHandler.endDocument();
        break;
    }
}

/************************************************************************
 * Methods used for SAX 2 extensions
 ************************************************************************/

// *** LexicalHandler ***

void reportStartDTD(String name, String pubID, String sysID)
throws SAXException {
    if (lexHandler != null)
        lexHandler.startDTD(name,pubID,sysID);
}

void reportEndDTD()
throws SAXException {
    if (lexHandler != null)
        lexHandler.endDTD();
}

void reportStartEntity(String name)
throws SAXException {
    if (lexHandler != null) {
        if (fLexicalParameterEntities || name.charAt(0) != '%')
            lexHandler.startEntity(name);
    }
}

void reportEndEntity(String name)
throws SAXException {
    if (lexHandler != null) {
        if (fLexicalParameterEntities || name.charAt(0) != '%')
            lexHandler.endEntity(name);
    }
}

void reportStartCdata()
throws SAXException {
    if (lexHandler != null)
        lexHandler.startCDATA();
}

void reportEndCdata()
throws SAXException {
    if (lexHandler != null)
        lexHandler.endCDATA();
}

void reportComment(char[] ch, int start, int length)
throws SAXException {
    if (lexHandler != null)
        lexHandler.comment(ch,start,length);
}


/************************************************************************
 * Miscellaneous methods used internally
 ************************************************************************/

private void addAttributeDefinition(String qName, int valueType, int defaultType, String defaultValue)
throws SAXException, IOException {
    String prefix="", localName="";
    if (fNamespaces) {
        localName = qName;
        if (qName == "xmlns" && defaultValue != null) // Internalize all URIs
            defaultValue.intern();
    }

    saveAttributeDefinition(prefix,localName,qName,valueType,defaultType,defaultValue);
}

private void addPrefixedAttributeDefinition(String qName, int valueType, int defaultType, String defaultValue)
throws SAXException, IOException {
    String prefix, localName;
    if (fNamespaces) {
        int colon = qName.indexOf(':');
        int len = qName.length();
        qName.getChars(0,len,lexer.cbuf,0);
        prefix = lexer.stringConverter.convert(lexer.cbuf,0,colon);
        localName = lexer.stringConverter.convert(lexer.cbuf,colon+1,len-(colon+1));
    }
    else {
        prefix=localName="";
    }

    saveAttributeDefinition(prefix,localName,qName,valueType,defaultType,defaultValue);
}

private void saveAttributeDefinition(String prefix,String localName,
                                     String qName, int valueType, int defaultType, String defaultValue)
throws SAXException, IOException {
    try {
        if (defaultValue != null) {
            if (valueType == AttributeDefinition.NMTOKEN || valueType == AttributeDefinition.NMTOKENS)
                defaultValue = lexer.normalizeValue(defaultValue);

            defaultValue = lexer.rescanAttributeValue(defaultValue);
        }

        if (declHandler != null) {
            String valueTypeString = null;
            if (valueType == AttributeDefinition.NOTATION) {
                modelBuffer.insert(0,"NOTATION (");
                modelBuffer.append(')');
                valueTypeString = modelBuffer.toString();
            }
            else
            if (valueType == AttributeDefinition.ENUMERATION) {
                modelBuffer.insert(0,'(');
                modelBuffer.append(')');
                valueTypeString = modelBuffer.toString();
            }
            else
                valueTypeString = AttributeDefinition.getValueTypeString(valueType);

            declHandler.attributeDecl(elementDefinition.getName(),qName,valueTypeString,
                                AttributeDefinition.getDefaultTypeString(defaultType),
                                defaultValue);

            modelBuffer.setLength(0);
        }


        elementDefinition.addAttribute(
            new AttributeDefinition(prefix,localName,qName,valueType,null,
                                    defaultType,defaultValue));
    }
    catch (DuplicateKeyException e) { // Attribute already exists; XML spec says ignore it
    }
}


private String resolveSystemID(String sysID) {
    String resolvedSysID;
    if (fResolveDTDURIs) {
        try {
            return EntityManager.resolveSystemID(docEntity.getSystemID(),sysID);
        }
        catch (MalformedURLException e) {
            return sysID;
        }
    }
    else 
        return sysID;
}



private int yylex() throws IOException, SAXException
{
    try {
     int tok = lexer.yylex();
     yylval = lexer.stringValue;
     lexer.stringValue = null;

    /* Uncomment for serious debugging
    if (yydebug) {
        if (tok == CDATA)
            System.out.println("Token: CDATA");
        else
            System.out.println("Token: " + yyname[tok] + " (" + yylval + ")");

        System.out.println("\tlexical state is now " + lexer.yystate() + ", line number " + getLineNumber() );
    }
    */

     return tok;
    }
    catch (IOException e) {
        while (lexer.currentEntity == null && lexer.entityStack.size() > 0) {
            lexer.currentEntity = (Entity) lexer.entityStack.pop();
            try {
                if (lexer.yymoreStreams())
                    lexer.yypopStream();
            }
            catch (IOException ie) {}
        }

        throw e;
    }
    catch (SAXException e) {
        while (lexer.currentEntity == null && lexer.entityStack.size() > 0) {
            lexer.currentEntity = (Entity) lexer.entityStack.pop();
            try {
                if (lexer.yymoreStreams())
                    lexer.yypopStream();
            }
            catch (IOException ie) {}
        }

        throw e;
    }


}


void yyerror(String msg) throws SAXException {
    // Check if this is because of an invalid entity reference
    if (yychar <= 0)
        throw new FatalParsingException("Unexpected end of file after " + yylval);
    else
        throw new FatalParsingException("Unexpected element: " + yyname[yychar]);
}








