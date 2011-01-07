import module namespace
excel="http://www.zorba-xquery.com/modules/excel/statistical";

excel:percentile((1, 3, 4, 3, 2, 2, 5, 3, 5), 5)

(:
Output: Error [XQP0021] Percentile function: k must be a value between 0 and 1 inclusive
:)