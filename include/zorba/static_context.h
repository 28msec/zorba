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

#include <zorba/config.h>
#include <zorba/api_shared_types.h>
#include <zorba/zorbastring.h>
#include <zorba/typeident.h>
#include <zorba/static_context_consts.h>
#include <zorba/options.h>  // for compiler hints class
#include <vector>
#include <zorba/function.h>
#include <zorba/annotation.h>
#include <zorba/smart_ptr.h>

namespace zorba {

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
       *         could be found for the given prefix and an ErrorHandler has been
       *         registered.
       * @throw ZorbaException if an error occured (e.g. no URI could be found for the given prefix).
       */
      virtual String
      getNamespaceURIByPrefix( const String& aPrefix ) const = 0;

      /** \brief Set the default element and type namespace
       *         (see http://www.w3.org/TR/xquery/#static_context)
       *
       * @param aURI of the default element and type namespace URI.
       * @return true if the default element and type namespace URI has been set, false otherwise
       *         if an ErrorHandler has been registered.
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
       *         if an ErrorHandler has been registered.
       * @throw ZorbaException if an error occured.
       */
      virtual bool
      setDefaultFunctionNamespace( const String& aURI ) = 0;

      /** \brief Get the default function namespace.
       *
       * @return String the URI of the default function namespace.
       *         ErrorHandler has been registered.
       * @throw ZorbaException if an error occured.
       */
      virtual String
      getDefaultFunctionNamespace( ) const = 0;

      /** \brief Adds a collation URI.
       *
       * The URI specifies the locale and collation strength of the collation that is added.
       * A valid collation URI must begin with http://www.flworfound.org/collations/.
       * This prefix is followed by a collation strength (i.e. PRIMARY, SECONDARY, TERTIARY,
       * QUATTERNARY, or IDENTICAL) followed by a '/'.
       * After the strength a lower-case two- or three-letter ISO-639 language code must follow.
       * The URI may end with an upper-case two-letter ISO-3166.
       * For example, http://www.flworfound.org/collations/PRIMARY/en/US
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

      /** \brief Set the XQuery processing mode (version 1.0 or 1.1).
       *
       *
       * @param aMode the XQuery version.
       * @return true if the version was set, false otherwise.
       */
      virtual bool
      setXQueryVersion( xquery_version_t aMode ) = 0;

      /** \brief Get the XQuery processing mode (version 1.0 or 1.1).
       *
       *
       * @return xquery_version_t the XQuery version processing mode.
       */
      virtual xquery_version_t
      getXQueryVersion( ) const = 0;

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

      virtual void
      setDocumentURIResolver(DocumentURIResolver* aDocumentURIResolver) = 0;

      virtual DocumentURIResolver*
      getDocumentURIResolver() const = 0;

      /** \brief Set the type of a statically known document
       */
      virtual void
      setDocumentType(const String& aDocUri, TypeIdentifier_t type) = 0;

      /** \brief Get the type of a statically known document
       */
      virtual TypeIdentifier_t
      getDocumentType(const String& aDocUri) const = 0;

      virtual void
      setCollectionURIResolver(CollectionURIResolver* aCollectionUriResolver) = 0;

      virtual CollectionURIResolver*
      getCollectionURIResolver() const = 0;

      /** \brief Set the type of a statically known collection
       */
      virtual void
      setCollectionType(const String& aCollectionUri, TypeIdentifier_t type) = 0;

      /** \brief Get the type of a statically known collection
       */
      virtual TypeIdentifier_t
      getCollectionType(const String& aCollectionUri) const = 0;

      virtual void
      addSchemaURIResolver(SchemaURIResolver* aSchemaUriResolver) = 0;

      virtual std::vector<SchemaURIResolver*>
      getSchemaURIResolvers() const = 0;

#ifndef ZORBA_NO_FULL_TEXT
      virtual void
      addFullTextURIResolver(FullTextURIResolver* aFullTextUriResolver) = 0;

      virtual std::vector<FullTextURIResolver*>
      getFullTextURIResolvers() const = 0;
#endif

      virtual void
      addModuleURIResolver(ModuleURIResolver* aModuleUriResolver) = 0;

      virtual std::vector<ModuleURIResolver*>
      getModuleURIResolvers() const = 0;

      virtual void
      removeModuleURIResolver(ModuleURIResolver* aModuleUriResolver) = 0;

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

      /** \brief Set the type of the context item.
       */
      virtual void
      setContextItemStaticType(TypeIdentifier_t type) = 0;

      /** \brief Fetch the type of the context item.
       */
      virtual TypeIdentifier_t
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
       * @return aOptionValue The value of the option if found.
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

      virtual void
      setModulePaths( const std::vector<String>& aModulePaths ) = 0;

      virtual void
      getModulePaths( std::vector<String>& aModulePaths ) const = 0;

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
       * @param aRelativeURI The relative URI to be resolved.
       * @param aBaseUri The absolute URI against which the resolving is performed.
       */
      virtual String
      resolve(const String& aRelativeUri, const String& aBaseUri) const = 0;

      virtual void
      setDeclaredCollectionCallback ( CollectionCallback aCallbackFunction,
                                      void* aCallbackData ) = 0;

      virtual void
      setDeclaredIndexCallback ( IndexCallback aCallbackFunction,
                                 void* aCallbackData ) = 0;

      /**
        * @brief Add a new ModuleImportChecker to this module.
        *
        * Module import checkers are used by zorba to allow users to deny
        * the import of specific modules. This method adds such a module
        * import checker to the current static context.
        *
        * @param aChecker The ModuleImportChecker which should be added to
        *                 the current static context.
        */
      virtual void
      addModuleImportChecker(ModuleImportChecker* aChecker) = 0;

      /**
        * @brief Removes aChecker from the current static contect.
        *
        * Will compare all currently registered module import checkers with
        * aChecker by using the operator== and will remove all found module
        * import checkers.
        *
        * @param aChecker The module import checker to remove.
        */
      virtual void
      removeModuleImportChecker(ModuleImportChecker* aChecker) = 0;
      
      /** \brief Validates this Item.
        *  Note: works only on document and element nodes, otherwise returns false.
        * 
        * @param rootElement the root of the tree beeing validated 
        * @return true if validating is correct, throws errors if validation fails
        * @return validatedResult the result of the validation
        * @throw ZorbaException if any validation error occured
        */
      virtual bool
      validate(const Item& rootElement, Item& validatedResult,
               validation_mode_t validationMode = validate_strict) = 0;

      /** \brief Validates this Item while loading the schema for targetNamespace
        *  Note: works only on document or element nodes, otherwise returns false.
        * 
        * @param rootElement the root of the tree beeing validated 
        * @return validatedResult the result of the validation
        * @param targetNamespace the expected namespace of root of the tree beeing validated ???
        * @return true if validating is correct, throws errors if validation fails
        * @throw ZorbaException if any validation error occured
        */
      virtual bool 
      validate(const Item& rootElement, Item& validatedResult, 
               const String& targetNamespace,
               validation_mode_t validationMode = validate_strict) = 0;
  
      /** \brief Validates stringValue as XML simple content, i.e. the text value of attributes or 
        * text only element content.
        * 
        * @param stringValue the value to be validated
        * @return true if validating is correct, throws errors if validation fails
        * @return resultList the result of the validation, a vector of atomic Items
        * @throw ZorbaException if any validation error occured
        */
      virtual bool 
      validateSimpleContent(const String& stringValue,
          const Item& typeQName, 
          std::vector<Item>& resultList) = 0;

};
} /* namespace zorba */
#endif
