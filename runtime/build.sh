
echo "Compile mod_xqp.c"
/usr/share/apr-1-build/libtool --silent --mode=compile gcc -prefer-pic -O2 \
  -DCYGWIN  -I/usr/include/apache2 -I/usr/include/apr-1   -I/usr/include/apr-1 \
  -I/usr/include  -c -o mod_xqp.lo mod_xqp.c && touch mod_xqp.slo

echo "Compile content_handler.cpp" 
/usr/share/apr-1-build/libtool --silent --mode=compile g++ -prefer-pic -O2 \
  -DCYGWIN  -I/usr/include/apache2 -I/usr/include/apr-1 -I/usr/include  \
  -c -o content_handler.lo content_handler.cpp && touch content_handler.slo
 
echo "Link"
/usr/share/apr-1-build/libtool --silent --mode=link gcc -o mod_xqp.la  \
  -rpath /usr/lib/apache2 -module -avoid-version -no-undefined -shrext .so \
  /usr/lib/libhttpd2core.la \
  -L/usr/lib /usr/lib/libaprutil-1.la -lgdbm -ldb-4.2 -lexpat -liconv \
  /usr/lib/libapr-1.la -lcrypt content_handler.lo mod_xqp.lo
  
#/lib/gcc/i686-pc-mingw32/3.4.4/libstdc++.la \
  
echo "Create library file .libs/mod_xqp.dll.a"
/usr/share/apache2/build/instdso.sh \
  SH_LIBTOOL='/usr/share/apr-1-build/libtool' mod_xqp.la /usr/lib/apache2
  
  
/usr/share/apr-1-build/libtool --mode=install cp mod_xqp.la /usr/lib/apache2/

echo "install libraries"
cp .libs/mod_xqp.dll.a /usr/lib/apache2/mod_xqp.dll.a
cp .libs/mod_xqp.so /usr/lib/apache2/mod_xqp.so
chmod a+x /usr/lib/apache2/mod_xqp.so
cp .libs/mod_xqp.lai /lib/apache2/mod_xqp.la

echo "finish"
libtool --finish /usr/lib/apache2


