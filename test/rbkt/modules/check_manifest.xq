import schema namespace mani = "http://zorba.io/manifest";

declare variable $manifest as xs:string external;

validate strict {
  fn:doc($manifest)
}
