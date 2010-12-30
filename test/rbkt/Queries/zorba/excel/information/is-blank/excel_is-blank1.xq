import module namespace
excel-information = "http://www.zorba-xquery.com/modules/excel/information";

excel-information:is-blank(()) eq fn:not(excel-information:is-blank((1)))
