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
#ifndef ZORBAC_CIMPLEMENTATION_H
#define ZORBAC_CIMPLEMENTATION_H

#include <zorba/zorbac.h>
#include <zorba/zorba.h>

using namespace zorba;

namespace zorbac {

  class CImplementation
  {
    public:
      CImplementation(Zorba* aZorba);
      ~CImplementation();

      static XQC_Error
      create_context(XQC_Implementation* impl, XQC_StaticContext** context);

      static XQC_Error 
      prepare(XQC_Implementation* implementation, 
              const char *query_string,
              XQC_StaticContext* context, 
              XQC_Expression **expr);

      static XQC_Error 
      prepare_file(XQC_Implementation* implementation, 
                   FILE *query_file,
                   XQC_StaticContext* context, 
                   XQC_Expression **expr);

      static XQC_Error
      prepare_stream(XQC_Implementation* implementation, 
                     XQC_InputStream* stream,
                     XQC_StaticContext* context, 
                     XQC_Expression **expr);

      static void 
      free(XQC_Implementation* implementation);

      static CImplementation*
      get(const XQC_Implementation* xqc);

      Zorba*
      getCPP();

      XQC_Implementation*
      getXQC();

    private:
      XQC_Implementation theXQCImpl;
      Zorba*             theZorba;
  };
} /* namespace zorbac */

#endif
