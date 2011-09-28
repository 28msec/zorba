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

// This header is configured by Zorba's build process -- DO NOT EDIT!

#ifndef ZORBA_CONFIG_H
#define ZORBA_CONFIG_H

////////// Platform & Compiler ////////////////////////////////////////////////

// Platform
#cmakedefine APPLE
#cmakedefine LINUX
#cmakedefine MINGW
#cmakedefine UNIX
#ifndef WIN32
#cmakedefine WIN32
#endif
#cmakedefine CYGWIN
#ifdef CYGWIN
# undef WIN32
#endif /* CYGWIN */

#ifdef WIN32
# pragma warning( disable: 4251 )
#endif /* WIN32 */

// Platform headers
#cmakedefine ZORBA_HAVE_COLL_H     
#cmakedefine ZORBA_HAVE_EXECINFO_H
#cmakedefine ZORBA_HAVE_FLEXLEXER_H
#cmakedefine ZORBA_HAVE_ICONV_H
#cmakedefine ZORBA_HAVE_INTTYPES_H 
#cmakedefine ZORBA_HAVE_LIMITS_H   
#cmakedefine ZORBA_HAVE_PTHREAD_H  
#cmakedefine ZORBA_HAVE_STDINT_H   
#cmakedefine ZORBA_HAVE_STDLIB_H   
#cmakedefine ZORBA_HAVE_SYS_MOUNT_H
#cmakedefine ZORBA_HAVE_SYS_TYPES_H
#cmakedefine ZORBA_HAVE_USTRING_H  
#cmakedefine ZORBA_HAVE_UTYPES_H   

// Platform functions
#cmakedefine ZORBA_HAVE_CLOCKGETTIME_FUNCTION
#cmakedefine ZORBA_HAVE_RUSAGE_FUNCTION
#cmakedefine ZORBA_HAVE_STRCAT_S_FUNCTION
#cmakedefine ZORBA_HAVE_STRCPY_S_FUNCTION
#cmakedefine ZORBA_HAVE_STRICMP_FUNCTION
#cmakedefine ZORBA_HAVE_STRTOF_FUNCTION
#cmakedefine ZORBA_HAVE_STRTOLL_FUNCTION

// Platform types
#cmakedefine ZORBA_HAVE_INT32_T
#cmakedefine ZORBA_HAVE_INT64_T
#cmakedefine ZORBA_HAVE_MS_INT32
#cmakedefine ZORBA_HAVE_MS_UINT32
#cmakedefine ZORBA_HAVE_UINT32_T

#ifdef ZORBA_HAVE_STDINT_H
# include <stdint.h>
#endif

#ifdef ZORBA_HAVE_INTTYPES_H
# include <inttypes.h>
#endif

#ifndef ZORBA_HAVE_INT32_T
# ifdef ZORBA_HAVE_MS_INT32
    typedef __int32 int32_t;
# endif
#endif

#ifndef ZORBA_HAVE_UINT32_T
# ifdef ZORBA_HAVE_MS_UINT32
    typedef unsigned __int32 uint32_t;
# endif
#endif /* ZORBA_HAVE_UINT32_T */

#ifndef ZORBA_HAVE_INT64_T
typedef __int64 int64_t;
#endif /* ZORBA_HAVE_INT64_T */

// Compiler
#cmakedefine CLANG
#cmakedefine MSVC
#cmakedefine MSVC60
#cmakedefine MSVC70
#cmakedefine MSVC71
#cmakedefine MSVC80

// C++ language features
#cmakedefine ZORBA_CXX_ENABLE_IF
#cmakedefine ZORBA_CXX_NULLPTR
#cmakedefine ZORBA_CXX_STATIC_ASSERT
#cmakedefine ZORBA_CXX_UNIQUE_PTR

////////// C++ tr1 include directory & namespace //////////////////////////////

#if defined( __GNUC__ ) && (__GNUC__ * 100 + __GNUC_MINOR__ < 430)
# define ZORBA_GCC_OLDER_THAN_430 1
#endif

#if defined( _MSC_VER ) && (_MSC_VER < 1600 /* 2010 */)
# define ZORBA_MSC_OLDER_THAN_2010 1
#endif

#if defined( ZORBA_GCC_OLDER_THAN_430 )
# define ZORBA_TR1_IN_TR1_SUBDIRECTORY 1
#endif

#if defined( ZORBA_GCC_OLDER_THAN_430 ) || defined( ZORBA_MSC_OLDER_THAN_2010 )
# define ZORBA_TR1_NS_IS_STD_TR1 1
#endif

#ifdef ZORBA_TR1_NS_IS_STD_TR1
# define ZORBA_TR1_NS std::tr1
#else
# define ZORBA_TR1_NS std
#endif

////////// Zorba //////////////////////////////////////////////////////////////

// Version
#define ZORBA_VERSION "${ZORBA_VERSION}"
#define ZORBA_MAJOR_NUMBER ${ZORBA_MAJOR_NUMBER}
#define ZORBA_MINOR_NUMBER ${ZORBA_MINOR_NUMBER}
#define ZORBA_PATCH_NUMBER ${ZORBA_PATCH_NUMBER}
#define ZORBA_MODULES_INSTALL_DIR "${ZORBA_MODULES_INSTALL_DIR}"

// Zorba features
#cmakedefine ZORBA_NO_FULL_TEXT
#cmakedefine ZORBA_NO_UNICODE
#cmakedefine ZORBA_NO_XMLSCHEMA
#cmakedefine ZORBA_NUMERIC_OPTIMIZATION
#cmakedefine ZORBA_VERIFY_PEER_SSL_CERTIFICATE
#cmakedefine ZORBA_WITH_BIG_INTEGER
#cmakedefine ZORBA_WITH_DEBUGGER
#cmakedefine ZORBA_WITH_FILE_ACCESS
#cmakedefine ZORBA_WITH_LIBXML2_SAX
#cmakedefine ZORBA_WITH_DEBUGGER_CLIENT

// Zorba parser configuration
#cmakedefine ZORBA_DEBUG_PARSER 
#cmakedefine ZORBA_DEBUG_STRING 

// Zorba runtime configuration parameters
#define ZORBA_BATCHING_TYPE         ${ZORBA_BATCHING_TYPE}
#define ZORBA_BATCHING_BATCHSIZE    ${ZORBA_BATCHING_BATCHSIZE}
#define ZORBA_FLOAT_POINT_PRECISION ${ZORBA_FLOAT_POINT_PRECISION}

// Zorba threading mechanism
#cmakedefine ZORBA_FOR_ONE_THREAD_ONLY     
#cmakedefine ZORBA_HAVE_PTHREAD_SPINLOCK
#cmakedefine ZORBA_HAVE_PTHREAD_MUTEX

// XQueryX
#cmakedefine ZORBA_XQUERYX

////////// Building Zorba /////////////////////////////////////////////////////

#ifndef BUILDING_ZORBA_STATIC
# if defined WIN32 || defined CYGWIN
#   ifdef zorba_EXPORTS
#     ifdef __GNUC__
#       define ZORBA_DLL_PUBLIC __attribute__((dllexport))
#     else
#       define ZORBA_DLL_PUBLIC __declspec(dllexport)
#     endif /* __GNUC__ */
#   else /* zorba_EXPORTS */
#     ifdef __GNUC__
#       define ZORBA_DLL_PUBLIC __attribute__((dllimport))
#     else
#       define ZORBA_DLL_PUBLIC __declspec(dllimport)
#     endif /* __GNUC__ */
#   endif /* zorba_EXPORTS */
#   define ZORBA_DLL_LOCAL
# else
#   if __GNUC__ >= 4
#     define ZORBA_DLL_PUBLIC __attribute__ ((visibility("default")))
#     define ZORBA_DLL_LOCAL  __attribute__ ((visibility("hidden")))
#   else
#     define ZORBA_DLL_PUBLIC
#     define ZORBA_DLL_LOCAL
#   endif
# endif
#else /* BUILDING_ZORBA_STATIC */
# define ZORBA_DLL_PUBLIC
# define ZORBA_DLL_LOCAL
#endif /* BUILDING_ZORBA_STATIC */

#endif /* ZORBA_CONFIG_H */
