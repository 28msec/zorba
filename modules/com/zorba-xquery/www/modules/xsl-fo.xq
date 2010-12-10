(:
 : Copyright 2006-2009 The FLWOR Foundation.
 :
 : Licensed under the Apache License, Version 2.0 (the "License");
 : you may not use this file except in compliance with the License.
 : You may obtain a copy of the License at
 :
 : http://www.apache.org/licenses/LICENSE-2.0
 :
 : Unless required by applicable law or agreed to in writing, software
 : distributed under the License is distributed on an "AS IS" BASIS,
 : WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 : See the License for the specific language governing permissions and
 : limitations under the License.
:)
(:~
 : This module uses Apache-FOP to generate content from a xsl-fo. Apache-FOP supports
 : several output formats. See <a href="http://xmlgraphics.apache.org/fop/">the Apache FOP
 : documentation</a> for further information.
 :
 : @author Markus Pilman
 :)
module namespace xsl-fo = "http://www.zorba-xquery.com/modules/xsl-fo";

import module namespace file = "http://www.zorba-xquery.com/modules/file";
import module namespace os = "http://www.zorba-xquery.com/modules/os";

(:~
 : This is the name of the error which gets thrown, if zorba is unable
 : to start a JVM.
 :)
declare variable $xsl-fo:VM001 as xs:QName := xs:QName("xsl-fo:VM001");
(:~
 : This is the name of the error which gets thrown, if Apache throws an exception
 : - the Java stack trace will be part of the description.
 :)
declare variable $xsl-fo:JAVA-EXCEPTION as xs:QName := xs:QName("xsl-fo:JAVA-EXCEPTION");
(:~
 : This is the name of the error which gets thrown, if zorba is unable to
 : find a required JAR library.
 :)
declare variable $xsl-fo:JAR-NOT-FOUND as xs:QName := xs:QName("xsl-fo:JAR_NOT_FOUND");

(:~
 : The mime type of IBMs AFP format.
 :)
declare variable $xsl-fo:AFP as xs:string := "application/x-afp";
(:~
 : The mime type of the EPS format.
 :)
declare variable $xsl-fo:EPS as xs:string := "application/postscript";
(:~
 : The mime type of the PCL format.
 :)
declare variable $xsl-fo:PCL as xs:string := "application/x-pcl";
(:~
 : The mime type of the PDF format.
 :)
declare variable $xsl-fo:PDF as xs:string := "application/pdf";
(:~
 : The mime type for plain text files.
 :)
declare variable $xsl-fo:PLAIN_TEXT as xs:string := "text/plain";
(:~
 : The mime type of the PNG format.
 :)
declare variable $xsl-fo:PNG as xs:string := "image/png";
(:~
 : The mime type of the postscript format.
 :)
declare variable $xsl-fo:POSTSCRIPT as xs:string := "application/postscript";
(:~
 : The mime type of the RTF format.
 :)
declare variable $xsl-fo:RTF as xs:string := "application/rtf";
(:~
 : The mime type of TIFF format.
 :)
declare variable $xsl-fo:TIFF as xs:string := "image/tiff";

(:~
 : The generator function takes an xsl-fo as input and generates output in the format given as input.
 : The output format can be given as a Mime - for example "application/pdf" - or one of the predefines
 : variables can be used - like $xsl-fo:PDF. Please refer to the Apache FOP documentation for documentation
 : about the supported ouput formats.
 :
 : Apache FOP does not support 100% of the XSL-FO standard. Please consult the official documentation,
 : for further information.
 :
 : @param $output-format The mime of the output format, to tell Apache FOP which kind of document it should
 :        create.
 : @param $xsl-fo-document The xsl-fo node, from which the document should be generated.
 : @param $classpath The classpath which has to contain Apache FOP and all its dependencies. If you don't
 :        want to set this programmatically, use the generator function without this parameter instead.
 : @return The generated output document.
 : @error VM001 if zorba was unable to start the JVM.
 : @error JAVA-EXCEPTION If Apache FOP throws an exception - i.e. if the input format is not correct/supported.
 :)
declare function xsl-fo:generator($output-format as xs:string, $xsl-fo-document as node(), $classpath as xs:string+) as xs:base64Binary {
  let $os as xs:string := os:operating-system()
  let $dir-separator as xs:string := if ($os eq "Windows") then ";" else ":"
  return xsl-fo:generator-impl($output-format, $xsl-fo-document, fn:string-join($classpath, $dir-separator))
};

(:~
 : The function behaves like generator#3, but tries to find the needed Java libraries itself.
 : On a Mac OS X computer, it should be sufficient to install Apache FOP via Mac Ports, on
 : Ubuntu it should be sufficient to install the fop packages via apt-get.
 :
 : This function tries to find the jar files via envroinment variables. The user can set the
 : variable FOP_HOME to the root directory of an Apache FOP distribution. If you have all
 : Jar files in the same directory, you can set the envroinment variable FOP_LIB_DIR to this
 : directory.
 :
 : @param $output-format The mime of the output format, to tell Apache FOP which kind of document it should
 :        create.
 : @param $xsl-fo-document The xsl-fo node, from which the document should be generated.
 : @return The generated output document.
 : @error VM001 if zorba was unable to start the JVM.
 : @error JAVA-EXCEPTION If Apache FOP throws an exception - i.e. if the input format is not correct/supported.
 : @error JAR-NOT-FOUND If a needed Java library could not be found.
 :)
declare function xsl-fo:generator($output-format as xs:string, $xsl-fo-document as node()) as xs:base64Binary {
  let $os as xs:string := os:operating-system()
  let $fop-home as xs:string? :=
    if (fn:not(os:get-env("FOP_HOME"))) then
      if ($os eq "Mac OS X") then
        let $f := fn:concat("/opt/local/share/java/fop/", xs:string((
          for $d in
              for $dir in file:files("/opt/local/share/java/fop", "[0-9]+\.[0-9]+")
              where file:is-directory(fn:concat("/opt/local/share/java/fop/", $dir))
              return $dir
          order by xs:decimal($d) descending
          return $d)[1]))
        return
          if (file:exists($f) and file:is-directory($f)) then
            $f
          else
            ()
      else ()
    else os:get-env("FOP_HOME") 
  let $fop-lib-dir as xs:string? :=
    if (os:get-env("FOP_LIB_DIR")) then
      os:get-env("FOP_LIB_DIR")
    else if ($os eq "Linux") then
      "/usr/share/java"
    else ()
  let $fop-jar-file as xs:string :=
    if ($fop-home or $fop-lib-dir) then 
      if (file:exists(fn:concat($fop-home, file:path-separator(), "build", file:path-separator(), "fop.jar"))) then
        fn:concat($fop-home, file:path-separator(), "build", file:path-separator(), "fop.jar")
      else if (file:exists(fn:concat($fop-lib-dir, file:path-separator(), "fop.jar"))) then
        fn:concat($fop-lib-dir, file:path-separator(), "fop.jar")
      else
        fn:error($xsl-fo:JAR-NOT-FOUND,
          fn:concat("Could not find fop.jar. If you are using Ubuntu or Mac OS X, please make sure,
           that you have installed it, else make sure, that you have set the envroinment variable
           FOP_HOME or FOP_LIB_DIR correctly.
           tried ", fn:concat($fop-home, file:path-separator(), "build",
           file:path-separator(), "fop.jar"), "
           and ",
           fn:concat($fop-lib-dir, file:path-separator(), "fop.jar"), " with FOP_HOME=",
           $fop-home, " and FOP_LIB_DIR=", $fop-lib-dir))
    else
      fn:error($xsl-fo:JAR-NOT-FOUND,
        "None of the envroinment variables FOP_HOME and FOP_LIB_DIR has bin set.")
  let $classpath as xs:string* :=
    ($fop-jar-file, for $jar in ("avalon-framework", "batik-all", "commons-io", "commons-logging", "serializer",
                 "xalan", "xmlgraphics-commons")
    let $jar-dir as xs:string :=
      if ($fop-home) then
        fn:concat($fop-home, file:path-separator(), "lib")
      else
        $fop-lib-dir
    let $res as xs:string := fn:concat($jar-dir, file:path-separator(), file:files($jar-dir, fn:concat($jar, ".*\.jar"))[1])
    return
      if (file:exists($res) and fn:not(file:is-directory($res))) then
        $res
      else
        fn:error($xsl-fo:JAR-NOT-FOUND, fn:concat("Could not find ", $jar)))
  return xsl-fo:generator($output-format, $xsl-fo-document, $classpath)
};

declare %private function xsl-fo:generator-impl($output-format as xs:string, $xsl-fo-document as node(), $classpath as xs:string) external;
