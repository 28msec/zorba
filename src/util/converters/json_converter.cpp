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

#include "util/converters/json_converter.h"

#include "json/parser.h"
#include "json/value.h"

#include "system/globalenv.h"
#include "context/namespace_context.h"

namespace zorba {

  bool JSON_parse(const char* json_string, store::Item_t& element, xqpStringStore_t baseUri, xqp_string& error_log)
  {
    store::Item_t qname, type_qname;
    xqpStringStore_t tname = new xqpStringStore("untyped");
    xqpStringStore_t name = new xqpStringStore("json");

    xqpString xs_ns = "http://www.w3.org/2001/XMLSchema";
    xqpString xs_pre = "xs";
    GENV_ITEMFACTORY->createQName(type_qname, xs_ns.theStrStore, xs_pre.theStrStore, tname);


    xqpString ns = ZORBA_JSON_FN_NS;
    xqpString pre = "zorba-json";
    GENV_ITEMFACTORY->createQName(qname, ns.getStore(), pre.getStore(), name);

    store::NsBindings bindings;
    GENV_ITEMFACTORY->createElementNode(element,
                                        NULL,
                                        -1,
                                        qname,
                                        type_qname,
                                        true,
                                        false,
                                        false,
                                        false,
                                        bindings,
                                        baseUri,
                                        true);
    return true;
  }

  bool JSON_serialize(store::Item_t element, xqpStringStore_t& json_string, xqp_string& error_log)
  {
    json_string = new xqpStringStore("NOT implemented yet");
    return true;
  }
} /*namespace Zorba */
