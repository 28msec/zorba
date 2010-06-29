import module namespace tidy = "http://www.zorba-xquery.com/modules/tidy";

tidy:tidy('<title>Foo</title><p>Foo!','"bare=yes", "indent=yes"');

