<xqdoc:xqdoc xmlns:xqdoc="http://www.xqdoc.org/1.0">
  <xqdoc:control>
    <xqdoc:date/>
    <xqdoc:version>1.0</xqdoc:version>
  </xqdoc:control>
  <xqdoc:module type="library">
    <xqdoc:uri>http://www.zorba-xquery.com/collindex</xqdoc:uri>
    <xqdoc:name>collindex.xqlib</xqdoc:name>
    <xqdoc:custom tag="namespaces">
      <xqdoc:namespace prefix="an" uri="" isSchema="false"/>
      <xqdoc:namespace prefix="cache" uri="http://www.28msec.com/modules/http/util/cache" isSchema="false"/>
      <xqdoc:namespace prefix="cil" uri="http://www.zorba-xquery.com/collindex" isSchema="false"/>
      <xqdoc:namespace prefix="ddl" uri="http://www.zorba-xquery.com/modules/store/static/collections/ddl" isSchema="false"/>
      <xqdoc:namespace prefix="dml" uri="http://www.zorba-xquery.com/modules/store/static/collections/dml" isSchema="false"/>
      <xqdoc:namespace prefix="functx" uri="http://www.functx.com/" isSchema="false"/>
      <xqdoc:namespace prefix="idml" uri="http://www.zorba-xquery.com/modules/store/static/indexes/dml" isSchema="false"/>
      <xqdoc:namespace prefix="req" uri="http://www.28msec.com/modules/http/request" isSchema="false"/>
      <xqdoc:namespace prefix="resp" uri="http://www.28msec.com/modules/http/response" isSchema="false"/>
    </xqdoc:custom>
  </xqdoc:module>
  <xqdoc:imports>
    <xqdoc:import type="library">
      <xqdoc:uri>http://www.functx.com/</xqdoc:uri>
    </xqdoc:import>
    <xqdoc:import type="library">
      <xqdoc:uri>http://www.28msec.com/modules/http/request</xqdoc:uri>
    </xqdoc:import>
    <xqdoc:import type="library">
      <xqdoc:uri>http://www.28msec.com/modules/http/response</xqdoc:uri>
    </xqdoc:import>
    <xqdoc:import type="library">
      <xqdoc:uri>http://www.28msec.com/modules/http/util/cache</xqdoc:uri>
    </xqdoc:import>
    <xqdoc:import type="library">
      <xqdoc:uri>http://www.zorba-xquery.com/modules/store/static/collections/ddl</xqdoc:uri>
    </xqdoc:import>
    <xqdoc:import type="library">
      <xqdoc:uri>http://www.zorba-xquery.com/modules/store/static/collections/dml</xqdoc:uri>
    </xqdoc:import>
    <xqdoc:import type="library">
      <xqdoc:uri>http://www.zorba-xquery.com/modules/store/static/indexes/dml</xqdoc:uri>
    </xqdoc:import>
  </xqdoc:imports>
  <xqdoc:variables>
    <xqdoc:variable>
      <xqdoc:uri>cil:entries</xqdoc:uri>
      <xqdoc:invoked arity="1">
        <xqdoc:uri>http://www.w3.org/2001/XMLSchema</xqdoc:uri>
        <xqdoc:name>QName</xqdoc:name>
      </xqdoc:invoked>
    </xqdoc:variable>
    <xqdoc:variable>
      <xqdoc:uri>cil:idx</xqdoc:uri>
      <xqdoc:invoked arity="1">
        <xqdoc:uri>http://www.w3.org/2001/XMLSchema</xqdoc:uri>
        <xqdoc:name>QName</xqdoc:name>
      </xqdoc:invoked>
    </xqdoc:variable>
  </xqdoc:variables>
  <xqdoc:collections>
    <xqdoc:collection>
      <xqdoc:name>entries</xqdoc:name>
      <xqdoc:comment>
        <xqdoc:description> some comment
</xqdoc:description>
        <xqdoc:custom tag="type">element(el)*</xqdoc:custom>
      </xqdoc:comment>
      <xqdoc:annotations>
        <xqdoc:annotation prefix="an" namespace="" localname="ordered" value=""/>
      </xqdoc:annotations>
    </xqdoc:collection>
    <xqdoc:collection>
      <xqdoc:name>entries2</xqdoc:name>
      <xqdoc:comment>
        <xqdoc:description> some comment2
</xqdoc:description>
      </xqdoc:comment>
      <xqdoc:annotations>
        <xqdoc:annotation prefix="an" namespace="" localname="ordered" value=""/>
      </xqdoc:annotations>
    </xqdoc:collection>
    <xqdoc:collection>
      <xqdoc:name>entries3</xqdoc:name>
      <xqdoc:comment>
        <xqdoc:description> some comment3
</xqdoc:description>
        <xqdoc:custom tag="type">element(el)*</xqdoc:custom>
      </xqdoc:comment>
    </xqdoc:collection>
    <xqdoc:collection>
      <xqdoc:name>entries4</xqdoc:name>
      <xqdoc:comment>
        <xqdoc:description> some comment4
</xqdoc:description>
      </xqdoc:comment>
    </xqdoc:collection>
  </xqdoc:collections>
  <xqdoc:indexes>
    <xqdoc:index>
      <xqdoc:name>idx</xqdoc:name>
      <xqdoc:source>
        <xqdoc:uri>http://www.zorba-xquery.com/collindex</xqdoc:uri>
        <xqdoc:name>entries</xqdoc:name>
      </xqdoc:source>
      <xqdoc:comment>
        <xqdoc:description> some comment5
</xqdoc:description>
      </xqdoc:comment>
      <xqdoc:annotations>
        <xqdoc:annotation prefix="an" namespace="" localname="automatic" value=""/>
        <xqdoc:annotation prefix="an" namespace="" localname="unique" value=""/>
        <xqdoc:annotation prefix="an" namespace="" localname="value-equality" value=""/>
      </xqdoc:annotations>
    </xqdoc:index>
    <xqdoc:index>
      <xqdoc:name>idx</xqdoc:name>
      <xqdoc:source>
        <xqdoc:uri>http://www.zorba-xquery.com/collindex</xqdoc:uri>
        <xqdoc:name>entries</xqdoc:name>
      </xqdoc:source>
      <xqdoc:comment>
        <xqdoc:description> some comment6
</xqdoc:description>
      </xqdoc:comment>
    </xqdoc:index>
  </xqdoc:indexes>
  <xqdoc:functions/>
</xqdoc:xqdoc>
