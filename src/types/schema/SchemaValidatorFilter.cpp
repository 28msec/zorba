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
#include <zorba/config.h>
#include <xercesc/util/XMLString.hpp>
#ifndef ZORBA_NO_XMLSCHEMA 

#include "types/schema/SchemaValidatorFilter.h"
#include "types/schema/StrX.h"

#include "types/schema/ValidationEventHandler.h"
#include <xercesc/validators/schema/identity/IdentityConstraintHandler.hpp>
#include <xercesc/internal/XMLReader.hpp>
#include <xercesc/framework/MemBufInputSource.hpp>
#include <xercesc/util/XMLUniDefs.hpp>
#include <xercesc/validators/common/ContentLeafNameTypeVector.hpp>
#include <xercesc/validators/schema/SubstitutionGroupComparator.hpp>
//daniel: this is to make cygwin work; xerces defines WIN32 in case of cygwin, which is wrong
#ifdef CYGWIN
#undef WIN32
#endif

#include <iostream>

#include "runtime/accessors/AccessorsImpl.h"
#include "zorbaerrors/error_messages.h"
#include "zorbaerrors/errors.h"
#include "zorbatypes/xerces_xmlcharray.h"
#include "types/schema/XercSchemaValidator.h"

//using namespace std;
XERCES_CPP_NAMESPACE_USE;

namespace zorba {

const XMLCh* emptyToNull(const XMLCh * chars)
{
  //return chars; 
  return XMLString::stringLen(chars) == 0 ? NULL : chars;
}


static inline const XMLCh *nullToZero(const XMLCh *in)
{
  return in ? in : XMLUni::fgZeroLenString;
}


const XMLCh SchemaValidatorFilter::DT_UNTYPED[] =
{
  chLatin_u, chLatin_n, chLatin_t, chLatin_y, chLatin_p, chLatin_e, chLatin_d, chNull
};

const XMLCh SchemaValidatorFilter::DT_UNTYPED_ATOMIC[] =
{
  chLatin_u, chLatin_n, chLatin_t, chLatin_y, chLatin_p, chLatin_e, chLatin_d,
  chLatin_A, chLatin_t, chLatin_o, chLatin_m, chLatin_i, chLatin_c, chNull
};


SchemaValidatorFilter::SchemaValidatorFilter(
    bool strictValidation,
    ValidationEventHandler* eventBuffer,
    GrammarResolver* grammarResolver,
    MemoryManager* mm,
    const QueryLoc& loc)
  :
  XMLScanner(0, grammarResolver, mm),
  _loc(loc),
  _strictValidation(strictValidation),
  _processorStipulatedTypeName(0),
  _parentStack(0),
  _elemDepth(0),
  _elementToProcess(false),
  _fContent(1023, mm),
  _xsiType(0),
  _attrCount(0),
  _eventBuffer(eventBuffer),
  _errorOccurred(false)
{
  _fSchemaGrammar = new (fGrammarPoolMemoryManager)
                    SchemaGrammar(fGrammarPoolMemoryManager);

  _fICHandler = new (fMemoryManager)
                IdentityConstraintHandler(this, fMemoryManager);

  _fSchemaValidator = new (mm) XercSchemaValidator(0, mm);

  _fElemNonDeclPool = new (mm) RefHash3KeysIdPool<SchemaElementDecl>(29, true, 128, mm);

  setURIStringPool(grammarResolver->getStringPool());

  // Create a fake XMLReader via the ReaderMgr if this XMLScanner. The only 
  // reason we do this is because we need the XMLReader::isAllSpaces() method.
  MemBufInputSource inputSrc(0, 0, XMLUni::fgZeroLenString, false, fMemoryManager);

  XMLReader* newReader = fReaderMgr.createReader(inputSrc,
                                                 true,
                                                 XMLReader::RefFrom_NonLiteral,
                                                 XMLReader::Type_General,
                                                 XMLReader::Source_External,
                                                 /*fCalculateSrcOfs*/false);
  fReaderMgr.pushReader(newReader, 0);
  fReaderMgr.setXMLVersion(XMLReader::XMLV1_1);
  
  // Initialize the XMLValidator: The input and the error handler of the validator
  // are set to "this". Furthermore, the XMLValidator is set to use the ReaderMgr
  // and the XMLBufferMgr of "this".
  initValidator(_fSchemaValidator);

  // Set the XMLDocHandler and the XMLErrorreporter to be used by this XMLScanner.
  setDocHandler(this);
  setErrorReporter(this);

  // Make this SchemaValidatorFilter and its associated XMLValidator ready for use.
  reset();
}


SchemaValidatorFilter::~SchemaValidatorFilter()
{
  delete _fSchemaValidator;
  delete _fSchemaGrammar;
  delete _fICHandler;
  delete _fElemNonDeclPool;
}


void SchemaValidatorFilter::reset()
{
  fGrammar = _fSchemaGrammar;
  fValidator = _fSchemaValidator;
  fValidator->setGrammar(fGrammar);
    
  fValidate = true;

  _fSchemaValidator->reset();
  _fSchemaValidator->setErrorReporter(fErrorReporter);
  _fSchemaValidator->setExitOnFirstFatal(true);
  _fSchemaValidator->setGrammarResolver(fGrammarResolver);
  _fICHandler->reset();
  _fElemNonDeclPool->removeAll();
  
  _errorOccurred = false;
    
  _processorStipulatedTypeName = NULL;
  _processorStipulatedTypeUriId = -1;  
}


void SchemaValidatorFilter::startDocumentEvent(
    const XMLCh *documentURI,
    const XMLCh *encoding)
{
  reset();
  _eventBuffer->startDocumentEvent(documentURI, encoding);
}


void SchemaValidatorFilter::endDocumentEvent()
{
  if(fValidate) 
    _fICHandler->endDocument();

  _eventBuffer->endDocumentEvent();
}


void SchemaValidatorFilter::startElementEvent(
    const XMLCh *prefix,
    const XMLCh *uri,
    const XMLCh *localname)
{
  //std::cout << "   svf startElememntEvent: " << StrX(localname) << "  @ " << StrX(uri) << "\n";
  if(_elementToProcess)
    processStartElement();

  _prefix.set(prefix);
  _uri.set(uri);
  _localname.set(localname);
  _elementToProcess = true;
  _attrCount = 0;
  _xsiType = 0;
  
  if(fElemStack.isEmpty()) 
    _parentStack = 0;
  else 
    _parentStack = const_cast<ElemStack::StackElem*>(fElemStack.topElement());
  
  _elemDepth = fElemStack.addLevel();
  fElemStack.setValidationFlag(fValidate);
  
  _errorOccurred = false;
  
  fElemStack.addPrefix(prefix, fURIStringPool->addOrFind(uri));
  
  _eventBuffer->startElementEvent(prefix, uri, localname);
}
  

void SchemaValidatorFilter::processStartElement()
{
  bool isRoot = _parentStack == 0;
  unsigned int uriId = fURIStringPool->addOrFind(_uri.getRawBuffer());

  // Handle xsi:type
  if( _xsiType )
  {
    int colonPos = -1;
    unsigned int atUriId = resolveQName(_xsiType,
                                        fPrefixBuf,
                                        ElemStack::Mode_Element,
                                        colonPos);

    ((XercSchemaValidator*)fValidator)->setXsiType(fPrefixBuf.getRawBuffer(),
                                                   _xsiType + colonPos + 1,
                                                   atUriId);
  }

  bool isProcessorStipulatedTypeName = false;

  if( _processorStipulatedTypeName && isRoot )
  {
    isProcessorStipulatedTypeName = true;                
    ((XercSchemaValidator*)fValidator)->setXsiType(NULL,
                                                   _processorStipulatedTypeName,
                                                   _processorStipulatedTypeUriId);
  } 
  
  //if schema, check if we should lax or skip the validation of this element
  bool parentValidation = fValidate;
  unsigned int currentScope = Grammar::TOP_LEVEL_SCOPE;
  bool laxThisOne = false;

  if(!isRoot) 
  {
    // schema validator will have correct type if validating
    SchemaElementDecl* tempElement = (SchemaElementDecl*)_parentStack->fThisElement;
    
    
    SchemaElementDecl::ModelTypes modelType = tempElement->getModelType();
    ComplexTypeInfo *currType = 0;

    if(fValidate) 
    {
      currType = ((XercSchemaValidator*)fValidator)->getCurrentTypeInfo();
      if (currType)
        modelType = (SchemaElementDecl::ModelTypes)currType->getContentType();
      else // something must have gone wrong
      {
        if ( modelType && modelType==SchemaElementDecl::Simple )
        {
          // error an element inside a Simple modelType
          fValidator->emitError(XMLValid::ElementNotDefined,
                                _localname.getRawBuffer());
        }
        modelType = SchemaElementDecl::Any;
      }
    }
    else 
    {
      currType = tempElement->getComplexTypeInfo();
    }
    
    if(modelType == SchemaElementDecl::Mixed_Simple ||
       modelType == SchemaElementDecl::Mixed_Complex ||
       modelType == SchemaElementDecl::Children) 
    {
      XMLContentModel* cm = currType->getContentModel();
      currentScope = _parentStack->fCurrentScope;
      
      QName element(_prefix.getRawBuffer(),
                    _localname.getRawBuffer(),
                    uriId,
                    fMemoryManager);
      // elementDepth will be > 0
      laxThisOne = laxElementValidation(&element,
                                        cm->getContentLeafNameTypeVector(),
                                        cm,
                                        _elemDepth - 1);
    }
    else if(modelType == SchemaElementDecl::Any) 
    {
      laxThisOne = true;
    }
  }
  
  XMLElementDecl* elemDecl = createElementDecl(uriId,
                                               currentScope,
                                               laxThisOne,
                                               isProcessorStipulatedTypeName);
  assert(elemDecl);
  fElemStack.setElement(elemDecl, fReaderMgr.getCurrentReaderNum());
  
  // save substituted element name
  _substitutedElemName = NULL;
  _substitutedElemUri  = NULL;
  SchemaElementDecl* schemaElemDecl = dynamic_cast<SchemaElementDecl*>(elemDecl);
  if (schemaElemDecl)
  {
      SchemaElementDecl* substitutedElem = schemaElemDecl->getSubstitutionGroupElem();
      if (substitutedElem)
      {
          //std::cout << "     svf substitutedElem: " << StrX(substitutedElem->getFullName()) << "\n";
          _substitutedElemName = substitutedElem->getBaseName();
          _substitutedElemUri  = (XMLCh*)fURIStringPool->getValueForId(substitutedElem->getURI());
      }
  }


  if(fValidate)
  {
    if (isProcessorStipulatedTypeName)
    {
      ((XercSchemaValidator*)fValidator)->
      validateProcessorStipulatedTypeName(elemDecl);
    }
    else
    {
      fValidator->validateElement(elemDecl);
    }
  }
  
  ComplexTypeInfo* typeinfo = 
    (fValidate ?
     ((XercSchemaValidator*)fValidator)->getCurrentTypeInfo() :
     ((SchemaElementDecl*)elemDecl)->getComplexTypeInfo());

  if(typeinfo) 
  {
    currentScope = typeinfo->getScopeDefined();
    
    // switch grammar if the typeinfo has a different grammar (happens
    // when there is xsi:type)
    if(!typeinfo->getAnonymous()) 
    {
      int comma = XMLString::indexOf(typeinfo->getTypeName(), chComma);
      if(comma > 0) 
      {
        XMLBuffer prefixBuf(comma + 1, fMemoryManager);
        prefixBuf.append(typeinfo->getTypeName(), comma);
        const XMLCh *uriStr = prefixBuf.getRawBuffer();
        
        if(!switchGrammar(uriStr) && fValidate && !laxThisOne) 
        {
          fValidator->emitError(XMLValid::GrammarNotFound,
                                prefixBuf.getRawBuffer());
        }
      }
      else if(comma == 0) 
      {
        if(!switchGrammar(XMLUni::fgZeroLenString) && fValidate && !laxThisOne) 
        {
          fValidator->emitError(XMLValid::GrammarNotFound,
                                XMLUni::fgZeroLenString);
        }
      }
    }
  }
  
  fElemStack.setCurrentScope(currentScope);
    
  // We commandeer fCurrentURI to keep the element state in
  fElemStack.setCurrentURI(0);

  fElemStack.setCurrentGrammar(fGrammar);
  
  if(!isRoot && parentValidation) 
  {
    fElemStack.addChild(elemDecl->getElementName(), true);
  }
  
  processAttrs(elemDecl);

  if(fValidate)
    _fICHandler->activateIdentityConstraint((SchemaElementDecl*)elemDecl,
                                            (int)_elemDepth,
                                            uriId,
                                            _prefix.getRawBuffer(),
                                            *fAttrList,
                                            _attrCount);

  _elementToProcess = false;
    
  _eventBuffer->typeElementEvent(getTypeUri(), getTypeName());

  // We commandeer fCommentOrPISeen to keep _errorOccurred in
  if(_errorOccurred)
    fElemStack.setCommentOrPISeen();
}


void SchemaValidatorFilter::processAttrs(XMLElementDecl *elemDecl)
{
  DatatypeValidator *currDV = 0;
  ComplexTypeInfo *currType = 0;

  if(fValidate) 
  {
    currType = ((XercSchemaValidator*)fValidator)->getCurrentTypeInfo();
    if(!currType)
      currDV = ((XercSchemaValidator*)fValidator)->getCurrentDatatypeValidator();
  }

  //   XMLBufBid bbNormal(&fBufMgr);
  //   XMLBuffer& normBuf = bbNormal.getBuffer();
  
  //  Loop through our explicitly provided attributes, which are in the raw
    //  scanned form, and build up XMLAttr objects.
  unsigned int index;
  for(index = 0; index < _attrCount; ++index)
  {
    const XMLAttr *attr = fAttrList->elementAt(index);
    const XMLCh *localname = attr->getName();
    const XMLCh *value = attr->getValue();
    
    unsigned int uriId = attr->getURIId();
    const XMLCh *uri = getURIText(uriId);
        
    bool attrValid = true;
    DatatypeValidator *attrValidator = 0;
    
    // Some checking for attribute wild card first (for schema)
    bool laxThisOne = false;
    bool skipThisOne = false;
    
    XMLAttDef *attDef = 0;

    //retrieve the att def
    SchemaAttDef* attWildCard = 0;
    if(currType) 
    {
      attDef = currType->getAttDef(localname, uriId);
      attWildCard = currType->getAttWildCard();
    }
    else if(!currDV) 
    { // check explicitly-set wildcard
      attWildCard = ((SchemaElementDecl*)elemDecl)->getAttWildCard();
    }
    
    // if not found or faulted in - check for a matching wildcard attribute
    // if no matching wildcard attribute, check (un)qualifed cases and flag
    // appropriate errors
    if (!attDef || (attDef->getCreateReason() == XMLAttDef::JustFaultIn)) 
    {
      if (attWildCard) 
      {
        //if schema, see if we should lax or skip the validation of this attribute
        if (anyAttributeValidation(attWildCard, uriId, skipThisOne, laxThisOne)) 
        {
          if(!skipThisOne)
          {
            SchemaGrammar* sGrammar = (SchemaGrammar*)
              fGrammarResolver->getGrammar(getURIText(uriId));

            if (sGrammar &&
                sGrammar->getGrammarType() == Grammar::SchemaGrammarType) 
            {
              RefHashTableOf<XMLAttDef>* attRegistry = sGrammar->getAttributeDeclRegistry();
              if (attRegistry) 
              {
                attDef = attRegistry->get(localname);
              }
            }
          }
        }
      }
      else if (currType) 
      {
        // not found, see if the attDef should be qualified or not
        if (uriId == fEmptyNamespaceId) 
        {
          attDef = currType->getAttDef(localname,
                                       fURIStringPool->getId(fGrammar->getTargetNamespace()));
          if (fValidate &&
              attDef &&
              attDef->getCreateReason() != XMLAttDef::JustFaultIn) 
          {
            // the attribute should be qualified
            fValidator->emitError(XMLValid::AttributeNotQualified,
                                  attDef->getFullName());
            attrValid = false;
          }
        }
        else 
        {
          attDef = currType->getAttDef(localname, fEmptyNamespaceId);
          if (fValidate &&
              attDef &&
              attDef->getCreateReason() != XMLAttDef::JustFaultIn) 
          {
            // the attribute should be qualified
            fValidator->emitError(XMLValid::AttributeNotUnQualified,
                                  attDef->getFullName());
            attrValid = false;
          }
        }
      }
    }
    
    if(!attDef)
      attrValid = false;
    
    if(fValidate && !attDef && !skipThisOne && !laxThisOne) 
    {
      //
      //  Its not valid for this element, so issue an error if we are
      //  validating.
      //
      XMLBufBid bbMsg(&fBufMgr);
      XMLBuffer& bufMsg = bbMsg.getBuffer();
      if(uriId != fEmptyNamespaceId) 
      {
        XMLBufBid bbURI(&fBufMgr);
        XMLBuffer& bufURI = bbURI.getBuffer();
        
        getURIText(uriId, bufURI);
        
        bufMsg.append(chOpenCurly);
        bufMsg.append(bufURI.getRawBuffer());
        bufMsg.append(chCloseCurly);
      }
      bufMsg.append(localname);
      fValidator->emitError(XMLValid::AttNotDefinedForElement,
                            bufMsg.getRawBuffer(), elemDecl->getFullName());
    }
    
    // TBD? - jpcs
    //     normalizeAttValue(attDef, namePtr, value, normBuf);
    
    if(attDef) 
    {
      DatatypeValidator* tempDV = ((SchemaAttDef*) attDef)->getDatatypeValidator();
      if(tempDV && tempDV->getWSFacet() != DatatypeValidator::PRESERVE) 
      {
        // normalize the attribute according to schema whitespace facet
        ((XercSchemaValidator*) fValidator)->normalizeWhiteSpace(tempDV,
                                                                 value,
                                                                 fWSNormalizeBuf);
        value = fWSNormalizeBuf.getRawBuffer();
      }
      
      if(fValidate && !skipThisOne) 
      {
        fValidator->validateAttrValue(attDef, value, false, elemDecl);
        attrValidator = ((XercSchemaValidator *)fValidator)->getMostRecentAttrValidator();
        if(((XercSchemaValidator *)fValidator)->getErrorOccurred())
          attrValid = false;
      }
    }
    
    if(fValidate && attrValid) 
    {
      if(attrValidator)
        _eventBuffer->attributeEvent(emptyToNull(attr->getPrefix()),
                              emptyToNull(uri),
                              localname,
                              value,
                              emptyToNull(attrValidator->getTypeUri()),
                              attrValidator->getTypeLocalName());
      else 
        _eventBuffer->attributeEvent(emptyToNull(attr->getPrefix()),
                                     emptyToNull(uri),
                                     localname,
                                     value,
                                     SchemaSymbols::fgURI_SCHEMAFORSCHEMA,
                                     SchemaSymbols::fgDT_ANYSIMPLETYPE);
    }
    else
    {
      _eventBuffer->attributeEvent(emptyToNull(attr->getPrefix()),
                            emptyToNull(uri),
                            localname,
                            value,
                            SchemaSymbols::fgURI_SCHEMAFORSCHEMA,
                            DT_UNTYPED_ATOMIC);
    }
  }
  
  // Deal with default, required and prohibited attrs
  if((currType && fValidate) ? currType->hasAttDefs() : elemDecl->hasAttDefs()) 
  {
    
    XMLAttDefList &attDefList = (currType ?
                                 currType->getAttDefList() :
                                 elemDecl->getAttDefList());

    for(unsigned int i = 0; i < attDefList.getAttDefCount(); ++i) 
    {
      SchemaAttDef *curDef = (SchemaAttDef*)&attDefList.getAttDef(i);
      XMLAttDef::DefAttTypes defType = curDef->getDefaultType();
      QName* attName = curDef->getAttName();
      
      unsigned int curUriId = attName->getURI();
      const XMLCh *curName = attName->getLocalPart();
      
      // See if the attribute is already defined
      for(index = 0; index < _attrCount; ++index) 
      {
        const XMLAttr *attr = fAttrList->elementAt(index);
        if(attr->getURIId() == curUriId &&
           XMLString::equals(attr->getName(), curName))
          break;
      }
      
      if(index >= _attrCount)   // if curDef is not in the list of instance attrs fAttrList
      {
        switch(defType) 
        {
        case XMLAttDef::Required:
        case XMLAttDef::Required_And_Fixed:
          if(fValidate)
            fValidator->emitError(XMLValid::RequiredAttrNotProvided,
                                  curDef->getFullName());
          break;
          
        case XMLAttDef::Default:
        case XMLAttDef::Fixed: 
        {
          DatatypeValidator *attrValidator = 0;
          if(fValidate)
          {
            fValidator->validateAttrValue(curDef,
                                          curDef->getValue(),
                                          false,
                                          elemDecl);
            attrValidator = ((XercSchemaValidator *)fValidator)->getMostRecentAttrValidator();
          }
          
          if(attrValidator)
            _eventBuffer->attributeEvent(emptyToNull(attName->getPrefix()),
                                  emptyToNull(getURIText(curUriId)),
                                  curName,
                                  curDef->getValue(),
                                  emptyToNull(attrValidator->getTypeUri()),
                                  attrValidator->getTypeLocalName());
          else
            _eventBuffer->attributeEvent(emptyToNull(attName->getPrefix()),
                                  emptyToNull(getURIText(curUriId)),
                                  curName,
                                  curDef->getValue(),
                                  SchemaSymbols::fgURI_SCHEMAFORSCHEMA,
                                  DT_UNTYPED);
          break;
        }
        default: break;
        }
      }
      else if(fValidate && defType == XMLAttDef::Prohibited) 
      {
        fValidator->emitError(XMLValid::ProhibitedAttributePresent,
                              curDef->getFullName());
      }
    }
  }
}
  

void SchemaValidatorFilter::endElementEvent(
    const XMLCh *prefix, 
    const XMLCh *uri,
    const XMLCh *localname,
    const XMLCh *typeURI,
    const XMLCh *typeName)
{
  if(_elementToProcess) 
    processStartElement();

  typeURI = SchemaSymbols::fgURI_SCHEMAFORSCHEMA;
  typeName = SchemaSymbols::fgATTVAL_ANYTYPE;

  assert(!fElemStack.isEmpty());
  const ElemStack::StackElem* topElem = fElemStack.topElement();

  // We commandeer fCommentOrPISeen to keep _errorOccurred in
  _errorOccurred = topElem->fCommentOrPISeen;
  
  if(fValidate) 
  {
    DatatypeValidator *currentDV = 0;
    if(topElem->fThisElement->isDeclared()) 
    {
      ComplexTypeInfo *currentTypeInfo = ((XercSchemaValidator*)fValidator)->
                                         getCurrentTypeInfo();

      if(currentTypeInfo) 
      {
        typeURI = currentTypeInfo->getTypeUri();
        typeName = currentTypeInfo->getTypeLocalName();
      }
      else 
      {
        currentDV = ((XercSchemaValidator*)fValidator)->
                    getCurrentDatatypeValidator();
        if (currentDV)
        {
          typeURI = currentDV->getTypeUri();
          typeName = currentDV->getTypeLocalName();
        }
        // else remains xs:anyType
      }
    }
    
#if _XERCES_VERSION >= 30000
    XMLSize_t failingChildNo;
    int res = fValidator->checkContent(topElem->fThisElement,
                                       topElem->fChildren,
                                       topElem->fChildCount,
                                       &failingChildNo);
#else
    int res = fValidator->checkContent(topElem->fThisElement,
                                       topElem->fChildren,
                                       topElem->fChildCount);
#endif // _XERCES_VERSION >= 30000
    
    if(res >= 0) 
    {
      if(!topElem->fChildCount) 
      {
        fValidator->emitError(XMLValid::EmptyNotValidForContent,
                              topElem->fThisElement->getFormattedContentModel());
      }
      else if((unsigned int)res >= topElem->fChildCount) 
      {
        fValidator->emitError(XMLValid::NotEnoughElemsForCM,
                              topElem->fThisElement->getFormattedContentModel());
      }
      else 
      {
        fValidator->emitError(XMLValid::ElementNotValidForContent,
                              topElem->fChildren[res]->getRawName(),
                              topElem->fThisElement->getFormattedContentModel());
      }
    }
    
    if(currentDV && currentDV->getType() == DatatypeValidator::Union) 
    {
      DatatypeValidator *memberType = fValidationContext->getValidatingMemberType();
      typeURI = memberType->getTypeUri();
      typeName = memberType->getTypeLocalName();
    }
    
    if(fValidate)
      _fICHandler->deactivateContext((SchemaElementDecl*)topElem->fThisElement,
                                     _fContent.getRawBuffer());
  }
  
  fElemStack.popTop(); 
  
  const bool isRoot = fElemStack.isEmpty();
  
  ((XercSchemaValidator *)fValidator)->clearDatatypeBuffer();
  
  if(!isRoot) 
  {
    // We commandeer fCommentOrPISeen to keep _errorOccurred in
    if(_errorOccurred)
      fElemStack.setCommentOrPISeen();
    
    fGrammar = fElemStack.getCurrentGrammar();
    fValidator->setGrammar(fGrammar);
    fValidate = fElemStack.getValidationFlag();
  }
  
  if(!fValidate || _errorOccurred) 
  {
    typeURI = SchemaSymbols::fgURI_SCHEMAFORSCHEMA;
    typeName = DT_UNTYPED; // DocumentCache::g_szUntyped;
  }
  
  _eventBuffer->endElementEvent(prefix, uri, localname, emptyToNull(typeURI), typeName);
}


void SchemaValidatorFilter::attributeEvent(
    const XMLCh *prefix,
    const XMLCh *uri,
    const XMLCh *localname,
    const XMLCh *value,
    const XMLCh *typeURI,
    const XMLCh *typeName)
{
  unsigned int uriId = fURIStringPool->addOrFind(uri);
  fElemStack.addPrefix(prefix, uriId);

  XMLAttr *curAttr;
  if(_attrCount >= fAttrList->size()) 
  {
    curAttr = new (fMemoryManager) XMLAttr(uriId, localname, nullToZero(prefix), nullToZero(value), XMLAttDef::CData, true, fMemoryManager);
    fAttrList->addElement(curAttr);
  }
  else 
  {
    curAttr = fAttrList->elementAt(_attrCount);
    curAttr->set(uriId, localname, nullToZero(prefix), nullToZero(value));
  }
  ++_attrCount;

  if(XMLString::equals(uri, SchemaSymbols::fgURI_XSI)) 
  {
    // Ignore schema location hints
    if(XMLString::equals(localname, SchemaSymbols::fgXSI_TYPE)) 
    {
      _xsiType = curAttr->getValue();
    }
    else if(XMLString::equals(localname, SchemaSymbols::fgATT_NILL) &&
            XMLString::equals(value, SchemaSymbols::fgATTVAL_TRUE)) 
    {
      ((XercSchemaValidator*)fValidator)->setNillable(true);
    }
    --_attrCount;  // remove att from the list but still needs to be reported
    
    //std::cout << "   svf attrEvent: " << StrX(localname) << "  T: " << StrX(typeName) << "\n";
    _eventBuffer->attributeEvent(emptyToNull(prefix), emptyToNull(uri), localname, value,
                          emptyToNull(typeURI), typeName);
  }
}


void SchemaValidatorFilter::endAttributesEvent()
{
  if(_elementToProcess) processStartElement();
  //_eventBuffer->endAttributesEvent();
}


void SchemaValidatorFilter::namespaceEvent(const XMLCh *prefix, const XMLCh *uri)
{
  fElemStack.addPrefix(prefix, fURIStringPool->addOrFind(uri));

  _eventBuffer->namespaceEvent(prefix, uri);
}


void SchemaValidatorFilter::textEvent(const XMLCh *chars)
{
  if(_elementToProcess) processStartElement();

  const XMLCh *end = chars;
  while(*end) ++end;
  unsigned int len = (unsigned int)(end - chars);
  
  if(fValidate) 
  {
    // Get the character data opts for the current element
    XMLElementDecl::CharDataOpts charOpts = XMLElementDecl::AllCharData;
    ComplexTypeInfo *currType = ((XercSchemaValidator*)fValidator)->getCurrentTypeInfo();
    if(currType) 
    {
      SchemaElementDecl::ModelTypes modelType = (SchemaElementDecl::ModelTypes)currType->getContentType(); 
      if(modelType == SchemaElementDecl::Children) 
        charOpts = XMLElementDecl::SpacesOk;
      else if(modelType == SchemaElementDecl::Empty) 
        charOpts = XMLElementDecl::NoCharData; 
    } 
    
    if(charOpts == XMLElementDecl::AllCharData) 
    {
      DatatypeValidator *tempDV = ((XercSchemaValidator*) fValidator)->getCurrentDatatypeValidator();
      if(tempDV && tempDV->getWSFacet() != DatatypeValidator::PRESERVE) 
      {
        // normalize the character according to schema whitespace facet
        ((XercSchemaValidator*) fValidator)->normalizeWhiteSpace(tempDV, chars, fWSNormalizeBuf);
        chars = fWSNormalizeBuf.getRawBuffer();
        len = fWSNormalizeBuf.getLen();
      }
      
      // tell the schema validation about the character data for checkContent later
      ((XercSchemaValidator*)fValidator)->setDatatypeBuffer(chars);
    }
    else if(charOpts == XMLElementDecl::NoCharData) 
    {
      fValidator->emitError(XMLValid::NoCharDataInCM);
    }
    else if(!fReaderMgr.getCurrentReader()->isAllSpaces(chars, len)) 
    {
      fValidator->emitError(XMLValid::NoCharDataInCM);
    }
  }
  
  // call all active identity constraints
  if(fValidate && _fICHandler->getMatcherCount())
    _fContent.append(chars, len);
  
  _eventBuffer->textEvent(chars, len);
}


void SchemaValidatorFilter::textEvent(const XMLCh *chars, unsigned int len)
{
  // Copy the chars to null terminate them
  XMLBuffer nullterm;
  nullterm.set(chars, len);
  textEvent(nullterm.getRawBuffer());
}


void SchemaValidatorFilter::commentEvent(const XMLCh *value)
{
  if(_elementToProcess) processStartElement();

  _eventBuffer->commentEvent(value);
}


void SchemaValidatorFilter::piEvent(const XMLCh *target, const XMLCh *value)
{
  if(_elementToProcess) processStartElement();

  _eventBuffer->piEvent(target, value);
}


void SchemaValidatorFilter::startTypeEvent(
    const XMLCh *typeUri,
    const XMLCh *typeName)
{
  reset();
        
  _processorStipulatedTypeUriId = fURIStringPool->addOrFind(typeUri);
  _processorStipulatedTypeName = XMLString::replicate(typeName);
  //std::cout << "  startTypeEvent:  " <<  StrX(typeName) << " @ " << StrX(typeUri) << "\n";
}


void SchemaValidatorFilter::endTypeEvent()
{
  if (_processorStipulatedTypeName)
  {
    XMLString::release(&_processorStipulatedTypeName);
    _processorStipulatedTypeName = NULL;
    _processorStipulatedTypeUriId = -1;
  }
  
  if(!fElemStack.isEmpty()) 
    ZORBA_ASSERT(false);
}


const XMLCh* SchemaValidatorFilter::getTypeUri()
{
  if(_elementToProcess) 
    processStartElement();

  const XMLCh *typeURI = NULL;
    
  if(fValidate) 
  {
    if (_processorStipulatedTypeName && _parentStack == 0)
    {
      typeURI = fURIStringPool->getValueForId(_processorStipulatedTypeUriId);
    }
    else
    {
      const ElemStack::StackElem* topElem = fElemStack.topElement();
      DatatypeValidator *currentDV = 0;
      if(topElem->fThisElement->isDeclared())
      {
        ComplexTypeInfo *currentTypeInfo = ((XercSchemaValidator*)fValidator)->getCurrentTypeInfo();
        if(currentTypeInfo)
        {
          typeURI = currentTypeInfo->getTypeUri();
        }
        else
        {
          currentDV = ((XercSchemaValidator*)fValidator)->getCurrentDatatypeValidator();
          if ( currentDV )
            typeURI = currentDV->getTypeUri();
          else
            typeURI = SchemaSymbols::fgURI_SCHEMAFORSCHEMA;
        }
      }
    }
  }
  
  return typeURI;
}


const XMLCh* SchemaValidatorFilter::getTypeName()
{
  if(_elementToProcess) 
    processStartElement();
  
  const XMLCh *typeName = NULL;
  
  if(fValidate) 
  {
    //std::cout << "  - getTypeQName: _elemDepth: " << _elemDepth << "\n";
    if (_processorStipulatedTypeName && _elemDepth == 0 )
    {
      typeName = _processorStipulatedTypeName;
    }
    else
    {
      const ElemStack::StackElem* topElem = fElemStack.topElement();
      DatatypeValidator *currentDV = 0;
      if(topElem->fThisElement->isDeclared())
      {
        ComplexTypeInfo *currentTypeInfo = ((XercSchemaValidator*)fValidator)->getCurrentTypeInfo();
        if(currentTypeInfo)
        {
          typeName = currentTypeInfo->getTypeLocalName();
        }
        else
        {
          currentDV = ((XercSchemaValidator*)fValidator)->getCurrentDatatypeValidator();
          if ( currentDV ) 
            typeName = currentDV->getTypeLocalName();
          else
            typeName = SchemaSymbols::fgATTVAL_ANYTYPE;
        }
      }
    }
  }
  
  return typeName;    
}


////////////////////////////////////////////////////////////////////////////////////////////////////

unsigned int SchemaValidatorFilter::resolveQName(
    const XMLCh *const qName,
    XMLBuffer &prefixBuf,
    const short mode,
    int &prefixColonPos)
{
  prefixColonPos = XMLString::indexOf(qName, chColon);

  if(prefixColonPos == -1) 
  {
    bool unknown = false;
    return fElemStack.mapPrefixToURI(XMLUni::fgZeroLenString, (ElemStack::MapModes) mode, unknown);
  }
  else 
  {
    prefixBuf.set(qName, prefixColonPos);
      
    if( XMLString::equals(prefixBuf.getRawBuffer(), XMLUni::fgXMLNSString)) 
    {
      if(mode == ElemStack::Mode_Element)
        emitError(XMLErrs::NoXMLNSAsElementPrefix, qName);
      
      return fXMLNSNamespaceId;
    }
    else if( XMLString::equals(prefixBuf.getRawBuffer(), XMLUni::fgXMLString)) 
    {
      return  fXMLNamespaceId;
    }
    else 
    {
      bool unknown = false;
      unsigned int uriId = fElemStack.mapPrefixToURI(prefixBuf.getRawBuffer(), (ElemStack::MapModes) mode, unknown);

      if(unknown)
        emitError(XMLErrs::UnknownPrefix, prefixBuf.getRawBuffer());
      
      return uriId;
    }
  }
}


bool SchemaValidatorFilter::switchGrammar(const XMLCh* uri)
{
  Grammar* tempGrammar = fGrammarResolver->getGrammar(uri);

  if(!tempGrammar) tempGrammar = _fSchemaGrammar;

  if(!tempGrammar || tempGrammar->getGrammarType() == Grammar::DTDGrammarType) return false;

  fGrammar = tempGrammar;
  fValidator->setGrammar(fGrammar);
  return true;
}


bool SchemaValidatorFilter::laxElementValidation(
    QName* element,
    ContentLeafNameTypeVector* cv,
    const XMLContentModel* cm,
    unsigned int parentElemDepth)
{
  bool skipThisOne = false;
  bool laxThisOne = false;
  unsigned int elementURI = element->getURI();
  
  // We commandeer fCurrentURI to keep the element state in
  unsigned int currState = _parentStack->fCurrentURI;

  if (currState == XMLContentModel::gInvalidTrans) 
  {
    return laxThisOne;
  }
  
  SubstitutionGroupComparator comparator(fGrammarResolver, fURIStringPool);
  
  if (cv)
  {
    unsigned int i = 0;
    unsigned int leafCount = cv->getLeafCount();
    
    for (; i < leafCount; ++i)
    {
      QName* fElemMap = cv->getLeafNameAt(i);
      unsigned int uri = fElemMap->getURI();
      unsigned int nextState;
      bool anyEncountered = false;
      ContentSpecNode::NodeTypes type = cv->getLeafTypeAt(i);
      
      if (type == ContentSpecNode::Leaf)
      {
        if (((uri == elementURI)
             && XMLString::equals(fElemMap->getLocalPart(), element->getLocalPart()))
            || comparator.isEquivalentTo(element, fElemMap))
        {
          nextState = cm->getNextState(currState, i);
          
          if (nextState != XMLContentModel::gInvalidTrans)
          {
            // We commandeer fCurrentURI to keep the element state in
            _parentStack->fCurrentURI = nextState;
            break;
          }
        }
      }
      else if ((type & 0x0f) == ContentSpecNode::Any)
      {
        anyEncountered = true;
      }
      else if ((type & 0x0f) == ContentSpecNode::Any_Other)
      {
        if (uri != elementURI)
        {
          anyEncountered = true;
        }
      }
      else if ((type & 0x0f) == ContentSpecNode::Any_NS)
      {
        if (uri == elementURI)
        {
          anyEncountered = true;
        }
      }
      
      if (anyEncountered)
      {
        
        nextState = cm->getNextState(currState, i);
        if (nextState != XMLContentModel::gInvalidTrans)
        {
          // We commandeer fCurrentURI to keep the element state in
          _parentStack->fCurrentURI = nextState;
          
          if (type == ContentSpecNode::Any_Skip ||
              type == ContentSpecNode::Any_NS_Skip ||
              type == ContentSpecNode::Any_Other_Skip)
          {
            skipThisOne = true;
          }
          else if (type == ContentSpecNode::Any_Lax ||
                   type == ContentSpecNode::Any_NS_Lax ||
                   type == ContentSpecNode::Any_Other_Lax)
          {
            laxThisOne = true;
          }
          
          break;
        }
      }
    }

    if (i == leafCount)
    { // no match
      // We commandeer fCurrentURI to keep the element state in
      _parentStack->fCurrentURI = XMLContentModel::gInvalidTrans;
      return laxThisOne;
    }
    
  }
  
  if (skipThisOne) 
  {
    fValidate = false;
    fElemStack.setValidationFlag(fValidate);
  }
  
  return laxThisOne;
}


bool SchemaValidatorFilter::anyAttributeValidation(
    SchemaAttDef* attWildCard,
    unsigned int uriId, 
    bool& skipThisOne,
    bool& laxThisOne)
{
  XMLAttDef::AttTypes wildCardType = attWildCard->getType();
  bool anyEncountered = false;
  skipThisOne = false;
  laxThisOne = false;
  if (wildCardType == XMLAttDef::Any_Any)
    anyEncountered = true;
  else if (wildCardType == XMLAttDef::Any_Other) 
  {
    if (attWildCard->getAttName()->getURI() != uriId
        && uriId != fEmptyNamespaceId)
      anyEncountered = true;
  }
  else if (wildCardType == XMLAttDef::Any_List) 
  {
    ValueVectorOf<unsigned int>* nameURIList = attWildCard->getNamespaceList();
    unsigned int listSize = (nameURIList) ? nameURIList->size() : 0;
    
    if (listSize) 
    {
      for (unsigned int i=0; i < listSize; i++) 
      {
        if (nameURIList->elementAt(i) == uriId)
          anyEncountered = true;
      }
    }
  }

  if (anyEncountered) 
  {
    XMLAttDef::DefAttTypes   defType   = attWildCard->getDefaultType();
    if (defType == XMLAttDef::ProcessContents_Skip) 
    {
      // attribute should just be bypassed,
      skipThisOne = true;
    }
    else if (defType == XMLAttDef::ProcessContents_Lax) 
    {
      laxThisOne = true;
    }
  }
  
  return anyEncountered;
}


XMLElementDecl *SchemaValidatorFilter::createElementDecl(
    unsigned int uriId,
    unsigned int currentScope,
    bool laxThisOne,
    bool isProcessorStipulatedTypeName)
{
  //  Look up the element now in the grammar. This will get us back a
  //  generic element decl object. We tell him to fault one in if he does
  //  not find it.
  XMLElementDecl* elemDecl = 0;
  const XMLCh* original_uriStr = fGrammar->getTargetNamespace();
  
  elemDecl = fGrammar->getElemDecl(uriId, _localname.getRawBuffer(), 0, currentScope);
  if(!elemDecl)
    elemDecl = _fElemNonDeclPool->getByKey(_localname.getRawBuffer(), uriId, currentScope);
  
  unsigned int orgGrammarUri = uriId;
  if(!elemDecl && ( 
                   original_uriStr==NULL ||       // to fix noTargetNamespace schema validation
                   (orgGrammarUri = fURIStringPool->getId(original_uriStr)) != uriId ) 
     ) 
  {
    //not found, switch grammar and try globalNS
    if(!switchGrammar(_uri.getRawBuffer()) && fValidate && !laxThisOne) 
    {
      fValidator->emitError(XMLValid::GrammarNotFound, _uri.getRawBuffer());
    }
    elemDecl = fGrammar->getElemDecl(uriId, _localname.getRawBuffer(), 0, currentScope);
  }
  
  if(!elemDecl && currentScope != Grammar::TOP_LEVEL_SCOPE) 
  {
    // if not found, then it may be a reference, try TOP_LEVEL_SCOPE
    elemDecl = fGrammar->getElemDecl(uriId, _localname.getRawBuffer(), 0, Grammar::TOP_LEVEL_SCOPE);
    if(!elemDecl)
      elemDecl = _fElemNonDeclPool->getByKey(_localname.getRawBuffer(), uriId, Grammar::TOP_LEVEL_SCOPE);
    
    if(!elemDecl) 
    {
      // still not found in specified uri
      if(uriId != fEmptyNamespaceId) 
      {
        // try emptyNamesapce see if element should be un-qualified.
        elemDecl = fGrammar->getElemDecl(fEmptyNamespaceId, _localname.getRawBuffer(), 0, currentScope); 
        if(elemDecl && elemDecl->getCreateReason() != XMLElementDecl::JustFaultIn && fValidate) 
        {
          fValidator->emitError(XMLValid::ElementNotUnQualified, elemDecl->getFullName());
        }
      }
      else if(orgGrammarUri != uriId) 
      {
        // go to original Grammar again to see if element needs to be fully qualified.
        if(!switchGrammar(original_uriStr) && fValidate && !laxThisOne) 
        {
          fValidator->emitError(XMLValid::GrammarNotFound, original_uriStr);
        }
        
        elemDecl = fGrammar->getElemDecl(orgGrammarUri, _localname.getRawBuffer(), 0, currentScope);
        if(elemDecl && elemDecl->getCreateReason() != XMLElementDecl::JustFaultIn && fValidate) 
        {
          fValidator->emitError(XMLValid::ElementNotQualified, elemDecl->getFullName());
        }
      }
    }
  }
  
  if(!elemDecl) 
  {
    // still not found, fault this in and issue error later
    // switch back to original grammar first (if necessary)
    if(orgGrammarUri != uriId) 
    {
      switchGrammar(original_uriStr);
    }
    elemDecl = new (fMemoryManager)
               SchemaElementDecl(_prefix.getRawBuffer(), 
                                 _localname.getRawBuffer(),
                                 uriId,
                                 SchemaElementDecl::Any,
                                 Grammar::TOP_LEVEL_SCOPE,
                                 fMemoryManager);

    elemDecl->setId(_fElemNonDeclPool->put((void*)elemDecl->getBaseName(),
                                           uriId,
                                           currentScope,
                                           (SchemaElementDecl*)elemDecl));
        
    if(laxThisOne) 
    {
      fValidate = false;
      fElemStack.setValidationFlag(fValidate);
    }
    else if(fValidate && !isProcessorStipulatedTypeName) 
    {
      // This is to tell the reuse Validator that this element was
      // faulted-in, was not an element in the grammar pool originally
      elemDecl->setCreateReason(XMLElementDecl::JustFaultIn);
      
      fValidator->emitError(XMLValid::ElementNotDefined, elemDecl->getFullName());
    }
  }
  else
  {
    // If its not marked declared and validating, then emit an error
    if(!elemDecl->isDeclared()) 
    {
      if(laxThisOne) 
      {
        fValidate = false;
        fElemStack.setValidationFlag(fValidate);                
      }
      else if(fValidate) 
      {
        fValidator->emitError(XMLValid::ElementNotDefined, elemDecl->getFullName());
      }
    }
  }
  
  return elemDecl;
}


////////////////////////////////////////////////////////////////////////////////////////////////////


void SchemaValidatorFilter::docCharacters(
    const XMLCh* const chars, 
    const unsigned int length,
    const bool cdataSection)
{
  // The XercSchemaValidator calls this method to report default element values
  ///_eventBuffer->textEvent(chars, length);
}


void SchemaValidatorFilter::error(
    const unsigned int errCode,
    const XMLCh* const errDomain, 
    const XMLErrorReporter::ErrTypes errType,
    const XMLCh* const errorText,
    const XMLCh* const systemId,
    const XMLCh* const publicId, 
#if _XERCES_VERSION >= 30000
    const XMLFileLoc lineNum, const XMLFileLoc colNum
#else
    const XMLSSize_t lineNum, const XMLSSize_t colNum
#endif // _XERCES_VERSION >= 30000
    )
{
  _errorOccurred = true;
  _eventBuffer->resetAttList();
  _eventBuffer->resetTextInfo();

  // Skip validation errors if validation isn't strict
  if(!_strictValidation && errDomain == XMLUni::fgValidityDomain &&
     errType != XMLErrorReporter::ErrType_Fatal)
    return;
  
  XMLBuffer exc_msg(1023);
  exc_msg.set( XMLChArray("Schema validation failed: ").get() );
  exc_msg.append(errorText);
  
  if((publicId && *publicId) || (systemId && *systemId)) 
  {
    exc_msg.append( XMLChArray(", ").get() );
    if(systemId && *systemId)
      exc_msg.append(systemId);
    else
      exc_msg.append(publicId);
    
    if(lineNum != 0) 
    {
      exc_msg.append(':');
    }
  }
  
  //std::cout << XMLString::transcode(exc_msg.getRawBuffer()) << std::endl;
  
  ZORBA_ERROR_LOC_DESC( XQDY0027, _loc, StrX(exc_msg.getRawBuffer()).localForm() );
}

}  //namespace zorba

#endif // ZORBA_NO_XMLSCHEMA
