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
#ifndef XQP_STATIC_CONTEXT_API_H
#define XQP_STATIC_CONTEXT_API_H

#include <vector>

#include <zorba/config.h>
#include <zorba/api_shared_types.h>
#include <zorba/zorba_string.h>
#include <zorba/typeident.h>
#include <zorba/static_context_consts.h>
#include <zorba/options.h>  // for compiler hints class
#include <zorba/function.h>
#include <zorba/annotation.h>
#include <zorba/util/smart_ptr.h>
#ifndef ZORBA_NO_FULL_TEXT
#include <zorba/thesaurus.h>
#endif /* ZORBA_NO_FULL_TEXT */
#include <zorba/zorba.h>
#include <zorba/store_manager.h>
#include <zorba/zorba_exception.h>

namespace zorba {

/** \brief Instances of the class StaticContext contain the information that is
 *         available at the time the query is compiled and run.
 *
 * This class contains the information that is defined in the %XQuery specification
 * (see http://www.w3.org/TR/xquery/#static_context).
 *
 * A StaticContext can be created by calling Zorba::createStaticContext and then
 * be passed to the Zorba::compileQuery or XQuery::compile functions. If no
 * static context has been passed to any of these functions, a default static
 * context is used. It can be accessed by calling XQuery::getStaticContext on
 * a compiled XQuery object.
 *
 * Note: This class is reference counted. When writing multi-threaded clients,
 * it is the responibility of the client code to synchronize assignments to the
 * SmartPtr holding this object.
 */
class ZORBA_DLL_PUBLIC StaticContext : public SmartObject
{
 public:
  /** \brief Destructor
   */
  virtual ~StaticContext() {}

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
  virtual void
  loadProlog(const String&, const Zorba_CompilerHints_t &hints) = 0;
  
  /** \brief Create a child static context, i.e. a context with the same information,
   *         of the given static context.
   *
   * A child static context carries the same context as it's parent but
   * can override any information.
   */
  virtual StaticContext_t
  createChildContext() const = 0;

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
  virtual bool
  addNamespace( const String& aPrefix, const String& aURI ) = 0;

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
  virtual String
  getNamespaceURIByPrefix( const String& aPrefix ) const = 0;

  /**
   * \brief Get the list of all namespace bindings (prefix, uri)
   *   declared in this and its parent static contexts.
   *
   * @param aBindings the bindings are added to this list
   */
  virtual void
  getNamespaceBindings( NsBindings& aBindings ) const = 0;

  /** \brief Set the default element and type namespace
   *         (see http://www.w3.org/TR/xquery/#static_context)
   *
   * @param aURI of the default element and type namespace URI.
   * @return true if the default element and type namespace URI has been set, false otherwise
   *         if an DiagnosticHandler has been registered.
   * @throw ZorbaException if an error occured.
   */
  virtual bool
  setDefaultElementAndTypeNamespace( const String& aURI ) = 0;
  
  /** \brief Get the default element and type namespace URI.
   *
   * @return String the URI for the default element and type namespace.
   * @throw ZorbaException if an error occured.
   */
  virtual String
  getDefaultElementAndTypeNamespace( ) const = 0;
  
  /** \brief Set the default functionnamespace
   *         (see http://www.w3.org/TR/xquery/#static_context)
   *
   * @param aURI of the default function namespace.
   * @return true if the default function namespace URI has been set, false otherwise
   *         if an DiagnosticHandler has been registered.
   * @throw ZorbaException if an error occured.
   */
  virtual bool
  setDefaultFunctionNamespace( const String& aURI ) = 0;

  /** \brief Get the default function namespace.
   *
   * @return String the URI of the default function namespace.
   *         DiagnosticHandler has been registered.
   * @throw ZorbaException if an error occured.
   */
  virtual String
  getDefaultFunctionNamespace( ) const = 0;

  /** \brief Adds a collation URI.
   *
   * The URI specifies the locale and collation strength of the collation that is added.
   * A valid collation URI must begin with %http://zorba.io/collations/.
   * This prefix is followed by a collation strength (i.e. PRIMARY, SECONDARY, TERTIARY,
   * QUATTERNARY, or IDENTICAL) followed by a '/'.
   * After the strength a lower-case two- or three-letter ISO-639 language code must follow.
   * The URI may end with an upper-case two-letter ISO-3166.
   * For example, %http://zorba.io/collations/PRIMARY/en/US
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
  virtual void
  addCollation( const String& aURI ) = 0;

  /** \brief Set the URI of the default collation.
   *         (see http://www.w3.org/TR/xquery/#static_context)
   *
   * @param aURI URI of the default collation.
   * @throw ZorbaException if an error occured (e.g., the URI does not
   *        identify a collation among the statically known collations.
   */
  virtual void
  setDefaultCollation( const String& aURI ) = 0;

  /** \brief Get the URI of the default collation
   *
   * @return String the URI of the default collation.
   */
  virtual String
  getDefaultCollation() const = 0;

  /** \brief Set the XQuery processing mode (version 1.0 or 3.0).
   *
   *
   * @param aMode the XQuery version.
   * @return true if the version was set, false otherwise.
   */
  virtual bool
  setXQueryVersion( xquery_version_t aMode ) = 0;

  /** \brief Set the JSONiq processing mode
   *
   *
   * @param aMode the JSONiq version
   * @return true if the version was set, false otherwise.
   */
  virtual bool
  setJSONiqVersion( jsoniq_version_t aMode ) = 0;

  /** \brief Get the XQuery processing mode (version 1.0 or 3.0).
   *
   *
   * @return xquery_version_t the XQuery version processing mode.
   */
  virtual xquery_version_t
  getXQueryVersion( ) const = 0;

  /** \brief Get the JSONiq processing mode.
   *
   *
   * @return jsoniq_version_t the JSONiq version processing mode.
   */
  virtual jsoniq_version_t
  getJSONiqVersion( ) const = 0;

  /** \brief Set the XPath 1.0 compatibility mode.
   *         (see http://www.w3.org/TR/xquery/#static_context)
   *
   * @param aMode the XPath 1.0 compatibility mode.
   * @return true if the mode was set, false otherwise.
   */
  virtual bool
  setXPath1_0CompatibMode( xpath1_0compatib_mode_t aMode ) = 0;

  /** \brief Get the XPath 1.0 compatibility mode.
   *         (see http://www.w3.org/TR/xquery/#static_context)
   *
   * @return xpath1_0compatib_mode_t the XPath 1.0 compatibility mode.
   */
  virtual xpath1_0compatib_mode_t
  getXPath1_0CompatibMode( ) const = 0;

  /** \brief Set the construction mode.
   *         (see http://www.w3.org/TR/xquery/#static_context)
   *
   * @param aMode the construction mode.
   * @return true if the mode was set, false otherwise.
   */
  virtual bool
  setConstructionMode( construction_mode_t aMode ) = 0;

  /** \brief Get the construction mode.
   *         (see http://www.w3.org/TR/xquery/#static_context)
   *
   * @return construction_mode_t the construction mode.
   */
  virtual construction_mode_t
  getConstructionMode( ) const = 0;

  /** \brief Set the ordering mode.
   *         (see http://www.w3.org/TR/xquery/#static_context)
   *
   * @param aMode the ordering mode.
   * @return true if the mode was set, false otherwise.
   */
  virtual bool
  setOrderingMode( ordering_mode_t aMode ) = 0;

  /** \brief Get the ordering mode.
   *         (see http://www.w3.org/TR/xquery/#static_context)
   *
   * @return ordering_mode_t the ordering mode.
   */
  virtual ordering_mode_t
  getOrderingMode( ) const = 0;

  /** \brief Set the default order for the empty sequence.
   *         (see http://www.w3.org/TR/xquery/#static_context)
   *
   * @param aMode the default order for the empty sequence.
   * @return true if the mode was set, false otherwise.
   */
  virtual bool
  setDefaultOrderForEmptySequences( order_empty_mode_t aMode ) = 0;

  /** \brief Get the default order for the empty sequence.
   *         (see http://www.w3.org/TR/xquery/#static_context)
   *
   * @return order_empty_mode_t the ordering mode.
   */
  virtual order_empty_mode_t
  getDefaultOrderForEmptySequences( ) const = 0;

  /** \brief Set the boundary space policy.
   *         (see http://www.w3.org/TR/xquery/#static_context)
   *
   * @param aMode the boundary space policy.
   * @return true if the mode was set, false otherwise.
   */
  virtual bool
  setBoundarySpacePolicy( boundary_space_mode_t aMode) = 0;

  /** \brief Get the boundary space policy.
   *         (see http://www.w3.org/TR/xquery/#static_context)
   *
   * @return boundary_space_mode_t the boundary space policy.
   */
  virtual boundary_space_mode_t
  getBoundarySpacePolicy( ) const = 0;

  /** \brief Set the copy namespace mode.
   *         (see http://www.w3.org/TR/xquery/#static_context)
   *
   * @param aPreserve the preserve mode.
   * @param aInherit the inherit mode.
   * @return true if the mode was set, false otherwise.
   */
  virtual bool
  setCopyNamespacesMode( preserve_mode_t aPreserve,
                         inherit_mode_t aInherit ) = 0;

  /** \brief Get the copy namespace mode.
   *         (see http://www.w3.org/TR/xquery/#static_context)
   *
   * @return aPreserve the preserve mode.
   * @return aInherit the inherit mode.
   */
  virtual void
  getCopyNamespacesMode( preserve_mode_t& aPreserve,
                         inherit_mode_t& aInherit ) const = 0;

  /** \brief Set the base URI.
   *         (see http://www.w3.org/TR/xquery/#static_context)
   *
   * @param aBaseURI the base URI as String.
   * @return true if the base URI has been set, false otherwise.
   */
  virtual bool
  setBaseURI( const String& aBaseURI ) = 0;

  /** \brief Get the base URI.
   *
   * @return String the base URI.
   */
  virtual String
  getBaseURI( ) const = 0;

  /** \brief Get the revalidation mode.
   *
   * @return the revalidation mode.
   */
  virtual validation_mode_t
  getRevalidationMode() const = 0;

  /** \brief Set the revalidation mode.
   *
   * @param aMode the revalidation mode.
   */
  virtual void
  setRevalidationMode(validation_mode_t aMode) = 0;
  
  /** \brief Register a module providing access to external functions.
   *
   * Register a module that provides access to external functions.
   * The caller keeps the ownership of the Module and the StatelessExternalFunction
   * objects passed to this function.
   *
   * @param aModule the module object
   * @return true if the module has been set, false otherwise.
   */
  virtual bool
  registerModule(ExternalModule* aModule) = 0;

  /**
   * \brief Register a URI Mapper which will transform a given URI
   * into several alternate potential URIs.
   *
   * QQQ doc
   */
  virtual void
  registerURIMapper(URIMapper* aMapper) = 0;

  /**
   * \brief Register a URL Resolver which will transform a given
   * URL into a Resource.
   *
   * QQQ doc
   */
  virtual void
  registerURLResolver(URLResolver* aResolver) = 0;

  /** \brief Set the type of a statically known document
   */
  virtual void
  setDocumentType(const String& aDocUri, const SequenceType& type) = 0;
  
  /** \brief Get the type of a statically known document
   */
  virtual SequenceType
  getDocumentType(const String& aDocUri) const = 0;
  
  /** \brief Set the type of a statically known collection
   */
  virtual void
  setCollectionType(const String& aCollectionUri, const SequenceType& type) = 0;

  /** \brief Get the type of a statically known collection
   */
  virtual SequenceType
  getCollectionType(const String& aCollectionUri) const = 0;

  /** \brief Check if a function with the given name and arity are registered in the context.
   */
  virtual bool
  containsFunction(const String& aFnNameUri, const String& aFnNameLocal, int arity) const = 0;

  virtual void
  findFunctions(const Item& aQName, std::vector<Function_t>& aFunctions) const = 0;
  
  virtual void
  disableFunction(const Function_t& aFunction) = 0;

  virtual void
  disableFunction(const Item& aQName, int arity) = 0;

  virtual void
  getFunctionAnnotations(const Item& aQName, int arity, std::vector<Annotation_t>& aAnnotations) const = 0;

  /** \brief Get all functions declared in the given static context
   *
   * @return aFunctions all of the said functions
   */
  virtual void
  getFunctions(std::vector<Function_t>& aFunctions) const = 0;

  /** \brief Get all functions with a specified namespace and airty\
   *    declared in the given static context.
   *
   * @param aFnNameUri the namespace for the functions to return
   * @param arity the arity for the functions to return
   * @param aFunctions all of the said functions
   */
  virtual void
  getFunctions(
      const String& aFnNameUri,
      uint32_t arity,
      std::vector<Function_t>& aFunctions) const = 0;

  /** \brief Set the type of the context item.
   */
  virtual void
  setContextItemStaticType(const SequenceType& type) = 0;

  /** \brief Fetch the type of the context item.
   */
  virtual SequenceType
  getContextItemStaticType() const = 0;

  /** \brief Set the output stream that is used by the fn:trace function
   *
   * Sets the output stream that is used by the fn:trace function to the given output stream.
   * The default stream is std::cerr.
   *
   */
  virtual void
  setTraceStream(std::ostream&) = 0;

  /** \brief Resets the output stream that is used by the fn:trace function to std::cerr
   */
  virtual void
  resetTraceStream() = 0;

  /** \brief Get an option that was declared using the declare option syntax
   *
   * @param aQName The QName of the option to get.
   * @param aOptionValue The value of the option if found.
   * @return true if the option was found, false otherwise.
   */
  virtual bool
  getOption( const Item& aQName, String& aOptionValue) const = 0;

  /** \brief Declare an option (same as using declare option in XQuery)
   *
   * @param aQName The QName of the option to declare.
   * @param aOptionValue The value of the option to declare.
   */
  virtual void
  declareOption( const Item& aQName, const String& aOptionValue) = 0;

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
  virtual void
  setModulePaths( const std::vector<String>& aModulePaths ) = 0;

  /**
   * @brief Return the union of the URI and library lookup paths (lists of
   * filesystem directories) for this static context. @deprecated Use 
   * StaticContext::getURIPath() and StaticContext::getLibPath().
   * @deprecated Use StaticContext::getURIPath() and StaticContext::getLibPath().
   *
   * Returns any values set by StaticContext::setLibPath() and/or StaticContext::setURIPath()
   * on this static context.
   */
  virtual void
  getModulePaths( std::vector<String>& aModulePaths ) const = 0;

  /**
   * @brief Return the union of the URI and library lookup paths (lists of
   * filesystem directories) for this static context and all its parents.
   * @deprecated Use StaticContext::getFullURIPath() and StaticContext::getFullLibPath().
   */
  virtual void
  getFullModulePaths( std::vector<String>& aFullModulePaths ) const = 0;

  /** \brief Resolves the given URI against the value of the base-uri
   * property from the static context.
   *
   * @param aRelativeUri The relative URI to be resolved.
   */
  virtual String
  resolve(const String& aRelativeUri) const = 0;

  /** \brief Resolves the given relative URI against the absolute base URI.
   *
   * @param aRelativeUri The relative URI to be resolved.
   * @param aBaseUri The absolute URI against which the resolving is performed.
   */
  virtual String
  resolve(const String& aRelativeUri, const String& aBaseUri) const = 0;

  /** \brief Validates this Item.
   *  Note: works only on document and element nodes, otherwise returns false.
   * 
   * @param rootElement the root of the tree beeing validated
   * @param validatedResult the result of the validation
   * @param validationMode Validation mode: default value is validate_strict
   * @return true if validation is correct, false if validation is disabled, throws errors if validation fails
   * @throw ZorbaException if any validation error occured
   */
  virtual bool
  validate(
      const Item& rootElement,
      Item& validatedResult,
      validation_mode_t validationMode = validate_strict) const = 0;

  /** \brief Validates this Item while loading the schema for targetNamespace
   *  Note: works only on document or element nodes, otherwise returns false.
   *
   * @param rootElement the root of the tree beeing validated 
   * @param validatedResult the result of the validation
   * @param targetNamespace the expected namespace of root of the tree beeing validated ???
   * @param validationMode Validation mode: default value is validate_strict
   * @return true if validation is correct, false if validation is disabled, throws errors if validation fails
   * @throw ZorbaException if any validation error occured
   */
  virtual bool 
  validate(
      const Item& rootElement,
      Item& validatedResult, 
      const String& targetNamespace,
      validation_mode_t validationMode = validate_strict) const = 0;
  
  /** \brief Validates stringValue as XML simple content, i.e. the text value of attributes or 
   * text only element content.
   * 
   * @param stringValue the value to be validated
   * @param typeQName
   * @param resultList the result of the validation, a vector of atomic Items
   * @return true if validation is correct, false if validation is disabled, throws errors if validation fails
   * @throw ZorbaException if any validation error occured
   */
  virtual bool 
  validateSimpleContent(
      const String& stringValue,
      const Item& typeQName, 
      std::vector<Item>& resultList) const= 0;

  /** \brief Invokes the XQuery function with the given name and
   *  the given parameters.
   *
   *  Note that the function to be invoked needs to be declared in this static
   *  context. In order to declare a function in the static context, the
   *  loadProlog method of this class can be used.
   *
   *  Also note that if the function to be invoked is an updating function,
   *  its resulting pending update list is implicitly applied by this function.
   *
   * @param aQName the name of the function to be invoked
   * @param aArgs a vector of ItemSequences. One entry in the vector
   *        corresponds to one argument that is passed to the function.
   *
   * @return The result of the function that is invoked. If the function
   *   to be invoked is an updating function, the resulting item sequence
   *   is empty.
   */
  virtual ItemSequence_t
  invoke(const Item& aQName, const std::vector<ItemSequence_t>& aArgs) const = 0;

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
  virtual StaticCollectionManager*
  getStaticCollectionManager() const = 0;
  
  /**
   * @brief sets the audit event that will be populated during execution
   *
   * @param anEvent the audit event
   */
  virtual void
  setAuditEvent(audit::Event* anEvent) = 0;

  /**
   * @brief gets the audit event that is populated during execution
   *
   * @return the audit event
   */
  virtual audit::Event*
  getAuditEvent() const = 0;


  /** \brief Returns the QName of all external variables within the
   *        static context
   *
   * @param aVarsIter iterator to store the results.
   * @throw ZorbaException if an error occured.
   */
  virtual void
  getExternalVariables(Iterator_t& aVarsIter) const = 0;

  /** \brief Gets the Annotations (if any) for the given external variable.
   *
   * @param var_name The QName of the variable.
   * @param result The vector into which to put all of the variable's
   * annotations.
   * @return Returns \c true only if the given external variable exists and has
   * at least one annotation.
   */
  virtual bool
  getExternalVariableAnnotations( Item const &var_name,
                                  std::vector<Annotation_t> &result ) const = 0;

  /** \brief Gets the given external variable Kind
   *
   * @param var_name The QName of the variable.
   * @return Returns \c true only if the given external variable exists.
   */
  virtual bool
  getExternalVariableKind(Item const & var_name,
      SequenceType::Kind& result) const = 0;

  /** \brief Gets the given external variable quantifier.
   *
   * @param var_name The QName of the variable.
   * @return Returns \c true only if the given external variable exists.
   */
  virtual bool
  getExternalVariableQuantifier(Item const & var_name,
      SequenceType::Quantifier& result) const = 0;

  /**
   * @brief Set the URI lookup path (list of filesystem directories) for this
   * static context.
   *
   * Queries which resolve URIs (for instance, importing modules or schemas)
   * will look in these directories.
   */
  virtual void
  setURIPath(const std::vector<String>& aURIPath) = 0;

  /**
   * @brief Return the URI lookup path (list of filesystem directories) for
   * this static context.
   *
   * Returns any values set by StaticContext::setURIPath() on this static context.
   * To return the full URI lookup path for this static context and
   * all its parents (usually most useful), call StaticContext::getFullURIPath().
   */
  virtual void
  getURIPath(std::vector<String>& aURIPath) const = 0;

  /**
   * @brief Return the URI lookup path (list of filesystem directories) for
   * this static context and all its parents.
   */
  virtual void
  getFullURIPath(std::vector<String>& aURIPath) const = 0;

  /**
   * @brief Set the library lookup path (list of filesystem directories) for
   * this static context.
   *
   * Queries which import modules that have external function
   * implementations will look for the implementation of those functions
   * (shared libraries) in these directories.
   */
  virtual void
  setLibPath(const std::vector<String>& aLibPath) = 0;

  /**
   * @brief Return the URI lookup path (list of filesystem directories) for
   * this static context.
   *
   * Returns any values set by StaticContext::setLibPath() on this static context.
   * To return the full library lookup path for this static context and
   * all its parents (usually most useful), call StaticContext::getFullLibPath().
   */
  virtual void
  getLibPath(std::vector<String>& aLibPath) const = 0;

  /**
   * @brief Return the URI lookup path (list of filesystem directories) for
   * this static context and all its parents.
   */
  virtual void
  getFullLibPath(std::vector<String>& aLibPath) const = 0;

  /** \brief Fetches an resource refered to by the given URI.
   *
   * Resolution is done using the URI mappers and resolvers registered
   * in this static context. If no such mappers or resolvers have been
   * registered, the built-in ones are used. 
   *
   * The default EntityKind for resources fetched by this function
   * is "SOME_CONTENT". The default encoding that is used to read the
   * resource is "UTF-8".
   *
   * @param aURI the name of the resource to fetch
   *
   * @return the fetched resource
   */
  virtual Item
  fetch(const String& aURI) const = 0;

  /** \brief Fetches an resource refered to by the given URI.
   *
   * Resolution is done using the URI mappers and resolvers registered
   * in this static context. If no such mappers or resolvers have been
   * registered, the built-in ones are used. 
   *
   * The default encoding that is used to read the * resource is "UTF-8".
   *
   * @param aURI the name of the resource to fetch
   *
   * @param aEntityKind the kind of the entity to fetch (i.e.
   *   SOME_CONTENT, SCHEMA, MODULE, THESAURUS, or STOP_WORDS)
   *
   * @return the fetched resource
   */

  virtual Item
  fetch(const String& aURI, const String& aEntityKind) const = 0;

  /** \brief Fetches an resource refered to by the given URI.
   *
   * Resolution is done using the URI mappers and resolvers registered
   * in this static context. If no such mappers or resolvers have been
   * registered, the built-in ones are used. 
   *
   * @param aURI the name of the resource to fetch
   * @param aEncoding the encoding to use when reading the resource.
   *
   * @param aEntityKind the kind of the entity to fetch (i.e.
   *   SOME_CONTENT, SCHEMA, MODULE, THESAURUS, or STOP_WORDS)
   *
   * @return the fetched resource
   */
  virtual Item
  fetch(
      const String& aURI,
      const String& aEntityKind,
      const String& aEncoding) const = 0;

  /** \brief Fetches an resource refered to by the given URI
   *   and returns it as a base64binary.
   *
   * Resolution is done using the URI mappers and resolvers registered
   * in this static context. If no such mappers or resolvers have been
   * registered, the built-in ones are used. 
   *
   * The default EntityKind for resources fetched by this function
   * is "SOME_CONTENT".
   *
   * @param aURI the name of the resource to fetch
   *
   * @return the fetched resource
   */
  virtual Item
  fetchBinary(const String& aURI) const = 0;

  /** \brief Fetches an resource refered to by the given URI
   *   and returns it as a base64binary.
   *
   * Resolution is done using the URI mappers and resolvers registered
   * in this static context. If no such mappers or resolvers have been
   * registered, the built-in ones are used. 
   *
   * @param aURI the name of the resource to fetch
   *
   * @param aEntityKind the kind of the entity to fetch (i.e.
   *   SOME_CONTENT, SCHEMA, MODULE, THESAURUS, or STOP_WORDS)
   *
   * @return the fetched resource
   */
  virtual Item
  fetchBinary(const String& aURI, const String& aEntityKind) const = 0;

  /** \brief Clears the base URI and sets it to undefined state.
   *         (see http://www.w3.org/TR/xquery/#static_context)
   */
  virtual void
  clearBaseURI() = 0;

  /** \brief Sets a list of default function namespaces that will be
   *   used in order during the lookup of functions.
   *
   * @param aURIs the list of default function namespaces.
   * @return true if the said namespaces have been set, false otherwise
   *         if an DiagnosticHandler has been registered.
   * @throw ZorbaException if an error occured.
   */
  virtual bool
  setDefaultFunctionNamespaces( const std::vector<String>& aURIs ) = 0;
};

} /* namespace zorba */
#endif
/* vim:set et sw=2 ts=2: */
