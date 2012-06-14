
declare namespace op = "http://www.zorba-xquery.com/options/features";

declare option op:disable "scripting";


try { delete node <a/> } catch * { 1 }
