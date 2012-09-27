<xqdoc:xqdoc xmlns:xqdoc="http://www.xqdoc.org/1.0">
  <xqdoc:control>
    <xqdoc:date/>
    <xqdoc:version>1.0</xqdoc:version>
  </xqdoc:control>
  <xqdoc:module type="library">
    <xqdoc:uri>http://www.28msec.com/modules/gdata</xqdoc:uri>
    <xqdoc:name>gdata.xqlib</xqdoc:name>
    <xqdoc:custom tag="namespaces">
      <xqdoc:namespace prefix="atom" uri="http://www.w3.org/2005/Atom" isSchema="true"/>
      <xqdoc:namespace prefix="atompub" uri="http://www.28msec.com/modules/atom" isSchema="false"/>
      <xqdoc:namespace prefix="gdata" uri="http://www.28msec.com/modules/gdata" isSchema="false"/>
      <xqdoc:namespace prefix="rest" uri="http://www.zorba-xquery.com/zorba/rest-functions" isSchema="false"/>
      <xqdoc:namespace prefix="zorba" uri="http://www.zorba-xquery.com/zorba/internal-functions" isSchema="false"/>
    </xqdoc:custom>
  </xqdoc:module>
  <xqdoc:functions>
    <xqdoc:function arity="3">
      <xqdoc:name>gdata:login</xqdoc:name>
      <xqdoc:signature>declare function gdata:login($account as xs:string*, $password as xs:string+, $service as xs:string?) as xs:boolean+</xqdoc:signature>
      <xqdoc:parameters>
        <xqdoc:parameter>
          <xqdoc:name>account</xqdoc:name>
          <xqdoc:type occurrence="*">xs:string</xqdoc:type>
        </xqdoc:parameter>
        <xqdoc:parameter>
          <xqdoc:name>password</xqdoc:name>
          <xqdoc:type occurrence="+">xs:string</xqdoc:type>
        </xqdoc:parameter>
        <xqdoc:parameter>
          <xqdoc:name>service</xqdoc:name>
          <xqdoc:type occurrence="?">xs:string</xqdoc:type>
        </xqdoc:parameter>
      </xqdoc:parameters>
      <xqdoc:return>
        <xqdoc:type occurrence="+">xs:boolean+</xqdoc:type>
      </xqdoc:return>
      <xqdoc:invoked arity="0">
        <xqdoc:uri>http://www.w3.org/2005/xpath-functions</xqdoc:uri>
        <xqdoc:name>current-dateTime</xqdoc:name>
      </xqdoc:invoked>
      <xqdoc:invoked arity="0">
        <xqdoc:uri>http://www.w3.org/2005/xpath-functions</xqdoc:uri>
        <xqdoc:name>false</xqdoc:name>
      </xqdoc:invoked>
      <xqdoc:invoked arity="2">
        <xqdoc:uri>http://www.w3.org/2005/xpath-functions</xqdoc:uri>
        <xqdoc:name>substring-after</xqdoc:name>
      </xqdoc:invoked>
      <xqdoc:invoked arity="0">
        <xqdoc:uri>http://www.w3.org/2005/xpath-functions</xqdoc:uri>
        <xqdoc:name>true</xqdoc:name>
      </xqdoc:invoked>
      <xqdoc:invoked arity="2">
        <xqdoc:uri>http://www.zorba-xquery.com/zorba/rest-functions</xqdoc:uri>
        <xqdoc:name>post</xqdoc:name>
      </xqdoc:invoked>
    </xqdoc:function>
    <xqdoc:function arity="0">
      <xqdoc:name>gdata:get-headers</xqdoc:name>
      <xqdoc:signature>declare function gdata:get-headers() as element(rest:headers)</xqdoc:signature>
      <xqdoc:return>
        <xqdoc:type>element(rest:headers)</xqdoc:type>
      </xqdoc:return>
      <xqdoc:invoked arity="1">
        <xqdoc:uri>http://www.w3.org/2001/XMLSchema</xqdoc:uri>
        <xqdoc:name>QName</xqdoc:name>
      </xqdoc:invoked>
      <xqdoc:invoked arity="2">
        <xqdoc:uri>http://www.w3.org/2005/xpath-functions</xqdoc:uri>
        <xqdoc:name>error</xqdoc:name>
      </xqdoc:invoked>
    </xqdoc:function>
    <xqdoc:function arity="0">
      <xqdoc:name>gdata:get-google-id</xqdoc:name>
      <xqdoc:signature>declare function gdata:get-google-id() as xs:string</xqdoc:signature>
      <xqdoc:return>
        <xqdoc:type>xs:string</xqdoc:type>
      </xqdoc:return>
      <xqdoc:invoked arity="1">
        <xqdoc:uri>http://www.w3.org/2005/xpath-functions</xqdoc:uri>
        <xqdoc:name>encode-for-uri</xqdoc:name>
      </xqdoc:invoked>
    </xqdoc:function>
  </xqdoc:functions>
</xqdoc:xqdoc>
