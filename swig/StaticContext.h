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
#ifndef API_STATIC_CONTEXT_H
#define API_STATIC_CONTEXT_H

#include <zorba/static_context_consts.h>

class ZorbaConstants
{
public:
  typedef enum {
    PRESERVE,
    NO_PRESERVE
  } PreserveMode;

  typedef enum {
    INHERIT,
    NO_INHERIT
  } InheritMode;

  typedef enum {
    PRESERVE_SPACE,
    STRIP_SPACE
  } BoundarySpaceMode;

  typedef enum {
    PRESERVE_CONSTRUCTION,
    STRIP_CONSTRUCTION
  } ConstructionMode;

  typedef enum {
    EMPTY_GREATEST,
    EMPTY_LEAST
  } OrderEmptyMode;

  typedef enum {
    ORDERED,
    UNORDERED
  } OrderingMode;

  typedef enum {
    VALIDATE_SKIP,
    VALIDATE_LAX,
    VALIDATE_STRICT
  } RevalidationMode;

  typedef enum {
    XPATH2_0,
    XPATH1_0
  } XPath1_0CompatibleMode;

}; // ZorbaConstants

  /** \brief Instances of the class StaticContext contain the information that is available
   *         at the time the query is compiled.
   *
   * This class contains the information that is defined in the %XQuery specification
   * (see http://www.w3.org/TR/xquery/#static_context).
   *
   * A StaticContext can be created by calling Zorba::createStaticContext and then be passed
   * to the Zorba::compileQuery or XQuery::compile functions.
   * If no static context has been passed to any of these functions, a default static context
   * is used. It can be accessed by calling XQuery::getStaticContext on a compiled XQuery object.
   *
   */
class StaticContext 
{
friend class Zorba;
friend class XQuery;

private:
  zorba::StaticContext_t theStaticContext;
public:

  StaticContext(const StaticContext& aStaticContext);
  StaticContext(zorba::StaticContext_t aStaticContext);
  
  /** \brief Adds a collation URI.
   *
   * The URI specifies the locale and collation strength of the collation that is added.
   * A valid collation URI must begin with %http://www.zorba-xquery.com/collations/.
   * This prefix is followed by a collation strength (i.e. PRIMARY, SECONDARY, TERTIARY,
   * QUATTERNARY, or IDENTICAL) followed by a '/'.
   * After the strength a lower-case two- or three-letter ISO-639 language code must follow.
   * The URI may end with an upper-case two-letter ISO-3166.
   * For example, %http://www.zorba-xquery.com/collations/PRIMARY/en/US
   * specifies an english language with US begin the country..
   *
   * Internally, ICU is used for comparing strings. For detailed description see
   * http://www.icu-project.org/apiref/icu4c/classCollator.html
   * and http://www.icu-project.org/apiref/icu4c/classLocale.html
   *
   * @param aURI the URI of the collation.
   * @throw ZorbaException if an error occured (e.g. the URI was not a valid
   *        collation URI).
   */
  void addColation(const std::string& aURI); 

  /** \brief Add a pair (prefix, URI) to the statically known namespaces that
   *         are available during query compilation.
   *
   *  See http://www.w3.org/TR/xquery/#static_context.
   *
   *  @param aPrefix the prefix String.
   *  @param aURI the URI String.
   *  @return true if the pair was added to the set of statically known namespaces,
   *          false otherwise.
   *  @throw ZorbaException if an error occures.
   */
  bool addNamespace(const std::string& aPrefix,
                            const std::string& aURI);

  /** \brief Check if a function with the given name and arity are registered in the context.
   */
  bool containsFunction(const std::string &aFnNameUri, 
                                const std::string &aFnNameLocal, 
                                int arity) const;

  /** \brief Create a child static context, i.e. a context with the same information,
   *         of the given static context.
   *
   * A child static context carries the same context as it's parent but
   * can override any information.
   */
  StaticContext createChildContext() const;

  /** \brief Declare an option (same as using declare option in XQuery)
   *
   * @param aQName The QName of the option to declare.
   * @param aOptionVal The value of the option to declare.
   */
  void declareOption(const Item &aQName, 
                             const std::string &aOptionVal);

  void disableFunction(const Item &aQName, int arity);

  /** \brief Get the base URI.
   *
   * @return String the base URI.
   */
  std::string getBaseURI () const;

  /** \brief Get the boundary space policy.
   *         (see http://www.w3.org/TR/xquery/#static_context)
   *
   * @return boundary_space_mode_t the boundary space policy.
   */
  ZorbaConstants::BoundarySpaceMode getBoundarySpacePolicy ();

  /** \brief Get the construction mode.
   *         (see http://www.w3.org/TR/xquery/#static_context)
   *
   * @return construction_mode_t the construction mode.
   */
  ZorbaConstants::ConstructionMode  getConstructionMode();

  /** \brief Get the copy namespace mode for Preserve.
   *         (see http://www.w3.org/TR/xquery/#static_context)
   *
   * @return aPreserve the preserve mode.
   */
  ZorbaConstants::PreserveMode getCopyNamespacesModePreserve();

  /** \brief Get the copy namespace mode for Preserve.
   *         (see http://www.w3.org/TR/xquery/#static_context)
   *
   * @return aInherit the inherit mode.
   */
  ZorbaConstants::InheritMode  getCopyNamespacesModeInherit();

  /** \brief Get the default order for the empty sequence.
   *         (see http://www.w3.org/TR/xquery/#static_context)
   *
   * @return order_empty_mode_t the ordering mode.
   */
  ZorbaConstants::OrderEmptyMode getDefaultOrderForEmptySequences();

  /** \brief Get the ordering mode.
   *         (see http://www.w3.org/TR/xquery/#static_context)
   *
   * @return ordering_mode_t the ordering mode.
   */
  ZorbaConstants::OrderingMode getOrderingMode();

  /** \brief Get the revalidation mode.
   *
   * @return the revalidation mode.
   */
  ZorbaConstants::RevalidationMode getRevalidationMode();

  /** \brief Get the XPath 1.0 compatibility mode.
   *         (see http://www.w3.org/TR/xquery/#static_context)
   *
   * @return xpath1_0compatib_mode_t the XPath 1.0 compatibility mode.
   */
  ZorbaConstants::XPath1_0CompatibleMode getXPath1_0CompatibMode();

  /** \brief Get the URI of the default collation
   *
   * @return String the URI of the default collation.
   */
  std::string getDefaultCollation () const;

  /** \brief Get the default element and type namespace URI.
   *
   * @return String the URI for the default element and type namespace.
   * @throw ZorbaException if an error occured.
   */
  std::string getDefaultElementAndTypeNamespace () const;

  /** \brief Get the default function namespace.
   *
   * @return String the URI of the default function namespace.
   *         DiagnosticHandler has been registered.
   * @throw ZorbaException if an error occured.
   */
  std::string getDefaultFunctionNamespace () const;
  
  /**
   * \brief Get the list of all namespace bindings (prefix, uri)
   *   declared in this and its parent static contexts.
   */
  std::vector< std::pair< std::string, std::string > > getNamespaceBindings ();

  /** \brief Get the namespace URI for a given prefix.
   *
   * @param aPrefix the prefix for which to retrieve the namespace URI.
   * @return String the URI for the given prefix or an empty String if no URI
   *         could be found for the given prefix and an DiagnosticHandler has been
   *         registered.
   * @throw ZorbaException if an error occured (e.g. no URI could be found for the given prefix).
   *
   * @deprecated This function is deprecated. Use getNamespaceBindings instead.
   */
  std::string getNamespaceURIByPrefix(const std::string &aPrefix) const;

  /** \brief Get an option that was declared using the declare option syntax
   *
   * @param aQName The QName of the option to get.
   * @param aOptionValue The value of the option if found.
   * @return true if the option was found, false otherwise.
   */
  bool getOption(const Item &aQName, std::string &aOptionValue) const;

  /** \brief Loads the declarations and definitions of a given XQuery prolog into
   *         this static context.
   *
   * This function compiles the prolog passed as first parameter and loads
   * all declarations and definitions into this static context.
   *
   * The static context extended by this prolog can then be used for creating
   * a compiling a new query.
   *
   * A StaticException is raised if the prolog could not be compiled or
   * if the prolog does not contain valid declarations (e.g. duplicate declarations).
   */
  void loadProlog (const std::string & aProlog, const CompilerHints &hints);

  /** \brief Returns a CollectionManager responsible for all collections
   * which are statically declared in this static context.
   *
   * The collection manager provides a set of functions for managing
   * collections and their contents.
   *
   * @return The collection manager responsible for managing
   *   collections of this context.
   *
   */
  StaticCollectionManager getStaticCollectionManager();

  /** \brief Returns the QName of all external variables within the
   *        static context
   *
   * @param vars iterator to store the results.
   * @throw ZorbaException if an error occured.
   */
  void getExternalVariables(Iterator& vars) const;
  
  /** \brief Get the type of a statically known collection
   */
  TypeIdentifier getCollectionType(const std::string &aCollectionUri);

  /** \brief Get the type of a statically known document
   */
  TypeIdentifier getDocumentType(const std::string &aDocUri);

  /** \brief Fetch the type of the context item.
   */
  TypeIdentifier getContextItemStaticType();

  /** \brief Set the type of the context item.
   */
  void setContextItemStaticType(const TypeIdentifier &aType);
  
  /** \brief Resets the output stream that is used by the fn:trace function to std::cerr
   */
  void resetTraceStream ();

  /** \brief Set the base URI.
   *         (see http://www.w3.org/TR/xquery/#static_context)
   *
   * @param aBaseURI the base URI as String.
   * @return true if the base URI has been set, false otherwise.
   */
  bool setBaseURI (const std::string &aBaseURI);

  /** \brief Set the boundary space policy.
   *         (see http://www.w3.org/TR/xquery/#static_context)
   *
   * @param aMode the boundary space policy.
   * @return true if the mode was set, false otherwise.
   */
  bool setBoundarySpacePolicy (ZorbaConstants::BoundarySpaceMode aMode);

  /** \brief Set the construction mode.
   *         (see http://www.w3.org/TR/xquery/#static_context)
   *
   * @param aMode the construction mode.
   * @return true if the mode was set, false otherwise.
   */
  bool setConstructionMode (ZorbaConstants::ConstructionMode aMode);

  /** \brief Set the copy namespace mode.
   *         (see http://www.w3.org/TR/xquery/#static_context)
   *
   * @param aPreserve the preserve mode.
   * @param aInherit the inherit mode.
   * @return true if the mode was set, false otherwise.
   */
  bool setCopyNamespacesMode (ZorbaConstants::PreserveMode aPreserve, ZorbaConstants::InheritMode aInherit);

  /** \brief Set the default order for the empty sequence.
   *         (see http://www.w3.org/TR/xquery/#static_context)
   *
   * @param aMode the default order for the empty sequence.
   * @return true if the mode was set, false otherwise.
   */
  bool setDefaultOrderForEmptySequences (ZorbaConstants::OrderEmptyMode aMode);

  /** \brief Set the ordering mode.
   *         (see http://www.w3.org/TR/xquery/#static_context)
   *
   * @param aMode the ordering mode.
   * @return true if the mode was set, false otherwise.
   */
  bool setOrderingMode (ZorbaConstants::OrderingMode aMode);

  /** \brief Set the revalidation mode.
   *
   * @param aMode the revalidation mode.
   */
  void setRevalidationMode (ZorbaConstants::RevalidationMode aMode);

  /**
   * @brief Set the URI lookup path (list of filesystem directories) for this
   * static context.
   *
   * Queries which resolve URIs (for instance, importing modules or schemas)
   * will look in these directories.
   */
  void setURIPath(std::vector< std::string > &aURIPath );

  /**
   * @brief Set the library lookup path (list of filesystem directories) for
   * this static context.
   *
   * Queries which import modules that have external function
   * implementations will look for the implementation of those functions
   * (shared libraries) in these directories.
   */
  void setLIBPath(std::vector< std::string > &aLIBPath );

  /**
   * @brief Set the URI and library lookup paths (lists of filesystem
   * directories) for this static context. Note that calling this method
   * will override any values previously passed to StaticContext::setURIPath()
   * and StaticContext::setLibPath().
   * @deprecated Use StaticContext::setURIPath() and StaticContext::setLibPath().
   *
   * Convenience method which adds the listed directories to both the
   * URI path and Library path for this static context.
   */
  void setModulePath(std::vector< std::string > &aModulePath );

  /** \brief Set the XPath 1.0 compatibility mode.
   *         (see http://www.w3.org/TR/xquery/#static_context)
   *
   * @param aMode the XPath 1.0 compatibility mode.
   * @return true if the mode was set, false otherwise.
   */
  bool setXPath1_0CompatibMode (ZorbaConstants::XPath1_0CompatibleMode aMode);
  
  /** \brief Set the URI of the default collation.
   *         (see http://www.w3.org/TR/xquery/#static_context)
   *
   * @param aURI URI of the default collation.
   * @throw ZorbaException if an error occured (e.g., the URI does not
   *        identify a collation among the statically known collations.
   */
  void setDefaultCollation (const std::string &aURI);

  /** \brief Set the default element and type namespace
   *         (see http://www.w3.org/TR/xquery/#static_context)
   *
   * @param aURI of the default element and type namespace URI.
   * @return true if the default element and type namespace URI has been set, false otherwise
   *         if an DiagnosticHandler has been registered.
   * @throw ZorbaException if an error occured.
   */
  bool setDefaultElementAndTypeNamespace (const std::string &aURI);

  /** \brief Set the default functionnamespace
   *         (see http://www.w3.org/TR/xquery/#static_context)
   *
   * @param aURI of the default function namespace.
   * @return true if the default function namespace URI has been set, false otherwise
   *         if an DiagnosticHandler has been registered.
   * @throw ZorbaException if an error occured.
   */
  bool setDefaultFunctionNamespace (const std::string &aURI);

  /** \brief Destroy this object from memory
   */
  void destroy();
}; // class StaticContext

#endif