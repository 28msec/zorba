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
#ifndef ZORBA_CONFIG_H
#define ZORBA_CONFIG_H

/* This header is configured by Zorba's build process.  */

/* Zorba Configuration */

/* general zorba configuration parameters */
#cmakedefine ZORBA_DEBUGGER 1
#ifndef WIN32
#cmakedefine WIN32
#endif
#cmakedefine CYGWIN
#ifdef CYGWIN
#undef WIN32
#endif
#cmakedefine UNIX
#cmakedefine MINGW
#cmakedefine APPLE
#cmakedefine MSVC
#cmakedefine MSVC60
#cmakedefine MSVC70
#cmakedefine MSVC71
#cmakedefine MSVC80
#cmakedefine LINUX


/* zorba runtime configuration parameters */
#define ZORBA_BATCHING_TYPE         ${ZORBA_BATCHING_TYPE}
#define ZORBA_BATCHING_BATCHSIZE    ${ZORBA_BATCHING_BATCHSIZE}
#define ZORBA_FLOAT_POINT_PRECISION ${ZORBA_FLOAT_POINT_PRECISION}

/* parser configuration */
#cmakedefine ZORBA_DEBUG_PARSER 

/* Platform checks */
#cmakedefine ZORBA_HAVE_SYS_MOUNT_H
#cmakedefine ZORBA_HAVE_UTYPES_H   
#cmakedefine ZORBA_HAVE_COLL_H     
#cmakedefine ZORBA_HAVE_USTRING_H  
#cmakedefine ZORBA_HAVE_PTHREAD_H  
#cmakedefine ZORBA_HAVE_INTTYPES_H 
#cmakedefine ZORBA_HAVE_STDINT_H   
#cmakedefine ZORBA_HAVE_STDLIB_H   
#cmakedefine ZORBA_HAVE_LIMITS_H   
#cmakedefine ZORBA_HAVE_SYS_TYPES_H
#cmakedefine ZORBA_HAVE_ICONV_H
#cmakedefine ZORBA_HAVE_EXECINFO_H
#cmakedefine ZORBA_HAVE_FLEXLEXER_H

/* rest support */
#cmakedefine ZORBA_WITH_REST
#cmakedefine ZORBA_WITH_SSL

/* tidy support*/
#cmakedefine ZORBA_WITH_TIDY

/* allow file system access */
#cmakedefine ZORBA_WITH_FILE_ACCESS

/* function checks */
#cmakedefine ZORBA_HAVE_STRTOF_FUNCTION    
#cmakedefine ZORBA_HAVE_STRICMP_FUNCTION   
#cmakedefine ZORBA_HAVE_STRCASECMP_FUNCTION
#cmakedefine ZORBA_HAVE_STRCAT_S_FUNCTION  
#cmakedefine ZORBA_HAVE_STRCPY_S_FUNCTION  

#cmakedefine ZORBA_HAVE_RUSAGE_FUNCTION

/* Threading mechanism*/
#cmakedefine ZORBA_FOR_ONE_THREAD_ONLY     
#cmakedefine ZORBA_HAVE_PTHREAD_SPINLOCK
#cmakedefine ZORBA_HAVE_PTHREAD_MUTEX

/* Configure Zorba features*/
#cmakedefine ZORBA_NO_UNICODE
#cmakedefine ZORBA_NO_XMLSCHEMA
#cmakedefine ZORBA_NO_BIGNUMBERS

/* Windows MSVC DLL */
#define    ZORBA_EXTERN_DECL
#cmakedefine ZORBA_WIN_DLL
#ifdef ZORBA_WIN_DLL
  #undef    ZORBA_EXTERN_DECL
#ifdef ZORBA_INTERNAL
  #define   ZORBA_EXTERN_DECL    __declspec(dllexport) 
#else
  #define   ZORBA_EXTERN_DECL    __declspec(dllimport)
#endif

#endif

#endif
