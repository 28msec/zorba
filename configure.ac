#                                               -*- Autoconf -*-
# Process this file with autoconf to produce a configure script.

AC_PREREQ(2.60)
AC_INIT(zorba, 0.1-1, pcp071098@yahoo.com)
AM_INIT_AUTOMAKE(zorba, 0.1-1)
AC_OUTPUT(Makefile context/Makefile exprtree/Makefile functions/Makefile \
	listeners/Makefile native_impl/Makefile parser/Makefile runtime/Makefile \
	store/Makefile types/Makefile util/Makefile values/Makefile)

# Checks for programs.
AC_PROG_CXX
AC_PROG_CC
AC_PROG_CPP
AC_PROG_INSTALL

# Checks for libraries.

# Checks for header files.
AC_HEADER_DIRENT
AC_HEADER_STDC
AC_CHECK_HEADERS([fcntl.h limits.h stddef.h stdlib.h string.h strings.h sys/time.h sys/vfs.h unistd.h])

# Checks for typedefs, structures, and compiler characteristics.
AC_HEADER_STDBOOL
AC_C_CONST
AC_C_INLINE
AC_TYPE_INT16_T
AC_TYPE_INT32_T
AC_TYPE_INT64_T
AC_TYPE_OFF_T
AC_TYPE_SIZE_T
AC_TYPE_SSIZE_T
AC_HEADER_TIME
AC_STRUCT_TM
AC_TYPE_UINT16_T
AC_TYPE_UINT32_T
AC_TYPE_UINT64_T
AC_C_VOLATILE
AC_CHECK_TYPES([ptrdiff_t])

# Checks for library functions.
AC_FUNC_CLOSEDIR_VOID
AC_FUNC_ERROR_AT_LINE
AC_FUNC_MALLOC
AC_FUNC_MMAP
AC_FUNC_STAT
AC_FUNC_STRFTIME
AC_FUNC_STRTOD
AC_CHECK_FUNCS([gettimeofday memchr memset mkdir munmap rmdir sqrt strcasecmp strchr strerror strncasecmp strspn strtol strtoul])

AC_OUTPUT
