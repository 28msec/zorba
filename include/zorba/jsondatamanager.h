/*
 * Copyright 2006-2014 The FLWOR Foundation.
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
#ifndef ZORBA_JSONDATAMANAGER_API_H
#define ZORBA_JSONDATAMANAGER_API_H

#include <istream>
#include <zorba/config.h>
#include <zorba/api_shared_types.h>
#include <zorba/static_context_consts.h>

namespace zorba {

/**
 * \brief Using the JsonDataManager one can parse JSON data.
 *
 * An instance of JsonDataManager can be obtained via the Zorba::getJsonDataManager()
 * method. The instance must be destroyed before Zorba::shutdown() is called.
 */
class ZORBA_DLL_PUBLIC JsonDataManager : public SmartObject
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
    bool              theMultipleTopLevelItems;
    bool              theStripTopLevelArray;

  public:
    ParseOptions():
      theMultipleTopLevelItems(true),
      theStripTopLevelArray(false)
    {
    }

    ~ParseOptions() {}

    /**
     * Set the multiple top level items property, which specifies
     * whether the multiple top level items are allowed or not.
     *
     * If multiple top level items are not allowed and the parsed
     * stream contains more than one top level items an error is
     * raised.
     */
    void setMultipleTopLevelItems(bool aEnable)
    {
      theMultipleTopLevelItems = aEnable;
    }
    
    /**
     * Returns true if dtd validation is enabled, false otherwise.
     */
    bool isMultipleTopLevelItemsEnabled() const
    {
      return theMultipleTopLevelItems;
    }
    
    /**
     * Set the property to enable or disable stripping of to level arrays
     */
    void setStripTopLevelArray(bool aEnable)
    {
      theStripTopLevelArray = aEnable;
    }
    
    /**
     * Returns true if strip top level array is enabled,
     * false otherwise.
     */
    bool isStripTopLevelArray() const
    {
      return theStripTopLevelArray;
    }
  };

  /**
   * \brief Parse an XML document and return an Item.
   */
  virtual ItemSequence_t
  parseJSON(std::istream& aStream) const = 0;

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
  parseJSON(std::istream& aStream, ParseOptions& aOptions) const = 0;

  /** \brief Register a DiagnosticHandler to which errors occurring during the
   * parsing of JSON streams.
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

 protected:
  /** \brief Destructor
   */
  virtual ~JsonDataManager() {}
  
}; /* class JsonDataManager */

} // namespace zorba
#endif /* ZORBA_JSONDATAMANAGER_API_H */
