module namespace cli = 'http://www.zorba-xquery.com/examples/commandline';

declare namespace ann = "http://www.zorba-xquery.com/annotations";
declare namespace ver = "http://www.zorba-xquery.com/options/versioning";

declare option ver:module-version "1.0";

declare variable $cli:endl as xs:string := "
";

(:~
 : This functions blocks until the user has entered a line
 : on the command line and pressed enter.
 :
 : @return The entered line as a string.
 :)
declare %ann:sequential function cli:get-line() as xs:string external;

(:~
 : This functions prints the given string to the standard output file.
 :
 : @param $string The string to print.
 :)
declare %ann:sequential function cli:print($string as xs:string) as empty-sequence() external;

(:~
 : This functions prints the given string to the standard output file.
 : and appends a new line.
 :
 : @param $string The string to print.
 :)
declare %ann:sequential function cli:print-line($string as xs:string) as empty-sequence() {
  cli:print(concat($string, $cli:endl));
};

