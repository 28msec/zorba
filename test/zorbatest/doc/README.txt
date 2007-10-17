*** Requirements

* zorba build requirements
* Saxon 8 (requires in turn Sun's Java)


*** Running

cd zorbatest
# only first time
./setup_framework
./integrate


*** Directory hierarchy

testing-+--tests-+--acceptance
        |        +--regression
        +--results


*** Writing tests

To create a new test (say foobar), you start in zorbatest/testing, and 
create two new directories with two new files:

* in tests/acceptance, create foobar/run. This must be an executable 
file (i.e. chmod a+x foobar/run). You can place additional files here if 
you want to. The framework will clone the foobar/ directory every time, 
and run the test from that cloned directory. Any files left behind by 
the test will be copied to the output directory (which is linked to from 
the corresponding report).

* in test_results/acceptance, create foobar/result.txt. This file must 
contain in the first line the string SUCCESS or FAILURE (depending on 
whether you expect foobar/run to exit successfully or return an error 
code), then the expected (textual) output of foobar/run.

Have a look at acceptance/valgring for an example.


*** Custom project files

These scripts should be modified if framework is reused in another 
project:

* build_project

* on_build_failure

* load_test_env

* process_test_results
