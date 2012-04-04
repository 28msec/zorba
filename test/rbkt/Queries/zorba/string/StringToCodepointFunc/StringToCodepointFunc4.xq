let $n := <root><node>myValue</node></root>
let $v := fn:serialize(
          $n/child::node(),
          <output:serialization-parameters
            xmlns:output="http://www.w3.org/2010/xslt-xquery-serialization">
            <output:method value="xml"/>
            <output:omit-xml-declaration value="yes"/>
            <output:version value="1.0"/>
          </output:serialization-parameters>)
return fn:string-to-codepoints($v)
