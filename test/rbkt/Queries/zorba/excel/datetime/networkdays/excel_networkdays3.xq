import module namespace
excel-datetime = "http://www.zorba-xquery.com/modules/excel/datetime";

excel-datetime:networkdays(xs:date("2008-10-01"), xs:date("2009-03-01"),
(xs:date("2008-11-26"),xs:date("2008-12-04"),xs:date("2009-01-21")))
