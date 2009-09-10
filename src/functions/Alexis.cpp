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
#include <vector>

#include "functions/function_impl.h"
#include "functions/Alexis.h"

#include "runtime/util/UtilImpl.h"
#include "runtime/misc/MiscImpl.h"

using namespace std;

namespace zorba 
{

typedef function_impl<ZorbaBase64DecodeIterator> zorba_decode_base64;


typedef function_impl<ZorbaBase64EncodeIterator> zorba_encode_base64;


typedef function_impl<ZorbaSchemaTypeIterator> zorba_schema_type;


#ifdef ZORBA_WITH_TIDY

typedef function_impl<ZorbaTidyIterator> zorba_tidy;


typedef function_impl<ZorbaTDocIterator> zorba_tdoc;

#endif/* ZORBA_WITH_TIDY */


class zorba_random : public function
{
public:
  zorba_random(const signature& sig): function(sig){}
    
  bool isPureFunction () const { return false; }

  DEFAULT_NARY_CODEGEN(ZorbaRandomIterator);
};


class zorba_uuid : public function
{
public:
  zorba_uuid(const signature& sig): function(sig){}
    
  bool isPureFunction () const { return false; }

  DEFAULT_NARY_CODEGEN(ZorbaUUIDIterator);
};


class zorba_timestamp : public function
{
public:
  zorba_timestamp(const signature& sig) : function(sig) {}

  bool requires_dyn_ctx () const { return true; }

  DEFAULT_NARY_CODEGEN(ZorbaTimestampIterator);
};


class zorba_serialize_to_string : public function 
{
public:
  zorba_serialize_to_string(const signature& sig) : function(sig) {}

  bool isPureFunction () const { return false; }

  PlanIter_t codegen(CompilerCB*,
                     static_context* sctx,
                     const QueryLoc& loc,
                     std::vector<PlanIter_t>& argv,
                     AnnotationHolder &) const
  {
    return new FnPrintIterator (sctx, loc, argv, false);
  }
};



void populateContext_Alexis(static_context* sctx)
{
DECL(sctx, zorba_decode_base64,
     (createQName(ZORBA_ALEXIS_FN_NS, "fn-zorba-util", "base64Decode"),
      GENV_TYPESYSTEM.BASE64BINARY_TYPE_ONE,
      GENV_TYPESYSTEM.STRING_TYPE_ONE));

DECL(sctx, zorba_encode_base64,
     (createQName(ZORBA_ALEXIS_FN_NS, "fn-zorba-util", "base64Encode"),
      GENV_TYPESYSTEM.ITEM_TYPE_ONE,
      GENV_TYPESYSTEM.BASE64BINARY_TYPE_ONE));

DECL(sctx, zorba_schema_type,
     (createQName(ZORBA_ALEXIS_FN_NS, "fn-zorba-util", "schema-type"),
      GENV_TYPESYSTEM.ITEM_TYPE_ONE,
      GENV_TYPESYSTEM.QNAME_TYPE_ONE));

#ifdef ZORBA_WITH_TIDY
  DECL(sctx, zorba_tidy,
       (createQName(ZORBA_ALEXIS_FN_NS, "fn-zorba-util", "tidy"),
        GENV_TYPESYSTEM.STRING_TYPE_ONE,
        GENV_TYPESYSTEM.ITEM_TYPE_ONE));

  DECL(sctx, zorba_tidy,
       (createQName(ZORBA_ALEXIS_FN_NS, "fn-zorba-util", "tidy"),
        GENV_TYPESYSTEM.STRING_TYPE_ONE,
        GENV_TYPESYSTEM.STRING_TYPE_QUESTION,
        GENV_TYPESYSTEM.ITEM_TYPE_ONE));

  DECL(sctx, zorba_tdoc,
       (createQName(ZORBA_ALEXIS_FN_NS, "fn-zorba-util", "tdoc"),
        GENV_TYPESYSTEM.STRING_TYPE_QUESTION,
        GENV_TYPESYSTEM.DOCUMENT_TYPE_QUESTION));

  DECL(sctx, zorba_tdoc,
       (createQName(ZORBA_ALEXIS_FN_NS, "fn-zorba-util", "tdoc"),
        GENV_TYPESYSTEM.STRING_TYPE_ONE,
        GENV_TYPESYSTEM.STRING_TYPE_QUESTION,
        GENV_TYPESYSTEM.DOCUMENT_TYPE_QUESTION));
#endif

  DECL(sctx, zorba_random,
       (createQName(ZORBA_ALEXIS_FN_NS, "fn-zorba-util", "random"),
        GENV_TYPESYSTEM.INTEGER_TYPE_ONE));

  DECL(sctx, zorba_random,
       (createQName(ZORBA_ALEXIS_FN_NS, "fn-zorba-util", "random"),
        GENV_TYPESYSTEM.INTEGER_TYPE_ONE,
        GENV_TYPESYSTEM.INTEGER_TYPE_ONE));

  DECL(sctx, zorba_uuid,
       (createQName(ZORBA_ALEXIS_FN_NS, "fn-zorba-util", "uuid"),
        GENV_TYPESYSTEM.STRING_TYPE_ONE));

  DECL(sctx, zorba_timestamp,
       (createQName(ZORBA_ALEXIS_FN_NS, "fn-zorba-util", "timestamp"),
        GENV_TYPESYSTEM.LONG_TYPE_ONE));

  DECL (sctx, zorba_serialize_to_string,
        (createQName(ZORBA_ALEXIS_FN_NS, "fn-zorba-util", "serialize-to-string"),
         GENV_TYPESYSTEM.ITEM_TYPE_STAR,
         GENV_TYPESYSTEM.STRING_TYPE_ONE));
}


}
/* vim:set ts=2 sw=2: */
