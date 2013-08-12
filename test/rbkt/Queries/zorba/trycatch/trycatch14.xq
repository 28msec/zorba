
declare namespace op = "http://zorba.io/options/features";

declare option op:disable "scripting";


try { 1 } catch * { delete node <a/> }


