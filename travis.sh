mkdir build && cd build && cmake -DZORBA_XQUERYX:BOOL=1 -DZORBA_TEST_XQUERYX:BOOL=1 -DZORBA_WITH_BIG_INTEGER=1 -DCMAKE_BUILD_TYPE=Release -DZORBA_TEST_PLAN_SERIALIZATION:BOOL=1 -DZORBATEST_USE_MT_XQTS:BOOL=1 .. && make -j2 && make all modules_svg
../test/rbkt/Scripts/w3c/import_w3c_testsuite.sh .. &
../test/rbkt/Scripts/w3c/import_w3c_full_text_testsuite.sh .. &
../test/update/Scripts/import_w3c_update_testsuite.sh .. &
cmake -D ZORBA=bin/zorba -D BUILDDIR=build -P ../test/fots/ImportFOTS.cmake &
make fots-activate-sets
env QTTEST=42 QTTEST2=other QTTESTEMPTY='' ctest -j2 -T Test -E '^zorba_info-extraction_module|conversion/currency-convert' --output-on-failure --no-compress-output
