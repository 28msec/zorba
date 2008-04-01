SET(ZORBATYPES_SRCS 
  decimal.cpp
  floatimpl.cpp
  integer.cpp
  numconversions.cpp
  binary.cpp
  utf8/xqpString.cpp
  utf8/Unicode_util.cpp
  collation_manager.cpp)
  
ADD_SRC_SUBFOLDER(ZORBATYPES_SRCS mapm     MAPM_SRCS)
ADD_SRC_SUBFOLDER(ZORBATYPES_SRCS datetime DATETIME_SRCS)
