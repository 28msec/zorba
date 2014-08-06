#!/bin/bash
sudo apt-get update -qq
sudo apt-get install libicu-dev libxml2-dev uuid-dev libxerces-c-dev graphviz libboost-filesystem-dev libgeos++-dev imagemagick libmagick++-dev libmagickwand-dev libfop-java libpdfbox-java libtidy-dev libjempbox-java libfontbox-java libarchive-dev libmysqlclient-dev swig python-dev php5-dev ruby-dev openjdk-6-jdk libaccess-bridge-java-jni libxslt-dev libcurl4-openssl-dev libxerces-c-dev php5-dev doxygen libedit-dev php5 python-dev libkvutils-dev
sudo apt-get remove bison flex
sudo locale-gen de_DE && sudo locale-gen de_DE.UTF-8 && sudo locale-gen fr_FR && sudo locale-gen fr_FR.UTF-8 && sudo update-locale

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
cmake -D ZORBA="${ZORB_BUILD_DIR}/bin/zorba" -D BUILDDIR="${ZORBA_BUILD_DIR}" -P "${ZORBA_SRC_DIR}/test/fots/ImportFOTS.cmake"
make fots-activate-sets


