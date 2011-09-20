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
#pragma once
#ifndef ZORBAC_CIMPLEMENTATION_H
#define ZORBAC_CIMPLEMENTATION_H

#include <xqc.h>
#include <zorba/zorbac.h>
#include <zorba/zorba.h>

using namespace zorba;

namespace zorbac {

  // Forward ref
  class CrSeqData;

  class CImplementation
  {
    public:
      CImplementation(Zorba* aZorba);
      ~CImplementation();

      static XQC_Error
      create_context(XQC_Implementation* impl, XQC_StaticContext** context);

      static XQC_Error 
      prepare(XQC_Implementation* impl, const char *query_string,
        const XQC_StaticContext* context,  XQC_Expression** expr);

      static XQC_Error 
      prepare_file(XQC_Implementation* impl, FILE *query_file,
        const XQC_StaticContext* context, XQC_Expression** expr);

      static XQC_Error
      prepare_stream(XQC_Implementation* impl, XQC_InputStream* stream,
        const XQC_StaticContext* context, XQC_Expression** expr);
      
      static XQC_Error
      parse_document(XQC_Implementation* impl,
        const char *string, XQC_Sequence** seq);

      static XQC_Error
      parse_document_file(XQC_Implementation* impl,
        FILE *file, XQC_Sequence** seq);

      static XQC_Error
      parse_document_stream(XQC_Implementation* impl,
        XQC_InputStream* stream, XQC_Sequence** seq);

      static XQC_Error
      create_empty_sequence(XQC_Implementation* impl, XQC_Sequence** seq);

      static XQC_Error
      create_singleton_sequence(XQC_Implementation* impl,
        XQC_ItemType type, const char *value, XQC_Sequence** seq);

      static XQC_Error
      create_string_sequence(XQC_Implementation* impl,
        const char *values[], unsigned int count, XQC_Sequence** seq);

      static XQC_Error
      create_integer_sequence(XQC_Implementation* impl,
        int values[], unsigned int count, XQC_Sequence** seq);

      static XQC_Error
      create_double_sequence(XQC_Implementation* impl,
        double values[], unsigned int count, XQC_Sequence** seq);

      static void *
      get_interface(const XQC_Implementation* impl, const char *name);

      static void 
      free(XQC_Implementation* impl);

      static CImplementation*
      get(const XQC_Implementation* xqc);

      Zorba*
      getCPP();

      XQC_Implementation*
      getXQC();

    private:

      void
      create_sequence(std::auto_ptr<CrSeqData> data, XQC_Sequence** seq);

      XQC_Error
      parse_istream(std::istream& aStream, XQC_Sequence** seq);

      static XQC_Error
      readXQCInputStream(XQC_InputStream* aXQCStream,
        std::stringstream& aStream);

      static XQC_Error
      readFile(FILE* aFile, std::stringstream& aStream);

      XQC_Implementation theXQCImpl;
      Zorba*             theZorba;
  };
} /* namespace zorbac */

#endif
/* vim:set et sw=2 ts=2: */
