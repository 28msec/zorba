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
#ifndef ZORBA_NS_CONSTS_H
#define ZORBA_NS_CONSTS_H

// TODO make these static members of the context
#define XML_NS "http://www.w3.org/XML/1998/namespace"
#define XMLNS_NS "http://www.w3.org/2000/xmlns/"
#define XML_SCHEMA_NS "http://www.w3.org/2001/XMLSchema"
#define XSI_NS "http://www.w3.org/2001/XMLSchema-instance"
#define XQUERY_ERR_NS  "http://www.w3.org/2005/xqt-errors"

#define XQUERY_FN_NS  "http://www.w3.org/2005/xpath-functions"
#define XQUERY_LOCAL_FN_NS "http://www.w3.org/2005/xquery-local-functions"

//
// Namespaces of external modules implementing zorba builtin functions
//
#define ZORBA_MATH_FN_NS            "http://www.zorba-xquery.com/modules/math"
#define ZORBA_BASE64_FN_NS          "http://www.zorba-xquery.com/modules/base64"
#define ZORBA_NODEREF_FN_NS         "http://www.zorba-xquery.com/modules/node-reference"
#define ZORBA_XQDDF_FN_NS           "http://www.zorba-xquery.com/modules/xqddf"
#define ZORBA_SCHEMA_FN_NS          "http://www.zorba-xquery.com/modules/schema"
#define ZORBA_TIDY_FN_NS            "http://www.zorba-xquery.com/modules/tidy"
#define ZORBA_JSON_FN_NS            "http://www.zorba-xquery.com/modules/json"
#define ZORBA_CSV_FN_NS             "http://www.zorba-xquery.com/modules/csv2xml"
#define ZORBA_XQDOC_FN_NS           "http://www.zorba-xquery.com/modules/xqdoc"
#define ZORBA_RANDOM_FN_NS          "http://www.zorba-xquery.com/modules/random"
#define ZORBA_INTROSPECT_DCTX_FN_NS "http://www.zorba-xquery.com/modules/introspection/dctx"
#define ZORBA_INTROSPECT_SCTX_FN_NS "http://www.zorba-xquery.com/modules/introspection/sctx"

//
// Namespaces of virtual modules implementing zorba builtin functions
//
#define ZORBA_UTIL_FN_NS        "http://www.zorba-xquery.com/zorba/util-functions"
#define ZORBA_FOP_FN_NS         "http://www.zorba-xquery.com/zorba/fop-functions"


//
// Namespaces of virtual modules implementing internal functions of XQUERY or zorba
// Internal functions are not visible to xquery programs.
//
#define XQUERY_OP_NS            "http://www.zorba-xquery.com/xquery/internal-functions"
#define ZORBA_OP_NS             "http://www.zorba-xquery.com/zorba/internal-functions"

//
//
//
#define ZORBA_COLLATION_NS_BASE "http://www.zorba-xquery.com/zorba/collations/"
#define ZORBA_DEF_COLLATION_NS ZORBA_COLLATION_NS_BASE "IDENTICAL/en/US"
#define W3C_CODEPT_COLLATION_NS "http://www.w3.org/2005/xpath-functions/collation/codepoint"

#endif
/*
 * Local variables:
 * mode: c++
 * End:
 */
