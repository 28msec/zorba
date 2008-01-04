<missing-variable>{
for $x in fn:doc("/home/markos/zorba/xquery/test/rbkt/Queries/w3c_testsuite/XQTSCatalog.xml")//*:input-file[count(@variable) = 0 and ./text() != "emptydoc"]
return string($x/../@name)
}</missing-variable>
