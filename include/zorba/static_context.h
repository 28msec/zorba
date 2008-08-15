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
#include <zorba/zorbastring.h>
#include <zorba/typeident.h> 
#include <zorba/static_context_consts.h>
#include <zorba/smart_ptr.h>

namespace zorba {

  /** \brief Instances of the class StaticContext containt the information that is available
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
  class ZORBA_EXTERN_DECL StaticContext : public SmartObject
  {
    public:
      /** \brief Destructor
       */
      virtual ~StaticContext() {}

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
       * @return true if the collation was added, false otherwise (e.g. the URI was not
       *         a valid collation URI).
       * @throw ZorbaException if an error occured.
       */
      virtual bool   
      addCollation( const String& aURI ) = 0;

      /** \brief Set the URI of the default collation.
       *         (see http://www.w3.org/TR/xquery/#static_context)
       *
       * @param aURI URI of the default collation.
       * @return true if the default collation URI has been set, false otherwise.
       * @throw ZorbaException if an error occured.
       */
      virtual bool   
      setDefaultCollation( const String& aURI ) = 0;

      /** \brief Get the URI of the default collation
       *
       * @return String the URI of the default collation.
       */
      virtual String 
      getDefaultCollation() const = 0;

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


      /** \brief Register a stateless external function.
       *
       * Register an external function that can be called within a query.
       * The caller keeps the ownership of the StatelessExternalFunction object passed
       * to this function.
       *
       * @param aExternalFunction the stateless external function.
       * @return true if the function has been set, false otherwise.
       */
      virtual bool 
      registerStatelessExternalFunction(StatelessExternalFunction* aExternalFunction) = 0;

      virtual void
      setDocumentURIResolver(DocumentURIResolver* aDocumentURIResolver) = 0;

      virtual DocumentURIResolver*
      getDocumentURIResolver() = 0;

      virtual void
      setCollectionURIResolver(CollectionURIResolver* aCollectionUriResolver) = 0;

      virtual CollectionURIResolver*
      getCollectionURIResolver() = 0;

      virtual void
      setSchemaURIResolver(SchemaURIResolver* aSchemaUriResolver) = 0;

      virtual SchemaURIResolver*
      getSchemaURIResolver() = 0;

      virtual void
      setModuleURIResolver(ModuleURIResolver* aModuleUriResolver) = 0;

      virtual ModuleURIResolver*
      getModuleURIResolver() = 0;
  };

} /* namespace zorba */
#endif
