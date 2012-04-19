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
 
#ifdef STDAFX

  #include <fstream>
  #include <iostream>
  #include <stdexcept>
  #include <cassert>
  #include <cstring>
  #include <memory>

  #include <sstream>
  #include <xfwrap>
  #include <xfwrap1>
  #include <istream>
  #include <cstdio>
  #include <xxshared>
  #include <crtdefs.h>
  #include <map>
  #include <set>

  #include "runtime/sequences/sequences.h"
  #include "diagnostics/xquery_diagnostics.h"
  #include "xercesc/util/xercesdefs.hpp"
  #include "runtime/collections/collections.h"
  #include "unicode/utypes.h"
  #include "zorba/config.h"
  #include "store/api/store.h"
  #include "zorba/zorba.h"
  #include "zorba/api_shared_types.h"
  #include "compiler/parsetree/parsenodes.h"
  #include "compiler/parser/parse_constants.h"
  #include "zorbautils/checked_vector.h"
  #include "compiler/parser/xquery_driver.h"
  #include "util/sorter.h"
  #include "compiler/xqueryx/xqueryx_to_xquery.h"
  #include <zorba/store_manager.h>
  #include <zorba/xquery.h>
  #include <zorba/xquery_exception.h>
  #include "util/cxx_util.h"
  #include "diagnostics/assert.h"
  #include "zorbatypes/mapm/m_apm_lc.h"
  #include "zorbatypes/datetime/parse.h"
  #include "zorbatypes/chartype.h"
  #include "zorbatypes/collation_manager.h"
  #include "zorbatypes/ft_token.h"
  #include "zorbatypes/m_apm.h"
  #include "zorbatypes/rclock.h"
  #include "zorbatypes/schema_types.h"
  #include "zorbatypes/timezone.h"
  #include "zorbatypes/transcoder.h"
  #include "zorbatypes/URI.h"
  #include "zorbatypes/xerces_xmlcharray.h"
  #include "zorbatypes/zorbatypes_decl.h"
  #include "zorbatypes/zstring.h"
  #include "zorbautils/condition.h"
  #include "zorbautils/hashfun.h"
  #include "zorbautils/hashmap.h"
  #include "zorbautils/hashmap_itemp.h"
  #include "zorbautils/hashmap_str_obj.h"
  #include "zorbautils/hashmap_zstring.h"
  #include "zorbautils/hashset.h"
  #include "zorbautils/hashset_itemh.h"
  #include "zorbautils/latch.h"
  #include "zorbautils/locale.h"
  #include "zorbautils/lock.h"
  #include "zorbautils/mutex.h"
  #include "zorbautils/runnable.h"
  #include "zorbautils/SAXParser.h"
  #include "zorbautils/stack.h"
  #include "zorbautils/string_util.h"
  #include "unit_tests/unit_test_list.h"
  #include "zorba/diagnostic_handler.h"
  #include "zorba/xquery_warning.h"
  #include "runtime/full_text/ftcontains_visitor.h"
  #include "store/api/ft_token_iterator.h"
  #include "store/naive/ft_token_store.h"

#endif
/* vim:set et sw=2 ts=2: */
