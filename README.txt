zorba 0.1-1
Jan 14, 2007


Building zorba
--------------

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
  
  
Known bugs
----------

There remain bugs in the autoconf setup.
Use the generated Makefiles directly for the time being.
In fact, the build is only partial at this point.

  - in 'parser', you need to stick to the Makefile.local, as in 
      > make all -f Makefile.local