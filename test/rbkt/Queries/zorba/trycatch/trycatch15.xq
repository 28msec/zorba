
declare namespace op = "http://zorba.io/options/features";

declare option op:disable "scripting";


try { delete node <a/> } catch * { 1 }
