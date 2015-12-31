#!/bin/bash
function show_usage()
{
  echo "import_tests.sh <SOURCE_DIR> <BUILD_DIR>"
}

if [ "$#" -ne "2" ]
then
  show_usage
  exit 1
fi

SOURCE_DIR="$1"
BUILD_DIR="$2"

"${SOURCE_DIR}/test/rbkt/Scripts/w3c/import_w3c_testsuite.sh" --builddir "${BUILD_DIR}" "${SOURCE_DIR}" &
"${SOURCE_DIR}/test/rbkt/Scripts/w3c/import_w3c_full_text_testsuite.sh" --builddir "${BUILD_DIR}" "${SOURCE_DIR}" &
"${SOURCE_DIR}/test/update/Scripts/import_w3c_update_testsuite.sh" --builddir "${BUILD_DIR}" "${SOURCE_DIR}" &
cmake -D ZORBA="${BUILD_DIR}/bin/zorba" -D BUILDDIR="${BUILD_DIR}" -P "${SOURCE_DIR}/test/fots/ImportFOTS.cmake" &

FAIL=0
for job in `jobs -p`
do
  wait $job || let "FAIL+=1"
done

if [ $FAIL != "0" ]
then
  exit 1
fi
