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
#ifndef ZORBA_STORE_LOAD_PROPERTIES_H
#define ZORBA_STORE_LOAD_PROPERTIES_H

#include "common/common.h"
#include "diagnostics/assert.h"
#include <libxml/parser.h>


namespace zorba
{

SYNC_CODE(class Lock;)


namespace store
{

/**
 * How should the document load be done
 */
class LoadProperties
{
private:
  bool theStoreDocument;
  bool theUseCachedDocument;
  zstring theBaseUri;
  bool theNoError;
  bool theStripWhitespace;
  bool theSchemaLaxValidate;
  bool theSchemaStrictValidate;
  bool theDTDValidate;
  bool theDTDLoad;
  bool theDefaultDTDAttributes;
  bool theParseExternalParsedEntity;
  unsigned int theSkipRootNodes;
  bool theSkipTopLevelTextNodes;
  bool theErrorOnDoctype;       // Used by the fragment parser. By default it will allow Doctype 
                                // declarations. But if a Doctype declaration is
                                // present, and the flag is set to true, an error will be generated.
  
  bool theSubstituteEntities;
  bool theXincludeSubstitutions;
  bool theRemoveRedundantNS;
  bool theNoCDATA;
  bool theNoXIncludeNodes;
  bool theNoNetworkAccess ;

  bool theCreateDocParentLink;  // Default true. If set to false, the parsed input
                                // nodes will not have their parent link set to the 
                                // the document node. This is used by the parse-fragment
                                // functions.
                               

public:
  LoadProperties()
    :
    theStoreDocument(true),
    theUseCachedDocument(true),
    theBaseUri(""),
    theNoError(false),
    theStripWhitespace(false),
    theSchemaLaxValidate(false),
    theSchemaStrictValidate(false),
    theDTDValidate(false),
    theDTDLoad(false),
    theDefaultDTDAttributes(false),
    theParseExternalParsedEntity(false),
    theSkipRootNodes(0),
    theSkipTopLevelTextNodes(false),
    theErrorOnDoctype(false),
    theSubstituteEntities(false),
    theXincludeSubstitutions(false),
    theRemoveRedundantNS(false),
    theNoCDATA(false),
    theNoXIncludeNodes(false),
    theNoNetworkAccess (false),
    theCreateDocParentLink(true)
  {
  }

  virtual ~LoadProperties()
  {
  }

  void reset()
  {
    theStoreDocument = true;
    theBaseUri = "";
    theNoError = false;
    theStripWhitespace = false;
    theSchemaLaxValidate = false;
    theSchemaStrictValidate = false;
    theDTDValidate = false;
    theDTDLoad = false;
    theDefaultDTDAttributes = false;
    theParseExternalParsedEntity = false;
    theSkipRootNodes = 0;
    theSkipTopLevelTextNodes = false;
    theErrorOnDoctype = false;
    theSubstituteEntities = false;
    theXincludeSubstitutions = false;
    theRemoveRedundantNS = false;
    theNoCDATA = false;
    theNoXIncludeNodes = false;
    theNoNetworkAccess  = false;
  }

  /**
   * Set the property storeDocument, it specifies whether the document
   * should be kept in the store (i.e. added to the set of documents)
   */
  void setStoreDocument(bool aStoreDocument)
  {
    theStoreDocument = aStoreDocument;
  }

  /**
   * Get the property storeDocument, it specifies whether the document
   * should be kept in the store (i.e. added to the set of documents)
   */
  bool getStoreDocument() const
  {
    return theStoreDocument;
  }

  /**
   * Set the property useCachedDocument, it specifies whether the loading
   * should be skipped if the document exists in the store already.
   */
  void setUseCachedDocument(bool v)
  {
    theUseCachedDocument = v;
  }

  bool getUseCachedDocument() const
  {
    return theUseCachedDocument;
  }

  // theBaseUri
  void setBaseUri(const zstring& aBaseUri)
  {
    theBaseUri = aBaseUri;
  }
  zstring getBaseUri() const
  {
    return theBaseUri;
  }

  // theNoError
  void setNoError(bool aNoError)
  {
    theNoError = aNoError;
  }
  bool getNoError() const
  {
    return theNoError;
  }

  // theStripWhitespace
  void setStripWhitespace(bool aStripWhitespace)
  {
    // This flag is only passed on to libxml2; however, libxml2 does not
    // implement this functionality correct, so (at least for now) it should
    // not be used.
    ZORBA_ASSERT(false);
    theStripWhitespace = aStripWhitespace;
  }
  bool getStripWhitespace() const
  {
    return theStripWhitespace;
  }

  // theSchemaLaxValidate
  void setSchemaLaxValidate(bool aSchemaLaxValidate)
  {
    theSchemaLaxValidate = aSchemaLaxValidate;
    if (theSchemaLaxValidate)
      theSchemaStrictValidate = false;
  }
  bool getSchemaLaxValidate() const
  {
    return theSchemaLaxValidate;
  }

  // theSchemaStrictValidate
  void setSchemaStrictValidate(bool aSchemaStrictValidate)
  {
    theSchemaStrictValidate = aSchemaStrictValidate;
    if (theSchemaStrictValidate)
      theSchemaLaxValidate = false;
  }
  bool getSchemaStrictValidate() const
  {
    return theSchemaStrictValidate;
  }

  // theDTDValidate
  void setDTDValidate(bool aDTDValidate)
  {
    theDTDValidate = aDTDValidate;
  }
  bool getDTDValidate() const
  {
    return theDTDValidate;
  }

  // theDTDLoad
  void setDTDLoad(bool aDTDLoad)
  {
    theDTDLoad = aDTDLoad;
  }
  bool getDTDLoad() const
  {
    return theDTDLoad;
  }

  // theDefaultDTDAttributes
  void setDefaultDTDAttributes(bool aDefaultDTDAttributes)
  {
    theDefaultDTDAttributes = aDefaultDTDAttributes;
  }
  bool getDefaultDTDAttributes() const
  {
    return theDefaultDTDAttributes;
  }

  // theParseExternalParsedEntity
  void setParseExternalParsedEntity(bool aParseExternalParsedEntity)
  {
    theParseExternalParsedEntity = aParseExternalParsedEntity;
  }
  bool getParseExternalParsedEntity() const
  {
    return theParseExternalParsedEntity;
  }

  // theSkipRootNodes
  void setSkipRootNodes(unsigned int aSkipRootNodes)
  {
    theSkipRootNodes = aSkipRootNodes;
  }
  unsigned int getSkipRootNodes() const
  {
    return theSkipRootNodes;
  }

  // theSkipTopLevelTextNodes
  void setSkipTopLevelTextNodes(bool aSkipTopLevelTextNodes)
  {
    theSkipTopLevelTextNodes = aSkipTopLevelTextNodes;
  }
  bool getSkipTopLevelTextNodes() const
  {
    return theSkipTopLevelTextNodes;
  }
  
  // theSkipTopLevelTextNodes
  void setErrorOnDoctype(bool aErrorOnDoctype)
  {
    theErrorOnDoctype = aErrorOnDoctype;
  }
  bool getErrorOnDoctype() const
  {
    return theErrorOnDoctype;
  }

  // theSubstituteEntities
  void setSubstituteEntities(bool aSubstituteEntities)
  {
    theSubstituteEntities = aSubstituteEntities;
  }
  bool getSubstituteEntities() const
  {
    return theSubstituteEntities;
  }

  // theXincludeSubstitutions
  void setXincludeSubstitutions(bool aXincludeSubstitutions)
  {
    theXincludeSubstitutions = aXincludeSubstitutions;
  }
  bool getXincludeSubstitutions() const
  {
    return theXincludeSubstitutions;
  }

  // theRemoveRedundantNS
  void setRemoveRedundantNS(bool aRemoveRedundantNS)
  {
    theRemoveRedundantNS = aRemoveRedundantNS;
  }
  bool getRemoveRedundantNS() const
  {
    return theRemoveRedundantNS;
  }

  // theNoCDATA
  void setNoCDATA(bool aNoCDATA)
  {
    theNoCDATA = aNoCDATA;
  }
  bool getNoCDATA() const
  {
    return theNoCDATA;
  }

  // theNoXIncludeNodes
  void setNoXIncludeNodes(bool aNoXIncludeNodes)
  {
    theNoXIncludeNodes = aNoXIncludeNodes;
  }
  bool getNoXIncludeNodes() const
  {
    return theNoXIncludeNodes;
  }
  
  // theNoXIncludeNodes
  void setCreateDocParentLink(bool aCreateDocParentLink)
  {
    theCreateDocParentLink = aCreateDocParentLink;
  }
  bool getCreateDocParentLink() const
  {
    return theCreateDocParentLink;
  }

  // theNoNetworkAccess 
  void setNoNetworkAccess(bool aNoNetworkAccess)
  {
    theNoNetworkAccess = aNoNetworkAccess;
  }
  bool getNoNetworkAccess() const
  {
    return theNoNetworkAccess ;
  }

  /**
   * @brief Return a libxml2 options bit-field based, suitable for using
   * while using libxml2 to parse XML. The following members of this
   * LoadProperties object are handled; others are ignored:
   *  - getStripWhitespace()
   *  - getDTDValidate()
   *  - getDTDLoad()
   *  - getDefaultDTDAttributes
   *  - getSubstituteEntities()
   *  - getXincludeSubstitutions()
   *  - getRemoveRedundantNS()
   *  - getNoCDATA()
   *  - getNoXIncludeNodes()
   *  - getNoNetworkAccess()
   * @return said bit-field.
   */
  int toLibXmlOptions() const
  {
    int options = 0;

    if (theStripWhitespace)
      options |= XML_PARSE_NOBLANKS;

    if (theDTDValidate)
      options |= XML_PARSE_DTDVALID;

    if (theDTDLoad)
      options |= XML_PARSE_DTDLOAD;

    if (theDefaultDTDAttributes)
      options |= XML_PARSE_DTDATTR;

    if (theSubstituteEntities)
      options |= XML_PARSE_NOENT;

    if (theXincludeSubstitutions)
      options |= XML_PARSE_XINCLUDE;

    if (theRemoveRedundantNS)
      options |= XML_PARSE_NSCLEAN;

    if (theNoCDATA)
      options |= XML_PARSE_NOCDATA;

    if (theNoXIncludeNodes)
      options |= XML_PARSE_NOXINCNODE;

    if (theNoNetworkAccess)
      options |= XML_PARSE_NONET; 

    return options;
  }
};

} // namespace store
} // namespace zorba

#endif /* ZORBA_STORE_LOAD_PROPERTIES_H */

/*
 * Local variables:
 * mode: c++
 * End:
 */
/* vim:set et sw=2 ts=2: */
