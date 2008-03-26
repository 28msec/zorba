#include "api/staticcontextimpl.h"

#include <zorba/error.h>
#include <zorba/stateless_function.h>
#include <zorba/default_error_handler.h>

#include "api/unmarshaller.h"
#include "context/static_context.h"
#include "system/globalenv.h"
#include <zorba/typeident.h>

namespace zorba {

  StaticContextImpl::StaticContextImpl(ErrorHandler* aErrorHandler)
    : theCtx(0),
      theUserStaticContext(false),
      theErrorHandler(aErrorHandler),
      theUserErrorHandler(true)
  {
    theCtx = GENV.getRootStaticContext().create_child_context();
    if ( ! theErrorHandler ) {
      theErrorHandler = new DefaultErrorHandler();
      theUserErrorHandler = false;
    }
  }

  StaticContextImpl::StaticContextImpl(static_context* aCtx, ErrorHandler* aErrorHandler)
    : theCtx(aCtx),
      theErrorHandler(aErrorHandler),
      theUserErrorHandler(true)
  {
    if ( ! theErrorHandler ) {
      theErrorHandler = new DefaultErrorHandler();
      theUserErrorHandler = false;
    }
  }


  StaticContextImpl::StaticContextImpl(const StaticContextImpl& aStaticContext)
    : StaticContext(),
      theCtx(0), 
      theUserStaticContext(false), // we are responsible to delete it
      theErrorHandler(aStaticContext.theErrorHandler),
      theUserErrorHandler(aStaticContext.theUserErrorHandler)
  {
    // hierarchy of contexts
    theCtx = aStaticContext.theCtx->create_child_context();
  }

  StaticContextImpl::~StaticContextImpl()
  {
    if ( ! theUserStaticContext )
      delete theCtx;

    if ( ! theUserErrorHandler )
      delete theErrorHandler;
  }

  StaticContext_t
  StaticContextImpl::createChildContext()
  {
    // TODO, do we need a parent pointer
    StaticContext_t lContext(new StaticContextImpl(*this));
    return lContext;
  }

  
  bool   
  StaticContextImpl::addNamespace( const String& prefix, const String& URI )
  {
    assert(false);
    return false;
  }

  
  String   
  StaticContextImpl::getNamespaceURIByPrefix( const String& prefix ) const
  {
    assert(false);
    return "";
  }


  void   
  StaticContextImpl::deleteNamespace( const String& prefix )
  {
    assert(false);
  }


  void   
  StaticContextImpl::setDefaultElementAndTypeNamespace( const String& URI )
  {
    assert(false);
  }

  
  String   
  StaticContextImpl::getDefaultElementAndTypeNamespace( ) const
  {
    assert(false);
    return "";
  }


  void   
  StaticContextImpl::setDefaultFunctionNamespace( const String& URI )
  {
    assert(false);
  }

  
  String   
  StaticContextImpl::getDefaultFunctionNamespace( ) const
  {
    assert(false);
    return "";
  }


  void   
  StaticContextImpl::addExternalVariableType( const String& var_name, TypeIdentifier_t var_type)
  {
    assert(false);
  }


  TypeIdentifier_t 
  StaticContextImpl::getExternalVariableType( const String& var_name )
  {
    assert(false);
    return TypeIdentifier::createAnyNodeType();
  }


  void   
  StaticContextImpl::deleteExternalVariableType( const String& var_name )
  {
    assert(false);
  }


  void   
  StaticContextImpl::setContextItemType( TypeIdentifier_t type )
  {
    assert(false);
  }


  TypeIdentifier_t   
  StaticContextImpl::getContextItemType( ) const
  {
    assert(false);
    return TypeIdentifier::createAnyNodeType();
  }


  void   
  StaticContextImpl::addCollation( const String& URI, const String& name )
  {
    xqpString lURI = xqpString(Unmarshaller::getInternalString(URI));
    xqpString lName = xqpString(Unmarshaller::getInternalString(name));
    theCtx->add_collation(lURI, lName);
  }


  void   
  StaticContextImpl::setDefaultCollation( const String& URI )
  {
    xqpString lURI = xqpString(Unmarshaller::getInternalString(URI));
    theCtx->set_default_collation_uri(lURI); 
  }


  String 
  StaticContextImpl::getDefaultCollation() const
  {
    return &*theCtx->default_collation_uri().theStrStore;
  }


  void   
  StaticContextImpl::setXPath1_0CompatibMode( StaticContext::xpath1_0compatib_mode_t mode )
  {
    if ( mode == StaticContext::xpath1_0)
      theCtx->set_xpath1_0compatib_mode(StaticContextConsts::xpath1_0_only);
    else
      theCtx->set_xpath1_0compatib_mode(StaticContextConsts::xpath2_0);
  }


  StaticContext::xpath1_0compatib_mode_t  
  StaticContextImpl::getXPath1_0CompatibMode( ) const
  {
    return theCtx->xpath1_0compatib_mode()==StaticContextConsts::xpath1_0_only?
          StaticContext::xpath1_0:StaticContext::xpath2_0;
  }


  void   
  StaticContextImpl::setConstructionMode( StaticContext::construction_mode_t mode )
  {
    if ( mode == StaticContext::preserve_cons)
      theCtx->set_construction_mode(StaticContextConsts::cons_preserve);
    else
      theCtx->set_construction_mode(StaticContextConsts::cons_strip);
  }


  StaticContext::construction_mode_t  
  StaticContextImpl::getConstructionMode( ) const
  {
    return theCtx->construction_mode()==StaticContextConsts::cons_preserve?
          StaticContext::preserve_cons:StaticContext::strip_cons;
  }


  void   
  StaticContextImpl::setOrderingMode( StaticContext::ordering_mode_t mode )
  {
    if ( mode == StaticContext::ordered)
      theCtx->set_ordering_mode(StaticContextConsts::ordered);
    else
      theCtx->set_ordering_mode(StaticContextConsts::unordered);
  }


  StaticContext::ordering_mode_t  
  StaticContextImpl::getOrderingMode( ) const
  {
    return theCtx->ordering_mode()==StaticContextConsts::ordered?
          StaticContext::ordered:StaticContext::unordered;
  }


  void   
  StaticContextImpl::setDefaultOrderForEmptySequences( StaticContext::order_empty_mode_t mode )
  {
    if ( mode == StaticContext::empty_greatest)
      theCtx->set_order_empty_mode(StaticContextConsts::empty_greatest);
    else
      theCtx->set_order_empty_mode(StaticContextConsts::empty_least);
  }


  StaticContext::order_empty_mode_t   
  StaticContextImpl::getDefaultOrderForEmptySequences( ) const
  {
    return theCtx->order_empty_mode()==StaticContextConsts::empty_greatest?
          StaticContext::empty_greatest:StaticContext::empty_least;
  }


  void   
  StaticContextImpl::setBoundarySpacePolicy( StaticContext::boundary_space_mode_t mode )
  {
    if ( mode == StaticContext::preserve_space)
      theCtx->set_boundary_space_mode(StaticContextConsts::preserve_space);
    else
      theCtx->set_boundary_space_mode(StaticContextConsts::strip_space);
  }


  StaticContext::boundary_space_mode_t  
  StaticContextImpl::getBoundarySpacePolicy( ) const
  {
    return theCtx->boundary_space_mode()==StaticContextConsts::preserve_space?
          StaticContext::preserve_space:StaticContext::strip_space;
  }


  void   
  StaticContextImpl::setCopyNamespacesMode( StaticContext::preserve_mode_t preserve, 
                                            StaticContext::inherit_mode_t inherit )
  {
    if ( preserve == StaticContext::preserve_ns )
      theCtx->set_preserve_mode(StaticContextConsts::preserve_ns);
    else
      theCtx->set_preserve_mode(StaticContextConsts::no_preserve_ns);

    if ( inherit == StaticContext::inherit_ns )
      theCtx->set_inherit_mode(StaticContextConsts::inherit_ns);
    else
      theCtx->set_inherit_mode(StaticContextConsts::no_inherit_ns);
  }


  void   
  StaticContextImpl::getCopyNamespacesMode( StaticContext::preserve_mode_t& preserve, 
                                            StaticContext::inherit_mode_t& inherit ) const
  {
    preserve = theCtx->preserve_mode()==StaticContextConsts::preserve_ns?
                    StaticContext::preserve_ns:StaticContext::no_preserve_ns;
    inherit = theCtx->inherit_mode()==StaticContextConsts::inherit_ns?
                    StaticContext::inherit_ns:StaticContext::no_inherit_ns;
  }


  bool   
  StaticContextImpl::setBaseURI( const String& baseURI )
  {
    assert(false);
    return false;
  }


  String   
  StaticContextImpl::getBaseURI( ) const
  {
    assert(false);
    return "";
  }


  void 
  StaticContextImpl::registerStatelessExternalFunction(StatelessExternalFunction* aExternalFunction)
  {
    if ( ! theCtx->bind_stateless_external_function(aExternalFunction) ) {
      // TODO currently, we do not have an error manager here, because
      // an error manager is always "A function with uri " +aExternalFunction->getURI() +" and name " 
      xqpString lLocalName = Unmarshaller::getInternalString(aExternalFunction->getLocalName());
      xqpString lMsg = lLocalName +" is already registered";
      // TODO use error handler here
      throw StaticException(ZorbaError::API0019_FUNCTION_ALREADY_REGISTERED, String(lMsg.theStrStore));
    }
  }


} /* namespace zorba */
