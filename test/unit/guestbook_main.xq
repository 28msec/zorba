import module namespace guestbook = "http://www.28msec.com/templates/guestbook/guestbook" at "@CMAKE_CURRENT_BINARY_DIR@/guestbook.xq";

guestbook:init(), eval { "guestbook:list()" }
