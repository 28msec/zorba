Requirements:

* zorba build requirements
* Saxon (requires itself Sun's Java)

Running:

cd zorbatest
# only first time
./setup_framework
./integrate

Directory hierarchy:

testing-+--tests-+--acceptance
        |        +--regression
        +--results


Custom project files (should be modified if framework is reused in 
another project):

* build_project

* on_build_failure

* load_test_env

* process_test_results
