This directory contains files that should be hosted on an http server
to support testing of the core and non-core http-client modules of
Zorba.  They are replicated here for reference and as backup.

The following is the Apache 2.4 configuration block for the server where
these files are currently hosted, zorbatest.28.io:8080 :

AddDefaultCharset UTF-8
Listen 8080
<VirtualHost *:8080>
    ServerName zorbatest.28.io
    DocumentRoot /var/www/docroot
    TraceEnable On
    
    <Directory /var/www/docroot>
        Require all granted        
    </Directory>
    
    <Directory /var/www/docroot/http-test-data/basic-auth>
        AuthType Basic
        AuthName "Password Required"
        AuthBasicProvider file
        AuthUserFile /var/www/conf/http-test-data.htpasswd
        Require valid-user
    </Directory>
    
    <Directory /var/www/docroot/cgi-bin>
        Require all granted        
    </Directory>
    
    ScriptAlias /cgi-bin/ /var/www/cgi-bin/
</VirtualHost>

For Apache 2.2 the following configuration can be used:

AddDefaultCharset UTF-8
Listen 8080
<VirtualHost *:8080>
    ServerName zorbatest.28.io
    DocumentRoot /var/www/docroot
    TraceEnable On
    
    <Directory /var/www/docroot/http-test-data/basic-auth>
        AuthType Basic
        AuthName "Password Required"
        AuthBasicProvider file
        AuthUserFile /var/www/conf/http-test-data.htpasswd
        Require valid-user
    </Directory>
    
    ScriptAlias /cgi-bin/ /var/www/cgi-bin/
</VirtualHost>


The named http-test-data.htpasswd file should allow access to a single
user "zorba" with the password "blub".

In addition, PHP should be configured and associated with files ending
in .php, and the server should be able to execute bourne shell scripts
in the /cgi-bin directory as CGI scripts.

Finally, note that all tests explicitly name zorbatest.28.io:8080
and some test results also include that name. So hosting these tests
anywhere else is unlikely to work.
