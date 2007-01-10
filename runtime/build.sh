BUILD=Build

echo -e "\nShutdown Apache server"
/usr/sbin/apachectl2 stop

echo -e "\nClear previous intermediate files, if any"
rm -f .libs/* libtest.so mod_xqp.{la,slo,lo} content_handler.{o,slo,lo}
rm -f /lib/apache2/libtest.so /lib/apache2/mod_xqp.{so,la,dll.a}

echo -e "\nCompile content_handler.cpp, create libtest"
g++ -Wall -I/usr/include/apache2 -c content_handler.cpp
g++ -shared -Wl,-soname,libtest.so -o libtest.so \
  ../datamodel/${BUILD}/qname.do \
  ../util/${BUILD}/xqp_exception.o \
  ../util/${BUILD}/tokenbuf.do \
  ../util/${BUILD}/file.do \
  ../util/${BUILD}/mmfile.do \
  ../util/${BUILD}/fxcharheap.do \
  ../util/${BUILD}/URI.do \
  ../parser/${BUILD}/parsenodes.do \
  ../parser/${BUILD}/xquery_scanner.do \
  ../parser/${BUILD}/xquery_parser.do \
  ../parser/${BUILD}/symbol_table.do \
  ../parser/${BUILD}/xquery_driver.do \
  content_handler.o
  
cp -f libtest.so /lib/apache2

echo -e "\nCompile and install mod_xqp.c"
apxs2 -Wl,-rdynamic,-ldl -a -i -c mod_xqp.c

echo -e "\nRestart Apache server"
/usr/sbin/apachectl2 start




