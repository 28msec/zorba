scanner : xquery_scanner.l
	flex -i -t xquery_scanner.l >xquery_scanner.yy.cpp
	g++ -c -o xquery_scanner.o xquery_scanner.yy.cpp

parser : xquery_parser.y
	bison -v -p xqp -d xquery_parser.y
	g++ -c -o xquery_parser.o xquery_parser.tab.c

driver : xquery_driver.h xquery_driver.cpp
	g++ -c -o xquery_driver.o xquery_driver.cpp

test : xquery_test.cpp
	g++ -o xquery xquery_scanner.o xquery_parser.o xquery_driver.o xquery_test.cpp
