import module namespace
excel="http://www.zorba-xquery.com/modules/excel/lookup";

(: vector form :)
excel:lookup(".2", ("11", "12", "13"), (11, 12, 13, 14))

(:
Output: Error [XQP0021] Lookup function: lookup value is smaller than any vector values 
:)