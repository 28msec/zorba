#define DECL_ENUM_PARAM( class, name )                                  \
  class::name##_t class::name () const {                                \
    ctx_value_t val;                                                    \
    bool found = context_value ("int:" #name, val);                     \
    assert (found);                                                     \
    return (class::name##_t) val.intValue;                              \
  }                                                                     \
  void class::set_##name (class::name##_t x) {                          \
    class::ctx_value_t val;                                             \
    val.intValue = (int) x;                                             \
    keymap.put ("int:" #name, val);                                     \
  }

#define DECL_STR_PARAM( class, name )                  \
  string class::name () const {                        \
    string val;                                        \
    bool found = context_value ("int:" #name, val);    \
    assert (found);                                    \
    return val;                                        \
  }                                                    \
  void class::set_##name (string val) {                \
    str_keymap.put ("int:" #name, val);                \
  }

/*
 * Local variables:
 * mode: c++
 * End:
 */
