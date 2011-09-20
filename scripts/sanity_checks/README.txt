The command ./zorba -f -q /tmp/XQTS_current/run_xqts.xq generates:
- /tmp/XQTS_current/conformanceXQTS.dox
- /tmp/XQTS_current/conformanceXQTSSummary.dox
Note: this takes quite a long time because there are over 28000 tests to be processed(14000 XQuery and the same for XQueryX)
Also there are over 580 XQueryX tests for wich there are no results reported in the submission XML.

The command ./zorba -f -q /tmp/XQTS_current/run_xquts.xq generates:
- /tmp/XQUTS_current/conformanceXQUTS.dox
- /tmp/XQUTS_current/conformanceXQUTSSummary.dox

The command ./zorba -f -q /tmp/XQTS_current/run_xqftts.xq generates:
- /tmp/XQFTTS_current/conformanceXQFTTS.dox
- /tmp/XQFTTS_current/conformanceXQFTTSSummary.dox

Here is how the query work:
- they load the correct catalog(XQTSCatalog.xml, XQUTSCatalog.xml or XQFTTSCatalog.xml)
- they load the submission XML's for XQuery and XQueryX
- based on this information they generate the conformance reported; Due to the fact that the output is a .dox page that 
has to be included in the Zorab documentation *only* the tests that have a status other than "pass" are shown.

generate_implementation_defined_features_dox.xq
Run it in order to generate the docygen page:
./zorba --indent -z method=xml --omit-xml-declaration
-f -q ../../scripts/sanity_checks/generate_implementation_defined_features_dox.xq > /home/spungi/work/zorba2/doc/zorba/impl_dep_features.dox