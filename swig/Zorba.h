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
#ifndef API_ZORBA_H
#define API_ZORBA_H

/**
 * The Zorba class is the single point of access to the %Zorba engine.
 * There exists one instance of the Zorba class per process.
 * It can be used to (1) create and compile queries,
 * (2) create static contexts,
 * (3) provides access to the XmlDataManager,
 * (4) provides access to the ItemFactory, and
 * (5) provides access to the PropertiesGlobal.
 */
class Zorba 
{
 private:
  zorba::Zorba* theZorba;
  Zorba(zorba::Zorba* aZorba) : theZorba(aZorba){};
 public:
  Zorba():theZorba(0){}
  Zorba(const Zorba& aZorba) : theZorba(aZorba.theZorba) {};
  
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
  static Zorba getInstance(const Store&);

  /** \brief Creates a new StaticContext.
   *
   * The method returns a StaticContext object that can be used
   * for compiling a query. Instances of the StaticContext class are
   * returned as a smart pointer.
   *
   * @return StaticContext_t a new StaticContext object.
   */
  StaticContext createStaticContext();

  /** \brief Creates an XQuery object.
   *
   * This methods creates an XQuery object without implicitliy assigning it
   * a query. An object returned by this method can be compiled (see compileQuery).
   *
   * @return XQuery the newly created XQuery object.
   */
  XQuery createQuery();

  /** \brief Creates and compiles an XQuery object.
   *
   * This methods creates an XQuery object and compiles the query string
   * passed to this method.
   *
   * @param aStr the query string for the new XQuery object.
   * @return XQuery the newly created and compiled XQuery object.
   */
  XQuery compileQuery(const std::string& aStr);

  /** \brief Creates and compiles an XQuery object using a StaticContext.
   *
   * This methods creates an XQuery object and compiles the query string
   * passed to this method. Compilation is done using the information
   * contained in the StaticContext that is passed as parameter.
   *
   * @param aStr the query string for the new XQuery object.
   * @param aStaticContext the StaticContext that contains information used for compiling the query.
   * @return XQuery the newly created and compiled XQuery object.
   */
  XQuery compileQuery(const std::string& aStr, StaticContext &aStaticContext );

  /** \brief Gets the singleton instance of the ItemFactory.
   *
   * @return ItemFactory the singleton instance of the ItemFactory.
   */
  ItemFactory getItemFactory();

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
   * @param aStr the query string for the new XQuery object.
   * @param aDiagnosticHandler the DiagnosticHandler to which errors should be reported.
   * @return XQuery the newly created and compiled XQuery object.
   */
  XQuery compileQuery(const std::string& aStr, DiagnosticHandler* aDiagnosticHandler);

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
   * @param aStr the query string for the new XQuery object.
   * @param aStaticContext the StaticContext that contains information used for compiling the query.
   * @param aDiagnosticHandler the DiagnosticHandler to which errors should be reported.
   * @return XQuery the newly created and compiled XQuery object.
   */
  XQuery compileQuery(const std::string& aStr, StaticContext &aStaticContext, 
                      DiagnosticHandler* aDiagnosticHandler);

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
   * @param aStr the query string for the new XQuery object.
   * @param aCompilerHints the CompilerHints used to compile the query.
   * @param aDiagnosticHandler the DiagnosticHandler to which errors should be reported.
   * @return XQuery the newly created and compiled XQuery object.
   */
  XQuery compileQuery(const std::string& aStr, CompilerHints &aCompilerHints, 
                      DiagnosticHandler* aDiagnosticHandler);


  /** \brief Gets the singleton instance of the XmlDataManager object.
   *
   * @return XmlDataManager the singleton instance of the XmlDataManager.
   */
  XmlDataManager getXmlDataManager();

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
  void shutdown();

  /** \brief Get information about the used version of %Zorba.
   *
   * @return Version information about the used %Zorba version.
   */
  std::string getVersion();

  /** \brief Get information about the used version of %Zorba.
   *
   * @return Version information about the used %Zorba version.
   */
  int getMajorVersion();

  /** \brief Get information about the used version of %Zorba.
   *
   * @return Version information about the used %Zorba version.
   */
  int getMinorVersion();

  /** \brief Get information about the used version of %Zorba.
   *
   * @return Version information about the used %Zorba version.
   */
  int getPatchVersion();

  /** \brief Get a boolean value informing if XQueryX is supported.
   *
   * @return A boolean value informing if XQueryX is supported.
   */
  bool isXQueryXSupported();

  /** \brief Creates and compiles an XQuery object.
   *
   * This methods creates an XQuery object and compiles the query string
   * passed to this method.
   *
   * @param stream the query stream, this object is an extension to stream data accross the API.
   * @return XQuery the newly created and compiled XQuery object.
   */
  XQuery compileQuery(ZorbaStream& stream);

  /** \brief Creates and compiles an XQuery object using a StaticContext.
   *
   * This methods creates an XQuery object and compiles the query string
   * passed to this method. Compilation is done using the information
   * contained in the StaticContext that is passed as parameter.
   *
   * @param stream the query stream, this object is an extension to stream data accross the API.
   * @param aStaticContext the StaticContext that contains information used for compiling the query.
   * @return XQuery the newly created and compiled XQuery object.
   */
  XQuery compileQuery(ZorbaStream& stream, StaticContext &aStaticContext );

}; // class Zorba

#endif
