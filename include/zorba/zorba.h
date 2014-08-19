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
#ifndef XQP_ZORBA_API_H
#define XQP_ZORBA_API_H

#include <istream>

#include <zorba/config.h>
#include <zorba/api_shared_types.h>
#include <zorba/collection.h>
#include <zorba/dynamic_context.h>
#include <zorba/diagnostic_handler.h>
#include <zorba/item.h>
#include <zorba/item_factory.h>
#include <zorba/jsondatamanager.h>
#include <zorba/options.h>
#include <zorba/static_context.h>
#include <zorba/version.h>
#include <zorba/xmldatamanager.h>
#include <zorba/document_manager.h>
#include <zorba/collection_manager.h>
#include <zorba/xquery.h>
#include <zorba/zorba_string.h>
#include <zorba/iterator.h>
#include <zorba/properties.h>

namespace zorba {

/**
 * The Zorba class is the single point of access to the %Zorba engine.
 * There exists one instance of the Zorba class per process.
 * It can be used to (1) create and compile queries,
 * (2) create static contexts,
 * (3) provides access to the XmlDataManager and JsonDataManager,
 * (4) provides access to the ItemFactory, and
 * (5) provides access to the Properties.
 */
class ZORBA_DLL_PUBLIC Zorba
{
 public:

  /** \brief Gets the singleton instance of the Zorba object.
   *
   * The Zorba object provides factory methods for creating and/or compiling
   * XQuery objects, creating StaticContext objects, and accessing components
   * as, for example, the ItemFactory or the XmlDataManager.
   *
   * The first time this function is called, the %Zorba Engine is initialized.
   * Thereby, it initializes all the libraries that are used in the system, i.e.
   * ICU, libxml2, xerces, and libcurl.
   *
   * @return Zorba the singleton Zorba object
   *
   */
  static Zorba*
  getInstance(void* store);

  /** \brief Get information about the used version of %Zorba.
   *
   * @return Version information about the used %Zorba version.
   */
  static const Version&
  version();


  /** \brief Destructor.
   *
   * The destructor is called during static deinitialization if getInstance
   * has been called at least once before.
   */
  virtual ~Zorba();

  /** \brief Releases all resources aquired by the Zorba %XQuery Engine.
   *
   * Also releases resources aquired by the libraries used (i.e. icu,
   * libxml2, xerces, libcurl).
   *
   * Before calling shutdown, all xquery objects, items, contexts, ... have
   * to be closed or gone out of scope; otherwise this call may fail.
   *
   * After shutdown has been called, any calls to zorba are invalid.
   *
   * getInstance may be used to reinitialize the engine.
   *
   */
  virtual void
  shutdown() = 0;

  /** \brief Creates an XQuery object.
   *
   * This methods creates an XQuery object without implicitliy assigning it
   * a query. An object returned by this method can be compiled (see compileQuery).
   *
   * Optionally, this method takes an DiagnosticHandler as parameter. In the case
   * an DiagnosticHandler is passed as parameter, each error that occurs during
   * compiling or executing the query, is reported to the passed error handler.
   * If no DiagnosticHandler is given, exceptions are thrown for each of these errors.
   *
   * @param aDiagnosticHandler the DiagnosticHandler to which errors should be reported.
   * @return XQuery the newly created XQuery object.
   */
  virtual XQuery_t
  createQuery(DiagnosticHandler* aDiagnosticHandler = 0) = 0;

  /** \brief Creates and compiles an XQuery object.
   *
   * This methods creates an XQuery object and compiles the query string
   * passed to this method.
   *
   * Optionally, this method takes an DiagnosticHandler as parameter. In the case
   * an DiagnosticHandler is passed as parameter, each error that occurs during
   * compiling or executing the query, is reported to the passed error handler.
   * If not DiagnosticHandler is given, exceptions are thrown for each of these errors.
   *
   * @param aQuery the query string for the new XQuery object.
   * @param aDiagnosticHandler the DiagnosticHandler to which errors should be reported.
   * @return XQuery the newly created and compiled XQuery object.
   */
  virtual XQuery_t
  compileQuery(const String& aQuery, DiagnosticHandler* aDiagnosticHandler = 0) = 0;

  /** \brief Creates and compiles an XQuery object using a StaticContext.
   *
   * This methods creates an XQuery object and compiles the query string
   * passed to this method. Compilation is done using the information
   * contained in the StaticContext that is passed as parameter.
   *
   * Optionally, this method takes an DiagnosticHandler as parameter. In the case
   * an DiagnosticHandler is passed as parameter, each error that occurs during
   * compiling or executing the query, is reported to the passed error handler.
   * If not DiagnosticHandler is given, exceptions are thrown for each of these errors.
   *
   * @param aQuery the query string for the new XQuery object.
   * @param aContext the StaticContext that contains information used for compiling the query.
   * @param aDiagnosticHandler the DiagnosticHandler to which errors should be reported.
   * @return XQuery the newly created and compiled XQuery object.
   */
  virtual XQuery_t
  compileQuery(const String& aQuery,
               const StaticContext_t& aContext,
               DiagnosticHandler* aDiagnosticHandler = 0) = 0;

  /** \brief Creates and compiles an XQuery object using the given CompilerHints.
   *
   * This methods creates an XQuery object and compiles the query string
   * passed to this method. Compilation and optimization is done with respect
   * to the given CompilerHints.
   *
   * Optionally, this method takes an DiagnosticHandler as parameter. In the case
   * an DiagnosticHandler is passed as parameter, each error that occurs during
   * compiling or executing the query, is reported to the passed error handler.
   * If not DiagnosticHandler is given, exceptions are thrown for each of these errors.
   *
   * @param aQuery the query string for the new XQuery object.
   * @param aCompilerHints the CompilerHints used to compile the query.
   * @param aDiagnosticHandler the DiagnosticHandler to which errors should be reported.
   * @return XQuery the newly created and compiled XQuery object.
   */
  virtual XQuery_t
  compileQuery(const String& aQuery,
               const Zorba_CompilerHints_t& aCompilerHints,
               DiagnosticHandler* aDiagnosticHandler = 0) = 0;

  /** \brief Creates and compiles an XQuery object using the given
   * CompilerHints and StaticContext.
   *
   * This methods creates an XQuery object and compiles the query string
   * passed to this method. Compilation and optimization is done with respect
   * to the given CompilerHints. Moreover, compilation is done using the
   * information contained in the StaticContext.
   *
   * Optionally, this method takes an DiagnosticHandler as parameter. In the case
   * an DiagnosticHandler is passed as parameter, each error that occurs during
   * compiling or executing the query, is reported to the passed error handler.
   * If not DiagnosticHandler is given, exceptions are thrown for each of these errors.
   *
   * @param aQuery the query string for the new XQuery object.
   * @param aContext the StaticContext that contains information used for compiling the query.
   * @param aCompilerHints the CompilerHints used to compile the query.
   * @param aDiagnosticHandler the DiagnosticHandler to which errors should be reported.
   * @return XQuery the newly created and compiled XQuery object.
   */
  virtual XQuery_t
  compileQuery(const String& aQuery,
               const StaticContext_t& aContext,
               const Zorba_CompilerHints_t& aCompilerHints,
               DiagnosticHandler* aDiagnosticHandler = 0) = 0;

  /** \brief Creates and compiles an XQuery object.
   *
   * This methods creates an XQuery object and compiles the query that is
   * passed to this method as an input stream.
   *
   * Optionally, this method takes an DiagnosticHandler as parameter. In the case
   * an DiagnosticHandler is passed as parameter, each error that occurs during
   * compiling or executing the query, is reported to the passed error handler.
   * If not DiagnosticHandler is given, exceptions are thrown for each of these errors.
   *
   * @param aQuery the input stream providing the query.
   * @param aDiagnosticHandler the DiagnosticHandler to which errors should be reported.
   * @return XQuery the newly created and compiled XQuery object.
   */
  virtual XQuery_t
  compileQuery(std::istream& aQuery, DiagnosticHandler* aDiagnosticHandler = 0) = 0;

  /** \brief Creates and compiles an XQuery object using a StaticContext.
   *
   * This methods creates an XQuery object and compiles the query that is
   * passed to this method as an input stream. Compilation is done using
   * the information contained in the StaticContext that is passed as
   * parameter.
   *
   * Optionally, this method takes an DiagnosticHandler as parameter. In the case
   * an DiagnosticHandler is passed as parameter, each error that occurs during
   * compiling or executing the query, is reported to the passed error handler.
   * If not DiagnosticHandler is given, exceptions are thrown for each of these errors.
   *
   * @param aQuery the input stream providing the query.
   * @param aContext the StaticContext that contains information used for compiling the query.
   * @param aDiagnosticHandler the DiagnosticHandler to which errors should be reported.
   * @return XQuery the newly created and compiled XQuery object.
   */
  virtual XQuery_t
  compileQuery(std::istream& aQuery,
               const StaticContext_t& aContext,
               DiagnosticHandler* aDiagnosticHandler = 0) = 0;

  /** \brief Creates and compiles an XQuery object using the given CompilerHints.
   *
   * This methods creates an XQuery object and compiles the query that is
   * passed to this method as an input stream. Compilation and optimization
   * is done with respect to the given CompilerHints.
   *
   * Optionally, this method takes an DiagnosticHandler as parameter. In the case
   * an DiagnosticHandler is passed as parameter, each error that occurs during
   * compiling or executing the query, is reported to the passed error handler.
   * If not DiagnosticHandler is given, exceptions are thrown for each of these errors.
   *
   * @param aQuery the input stream providing the query.
   * @param aCompilerHints the CompilerHints used to compile the query.
   * @param aDiagnosticHandler the DiagnosticHandler to which errors should be reported.
   * @return XQuery the newly created and compiled XQuery object.
   */
  virtual XQuery_t
  compileQuery(std::istream& aQuery,
               const Zorba_CompilerHints_t& aCompilerHints,
               DiagnosticHandler* aDiagnosticHandler = 0) = 0;

  /** \brief Creates and compiles an XQuery object using the given
   * CompilerHints and StaticContext.
   *
   * This methods creates an XQuery object and compiles the query that is
   * passed to this method as an input stream. Compilation and optimization
   * is done with respect to the given CompilerHints. Moreover, compilation
   * is done using the information contained in the StaticContext.
   *
   * Optionally, this method takes an DiagnosticHandler as parameter. In the case
   * an DiagnosticHandler is passed as parameter, each error that occurs during
   * compiling or executing the query, is reported to the passed error handler.
   * If not DiagnosticHandler is given, exceptions are thrown for each of these errors.
   *
   * @param aQuery the input stream providing the query.
   * @param aContext the StaticContext that contains information used for compiling the query.
   * @param aCompilerHints the CompilerHints used to compile the query.
   * @param aDiagnosticHandler the DiagnosticHandler to which errors should be reported.
   * @return XQuery the newly created and compiled XQuery object.
   */
  virtual XQuery_t
  compileQuery(std::istream& aQuery,
               const StaticContext_t& aContext,
               const Zorba_CompilerHints_t& aCompilerHints,
               DiagnosticHandler* aDiagnosticHandler = 0) = 0;

  /** \brief Creates a new StaticContext.
   *
   * The method returns a smart pointer to a new StaticContext object that can
   * be used for compiling a query.
   *
   * @param aDiagnosticHandler the DiagnosticHandler to which errors should be
   *        reported. If not DiagnosticHandler is given, exceptions are thrown
   *        for each of these errors.
   * @return StaticContext_t a smart pointer to a new StaticContext object.
   */
  virtual StaticContext_t
  createStaticContext(DiagnosticHandler* aDiagnosticHandler = 0) = 0;

  /** \brief Returns an XmlDataManager object.
   *
   * @return XmlDataManager an XmlDataManager.
   */
  virtual XmlDataManager_t
  getXmlDataManager() = 0;

  /** \brief Returns a JsonDataManager object.
   *
   * @return JsonDataManager a JsonDataManager.
   */
  virtual JsonDataManager_t
  getJsonDataManager() = 0;

  /** \brief Gets the singleton instance of the ItemFactory.
   *
   * @return ItemFactory the singleton instance of the ItemFactory.
   */
  virtual ItemFactory*
  getItemFactory() = 0;

  /** \brief Gets the singleton instance of Zorba's audit provider object.
   *
   * @return audit::Provider the singeleton instance of Zorba's audit provider.
   */
  virtual audit::Provider*
  getAuditProvider() = 0;

  /** \brief Gets the singleton instance of Zorba's properties object.
   *
   * @return zorba::Properties the singleton instance of Zorba's properties
   * object.
   * @deprecated Use Properties::instance() instead.
   */
  virtual Properties* getProperties() = 0;

  /**
   * @deprecated Use Properties::instance() instead.
   */
  Properties* getPropertiesGlobal() {
    return getProperties();
  }

}; /* class Zorba */


} /* namespace zorba */

/**
 * \example simple.cpp
 *  This is a simple example that demonstrate how to create, compile, and execute queries.
 *
 * \example datamanager.cpp
 *  This file contains some examples that demonstrate how the XmlDataManager can be used
 *  to load files, create collection, etc.
 *
 * \example context.cpp
 *  This file demonstrates how the ItemFactory can be used to create new Items and
 *  bind the Items to external variables in the dynamic context of a query.
 *
 * \example errors.cpp
 *  This file demonstrates how error management and handling is done in Zorba.
 *
 * \example serialization.cpp
 * This file shows examples of how to serialize query results, for example as XML.
 *
 * \example sax2.cpp
 * An example showing XML serialization that is performed using SAX2.
 *
 * \example external_functions.cpp
 * This file shows some simple examples of external functions.
 *
 */
#endif /* XQP_ZORBA_API_H */

/*
 * Local variables:
 * mode: c++
 * End:
 */
/* vim:set et sw=2 ts=2: */
