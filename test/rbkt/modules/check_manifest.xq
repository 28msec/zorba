import schema namespace mani = "http://www.zorba-xquery.com/manifest";

declare variable $manifest as xs:string external;

validate strict {
  fn:doc($manifest)
}
