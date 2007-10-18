#define DECL_PARAM1( class, name, retType, keytype, map, unionField)    \
  retType class::name () const {                                        \
    bool found;                                                         \
    retType x =                                                         \
      (retType) context_value (map, "int:" #name, &found) unionField;   \
    assert (found);                                                     \
    return x;                                                           \
  }                                                                     \
  void class::set_##name (retType x) {                                  \
    keytype y;                                                          \
    y unionField = x;                                                   \
    map.put ("int:" #name, y);                                          \
  }

#define DECL_PARAM2( class, name )                                      \
  DECL_PARAM1 (class, name, class::name##_t, ctx_value_t, keymap, .intValue)

#define DECL_STR_PARAM( class, name )                 \
  DECL_PARAM1 (class, name, string, string, str_keymap, )

/*
 * Local variables:
 * mode: c++
 * End:
 */
