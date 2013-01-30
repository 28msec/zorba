import module namespace guestbook = "http://www.28msec.com/guestbook" at "test5.xqlib";


import module namespace db = "http://www.zorba-xquery.com/modules/store/static/collections/ddl";


db:create($guestbook:entries);
