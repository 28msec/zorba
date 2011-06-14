/*
 * Copyright 2006-2008 The FLWOR Foundation.
 * 
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 * 
 * http://www.apache.org/licenses/LICENSE-2.0
 * 
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */
#pragma once
#ifndef _SCHEMAVALIDATORFILTER_H
#define _SCHEMAVALIDATORFILTER_H

#include "common/common.h"
#ifndef ZORBA_NO_XMLSCHEMA

#include <vector>

#include <xercesc/framework/XMLDocumentHandler.hpp>
#include <xercesc/framework/XMLErrorReporter.hpp>
#include <xercesc/internal/XMLScanner.hpp>
#include <xercesc/validators/schema/SchemaElementDecl.hpp>
#include <xercesc/util/RefHash3KeysIdPool.hpp>

#if (XERCES_VERSION_MAJOR < 3)
#  define XERCESC_XMLSize_t unsigned int
#else
#  define XERCESC_XMLSize_t XMLSize_t
#endif

//daniel: this is to make cygwin work; xerces defines WIN32 in case of cygwin, which is wrong
#ifdef CYGWIN
#undef WIN32
#endif


namespace XERCES_CPP_NAMESPACE
{
  class SchemaGrammar;
  class IdentityConstraintHandler;
  class GrammarResolver;
}


namespace zorba
{

class DynamicContext;
class LocationInfo;
class QueryLoc;
class XercSchemaValidator;
class ValidationEventHandler;

/*******************************************************************************
  The SchemaValidatorFilter class implements a module that sits between an
  EventSchemaValidator and a XercSchemaValidator; it receives events from the
  EventSchemaValidator and propagates them to XercSchemaValidator.

  SchemaValidatorFilter is implemented as a subclass of Xerces::XMLScanner, 
  even though it is not really an XMLScanner. The reason is that certain
  "utility" methods that are provided by XMLScanner are needed either by
  SchemaValidatorFilter itself or by XercSchemaValidator. Furthermore,
  XercSchemaValidator is a subclass of Xerces::XMLValidator, which expects
  an XMLScanner as its input module.

  The following XMLScanner methods are needed:

  fScanner->incrementErrorCount();                 implemented
  fScanner->getValidationConstraintFatal();        implemented
  fScanner->getExitOnFirstFatal();                 implemented
  fScanner->getInException();                      implemented
  fScanner->getMemoryManager();                    implemented
  getScanner()->getEmptyNamespaceId();             implemented
  getScanner()->resolveQName();                    ***
  getScanner()->getURIText();                      implemented
  getScanner()->getDocHandler(); for docCharacters() ***
  getScanner()->getValidationContext();            implemented
  getScanner()->emitError();                       implemented
  getScanner()->getValidationSchemaFullChecking(); implemented

  XMLDocumentHandler:
  ------------------
  In general, XMLDocumentHandler provides the interface for the scanner to return
  XML document information up to the parser as it scans through the document.
********************************************************************************/
class SchemaValidatorFilter : 
    public XERCES_CPP_NAMESPACE::XMLScanner,
    private XERCES_CPP_NAMESPACE::XMLDocumentHandler,
    private XERCES_CPP_NAMESPACE::XMLErrorReporter
{
public:
  static const XMLCh DT_UNTYPED[];
  static const XMLCh DT_UNTYPED_ATOMIC[];

private:
  const QueryLoc                              & theLoc;

  bool                                          theStrictValidation;

  XMLCh                                       * theProcessorStipulatedTypeName;
  unsigned int                                  theProcessorStipulatedTypeUriId;

  XERCES_CPP_NAMESPACE::SchemaGrammar         * theSchemaGrammar;
  XERCES_CPP_NAMESPACE::
    IdentityConstraintHandler                 * theICHandler;
  XercSchemaValidator                         * theSchemaValidator;

  XERCES_CPP_NAMESPACE::RefHash3KeysIdPool
    <XERCES_CPP_NAMESPACE::SchemaElementDecl> * theElemNonDeclPool;

  XERCES_CPP_NAMESPACE::ElemStack::StackElem  * theParentStack;
  unsigned int                                  theElemDepth;

  bool                                          theElementToProcess;

  XERCES_CPP_NAMESPACE_QUALIFIER XMLBuffer      thePrefix;
  XERCES_CPP_NAMESPACE_QUALIFIER XMLBuffer      theUri;
  XERCES_CPP_NAMESPACE_QUALIFIER XMLBuffer      theLocalname;

  XERCES_CPP_NAMESPACE_QUALIFIER XMLBuffer      theContent;

  const XMLCh                                 * theXsiType;

  unsigned int                                  theAttrCount;

  ValidationEventHandler                      * theEventBuffer;

  bool                                          theErrorOccurred;

  // After an element is processed will contain the name of the substituted element 
  // if current is a substitution element, otherwise NULL
  XMLCh*                                        theSubstitutedElemName;
  XMLCh*                                        theSubstitutedElemUri;

public:
  SchemaValidatorFilter(
        bool strictValidation,
        ValidationEventHandler* eventBuffer,
        XERCES_CPP_NAMESPACE::GrammarResolver* grammarResolver,
        XERCES_CPP_NAMESPACE_QUALIFIER MemoryManager* mm,
        const QueryLoc& loc);

  virtual ~SchemaValidatorFilter();

  void reset();

  virtual void startDocumentEvent(
        const XMLCh *documentURI,
        const XMLCh *encoding);

  virtual void endDocumentEvent();

  virtual void startElementEvent(
        const XMLCh *prefix,
        const XMLCh *uri,
        const XMLCh *localname);

  virtual void endElementEvent(
        const XMLCh *prefix,
        const XMLCh *uri,
        const XMLCh *localname,
        const XMLCh *typeURI,
        const XMLCh *typeName);

  virtual void piEvent(const XMLCh *target, const XMLCh *value);

  virtual void textEvent(const XMLCh *value);

  virtual void textEvent(const XMLCh *chars, unsigned int length);

  virtual void commentEvent(const XMLCh *value);

  virtual void attributeEvent(
        const XMLCh *prefix,
        const XMLCh *uri,
        const XMLCh *localname, 
        const XMLCh *value,
        const XMLCh *typeURI,
        const XMLCh *typeName);

  virtual void endAttributesEvent();

  virtual void namespaceEvent(const XMLCh *prefix, const XMLCh *uri);

  virtual void startTypeEvent(const XMLCh *uri, const XMLCh *typeName);

  virtual void endTypeEvent();
  
  virtual const XMLCh* getTypeName();
  virtual const XMLCh* getTypeUri();
  
  virtual const XMLCh* getSubstitutedElemName()
  {   return theSubstitutedElemName; }

  virtual const XMLCh* getSubstitutedElemUri()
  {   return theSubstitutedElemUri;  }


private:
  //
  // XMLScanner
  //
  virtual const XMLCh *getName() const { return 0; }

  virtual XERCES_CPP_NAMESPACE_QUALIFIER NameIdPool<XERCES_CPP_NAMESPACE_QUALIFIER DTDEntityDecl> *getEntityDeclPool() 
  {
    return 0; 
  }

  virtual const XERCES_CPP_NAMESPACE_QUALIFIER NameIdPool<XERCES_CPP_NAMESPACE_QUALIFIER DTDEntityDecl> *getEntityDeclPool() const
  {
    return 0;
  }

  virtual unsigned int resolveQName(
        const XMLCh *const qName,
        XERCES_CPP_NAMESPACE_QUALIFIER XMLBuffer &prefixBufToFill,
        const short mode,
        int &prefixColonPos);

  virtual void scanDocument(
        const XERCES_CPP_NAMESPACE_QUALIFIER InputSource &src)
  {
  }

  virtual bool scanNext(
        XERCES_CPP_NAMESPACE_QUALIFIER XMLPScanToken &toFill) 
  {
    return false; 
  }

  virtual XERCES_CPP_NAMESPACE_QUALIFIER Grammar* loadGrammar(
        const XERCES_CPP_NAMESPACE_QUALIFIER InputSource &src,
        const short grammarType,
        const bool toCache) 
  {
    return 0;
  }
  
  virtual void scanCDSection() {}

  virtual void scanCharData(XERCES_CPP_NAMESPACE_QUALIFIER XMLBuffer &toToUse) 
  {
  }

  virtual EntityExpRes scanEntityRef(
        const bool inAttVal,
        XMLCh &firstCh,
        XMLCh &secondCh,
        bool &escaped)
  {
    return EntityExp_Returned; 
  }

  virtual void scanDocTypeDecl() {}

  virtual void scanReset(const XERCES_CPP_NAMESPACE_QUALIFIER InputSource &src)
  {
  }

  virtual void sendCharData(XERCES_CPP_NAMESPACE_QUALIFIER XMLBuffer &toSend)
  {
  }
  
  //
  // XMLDocumentHandler
  //
  virtual void startDocument() {}

  virtual void endDocument() {}

  virtual void resetDocument() {}

  virtual void startElement(
        const XERCES_CPP_NAMESPACE_QUALIFIER XMLElementDecl& elemDecl,
        const unsigned int urlId,
        const XMLCh* const elemPrefix,
        const XERCES_CPP_NAMESPACE_QUALIFIER RefVectorOf<XERCES_CPP_NAMESPACE_QUALIFIER XMLAttr>& attrList,
        const XERCESC_XMLSize_t attrCount,
        const bool isEmpty,
        const bool isRoot) 
  {
  }

  virtual void endElement(
        const XERCES_CPP_NAMESPACE_QUALIFIER XMLElementDecl& elemDecl,
        const unsigned int urlId,
        const bool isRoot,
        const XMLCh* const elemPrefix = 0)
  {
  }

  virtual void docCharacters(
        const XMLCh* const chars,
        const XERCESC_XMLSize_t length,
        const bool cdataSection);

  virtual void ignorableWhitespace(
        const XMLCh* const chars,
        const XERCESC_XMLSize_t length,
        const bool cdataSection)
  {
  }

  virtual void docComment(const XMLCh* const comment)
  {
  }

  virtual void docPI(const XMLCh* const target, const XMLCh* const data) 
  {
  }

  virtual void startEntityReference(
        const XERCES_CPP_NAMESPACE_QUALIFIER XMLEntityDecl& entDecl)
  {
  }

  virtual void endEntityReference(
        const XERCES_CPP_NAMESPACE_QUALIFIER XMLEntityDecl& entDecl)
  {
  }

  virtual void XMLDecl(
        const XMLCh* const versionStr,
        const XMLCh* const encodingStr,
        const XMLCh* const standaloneStr,
        const XMLCh* const actualEncodingStr)
  {
  }

  //  
  // XMLErrorReporter
  //
  virtual void resetErrors() {}

  virtual void error(
        const unsigned int,
        const XMLCh* const, 
        const XMLErrorReporter::ErrTypes errType,
        const XMLCh* const errorText,
        const XMLCh* const systemId,
        const XMLCh* const publicId, 
#if _XERCES_VERSION >= 30000
        const  XMLFileLoc lineNum,
        const  XMLFileLoc colNum
#else
        const XMLSSize_t lineNum,
        const XMLSSize_t colNum
#endif // _XERCES_VERSION >= 30000
                     );
  
private:
  void processStartElement();

  void processAttrs(XERCES_CPP_NAMESPACE_QUALIFIER XMLElementDecl *elemDecl);
  
  bool switchGrammar(const XMLCh *uri);

  bool laxElementValidation(
        XERCES_CPP_NAMESPACE_QUALIFIER QName* element,
        XERCES_CPP_NAMESPACE_QUALIFIER ContentLeafNameTypeVector* cv,
        const XERCES_CPP_NAMESPACE_QUALIFIER XMLContentModel *cm,
        unsigned int parentElemDepth);

  bool anyAttributeValidation(
        XERCES_CPP_NAMESPACE_QUALIFIER SchemaAttDef* attWildCard,
        unsigned int uriId,
        bool& skipThisOne,
        bool& laxThisOne);

  XERCES_CPP_NAMESPACE_QUALIFIER XMLElementDecl* createElementDecl(
        unsigned int uriId,
        unsigned int currentScope,
        bool laxThisOne,
        bool isProcessorStipulatedTypeName);
};

}  // namespace zorba


#endif // ZORBA_NO_XMLSCHEMA
#undef XERCESC_XMLSize_t
#endif

/*
 * Local variables:
 * mode: c++
 * End:
 */
/* vim:set et sw=2 ts=2: */
