#define RAISE_ERROR(errcode, loc, params)                     \
  throw XQUERY_EXCEPTION(errcode,                             \
                         params,                              \
                         ERROR_LOC(loc));


#define RAISE_ERROR_NO_LOC(errcode, params)                   \
  throw XQUERY_EXCEPTION(errcode,                             \
                         params);


#define RAISE_ERROR_NO_PARAMS(errcode, loc)                   \
  throw XQUERY_EXCEPTION(errcode,                             \
                         ERROR_LOC(loc));
