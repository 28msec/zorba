1) compile Zorba by setting the following flags:
cmake -DZORBA_TEST_XQUERYX=ON -DZORBA_XQUERYX=ON -DZORBA_WITH_BIG_INTEGER=ON -DZORBA_TEST_W3C_TO_SUBMIT_RESULTS=ON -DZORBA_MODULES_DIR="/home" ..

2) import the 3 testsuites by running:
$zorbaDir/test/rbkt/Scripts/w3c/import_w3c_testsuite.sh $zorbaDir
$zorbaDir/test/rbkt/Scripts/w3c/import_w3c_full_text_testsuite.sh $zorbaDir
$zorbaDir/test/update/Scripts/import_w3c_update_testsuite.sh $zorbaDir

3) Generate the conformance reports following the details provided in:
  - test/rbtk/Scripts/w3c/Readme.txt
  - test/update/Scripts/Readme.txt
The latest reports can also be downloaded from the private wiki: http://my.zorba-xquery.com/dokuwiki/doku.php

4.1) The command ./zorba -f -q ../../scripts/sanity_checks/run_xqts.xq generates:
- /tmp/XQTS_current/conformanceXQTS.dox
- /tmp/XQTS_current/conformanceXQTSSummary.dox
Note: this should take around 2 minutes because there are over 28000 tests to be processed(14000 XQuery and the same for XQueryX)
Also there are over 402 XQueryX tests for which there are no results reported in the submission XML.

4.2) The command ./zorba -f -q ../../scripts/sanity_checks/run_xquts.xq generates:
- /tmp/XQUTS_current/conformanceXQUTS.dox
- /tmp/XQUTS_current/conformanceXQUTSSummary.dox

4.3) The command ./zorba -f -q ../../scripts/sanity_checks/run_xqftts.xq generates:
- /tmp/XQFTTS_current/conformanceXQFTTS.dox
- /tmp/XQFTTS_current/conformanceXQFTTSSummary.dox


Here is how the query work:
- they load the correct catalog(XQTSCatalog.xml, XQUTSCatalog.xml or XQFTTSCatalog.xml)
- they load the submission XML's for XQuery and XQueryX
- based on this information they generate the conformance reported; Due to the fact that the output is a .dox page that 
has to be included in the Zorab documentation *only* the tests that have a status other than "pass" are shown.

generate_implementation_defined_features_dox.xq
Run it in order to generate the docygen page:
./zorba --indent -z method=xml --omit-xml-declaration -f -q ../../scripts/sanity_checks/generate_implementation_defined_features_dox.xq > ../../doc/zorba/impl_dep_features.dox
