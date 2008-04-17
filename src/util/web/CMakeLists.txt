IF(HAVE_CURL_H)

  SET(WEB_SRCS
    web_curl.cpp)

ELSE(HAVE_CURL_H)

  SET(WEB_SRCS
    web_none.cpp)

ENDIF(HAVE_CURL_H)
