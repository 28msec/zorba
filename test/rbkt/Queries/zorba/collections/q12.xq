import module namespace coll="http://www.zorba-xquery.com/zorba/collection-functions";

declare sequential function local:foo($collUri) {
  coll:create-collection($collUri,<a/>);
  let $a := fn:collection($collUri)
  return coll:insert-nodes-last($collUri, <b/>);
  exit with ();
};


let $collUri := "http://example.org/collection_1"
return local:foo($collUri)
