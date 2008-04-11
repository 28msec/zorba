#ifndef ZORBA_CONFIG_H
#define ZORBA_CONFIG_H

/* This header is configured by Zorba's build process.  */

/* Zorba Configuration */

/* general zorba configuration parameters */
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


/* zorba runtime configuration parameters */
#define ZORBA_BATCHING_TYPE         ${ZORBA_BATCHING_TYPE}
#define ZORBA_BATCHING_BATCHSIZE    ${ZORBA_BATCHING_BATCHSIZE}
#define ZORBA_FLOAT_POINT_PRECISION ${ZORBA_FLOAT_POINT_PRECISION}

/* parser configuration */
#cmakedefine ZORBA_DEBUG_PARSER 

/* Platform checks */
#cmakedefine HAVE_SYS_MOUNT_H
#cmakedefine HAVE_UTYPES_H   
#cmakedefine HAVE_COLL_H     
#cmakedefine HAVE_USTRING_H  
#cmakedefine HAVE_PTHREAD_H  
#cmakedefine HAVE_INTTYPES_H 
#cmakedefine HAVE_STDINT_H   
#cmakedefine HAVE_STDLIB_H   
#cmakedefine HAVE_LIMITS_H   
#cmakedefine HAVE_SYS_TYPES_H
#cmakedefine HAVE_ICONV_H
#cmakedefine HAVE_EXECINFO_H
#cmakedefine HAVE_FLEXLEXER_H

/* function checks */
#cmakedefine HAVE_STRTOF_FUNCTION    
#cmakedefine HAVE_STRICMP_FUNCTION   
#cmakedefine HAVE_STRCASECMP_FUNCTION
#cmakedefine HAVE_STRCAT_S_FUNCTION  
#cmakedefine HAVE_STRCPY_S_FUNCTION  

/* Threading mechanism*/
#cmakedefine ZORBA_FOR_ONE_THREAD_ONLY     
#cmakedefine HAVE_PTHREAD_SPINLOCK
#cmakedefine HAVE_PTHREAD_MUTEX

/* Configure Zorba features*/
#cmakedefine ZORBA_NO_UNICODE

#endif
