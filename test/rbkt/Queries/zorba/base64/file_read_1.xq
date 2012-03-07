import module namespace f = "http://expath.org/ns/file";

variable $enc-file-name := resolve-uri("encoded");
variable $dec-file-name := resolve-uri("decoded");
variable $base64-1 := f:read-binary($dec-file-name);
variable $base64-2 := f:read-binary($dec-file-name);
variable $ref-result := f:read-text($enc-file-name);

xs:string($base64-1) eq $ref-result, $base64-1 eq $base64-2,
fn:serialize($base64-1)
