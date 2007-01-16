zorba 0.1-1
Jan 14, 2007


Building zorba
--------------
The root directory is
	$INSTALL/zorba/xquery.

setup.sh
  makes symbolic links needed by configure:
    install-sh, depcomp, missing
  
rebuild_autoconf
  Generates a file aclocal.m4 that contains macros for automake.
  Automake reads configure.ac and the top-level Makefile.am, 
  interprets them, and for each Makefile.am produces a Makefile.in.
  Lastly, autoconf builds the configure script.
  
configure
  Generated script that creates Makefiles

build.sh
	Manually created make, using simple Makefile.local
	scripts.   A lot easier to use during initial development.
  
  
Known bugs
----------

There remain bugs in the autoconf setup.
Use the manual Makefile.local system for the time being.

