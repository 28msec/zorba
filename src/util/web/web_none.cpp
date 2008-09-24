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
#include "util/web/web.h"
#include "zorbaerrors/error_manager.h"

#ifdef ZORBA_WITH_TIDY
  #include <tidy.h>
  #include <buffio.h>
#endif

#include <iostream>
#include <sstream>
#include <string>
#include <fstream>

namespace zorba
{

int http_get(const char* url, xqp_string& result)
{
  ZORBA_ERROR_PARAM(  XQP0004_SYSTEM_NOT_SUPPORTED, "HTTP GET" , "");

  return 0;
}

#ifdef ZORBA_WITH_TIDY
int tidy(const char* input, xqp_string& result, xqp_string& diagnostics)
{
  TidyDoc             tdoc;
  bool                ok;
  int                 rc = -1;
  TidyBuffer output = {0, 0, 0, 0};
  TidyBuffer errbuf = {0, 0, 0, 0};
  xqpStringStore_t    buf, err;

  tdoc = tidyCreate();

  ok = tidyOptSetBool( tdoc, TidyXhtmlOut, yes );  // Convert to XHTML
  if ( ok )
    rc = tidySetErrorBuffer( tdoc, &errbuf );      // Capture diagnostics
  if ( rc >= 0 )
    rc = tidyParseString( tdoc, input );     // Parse the input
  if ( rc >= 0 )
    rc = tidyCleanAndRepair( tdoc );               // Tidy it up!
  if ( rc >= 0 )
    rc = tidyRunDiagnostics( tdoc );               // Kvetch
  if ( rc > 1 )                                    // If error, force output.
    rc = ( tidyOptSetBool(tdoc, TidyForceOutput, yes) ? rc : -1 );
  if ( rc >= 0 )
    rc = tidySaveBuffer( tdoc, &output );          // Pretty Print

  if ( rc >= 0 ) {
    result = new xqpStringStore((char*)output.bp, output.size);
    if ( rc > 0 )
      diagnostics = new xqpStringStore((char*)errbuf.bp, errbuf.size);
  }

  tidyBufFree( &output );
  tidyBufFree( &errbuf );
  tidyRelease( tdoc );
  return rc;
}

int tidy(const std::ifstream& fStream, std::iostream& result, std::iostream& diagnostics)
{
  TidyDoc         tdoc;
  bool            ok;
  int             rc = -1;
  std::filebuf*   pbuf;
  long            size;
  char*           buffer;

  pbuf=fStream.rdbuf();
  size=pbuf->pubseekoff (0,std::ios::end,std::ios::in);
  pbuf->pubseekpos (0,std::ios::in);
  buffer=new char[size];
  pbuf->sgetn (buffer,size);

  TidyBuffer inputBuf = {(byte*)buffer, size, size, 0};
  TidyBuffer output = {0, 0, 0, 0};
  TidyBuffer errbuf = {0, 0, 0, 0};

  tdoc = tidyCreate();

  ok = tidyOptSetBool( tdoc, TidyXhtmlOut, yes );  // Convert to XHTML
  if ( ok )
    rc = tidySetErrorBuffer( tdoc, &errbuf );      // Capture diagnostics
  if ( rc >= 0 )
    rc = tidyParseBuffer( tdoc, &inputBuf );     // Parse the input
  if ( rc >= 0 )
    rc = tidyCleanAndRepair( tdoc );               // Tidy it up!
  if ( rc >= 0 )
    rc = tidyRunDiagnostics( tdoc );               // Kvetch
  if ( rc > 1 )                                    // If error, force output.
    rc = ( tidyOptSetBool(tdoc, TidyForceOutput, yes) ? rc : -1 );
  if ( rc >= 0 )
    rc = tidySaveBuffer( tdoc, &output );          // Pretty Print

  if ( rc >= 0 ) {
    result << output.bp;
    if ( rc > 0 )
      diagnostics << errbuf.bp;
  }

  tidyBufFree( &output );
  tidyBufFree( &errbuf );
  tidyRelease( tdoc );
  return rc;
}

int tidy(const std::istringstream& isStream, std::iostream& result, std::iostream& diagnostics)
{
  TidyDoc             tdoc;
  bool                ok;
  int                 rc = -1;
  TidyBuffer inputBuf = {(byte*)(isStream.str().c_str()), isStream.str().size(), isStream.str().size(), 0};
  TidyBuffer output = {0, 0, 0, 0};
  TidyBuffer errbuf = {0, 0, 0, 0};
  xqpStringStore_t    buf, err;

  tdoc = tidyCreate();

  ok = tidyOptSetBool( tdoc, TidyXhtmlOut, yes );  // Convert to XHTML
  if ( ok )
    rc = tidySetErrorBuffer( tdoc, &errbuf );      // Capture diagnostics
  if ( rc >= 0 )
    rc = tidyParseBuffer( tdoc, &inputBuf );     // Parse the input
  if ( rc >= 0 )
    rc = tidyCleanAndRepair( tdoc );               // Tidy it up!
  if ( rc >= 0 )
    rc = tidyRunDiagnostics( tdoc );               // Kvetch
  if ( rc > 1 )                                    // If error, force output.
    rc = ( tidyOptSetBool(tdoc, TidyForceOutput, yes) ? rc : -1 );
  if ( rc >= 0 )
    rc = tidySaveBuffer( tdoc, &output );          // Pretty Print

  if ( rc >= 0 ) {
    result << output.bp;
    if ( rc > 0 )
      diagnostics << errbuf.bp;
  }

  tidyBufFree( &output );
  tidyBufFree( &errbuf );
  tidyRelease( tdoc );
  return rc;
}

#endif
} // namespace zorba
