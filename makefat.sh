#!/bin/sh
#
#   This script is to be used to build Universal binaries of the ICU
# libraries on Mac OS X.  Universal binaries can not be built for the
# ICU libraries on single machine because the ICU configure script
# checks for endianess (see line 507 of its configure.in).  Thus we
# must use lipo to combine binaries built from separate machines which
# is what this script does.
#
# place this file in the ICU source/lib directory of the build on the host
# archecture and run it from there before doing "make install".
#
# author: Paul F. Kunz <paulfkunz@gmail.com>
# Oct 27, 2008
#
# where the libs built on the other architecure are built
OTHERLIBS=../../../libicu38

ver=38.1
lib1=libicudata.$ver.dylib
lib2=libicui18n.$ver.dylib
lib3=libicuio.$ver.dylib
lib4=libicule.$ver.dylib
lib5=libiculx.$ver.dylib
lib6=libicutu.$ver.dylib
lib7=libicuuc.$ver.dylib

lipo -create $lib1 $OTHERLIBS/$lib1 -output $lib1.fat
lipo -create $lib2 $OTHERLIBS/$lib2 -output $lib2.fat
lipo -create $lib3 $OTHERLIBS/$lib3 -output $lib3.fat
lipo -create $lib4 $OTHERLIBS/$lib4 -output $lib4.fat
lipo -create $lib5 $OTHERLIBS/$lib5 -output $lib5.fat
lipo -create $lib6 $OTHERLIBS/$lib6 -output $lib6.fat
lipo -create $lib7 $OTHERLIBS/$lib7 -output $lib7.fat

mv $lib1.fat $lib1
mv $lib2.fat $lib2
mv $lib3.fat $lib3
mv $lib4.fat $lib4
mv $lib5.fat $lib5
mv $lib6.fat $lib6
mv $lib7.fat $lib7


