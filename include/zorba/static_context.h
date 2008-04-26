#ifndef XQP_STATIC_CONTEXT_API_H
#define XQP_STATIC_CONTEXT_API_H

#include <zorba/zorbastring.h>
#include <zorba/typeident.h> 

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
   */
  class StaticContext
  {
    public:
      /** \brief XPath 1.0 compatibility mode as defined in 
       *         http://www.w3.org/TR/xquery/#static_context 
       */
      enum xpath1_0compatib_mode_t { xpath2_0, xpath1_0          };

      /** \brief Ordering mode as defined in http://www.w3.org/TR/xquery/#static_context.
       */
      enum ordering_mode_t         { ordered, unordered          };

      /** \brief Default order for empty sequences as defined in 
       *         http://www.w3.org/TR/xquery/#static_context.
       */
      enum order_empty_mode_t      { empty_greatest, empty_least };

      /** \brief Inherit part of the Copy-namespace mode as defined in 
       *         http://www.w3.org/TR/xquery/#static_context.
       */
      enum inherit_mode_t          { inherit_ns, no_inherit_ns   };

      /** \brief Preserve part of the Copy-namespace mode as defined in 
       *         http://www.w3.org/TR/xquery/#static_context.
       */
      enum preserve_mode_t         { preserve_ns, no_preserve_ns };

      /** \brief Boundary-space policy as defined in http://www.w3.org/TR/xquery/#static_context.
       */
      enum boundary_space_mode_t   { preserve_space, strip_space };

      /** \brief Construction mode as defined in http://www.w3.org/TR/xquery/#static_context.
       */
      enum construction_mode_t     { preserve_cons, strip_cons   };

      /** \brief Destructor
       */
      virtual ~StaticContext() {}

      virtual StaticContext_t
      createChildContext() const = 0;
      
      virtual bool   
      addNamespace( const String& prefix, const String& URI ) = 0;
      
      virtual String   
      getNamespaceURIByPrefix( const String& prefix ) const = 0;

      virtual bool   
      deleteNamespace( const String& prefix ) = 0;

      virtual bool   
      setDefaultElementAndTypeNamespace( const String& URI ) = 0;
      
      virtual String   
      getDefaultElementAndTypeNamespace( ) const = 0;

      virtual bool   
      setDefaultFunctionNamespace( const String& URI ) = 0;
      
      virtual String   
      getDefaultFunctionNamespace( ) const = 0;

      virtual bool   
      addExternalVariableType( const String& var_name, TypeIdentifier_t var_type) = 0;

      virtual TypeIdentifier_t 
      getExternalVariableType( const String& var_name ) = 0;

      virtual bool   
      deleteExternalVariableType( const String& var_name ) = 0;

      virtual bool   
      setContextItemType( TypeIdentifier_t type ) = 0;

      virtual TypeIdentifier_t   
      getContextItemType( ) const = 0;

      virtual bool   
      addCollation( const String& uri ) = 0;

      virtual bool   
      setDefaultCollation( const String& URI ) = 0;

      virtual String 
      getDefaultCollation() const = 0;

      virtual bool   
      setXPath1_0CompatibMode( xpath1_0compatib_mode_t mode ) = 0;

      virtual xpath1_0compatib_mode_t  
      getXPath1_0CompatibMode( ) const = 0;

      virtual bool   
      setConstructionMode( construction_mode_t ) = 0;

      virtual construction_mode_t  
      getConstructionMode( ) const = 0;

      virtual bool   
      setOrderingMode( ordering_mode_t ) = 0;

      virtual ordering_mode_t  
      getOrderingMode( ) const = 0;

      virtual bool   
      setDefaultOrderForEmptySequences( order_empty_mode_t ) = 0;

      virtual order_empty_mode_t   
      getDefaultOrderForEmptySequences( ) const = 0;

      virtual bool   
      setBoundarySpacePolicy( boundary_space_mode_t ) = 0;

      virtual boundary_space_mode_t  
      getBoundarySpacePolicy( ) const = 0;


      virtual bool   
      setCopyNamespacesMode( preserve_mode_t preserve, 
                             inherit_mode_t inherit ) = 0;

      virtual bool   
      getCopyNamespacesMode( preserve_mode_t& preserve, 
                              inherit_mode_t& inherit ) const = 0;

      virtual bool   
      setBaseURI( const String& baseURI ) = 0;

      virtual String   
      getBaseURI( ) const = 0;


      /**
       * functions that are used for registering external functions
       */
      virtual bool 
      registerStatelessExternalFunction(StatelessExternalFunction* aExternalFunction) = 0;


  };

} /* namespace zorba */
#endif
