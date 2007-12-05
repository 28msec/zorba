IF(WITH_CURL)

  SET(WEB_SRCS
    web_curl.cpp)

ELSE(WITH_CURL)

  SET(WEB_SRCS
    web_none.cpp)

ENDIF(WITH_CURL)
