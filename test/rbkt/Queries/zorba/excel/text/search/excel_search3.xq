import module namespace
excel-text = "http://www.zorba-xquery.com/modules/excel/text";

excel-text:replace("Profit Margin",excel-text:search("margin","Profit Margin"),6,"Amount")
