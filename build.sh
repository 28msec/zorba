#!/bin/bash -f

cd util
echo ""; echo "- util -"
if (!(test -d Build)); then
	mkdir Build;
fi;
make all -f makefile.l
cd ../context
echo ""; echo "- context -"
if (!(test -d Build)); then
	mkdir Build;
fi;
make all -f makefile.l
cd ../exprtree
echo ""; echo "- exprtree -"
if (!(test -d Build)); then
	mkdir Build;
fi;
make all -f makefile.l
cd ../functions
echo ""; echo "- functions -"
if (!(test -d Build)); then
	mkdir Build;
fi;
make all -f makefile.l
cd ../listeners
echo ""; echo "- listeners -"
if (!(test -d Build)); then
	mkdir Build;
fi;
make all -f makefile.l
cd ../native_impl
echo ""; echo "- native_impl -"
if (!(test -d Build)); then
	mkdir Build;
fi;
make all -f makefile.l
cd ../parser
echo ""; echo "- parser -"
if (!(test -d Build)); then
	mkdir Build;
fi;
make all -f makefile.l
cd ../runtime
echo ""; echo "- runtime -"
if (!(test -d Build)); then
	mkdir Build;
fi;
make all -f makefile.l
cd ../store
echo ""; echo "- store -"
if (!(test -d Build)); then
	mkdir Build;
fi;
make all -f makefile.l
cd ../types
echo ""; echo "- types -"
if (!(test -d Build)); then
	mkdir Build;
fi;
make all -f makefile.l
cd ../values
echo ""; echo "- values -"
if (!(test -d Build)); then
	mkdir Build;
fi;
make all -f makefile.l

cd ../context
echo ""; echo "- context unit tests -"
make test -f makefile.l
cd ../exprtree
echo ""; echo "- exprtree unit tests -"
make test -f makefile.l
cd ../functions
echo ""; echo "- functions unit tests -"
make test -f makefile.l
cd ../listeners
echo ""; echo "- listeners unit tests -"
make test -f makefile.l
cd ../native_impl
echo ""; echo "- native_impl unit tests -"
make test -f makefile.l
cd ../parser
echo ""; echo "- parser unit tests -"
make test -f makefile.l
cd ../runtime
echo ""; echo "- runtime unit tests -"
make test -f makefile.l
cd ../store
echo ""; echo "- store unit tests -"
make test -f makefile.l
cd ../types
echo ""; echo "- types unit tests -"
make test -f makefile.l
cd ../values
echo ""; echo "- values unit tests -"
make test -f makefile.l

