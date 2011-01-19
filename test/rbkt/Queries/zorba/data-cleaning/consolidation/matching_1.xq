import module namespace con = "http://www.zorba-xquery.com/modules/data-cleaning/consolidation";

con:matching( ( "a A b", "c AAA d", "e BB f"), "A+" )