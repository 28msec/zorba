
import schema namespace s = "http://www.xqdoc.org/1.0";

let $hostInfo :=<xqdoc xmlns="http://www.xqdoc.org/1.0">
    <control>
        <date><?processinginstruction aaa?>TS4J5UJ</date>
        <version>N/A</version>
    </control>
    <module type="library">
        <uri>DGQEb8Q</uri>
    </module>
</xqdoc>

return
  validate { $hostInfo }
