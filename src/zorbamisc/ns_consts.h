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
#define XQUERY_FN_NS  "http://www.w3.org/2005/xpath-functions"
#define XQUERY_OP_NS  "http://www.w3.org/2005/xpath-functions"
#define XML_NS "http://www.w3.org/XML/1998/namespace"
#define XML_SCHEMA_NS "http://www.w3.org/2001/XMLSchema"
#define XSI_NS "http://www.w3.org/2001/XMLSchema-instance"
#define XQUERY_LOCAL_FN_NS "http://www.w3.org/2005/xquery-local-functions"
#define XQUERY_ERR_NS  "http://www.w3.org/2005/xqt-errors"

#define ZORBA_FN_NS  "http://www.zorba-xquery.com/zorba/internal-functions"
#define ZORBA_REST_FN_NS "http://www.zorba-xquery.com/zorba/rest-functions"
#define ZORBA_MATH_FN_NS "http://www.zorba-xquery.com/zorba/math-functions"
#define ZORBA_NODEREF_FN_NS "http://www.zorba-xquery.com/zorba/node-ref-functions"
#define ZORBA_COLLECTION_FN_NS "http://www.zorba-xquery.com/zorba/collection-functions"

#define ZORBA_COLLATION_NS_BASE "http://www.zorba-xquery.com/zorba/collations/"
#define ZORBA_DEF_COLLATION_NS ZORBA_COLLATION_NS_BASE "IDENTICAL/en/US"
#define W3C_CODEPT_COLLATION_NS "http://www.w3.org/2005/xpath-functions/collation/codepoint"

#endif
/*
 * Local variables:
 * mode: c++
 * End:
 */
