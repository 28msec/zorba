#include "api/staticcontextimpl.h"

#include <zorba/error.h>
#include <zorba/stateless_function.h>
#include <zorba/default_error_handler.h>

#include "zorbatypes/xqpstring.h"
#include "api/unmarshaller.h"
#include "context/static_context.h"
#include "system/globalenv.h"
#include <zorba/typeident.h>
#include "errors/error_manager.h"
#include "api/zorbaimpl.h"
#include "types/casting.h"

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
      theUserStaticContext(true),
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
  StaticContextImpl::createChildContext() const
  {
    try {
      StaticContext_t lContext(new StaticContextImpl(*this));
      return lContext;
    } catch (error::ZorbaError& e) {
      ZorbaImpl::notifyError(theErrorHandler, e);
    } catch (std::exception& e) {
      ZorbaImpl::notifyError(theErrorHandler, e.what());
    }
    return StaticContext_t();
  }

  
  bool   
  StaticContextImpl::addNamespace( const String& aPrefix, const String& aURI )
  {
    ZORBA_TRY
      xqpString lPrefix = Unmarshaller::getInternalString(aPrefix);
      xqpString lURI = Unmarshaller::getInternalString(aURI);
      theCtx->bind_ns(lPrefix, lURI);
      return true;
    ZORBA_CATCH
    return false;
  }

  
  String   
  StaticContextImpl::getNamespaceURIByPrefix( const String& aPrefix ) const
  {
    try {
      xqpString lPrefix = Unmarshaller::getInternalString(aPrefix);
      return &*theCtx->lookup_ns(lPrefix).theStrStore;
    } catch (error::ZorbaError& e) {
      ZorbaImpl::notifyError(theErrorHandler, e);
    } catch (std::exception& e) {
      ZorbaImpl::notifyError(theErrorHandler, e.what());
    }
    return "";
  }


  bool   
  StaticContextImpl::deleteNamespace( const String& prefix )
  {
    assert(false);
  }


  bool   
  StaticContextImpl::setDefaultElementAndTypeNamespace( const String& aURI )
  {
    ZORBA_TRY
      xqpString lURI = Unmarshaller::getInternalString(aURI);
      theCtx->set_default_elem_type_ns(lURI);
      return true;
    ZORBA_CATCH
    return false;
  }

  
  String   
  StaticContextImpl::getDefaultElementAndTypeNamespace( ) const
  {
    try {
      return &*theCtx->default_elem_type_ns().theStrStore;
    } catch (error::ZorbaError& e) {
      ZorbaImpl::notifyError(theErrorHandler, e);
    } catch (std::exception& e) {
      ZorbaImpl::notifyError(theErrorHandler, e.what());
    }
    return "";
  }


  bool   
  StaticContextImpl::setDefaultFunctionNamespace( const String& aURI )
  {
    ZORBA_TRY
      xqpString lURI = Unmarshaller::getInternalString(aURI);
      theCtx->set_default_function_namespace(lURI);
      return true;
    ZORBA_CATCH
    return false;
  }

  
  String   
  StaticContextImpl::getDefaultFunctionNamespace( ) const
  {
    try {
      return &*theCtx->default_function_namespace().theStrStore;
    } catch (error::ZorbaError& e) {
      ZorbaImpl::notifyError(theErrorHandler, e);
    } catch (std::exception& e) {
      ZorbaImpl::notifyError(theErrorHandler, e.what());
    }
    return "";
  }


  bool   
  StaticContextImpl::addExternalVariableType( const String& var_name, TypeIdentifier_t var_type)
  {
    ZORBA_TRY
      assert(false);
    ZORBA_CATCH;
    return true;
  }


  TypeIdentifier_t 
  StaticContextImpl::getExternalVariableType( const String& var_name )
  {
    try { 
      assert(false);
    } catch (error::ZorbaError& e) {
      ZorbaImpl::notifyError(theErrorHandler, e);
    } catch (std::exception& e) {
      ZorbaImpl::notifyError(theErrorHandler, e.what());
    }
    return TypeIdentifier::createAnyNodeType();
  }


  bool   
  StaticContextImpl::deleteExternalVariableType( const String& var_name )
  {
    assert(false);
  }


  bool   
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

  bool   
  StaticContextImpl::addCollation( const String& URI )
  {
    ZORBA_TRY
      xqpString lURI = xqpString(Unmarshaller::getInternalString(URI));
      theCtx->add_collation(lURI);
      return true;
    ZORBA_CATCH
    return false;
  }


  bool   
  StaticContextImpl::setDefaultCollation( const String& URI )
  {
    ZORBA_TRY
      xqpString lURI = xqpString(Unmarshaller::getInternalString(URI));
      theCtx->set_default_collation_uri(lURI); 
      return true;
    ZORBA_CATCH
    return false;
  }


  String 
  StaticContextImpl::getDefaultCollation() const
  {
    try {
      return &*theCtx->default_collation_uri().theStrStore;
    } catch (error::ZorbaError& e) {
      ZorbaImpl::notifyError(theErrorHandler, e);
    } catch (std::exception& e) {
      ZorbaImpl::notifyError(theErrorHandler, e.what());
    }
    return "";
  }


  bool   
  StaticContextImpl::setXPath1_0CompatibMode( StaticContext::xpath1_0compatib_mode_t mode )
  {
    ZORBA_TRY
      if ( mode == StaticContext::xpath1_0)
        theCtx->set_xpath1_0compatib_mode(StaticContextConsts::xpath1_0_only);
      else
        theCtx->set_xpath1_0compatib_mode(StaticContextConsts::xpath2_0);
      return true;
    ZORBA_CATCH
    return false;
  }


  StaticContext::xpath1_0compatib_mode_t  
  StaticContextImpl::getXPath1_0CompatibMode( ) const
  {
    try {
      return theCtx->xpath1_0compatib_mode()==StaticContextConsts::xpath1_0_only?
            StaticContext::xpath1_0:StaticContext::xpath2_0;
    } catch (error::ZorbaError& e) {
      ZorbaImpl::notifyError(theErrorHandler, e);
    } catch (std::exception& e) {
      ZorbaImpl::notifyError(theErrorHandler, e.what());
    }
    return StaticContext::xpath2_0;
  }


  bool   
  StaticContextImpl::setConstructionMode( StaticContext::construction_mode_t mode )
  {
    ZORBA_TRY
      if ( mode == StaticContext::preserve_cons)
        theCtx->set_construction_mode(StaticContextConsts::cons_preserve);
      else
        theCtx->set_construction_mode(StaticContextConsts::cons_strip);
      return true;
    ZORBA_CATCH
    return false;
  }


  StaticContext::construction_mode_t  
  StaticContextImpl::getConstructionMode( ) const
  {
    try {
      return theCtx->construction_mode()==StaticContextConsts::cons_preserve?
             StaticContext::preserve_cons:StaticContext::strip_cons;
    } catch (error::ZorbaError& e) {
      ZorbaImpl::notifyError(theErrorHandler, e);
    } catch (std::exception& e) {
      ZorbaImpl::notifyError(theErrorHandler, e.what());
    }
    return StaticContext::preserve_cons;
  }


  bool   
  StaticContextImpl::setOrderingMode( StaticContext::ordering_mode_t mode )
  {
    ZORBA_TRY
      if ( mode == StaticContext::ordered)
        theCtx->set_ordering_mode(StaticContextConsts::ordered);
      else
        theCtx->set_ordering_mode(StaticContextConsts::unordered);
      return true;
    ZORBA_CATCH
    return false;
  }


  StaticContext::ordering_mode_t  
  StaticContextImpl::getOrderingMode( ) const
  {
    try {
      return theCtx->ordering_mode()==StaticContextConsts::ordered?
            StaticContext::ordered:StaticContext::unordered;
    } catch (error::ZorbaError& e) {
      ZorbaImpl::notifyError(theErrorHandler, e);
    } catch (std::exception& e) {
      ZorbaImpl::notifyError(theErrorHandler, e.what());
    }
    return StaticContext::ordered;
  }


  bool   
  StaticContextImpl::setDefaultOrderForEmptySequences( StaticContext::order_empty_mode_t mode )
  {
    ZORBA_TRY
      if ( mode == StaticContext::empty_greatest)
        theCtx->set_order_empty_mode(StaticContextConsts::empty_greatest);
      else
        theCtx->set_order_empty_mode(StaticContextConsts::empty_least);
        return true;
    ZORBA_CATCH
    return false;
  }


  StaticContext::order_empty_mode_t   
  StaticContextImpl::getDefaultOrderForEmptySequences( ) const
  {
    try {
      return theCtx->order_empty_mode()==StaticContextConsts::empty_greatest?
            StaticContext::empty_greatest:StaticContext::empty_least;
    } catch (error::ZorbaError& e) {
      ZorbaImpl::notifyError(theErrorHandler, e);
    } catch (std::exception& e) {
      ZorbaImpl::notifyError(theErrorHandler, e.what());
    }
    return StaticContext::empty_greatest;
  }


  bool   
  StaticContextImpl::setBoundarySpacePolicy( StaticContext::boundary_space_mode_t mode )
  {
    ZORBA_TRY
      if ( mode == StaticContext::preserve_space)
        theCtx->set_boundary_space_mode(StaticContextConsts::preserve_space);
      else
        theCtx->set_boundary_space_mode(StaticContextConsts::strip_space);
      return true;
    ZORBA_CATCH
    return false;
  }


  StaticContext::boundary_space_mode_t  
  StaticContextImpl::getBoundarySpacePolicy( ) const
  {
    try {
      return theCtx->boundary_space_mode()==StaticContextConsts::preserve_space?
            StaticContext::preserve_space:StaticContext::strip_space;
    } catch (error::ZorbaError& e) {
      ZorbaImpl::notifyError(theErrorHandler, e);
    } catch (std::exception& e) {
      ZorbaImpl::notifyError(theErrorHandler, e.what());
    }
    return StaticContext::preserve_space;
  }


  bool   
  StaticContextImpl::setCopyNamespacesMode( StaticContext::preserve_mode_t preserve, 
                                            StaticContext::inherit_mode_t inherit )
  {
    ZORBA_TRY
      if ( preserve == StaticContext::preserve_ns )
        theCtx->set_preserve_mode(StaticContextConsts::preserve_ns);
      else
        theCtx->set_preserve_mode(StaticContextConsts::no_preserve_ns);

      if ( inherit == StaticContext::inherit_ns )
        theCtx->set_inherit_mode(StaticContextConsts::inherit_ns);
      else
        theCtx->set_inherit_mode(StaticContextConsts::no_inherit_ns);
      return true;
    ZORBA_CATCH
    return false;
  }


  bool   
  StaticContextImpl::getCopyNamespacesMode( StaticContext::preserve_mode_t& preserve, 
                                            StaticContext::inherit_mode_t& inherit ) const
  {
    ZORBA_TRY
      preserve = theCtx->preserve_mode()==StaticContextConsts::preserve_ns?
                      StaticContext::preserve_ns:StaticContext::no_preserve_ns;
      inherit = theCtx->inherit_mode()==StaticContextConsts::inherit_ns?
                      StaticContext::inherit_ns:StaticContext::no_inherit_ns;
      return true;
    ZORBA_CATCH
    return false;
  }


  bool   
  StaticContextImpl::setBaseURI( const String& aBaseURI )
  {
    try {
      xqpString lBaseURI = Unmarshaller::getInternalString(aBaseURI);
 
      if(!GenericCast::instance()->isCastable(lBaseURI, GENV_TYPESYSTEM.ANY_URI_TYPE_ONE)) {
          ZORBA_ERROR_DESC(ZorbaError::XQP0020_INVALID_URI, lBaseURI);
      }
      theCtx->set_baseuri(lBaseURI, false);
    } catch (error::ZorbaError& e) {
      ZorbaImpl::notifyError(theErrorHandler, e);
      return false;
    } catch (std::exception& e) {
      ZorbaImpl::notifyError(theErrorHandler, e.what());
      return false;
    }
    return true;
  }


  String   
  StaticContextImpl::getBaseURI( ) const
  {
    try {
      xqpString lBaseURI = theCtx->baseuri();
      return &*lBaseURI.theStrStore;
    } catch (error::ZorbaError& e) {
      ZorbaImpl::notifyError(theErrorHandler, e);
    } catch (std::exception& e) {
      ZorbaImpl::notifyError(theErrorHandler, e.what());
    }
    return "";
  }


  bool 
  StaticContextImpl::registerStatelessExternalFunction(StatelessExternalFunction* aExternalFunction)
  {
    try {
      if ( ! theCtx->bind_stateless_external_function(aExternalFunction) ) {
        xqpString lLocalName = Unmarshaller::getInternalString(aExternalFunction->getLocalName());
        xqpString lMsg = lLocalName +" is already registered";

        ZORBA_ERROR_DESC(ZorbaError::API0019_FUNCTION_ALREADY_REGISTERED, String(lMsg.theStrStore));
      }
    } catch (error::ZorbaError& e) {
      ZorbaImpl::notifyError(theErrorHandler, e);
      return false;
    }
    return true;
  }


} /* namespace zorba */
