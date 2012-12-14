(: This should raise XQDY0091 because the value of the xml:ID is not a :)
(: valid NCNAME (XQuery 3.7.1.1 clause 5). :)

let $in := <input xml:id="-ptr"/>
return element out {
 attribute id { $in/@xml:id }
}
