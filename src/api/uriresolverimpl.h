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
#ifndef ZORBA_URIRESOLVERIMPL_H
#define ZORBA_URIRESOLVERIMPL_H

#include <zorba/uri_resolvers.h>

namespace zorba {

class StreamResourceImpl : public StreamResource
{
public:
  virtual std::istream* getStream();

  virtual StreamReleaser getStreamReleaser();

  /**
   * @brief Assign the StreamReleaser. Generally you should only use this
   * to set the StreamReleaser to "nullptr" if you are taking memory
   * ownership of the istream. This method is only on StreamResourceImpl;
   * it's not part of the public API.
   */
  virtual void setStreamReleaser(StreamReleaser aStreamReleaser);

  virtual ~StreamResourceImpl();

private:

  StreamResourceImpl(std::istream* aStream, StreamReleaser aStreamReleaser);

  friend StreamResource* StreamResource::create(std::istream *aStream,
                                                StreamReleaser aStreamReleaser);
  std::istream* theStream;
  StreamReleaser theStreamReleaser;

};

} // namespace zorba
#endif // ZORBA_URIRESOLVERIMPL_H
