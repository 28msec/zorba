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
#ifndef ZORBA_XMLDATAMANAGER_API_H
#define ZORBA_XMLDATAMANAGER_API_H

#include <istream>
#include <zorba/config.h>
#include <zorba/api_shared_types.h>
#include <zorba/static_context_consts.h>

namespace zorba {

  /** \brief Using the XmlDataManager one can manage documents and collections.
   *
   * The XmlDataManager is a singleton instance. The Zorba object is reponsible
   * for maintaining its lifetime. The instance can be accessed by calling
   * getXmlDataManager() on the Zorba object. It may not be accessed anymore
   * after Zorba::shutdown() has been called.
   *
   * XmlDataManager is a thread-safe class.
   */
  class ZORBA_DLL_PUBLIC XmlDataManager
  {
  public:
    /**
     * \brief The ParseOptions class stores various properties that affect
     *        how a document is parsed. An instance of this class is passed
     *        as input to the parseXML function.
     */
    class ParseOptions
    {
    private:
      bool              theDtdValidation;
      bool              theExternalEntityProcessing;

    public:
      ParseOptions() :
        theDtdValidation(false),
        theExternalEntityProcessing(false)
      {}

      ~ParseOptions() {}

      /**
       * Set the property enableDtd, which specifies whether the
       * document should be validated against its associated DTD (if
       * any).
       */
      void setDtdValidation(bool aEnable)
      {
        theDtdValidation = aEnable;
      }

      /**
       * Returns true if dtd validation is enabled, false otherwise.
       */
      bool isDtdValidationEnabled() const
      {
        return theDtdValidation;
      }

      /**
       * Set the property to enable or disable processing of XML external entities. 
       * If the option is enabled, the input must conform to the syntax
       * _extParsedEnt_ (production [78] in XML 1.0); and since there is no DTD,
       * the content must include no entity references. The result of the
       * function call is a sequence of nodes.
       */
      void setExternalEntityProcessing(bool aEnable)
      {
        theExternalEntityProcessing = aEnable;
      }

      /**
       * Returns true if external entity processig is enabled,
       * false otherwise.
       */
      bool isExternalEntityProcessingEnabled() const
      {
        return theExternalEntityProcessing;
      }
    };

    virtual DocumentManager*
    getDocumentManager() const = 0;

    /** \brief Returns a CollectionManager responsible for all collections.
     * 
     * The collection manager provides a set of functions for managing
     * collections identified by a QName and their contents.
     *
     * Please note that the resulting manager is only responsible for
     * dynamic collections identified by a QName, i.e. those that are
     * not declared in the prolog of a module or identified by a URI.
     *
     * @return The collection manager responsible for managing
     *   collections.
     *
     */
    virtual CollectionManager*
    getCollectionManager() const = 0;

    /** \brief Returns a CollectionManager responsible for collections
     * identified by a URI.
     * 
     * The collection manager provides a set of functions for managing
     * collections identified by a URI and their contents.
     *
     * Please note that the resulting manager is only responsible for
     * dynamic collections identified by a URI, i.e. those that are
     * not declared in the prolog of a module or identified by a QName.
     *
     * @return The collection manager responsible for managing
     *   collections.
     *
     */
    virtual CollectionManager*
    getW3CCollectionManager() const = 0;

    /** \brief Parse an XML document and return an Item.
     *
     */
    virtual Item
    parseXML(std::istream& aStream) const = 0;

    /** \brief Parse an XML document and return an Item.
     *
     * @param aStream the input stream whose content should be parsed
     * @param aBaseURI the base URI which will be used as the base URI
     *                 of the document. This serves both as the base URI
     *                 used by the XML parser to resolve relative entity
     *                 references within the document, and as the base URI
     *                 of the document node that is returned.
     */
    virtual Item
    parseXML(std::istream& aStream, const String& aBaseURI) const = 0;

    /** \brief Parse an XML document and return a sequence of nodes.
     *
     * This function parses the given input stream and returns the result
     * as a sequence of nodes. If external entity processing is disabled
     * the result will be a singleton sequence consisting of one document
     * node. Otherwise, the result is the sequence of the external entity
     * nodes.
     *
     * @param aStream the input stream whose content should be parsed
     * @param aOptions @see ParseOptions
     * @see ParseOptions
     */
    virtual ItemSequence_t
    parseXML(std::istream& aStream, ParseOptions& aOptions) const = 0;

    /** \brief Parse an XML document and return a sequence of nodes.
     *
     * This function parses the given input stream and returns the result
     * as a sequence of nodes. If external entity processing is disabled
     * the result will be a singleton sequence consisting of one document
     * node. Otherwise, the result is the sequence of the external entity
     * nodes.
     *
     * @param aStream the input stream whose content should be parsed
     * @param aBaseURI the base URI which will be used as the base URI
     *                 of the document. This serves both as the base URI
     *                 used by the XML parser to resolve relative entity
     *                 references within the document, and as the base URI
     *                 of the document node that is returned.
     * @param aOptions @see ParseOptions
     * @see ParseOptions
     */
    virtual ItemSequence_t
    parseXML(
        std::istream& aStream,
        const String& aBaseURI,
        ParseOptions& aOptions) const = 0;

    /** \brief Fetches an resource refered to by the given URI.
     */
    virtual Item
    fetch(const String& aURI) const = 0;

    /** \brief Register a DiagnosticHandler to which errors occuring during the
     * management of documents and collections are reported.
     *
     * If no DiagnosticHandler has been set using this function then
     * subclasses of the ZorbaException class are thrown to report
     * errors.
     *
     *  @param aDiagnosticHandler DiagnosticHandler to which errors
     *         are reported. The caller retains ownership over the
     *         DiagnosticHandler passed as parameter.
     */
    virtual void
    registerDiagnosticHandler(DiagnosticHandler* aDiagnosticHandler) = 0;

#ifndef ZORBA_NO_FULL_TEXT
    /**
     * Registers a StemmerProvider to use for stemming of text content in order
     * to perform queries involving full-text.
     *
     * If no StemmerProvider has been set using this function, then the default
     * StemmerProvider will be used.
     *
     * @param provider If not NULL, sets the StemmerProvider to use; if NULL,
     * removes any previously registered StemmerProvider.
     */
    virtual void
    registerStemmerProvider(StemmerProvider const *provider) = 0;

    /**
     * Registers a TokenizerProvider to use for toknenization of text content
     * in order to perform queries involving full-text.
     *
     * If no TokenizerProvider has been set using this function, then the
     * default TokenizerProvider will be used.
     *
     * @param provider If not NULL, sets the TokenizerProvider to use; if NULL,
     * removes any previously registered TokenizerProvider.
     */
    virtual void
    registerTokenizerProvider(TokenizerProvider const *provider) = 0;
#endif /* ZORBA_NO_FULL_TEXT */

    protected:
    /** \brief Destructor
     */
    virtual ~XmlDataManager() {}

  }; /* class XmlDataManager */

} // namespace zorba
#endif /* ZORBA_XMLDATAMANAGER_API_H */
/* vim:set et sw=2 ts=2: */
