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
#include <curl/curl.h>
#include "util/web/web.h"

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

static size_t
WriteMemoryCallback(void *ptr, size_t size, size_t nmemb, void* data)
{
  size_t realsize = size * nmemb;
  std::string* str = (std::string*)data;
  str->append((char*)ptr, realsize);
  return realsize;
}

int http_get(const char* url, xqp_string& result)
{
  int result_code;
  CURL* curl_handle;
  std::string temp;

  curl_handle = curl_easy_init();                                             /* init the curl session */
  curl_easy_setopt(curl_handle, CURLOPT_URL, url);                            /* specify URL to get */
  curl_easy_setopt(curl_handle, CURLOPT_WRITEFUNCTION, WriteMemoryCallback);  /* send all data to this function  */
  curl_easy_setopt(curl_handle, CURLOPT_WRITEDATA, (void *)&temp);            /* we pass our 'result' struct to the callback function */

  /* some servers don't like requests that are made without a user-agent
    field, so we provide one */
  curl_easy_setopt(curl_handle, CURLOPT_USERAGENT, "libcurl-agent/1.0");
  
  result_code = curl_easy_perform(curl_handle);
  curl_easy_cleanup(curl_handle);

  result = temp;
  return result_code;
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
  TidyOptionId        toID;
  std::string         optTM("tidy-mark");

  tdoc = tidyCreate();

  ok = tidyOptSetBool( tdoc, TidyXhtmlOut, yes );  // Convert to XHTML
  if ( ok )
    rc = tidySetErrorBuffer( tdoc, &errbuf );      // Capture diagnostics
  if ( rc >= 0 )
    rc = tidyParseString( tdoc, input );           // Parse the input
  if ( rc >= 0 ) {
    //set tidy-mark to off: Tidy will not add a meta element to the document head to indicate that the document has been tidied.
    toID = tidyOptGetIdForName(optTM.c_str());
    if( tidyOptGetBool(tdoc, toID) )
      ok = tidyOptSetBool(tdoc, toID, no);
  }
  if( ok )
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
  TidyOptionId    toID;
  std::string     optTM("tidy-mark");

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
  if ( rc >= 0 ) {
    //set tidy-mark to off: Tidy will not add a meta element to the document head to indicate that the document has been tidied.
    toID = tidyOptGetIdForName(optTM.c_str());
    if( tidyOptGetBool(tdoc, toID) )
      ok = tidyOptSetBool(tdoc, toID, no);
  }
  if( ok )
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
  TidyOptionId        toID;
  std::string         optTM("tidy-mark");

  tdoc = tidyCreate();

  ok = tidyOptSetBool( tdoc, TidyXhtmlOut, yes );  // Convert to XHTML
  if ( ok )
    rc = tidySetErrorBuffer( tdoc, &errbuf );      // Capture diagnostics
  if ( rc >= 0 )
    rc = tidyParseBuffer( tdoc, &inputBuf );     // Parse the input
  if ( rc >= 0 ) {
    //set tidy-mark to off: Tidy will not add a meta element to the document head to indicate that the document has been tidied.
    toID = tidyOptGetIdForName(optTM.c_str());
    if( tidyOptGetBool(tdoc, toID) )
      ok = tidyOptSetBool(tdoc, toID, no);
  }
  if( ok )
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
