/*
 * Copyright 2006-2012 The FLWOR Foundation.
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
#ifndef API_XML_DATA_MANAGER_H
#define API_XML_DATA_MANAGER_H

  /** \brief Using the XmlDataManager one can manage documents and collections.
   *
   * The XmlDataManager is a singleton instance. The Zorba object is reponsible
   * for maintaining its lifetime. The instance can be accessed by calling
   * getXmlDataManager() on the Zorba object. It may not be accessed anymore
   * after Zorba::shutdown() has been called.
   *
   * XmlDataManager is a thread-safe class.
   */
class XmlDataManager
{
private:
  zorba::XmlDataManager* theManager;

public:
  XmlDataManager(const XmlDataManager& aMgr) : theManager(aMgr.theManager) {}
  XmlDataManager(zorba::XmlDataManager* aMgr) : theManager(aMgr) {}

    /** \brief Returns a DocumentManager
     * 
     * @return The document manager.
     *
     */
  DocumentManager getDocumentManager();

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
  CollectionManager getCollectionManager();

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
  CollectionManager getW3CCollectionManager();

    /** \brief Parse an XML document and return an Iterator.
     *
     * @param aDoc the input string whose content should be parsed
     */
  Iterator parseXML(const std::string& aDoc);

    /** \brief Parse an XML document and return an Item.
     *
     * @param aDoc the input string whose content should be parsed
     */
  Item parseXMLtoItem(const std::string& aDoc);

};
#endif