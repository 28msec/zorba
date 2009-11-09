<?xml version="1.0" encoding="UTF-8"?>
<xqdoc:xqdoc xmlns:xqdoc="http://www.xqdoc.org/1.0">
<xqdoc:control>
<xqdoc:date/>
<xqdoc:version>1.0</xqdoc:version>
</xqdoc:control>
<xqdoc:module type="library"><xqdoc:uri>http://www.28msec.com/modules/gdata</xqdoc:uri>
<xqdoc:name>gdata.xqlib</xqdoc:name>
<xqdoc:comment>
<xqdoc:description>The description of this module must have the whitespaces normalized: 1) NL at top, middle &amp; end; 2) TABs in this line; 3) SPACES here and after.</xqdoc:description>
<xqdoc:see>http://example.com</xqdoc:see>
</xqdoc:comment>
</xqdoc:module><xqdoc:imports><xqdoc:import><xqdoc:uri>http://www.zorba-xquery.com/zorba/internal-functions</xqdoc:uri></xqdoc:import>
<xqdoc:import><xqdoc:uri>http://www.28msec.com/modules/atom</xqdoc:uri></xqdoc:import>
<xqdoc:import><xqdoc:uri>http://www.zorba-xquery.com/zorba/rest-functions</xqdoc:uri></xqdoc:import>
</xqdoc:imports>
<xqdoc:variables><xqdoc:variable><xqdoc:uri>version</xqdoc:uri><xqdoc:comment>
<xqdoc:description>Import the Atom XML Schema</xqdoc:description>
<xqdoc:see>http://www.kbcafe.com/rss/atom.xsd.xml</xqdoc:see>
</xqdoc:comment>
</xqdoc:variable>
<xqdoc:variable><xqdoc:uri>id</xqdoc:uri><xqdoc:comment>
<xqdoc:description>Google ID</xqdoc:description>
<xqdoc:see>http://www.google.com</xqdoc:see>
</xqdoc:comment>
</xqdoc:variable>
<xqdoc:variable><xqdoc:uri>authToken</xqdoc:uri></xqdoc:variable>
</xqdoc:variables>
<xqdoc:functions><xqdoc:function><xqdoc:comment>
<xqdoc:description>Google Login</xqdoc:description>
<xqdoc:param>account This parameter will be deleted by the test query.</xqdoc:param>
<xqdoc:param>password This description must have the whitespaces normalized.</xqdoc:param>
<xqdoc:see>http://www.google.com</xqdoc:see>
</xqdoc:comment>
<xqdoc:name>login</xqdoc:name>
<xqdoc:signature>declare function gdata:login($account as xs:string*, $password as xs:string+, $service as xs:string?) as xs:boolean+</xqdoc:signature>
</xqdoc:function>
<xqdoc:function><xqdoc:name>get-headers</xqdoc:name>
<xqdoc:signature>declare function gdata:get-headers() as element(rest:headers)</xqdoc:signature>
</xqdoc:function>
<xqdoc:function><xqdoc:name>get-google-id</xqdoc:name>
<xqdoc:signature>declare function gdata:get-google-id() as xs:string</xqdoc:signature>
</xqdoc:function>
</xqdoc:functions>
</xqdoc:xqdoc>