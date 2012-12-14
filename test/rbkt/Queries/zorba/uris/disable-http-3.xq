(: Ensure that disabling HTTP URI resolution doesn't defeat fn:doc(). :)
fn:doc("http://zorbatest.lambda.nu:8080/cgi-bin/test-xml?querystring")/body/query
