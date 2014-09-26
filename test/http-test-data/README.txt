This directory contains files that should be hosted on an http server
to support testing of the core and non-core http-client modules of
Zorba.  They are replicated here for reference and as backup.

The following is the Apache configuration block for the server where
these files are currently hosted, zorbatest.28.io:8080 :

<VirtualHost *:8080>
    ServerName zorbatest.28.io
    DocumentRoot /home/ceej/zo/www/docroot
    <Directory /home/ceej/zo/www/docroot/http-test-data/basic-auth>
        AuthType Basic
        AuthName "Password Required"
        AuthBasicProvider file
        AuthUserFile /home/ceej/zo/www/conf/http-test-data.htpasswd
        Require valid-user
    </Directory>
    ScriptAlias /cgi-bin/ /home/ceej/zo/www/cgi-bin/
</VirtualHost>

The named http-test-data.htpasswd file should allow access to a single
user "zorba" with the password "blub".

In addition, PHP should be configured and associated with files ending
in .php, and the server should be able to execute bourne shell scripts
in the /cgi-bin directory as CGI scripts.

Finally, note that all tests explicitly name zorbatest.28.io:8080
and some test results also include that name. So hosting these tests
anywhere else is unlikely to work.
