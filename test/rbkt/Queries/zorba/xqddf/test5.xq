import module namespace guestbook = "http://www.28msec.com/guestbook" at "test5.xqlib";


import module namespace db = "http://zorba.io/modules/store/static/collections/ddl";


db:create($guestbook:entries);
