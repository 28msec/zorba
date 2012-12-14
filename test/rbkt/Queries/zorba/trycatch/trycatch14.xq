
declare namespace op = "http://www.zorba-xquery.com/options/features";

declare option op:disable "scripting";


try { 1 } catch * { delete node <a/> }


