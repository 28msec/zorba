These library modules need the c-client library installed to work properly.
Here are a few notes that should help in doing this.

Building IMAP CClient

Zorba provides email (smtp and imap) support using the CClient library part of thei UW IMAP toolkit found at http://www.washington.edu/imap/.

Unix/Linux/Mac OS
Notes:
  - There are some known issues with the CClient packages that come with diffrent Linux distributions.
  - On x32 bit OpenSuse and also on x64 bit Ubuntu we noticed that the CClient shared library is broken (undefined symbol: mm_dlog).
  - Due to that fact that Mark Crispin (the creator of CClient library) does not support CClient as a shared library but only as a static library (see FAQs shared library at http://www.washington.edu/imap/IMAP-FAQs/index.html#6.3), we strongly suggest you want to get the UW IMAP toolkit</a> and compile it yourself.
- On Linux 64-bit, you might discover a problem with the optional package cclient. E.g. on Ubuntu 64-bit, you might discover the following:

Linking CXX shared library libsmtp.so
/usr/bin/ld: /usr/lib/gcc/x86_64-linux-gnu/4.4.3/../../../../lib/libc-client.a(osdep.o): relocation R_X86_64_32 against
  `server_input_wait' can not be used when making a shared object; recompile with -fPIC
/usr/lib/gcc/x86_64-linux-gnu/4.4.3/../../../../lib/libc-client.a: could not read symbols: Bad value
e
  To fix this, you need to compile CClient yourself. The commands to compile CClient correctly are:
 
cd <some_directory>
wget ftp://ftp.cac.washington.edu/imap/imap-2007e.tar.gz
tar -xf imap-2007e.tar.gz
cd imap-2007e
make slx EXTRACFLAGS="-I/usr/include/openssl -fPIC"
  

  - Also please keep in mind that if SSL/TLS authentication is required by the SMTP server, then you first need to install OpenSSL found at http://www.openssl.org/ and configure CClient to use it.
  - Make sure the name of the library is prefixed by 'lib' and suffixed with '.a' (for example libc-client.a on Linux/Unix or libc-client4.a on Mac OS).

Use the following extra CMake arguments when building Zorba:

-D "CCLIENT_INCLUDE=path_to_imap-2007e\c-client"
-D CCLIENT_LIBRARY=path_to_imap-2007e\c-client\libc-client.a"

Here are some quick suggestions to build CClient on Linux:
- x32-bit Linux: make lnp
- x64-bit Linux: make lnp  EXTRACFLAGS="-I/usr/include/openssl -fPIC" EXTRAAUTHENTICATORS=gss in order to build with SSL and Kerberos support.

For more detailed build instructions please check out the Server Documentation at http://www.washington.edu/imap/documentation and the UW IMAP FAQs at http://www.washington.edu/imap/IMAP-FAQs/index.html

Windows
You must build the UW IMAP toolkit yourself.

Use the following extra CMake arguments when building Zorba:

-D "CCLIENT_INCLUDE=path_to_imap-2007e\c-client"
-D "CCLIENT_LIBRARY=path_to_imap-2007e\c-client\release\cclient.lib"

