#define DECL_ENUM_PARAM( class, name )                                  \
  StaticQueryContext::name##_t class::name () const {                                \
    ctx_value_t val;                                                    \
    bool found = context_value ("int:" #name, val);                     \
    assert (found);                                                     \
    return (StaticQueryContext::name##_t) val.intValue;                              \
  }                                                                     \
  void class::set_##name (StaticQueryContext::name##_t x) {                          \
    class::ctx_value_t val;                                             \
    val.intValue = (int) x;                                             \
    keymap.put ("int:" #name, val);                                     \
  }

#define DECL_STR_PARAM( class, name )                  \
  xqpString class::name () const {                        \
    xqpString val;                                        \
    bool found = context_value ("int:" #name, val);    \
    assert (found);                                    \
    return val;                                        \
  }                                                    \
  void class::set_##name (xqpString val) {                \
    str_keymap.put ("int:" #name, val);                \
  }

/*
 * Local variables:
 * mode: c++
 * End:
 */
