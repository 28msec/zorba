
echo -e "\nShutdown Apache server"
/usr/sbin/apachectl2 stop

echo -e "\nClear previous intermediate files, if any"
rm -f .libs/* libtest.so mod_xqp.{la,slo,lo} content_handler.{o,slo,lo}
rm -f /lib/apache2/libtest.so /lib/apache2/mod_xqp.{so,la,dll.a}

echo -e "\nCompile content_handler.cpp, create libtest"
g++ -Wall -I/usr/include/apache2 -c content_handler.cpp
g++ -shared -Wl,-soname,libtest.so -o libtest.so content_handler.o
cp -f libtest.so /lib/apache2

echo -e "\nCompile and install mod_xqp.c"
apxs2 -Wl,-rdynamic,-ldl -a -i -c mod_xqp.c

echo -e "\nRestart Apache server"
/usr/sbin/apachectl2 start




