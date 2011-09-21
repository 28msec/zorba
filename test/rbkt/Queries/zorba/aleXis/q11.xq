import module namespace tidy ="http://www.zorba-xquery.com/modules/tidy";

tidy:tidy("<dd>François Yergeau</dd>", '"output-xml=yes","doctype=omit","quote-nbsp=no","char-encoding=utf8","newline=LF","tidy-mark=no"')//*:dd

