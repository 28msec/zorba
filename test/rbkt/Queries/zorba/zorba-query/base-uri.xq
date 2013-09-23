import module namespace zq = "http://zorba.io/modules/zorba-query";

variable $q := zq:prepare-main-module("fn:static-base-uri()");
zq:evaluate($q)