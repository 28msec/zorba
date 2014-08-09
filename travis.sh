#!/bin/bash
set -e

ZORBA_SRC_DIR="$( cd "$( dirname "${BASH_SOURCE[0]}" )" && pwd )"
ZORBA_BUILD_DIR="${ZORBA_SRC_DIR}/build"
ZORBA_MODULE_DIR="${ZORBA_SRC_DIR}/../zorba_modules"

set -x

echo "================================================================================"
echo "ZORBA_SRC_DIR ${ZORBA_SRC_DIR}"
echo "ZORBA_BUILD_DIR ${ZORBA_BUILD_DIR}"
echo "ZORBA_MODULE_DIR ${ZORBA_MODULE_DIR}"

echo "================================================================================"
mkdir -p "${ZORBA_MODULE_DIR}"
cmake -Doutdir="${ZORBA_MODULE_DIR}" -Dallmodules=1 -P "${ZORBA_SRC_DIR}/modules/DownloadModules.cmake"

echo "================================================================================"
mkdir -p "${ZORBA_BUILD_DIR}"
cd "${ZORBA_BUILD_DIR}"
cmake -DZORBA_XQUERYX:BOOL=1 -DZORBA_TEST_XQUERYX:BOOL=1 -DZORBA_WITH_BIG_INTEGER=1 -DCMAKE_BUILD_TYPE=Release -DZORBA_TEST_PLAN_SERIALIZATION:BOOL=1 -DZORBATEST_USE_MT_XQTS:BOOL=1 "${ZORBA_SRC_DIR}"
make -j8

echo "================================================================================"
"${ZORBA_SRC_DIR}/test/rbkt/Scripts/w3c/import_w3c_testsuite.sh" "${ZORBA_SRC_DIR}" &
"${ZORBA_SRC_DIR}/test/rbkt/Scripts/w3c/import_w3c_full_text_testsuite.sh" "${ZORBA_SRC_DIR}" &
"${ZORBA_SRC_DIR}/test/update/Scripts/import_w3c_update_testsuite.sh" "${ZORBA_SRC_DIR}" &
FAIL=0
for job in `jobs -p`
do
  wait $job || let "FAIL+=1"
done
 
if [ $FAIL != "0" ]
then
  exit 1
fi

echo "================================================================================"
cmake -D ZORBA="${ZORBA_BUILD_DIR}/bin/zorba" -D BUILDDIR="${ZORBA_BUILD_DIR}" -P "${ZORBA_SRC_DIR}/test/fots/ImportFOTS.cmake"
make fots-activate-sets

echo "================================================================================"
#export CLOUDANT_CREDENTIALS=/home/jenkins/rq/dbs/cloudant/credentials.json
env QTTEST=42 QTTEST2=other QTTESTEMPTY='' ctest -j8 -T Test -E '^zorba_info-extraction_module|conversion/currency-convert' --output-on-failure --no-compress-output &
wait $! || FAIL=1
#cmake -D zorba="${ZORB_BUILD_DIR}/bin/zorba" -P "${ZORBA_SRC_DIR}/ctest2junit.cmake"
exit ${FAIL}
