(:~
 : Module Name: XSLT 2.0 and XQuery 1.0 Serialization Module
 : Module Overview: This library module provides functions for serializing XDM instances to strings
 : Date: November 10, 2009
 : Copyright: 2006-2009 The FLWOR Foundation. Licensed under the Apache License, Version 2.0.
 : @author Matthias Brantner & Gabriel Petrovay
 : @version 1.0
 :)
module namespace ser = "http://www.zorba-xquery.com/modules/serialize";


(:~
 : Serialize a sequence of items to a string. 
 :
 : @param $content The content to be serialized to the string.
 : @param $serializer-params Parameters to control the serialization of the
 :        content. This parameter can either be a string (xml, html, xhtml,
 :        text, json, or jsonml) describing the serialization method to
 :        be used or a element node as follows:
 :        &lt;xsl:output  method="xml|html|text|json|jsonml"
 :          version="string" encoding="string"
 :          omit-xml-declaration="yes|no"
 :          standalone="yes|no"
 :          doctype-public="string" doctype-system="string"
 :          cdata-section-elements="namelist"
 :          indent="yes|no" media-type="string"/>

 : @error An error is thrown if serialization problems occur.
 :)
declare function ser:serialize($content as item()*,
                               $serializer-params as item()) as xs:string external;

(:~
 : Serialize a sequence of items to a string. For serialization,
 : the serialization parameters are set as follows:
 : <ul>
 :   <li> serialization method: XML</li>
 :   <li> byte-order-mark: NO</li>
 :   <li> esacpe-uri-attributes: NO</li>
 :   <li> include-content-type: NO</li>
 :   <li> indent: NO</li>
 :   <li> normalization-form: none</li>
 :   <li> omit-xml-declaration: NO</li>
 :   <li> standalone: omit</li>
 :   <li> undeclare-prefixes: NO</li>
 : </ul>
 :
 : @param $content The content to be serialized to the string.
 : @error An error is thrown if serialization problems occur.
 :)
declare function ser:serialize($content as item()*) as xs:string external;
