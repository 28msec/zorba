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

#ifndef ZORBA_JSONMODULE_JANSSON_WRAPPER_H
#define ZORBA_JSONMODULE_JANSSON_WRAPPER_H

#include <zorba/item_factory.h>
#include <zorba/item.h>

namespace zorba
{
  namespace jsonmodule
  {
    //Json parse and serialize: http://www.json.org/
    //according to the mapping proposed by john snelson:
    //http://snelson.org.uk/archives/2008/02/parsing_json_in.php#more
    void JSON_parse(
      const char* aJsonString,
      std::stringstream& aSs,
      std::stringstream& aErrorLogSs);

    void JSON_serialize(
      const zorba::Item& aElement,
      std::stringstream& aResultSs,
      std::stringstream& aErrorLogSs);


    //Json ML parse and serialize: http://jsonml.org/
    void JSON_ML_parse(
      const char* aJsonString,
      std::stringstream& aSs,
      std::stringstream& aErrorLogSs);


    void JSON_ML_serialize(
      const zorba::Item& aElement,
      std::stringstream& aResultSs,
      std::stringstream& aErrorLogSs);

  } /* namespace jsonmodule */
} /* namespace zorba */

#endif //ZORBA_JSONMODULE_JANSSON_WRAPPER_H