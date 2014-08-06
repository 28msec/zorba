#!/bin/bash
set -e

ZORBA_SRC_DIR="$( cd "$( dirname "${BASH_SOURCE[0]}" )" && pwd )"
ZORBA_BUILD_DIR="${ZORBA_SRC_DIR}/build"
ZORBA_MODULE_DIR="${ZORBA_SRC_DIR}/../zorba_modules"

set -x

echo "================================================================================"
#export CLOUDANT_CREDENTIALS=/home/jenkins/rq/dbs/cloudant/credentials.json
env QTTEST=42 QTTEST2=other QTTESTEMPTY='' ctest -j8 -T Test -E '^zorba_info-extraction_module|conversion/currency-convert' -R $TEST_FOLDER --output-on-failure --no-compress-output &
wait $! || FAIL=1
#cmake -D zorba="${ZORB_BUILD_DIR}/bin/zorba" -P "${ZORBA_SRC_DIR}/ctest2junit.cmake"
exit ${FAIL}
