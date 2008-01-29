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

#define DECL_STR_PARAM( class, name, err )                     \
  xqp_string class::name () const {                            \
    xqp_string val;                                            \
    bool found = context_value ("int:" #name, val);            \
    assert (found);                                            \
    return val;                                                \
  }                                                            \
  void class::set_##name (xqp_string val) {                    \
    bind_str ("int:" #name, val, ZorbaError::err);             \
  }

/*
 * Local variables:
 * mode: c++
 * End:
 */
