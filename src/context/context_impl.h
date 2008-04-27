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
#define DECL_ENUM_PARAM( class, name )                                  \
  StaticContextConsts::name##_t class::name () const {                  \
    ctx_value_t val;                                                    \
    bool found = context_value ("int:" #name, val);                     \
    assert (found);                                                     \
    return (StaticContextConsts::name##_t) val.intValue;                \
  }                                                                     \
                                                                        \
  void class::set_##name (StaticContextConsts::name##_t x) {            \
    class::ctx_value_t val;                                             \
    val.intValue = (int) x;                                             \
    keymap.put ("int:" #name, val);                                     \
  }


#define DECL_STR_PARAM( class, name, err )                     \
  xqp_string class::name () const {                            \
    xqp_string val;                                            \
    bool found = context_value ("int:" #name, val);            \
    assert (found);                                            \
    return val;                                                \
  }                                                            \
                                                               \
  void class::set_##name (xqp_string val) {                    \
    bind_str ("int:" #name, val, ZorbaError::err);             \
  }

/*
 * Local variables:
 * mode: c++
 * End:
 */
