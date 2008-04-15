#ifndef XQP_STATIC_CONTEXT_IMPL_H
#define XQP_STATIC_CONTEXT_IMPL_H

#include <zorba/typeident.h> 
#include <zorba/static_context.h>
#include <zorba/api_shared_types.h>

#include "common/shared_types.h"


namespace zorba {

  class ErrorHandler;
  class static_context;

  class StaticContextImpl : public StaticContext
  {
    private:
      StaticContextImpl(const StaticContextImpl&);

    public:
      StaticContextImpl(ErrorHandler*);
      StaticContextImpl(static_context*, ErrorHandler*);

      virtual ~StaticContextImpl();

      virtual StaticContext_t
      createChildContext() const;
      
      virtual bool   
      addNamespace( const String& prefix, const String& URI );
      
      virtual String   
      getNamespaceURIByPrefix( const String& prefix ) const;

      virtual bool   
      deleteNamespace( const String& prefix );

      virtual bool   
      setDefaultElementAndTypeNamespace( const String& URI );
      
      virtual String   
      getDefaultElementAndTypeNamespace( ) const;

      virtual bool   
      setDefaultFunctionNamespace( const String& URI );
      
      virtual String   
      getDefaultFunctionNamespace( ) const;

      virtual bool   
      addExternalVariableType( const String& var_name, TypeIdentifier_t var_type);

      virtual TypeIdentifier_t 
      getExternalVariableType( const String& var_name );

      virtual bool   
      deleteExternalVariableType( const String& var_name );

      virtual bool   
      setContextItemType( TypeIdentifier_t type );

      virtual TypeIdentifier_t   
      getContextItemType( ) const;

      virtual bool   
      addCollation( const String& URI );

      virtual bool   
      setDefaultCollation( const String& URI );

      virtual String 
      getDefaultCollation() const;

      virtual bool   
      setXPath1_0CompatibMode( StaticContext::xpath1_0compatib_mode_t mode );

      virtual StaticContext::xpath1_0compatib_mode_t  
      getXPath1_0CompatibMode( ) const;

      virtual bool   
      setConstructionMode( StaticContext::construction_mode_t );

      virtual StaticContext::construction_mode_t  
      getConstructionMode( ) const;

      virtual bool   
      setOrderingMode( StaticContext::ordering_mode_t );

      virtual StaticContext::ordering_mode_t  
      getOrderingMode( ) const;

      virtual bool   
      setDefaultOrderForEmptySequences( StaticContext::order_empty_mode_t );

      virtual StaticContext::order_empty_mode_t   
      getDefaultOrderForEmptySequences( ) const;

      virtual bool   
      setBoundarySpacePolicy( StaticContext::boundary_space_mode_t );

      virtual StaticContext::boundary_space_mode_t  
      getBoundarySpacePolicy( ) const;


      virtual bool   
      setCopyNamespacesMode( StaticContext::preserve_mode_t preserve, 
                             StaticContext::inherit_mode_t inherit );

      virtual bool   
      getCopyNamespacesMode( StaticContext::preserve_mode_t& preserve, 
                             StaticContext::inherit_mode_t& inherit ) const;

      virtual bool
      setBaseURI( const String& baseURI );

      virtual String   
      getBaseURI( ) const;

      virtual bool 
      registerStatelessExternalFunction(StatelessExternalFunction* aExternalFunction);

      friend class Unmarshaller; // needs to get the context out of this class
    protected:
      static_context*  theCtx;
      bool             theUserStaticContext;

      ErrorHandler*    theErrorHandler;
      bool             theUserErrorHandler;

  };

} /* namespace zorba */
#endif
