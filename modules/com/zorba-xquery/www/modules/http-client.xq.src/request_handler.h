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
#ifndef REQUEST_HANDLER_H
#define REQUEST_HANDLER_H

namespace zorba {
class String;
class Item;
class ItemSequence;

namespace http_client {
  class RequestHandler {
  public:
    virtual ~RequestHandler();
  public:
    virtual void begin() = 0;
    virtual void beginResponse(int aStatus, String aMessage) = 0;
    virtual void endResponse() = 0;
    virtual void beginRequest(
      String aMethod,
      String href,
      bool aStatusOnly,
      String aUsername,
      String aPassword,
      String aAuthMethod,
      bool aSendAuthorization,
      String aOverrideContentType,
      bool aFollowRedirect,
      int aTimeout = -1) = 0;
    virtual void endRequest() = 0;
    virtual void header(String aName, String aValue) = 0;
    virtual void beginBody(
      String aContentType,
      String aSrc,
      ItemSequence* aSerializerOptions) = 0;
    virtual void any(Item aItem) = 0;
    virtual void endBody() = 0;
    virtual void beginMultipart(String aContentType, String aBoundary) = 0;
    virtual void endMultipart() = 0;
    virtual void end() = 0;
  public: // status
    virtual bool isHeadRequest() const = 0;
  };
}
}

#endif //REQUEST_HANDLER_H
