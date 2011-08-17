
let $XQTSZorba := fn:doc("../../test/rbkt/Scripts/w3c/XQTS.xml")
let $XQUTSZorba := fn:doc("../../test/update/Scripts/XQUTS.xml")
let $XQFTTSZorba := fn:doc("../../test/rbkt/Scripts/w3c/XQFTTS.xml")

return 
("",
"/** \page impl_dep_features  Implementation dependent features, supported features and context properties

",
<ul>
  <li> \ref IDI </li>  
  <li> \ref Features </li>
  <li> \ref Context_properties </li>
</ul>,
"\section IDI Implementation defined items",
  <table bgcolor="lightcyan">
    <tr><td collspan="3">Implementation defined items</td></tr>
    <tr><td>Feature</td><td>Name</td><td>Value</td></tr>
    {
      for $idi in $XQTSZorba//*:implementation-defined-item
      where not(data($idi/@value) = "")
      return
      <tr>
        <td>W3C XQuery 1.0</td>
        <td>{data($idi/@name)}</td>
        <td>{data($idi/@value)}</td>
      </tr>
    }
    {
      for $idi in $XQUTSZorba//*:implementation-defined-item
      where not(data($idi/@value) = "")
      return
      <tr>
        <td>W3C XQuery Update Facility 1.0</td>
        <td>{data($idi/@name)}</td>
        <td>{data($idi/@value)}</td>
      </tr>
    }
    {
      for $idi in $XQFTTSZorba//*:implementation-defined-item
      where not(data($idi/@value) = "")
      return
      <tr>
        <td>W3C XQuery and XPath Full Text 1.0</td>
        <td>{data($idi/@name)}</td>
        <td>{data($idi/@value)}</td>
      </tr>
    }
  </table>
  ,
"\section Features",
  <table bgcolor="lightcyan">
    <tr><td collspan="3">Features</td></tr>
    <tr><td>Feature</td><td>Name</td><td>Value</td></tr>
    {
      for $feature in $XQTSZorba//*:feature
      return
      <tr>
        <td>W3C XQuery 1.0</td>
        <td>{data($feature/@name)}</td>
        <td bgcolor="{if(xs:boolean(data($feature/@supported))) then 'mediumseagreen' else 'white'}">{data($feature/@supported)}</td>
      </tr>
    }
    {
      for $feature in $XQUTSZorba//*:feature
      return
      <tr>
        <td>W3C XQuery Update Facility 1.0</td>
        <td>{data($feature/@name)}</td>
        <td bgcolor="{if(xs:boolean(data($feature/@supported))) then 'mediumseagreen' else 'white'}">{data($feature/@supported)}</td>
      </tr>
    }
    {
      for $feature in $XQFTTSZorba//*:feature
      return
      <tr>
        <td>W3C XQuery and XPath Full Text 1.0</td>
        <td>{data($feature/@name)}</td>
        <td bgcolor="{if(xs:boolean(data($feature/@supported))) then 'mediumseagreen' else 'white'}">{data($feature/@supported)}</td>
      </tr>
    }
  </table>,
  "\section Context_properties Context properties",
    <table bgcolor="lightcyan">
    <tr><td collspan="4">Context properties</td></tr>
    <tr><td>Feature</td><td>Name</td><td>Context type</td><td>Value</td></tr>
    {
      for $property in $XQTSZorba//*:context-property
      where not(data($property/@value) = "")
      return
      <tr>
        <td>W3C XQuery 1.0</td>
        <td>{data($property/@name)}</td>
        <td>{data($property/@context-type)}</td>
        <td>{data($property/@value)}</td>
      </tr>
    }
    {
      for $property in $XQUTSZorba//*:context-property
      where not(data($property/@value) = "")
      return
      <tr>
        <td>W3C XQuery Update Facility 1.0</td>
        <td>{data($property/@name)}</td>
        <td>{data($property/@context-type)}</td>
        <td>{data($property/@value)}</td>
      </tr>
    }
    {
      for $property in $XQFTTSZorba//*:context-property
      where not(data($property/@value) = "")
      return
      <tr>
        <td>W3C XQuery and XPath Full Text 1.0</td>
        <td>{data($property/@name)}</td>
        <td>{data($property/@context-type)}</td>
        <td>{data($property/@value)}</td>
      </tr>
    }
  </table>,
"*/")