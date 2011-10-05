(:
 : Copyright 2006-2011 The FLWOR Foundation.
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

let $XQTSZorba := fn:doc("../../test/rbkt/Scripts/w3c/XQTS.xml")
let $XQUTSZorba := fn:doc("../../test/update/Scripts/XQUTS.xml")
let $XQFTTSZorba := fn:doc("../../test/rbkt/Scripts/w3c/XQFTTS.xml")

return 
("",
"/** \page impl_dep_features  Implementation Dependent Features and Properties

",
<ul>
  <li> \ref IDI </li>  
  <li> \ref Features </li>
  <li> \ref Context_properties </li>
</ul>,
"
\section IDI Implementation Defined Items",
  <table bgcolor="white" cellpadding="2">
    <tr bgcolor="lightcyan"><td><strong>W3C Specification</strong></td><td><strong>Description</strong></td><td><strong>Description of the Implementation in Zorba</strong></td></tr>
    {
      for $idi in $XQTSZorba//*:implementation-defined-item
      where not(data($idi/@value) = "")
      return
      <tr bgcolor="lightcyan">
        <td>W3C XQuery 1.0</td>
        <td>{normalize-space($idi/*:description/text())}</td>
        <td>{data($idi/@value)}</td>        
      </tr>
    }
    {
      for $idi in $XQUTSZorba//*:implementation-defined-item
      where not(data($idi/@value) = "")
      return
      <tr bgcolor="lightcyan">
        <td>W3C XQuery Update Facility 1.0</td>
        <td>{normalize-space($idi/*:description/text())}</td>
        <td>{data($idi/@value)}</td>
      </tr>
    }
    {
      for $idi in $XQFTTSZorba//*:implementation-defined-item
      where not(data($idi/@value) = "") and data($idi/@spec) = "XQueryFullText"
      return
      <tr bgcolor="lightcyan">
        <td>W3C XQuery and XPath Full Text 1.0</td>
        <td>{normalize-space($idi/*:description/text())}</td>
        <td>{data($idi/@value)}</td>
      </tr>
    }
  </table>
  ,
"
\section Features Supported Features",
  <table bgcolor="white" cellpadding="2">
    <tr bgcolor="lightcyan"><td><strong>W3C Specification</strong></td><td><strong>Name</strong></td><td><strong>Value</strong></td></tr>
    {
      for $feature in $XQTSZorba//*:feature
      return
      <tr bgcolor="lightcyan">
        <td>W3C XQuery 1.0</td>
        <td>{data($feature/@name)}</td>
        <td bgcolor="{if(xs:boolean(data($feature/@supported))) then 'mediumseagreen' else 'white'}">{data($feature/@supported)}</td>
      </tr>
    }
    {
      for $feature in $XQUTSZorba//*:feature
      return
      <tr bgcolor="lightcyan">
        <td>W3C XQuery Update Facility 1.0</td>
        <td>{data($feature/@name)}</td>
        <td bgcolor="{if(xs:boolean(data($feature/@supported))) then 'mediumseagreen' else 'white'}">{data($feature/@supported)}</td>
      </tr>
    }
    {
      for $feature in $XQFTTSZorba//*:feature
      return
      <tr bgcolor="lightcyan">
        <td>W3C XQuery and XPath Full Text 1.0</td>
        <td>{data($feature/@name)}</td>
        <td bgcolor="{if(xs:boolean(data($feature/@supported))) then 'mediumseagreen' else 'white'}">{data($feature/@supported)}</td>
      </tr>
    }
  </table>,
  "
\section Context_properties Context Properties",
    <table bgcolor="white" cellpadding="2">
    <tr bgcolor="lightcyan"><td><strong>W3C Specification</strong></td><td><strong>Name</strong></td><td><strong>Context Type</strong></td><td><strong>Value</strong></td></tr>
   {
      for $property in $XQTSZorba//*:context-property
      where not(data($property/@value) = "")
      return
      <tr bgcolor="lightcyan">
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
      <tr bgcolor="lightcyan">
        <td>W3C XQuery Update Facility 1.0</td>
        <td>{data($property/@name)}</td>
        <td>{data($property/@context-type)}</td>
        <td>{data($property/@value)}</td>
      </tr>
    }
    {
      for $property in $XQFTTSZorba//*:context-property
      where not(data($property/@value) = "") and data($property/@spec) = "XQueryFullText"
      return
      <tr bgcolor="lightcyan">
        <td>W3C XQuery and XPath Full Text 1.0</td>
        <td>{data($property/@name)}</td>
        <td>{data($property/@context-type)}</td>
        <td>{data($property/@value)}</td>
      </tr>
    }
  </table>,
"*/")
