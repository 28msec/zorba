#ifndef ZORBA_CONFIG_H
#define ZORBA_CONFIG_H

/* This header is configured by Zorba's build process.  */

/* Zorba Configuration */

/* general zorba configuration parameters */


/* zorba runtime configuration parameters */
#define ZORBA_BATCHING_TYPE         ${ZORBA_BATCHING_TYPE}
#define ZORBA_BATCHING_BATCHSIZE    ${ZORBA_BATCHING_BATCHSIZE}
#define ZORBA_FLOAT_POINT_PRECISION ${ZORBA_FLOAT_POINT_PRECISION}

/* parser configuration */
#cmakedefine ZORBA_DEBUG_PARSER 


/* Platform checks */
#cmakedefine HAVE_SYS_MOUNT_H       1
#cmakedefine HAVE_UTYPES_H          1
#cmakedefine HAVE_COLL_H            1
#cmakedefine HAVE_USTRING_H         1
#cmakedefine HAVE_PTHREAD_H         1
#cmakedefine HAVE_INTTYPES_H        1
#cmakedefine HAVE_STDINT_H          1
#cmakedefine HAVE_STDLIB_H          1
#cmakedefine HAVE_LIMITS_H          1
#cmakedefine HAVE_SYS_TYPES_H       1
#cmakedefine HAVE_ICONV_H           1

/* function checks */
#cmakedefine HAVE_STRTOF_FUNCTION            1
#cmakedefine HAVE_STRICMP_FUNCTION           1
#cmakedefine HAVE_STRCASECMP_FUNCTION        1
#cmakedefine HAVE_STRCAT_S_FUNCTION          1
#cmakedefine HAVE_STRCPY_S_FUNCTION          1

/* Threading mechanism*/
#cmakedefine ZORBA_USE_PTHREAD_LIBRARY          1
#cmakedefine ZORBA_USE_BOOST_THREAD_LIBRARY     1
#cmakedefine ZORBA_FOR_ONE_THREAD_ONLY          1

#include "config/platform.h"

#endif
