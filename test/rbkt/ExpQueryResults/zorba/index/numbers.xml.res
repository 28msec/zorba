<?xml version="1.0" encoding="UTF-8"?>

-------------------------------------
Probing long keys with a double
-------------------------------------

probe 1 (eq - hash):

<xs_long num="9223372036854770178"/><xs_long num="9223372036854770688" noloss="t"/><xs_long num="9223372036854770888"/>

probe 2 (eq - hash):

<xs_long num="9223372036854770178"/><xs_long num="9223372036854770688" noloss="t"/><xs_long num="9223372036854770888"/>

probe 3 (gt):

<xs_long num="9223372036854771200"/>

probe 4 (ge):

<xs_long num="9223372036854770178"/><xs_long num="9223372036854770688" noloss="t"/><xs_long num="9223372036854770888"/><xs_long num="9223372036854771200"/>
