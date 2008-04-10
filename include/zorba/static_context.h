#ifndef XQP_STATIC_CONTEXT_API_H
#define XQP_STATIC_CONTEXT_API_H

#include <zorba/zorbastring.h>
#include <zorba/typeident.h> 

namespace zorba {

  class StaticContext
  {
    public:
      enum xpath1_0compatib_mode_t { xpath2_0, xpath1_0          };
      enum ordering_mode_t         { ordered, unordered          };
      enum order_empty_mode_t      { empty_greatest, empty_least };
      enum inherit_mode_t          { inherit_ns, no_inherit_ns   };
      enum boundary_space_mode_t   { preserve_space, strip_space };
      enum construction_mode_t     { preserve_cons, strip_cons   };
      enum preserve_mode_t         { preserve_ns, no_preserve_ns };

      virtual ~StaticContext() {}

      virtual StaticContext_t
      createChildContext() const = 0;
      
      virtual bool   
      addNamespace( const String& prefix, const String& URI ) = 0;
      
      virtual String   
      getNamespaceURIByPrefix( const String& prefix ) const = 0;

      virtual void   
      deleteNamespace( const String& prefix ) = 0;

      virtual void   
      setDefaultElementAndTypeNamespace( const String& URI ) = 0;
      
      virtual String   
      getDefaultElementAndTypeNamespace( ) const = 0;

      virtual void   
      setDefaultFunctionNamespace( const String& URI ) = 0;
      
      virtual String   
      getDefaultFunctionNamespace( ) const = 0;

      virtual void   
      addExternalVariableType( const String& var_name, TypeIdentifier_t var_type) = 0;

      virtual TypeIdentifier_t 
      getExternalVariableType( const String& var_name ) = 0;

      virtual void   
      deleteExternalVariableType( const String& var_name ) = 0;

      virtual void   
      setContextItemType( TypeIdentifier_t type ) = 0;

      virtual TypeIdentifier_t   
      getContextItemType( ) const = 0;

      virtual void
      removeCollation( const String& uri ) = 0;

      virtual void   
      addCollation( const String& uri ) = 0;

      virtual void   
      setDefaultCollation( const String& URI ) = 0;

      virtual String 
      getDefaultCollation() const = 0;

      virtual void   
      setXPath1_0CompatibMode( xpath1_0compatib_mode_t mode ) = 0;

      virtual xpath1_0compatib_mode_t  
      getXPath1_0CompatibMode( ) const = 0;

      virtual void   
      setConstructionMode( construction_mode_t ) = 0;

      virtual construction_mode_t  
      getConstructionMode( ) const = 0;

      virtual void   
      setOrderingMode( ordering_mode_t ) = 0;

      virtual ordering_mode_t  
      getOrderingMode( ) const = 0;

      virtual void   
      setDefaultOrderForEmptySequences( order_empty_mode_t ) = 0;

      virtual order_empty_mode_t   
      getDefaultOrderForEmptySequences( ) const = 0;

      virtual void   
      setBoundarySpacePolicy( boundary_space_mode_t ) = 0;

      virtual boundary_space_mode_t  
      getBoundarySpacePolicy( ) const = 0;


      virtual void   
      setCopyNamespacesMode( preserve_mode_t preserve, 
                             inherit_mode_t inherit ) = 0;

      virtual void   
      getCopyNamespacesMode( preserve_mode_t& preserve, 
                              inherit_mode_t& inherit ) const = 0;

      virtual void   
      setBaseURI( const String& baseURI ) = 0;

      virtual String   
      getBaseURI( ) const = 0;


      /**
       * functions that are used for registering external functions
       */
      virtual void 
      registerStatelessExternalFunction(StatelessExternalFunction* aExternalFunction) = 0;


  };

} /* namespace zorba */
#endif
