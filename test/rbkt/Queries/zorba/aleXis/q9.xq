import module namespace tidy = "http://www.zorba-xquery.com/modules/tidy";

tidy:tidy('<title>Foo</title><p>Foo!','"char-encoding=utf8","newline=LF","tidy-mark=no","quote-nbsp=no"')
