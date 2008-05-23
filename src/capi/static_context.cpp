#include "capi/static_context.h"

#include <cassert>
#include <zorba/zorba.h>
#include "capi/shared_wrapper.h"

using namespace zorba;

#define SC_TRY try {
#define SC_CATCH \
    return XQ_SUCCESS;              \
  } catch (ZorbaException &e) {     \
    return e.getErrorCode();        \
  } catch (...) {                   \
    return XQP0019_INTERNAL_ERROR;  \
  }

namespace zorbac {

  XQUERY_ERROR
  StaticContext::create_child_context(XQC_StaticContext context, XQC_StaticContext_Ref child_context)
  {
    SC_TRY
    SC_CATCH
  }

  XQUERY_ERROR
  StaticContext::add_namespace(XQC_StaticContext context, XQC_String prefix, XQC_String uri)
  {
    SC_TRY
    SC_CATCH
  }

  XQUERY_ERROR
  StaticContext::get_namespace_by_prefix(XQC_StaticContext context, XQC_String prefix, 
                                         XQC_String_Ref result_ns)
  {
    SC_TRY
    SC_CATCH
  }

  XQUERY_ERROR
  StaticContext::set_default_element_and_type_ns(XQC_StaticContext context, XQC_String uri)
  {
    SC_TRY
    SC_CATCH
  }

  XQUERY_ERROR
  StaticContext::get_default_element_and_type_ns(XQC_StaticContext context, XQC_String_Ref uri)
  {
    SC_TRY
    SC_CATCH
  }

  XQUERY_ERROR
  StaticContext::set_default_function_ns(XQC_StaticContext context, XQC_String uri)
  {
    SC_TRY
    SC_CATCH
  }

  XQUERY_ERROR
  StaticContext::get_default_function_ns(XQC_StaticContext context, XQC_String_Ref uri)
  {
    SC_TRY
    SC_CATCH
  }

  XQUERY_ERROR
  StaticContext::add_collation(XQC_StaticContext context, XQC_String uri)
  {
    SC_TRY
    SC_CATCH
  }

  XQUERY_ERROR
  StaticContext::set_default_collation(XQC_StaticContext context, XQC_String uri)
  {
    SC_TRY
    SC_CATCH
  }

  XQUERY_ERROR
  StaticContext::get_default_collation(XQC_StaticContext context, XQC_String_Ref uri)
  {
    SC_TRY
    SC_CATCH
  }

  XQUERY_ERROR
  StaticContext::set_xpath1_0_mode(XQC_StaticContext context, xpath1_0compatib_mode_t mode )
  {
    SC_TRY
    SC_CATCH
  }

  XQUERY_ERROR 
  StaticContext::get_xpath1_0_mode(XQC_StaticContext context, xpath1_0compatib_mode_t* mode)
  {
    SC_TRY
    SC_CATCH
  }

  XQUERY_ERROR
  StaticContext::set_construction_mode(XQC_StaticContext context, construction_mode_t mode )
  {
    SC_TRY
    SC_CATCH
  }

  XQUERY_ERROR
  StaticContext::get_construction_mode(XQC_StaticContext context, construction_mode_t* mode)
  {
    SC_TRY
    SC_CATCH
  }

  XQUERY_ERROR
  StaticContext::set_ordering_mode(XQC_StaticContext context, ordering_mode_t mode )
  {
    SC_TRY
    SC_CATCH
  }

  XQUERY_ERROR
  StaticContext::get_ordering_mode(XQC_StaticContext context, ordering_mode_t* mode )
  {
    SC_TRY
    SC_CATCH
  }

  XQUERY_ERROR
  StaticContext::set_default_order_empty_sequences(XQC_StaticContext context,
                                                   order_empty_mode_t mode )
  {
    SC_TRY
    SC_CATCH
  }

  XQUERY_ERROR
  StaticContext::get_default_order_empty_sequences(XQC_StaticContext context,
                                                   order_empty_mode_t* mode )
  {
    SC_TRY
    SC_CATCH
  }

  XQUERY_ERROR  
  StaticContext::set_boundary_space_policy(XQC_StaticContext context, boundary_space_mode_t mode)
  {
    SC_TRY
    SC_CATCH
  }

  XQUERY_ERROR
  StaticContext::get_boundary_space_policy(XQC_StaticContext context, boundary_space_mode_t* mode )
  {
    SC_TRY
    SC_CATCH
  }

  XQUERY_ERROR 
  StaticContext::set_copy_namespaces_mode(XQC_StaticContext context,  
                                          preserve_mode_t preserve,
                                          inherit_mode_t inherit )
  {
    SC_TRY
    SC_CATCH
  }

  XQUERY_ERROR
  StaticContext::get_copy_namespaces_mode(XQC_StaticContext context,
                                          preserve_mode_t* aPreserve, 
                                          inherit_mode_t* aInherit )
  {
    SC_TRY
    SC_CATCH
  }

  XQUERY_ERROR
  StaticContext::set_base_uri(XQC_StaticContext context, XQC_String base_uri )
  {
    SC_TRY
    SC_CATCH
  }

  XQUERY_ERROR
  StaticContext::get_base_uri(XQC_StaticContext context, XQC_String_Ref base_uri)
  {
    SC_TRY
    SC_CATCH
  }

  void
  StaticContext::free(XQC_StaticContext context)
  {
    try {
      SharedWrapper<zorba::StaticContext>* lQuery 
        = static_cast<SharedWrapper<zorba::StaticContext>* >(context->data);
      delete lQuery;
      delete context;

    } catch (ZorbaException &e) { 
      assert(false);
    } catch (...) { 
      assert(false);
    }
  }
} /* namespace zorbac */
