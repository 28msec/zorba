/*
 * Copyright 2006-2010 The FLWOR Foundation.
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
#include <zorba/uri_resolvers.h>

namespace zorba {

/*************
 * Implementation of the Resource class hierarchy.
 *************/

  Resource::Resource(Resource::Kind aKind)
    : theKind(aKind)
  {}

  Resource::~Resource()
  {}

  Resource::Kind Resource::getKind() throw ()
  {
    return theKind;
  }

  StreamResource::StreamResource(std::auto_ptr<std::istream> aStream)
    : Resource(Resource::STREAM),
      theStream(aStream)
  {}

  std::auto_ptr<std::istream>
  StreamResource::getStream() throw ()
  {
    return theStream;
  }

/*************
 * URIMapper is an abstract class, but we have to define its vtbl and
 * base destructor somewhere.
 *************/

  URIMapper::~URIMapper()
  {}

/*************
 * URIResolver is an abstract class, but we have to define its vtbl
 * and base destructor somewhere.
 *************/

  URLResolver::~URLResolver()
  {}

} /* namespace zorba */
