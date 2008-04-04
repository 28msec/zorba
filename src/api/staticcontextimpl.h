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

      virtual void   
      deleteNamespace( const String& prefix );

      virtual void   
      setDefaultElementAndTypeNamespace( const String& URI );
      
      virtual String   
      getDefaultElementAndTypeNamespace( ) const;

      virtual void   
      setDefaultFunctionNamespace( const String& URI );
      
      virtual String   
      getDefaultFunctionNamespace( ) const;

      virtual void   
      addExternalVariableType( const String& var_name, TypeIdentifier_t var_type);

      virtual TypeIdentifier_t 
      getExternalVariableType( const String& var_name );

      virtual void   
      deleteExternalVariableType( const String& var_name );

      virtual void   
      setContextItemType( TypeIdentifier_t type );

      virtual TypeIdentifier_t   
      getContextItemType( ) const;

      virtual void
      removeCollation( const String& URI );

      virtual void   
      addCollation( const String& URI );

      virtual void   
      setDefaultCollation( const String& URI );

      virtual String 
      getDefaultCollation() const;

      virtual void   
      setXPath1_0CompatibMode( StaticContext::xpath1_0compatib_mode_t mode );

      virtual StaticContext::xpath1_0compatib_mode_t  
      getXPath1_0CompatibMode( ) const;

      virtual void   
      setConstructionMode( StaticContext::construction_mode_t );

      virtual StaticContext::construction_mode_t  
      getConstructionMode( ) const;

      virtual void   
      setOrderingMode( StaticContext::ordering_mode_t );

      virtual StaticContext::ordering_mode_t  
      getOrderingMode( ) const;

      virtual void   
      setDefaultOrderForEmptySequences( StaticContext::order_empty_mode_t );

      virtual StaticContext::order_empty_mode_t   
      getDefaultOrderForEmptySequences( ) const;

      virtual void   
      setBoundarySpacePolicy( StaticContext::boundary_space_mode_t );

      virtual StaticContext::boundary_space_mode_t  
      getBoundarySpacePolicy( ) const;


      virtual void   
      setCopyNamespacesMode( StaticContext::preserve_mode_t preserve, 
                             StaticContext::inherit_mode_t inherit );

      virtual void   
      getCopyNamespacesMode( StaticContext::preserve_mode_t& preserve, 
                             StaticContext::inherit_mode_t& inherit ) const;

      virtual bool   
      setBaseURI( const String& baseURI );

      virtual String   
      getBaseURI( ) const;

      virtual void 
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
