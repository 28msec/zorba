#!/bin/bash
set -e
set -x

echo ====== Download External Modules ====
mkdir -p ../zorba_modules
cmake -Doutdir=../zorba_modules -Dallmodules=1 -P modules/DownloadModules.cmake

echo ====== Build Zorba ======
mkdir -p build && cd build && cmake -DZORBA_XQUERYX:BOOL=1 -DZORBA_TEST_XQUERYX:BOOL=1 -DZORBA_WITH_BIG_INTEGER=1 -DCMAKE_BUILD_TYPE=Release -DZORBA_TEST_PLAN_SERIALIZATION:BOOL=1 -DZORBATEST_USE_MT_XQTS:BOOL=1 .. && make -j8

echo ====== Import Tests ======
../test/rbkt/Scripts/w3c/import_w3c_testsuite.sh .. &
../test/rbkt/Scripts/w3c/import_w3c_full_text_testsuite.sh .. &
../test/update/Scripts/import_w3c_update_testsuite.sh .. &
FAIL=0
for job in `jobs -p`
do
  wait $job || let "FAIL+=1"
done
 
if [ $FAIL != "0" ]
then
  exit 1
fi

echo ====== Import Tests ======
cmake -D ZORBA=./bin/zorba -D BUILDDIR=/home/travis/build/28msec/zorba/build -P ../test/fots/ImportFOTS.cmake
make fots-activate-sets

echo ====== Run Tests ======
env QTTEST=42 QTTEST2=other QTTESTEMPTY='' CLOUDANT_CREDENTIALS=/home/jenkins/rq/dbs/cloudant/credentials.json ctest -j8 -T Test -E '^zorba_info-extraction_module|conversion/currency-convert' --output-on-failure --no-compress-output &
wait $! || FAIL=1
#cmake -D zorba=./bin/zorba -P ../ctest2junit.cmake
exit ${FAIL}
