import module namespace doc = "http://www.zorba-xquery.com/modules/store/documents";

declare base-uri "http://www.zorba-xquery.com/";

declare sequential function local:add()
{
  doc:add("foo", document { <foo>bar</foo> });
};

declare sequential function local:add-twice()
{
  try {
    doc:add("foo", document { <foo>bar</foo> });
  } catch zerr:API0020 {
    "caught duplicate attempt to add a document"
  }
};

declare sequential function local:remove()
{
  doc:remove("foo");
};

declare sequential function local:remove-twice()
{
  try {
    doc:remove("foo");
  } catch zerr:XQD0001 ($err) {
    "caught attempt to remove a document that doesn't exist"
  }
};

declare function local:document()
{
  try {
    doc:document("foo")
  } catch zerr:XQD0001 {
    "caught attempt to retrieve a document that doesn't exist"
  }
};

declare function local:resolve()
{
  try {
    doc:document("dd%d")
  } catch FODC0004 {
    "caught attempt to resolve an invalid uri"
  }

};

string-join(
  (local:add(), (: add a document :)
   local:add-twice(), (: try creating it a second time and make sure that an error is raised :)
   string(doc:is-available-document("foo")), (: check if the document is available :)
   local:document(), (: return the document :)
   doc:available-documents(), (: list the names of all documents :)
   local:remove(), (: remove the document :)
   string(doc:is-available-document("foo")), (: check if the document has been deleted :)
   local:document(), (: return the document and make sure an error is raised :)
   local:remove-twice(), (: try to delete a document that doesn't exist and make sure that an error is raised :)
   local:resolve()), (: make sure that the document functions properly resolve relative URIs :)
   "
")
