# Copyright 2006-2013 The FLWOR Foundation.
#
# Licensed under the Apache License, Version 2.0 (the "License");
# you may not use this file except in compliance with the License.
# You may obtain a copy of the License at
#
# http://www.apache.org/licenses/LICENSE-2.0
#
# Unless required by applicable law or agreed to in writing, software
# distributed under the License is distributed on an "AS IS" BASIS,
# WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
# See the License for the specific language governing permissions and
# limitations under the License.

IF (ZORBA_HAVE_CURL)
  SET(ZorbaUtilCurlModule_DIR "../util-curl")
  FIND_PACKAGE(ZorbaUtilCurlModule REQUIRED)
  IF (ZorbaUtilCurlModule_FOUND)
    FIND_PACKAGE(Curl)
    INCLUDE_DIRECTORIES("${ZorbaUtilCurlModule_INCLUDE_DIRS}" "${CURL_INCLUDE_DIRS}")
	
    DECLARE_ZORBA_MODULE( FILE ftp-client.xq VERSION 1.0
      URI "http://zorba.io/modules/ftp-client"
      LINK_LIBRARIES ${CURL_LIBRARIES} ${ZorbaUtilCurlModule_LIBS})
  ENDIF (ZorbaUtilCurlModule_FOUND)
ENDIF (ZORBA_HAVE_CURL)

# vim:set et sw=2 ts=2:
