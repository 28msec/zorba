../test/rbkt/Scripts/w3c/import_w3c_testsuite.sh .. &
../test/rbkt/Scripts/w3c/import_w3c_full_text_testsuite.sh .. &
../test/update/Scripts/import_w3c_update_testsuite.sh .. &
cmake -D ZORBA=bin/zorba -D BUILDDIR=build -P ../test/fots/ImportFOTS.cmake &
 
FAIL=0
for job in `jobs -p`
do
  wait $job || let "FAIL+=1"
done
 
if [ $FAIL != "0" ]
then
  exit 1
fi
 
make fots-activate-sets

env QTTEST=42 QTTEST2=other QTTESTEMPTY='' CLOUDANT_CREDENTIALS=/home/jenkins/rq/dbs/cloudant/credentials.json ctest -j2 -T Test -E '^zorba_info-extraction_module|conversion/currency-convert' --output-on-failure --no-compress-output &
wait $! || FAIL=1
cmake -D zorba=/usr/bin/zorba -P /home/jenkins/rq/ctest2junit.cmake
exit ${FAIL}
