declare namespace myns="blah";
declare variable $f external;
count ($f//@myns:att), count ($f//@att)
