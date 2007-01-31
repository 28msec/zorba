#!/bin/bash -f

cd util
if (!(test -d Build)); then
	mkdir Build;
fi;
make all -f makefile.l
cd ../context
if (!(test -d Build)); then
	mkdir Build;
fi;
make all -f makefile.l
cd ../exprtree
if (!(test -d Build)); then
	mkdir Build;
fi;
make all -f makefile.l
cd ../functions
if (!(test -d Build)); then
	mkdir Build;
fi;
make all -f makefile.l
cd ../listeners
if (!(test -d Build)); then
	mkdir Build;
fi;
make all -f makefile.l
cd ../native_impl
if (!(test -d Build)); then
	mkdir Build;
fi;
make all -f makefile.l
cd ../parser
if (!(test -d Build)); then
	mkdir Build;
fi;
make all -f makefile.l
cd ../runtime
if (!(test -d Build)); then
	mkdir Build;
fi;
make all -f makefile.l
cd ../store
if (!(test -d Build)); then
	mkdir Build;
fi;
make all -f makefile.l
cd ../types
if (!(test -d Build)); then
	mkdir Build;
fi;
make all -f makefile.l
cd ../values
if (!(test -d Build)); then
	mkdir Build;
fi;
make all -f makefile.l

