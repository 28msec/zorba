declare variable $tests := <tests/>;

for $test in $tests
let $test_old := $tests[text() eq $test/text()]
let $qt_old := $tests[@name]
return  1
