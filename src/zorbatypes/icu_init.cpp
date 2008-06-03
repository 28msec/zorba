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
#ifndef ZORBA_NO_UNICODE
#include <unicode/uclean.h>
#include <unicode/utypes.h>
#include <unicode/udata.h>
#endif//#ifndef ZORBA_NO_UNICODE

#include "icu_init.h"
#include "zorbaerrors/Assert.h"

namespace zorba
{

void icu_init::zorbatypes_global_init()
{
  // initialize the icu library
  // we do this here because we are sure that is used
  // from one thread only
  // see http://www.icu-project.org/userguide/design.html#Init_and_Termination
  // and http://www.icu-project.org/apiref/icu4c/uclean_8h.html
  #ifndef ZORBA_NO_UNICODE
  {
  #if defined U_STATIC_IMPLEMENTATION && (defined WIN32 || defined WINCE)
  {
    TCHAR    self_path[1024];
    GetModuleFileName(NULL, self_path, sizeof(self_path));
        //PathRemoveFileSpec(self_path);
    TCHAR  *filename;
    filename = _tcsrchr(self_path, _T('\\'));
    if(filename)
      filename[1] = 0;
    else
      self_path[0] = 0;
        //strcat(self_path, "\\");
        //_tcscat(self_path, _T(U_ICUDATA_NAME));//icudt39l.dat");
    _tcscat(self_path, _T("icudt") _T(U_ICU_VERSION_SHORT) _T(U_ICUDATA_TYPE_LETTER));//icudt39l.dat");
    _tcscat(self_path, _T(".dat"));
        //unsigned char *icu_data;
    HANDLE    hfile;
    hfile = CreateFile(self_path, GENERIC_READ, FILE_SHARE_READ, NULL, OPEN_EXISTING, 0, NULL);
    ZORBA_ASSERT(hfile != INVALID_HANDLE_VALUE);
    DWORD   icusize;
    icusize = GetFileSize(hfile, NULL);
    icu_appdata = new unsigned char[icusize];
    DWORD   nr_read;
    ReadFile(hfile, icu_appdata, icusize, &nr_read, NULL);
    CloseHandle(hfile);
    UErrorCode    data_err = U_ZERO_ERROR;
    udata_setCommonData(icu_appdata, &data_err);
    ZORBA_ASSERT(data_err == U_ZERO_ERROR);
  
      //  u_setDataDirectory(self_path);
  }
  #endif
      UErrorCode lICUInitStatus = U_ZERO_ERROR;
      u_init(&lICUInitStatus);
      ZORBA_ASSERT(lICUInitStatus == U_ZERO_ERROR);
  }
  #endif//ifndef ZORBA_NO_UNICODE
}

void icu_init::zorbatypes_global_cleanup()
{
  // we shutdown icu
  // again it is important to mention this in the documentation
  // we might disable this call because it only
  // releases statically initialized memory and prevents
  // valgrind from reporting those problems at the end
  // see http://www.icu-project.org/apiref/icu4c/uclean_8h.html#93f27d0ddc7c196a1da864763f2d8920
#ifndef ZORBA_NO_UNICODE
{
  u_cleanup();
#if defined U_STATIC_IMPLEMENTATION && (defined WIN32 || defined WINCE)
  delete[] icu_appdata;
#endif
}
#endif//ifndef ZORBA_NO_UNICODE
}

}
