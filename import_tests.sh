"${ZORBA_SRC_DIR}/test/rbkt/Scripts/w3c/import_w3c_testsuite.sh" --builddir "${ZORBA_BUILD_DIR}" "${ZORBA_SRC_DIR}" 
"${ZORBA_SRC_DIR}/test/rbkt/Scripts/w3c/import_w3c_full_text_testsuite.sh" --builddir "${ZORBA_BUILD_DIR}" "${ZORBA_SRC_DIR}" 
"${ZORBA_SRC_DIR}/test/update/Scripts/import_w3c_update_testsuite.sh" --builddir "${ZORBA_BUILD_DIR}" "${ZORBA_SRC_DIR}" 
cmake -D ZORBA="${ZORBA_BUILD_DIR}/bin/zorba" -D BUILDDIR="${ZORBA_BUILD_DIR}" -P "${ZORBA_SRC_DIR}/test/fots/ImportFOTS.cmake"

FAIL=0
for job in `jobs -p`
do
  wait $job || let "FAIL+=1"
done
 
if [ $FAIL != "0" ]
then
  exit 1
fi
