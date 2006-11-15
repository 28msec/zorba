scanner : xquery.l
	flex -i -t xquery.l >xquery.yy.cpp

parser : xquery.y
	bison -p xqp -d xquery.y
