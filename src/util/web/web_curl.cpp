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
// #include "zorbaerrors/error_manager.h"

#ifdef ZORBA_WITH_TIDY
  #include <tidy.h>
  #include <buffio.h>
#endif

#include <iostream>
#include <sstream>
#include <string>
#include <fstream>

#include "system/globalenv.h"

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

int http_get(const char* url, std::iostream& result)
{
  int result_code;
  CURL* curl_handle;
  std::string temp;

  curl_handle = curl_easy_init();                                             /* init the curl session */
  curl_easy_setopt(curl_handle, CURLOPT_URL, url);                            /* specify URL to get */
  curl_easy_setopt(curl_handle, CURLOPT_WRITEFUNCTION, WriteMemoryCallback);  /* send all data to this function  */
  curl_easy_setopt(curl_handle, CURLOPT_WRITEDATA, (void *)&temp);            /* we pass our 'result' struct to the callback function */
  curl_easy_setopt(curl_handle, CURLOPT_FAILONERROR, 1);        /* tells the library to fail silently if the HTTP code returned >= 400*/
  curl_easy_setopt(curl_handle, CURLOPT_FOLLOWLOCATION, 1); /*Tells cURL to follow redirects. CURLOPT_MAXREDIRS is by default set to -1 thus cURL will do an infinite number of redirects */

#ifndef ZORBA_VERIFY_PEER_SSL_CERTIFICATE//default is to not verify root certif
  curl_easy_setopt(curl_handle, CURLOPT_SSL_VERIFYPEER, 0);
  //but CURLOPT_SSL_VERIFYHOST is left default, value 2, meaning verify that the Common Name or Subject Alternate Name field in the certificate matches the name of the server
  //tested with https://www.npr.org/rss/rss.php?id=1001
  //about using ssl certs in curl: http://curl.haxx.se/docs/sslcerts.html
#else
  #if defined WIN32
  //set the root CA certificates file path
  if(GENV.g_curl_root_CA_certificates_path[0])
    curl_easy_setopt(curl_handle, CURLOPT_CAINFO, GENV.g_curl_root_CA_certificates_path);
  #endif
#endif

  /* some servers don't like requests that are made without a user-agent
    field, so we provide one */
  curl_easy_setopt(curl_handle, CURLOPT_USERAGENT, "libcurl-agent/1.0");

  result_code = curl_easy_perform(curl_handle);

  if(0 != result_code) /*warkaround for a problem in cURL: curl_easy_cleanup fails if curl_easy_perform returned an error*/
    curl_easy_reset(curl_handle);

  curl_easy_cleanup(curl_handle);

  result << temp.c_str();
  return result_code;
}

#ifdef ZORBA_WITH_TIDY
void tokenize(const std::string& str,
              std::vector<std::string>& tokens,
              const std::string& delimiters)
{
  // Skip delimiters at beginning.
  std::string::size_type lastPos = str.find_first_not_of(delimiters, 0);
  // Find first "non-delimiter".
  std::string::size_type pos     = str.find_first_of(delimiters, lastPos);

  while (std::string::npos != pos || std::string::npos != lastPos)
  {
    // Found a token, add it to the vector
    tokens.push_back(str.substr(lastPos, pos - lastPos));
    // Skip delimiters.  Note the "not_of"
    lastPos = str.find_first_not_of(delimiters, pos);
    // Find next "non-delimiter"
    pos = str.find_first_of(delimiters, lastPos);
  }
}

/* char-encoding=utf8, newline=LF, tidy-mark=no, quote-nbsp=no */
Bool setZorbaOptions(TidyDoc& tdoc)
{
  Bool ok;

  //set char-encoding to utf-8(Default value is ascii.): This option specifies the character encoding
  //Tidy uses for the output. For utf8, Tidy assumes that both input and output is encoded as UTF-8.
  ok = tidyOptSetValue(tdoc, TidyCharEncoding, "utf8");

  //The default is appropriate to the current platform: CRLF on PC-DOS, MS-Windows and OS/2,
  //CR on Classic Mac OS, and LF everywhere else (Unix and Linux).
  if(ok) {
    ok = tidyOptSetValue(tdoc, TidyNewline, "LF");
  }

  if(ok) {
    //set tidy-mark to off(Default value is on.): Tidy will not add a meta element to the document head
    //to indicate that the document has been tidied.
    ok = tidyOptSetBool(tdoc, TidyMark, no);
  }

  if(ok) {
    //set quote-nbsp to off(Default value is on.): This option specifies if Tidy should output non-breaking space
    //characters as entities, rather than as the Unicode character value 160 (decimal).
    ok = tidyOptSetBool(tdoc, TidyQuoteNbsp, no);
  }

  return ok;
}

Bool setUserOptions(TidyDoc& tdoc, const char* options)  throw()
{
  Bool          ok = yes;
  TidyOptionId  toID;
  std::string   option, value;

  if(NULL != options) {
    std::vector<std::string> tokens;
    std::vector<std::string>::iterator lIter;
    tokenize(options, tokens, ",");
    for(lIter=tokens.begin(); lIter!=tokens.end() && ok; ++lIter) {
      size_t pos = (*lIter).substr(1,(*lIter).length() -2).find('=');
      if(pos != std::string::npos) {
       option = (*lIter).substr(1, pos);
       value = (*lIter).substr(pos + 2, (*lIter).length() - pos - 3);
      }
      else {
        option = (*lIter).substr(1, (*lIter).length() - 2);
        value = "true";
      }

      toID = tidyOptGetIdForName(option.c_str());
      ok = tidyOptSetValue(tdoc, toID, value.c_str());

//       if(!ok)
//         ZORBA_ERROR_PARAM(API0037_TIDY_ERROR_SET_OPTION, option.c_str(), value.c_str());
     }
  }
  return ok;
}

int tidy(const char* input,
         xqp_string& result,
         xqp_string& diagnostics,
         const char* userOpt) throw()
{
  TidyDoc     tdoc;
  Bool        ok;
  int         rc = -1;
  TidyBuffer  output, errbuf;
  tidyBufInit( &output );
  tidyBufInit( &errbuf );
  xqpStringStore_t    buf, err;

  tdoc = tidyCreate();

  ok = tidyOptSetBool( tdoc, TidyXhtmlOut, yes );  // Convert to XHTML
  if ( ok )
    rc = tidySetErrorBuffer( tdoc, &errbuf );      // Capture diagnostics
  if ( rc >= 0 )
    rc = tidyParseString( tdoc, input );           // Parse the input
  if ( rc >= 0 )
    ok = setZorbaOptions(tdoc);
  if(ok)
    ok = setUserOptions(tdoc, userOpt);
  if( ok )
  {
    rc = tidyCleanAndRepair( tdoc );                 // Tidy it up!
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
  }
  else
  {
    rc = -1;
    diagnostics = new xqpStringStore("couldn't set the Tidy options");
  }

  tidyBufFree( &output );
  tidyBufFree( &errbuf );
  tidyRelease( tdoc );
  return rc;
}

int tidy(const std::ifstream& fStream,
         std::iostream& result,
         xqp_string& diagnostics,
         const char* userOpt)
{
  TidyDoc         tdoc;
  Bool            ok;
  int             rc = -1;
  std::filebuf*   pbuf;
  uint            size;
  char*           buffer;

  pbuf = fStream.rdbuf();
  size = (uint)pbuf->pubseekoff (0,std::ios::end, std::ios::in);
  pbuf->pubseekpos (0, std::ios::in);
  buffer = new char[size];
#ifdef WIN32
  pbuf->_Sgetn_s (buffer, size, size);
#else
  pbuf->sgetn (buffer, size);
#endif

  TidyBuffer inputBuf;
  tidyBufAlloc(&inputBuf, size+1);
  inputBuf.bp = (byte*)buffer;
  inputBuf.size = size;
  TidyBuffer output, errbuf;
  tidyBufInit( &output );
  tidyBufInit( &errbuf );

  tdoc = tidyCreate();

  ok = tidyOptSetBool( tdoc, TidyXhtmlOut, yes );   // Convert to XHTML
  if ( ok )
    rc = tidySetErrorBuffer( tdoc, &errbuf );       // Capture diagnostics
  if ( rc >= 0 )
    rc = tidyParseBuffer( tdoc, &inputBuf );        // Parse the input
  if ( rc >= 0 )
    ok = setZorbaOptions(tdoc);
  if(ok)
    ok = setUserOptions(tdoc, userOpt);
  if( ok )
  {
    rc = tidyCleanAndRepair( tdoc );                 // Tidy it up!
    if ( rc >= 0 )
      rc = tidyRunDiagnostics( tdoc );               // Kvetch
    if ( rc > 1 )                                    // If error, force output.
      rc = ( tidyOptSetBool(tdoc, TidyForceOutput, yes) ? rc : -1 );
    if ( rc >= 0 )
      rc = tidySaveBuffer( tdoc, &output );          // Pretty Print

    if ( rc >= 0 ) {
      result << output.bp;
      if ( rc > 0 )
        diagnostics = new xqpStringStore((char*)errbuf.bp, errbuf.size);
    }
  }
    else
  {
    rc = -1;
    diagnostics = new xqpStringStore("couldn't set the Tidy options");
  }

  tidyBufFree( &inputBuf );
  tidyBufFree( &output );
  tidyBufFree( &errbuf );
  tidyRelease( tdoc );
  return rc;
}

int tidy(const std::istringstream& isStream,
         std::iostream& result,
         xqp_string& diagnostics,
         const char* userOpt)
{
  TidyDoc             tdoc;
  Bool                ok;
  int                 rc = -1;
  std::stringbuf *    isBuf = isStream.rdbuf();
  uint                size = (uint)isBuf->in_avail();

  TidyBuffer inputBuf;
  tidyBufAlloc(&inputBuf, size+1);
  memset(inputBuf.bp, 0, size+1);
  memcpy(inputBuf.bp, isStream.str().c_str(), size);
  inputBuf.size = size;
  TidyBuffer output, errbuf;
  tidyBufInit( &output );
  tidyBufInit( &errbuf );
  xqpStringStore_t    buf, err;

  tdoc = tidyCreate();

  ok = tidyOptSetBool( tdoc, TidyXhtmlOut, yes );  // Convert to XHTML
  if ( ok )
    rc = tidySetErrorBuffer( tdoc, &errbuf );      // Capture diagnostics
  if ( rc >= 0 )
    rc = tidyParseBuffer( tdoc, &inputBuf );       // Parse the input
  if ( rc >= 0 )
    ok = setZorbaOptions(tdoc);
  if(ok)
    ok = setUserOptions(tdoc, userOpt);
  if( ok )
  {
    rc = tidyCleanAndRepair( tdoc );                 // Tidy it up!
    if ( rc >= 0 )
      rc = tidyRunDiagnostics( tdoc );               // Kvetch
    if ( rc > 1 )                                    // If error, force output.
      rc = ( tidyOptSetBool(tdoc, TidyForceOutput, yes) ? rc : -1 );
    if ( rc >= 0 )
      rc = tidySaveBuffer( tdoc, &output );          // Pretty Print

    if ( rc >= 0 ) {
      result << output.bp;
      if ( rc > 0 )
        diagnostics = new xqpStringStore((char*)errbuf.bp, errbuf.size);
    }
  }
  else
  {
    rc = -1;
    diagnostics = new xqpStringStore("couldn't set the Tidy options");
  }

  tidyBufFree( &inputBuf );
  tidyBufFree( &output );
  tidyBufFree( &errbuf );
  tidyRelease( tdoc );
  return rc;
}
#endif
} // namespace zorba
