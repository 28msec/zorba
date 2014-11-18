/*
 * Copyright 2006-2012 The FLWOR Foundation.
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
#include "stdafx.h"

#include <assert.h>
#include <algorithm>

#include <zorba/external_module.h>
#include <zorba/serialization_callback.h>

#include "functions/udf.h"

#include "zorbamisc/ns_consts.h"
#include "util/string_util.h"

#define ZORBA_UTILS_HASHMAP_WITH_SERIALIZATION
#include "zorbautils/hashmap_itemp.h"
#undef ZORBA_UTILS_HASHMAP_WITH_SERIALIZATION

#include "context/static_context_consts.h"
#include "context/static_context.h"
#include "context/root_static_context.h"
#include "context/dynamic_loader.h"
#include "context/decimal_format.h"
#include "context/sctx_map_iterator.h"

#include "compiler/api/compilercb.h"
#include "compiler/expression/expr_base.h"
#include "compiler/expression/var_expr.h"
#ifndef ZORBA_NO_FULL_TEXT
#include "compiler/expression/ftnode.h"
#endif /* ZORBA_NO_FULL_TEXT */
#include "compiler/xqddf/collection_decl.h"
#include "compiler/xqddf/value_index.h"
#include "compiler/xqddf/value_ic.h"

#include "zorbatypes/collation_manager.h"
#include "zorbatypes/URI.h"

#include "api/unmarshaller.h"
#include "api/auditimpl.h"
#include "api/uri_resolver_wrappers.h"

#include "diagnostics/xquery_diagnostics.h"
#include "diagnostics/util_macros.h"

#include "system/globalenv.h"

#include "types/typemanager.h"
#include "types/casting.h"
#include "types/typeops.h"
#include "types/schema/validate.h"

#include <util/uri_util.h>

#include "functions/function.h"
#include "functions/library.h"
#include "functions/signature.h"

#include "compiler/translator/module_version.h"

#include "zorbaserialization/serialize_zorba_types.h"
#include "zorbaserialization/serialize_template_types.h"

#include "store/api/store.h"
#include "store/api/item_factory.h"
#include "store/api/iterator.h"


using namespace std;
#ifndef ZORBA_NO_FULL_TEXT
using namespace zorba::locale;
#endif /* ZORBA_NO_FULL_TEXT */

namespace zorba
{

#define ITEM_FACTORY (GENV.getStore().getItemFactory())


SERIALIZABLE_CLASS_VERSIONS(BaseUriInfo)

SERIALIZABLE_CLASS_VERSIONS(FunctionInfo)

SERIALIZABLE_CLASS_VERSIONS(VarInfo)

SERIALIZABLE_CLASS_VERSIONS(PrologOption)

SERIALIZABLE_CLASS_VERSIONS_2(static_context::ctx_module_t, TYPE_sctx_module)

SERIALIZABLE_CLASS_VERSIONS(static_context)


/**************************************************************************//**

*******************************************************************************/
void BaseUriInfo::serialize(::zorba::serialization::Archiver& ar)
{
  ar & thePrologBaseUri;
  ar & theApplicationBaseUri;
  ar & theEntityRetrievalUri;
  ar & theEncapsulatingEntityUri;

  ar & theBaseUri;

  ar & theHavePrologBaseUri;
  ar & theHaveApplicationBaseUri;
  ar & theHaveEntityRetrievalUri;
  ar & theHaveEncapsulatingEntityUri;

  ar & theHaveBaseUri;
}


/**************************************************************************//**

*******************************************************************************/
FunctionInfo::FunctionInfo()
  :
  theFunction(NULL),
  theIsDisabled(false)
{
}


FunctionInfo::FunctionInfo(function* f, bool disabled)
  :
  theFunction(f),
  theIsDisabled(disabled)
{
}


FunctionInfo::FunctionInfo(::zorba::serialization::Archiver& ar)
  :
  ::zorba::serialization::SerializeBaseClass()
{
}


/**************************************************************************//**

*******************************************************************************/
FunctionInfo::~FunctionInfo()
{
}


/**************************************************************************//**

*******************************************************************************/
void FunctionInfo::serialize(::zorba::serialization::Archiver& ar)
{
  ar & theFunction;
  ar & theIsDisabled;
}


/**************************************************************************//**

*******************************************************************************/
VarInfo::VarInfo()
  :
  theId(0),
  theKind(var_expr::unknown_var),
  theVarExpr(NULL)
{
}


/**************************************************************************//**

*******************************************************************************/
VarInfo::VarInfo(::zorba::serialization::Archiver& ar)
  :
  SimpleRCObject(ar)
{
}


/**************************************************************************//**

*******************************************************************************/
VarInfo::~VarInfo()
{
}


/**************************************************************************//**

*******************************************************************************/
VarInfo::VarInfo(var_expr* v)
  :
  theName(v->get_name()),
  theId(v->get_unique_id()),
  theKind(v->get_kind()),
  theType(v->get_type()),
  theIsExternal(v->is_external()),
  theHasInitializer(v->has_initializer()),
  theVarExpr(v),
  theSctx(v->get_sctx())
{
  theAnnotations.swap(v->theAnnotations);
}


/**************************************************************************//**

*******************************************************************************/
void VarInfo::serialize(::zorba::serialization::Archiver& ar)
{
  ar & theName;
  ar & theId;
  ar & theKind;
  ar & theType;
  ar & theIsExternal;
  ar & theHasInitializer;
  ar & theAnnotations;
  ar & theSctx;
}


/**************************************************************************//**

*******************************************************************************/
void VarInfo::setType(const xqtref_t& t)
{
  theType = t;
}

/**************************************************************************//**

*******************************************************************************/
TypeManager* VarInfo::getTypeManager() const
{
  return theSctx->get_typemanager();
}

/**************************************************************************//**

*******************************************************************************/
void PrologOption::serialize(::zorba::serialization::Archiver& ar)
{
  ar & theName;
  ar & theValue;
}


/**************************************************************************//**

*******************************************************************************/
void static_context::ctx_module_t::serialize(serialization::Archiver& ar)
{
  if (ar.is_serializing_out())
  {
    // serialize out: the uri of the module that is used in this plan

    zstring lURI = Unmarshaller::getInternalString(module->getURI());
    ar.set_is_temp_field(true);
    ar.dont_allow_delay();
    ar & lURI;
    ar.set_is_temp_field(false);
    ar & dyn_loaded_module;
    ar & theSctx;
  }
  else
  {
    // serialize in: load the serialized uri of the module and
    //               get the externalmodule from the user's
    //               registered serialization callback
    zstring lURI;
    ar.set_is_temp_field(true);
    ar & lURI;
    ar.set_is_temp_field(false);
    ar & dyn_loaded_module;
    ar & theSctx;

    if (dyn_loaded_module)
    {
      ZORBA_ASSERT(theSctx);
      module = GENV_DYNAMIC_LOADER->getExternalModule(lURI, *theSctx);

      // no way to get the module
      if (!module)
      {
        throw ZORBA_EXCEPTION(zerr::ZCSE0013_UNABLE_TO_LOAD_QUERY,
        ERROR_PARAMS(ZED(NoExternalModuleFromDLL_2), lURI));
      }
    }
    else
    {
      // class registered by the user
      SerializationCallback* lCallback = ar.getUserCallback();
      if (!lCallback)
      {
        throw ZORBA_EXCEPTION(zerr::ZCSE0013_UNABLE_TO_LOAD_QUERY,
        ERROR_PARAMS(ZED(NoSerializationCallbackForModule), lURI));
      }

      // the life-cycle of the module is managed by the user
      module = lCallback->getExternalModule(lURI.str());
      if (!module)
      {
        throw ZORBA_EXCEPTION(zerr::ZCSE0013_UNABLE_TO_LOAD_QUERY,
        ERROR_PARAMS(ZED(NoRegisteredSerializationCallback_2), lURI));
      }
    }
  }
}


/***************************************************************************//**
  Target namespaces of zorba builtin modules
********************************************************************************/

const zstring
static_context::DOT_VAR_NAME = "$$context-item";

const zstring
static_context::DOT_POS_VAR_NAME = "$$context-position";

const zstring
static_context::DOT_SIZE_VAR_NAME = "$$context-size";


const char*
static_context::W3C_NS_PREFIX = "http://www.w3.org/";

const char*
static_context::W3C_XML_NS = "http://www.w3.org/XML/1998/namespace";

const char*
static_context::W3C_XML_SCHEMA_NS = "http://www.w3.org/2001/XMLSchema";

const char*
static_context::W3C_FN_NS = "http://www.w3.org/2005/xpath-functions";

const char*
static_context::W3C_ERR_NS = "http://www.w3.org/2005/xqt-errors";

const char*
static_context::XQUERY_MATH_FN_NS = "http://www.w3.org/2005/xpath-functions/math";


const char*
static_context::ZORBA_NS_PREFIX = "http://www.zorba-xquery.com/";

const char*
static_context::ZORBA_IO_NS_PREFIX = "http://zorba.io/";

const char*
static_context::JSOUND_IO_NS_PREFIX = "http://jsound.io/";

const char*
static_context::ZORBA_MATH_FN_NS =
"http://zorba.io/modules/math";

const char*
static_context::ZORBA_BASE64_FN_NS =
"http://zorba.io/modules/base64";

const char*
static_context::ZORBA_JSON_CSV_FN_NS =
"http://zorba.io/modules/json-csv";

const char*
static_context::ZORBA_JSON_XML_FN_NS =
"http://zorba.io/modules/json-xml";

const char*
static_context::ZORBA_JSOUND_FN_NS =
"http://jsound.io/modules/jsound";

const char*
static_context::ZORBA_REFERENCE_FN_NS =
"http://zorba.io/modules/reference";

const char*
static_context::ZORBA_NODEPOS_FN_NS =
"http://zorba.io/modules/node-position";

const char*
static_context::ZORBA_STORE_DYNAMIC_COLLECTIONS_DDL_FN_NS =
"http://zorba.io/modules/store/dynamic/collections/ddl";

const char*
static_context::ZORBA_STORE_DYNAMIC_COLLECTIONS_DML_FN_NS =
"http://zorba.io/modules/store/dynamic/collections/dml";

const char*
static_context::ZORBA_STORE_STATIC_COLLECTIONS_DDL_FN_NS =
"http://zorba.io/modules/store/static/collections/ddl";

const char*
static_context::ZORBA_STORE_STATIC_COLLECTIONS_DML_FN_NS =
"http://zorba.io/modules/store/static/collections/dml";

const char*
static_context::ZORBA_STORE_STATIC_INDEXES_DDL_FN_NS =
"http://zorba.io/modules/store/static/indexes/ddl";

const char*
static_context::ZORBA_STORE_STATIC_INDEXES_DML_FN_NS =
"http://zorba.io/modules/store/static/indexes/dml";

const char*
static_context::ZORBA_STORE_STATIC_INTEGRITY_CONSTRAINTS_DDL_FN_NS =
"http://zorba.io/modules/store/static/integrity-constraints/ddl";

const char*
static_context::ZORBA_STORE_STATIC_INTEGRITY_CONSTRAINTS_DML_FN_NS =
"http://zorba.io/modules/store/static/integrity-constraints/dml";

const char*
static_context::ZORBA_STORE_DOCUMENTS_FN_NS =
"http://zorba.io/modules/store/documents";

const char*
static_context::ZORBA_STORE_UNORDERED_MAPS_FN_NS =
"http://zorba.io/modules/unordered-maps";

const char*
static_context::JSONIQ_DM_NS =
"http://jsoniq.org/types";

const char*
static_context::JSONIQ_FN_NS =
"http://jsoniq.org/functions";

const char*
static_context::ZORBA_SCHEMA_FN_NS =
"http://zorba.io/modules/schema";

const char*
static_context::ZORBA_XQDOC_FN_NS =
"http://zorba.io/modules/xqdoc";

const char*
static_context::ZORBA_RANDOM_FN_NS =
"http://zorba.io/modules/random";

const char*
static_context::ZORBA_SCTX_FN_NS =
"http://zorba.io/modules/sctx";

const char*
static_context::ZORBA_DCTX_FN_NS =
"http://zorba.io/modules/dctx";

const char*
static_context::ZORBA_REFLECTION_FN_NS =
"http://zorba.io/modules/reflection";

const char*
static_context::ZORBA_UTIL_FN_NS =
"http://zorba.io/util-functions";

const char*
static_context::ZORBA_SCRIPTING_FN_NS =
"http://www.zorba-xquery.com/zorba/scripting";

const char*
static_context::ZORBA_SEQ_FN_NS =
"http://zorba.io/modules/sequence";

const char*
static_context::ZORBA_STRING_FN_NS =
"http://zorba.io/modules/string";

const char*
static_context::ZORBA_URI_FN_NS =
"http://zorba.io/modules/uri";

const char*
static_context::ZORBA_FETCH_FN_NS =
"http://zorba.io/modules/fetch";

const char*
static_context::ZORBA_NODE_FN_NS =
"http://zorba.io/modules/node";

const char*
static_context::ZORBA_ITEM_FN_NS =
"http://zorba.io/modules/item";

const char*
static_context::ZORBA_XML_FN_NS =
"http://zorba.io/modules/xml";

#ifndef ZORBA_NO_FULL_TEXT
const char*
static_context::ZORBA_FULL_TEXT_FN_NS =
"http://zorba.io/modules/full-text";
#endif /* ZORBA_NO_FULL_TEXT */

const char*
static_context::ZORBA_DATETIME_FN_NS =
"http://zorba.io/modules/datetime";

const char*
static_context::ZORBA_XML_FN_OPTIONS_NS =
"http://zorba.io/modules/xml-options";

/***************************************************************************//**
  Target namespaces of zorba reserved modules
********************************************************************************/
const char*
static_context::XQUERY_OP_NS = "http://zorba.io/internal/xquery-ops";

const char*
static_context::ZORBA_OP_NS = "http://zorba.io/internal/zorba-ops";

/***************************************************************************//**
  Options-related namespaces
********************************************************************************/
const char*
static_context::ZORBA_OPTIONS_NS = "http://zorba.io/options";

const char*
static_context::ZORBA_OPTION_WARN_NS = "http://zorba.io/options/warnings";

const char*
static_context::ZORBA_OPTION_FEATURE_NS = "http://zorba.io/options/features";

const char*
static_context::ZORBA_OPTION_OPTIM_NS = "http://zorba.io/options/optimizer";

const char*
static_context::XQUERY_NS =
"http://www.w3.org/2012/xquery";

const char*
static_context::XQUERY_OPTION_NS =
"http://www.w3.org/2011/xquery-options";

const char*
static_context::ZORBA_VERSIONING_NS =
"http://zorba.io/options/versioning";


/***************************************************************************//**
  Static method to check if a given target namespace identifies a zorba
  builtin module.
********************************************************************************/
bool static_context::is_builtin_module(const zstring& ns)
{
  if (ns.compare(0, strlen(ZORBA_NS_PREFIX), ZORBA_NS_PREFIX) == 0 ||
      ns.compare(0, strlen(ZORBA_IO_NS_PREFIX), ZORBA_IO_NS_PREFIX) == 0 ||
      ns.compare(0, strlen(JSOUND_IO_NS_PREFIX), JSOUND_IO_NS_PREFIX) == 0)
  {
    return (ns == ZORBA_MATH_FN_NS ||
            ns == ZORBA_BASE64_FN_NS ||
            ns == ZORBA_REFERENCE_FN_NS ||
            ns == ZORBA_NODEPOS_FN_NS ||

            ns == ZORBA_STORE_DOCUMENTS_FN_NS ||
            ns == ZORBA_STORE_UNORDERED_MAPS_FN_NS ||
            ns == ZORBA_STORE_DYNAMIC_COLLECTIONS_DDL_FN_NS ||
            ns == ZORBA_STORE_DYNAMIC_COLLECTIONS_DML_FN_NS ||
            ns == ZORBA_STORE_STATIC_COLLECTIONS_DDL_FN_NS ||
            ns == ZORBA_STORE_STATIC_COLLECTIONS_DML_FN_NS ||
            ns == ZORBA_STORE_STATIC_INDEXES_DDL_FN_NS ||
            ns == ZORBA_STORE_STATIC_INDEXES_DML_FN_NS ||
            ns == ZORBA_STORE_STATIC_INTEGRITY_CONSTRAINTS_DDL_FN_NS ||
            ns == ZORBA_STORE_STATIC_INTEGRITY_CONSTRAINTS_DML_FN_NS ||
            ns == ZORBA_SCHEMA_FN_NS ||
            ns == ZORBA_XQDOC_FN_NS ||
            ns == ZORBA_RANDOM_FN_NS ||
            ns == ZORBA_SCTX_FN_NS ||
            ns == ZORBA_DCTX_FN_NS ||
            ns == ZORBA_REFLECTION_FN_NS ||
            ns == ZORBA_SCRIPTING_FN_NS ||
            ns == ZORBA_STRING_FN_NS ||

            ns == ZORBA_URI_FN_NS ||

            ns == ZORBA_JSON_CSV_FN_NS ||
            ns == ZORBA_JSON_XML_FN_NS ||
            ns == ZORBA_JSOUND_FN_NS ||
            ns == ZORBA_FETCH_FN_NS ||
            ns == ZORBA_NODE_FN_NS ||
            ns == ZORBA_ITEM_FN_NS ||
            ns == ZORBA_SEQ_FN_NS ||
            ns == ZORBA_UTIL_FN_NS ||
#ifndef ZORBA_NO_FULL_TEXT
            ns == ZORBA_FULL_TEXT_FN_NS ||
#endif /* ZORBA_NO_FULL_TEXT */
            ns == ZORBA_DATETIME_FN_NS ||
            ns == JSONIQ_FN_NS ||
            ns == ZORBA_XML_FN_NS);
  }
  else if (ns == W3C_FN_NS || ns == XQUERY_MATH_FN_NS)
  {
    return true;
  }

  return false;
}


/***************************************************************************//**
  Static method to check if a given target namespace identifies a zorba
  builtin virtual module. Virtual builtin modules do not actually exist (that's
  why they are called virtual), but they still have to be imported in order
  to make the functions in them visible to the importing module.
********************************************************************************/
bool static_context::is_builtin_virtual_module(const zstring& ns)
{
  if (ns.compare(0, strlen(ZORBA_NS_PREFIX), ZORBA_NS_PREFIX) == 0 ||
      ns.compare(0, strlen(ZORBA_IO_NS_PREFIX), ZORBA_IO_NS_PREFIX) == 0)
  {
    return (ns == ZORBA_SCRIPTING_FN_NS ||
            ns == ZORBA_UTIL_FN_NS);
  }
  else if (ns == W3C_FN_NS || ns == XQUERY_MATH_FN_NS)
  {
    return true;
  }

  return false;
}


/***************************************************************************//**
  Static method to check if a given target namespace identifies a zorba non
  pure builtin module, i.e. a builtin module that, in addition to builtin
  external functions, contains variable declarations and/or udfs.

  Note: The fuul-text module must be included here because it MUST be processed
  when imported, even in RELEASE mode. The reason is that the
  current-compare-options(), tokenize(), and tokenizer-properties() functions
  must be registered in the module's sctx (in addition to the root sctx).
********************************************************************************/
bool static_context::is_non_pure_builtin_module(const zstring& ns)
{
  if (ns.compare(0, strlen(ZORBA_NS_PREFIX), ZORBA_NS_PREFIX) == 0 ||
      ns.compare(0, strlen(ZORBA_IO_NS_PREFIX), ZORBA_IO_NS_PREFIX) == 0 ||
      ns.compare(0, strlen(JSOUND_IO_NS_PREFIX), JSOUND_IO_NS_PREFIX) == 0)
  {
    return (ns == ZORBA_MATH_FN_NS ||
            ns == ZORBA_JSON_CSV_FN_NS ||
            ns == ZORBA_JSON_XML_FN_NS ||
            ns == ZORBA_JSOUND_FN_NS ||
            ns == ZORBA_XQDOC_FN_NS ||
            ns == ZORBA_URI_FN_NS ||
            ns == ZORBA_RANDOM_FN_NS ||
            ns == ZORBA_STORE_UNORDERED_MAPS_FN_NS ||
            ns == ZORBA_FETCH_FN_NS ||
#ifndef ZORBA_NO_FULL_TEXT
            ns == ZORBA_FULL_TEXT_FN_NS ||
#endif /* ZORBA_NO_FULL_TEXT */
            ns == ZORBA_XML_FN_NS);
  }

  return false;
}


/***************************************************************************//**
  Static method to check if a given target namespace identifies a zorba
  reserved module.
********************************************************************************/
bool static_context::is_reserved_module(const zstring& ns)
{
  if (ns.compare(0, strlen(ZORBA_NS_PREFIX), ZORBA_NS_PREFIX) == 0 ||
      ns.compare(0, strlen(ZORBA_IO_NS_PREFIX), ZORBA_IO_NS_PREFIX) == 0)
  {
    return (ns == ZORBA_OP_NS || ns == XQUERY_OP_NS);
  }

  return false;
}


/***************************************************************************//**
  Static method
********************************************************************************/
zstring static_context::var_name(const store::Item* aVarName)
{
  zstring lVarName = aVarName->getStringValue();
  if (lVarName == static_context::DOT_POS_VAR_NAME)
  {
    lVarName = "context position";
  }
  else if (lVarName == static_context::DOT_SIZE_VAR_NAME)
  {
    lVarName = "context size";
  }
  else if (lVarName == static_context::DOT_VAR_NAME)
  {
    lVarName = "context item";
  }
  return lVarName;
}


/***************************************************************************//**
  Default Constructor.
********************************************************************************/
static_context::static_context()
  :
  theParent(NULL),
  theTraceStream(NULL),
  theQueryExpr(NULL),
  theBaseUriInfo(NULL),
  theExternalModulesMap(NULL),
  theNamespaceBindings(NULL),
  theHaveDefaultElementNamespace(false),
  theContextItemType(NULL),
  theVariablesMap(NULL),
  theImportedPrivateVariablesMap(NULL),
  theFunctionMap(NULL),
  theFunctionArityMap(NULL),
  theCollectionMap(NULL),
  theW3CCollectionMap(NULL),
  theIndexMap(NULL),
  theICMap(NULL),
  theDocumentMap(NULL),
  theCollationMap(NULL),
  theDefaultCollation(NULL),
  theCachedDefaultCollator(NULL),
  theOptionMap(NULL),
  theAuditEvent(&zorba::audit::NOP_EVENT_IMPL),
#ifndef ZORBA_NO_FULL_TEXT
  theFTMatchOptions(NULL),
#endif /* ZORBA_NO_FULL_TEXT */
  theLanguageKind(StaticContextConsts::language_kind_unknown),
  theXQueryVersion(StaticContextConsts::xquery_version_unknown),
  theJSONiqVersion(StaticContextConsts::jsoniq_version_unknown),
  theXPathCompatibility(StaticContextConsts::xpath_unknown),
  theConstructionMode(StaticContextConsts::cons_unknown),
  theInheritNamespaces(true),
  thePreserveNamespaces(true),
  theOrderingMode(StaticContextConsts::ordering_unknown),
  theEmptyOrderMode(StaticContextConsts::empty_order_unknown),
  theBoundarySpaceMode(StaticContextConsts::boundary_space_unknown),
  theValidationMode(StaticContextConsts::validation_unknown),
  theAllWarningsDisabled(false),
  theAllWarningsErrors(false),
  theFeatures(0),
  theTempIndexCounter(0)
{
#if 0
  std::cout << "Allocating SCTX : " << this << std::endl;
#endif
}


/*******************************************************************************

********************************************************************************/
static_context::static_context(static_context* parent)
  :
  theParent(parent),
  theTraceStream(NULL),
  theQueryExpr(NULL),
  theBaseUriInfo(NULL),
  theExternalModulesMap(NULL),
  theNamespaceBindings(NULL),
  theHaveDefaultElementNamespace(false),
  theContextItemType(NULL),
  theVariablesMap(NULL),
  theImportedPrivateVariablesMap(NULL),
  theFunctionMap(NULL),
  theFunctionArityMap(NULL),
  theCollectionMap(0),
  theW3CCollectionMap(NULL),
  theIndexMap(NULL),
  theICMap(NULL),
  theDocumentMap(NULL),
  theCollationMap(NULL),
  theDefaultCollation(NULL),
  theCachedDefaultCollator(NULL),
  theOptionMap(NULL),
  theAuditEvent(&zorba::audit::NOP_EVENT_IMPL),
#ifndef ZORBA_NO_FULL_TEXT
  theFTMatchOptions(NULL),
#endif /* ZORBA_NO_FULL_TEXT */
  theLanguageKind(StaticContextConsts::language_kind_unknown),
  theXQueryVersion(StaticContextConsts::xquery_version_unknown),
  theJSONiqVersion(StaticContextConsts::jsoniq_version_unknown),
  theXPathCompatibility(StaticContextConsts::xpath_unknown),
  theConstructionMode(StaticContextConsts::cons_unknown),
  theInheritNamespaces(parent->theInheritNamespaces),
  thePreserveNamespaces(parent->thePreserveNamespaces),
  theOrderingMode(StaticContextConsts::ordering_unknown),
  theEmptyOrderMode(StaticContextConsts::empty_order_unknown),
  theBoundarySpaceMode(StaticContextConsts::boundary_space_unknown),
  theValidationMode(StaticContextConsts::validation_unknown),
  theAllWarningsDisabled(false),
  theAllWarningsErrors(false),
  // we copy features from the parent such that it's
  // easy to set and unset them
  theFeatures(parent->theFeatures),
  theTempIndexCounter(0)
{
#if 0
  std::cout << "Allocating SCTX : " << this << " under parent SCTX : "
            << parent << std::endl;
#endif

  if (theParent != NULL && !theParent->is_global_root_sctx())
    RCHelper::addReference(theParent);
}


/*******************************************************************************

********************************************************************************/
static_context::static_context(::zorba::serialization::Archiver& ar)
  :
  SyncedRCObject(ar),
  theParent(NULL),
  theTraceStream(NULL),
  theQueryExpr(NULL),
  theBaseUriInfo(NULL),
  theExternalModulesMap(NULL),
  theNamespaceBindings(NULL),
  theHaveDefaultElementNamespace(false),
  theContextItemType(NULL),
  theVariablesMap(NULL),
  theImportedPrivateVariablesMap(NULL),
  theFunctionMap(NULL),
  theFunctionArityMap(NULL),
  theCollectionMap(0),
  theW3CCollectionMap(NULL),
  theIndexMap(0),
  theICMap(0),
  theDocumentMap(NULL),
  theCollationMap(NULL),
  theDefaultCollation(NULL),
  theCachedDefaultCollator(NULL),
  theOptionMap(NULL),
  theAuditEvent(&zorba::audit::NOP_EVENT_IMPL),
#ifndef ZORBA_NO_FULL_TEXT
  theFTMatchOptions(NULL),
#endif /* ZORBA_NO_FULL_TEXT */
  theLanguageKind(StaticContextConsts::language_kind_unknown),
  theXQueryVersion(StaticContextConsts::xquery_version_unknown),
  theJSONiqVersion(StaticContextConsts::jsoniq_version_unknown),
  theXPathCompatibility(StaticContextConsts::xpath_unknown),
  theConstructionMode(StaticContextConsts::cons_unknown),
  theInheritNamespaces(true),
  thePreserveNamespaces(true),
  theOrderingMode(StaticContextConsts::ordering_unknown),
  theEmptyOrderMode(StaticContextConsts::empty_order_unknown),
  theBoundarySpaceMode(StaticContextConsts::boundary_space_unknown),
  theValidationMode(StaticContextConsts::validation_unknown),
  theAllWarningsDisabled(false),
  theAllWarningsErrors(false),
  theFeatures(0),
  theTempIndexCounter(0)
{
}


/***************************************************************************//**
  Destructor.
********************************************************************************/
static_context::~static_context()
{
#if 0
  std::cout << "Deallocating SCTX : " << this << std::endl;
#endif
  for (std::vector<internal::URIMapper*>::const_iterator mapper =
         theURIMappers.begin();
       mapper != theURIMappers.end(); mapper++) {
    delete *mapper;
  }
  for (std::vector<internal::URLResolver*>::const_iterator resolver =
         theURLResolvers.begin();
       resolver != theURLResolvers.end(); resolver++) {
    delete *resolver;
  }

  if (theExternalModulesMap)
  {
    ExternalModuleMap::iterator ite = theExternalModulesMap->begin();
    ExternalModuleMap::iterator end = theExternalModulesMap->end();
    for(; ite != end; ++ite)
    {
      const ctx_module_t& val = ite.getValue();
      if (val.dyn_loaded_module)
      {
        val.module->destroy();
      }
    }

    delete theExternalModulesMap;
  }

  if (theW3CCollectionMap)
    delete theW3CCollectionMap;

  if (theCollectionMap)
    delete theCollectionMap;

  if (theIndexMap)
    delete theIndexMap;

  if (theICMap)
    delete theICMap;

  if (theFunctionMap)
  {
    delete theFunctionMap;
  }

  if (theFunctionArityMap)
  {
    FunctionArityMap::iterator ite = theFunctionArityMap->begin();
    FunctionArityMap::iterator end = theFunctionArityMap->end();
    for (; ite != end; ++ite)
    {
      std::vector<FunctionInfo>* fv = ite.getValue();
      delete fv;
    }

    delete theFunctionArityMap;
  }

  if (theVariablesMap)
  {
    delete theVariablesMap;
    theVariablesMap = NULL;
  }

  if (theImportedPrivateVariablesMap)
  {
    delete theImportedPrivateVariablesMap;
    theImportedPrivateVariablesMap = NULL;
  }

  if (theNamespaceBindings)
    delete theNamespaceBindings;

  if (theDefaultCollation)
    delete theDefaultCollation;

  if (theCollationMap)
  {
    CollationMap::iterator ite = theCollationMap->begin();
    CollationMap::iterator end = theCollationMap->end();
    for ( ; ite != end ; ++ite)
    {
      delete ite->second;
    }

    delete theCollationMap;
    theCollationMap = 0;
  }

  if (theOptionMap)
    delete theOptionMap;

#ifndef ZORBA_NO_FULL_TEXT
  delete theFTMatchOptions;
#endif /* ZORBA_NO_FULL_TEXT */

  if (theBaseUriInfo)
    delete theBaseUriInfo;

  if (theParent && !theParent->is_global_root_sctx())
    RCHelper::removeReference(theParent);
}


/*******************************************************************************

********************************************************************************/
void static_context::serialize_resolvers(serialization::Archiver& ar)
{
  csize lNumURIMappers;
  csize lNumURLResolvers;

  if (ar.is_serializing_out())
  {
    lNumURIMappers = theURIMappers.size();
    lNumURLResolvers = theURLResolvers.size();

    ar.set_is_temp_field(true);
    ar & lNumURIMappers;
    ar & lNumURLResolvers;
    ar.set_is_temp_field(false);
  }
  else
  {
    // serialize in: set the document and collection resolvers
    //               use one by the user or use the default
    //               if null is returned
    SerializationCallback* lCallback = ar.getUserCallback();

    ar.set_is_temp_field(true);
    // number of URIMappers passed by the user
    ar & lNumURIMappers;
    // number of URLResolvers passed by the user
    ar & lNumURLResolvers;
    ar.set_is_temp_field(false);

    // callback required but not available
    if ((lNumURIMappers || lNumURLResolvers) && !lCallback)
    {
      throw ZORBA_EXCEPTION(zerr::ZCSE0013_UNABLE_TO_LOAD_QUERY,
      ERROR_PARAMS(ZED(NoSerializationCallbackForDocColMod)));
    }

    if (lNumURIMappers)
    {
      for (size_t i = 0; i < lNumURIMappers; ++i)
      {
        zorba::URIMapper* lURIMapper = lCallback->getURIMapper(i);
        if (!lURIMapper)
        {
          throw ZORBA_EXCEPTION(zerr::ZCSE0013_UNABLE_TO_LOAD_QUERY,
          ERROR_PARAMS(ZED(NoModuleURIResolver)));
        }

        add_uri_mapper(new URIMapperWrapper(*lURIMapper));
      }
    }

    if (lNumURLResolvers)
    {
      for (size_t i = 0; i < lNumURLResolvers; ++i)
      {
        zorba::URLResolver* lURLResolver = lCallback->getURLResolver(i);
        if (!lURLResolver)
        {
          throw ZORBA_EXCEPTION(zerr::ZCSE0013_UNABLE_TO_LOAD_QUERY,
          ERROR_PARAMS(ZED(NoModuleURIResolver)));
        }

        add_url_resolver(new URLResolverWrapper(*lURLResolver));
      }
    }
  }
}


/*******************************************************************************

********************************************************************************/
void static_context::serialize_tracestream(serialization::Archiver& ar)
{
  bool lUserTraceStream;
  if (ar.is_serializing_out())
  {
    // serialize out: remember whether the user registered a trace stream
    lUserTraceStream = (theTraceStream != 0);

    ar.set_is_temp_field(true);
    ar & lUserTraceStream;
    ar.set_is_temp_field(false);
  }
  else
  {
    // serialize in: set the trace stream from the user
    //               std::cerr is used if non was registered
    SerializationCallback* lCallback = ar.getUserCallback();

    ar.set_is_temp_field(true);
    ar & lUserTraceStream; // trace stream passed by the user
    ar.set_is_temp_field(false);

    // callback required but not available
    if (lUserTraceStream && !lCallback)
    {
      throw ZORBA_EXCEPTION(
        zerr::ZCSE0013_UNABLE_TO_LOAD_QUERY,
        ERROR_PARAMS( ZED( NoSerializationCallbackForTraceStream ) )
      );
    }

    if (lUserTraceStream) {
      bool lTraceStream =  lCallback->getTraceStream(theTraceStream);
      if (!lTraceStream) {
        throw ZORBA_EXCEPTION(
          zerr::ZCSE0013_UNABLE_TO_LOAD_QUERY,
          ERROR_PARAMS( ZED( BadTraceStream ) )
        );
      }
    }
  }
}


/*******************************************************************************

********************************************************************************/
void static_context::serialize(::zorba::serialization::Archiver& ar)
{
  if (ar.is_serializing_out())
  {
    ar.set_is_temp_field(true);
    bool  parent_is_root = check_parent_is_root();
    ar & parent_is_root;
    ar.set_is_temp_field(false);

    if (!parent_is_root)
    {
      ar.dont_allow_delay();
      ar & theParent;
    }
    else
    {
      //  context *fooctx = NULL;
      //  ar & fooctx;
    }
  }
  else
  {
    //in serialization
    ar.set_is_temp_field(true);
    bool  parent_is_root;
    ar & parent_is_root;
    ar.set_is_temp_field(false);

    if (parent_is_root)
    {
      theParent = &GENV_ROOT_STATIC_CONTEXT;
    }
    else
    {
      ar & theParent;
      ZORBA_ASSERT(theParent);
      theParent->addReference();
    }
  }

  ar & theModuleNamespace;
  ar & theImportedBuiltinModules;

  ar & theBaseUriInfo;

  serialize_resolvers(ar);
  serialize_tracestream(ar);

  ar & theURIPath;
  ar & theLibPath;

  // Options must be serialized BEFORE external modules
  ar & theOptionMap;
  ar & theExternalModulesMap;

  SERIALIZE_TYPEMANAGER_RCHANDLE(TypeManager, theTypeManager);

  ar & theNamespaceBindings;
  ar & theDefaultElementNamespace;
  ar & theHaveDefaultElementNamespace;
  ar & theDefaultFunctionNamespaces;

  ar & theContextItemType;

  ar & theVariablesMap;
  ar & theImportedPrivateVariablesMap;

  if (ar.get_ccb()->theHasEval)
  {
    ar & theFunctionMap;
    ar & theFunctionArityMap;
  }

  ar & theCollectionMap;

  ar & theW3CCollectionMap;
  ar & theDefaultW3CCollectionType;

  ar & theIndexMap;

  ar & theICMap;

  ar & theDocumentMap;

  ar & theCollationMap;
  ar & theDefaultCollation;

#ifndef ZORBA_NO_FULL_TEXT
  ar & theFTMatchOptions;
#endif /* ZORBA_NO_FULL_TEXT */

  SERIALIZE_ENUM(StaticContextConsts::language_kind_t,  theLanguageKind);
  SERIALIZE_ENUM(StaticContextConsts::xquery_version_t, theXQueryVersion);
  SERIALIZE_ENUM(StaticContextConsts::jsoniq_version_t, theJSONiqVersion);
  SERIALIZE_ENUM(StaticContextConsts::xpath_compatibility_t, theXPathCompatibility);
  SERIALIZE_ENUM(StaticContextConsts::construction_mode_t, theConstructionMode);
  ar & theInheritNamespaces;
  ar & thePreserveNamespaces;
  SERIALIZE_ENUM(StaticContextConsts::ordering_mode_t, theOrderingMode);
  SERIALIZE_ENUM(StaticContextConsts::empty_order_mode_t, theEmptyOrderMode);
  SERIALIZE_ENUM(StaticContextConsts::boundary_space_mode_t, theBoundarySpaceMode);
  SERIALIZE_ENUM(StaticContextConsts::validation_mode_t, theValidationMode);

  ar & theDecimalFormats;

  ar & theDisabledWarnings;

  ar & theAllWarningsDisabled;

  ar & theWarningsAreErrors;

  ar & theAllWarningsErrors;

  ar & theFeatures;

  ar & theTempIndexCounter;
}


/***************************************************************************//**
  Create a new static_context obj and make a child of "this" static_context obj.
********************************************************************************/
static_context* static_context::create_child_context()
{
  return new static_context(this);
}


/***************************************************************************//**

********************************************************************************/
bool static_context::is_global_root_sctx() const
{
  return (this == &GENV_ROOT_STATIC_CONTEXT);
}


/***************************************************************************//**

********************************************************************************/
bool static_context::check_parent_is_root()
{
  return theParent == &GENV_ROOT_STATIC_CONTEXT;
}


/***************************************************************************//**

********************************************************************************/
expr* static_context::get_query_expr() const
{
  return theQueryExpr;
}


/***************************************************************************//**

********************************************************************************/
void static_context::set_query_expr(expr* expr)
{
  theQueryExpr = expr;
}


/***************************************************************************//**

********************************************************************************/
void static_context::set_trace_stream(std::ostream& os)
{
  theTraceStream = &os;
}


/***************************************************************************//**

********************************************************************************/
std::ostream* static_context::get_trace_stream() const
{
  if (theTraceStream)
    return theTraceStream;

  return (theParent == NULL ?
          &std::cerr :
          dynamic_cast<static_context*>(theParent)->get_trace_stream());
}


/***************************************************************************//**

********************************************************************************/
void static_context::add_imported_builtin_module(const zstring& ns)
{
  theImportedBuiltinModules.push_back(ns);
}


/***************************************************************************//**

********************************************************************************/
bool static_context::is_imported_builtin_module(const zstring& ns)
{
  static_context* sctx = this;

  while (sctx != NULL)
  {
    if (!sctx->theImportedBuiltinModules.empty())
    {
      std::vector<zstring>::const_iterator ite = sctx->theImportedBuiltinModules.begin();
      std::vector<zstring>::const_iterator end = sctx->theImportedBuiltinModules.end();
      for (; ite != end; ++ite)
      {
        if (*ite == ns)
          return true;
      }
    }

    sctx = sctx->theParent;
  }

  return false;
}


/////////////////////////////////////////////////////////////////////////////////
//                                                                             //
//  Base URI                                                                   //
//                                                                             //
/////////////////////////////////////////////////////////////////////////////////


/***************************************************************************//**

********************************************************************************/
zstring static_context::get_implementation_baseuri() const
{
  return reinterpret_cast<root_static_context*>(&GENV_ROOT_STATIC_CONTEXT)->
         theImplementationBaseUri;
}


/***************************************************************************//**

********************************************************************************/
bool static_context::get_encapsulating_entity_uri(zstring& res) const
{
  const static_context* sctx = this;
  while (sctx != NULL)
  {
    if (sctx->theBaseUriInfo != NULL &&
        sctx->theBaseUriInfo->theHaveEncapsulatingEntityUri)
    {
      res = sctx->theBaseUriInfo->theEncapsulatingEntityUri;
      return true;
    }

    sctx = sctx->theParent;
  }

  return false;
}


/***************************************************************************//**

********************************************************************************/
void static_context::set_encapsulating_entity_uri(const zstring& uri)
{
  if (theBaseUriInfo == NULL)
  {
    theBaseUriInfo = new BaseUriInfo;
  }

  theBaseUriInfo->theEncapsulatingEntityUri = uri;
  theBaseUriInfo->theHaveEncapsulatingEntityUri = true;

  compute_base_uri();
}


/***************************************************************************//**

********************************************************************************/
bool static_context::get_entity_retrieval_uri(zstring& res) const
{
  const static_context* sctx = this;
  while (sctx != NULL)
  {
    if (sctx->theBaseUriInfo != NULL &&
        sctx->theBaseUriInfo->theHaveEntityRetrievalUri)
    {
      res = sctx->theBaseUriInfo->theEntityRetrievalUri;
      return true;
    }

    sctx = sctx->theParent;
  }

  return false;
}


/***************************************************************************//**

********************************************************************************/
void static_context::set_entity_retrieval_uri(const zstring& uri)
{
  if (theBaseUriInfo == NULL)
  {
    theBaseUriInfo = new BaseUriInfo;
  }

  theBaseUriInfo->theEntityRetrievalUri = uri;
  theBaseUriInfo->theHaveEntityRetrievalUri = true;

  compute_base_uri();
}


/***************************************************************************//**

********************************************************************************/
zstring static_context::get_base_uri() const
{
  const static_context* sctx = this;
  while (sctx != NULL)
  {
    if (sctx->theBaseUriInfo != NULL &&
        sctx->theBaseUriInfo->theHaveBaseUri)
    {
      return sctx->theBaseUriInfo->theBaseUri;
    }

    sctx = sctx->theParent;
  }
  return "";  //undefined
}


/***************************************************************************//**

********************************************************************************/
void static_context::set_base_uri(const zstring& uri, bool from_prolog)
{
  if (theBaseUriInfo == NULL)
  {
    theBaseUriInfo = new BaseUriInfo;
  }

  if (from_prolog)
  {
    if (theBaseUriInfo->theHavePrologBaseUri)
      throw XQUERY_EXCEPTION(err::XQST0032);

    theBaseUriInfo->thePrologBaseUri = uri;
    theBaseUriInfo->theHavePrologBaseUri = true;
  }
  else
  {
    // overwite existing value of application baseuri, if any
    theBaseUriInfo->theApplicationBaseUri = uri;
    theBaseUriInfo->theHaveApplicationBaseUri = true;
  }

  compute_base_uri();
}


/***************************************************************************//**
  Base Uri Computation

  The from_prolog_baseuri is the one declared in the prolog. The baseuri is set
  explicitly from the C++/C api. If both the from_prolog_baseuri and the baseuri
  are set, the from_prolog_baseuri hides the baseuri.

  For the main module, the entity_retrieval_url is set by default to the name
  of file containing the query we are running. For library modules, it is set
  to the location uri of each module component. It may also be set explicitly
  from the C++/C api.
********************************************************************************/
void static_context::compute_base_uri()
{
  if (theBaseUriInfo == NULL)
  {
    theBaseUriInfo = new BaseUriInfo;
  }

  bool found;

  bool foundUserBaseUri = false;
  zstring userBaseUri;
  zstring encapsulatingUri;
  zstring entityUri;

  const static_context* sctx = this;

  while (sctx != NULL)
  {
    if (sctx->theBaseUriInfo != NULL &&
        sctx->theBaseUriInfo->theHavePrologBaseUri)
    {
      userBaseUri = sctx->theBaseUriInfo->thePrologBaseUri;
      foundUserBaseUri = true;
      break;
    }

    sctx = sctx->theParent;
  }

  if (!foundUserBaseUri)
  {
    sctx = this;

    while (sctx != NULL)
    {
      if (sctx->theBaseUriInfo != NULL &&
          sctx->theBaseUriInfo->theHaveApplicationBaseUri)
      {
        userBaseUri = sctx->theBaseUriInfo->theApplicationBaseUri;
        foundUserBaseUri = true;
        break;
      }

      sctx = sctx->theParent;
    }
  }

  if (foundUserBaseUri)
  {
    try
    {
      URI lCheckValid(userBaseUri);
      if (lCheckValid.is_absolute())
      {
        theBaseUriInfo->theBaseUri = lCheckValid.toString();
        theBaseUriInfo->theHaveBaseUri = true;
        return; // valid (absolute) uri
      }
    }
    catch (ZorbaException const&)
    {
      // assume it's relative and go on
    }

    /// is relative, needs to be resolved
    found = get_encapsulating_entity_uri(encapsulatingUri);
    if (found)
    {
      URI base(encapsulatingUri);
      URI resolvedURI(base, userBaseUri);
      theBaseUriInfo->theBaseUri = resolvedURI.toString();
      theBaseUriInfo->theHaveBaseUri = true;
      return;
    }

    found = get_entity_retrieval_uri(entityUri);
    if (found)
    {
      URI base(entityUri);
      if (base.is_absolute())
      {
        URI resolvedURI(base, userBaseUri);
        theBaseUriInfo->theBaseUri = resolvedURI.toString();
        theBaseUriInfo->theHaveBaseUri = true;
        return;
      }
    }

    URI base(get_implementation_baseuri());
    URI resolvedURI(base, userBaseUri);
    theBaseUriInfo->theBaseUri = resolvedURI.toString();
    theBaseUriInfo->theHaveBaseUri = true;
    return;
  }

  found = get_encapsulating_entity_uri(encapsulatingUri);
  if (found)
  {
    theBaseUriInfo->theBaseUri = encapsulatingUri;
    theBaseUriInfo->theHaveBaseUri = true;
    return;
  }

  found = get_entity_retrieval_uri(entityUri);
  if (found)
  {
    theBaseUriInfo->theBaseUri = entityUri;
    theBaseUriInfo->theHaveBaseUri = true;
    return;
  }

  theBaseUriInfo->theBaseUri = "";
  theBaseUriInfo->theHaveBaseUri = false;
  return;
}


////////////////////////////////////////////////////////////////////////////////
//                                                                            //
//  URI Absolutization                                                        //
//                                                                            //
////////////////////////////////////////////////////////////////////////////////


/***************************************************************************//**

********************************************************************************/
zstring static_context::resolve_relative_uri(
    const zstring& aUri,
    bool aValidate) const
{
  URI lBaseUri(get_base_uri());
  URI lResolvedUri(lBaseUri, aUri, aValidate);
  return lResolvedUri.toString();
}


/***************************************************************************//**

********************************************************************************/
zstring static_context::resolve_relative_uri(
    const zstring& aRelativeUri,
    const zstring& aBaseUri,
    bool aValidate) const
{
  URI lBaseUri(aBaseUri);
  URI lResolvedUri(lBaseUri, aRelativeUri, aValidate);
  return lResolvedUri.toString();
}


////////////////////////////////////////////////////////////////////////////////
//                                                                            //
//  URI Resolution                                                            //
//                                                                            //
////////////////////////////////////////////////////////////////////////////////


/***************************************************************************//**

********************************************************************************/
void static_context::add_uri_mapper(internal::URIMapper* aMapper)
{
  theURIMappers.push_back(aMapper);
}


/***************************************************************************//**

********************************************************************************/
void static_context::add_url_resolver(internal::URLResolver* aResolver)
{
  theURLResolvers.push_back(aResolver);
}


/***************************************************************************//**

********************************************************************************/
std::unique_ptr<internal::Resource> static_context::resolve_uri(
    zstring const& aUri,
    internal::EntityData::Kind aEntityKind,
    zstring& oErrorMessage) const
{
  // Create a simple EntityData that just reports the specified Kind
  internal::EntityData const lData(aEntityKind);
  return this->resolve_uri(aUri, lData, oErrorMessage);
}

std::unique_ptr<internal::Resource> static_context::resolve_uri(
    zstring const& aUri,
    internal::EntityData const& aEntityData,
    zstring& oErrorMessage) const
{
  std::vector<zstring> lUris;
  apply_uri_mappers(aUri, &aEntityData, internal::URIMapper::CANDIDATE, lUris);

  std::unique_ptr<internal::Resource> lRetval;
  apply_url_resolvers(lUris, &aEntityData, lRetval, oErrorMessage);

  return std::move(lRetval);
}

void static_context::get_component_uris(
    zstring const& aUri,
    internal::EntityData::Kind aEntityKind,
    std::vector<zstring>& oComponents) const
{
  // Create a simple EntityData that just reports the specified Kind
  internal::EntityData const lData(aEntityKind);

  apply_uri_mappers(aUri, &lData, internal::URIMapper::COMPONENT, oComponents);
  if (oComponents.size() == 0)
  {
    oComponents.push_back(aUri);
  }
}

void static_context::get_candidate_uris(
    zstring const& aUri,
    internal::EntityData::Kind aEntityKind,
    std::vector<zstring>& oComponents) const
{
  // Create a simple EntityData that just reports the specified Kind
  internal::EntityData const lData(aEntityKind);

  apply_uri_mappers(aUri, &lData, internal::URIMapper::CANDIDATE, oComponents);
  if (oComponents.size() == 0)
  {
    oComponents.push_back(aUri);
  }
}


/***************************************************************************//**

********************************************************************************/
void static_context::apply_uri_mappers(
    zstring const& aUri,
    internal::EntityData const* aEntityData,
    internal::URIMapper::Kind aMapperKind,
    std::vector<zstring>& oUris) const
{
  // Initialize list with the one input URI.
  oUris.push_back(aUri);

  // Iterate upwards through the static_context tree...
  for (static_context const* sctx = this;
       sctx != NULL; sctx = sctx->theParent)
  {
    // Iterate through all available mappers on this static_context...
    for (std::vector<internal::URIMapper*>::const_iterator mapper =
           sctx->theURIMappers.begin();
         mapper != sctx->theURIMappers.end(); mapper++)
    {
      // Only call mappers of the appropriate kind
      if ((**mapper).mapperKind() != aMapperKind)
      {
        continue;
      }

      // Create new list (currently empty) for this mapper
      std::vector<zstring> lResultUris;

      // Iterate through all URIs on the current list...
      for (std::vector<zstring>::iterator uri = oUris.begin();
           uri != oUris.end(); uri++)
      {
        // And call the current mapper with the current URI.
        size_t const lPreNumResultUris = lResultUris.size();
        (*mapper)->mapURI(*uri, aEntityData, *this, lResultUris);
        size_t const lPostNumResultUris = lResultUris.size();
        if (lPreNumResultUris == lPostNumResultUris)
        {
          // Mapper didn't map this URI to anything new, therefore add
          // the original URI to the result list
          lResultUris.push_back(*uri);
        }
        else
        {
          // Check the new entries for DENY_ACCESS.
          for (size_t i = lPreNumResultUris; i < lPostNumResultUris; i++)
          {
            if (lResultUris.at(i) == internal::URIMapper::DENY_ACCESS) {
              throw XQUERY_EXCEPTION(zerr::ZXQP0029_URI_ACCESS_DENIED,
                                     ERROR_PARAMS(aUri));
            }
          }
        }
      }

      // Now repeat process with the next mapper using the new list of
      // URIs.
      oUris = lResultUris;
    }
  }

  // We're all done, but for efficiency, we want to attempt all possible file:
  // URIs first. So, post-sort the list.
  size_t const lNumUris = oUris.size();
  std::vector<zstring> lFileUris, lNonFileUris;
  for (size_t i = 0; i < lNumUris; i++) {
    zstring lUri = oUris.at(i);
    if (uri::get_scheme(lUri) == uri::file) {
      lFileUris.push_back(lUri);
    }
    else {
      lNonFileUris.push_back(lUri);
    }
  }

  oUris = lFileUris;
  oUris.insert(oUris.end(), lNonFileUris.begin(), lNonFileUris.end());
}


/***************************************************************************//**

********************************************************************************/
void static_context::apply_url_resolvers(
    std::vector<zstring>& aUrls,
    internal::EntityData const* aEntityData,
    std::unique_ptr<internal::Resource>& oResource,
    zstring& oErrorMessage) const
{
  oErrorMessage.clear();

  // Iterate through all candidate URLs...
  for (std::vector<zstring>::iterator url = aUrls.begin();
       url != aUrls.end(); url++)
  {
    // We should never try to load the http-client module using its original URI,
    // because that URI starts with http:, so we'll try to load the http-client
    // module, leading to a stack overflow.
    if (ZA_BEGINS_WITH(*url, "http://zorba.io/modules/http-client")
        ||
        ZA_BEGINS_WITH(*url, "http://www.zorba-xquery.com/modules/http-client"))
    {
      continue;
    }

    // Iterate upwards through the static_context tree...
    for (static_context const* sctx = this;
         sctx != NULL; sctx = sctx->theParent)
    {
      // Iterate through all available resolvers on this static_context...
      for (std::vector<internal::URLResolver*>::const_iterator resolver =
             sctx->theURLResolvers.begin();
           resolver != sctx->theURLResolvers.end(); resolver++)
      {
        try
        {
          // Take ownership of returned Resource (if any)
          oResource.reset((**resolver).resolveURL(*url, aEntityData));
          if (oResource.get() != NULL)
          {
            // Populate the URL used to load this Resource
            oResource->setUrl(*url);
            return;
          }
        }
        catch (const std::exception& e)
        {
          if (oErrorMessage.empty())
          {
            // Really no point in saving anything more than the first message
            oErrorMessage = e.what();
          }
        }
        catch (...)
        {
          // Not much we can do here except try the rest of the
          // candidate URIs
        }
      }
    }
  }
}


/*******************************************************************************

********************************************************************************/
void static_context::set_uri_path(const std::vector<zstring>& path)
{
  theURIPath = path;
}


/*******************************************************************************

********************************************************************************/
void static_context::get_uri_path(std::vector<zstring>& path) const
{
  path.insert(path.end(), theURIPath.begin(), theURIPath.end());
}


/*******************************************************************************

********************************************************************************/
void static_context::get_full_uri_path(std::vector<zstring>& path) const
{
  if (theParent != NULL)
  {
    theParent->get_full_uri_path(path);
  }

  get_uri_path(path);
}

/*******************************************************************************

********************************************************************************/
void static_context::set_lib_path(const std::vector<zstring>& path)
{
  theLibPath = path;
}


/*******************************************************************************

********************************************************************************/
void static_context::get_lib_path(std::vector<zstring>& path) const
{
  path.insert(path.end(), theLibPath.begin(), theLibPath.end());
}


/*******************************************************************************

********************************************************************************/
void static_context::get_full_lib_path(std::vector<zstring>& path) const
{
  if (theParent != NULL)
  {
    theParent->get_full_lib_path(path);
  }

  get_lib_path(path);
}


/////////////////////////////////////////////////////////////////////////////////
//                                                                             //
//  Validating Items                                                           //
//                                                                             //
/////////////////////////////////////////////////////////////////////////////////


/***************************************************************************//**

********************************************************************************/
bool static_context::validate(
    store::Item* rootElement,
    store::Item_t& validatedResult,
    StaticContextConsts::validation_mode_t validationMode) const
{
  zstring xsTns(static_context::W3C_XML_SCHEMA_NS);
  return validate(rootElement, validatedResult, xsTns, validationMode);
}


/***************************************************************************//**

********************************************************************************/
bool static_context::validate(
    store::Item* rootElement,
    store::Item_t& validatedResult,
    const zstring& targetNamespace,
    StaticContextConsts::validation_mode_t validationMode) const
{
  if ( !rootElement->isNode() ||
       (rootElement->getNodeKind() != store::StoreConsts::documentNode &&
       rootElement->getNodeKind() != store::StoreConsts::elementNode))
    return false;

  if ( rootElement->isValidated() )
  {
    validatedResult = rootElement;
    return true;
  }

#ifndef ZORBA_NO_XMLSCHEMA

  TypeManager* tm = this->get_typemanager();
  zstring docUri;
  rootElement->getDocumentURI(docUri);

  if (validationMode != StaticContextConsts::skip_validation)
  {
    store::Item_t validatedNode;
    store::Item_t typeName;
    QueryLoc loc;

    ParseConstants::validation_mode_t mode;
    switch( validationMode )
    {
    case StaticContextConsts::strict_validation:
      mode = ParseConstants::val_strict;
      break;
    case StaticContextConsts::lax_dtd_validation:
      mode = ParseConstants::val_dtd_lax;
      break;
    case StaticContextConsts::lax_validation:
    default:
      mode = ParseConstants::val_lax;
    }

    bool res = Validator::effectiveValidationValue(validatedResult,
                                                   rootElement,
                                                   typeName,
                                                   tm,
                                                   mode,
                                                   this,
                                                   loc);
    return res;

  }
#endif //ZORBA_NO_XMLSCHEMA

  return false;
}


/***************************************************************************//**

********************************************************************************/
bool static_context::validateSimpleContent(
    zstring& stringValue,
    store::Item* typeQName,
    std::vector<store::Item_t>& resultList) const
{
  store::NsBindings bindings;
  this->get_namespace_bindings(bindings);
  store::Item_t lTypeQName(typeQName);

#ifndef ZORBA_NO_XMLSCHEMA
  Validator::processTextValue(
      this,
      this->get_typemanager(),
      bindings,
      lTypeQName,
      stringValue,
      resultList,
      QueryLoc::null);

  return true;
#else
  throw ZORBA_EXCEPTION(err::XQST0009);
  return false;
#endif
}


/////////////////////////////////////////////////////////////////////////////////
//                                                                             //
//  Type Manager                                                               //
//                                                                             //
/////////////////////////////////////////////////////////////////////////////////


/*******************************************************************************

********************************************************************************/
void static_context::set_typemanager(rchandle<TypeManager> typemgr)
{
  theTypeManager = typemgr;
}


TypeManager* static_context::get_typemanager() const
{
  TypeManager* tm = theTypeManager.getp();
  if (tm != NULL)
  {
    return tm;
  }
  return static_cast<static_context *>(theParent)->get_typemanager();
}


TypeManager* static_context::get_local_typemanager() const
{
  return theTypeManager.getp();
}


/////////////////////////////////////////////////////////////////////////////////
//                                                                             //
//  Namespace Bindings                                                         //
//                                                                             //
/////////////////////////////////////////////////////////////////////////////////


/***************************************************************************//**
  Get the default namespace for element and type qnames.
********************************************************************************/
const zstring& static_context::default_elem_type_ns() const
{
  if (theHaveDefaultElementNamespace || theParent == NULL)
  {
    return theDefaultElementNamespace;
  }
  else
  {
    return theParent->default_elem_type_ns();
  }
}


/***************************************************************************//**
  Set the default namespace for element and type qnames to the given namespace.
********************************************************************************/
void static_context::set_default_elem_type_ns(
    const zstring& ns,
    bool raiseError,
    const QueryLoc& loc)
{
  if (!theHaveDefaultElementNamespace)
  {
    theDefaultElementNamespace = ns;
    theHaveDefaultElementNamespace = true;
  }
  else if (raiseError)
  {
    throw XQUERY_EXCEPTION(err::XQST0066, ERROR_LOC(loc));
  }
  else
  {
    theDefaultElementNamespace = ns;
  }
}


/***************************************************************************//**
  Get the default namespace for function qnames.
********************************************************************************/
const zstring& static_context::default_function_ns() const
{
  if (!theDefaultFunctionNamespaces.empty() || theParent == NULL)
  {
    return theDefaultFunctionNamespaces[0];
  }
  else
  {
    return theParent->default_function_ns();
  }
}


/***************************************************************************//**
 Set the default namespace for function qnames to the given namespace.
********************************************************************************/
void static_context::set_default_function_ns(
   const zstring& ns,
   bool raiseError,
   const QueryLoc& loc)
{
  if (theDefaultFunctionNamespaces.empty())
  {
    theDefaultFunctionNamespaces.push_back(ns);
  }
  else if (raiseError)
  {
    throw XQUERY_EXCEPTION(err::XQST0066, ERROR_LOC(loc));
  }
  else
  {
    theDefaultFunctionNamespaces.insert(theDefaultFunctionNamespaces.begin(), ns);
  }
}


/***************************************************************************//**
  Bind the given prefix to the given namaspace uri. The binding is stored in
  "this". If there is already in "this" a binding for the prefix, raise error.
********************************************************************************/
void static_context::bind_ns(
    const zstring& prefix,
    const zstring& ns,
    const QueryLoc& loc)
{
  if (theNamespaceBindings == NULL)
  {
    theNamespaceBindings = new NamespaceBindings(16, false);
  }

  zstring temp(ns);

  if (!theNamespaceBindings->insert(prefix, temp))
  {
    RAISE_ERROR(err::XQST0033, loc, ERROR_PARAMS(prefix, ns));
  }
}


/***************************************************************************//**
  Search the static-context tree, starting from "this" and moving upwards,
  looking for the 1st namespace binding for the given prefix. If no such
  binding is found, either raise an error (if the given error code is not
  ZXQP0000_NO_ERROR) or return false. Otherwise, return true and the
  associated namespace uri.
********************************************************************************/
bool static_context::lookup_ns(
    zstring& ns,
    const zstring& prefix,
    const QueryLoc& loc,
    bool raiseError) const
{
  if (theNamespaceBindings == NULL || !theNamespaceBindings->get(prefix, ns))
  {
    if (theParent != NULL)
    {
      return theParent->lookup_ns(ns, prefix, loc, raiseError);
    }
    else if (raiseError)
    {
      RAISE_ERROR(err::XPST0081, loc, ERROR_PARAMS(prefix));
    }
    else
    {
      return false;
    }
  }
  else if (!prefix.empty() && ns.empty())
  {
    if (raiseError)
    {
      RAISE_ERROR(err::XPST0081, loc, ERROR_PARAMS(prefix));
    }
    else
    {
      return false;
    }
  }

  return true;
}


/***************************************************************************//**
  Convert a [prefix, localName] pair to an expanded QName item, using the given
  default namespace if the prefix is empty. Raise error if the prefix is non-
  empty and there is no associated namespace uri.
********************************************************************************/
void static_context::expand_qname(
    store::Item_t& qname,
    const zstring& default_ns,
    const zstring& prefix,
    const zstring& local,
    const QueryLoc& loc) const
{
  if (prefix.empty())
  {
    ITEM_FACTORY->createQName(qname, default_ns, prefix, local);
  }
  else
  {
    zstring ns;
    lookup_ns(ns, prefix, loc);
    ITEM_FACTORY->createQName(qname, ns, prefix, local);
  }
}


/***************************************************************************//**

********************************************************************************/
void static_context::get_namespace_bindings(store::NsBindings& bindings) const
{
  const static_context* sctx = this;

  while (sctx != NULL)
  {
    if (sctx->theNamespaceBindings != NULL)
    {
      NamespaceBindings::iterator ite = sctx->theNamespaceBindings->begin();
      NamespaceBindings::iterator end = sctx->theNamespaceBindings->end();

      for (; ite != end; ++ite)
      {
        std::pair<zstring, zstring> binding = (*ite);

        // Ignore duplicates
        const zstring& prefix = binding.first;
        ulong numBindings = (ulong)bindings.size();
        bool found = 0;
        for (unsigned int i = 0; i < numBindings; ++i)
        {
          if (bindings[i].first == prefix)
          {
            found = 1;
            break;
          }
        }

        if (!found)
          bindings.push_back(binding);
      }
    }

    sctx = sctx->theParent;
  }
}


/////////////////////////////////////////////////////////////////////////////////
//                                                                             //
//  Variables                                                                  //
//                                                                             //
/////////////////////////////////////////////////////////////////////////////////


/***************************************************************************//**

********************************************************************************/
void static_context::bind_var(var_expr* varExpr, const QueryLoc& loc)
{
  if (theVariablesMap == NULL)
  {
    theVariablesMap = new VariableMap(HashMapItemPointerCmp(0, NULL), 16, false);
  }

  store::Item* qname = varExpr->get_name();

  VarInfo_t vi = varExpr->get_var_info();

  if (vi == NULL)
  {
    vi = new VarInfo(varExpr);

    if (!theVariablesMap->insert(qname, vi))
    {
      goto error;
    }

    if (varExpr->get_kind() == var_expr::prolog_var)
      varExpr->set_var_info(vi);
  }
  else
  {
    if (!theVariablesMap->insert(qname, vi))
    {
      goto error;
    }
  }

  return;

 error:
  switch (varExpr->get_kind())
  {
  case var_expr::let_var:
  {
    RAISE_ERROR(err::XQST0039, loc, ERROR_PARAMS(qname->getStringValue()));
  }
  case var_expr::win_var:
  case var_expr::wincond_out_var:
  case var_expr::wincond_out_pos_var:
  case var_expr::wincond_in_var:
  case var_expr::wincond_in_pos_var:
  {
    RAISE_ERROR(err::XQST0103, loc, ERROR_PARAMS(qname->getStringValue()));
  }
  default:
  {
    RAISE_ERROR(err::XQST0049, loc, ERROR_PARAMS(qname->getStringValue()));
  }
  }
}


/***************************************************************************//**
  Lookup variable by expanded qname. Search starts from the "current" sctx and
  moves upwards the ancestor path until the first instance (if any) of the var
  is found.

  If var is not found, the method raises the given error, unless the given error
  is ZXQP0000_NO_ERROR, in which case it returns NULL.
********************************************************************************/
VarInfo* static_context::lookup_var(const store::Item* qname) const
{
  store::Item* qname2 = const_cast<store::Item*>(qname);

  VarInfo_t var;

  const static_context* sctx = this;

  while (sctx != NULL)
  {
    if (sctx->theVariablesMap != NULL &&
        sctx->theVariablesMap->get(qname2, var))
    {
      return var.getp();
    }

    sctx = sctx->theParent;
  }

  return NULL;
}


/***************************************************************************//**
  This method is used by introspection and debugger
********************************************************************************/
void static_context::getVariables(
    std::vector<VarInfo*>& vars,
    bool localsOnly,
    bool returnPrivateVars,
    bool externalVarsOnly) const
{
  const static_context* sctx = this;

  while (sctx != NULL)
  {
    if (sctx->theVariablesMap != NULL)
    {
      VariableMap::iterator ite = sctx->theVariablesMap->begin();
      VariableMap::iterator end = sctx->theVariablesMap->end();

      for (; ite != end; ++ite)
      {
        csize numVars = vars.size();
        csize i = 0;
        for (; i < numVars; ++i)
        {
          if (vars[i]->getName()->equals((*ite).first))
            break;
        }

        if (i == numVars)
        {
          if (externalVarsOnly)
          {
            if ((*ite).second->isExternal())
              vars.push_back((*ite).second.getp());
          }
          else
          {
            vars.push_back((*ite).second.getp());
          }
        }
      }
    }

    if (returnPrivateVars && sctx->theImportedPrivateVariablesMap != NULL)
    {
      VariableMap::iterator ite = sctx->theImportedPrivateVariablesMap->begin();
      VariableMap::iterator end = sctx->theImportedPrivateVariablesMap->end();

      for (; ite != end; ++ite)
      {
        csize numVars = vars.size();
        csize i = 0;
        for (; i < numVars; ++i)
        {
          if (vars[i]->getName()->equals((*ite).first))
            break;
        }

        if (i == numVars)
        {
          if (externalVarsOnly)
          {
            if((*ite).second->isExternal())
              vars.push_back((*ite).second.getp());
          }
          else
            vars.push_back((*ite).second.getp());
        }
      }
    }

    if (localsOnly)
    {
      break;
    }

    sctx = sctx->theParent;
  }
}


/***************************************************************************//**

********************************************************************************/
void static_context::set_context_item_type(const xqtref_t& t, const QueryLoc& loc)
{
  if (theContextItemType != NULL)
  {
    RAISE_ERROR_NO_PARAMS(err::XQST0099, loc);
  }

  theContextItemType = t;
}


/***************************************************************************//**

********************************************************************************/
const XQType* static_context::get_context_item_type() const
{
  const static_context* sctx = this;
  while (sctx != NULL)
  {
    if (sctx->theContextItemType != NULL)
      return sctx->theContextItemType.getp();

    sctx = sctx->theParent;
  }

  return NULL;
}


/////////////////////////////////////////////////////////////////////////////////
//                                                                             //
//  Functions                                                                  //
//                                                                             //
/////////////////////////////////////////////////////////////////////////////////


/***************************************************************************//**

********************************************************************************/
void static_context::bind_fn(
    const function_t& f,
    csize arity,
    const QueryLoc& loc)
{
  store::Item* qname = f->getName();

  if (!is_global_root_sctx() && lookup_local_fn(qname, arity) != NULL)
  {
    RAISE_ERROR(err::XQST0034, loc, ERROR_PARAMS(qname->getStringValue()));
  }

  if (theFunctionMap == NULL)
  {
    csize size = (is_global_root_sctx() ? 500 : 32);
    theFunctionMap = new FunctionMap(HashMapItemPointerCmp(0, NULL), size, false);
  }

  FunctionInfo fi(f.getp());

  if (!theFunctionMap->insert(qname, fi))
  {
    // There is already a function F with the given qname in theFunctionMap.
    // First, check if F is the same as f, which implies that f is disabled.
    // In this case, re-enable f. Otherwise, we have to use theFunctionArityMap.
    if (fi.theFunction.getp() == f)
    {
      ZORBA_ASSERT(fi.theIsDisabled);
      fi.theIsDisabled = false;
      theFunctionMap->update(qname, fi);
      return;
    }

    fi.theFunction = f;
    fi.theIsDisabled = false;

    ZORBA_ASSERT(!f->isVariadic());

    if (theFunctionArityMap == NULL)
    {
      theFunctionArityMap =
      new FunctionArityMap(HashMapItemPointerCmp(0, NULL), 16, false);
    }

    std::vector<FunctionInfo>* fv = 0;

    if (theFunctionArityMap->get(qname, fv))
    {
      csize numFunctions = fv->size();
      for (csize i = 0; i < numFunctions; ++i)
      {
        if ((*fv)[i].theFunction.getp() == f)
        {
          ZORBA_ASSERT((*fv)[i].theIsDisabled);
          (*fv)[i].theIsDisabled = false;
          return;
        }
      }

      fv->push_back(fi);
    }
    else
    {
      fv = new std::vector<FunctionInfo>(1);
      (*fv)[0] = fi;
      theFunctionArityMap->insert(qname, fv);
    }
  }
}


/***************************************************************************//**
  Remove the function with the given qname and arity from the in-scope functions
  of this sctx.
********************************************************************************/
void static_context::unbind_fn(
    const store::Item* qname,
    csize arity)
{
  ZORBA_ASSERT(!is_global_root_sctx());

  function* f = lookup_fn(qname, arity);

  if (f == NULL)
    return;

  if (theFunctionMap == NULL)
  {
    theFunctionMap = new FunctionMap(HashMapItemPointerCmp(0, NULL), 32, false);
  }

  FunctionInfo fi(f, true);
  store::Item* qname2 = const_cast<store::Item*>(f->getName());

  if (theFunctionMap->get(qname2, fi))
  {
    if (fi.theFunction.getp() == f)
    {
      fi.theIsDisabled = true;
      theFunctionMap->update(qname2, fi);
      return;
    }

    if (theFunctionArityMap == NULL)
    {
      theFunctionArityMap =
      new FunctionArityMap(HashMapItemPointerCmp(0, NULL), 16, false);
    }

    std::vector<FunctionInfo>* fv = NULL;

    if (theFunctionArityMap->get(qname2, fv))
    {
      csize numFunctions = fv->size();
      for (csize i = 0; i < numFunctions; ++i)
      {
        if ((*fv)[i].theFunction.getp() == f)
        {
          (*fv)[i].theIsDisabled = true;
          return;
        }
      }
    }

    fv = new std::vector<FunctionInfo>(1);
    fi.theIsDisabled = true;
    fi.theFunction = f;
    (*fv)[0] = fi;
    theFunctionArityMap->insert(qname2, fv);
  }
  else
  {
    theFunctionMap->insert(qname2, fi);
  }
}


/*******************************************************************************
  Search in the sctx, starting from "this" and moving upwards, for the function
  object for a function with a given prefix local name and arity. Raise error if
  the prefix is non-empty and does not have an associated namespace. Return NULL
  if such a function is not found.
********************************************************************************/
function* static_context::lookup_fn(
    const zstring& ns,
    const zstring& pre,
    const zstring& local,
    csize arity,
    const QueryLoc& loc)
{
  store::Item_t qnameItem;
  std::vector<zstring>::const_iterator ite;
  std::vector<zstring>::const_iterator end;
  function* f = NULL;

  if (!ns.empty())
  {
    ITEM_FACTORY->createQName(qnameItem, ns, "", local);

    f = lookup_fn(qnameItem, arity, true);
  }
  else if (!pre.empty())
  {
    expand_qname(qnameItem, "", pre, local, loc);
    
    f = lookup_fn(qnameItem, arity, true);
  }
  else if (language_kind() == StaticContextConsts::language_kind_jsoniq)
  {
    static_context* sctx = this;

    while (f == NULL && sctx != NULL)
    {
      ite = sctx->theDefaultFunctionNamespaces.begin();
      end = sctx->theDefaultFunctionNamespaces.end();

      for (; f == NULL && ite != end; ++ite)
      {
        ITEM_FACTORY->createQName(qnameItem, *ite, "", local);
        f = lookup_fn(qnameItem, arity, true);
      }

      sctx = sctx->theParent;
    }
  }
  else
  {
    expand_qname(qnameItem, default_function_ns(), pre, local, loc);
    
    f = lookup_fn(qnameItem, arity, true);
  }

  return f;
}


/***************************************************************************//**
  Search the static-context tree, starting from "this" and moving upwards,
  looking for the 1st sctx obj that contains a binding for a function with
  the given qname and arity. If no such binding is found return NULL. Otherwise,
  return the associated function object (which may be NULL if the function
  was disabled).
********************************************************************************/
function* static_context::lookup_fn(
    const store::Item* qname,
    csize arity,
    bool skipDisabled)
{
  FunctionInfo fi;
  store::Item* qname2 = const_cast<store::Item*>(qname);

  static_context* sctx = this;

  while (sctx != NULL)
  {
    if (sctx->theFunctionMap != NULL && sctx->theFunctionMap->get(qname2, fi))
    {
      function* f = fi.theFunction;

      if (f->getArity() == arity || f->isVariadic())
      {
        if (fi.theIsDisabled && skipDisabled)
          return NULL;

        return f;
      }

      std::vector<FunctionInfo>* fv = NULL;

      if (sctx->theFunctionArityMap != NULL &&
          sctx->theFunctionArityMap->get(qname2, fv))
      {
        csize numFunctions = fv->size();
        for (csize i = 0; i < numFunctions; ++i)
        {
          if ((*fv)[i].theFunction->getArity() == arity)
          {
            if ((*fv)[i].theIsDisabled && skipDisabled)
              return NULL;

            return (*fv)[i].theFunction;
          }
        }
      }
    }

    sctx = sctx->theParent;
  }

  return NULL;
}


/***************************************************************************//**
  Search "this" static context a function with the given qname and arity. If no
  such function binding is found return NULL. Otherwise, return the associated
  function object (which may be NULL if the function was disabled).
********************************************************************************/
function* static_context::lookup_local_fn(
    const store::Item* qname,
    csize arity,
    bool skipDisabled)
{
  FunctionInfo fi;
  store::Item* qname2 = const_cast<store::Item*>(qname);

  if (theFunctionMap != NULL && theFunctionMap->get(qname2, fi))
  {
    function* f = fi.theFunction;

    if (f->getArity() == arity || f->isVariadic())
    {
      if (fi.theIsDisabled && skipDisabled)
        return NULL;

      return f;
    }

    std::vector<FunctionInfo>* fv = NULL;

    if (theFunctionArityMap != NULL && theFunctionArityMap->get(qname2, fv))
    {
      csize numFunctions = fv->size();
      for (csize i = 0; i < numFunctions; ++i)
      {
        if ((*fv)[i].theFunction->getArity() == arity)
        {
          if ((*fv)[i].theIsDisabled && skipDisabled)
            return NULL;

          return (*fv)[i].theFunction;
        }
      }
    }
  }

  return NULL;
}


/***************************************************************************//**
  Find all the in-scope and non-disabled functions in this sctx and its ancestors.
********************************************************************************/
void static_context::get_functions(std::vector<function *>& functions) const
{
  std::vector<function*> disabled;
  std::vector<zstring> importedBuiltinModules;

  const static_context* sctx = this;

  while (sctx != NULL)
  {
    if (!sctx->theImportedBuiltinModules.empty())
    {
      std::vector<zstring>::const_iterator ite = sctx->theImportedBuiltinModules.begin();
      std::vector<zstring>::const_iterator end = sctx->theImportedBuiltinModules.end();
      for (; ite != end; ++ite)
      {
        importedBuiltinModules.push_back(*ite);
      }
    }

    if (sctx->theFunctionMap != NULL)
    {
      FunctionMap::iterator ite = sctx->theFunctionMap->begin();
      FunctionMap::iterator end = sctx->theFunctionMap->end();

      for (; ite != end; ++ite)
      {
        function* f = (*ite).second.theFunction;

        if (!(*ite).second.theIsDisabled)
        {
          if (std::find(disabled.begin(), disabled.end(), f) == disabled.end())
          {
            if (f->isBuiltin())
            {
              // Skip builtin functions that (a) are fn functions, or (b) are fn or
              // zorba operators (i.e., non user visible), or (c) their containing
              // module has not been imported.

              assert(sctx->is_global_root_sctx());

              const zstring& ns = f->getName()->getNamespace();

              // if (ns != W3C_FN_NS)
              if ( ! utf8::begins_with(ns, W3C_FN_NS))
              {
                if (ns == XQUERY_OP_NS || ns == ZORBA_OP_NS)
                  continue;

                std::vector<zstring>::const_iterator ite = importedBuiltinModules.begin();
                std::vector<zstring>::const_iterator end = importedBuiltinModules.end();
                for (; ite != end; ++ite)
                {
                  if (ns == *ite)
                    break;
                }

                if (ite == end)
                  continue;
              }
            }
            else
            {
              assert(!sctx->is_global_root_sctx());
            }

            functions.push_back(f);
          }
        }
        else
        {
          disabled.push_back(f);
        }
      }
    }

    if (sctx->theFunctionArityMap != NULL)
    {
      FunctionArityMap::iterator ite = sctx->theFunctionArityMap->begin();
      FunctionArityMap::iterator end = sctx->theFunctionArityMap->end();

      for (; ite != end; ++ite)
      {
        std::vector<FunctionInfo>* fv = (*ite).second;

        csize numFunctions = fv->size();
        for (csize i = 0; i < numFunctions; ++i)
        {
          function* f = (*fv)[i].theFunction;

          if (!(*fv)[i].theIsDisabled)
          {
            if (std::find(disabled.begin(), disabled.end(), f) == disabled.end())
            {
              if (f->isBuiltin())
              {
                assert(sctx->is_global_root_sctx());

                const zstring& ns = f->getName()->getNamespace();

                // if (ns != W3C_FN_NS)
                if ( ! utf8::begins_with(ns, W3C_FN_NS))
                {
                  if (ns == XQUERY_OP_NS || ns == ZORBA_OP_NS)
                    continue;

                  std::vector<zstring>::const_iterator ite = importedBuiltinModules.begin();
                  std::vector<zstring>::const_iterator end = importedBuiltinModules.end();
                  for (; ite != end; ++ite)
                  {
                    if (ns == *ite)
                      break;
                  }

                  if (ite == end)
                    continue;
                }
              }
              else
              {
                assert(!sctx->is_global_root_sctx());
              }

              functions.push_back(f);
            }
          }
          else
          {
            disabled.push_back(f);
          }
        }
      }
    }

    sctx = sctx->theParent;
  }
}


/***************************************************************************//**
  Find all the functions with the given qname.
********************************************************************************/
void static_context::find_functions(
    const store::Item* qname,
    std::vector<function *>& functions) const
{
  FunctionInfo fi;
  store::Item* qname2 = const_cast<store::Item*>(qname);

  if (theFunctionMap != NULL && theFunctionMap->get(qname2, fi))
  {
    if (!fi.theIsDisabled)
      functions.push_back(fi.theFunction);
  }

  std::vector<FunctionInfo>* fv = NULL;

  if (theFunctionArityMap != NULL && theFunctionArityMap->get(qname2, fv))
  {
    csize numFunctions = fv->size();
    for (csize i = 0; i < numFunctions; ++i)
    {
      if (!(*fv)[i].theIsDisabled)
        functions.push_back((*fv)[i].theFunction);
    }
  }

  if (theParent != NULL)
    theParent->find_functions(qname2, functions);
}


/***************************************************************************//**
  Register an external module.  This module can be used to retrieve external
  functions defined in the target namespace of the module.

  If aDynamicallyLoaded is false, then the external module to register has been
  created and is provided directly by the application. Otherwise, it is an
  external module that is created and loaded dynamically by zorba from a lib
  file that is stored somewhere in the in-scope module paths (see
  DynamicLoader::getExternalModule method and how this method is
  invoked by the static_context::lookup_external_function method below).
********************************************************************************/
void static_context::bind_external_module(
    ExternalModule* aModule,
    bool aDynamicallyLoaded)
{
  if (theExternalModulesMap == NULL)
  {
    theExternalModulesMap = new ExternalModuleMap(8, false);
  }

  zstring uri = Unmarshaller::getInternalString(aModule->getURI());
  ctx_module_t modinfo;
  modinfo.module = aModule;
  modinfo.dyn_loaded_module = aDynamicallyLoaded;
  modinfo.theSctx = this;

  if (!theExternalModulesMap->insert(uri, modinfo))
  {
    throw ZORBA_EXCEPTION(
      zerr::ZAPI0019_MODULE_ALREADY_REGISTERED, ERROR_PARAMS( uri )
    );
  }
}


/***************************************************************************//**
  Find and return the implementation of an external function, given its namespace
  URI and local name.
********************************************************************************/
ExternalFunction* static_context::lookup_external_function(
    const zstring& aURI,
    const zstring& aLocalName)
{
  // get the module for the given namespace
  bool found = false;
  ctx_module_t modinfo;
  const static_context* sctx = this;

  while (sctx != NULL)
  {
    if (sctx->theExternalModulesMap != NULL &&
        sctx->theExternalModulesMap->get(aURI, modinfo))
    {
      found = true;
      break;
    }

    sctx = sctx->theParent;
  }

  ExternalModule* lModule = 0;

  // If the module is not yet in the static context we try to get it from the
  // dynamic loader
  if (!found)
  {
    lModule = GENV_DYNAMIC_LOADER->getExternalModule(aURI, *this);

    // no way to get the module
    if (!lModule)
      return NULL;

    // remember the module for future use
    bind_external_module(lModule, true);
  }
  else
  {
    lModule = modinfo.module;
  }

  // get the function from this module.
  // return 0 if not found
  return lModule->getExternalFunction(aLocalName.str());
}


/////////////////////////////////////////////////////////////////////////////////
//                                                                             //
//  Documents                                                                  //
//                                                                             //
/////////////////////////////////////////////////////////////////////////////////


/***************************************************************************//**
  This method may be called only on an application-created sctx.
********************************************************************************/
void static_context::bind_document(const zstring& uri, xqtref_t& type)
{
  if (theDocumentMap == NULL)
  {
    theDocumentMap = new DocumentMap(16, false);
  }

  if (!theDocumentMap->update(uri, type))
  {
    theDocumentMap->insert(uri, type);
  }
}


/***************************************************************************//**

********************************************************************************/
const XQType* static_context::lookup_document(const zstring& uri)
{
  xqtref_t type;

  static_context* sctx = this;
  while (sctx != NULL)
  {
    if (sctx->theDocumentMap && sctx->theDocumentMap->get(uri, type))
      return type.getp();

    sctx = sctx->theParent;
  }

  return NULL;
}

void static_context::get_all_documents(std::vector<zstring>& documents)
{
  static_context* sctx = this;
  documents.clear();

  while (sctx != NULL)
  {
    if (sctx->theDocumentMap != NULL)
    {
      for(DocumentMap::iterator it = sctx->theDocumentMap->begin();
          it != sctx->theDocumentMap->end();
          ++it)
        documents.push_back(it.getKey());
    }

    sctx = sctx->theParent;
  }
}


/////////////////////////////////////////////////////////////////////////////////
//                                                                             //
//  W3C Collections                                                            //
//                                                                             //
/////////////////////////////////////////////////////////////////////////////////


/***************************************************************************//**
  This method may be called only on an application-created sctx.
********************************************************************************/
void static_context::bind_w3c_collection(zstring& uri, xqtref_t& type)
{
  if (theW3CCollectionMap == NULL)
  {
    theW3CCollectionMap = new W3CCollectionMap(16, false);
  }

  if (!theW3CCollectionMap->update(uri, type))
  {
    theW3CCollectionMap->insert(uri, type);
  }
}


/***************************************************************************//**

********************************************************************************/
const XQType* static_context::lookup_w3c_collection(const zstring& uri)
{
  xqtref_t type;

  if (theW3CCollectionMap && theW3CCollectionMap->get(uri, type))
    return type.getp();
  else
    return (theParent == NULL ? 0 : theParent->lookup_w3c_collection(uri));
}


/***************************************************************************//**

********************************************************************************/
void static_context::set_default_w3c_collection_type(xqtref_t& t)
{
  theDefaultW3CCollectionType = t;
}


/***************************************************************************//**

********************************************************************************/
const XQType* static_context::get_default_w3c_collection_type()
{
  static_context* sctx = this;
  while (sctx != NULL)
  {
    if (sctx->theDefaultW3CCollectionType != NULL)
      return sctx->theDefaultW3CCollectionType.getp();

    sctx = sctx->theParent;
  }

  return NULL;
}


/////////////////////////////////////////////////////////////////////////////////
//                                                                             //
//  XQDDF Collections                                                          //
//                                                                             //
/////////////////////////////////////////////////////////////////////////////////


/***************************************************************************//**

********************************************************************************/
void static_context::bind_collection(
    StaticallyKnownCollection_t& aCollection,
    const QueryLoc& aLoc)
{
  if (lookup_collection(aCollection->getName()) != NULL)
  {
    throw XQUERY_EXCEPTION(
      zerr::ZDST0001_COLLECTION_ALREADY_DECLARED,
      ERROR_PARAMS( aCollection->getName()->getStringValue() ),
      ERROR_LOC( aLoc )
    );
  }

  if (theCollectionMap == 0)
    theCollectionMap = new CollectionMap(HashMapItemPointerCmp(0, NULL), 8, false);

  store::Item* qname = const_cast<store::Item*>(aCollection->getName());
  theCollectionMap->insert(qname, aCollection);
}


/***************************************************************************//**

********************************************************************************/
const StaticallyKnownCollection* static_context::lookup_collection(
    const store::Item* qname) const
{
  StaticallyKnownCollection_t lColl;
  store::Item* qname2 = const_cast<store::Item*>(qname);

  if (theCollectionMap && theCollectionMap->get(qname2, lColl))
    return lColl.getp();
  else
    return (theParent == NULL ? 0 : theParent->lookup_collection(qname));
}


/***************************************************************************//**

********************************************************************************/
store::Iterator_t static_context::collection_names() const
{
  return new SctxMapIterator<StaticallyKnownCollection>(
             this,
             &static_context::collection_map);
}


/////////////////////////////////////////////////////////////////////////////////
//                                                                             //
//  XQDDF Indexes                                                              //
//                                                                             //
/////////////////////////////////////////////////////////////////////////////////


/***************************************************************************//**

********************************************************************************/
void static_context::bind_index(IndexDecl_t& index, const QueryLoc& loc)
{
  store::Item* qname = const_cast<store::Item*>(index->getName());

  if (lookup_index(qname) != NULL)
  {
    RAISE_ERROR(zerr::ZDST0021_INDEX_ALREADY_DECLARED, loc,
    ERROR_PARAMS(qname->getStringValue()));
  }

  if (theIndexMap == NULL)
    theIndexMap = new IndexMap(HashMapItemPointerCmp(0, NULL), 8, false);

  theIndexMap->insert(qname, index);
}


/***************************************************************************//**

********************************************************************************/
IndexDecl* static_context::lookup_index(const store::Item* qname) const
{
  IndexDecl_t index;
  store::Item* qname2 = const_cast<store::Item*>(qname);

  if (theIndexMap && theIndexMap->get(qname2, index))
    return index.getp();
  else
    return (theParent == NULL ? NULL : theParent->lookup_index(qname));
}


/*******************************************************************************

********************************************************************************/
store::Iterator_t static_context::index_names() const
{
  return new SctxMapIterator<IndexDecl>(this, &static_context::index_map);
}


/*******************************************************************************

********************************************************************************/
void static_context::get_index_decls(std::vector<IndexDecl*>& decls) const
{
  const static_context* sctx = this;

  while (sctx != NULL)
  {
    if (sctx->theIndexMap)
    {
      IndexMap::iterator ite = sctx->theIndexMap->begin();
      IndexMap::iterator end = sctx->theIndexMap->end();
      
      for (; ite != end; ++ite)
      {
        IndexDecl* decl = ite.getValue().getp();
        decls.push_back(decl);
      }
    }

    sctx = sctx->theParent;
  }
}


/////////////////////////////////////////////////////////////////////////////////
//                                                                             //
//  XQDDF Integrity Constraints                                                //
//                                                                             //
/////////////////////////////////////////////////////////////////////////////////


/***************************************************************************//**

********************************************************************************/
void static_context::bind_ic(
    ValueIC_t& vic,
    const QueryLoc& loc)
{
  store::Item* qname = vic->getICName();

  if (lookup_ic(qname) != NULL)
  {
    throw XQUERY_EXCEPTION(
      zerr::ZDST0041_IC_ALREADY_DECLARED,
      ERROR_PARAMS( qname->getStringValue() ),
      ERROR_LOC( loc )
    );
  }

  if (theICMap == NULL)
    theICMap = new ICMap(HashMapItemPointerCmp(0, NULL), 8, false);

  theICMap->insert(qname, vic);
}


/***************************************************************************//**

********************************************************************************/
ValueIC_t static_context::lookup_ic(const store::Item* qname) const
{
  ValueIC_t vic;
  store::Item* qname2 = const_cast<store::Item*>(qname);

  if (theICMap != NULL && theICMap->get(qname2, vic))
    return vic;
  else
    return (theParent == NULL ? NULL : theParent->lookup_ic(qname));
}


/***************************************************************************//**

********************************************************************************/
store::Iterator_t static_context::ic_names() const
{
  return new SctxMapIterator<ValueIC>(this, &static_context::ic_map);
}


/////////////////////////////////////////////////////////////////////////////////
//                                                                             //
//  Collations                                                                 //
//                                                                             //
/////////////////////////////////////////////////////////////////////////////////


/***************************************************************************//**
  This method may be called only on the the zorba root sctx or an application-
  created sctx.
********************************************************************************/
void static_context::add_collation(const std::string& uri, const QueryLoc& loc)
{
  if (is_known_collation(uri))
    return;

  std::string resolvedURI = resolve_relative_uri(uri).str();

  XQPCollator* collator = CollationFactory::createCollator(resolvedURI);

  if (collator == NULL)
  {
    throw XQUERY_EXCEPTION(err::FOCH0002, ERROR_PARAMS(uri), ERROR_LOC(loc));
  }
  else
  {
    if (theCollationMap == NULL)
      theCollationMap = new CollationMap();

    (*theCollationMap)[resolvedURI] = collator;
  }
}


/***************************************************************************//**

********************************************************************************/
bool static_context::is_known_collation(const std::string& uri) const
{
  std::string resolvedURI = resolve_relative_uri(uri).str();

  const static_context* sctx = this;

  while (sctx != NULL)
  {
    if (sctx->theCollationMap != NULL &&
        sctx->theCollationMap->find(resolvedURI) != sctx->theCollationMap->end())
    {
      return true;
    }

    sctx = sctx->theParent;
  }

  return false;
}


/***************************************************************************//**

********************************************************************************/
XQPCollator* static_context::get_collator(
     const std::string& uri,
     const QueryLoc& loc) const
{
  std::string resolvedURI = resolve_relative_uri(uri).str();

  const static_context* sctx = this;

  while (sctx != NULL)
  {
    if (sctx->theCollationMap != NULL)
    {
      CollationMap::iterator ite = sctx->theCollationMap->find(resolvedURI);

      if (ite != sctx->theCollationMap->end())
      {
        return ite->second;
      }
    }

    sctx = sctx->theParent;
  }

  throw XQUERY_EXCEPTION(err::FOCH0002,
                         ERROR_PARAMS(uri, ZED(NotInStaticCtx)),
                         ERROR_LOC(loc));
}


/***************************************************************************//**

********************************************************************************/
void static_context::set_default_collation(
    const std::string& uri,
    const QueryLoc& loc)
{
  if (theDefaultCollation != NULL || !is_known_collation(uri))
    throw XQUERY_EXCEPTION(err::XQST0038, ERROR_LOC(loc));

  zstring const resolvedUri( resolve_relative_uri(uri) );

  theDefaultCollation = new std::string(resolvedUri.c_str());
}


/***************************************************************************//**

********************************************************************************/
const std::string& static_context::get_default_collation(const QueryLoc& loc) const
{
  const static_context* sctx = this;

  while (sctx != NULL)
  {
    if (sctx->theDefaultCollation != NULL)
    {
      return *sctx->theDefaultCollation;
    }

    sctx = sctx->theParent;
  }

  ZORBA_ASSERT(false);
  return *theDefaultCollation;
}


/***************************************************************************//**

********************************************************************************/
XQPCollator* static_context::get_default_collator(const QueryLoc& loc) const
{
  if (!theCachedDefaultCollator)
  {
    const std::string& default_collation = get_default_collation(loc);
    theCachedDefaultCollator = get_collator(default_collation, loc);
  }
  return theCachedDefaultCollator;
}


/***************************************************************************//**

********************************************************************************/
void static_context::get_collations(std::vector<std::string>& collations) const
{
  const static_context* sctx = this;

  while (sctx != NULL)
  {
    if (theCollationMap != NULL)
    {
      CollationMap::const_iterator ite = theCollationMap->begin();
      CollationMap::const_iterator end = theCollationMap->end();
      for (; ite !=  end; ++ite)
      {
        collations.push_back(ite->first);
      }
    }

    sctx = sctx->theParent;
  }
}


/////////////////////////////////////////////////////////////////////////////////
//                                                                             //
//  Options                                                                    //
//                                                                             //
/////////////////////////////////////////////////////////////////////////////////

/***************************************************************************//**

********************************************************************************/
void static_context::bind_option(
    const store::Item* qname,
    const zstring& value,
    const QueryLoc& loc)
{
  if (theOptionMap == NULL)
  {
    theOptionMap = new OptionMap(HashMapItemPointerCmp(0, NULL), 8, false);
  }

  /*
   * The key of the map is a simple pointer.
   * The lifetime of the qname pointed by the key is managed through a smart
   * pointer which is stored inside the value.
   *
   * When updating the value of an option, we must either update the current key or
   * the smart pointer inside the value.
   */
  store::Item* qname2 = const_cast<store::Item*>(qname);

  OptionMap::iterator lIt = theOptionMap->find(qname2);
  if (lIt != theOptionMap->end())
    qname2 = lIt.getKey();

  PrologOption option(qname2, value);

  process_option(option, lIt, loc);

  // in any case, we bind the option in the static context such that
  // external functions can also access them
  if (lIt != theOptionMap->end())
    theOptionMap->update(qname2, option);
  else
    theOptionMap->insert(qname2, option);
}

void static_context::process_option(
    PrologOption& option,
    const OptionMap::iterator& iterator,
    const QueryLoc& loc)
{
  store::Item* qname = option.theName.getp();

  const zstring& lNamespace = qname->getNamespace();
  const zstring& lLocalName = qname->getLocalName();

  // If option namespace is the XQuery namespace.
  if ( lNamespace == XQUERY_NS )
  {
    if (iterator != theOptionMap->end())
    {
      // if there was already an earlier declaration of the same option, append
      // the value of the current declaration to the value of the earlier decl.
      std::ostringstream lOss;
      lOss << iterator.getValue().theValue << " " << option.theValue;
      option.theValue = lOss.str();
    }
  }

  // If option namespace starts with zorba options namespace
  else if ( lNamespace.find(ZORBA_OPTIONS_NS) == 0 )
  {
    if (lNamespace == ZORBA_OPTION_FEATURE_NS &&
        (lLocalName == "enable" || lLocalName == "disable"))
    {
      zstring lVal1 = option.theValue;
      zstring lVal2;
      bool lCommaFound = false;
      while (ztd::split(lVal1, ",", &lVal1, &lVal2))
      {
        process_feature_option(lVal1, lLocalName == "enable", loc);
        lCommaFound = true;
      }
      process_feature_option(lCommaFound ? lVal2 : lVal1,
          lLocalName == "enable",
          loc);
    }
    else if (lNamespace == ZORBA_OPTION_OPTIM_NS &&
        (lLocalName == "enable" || lLocalName == "disable"))
    {
      zstring lVal1 = option.theValue;
      zstring lVal2;
      bool lCommaFound = false;
      while (ztd::split(lVal1, ",", &lVal1, &lVal2))
      {
        process_optim_option(lVal1, lLocalName == "enable", loc);
        lCommaFound = true;
      }
      process_optim_option(lCommaFound ? lVal2 : lVal1,
          lLocalName == "enable",
          loc);
    }
    else if (lNamespace == ZORBA_OPTION_WARN_NS &&
        (lLocalName == "enable" || lLocalName == "disable" || lLocalName == "error"))
    {
      zstring lVal1 = option.theValue;
      zstring lVal2;
      bool lCommaFound = false;
      while (ztd::split(lVal1, ",", &lVal1, &lVal2))
      {
        process_warning_option(lVal1, lLocalName, loc);
        lCommaFound = true;
      }
      process_warning_option(lCommaFound ? lVal2 : lVal1, lLocalName, loc);
    }

    // process zorba-version option
    else if (lNamespace == ZORBA_VERSIONING_NS &&
        ( lLocalName == ZORBA_OPTION_MODULE_VERSION ||
            lLocalName == ZORBA_OPTION_ZORBA_VERSION ) )
    {
      if ( lLocalName == ZORBA_OPTION_ZORBA_VERSION )
      {
        // Re-use "ModuleVersion" class since it does 98% of the work for us;
        // just use a fake URI
        ModuleVersion lOptVersion(zstring(ZORBA_VERSIONING_NS) + "/corezorba", option.theValue);
        if (! lOptVersion.is_valid_version())
        {
          RAISE_ERROR(zerr::ZXQP0039_INVALID_VERSION_SPECIFICATION, loc,
              ERROR_PARAMS(option.theValue));
        }

        ModuleVersion lZorbaVersion(zstring(ZORBA_VERSIONING_NS) + "/corezorba",
            ZORBA_VERSION);

        if ( ! lZorbaVersion.satisfies(lOptVersion))
        {
          RAISE_ERROR(zerr::ZXQP0038_INAPPROPRIATE_ZORBA_VERSION, loc,
              ERROR_PARAMS(option.theValue, ZORBA_VERSION));
        }
      }
    }

    // If the option is in (starts-with) Zorba's own namespace but not known,
    // we raise an error
    else
    {
      RAISE_ERROR(zerr::ZXQP0060_OPTION_NOT_KNOWN, loc,
          ERROR_PARAMS(lNamespace + ":" + lLocalName));
    }
  }
}


/***************************************************************************//**

********************************************************************************/
store::Item_t static_context::parse_and_expand_qname(
    const zstring& value,
    const char* default_ns,
    const QueryLoc& loc) const
{
  zstring lPrefix;
  zstring lLocalName;

  zstring::size_type n = value.rfind(':');

  if ( n == zstring::npos )
  {
    lLocalName = value;
  }
  else
  {
    lPrefix = value.substr( 0, n );
    lLocalName = value.substr( n+1 );
  }
  store::Item_t lQName;
  expand_qname( lQName, default_ns, lPrefix, lLocalName, loc );

  return lQName;
}


/***************************************************************************//**

********************************************************************************/
void static_context::process_warning_option(
  const zstring& value,
  const zstring& name,
  const QueryLoc& loc)
{
  store::Item_t lQName = parse_and_expand_qname( value, ZORBA_WARN_NS, loc );

  std::vector<store::Item_t>::iterator lIter;

  if (name == "error")
  {
    if ( lQName->getLocalName() == "all" )
    {
      theAllWarningsErrors = true;
      return;
    }
    for ( lIter = theWarningsAreErrors.begin();
          lIter != theWarningsAreErrors.end();
          ++lIter )
    {
      if (lQName->equals((*lIter)))
      {
        return;
      }
    }

    theWarningsAreErrors.push_back( lQName );
  }
  else if ( name == "disable" )
  {
    if ( lQName->getLocalName() == "all" )
    {
      theAllWarningsDisabled = true;
      return;
    }
    for ( lIter = theDisabledWarnings.begin();
          lIter != theDisabledWarnings.end();
          ++lIter )
    {
      if ( lQName->equals( (*lIter) ) )
      {
        return;
      }
    }
    theDisabledWarnings.push_back( lQName );
  }
  else if ( name == "enable" )
  {
    if ( lQName->getLocalName() == "all" )
    {
      theAllWarningsDisabled = false;
      return;
    }
  }
}


/***************************************************************************//**

********************************************************************************/
void static_context::process_feature_option(
    const zstring& value,
    bool enable,
    const QueryLoc& loc)
{
  store::Item_t featureName = parse_and_expand_qname(value, ZORBA_FEATURES_NS, loc);

  if (featureName->getNamespace() != ZORBA_FEATURES_NS)
  {
    RAISE_ERROR(zerr::ZDST0060_FEATURE_NOT_SUPPORTED, loc,
    ERROR_PARAMS(featureName->getStringValue(),
                 ZED(ZDST0060_unknown_namespace),
                 featureName->getNamespace()));
  }

  feature::kind k;
  if (feature::kind_for(featureName->getLocalName().c_str(), k))
  {
    // Special case: the http-uri-resolution feature is ALWAYS set on the
    // root static context, to ensure it is applied system-wide.
    static_context& target = (k != feature::http_resolution) ?
          *this : GENV.getRootStaticContext();
    if (enable)
      target.set_feature(k);
    else
      target.unset_feature(k);
  }
  else
  {
    RAISE_ERROR(zerr::ZDST0060_FEATURE_NOT_SUPPORTED, loc,
    ERROR_PARAMS(featureName->getStringValue(),
                 ZED(ZDST0060_unknown_localname),
                 featureName->getLocalName()));
  }
}


/***************************************************************************//**

********************************************************************************/
void static_context::process_optim_option(
    const zstring& value,
    bool enable,
    const QueryLoc& loc)
{
  if (value != "for-serialization-only")
  {
    RAISE_ERROR(zerr::ZDST0060_FEATURE_NOT_SUPPORTED, loc,
    ERROR_PARAMS(value, ZED(ZDST0060_unknown_localname), value));
  }
}


/***************************************************************************//**

********************************************************************************/
bool static_context::lookup_option(
    const store::Item* qname,
    zstring& value) const
{
  store::Item* qname2 = const_cast<store::Item*>(qname);
  PrologOption option;
  const static_context* sctx = this;
  while (sctx != NULL)
  {
    if (sctx->theOptionMap && sctx->theOptionMap->get(qname2, option))
    {
      value = option.theValue;
      return true;
    }
    sctx = sctx->theParent;
  }

  return false;
}


/////////////////////////////////////////////////////////////////////////////////
//                                                                             //
//  Auditing                                                                   //
//                                                                             //
/////////////////////////////////////////////////////////////////////////////////


/***************************************************************************//**

********************************************************************************/
void static_context::set_audit_event(audit::Event* ae)
{
  theAuditEvent = ae;
}


/***************************************************************************//**

********************************************************************************/
audit::Event* static_context::get_audit_event() const
{
  const static_context* sctx = this;
  audit::Event* res = sctx->theAuditEvent;
  while (res == &zorba::audit::NOP_EVENT_IMPL && sctx != NULL)
  {
    sctx = sctx->theParent;
    if (sctx != NULL) {
      res = sctx->theAuditEvent;
    }
  }
  return res;
}


/////////////////////////////////////////////////////////////////////////////////
//                                                                             //
//  Miscellaneous                                                              //
//                                                                             //
/////////////////////////////////////////////////////////////////////////////////


/***************************************************************************//**

********************************************************************************/
StaticContextConsts::language_kind_t static_context::language_kind() const
{
  const static_context* sctx = this;

  while (sctx != NULL)
  {
    if (sctx->theLanguageKind != StaticContextConsts::language_kind_unknown)
      return sctx->theLanguageKind;

    sctx = sctx->theParent;
  }

  ZORBA_ASSERT(false);
  return StaticContextConsts::language_kind_unknown;
}


/***************************************************************************//**

********************************************************************************/
void static_context::set_language_kind(StaticContextConsts::language_kind_t k)
{
  theLanguageKind = k;
}

/***************************************************************************//**

********************************************************************************/
StaticContextConsts::xquery_version_t static_context::xquery_version() const
{
  const static_context* sctx = this;

  while (sctx != NULL)
  {
    if (sctx->theXQueryVersion != StaticContextConsts::xquery_version_unknown)
      return sctx->theXQueryVersion;

    sctx = sctx->theParent;
  }

  ZORBA_ASSERT(false);
  return StaticContextConsts::xquery_version_unknown;
}


/***************************************************************************//**

********************************************************************************/
void static_context::set_xquery_version(StaticContextConsts::xquery_version_t v)
{
  theXQueryVersion = v;
}


/***************************************************************************//**

********************************************************************************/
StaticContextConsts::jsoniq_version_t static_context::jsoniq_version() const
{
  const static_context* sctx = this;

  while (sctx != NULL)
  {
    if (sctx->theJSONiqVersion != StaticContextConsts::jsoniq_version_unknown)
      return sctx->theJSONiqVersion;

    sctx = sctx->theParent;
  }

  ZORBA_ASSERT(false);
  return StaticContextConsts::jsoniq_version_unknown;
}


/***************************************************************************//**

********************************************************************************/
void static_context::set_jsoniq_version(StaticContextConsts::jsoniq_version_t v)
{
  theJSONiqVersion = v;
}


/***************************************************************************//**

********************************************************************************/
StaticContextConsts::xpath_compatibility_t static_context::xpath_compatibility() const
{
  const static_context* sctx = this;

  while (sctx != NULL)
  {
    if (sctx->theXPathCompatibility != StaticContextConsts::xpath_unknown)
      return sctx->theXPathCompatibility;

    sctx = sctx->theParent;
  }

  ZORBA_ASSERT(false);
  return StaticContextConsts::xpath_unknown;
}


/***************************************************************************//**

********************************************************************************/
void static_context::set_xpath_compatibility(StaticContextConsts::xpath_compatibility_t v)
{
  theXPathCompatibility = v;
}


/***************************************************************************//**

********************************************************************************/
StaticContextConsts::construction_mode_t static_context::construction_mode() const
{
  const static_context* sctx = this;

  while (sctx != NULL)
  {
    if (sctx->theConstructionMode != StaticContextConsts::cons_unknown)
      return sctx->theConstructionMode;

    sctx = sctx->theParent;
  }

  ZORBA_ASSERT(false);
  return StaticContextConsts::cons_unknown;
}


/***************************************************************************//**

********************************************************************************/
void static_context::set_construction_mode(StaticContextConsts::construction_mode_t v)
{
  theConstructionMode = v;
}


/***************************************************************************//**

********************************************************************************/
bool static_context::inherit_ns() const
{
  return theInheritNamespaces;
}


/***************************************************************************//**

********************************************************************************/
void static_context::set_inherit_ns(bool v)
{
  theInheritNamespaces = v;
}


/***************************************************************************//**

********************************************************************************/
bool static_context::preserve_ns() const
{
  return thePreserveNamespaces;
}


/***************************************************************************//**

********************************************************************************/
void static_context::set_preserve_ns(bool v)
{
  thePreserveNamespaces = v;
}


/***************************************************************************//**

********************************************************************************/
StaticContextConsts::ordering_mode_t static_context::ordering_mode() const
{
  const static_context* sctx = this;

  while (sctx != NULL)
  {
    if (sctx->theOrderingMode != StaticContextConsts::ordering_unknown)
      return sctx->theOrderingMode;

    sctx = sctx->theParent;
  }

  ZORBA_ASSERT(false);
  return StaticContextConsts::ordering_unknown;
}


/***************************************************************************//**

********************************************************************************/
bool static_context::is_in_ordered_mode() const
{
  return ordering_mode() == StaticContextConsts::ordered;
}


/***************************************************************************//**

********************************************************************************/
void static_context::set_ordering_mode(StaticContextConsts::ordering_mode_t v)
{
  theOrderingMode = v;
}


/***************************************************************************//**

********************************************************************************/
StaticContextConsts::empty_order_mode_t static_context::empty_order_mode() const
{
  const static_context* sctx = this;

  while (sctx != NULL)
  {
    if (sctx->theEmptyOrderMode != StaticContextConsts::empty_order_unknown)
      return sctx->theEmptyOrderMode;

    sctx = sctx->theParent;
  }

  ZORBA_ASSERT(false);
  return StaticContextConsts::empty_order_unknown;
}


/***************************************************************************//**

********************************************************************************/
void static_context::set_empty_order_mode(StaticContextConsts::empty_order_mode_t v)
{
  theEmptyOrderMode = v;
}


/***************************************************************************//**

********************************************************************************/
StaticContextConsts::boundary_space_mode_t static_context::boundary_space_mode() const
{
  const static_context* sctx = this;

  while (sctx != NULL)
  {
    if (sctx->theBoundarySpaceMode != StaticContextConsts::boundary_space_unknown)
      return sctx->theBoundarySpaceMode;

    sctx = sctx->theParent;
  }

  ZORBA_ASSERT(false);
  return StaticContextConsts::boundary_space_unknown;
}


/***************************************************************************//**

********************************************************************************/
void static_context::set_boundary_space_mode(StaticContextConsts::boundary_space_mode_t v)
{
  theBoundarySpaceMode = v;
}


/***************************************************************************//**

********************************************************************************/
StaticContextConsts::validation_mode_t static_context::validation_mode() const
{
  const static_context* sctx = this;

  while (sctx != NULL)
  {
    if (sctx->theValidationMode != StaticContextConsts::validation_unknown)
      return sctx->theValidationMode;

    sctx = sctx->theParent;
  }

  ZORBA_ASSERT(false);
  return StaticContextConsts::validation_unknown;
}


/***************************************************************************//**

********************************************************************************/
void static_context::set_validation_mode(StaticContextConsts::validation_mode_t v)
{
  theValidationMode = v;
}


/***************************************************************************//**

********************************************************************************/
void static_context::add_decimal_format(
    const DecimalFormat_t& decimalFormat,
    const QueryLoc& loc)
{
  if (!theDecimalFormats.empty())
  {
    csize num = theDecimalFormats.size();
    for (csize i = 0; i < num; ++i)
    {
      const DecimalFormat_t& format = theDecimalFormats[i];

      if (decimalFormat->isDefault() && format->isDefault())
      {
        RAISE_ERROR(err::XQST0111, loc,
        ERROR_PARAMS(ZED(TwoDefaultDecimalFormats)));
      }

      if (!format->isDefault() &&
          !decimalFormat->isDefault() &&
          format->getName()->equals(decimalFormat->getName()))
      {
        RAISE_ERROR(err::XQST0111, loc,
        ERROR_PARAMS(ZED(TwoDecimalFormatsSameName_2),
                     format->getName()->getStringValue()));
      }
    }
  }

  theDecimalFormats.push_back(decimalFormat);
}


/***************************************************************************//**

********************************************************************************/
DecimalFormat_t static_context::get_decimal_format(const store::Item_t& qname)
{
  if (!theDecimalFormats.empty())
  {
    csize num = theDecimalFormats.size();

    for (csize i = 0; i < num; ++i)
    {
      const DecimalFormat_t& format = theDecimalFormats[i];

      if ((qname == NULL && format->isDefault()) ||
          (qname != NULL && !format->isDefault() && format->getName()->equals(qname)))
      {
        return format;
      }
    }
  }

  return (theParent == NULL ? NULL : theParent->get_decimal_format(qname));
}

/***************************************************************************//**

********************************************************************************/
uint32_t static_context::create_temporary_index_id()
{
  static_context* lSctx = this;

  while (lSctx->theParent)
    lSctx = lSctx->theParent;

  return lSctx->theTempIndexCounter++;
}


/////////////////////////////////////////////////////////////////////////////////
//                                                                             //
//  Warnings                                                                   //
//                                                                             //
/////////////////////////////////////////////////////////////////////////////////

/*******************************************************************************

********************************************************************************/
void static_context::disableWarning(store::Item_t qname)
{
  for (unsigned int i=0; i<theDisabledWarnings.size(); i++)
    if (qname->equals(theDisabledWarnings[i]))
      return;

  theDisabledWarnings.push_back(qname);
}

/*******************************************************************************

********************************************************************************/
void static_context::disableAllWarnings()
{
  theAllWarningsDisabled = true;
}

/*******************************************************************************

********************************************************************************/
void static_context::setWarningAsError(store::Item_t qname)
{
  for (unsigned int i=0; i<theWarningsAreErrors.size(); i++)
    if (theWarningsAreErrors[i] )
      return;

  theWarningsAreErrors.push_back(qname);
}

/*******************************************************************************

********************************************************************************/
bool static_context::isWarningDisabled(const char* ns, const char* localname)
{
  for (unsigned int i=0; i<theDisabledWarnings.size(); i++)
  {
    if ( theDisabledWarnings[i]->getNamespace() == ns &&
         theDisabledWarnings[i]->getLocalName() == localname )
      return true;
  }

  if (theAllWarningsDisabled)
  {
    return true;
  }

  return (theParent == NULL ? false : theParent->isWarningDisabled(ns, localname));
}

/*******************************************************************************

********************************************************************************/
bool static_context::isWarningAnError(const char* ns, const char* localname)
{
  for (unsigned int i=0; i<theWarningsAreErrors.size(); i++)
  {
    if (theWarningsAreErrors[i]->getNamespace() == ns &&
        theWarningsAreErrors[i]->getLocalName() == localname)
      return true;
  }
  if ( theAllWarningsErrors )
  {
    return true;
  }

  return (theParent == NULL ? false : theParent->isWarningAnError(ns, localname));
}


/////////////////////////////////////////////////////////////////////////////////
//                                                                             //
//  Module Import                                                              //
//                                                                             //
/////////////////////////////////////////////////////////////////////////////////


/***************************************************************************//**
  Merge the static context of a module with this static context. Only functions
  and variables defined in the module are included in this static context.
********************************************************************************/
void static_context::import_module(const static_context* module, const QueryLoc& loc)
{
  if (module->theVariablesMap)
  {
    if (theVariablesMap == NULL)
    {
      theVariablesMap = new VariableMap(HashMapItemPointerCmp(0, NULL),
                                        module->theVariablesMap->capacity(),
                                        false);
    }

    VariableMap::iterator ite = module->theVariablesMap->begin();
    VariableMap::iterator end = module->theVariablesMap->end();
    for (; ite != end; ++ite)
    {
      var_expr* ve = (*ite).second->getVar();

      if (!ve->is_private())
      {
        bind_var(ve, loc);
      }
      else
      {
        if (theImportedPrivateVariablesMap == NULL)
        {
          theImportedPrivateVariablesMap =
          new VariableMap(HashMapItemPointerCmp(0, NULL), 8, false);
        }

        VarInfo_t vi = ve->get_var_info();

        assert (vi != NULL);

        if (!theImportedPrivateVariablesMap->insert(ve->get_name(), vi))
        {
          RAISE_ERROR(err::XQST0049, loc,
          ERROR_PARAMS(ve->get_name()->getStringValue()));
        }
      }
    }
  }

  if (module->theFunctionMap)
  {
    if (theFunctionMap == NULL)
    {
      theFunctionMap = new FunctionMap(HashMapItemPointerCmp(0, NULL),
                                       (ulong)module->theFunctionMap->capacity(),
                                       false);
    }

    FunctionMap::iterator ite = module->theFunctionMap->begin();
    FunctionMap::iterator end = module->theFunctionMap->end();
    for (; ite != end; ++ite)
    {
      function* f = (*ite).second.theFunction;
      if (!f->isPrivate())
        bind_fn(f, f->getArity(), loc);
    }
  }

  if (module->theFunctionArityMap)
  {
    if (theFunctionArityMap == NULL)
    {
      theFunctionArityMap =
      new FunctionArityMap(HashMapItemPointerCmp(0, NULL),
                           (ulong)module->theFunctionArityMap->capacity(),
                           false);
    }

    FunctionArityMap::iterator ite = module->theFunctionArityMap->begin();
    FunctionArityMap::iterator end = module->theFunctionArityMap->end();
    for (; ite != end; ++ite)
    {
      std::vector<FunctionInfo>* fv = (*ite).second;
      csize num = fv->size();
      for (csize i = 0; i < num; ++i)
      {
        function* f = (*fv)[i].theFunction;
        bind_fn(f, f->getArity(), loc);
      }
    }
  }

  if (module->theCollectionMap)
  {
    if (theCollectionMap == 0)
      theCollectionMap = new CollectionMap(HashMapItemPointerCmp(0, 0), 8, false);

    CollectionMap::iterator coll_iter = module->theCollectionMap->begin();
    CollectionMap::iterator coll_end = module->theCollectionMap->end();
    for (; coll_iter != coll_end; ++ coll_iter)
    {
      std::pair<store::Item*, StaticallyKnownCollection_t > pair = (*coll_iter);

      if (!theCollectionMap->insert(pair.first, pair.second))
      {
        RAISE_ERROR(zerr::ZDST0002_COLLECTION_ALREADY_IMPORTED, loc,
        ERROR_PARAMS(pair.second->getName()->getStringValue(),
                     module->get_module_namespace()));
      }
    }
  }

  if (module->theIndexMap)
  {
    if (theIndexMap == NULL)
      theIndexMap = new IndexMap(HashMapItemPointerCmp(0, NULL), 8, false);

    IndexMap::iterator idx_iter = module->theIndexMap->begin();
    IndexMap::iterator idx_end = module->theIndexMap->end();
    for (; idx_iter != idx_end; ++idx_iter)
    {
      std::pair<store::Item*, rchandle<IndexDecl> > pair = (*idx_iter);

      if (lookup_index(pair.first) != NULL)
      {
        RAISE_ERROR(zerr::ZDST0022_INDEX_ALREADY_IMPORTED, loc,
        ERROR_PARAMS(pair.first->getStringValue(), module->get_module_namespace()));
      }

      if (!theIndexMap->insert(pair.first, pair.second))
      {
        ZORBA_ASSERT(false);
      }
    }
  }

  if (module->theICMap)
  {
    if (theICMap == NULL)
    {
      theICMap = new ICMap(HashMapItemPointerCmp(0, NULL), 8, false);
    }

    ICMap::iterator ic_iter = module->theICMap->begin();
    ICMap::iterator ic_end = module->theICMap->end();
    for (; ic_iter != ic_end; ++ic_iter)
    {
      std::pair<store::Item*, rchandle<ValueIC> > pair = (*ic_iter);

      if (!theICMap->insert(pair.first, pair.second))
      {
        RAISE_ERROR(zerr::ZDST0041_IC_ALREADY_DECLARED, loc,
        ERROR_PARAMS(pair.first->getStringValue()));
      }
    }
  }
}

/***************************************************************************//**

********************************************************************************/
void static_context::clear_base_uri()
{
  if (theBaseUriInfo)
    delete theBaseUriInfo;

    theBaseUriInfo = new BaseUriInfo;
}

/***************************************************************************//**

********************************************************************************/
#ifndef NDEBUG
std::string static_context::toString()
{
  std::stringstream ss;

  ss << "static_context: " << this;
  static_context* parent = theParent;
  while (parent != NULL)
  {
    ss << " -> " << parent;
    parent = parent->theParent;
  }
  ss << std::endl;

  std::vector<VarInfo*> vars;
  getVariables(vars, false, false, false);
  for (csize i=0; i < vars.size(); i++)
  {
    ss << "    var[" << i << "]: " << vars[i]->getName()->show() << " (" << std::hex << vars[i]->getVar() << ")";
    ss << " " << var_expr::decode_var_kind((var_expr::var_kind)vars[i]->getKind()) << " id: " << vars[i]->getId();
    // ss << " from sctx: " << this;
    ss << std::endl;
  }

  return ss.str();
}
#endif


} // namespace zorba
/* vim:set et sw=2 ts=2: */
