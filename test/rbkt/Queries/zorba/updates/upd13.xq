import module namespace doc = "http://zorba.io/modules/store/documents";

put(attribute {"test"}{"test"},"http://www.zorba-xquery.com");
doc:document("http://www.zorba-xquery.com")
