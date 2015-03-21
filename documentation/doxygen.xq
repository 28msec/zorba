module namespace c = "http://www.zorba-xquery.com/doxygen";
declare namespace xqdoc = "http://www.xqdoc.org/1.0";

declare copy-namespaces no-preserve, inherit;

declare function c:capitalize-first ( $arg as xs:string? )  as xs:string* {
  let $tokens := tokenize($arg, " ")
  return
  if (fn:count($tokens)>1) then
    for $token in $tokens
    return
     fn:concat(fn:upper-case(fn:substring($token,1,1)),
               fn:substring($token,2), " ")
   else (: do not capitalize if is just one work, because it's a class name :)
    {$arg}
};
 
declare function c:section-name($name as xs:string)
{
  switch($name)
  case "public-static-func"   return "Public Static Functions"
  case "public-func"          return "Public Functions"
  case "public-type"          return "Public Types"
  case "public-static-attrib" return "Public Static Attributes"
  case "public-attrib"        return "Public Attributes"

  case "protected-static-func"   return "Protected Static Functions"
  case "protected-func"          return "Protected Functions"
  case "protected-type"          return "Protected Types"
  case "protected-static-attrib" return "Protected Static Attributes"
  case "protected-attrib"        return "Protected Attributes"

  case "private-static-func"   return "Private Static Functions"
  case "private-func"          return "Private Functions"
  case "private-type"          return "Private Types"
  case "private-static-attrib" return "Private Static Attributes"
  case "private-attrib"        return "Private Attributes"

  case "enum"                 return "Enumerations"
  case "typedef"              return "Type Definitions"
  case "func"                 return "Functions"
  case "var"                  return "Variables"
  case "friend"               return "Friend Classes"
 
 default return $name
};

declare function c:api-text($api as xs:string) as xs:string
{
  if ($api = "cxx") then
    "C++"
  else if ($api = "c") then
    "C"
  else if ($api = "csharp") then
    "C#"
  else if ($api = "python") then
    "Python"
  else if ($api = "php") then
    "PHP"
  else if ($api = "java") then
    "Java"
  else if ($api = "xqj") then
    "XQJ"
  else ""
};

declare function c:ref($ref as element(ref), $version as xs:string, $api as xs:string)
{
  let $root := $ref//ancestor::*[empty(..)]
  return
    if($ref/@kindref = "compound") then
      <a href="/pages/{$version}/{$api}/{$ref/@refid}">{$ref/text()}</a>
    else
      let $tokens := c:split-id($ref/@refid)
      let $id := $tokens[1]
      let $anchor := $tokens[2]
      return
        <a href="/pages/{$version}/zorba/{$id}?anchor={$anchor}">{$ref/text()}</a>
};

declare function c:split-id($url as xs:string) as xs:string+
{
  let $tokens := tokenize($url, "_1")
  let $id := string-join(subsequence($tokens, 1, count($tokens) - 1), "_1")
  let $anchor := $tokens[last()]
  return ($id, $anchor)
};


declare function c:section-details($nodes as node()*, $version as xs:string, $api as xs:string)
{
  for $node in $nodes
  return
    typeswitch($node)
      case element(sectiondef)
      return
        <div class="section">
          <h2>{ let $kind := string($node/@kind)
                return c:section-name($kind) }</h2>
          <div class="detailed">
          {
            for $memberdef in $node/memberdef
            let $anchor := c:split-id($memberdef/@id)[2]
            return
            <div id="{$anchor}" class="sect1">
            <div><h3>{$memberdef/name/text()}</h3></div>
            <div class="signature-box">
            { c:html($memberdef/type/node(), $version, $api)} 
            <span>&#160;</span>
            { $memberdef/name/text() }
            { $memberdef/argsstring/text() }
            </div>
            <div>
            <p class="signature-description">{c:html($memberdef/briefdescription/node(), $version, $api)}</p>
            <p class="signature-description">{c:html($memberdef/detaileddescription/node(), $version, $api)}</p>
            </div>
            </div>
          }
          </div>
        </div>
    default return $node
};

declare function c:xdoc-description($node as node()*)
{ 
  if($node instance of text())
  then <p>{$node}</p>
  else $node
};

declare %private function c:is-zorba-module($uri as xs:string) as xs:boolean
{
  if(starts-with($uri,"http://www.zorba-xquery.com/modules") or
          starts-with($uri,"http://zorba.io/modules") or
          starts-with($uri,"http://expath.org/ns") or
          exists(index-of(("http://zorba.io/errors",
                           "http://zorba.io/warnings",
                           "http://jsoniq.org/errors",
                           "http://jsoniq.org/function-library",
                           "http://jsoniq.org/functions",
                           "http://www.functx.com",
                           "http://www.w3.org/2005/xpath-functions",
                           "http://www.w3.org/2005/xpath-functions/math",
                           "http://www.w3.org/2005/xqt-errors"), $uri)))
  then fn:true() else fn:false()
};

declare function c:filename-from-uri($uri as xs:string) as xs:string
{
  let $tmp := substring-after($uri, "http://")
  return replace($tmp, "/", "_")
};

declare function c:xdoc-header($node as node(), $version as xs:string, $api as xs:string)
{
  let $uri := $node/xqdoc:uri/text()
  let $prefix := xs:string($node/xqdoc:custom/xqdoc:namespace[@uri={$uri}][@isSchema="false"]/@prefix)
  let $comment := $node/xqdoc:comment
  let $description := $comment/xqdoc:description/node()
  return
  <div class="module-header">
    <h1>{$uri}</h1>
    <h2>Description</h2>
    <p>Before using any of the functions below please remember to import the module namespace:</p>
    <pre class="ace-static" ace-mode="xquery">import module namespace {$prefix} = "{$uri}";</pre>
    {c:xdoc-description($description)}
    <h3>Module code</h3>
    <p><a href="{c:filename-from-uri($uri) || '-module.html'}">Here</a> is the actual XQuery module code.</p>
    {
      if ($node/../xqdoc:imports/xqdoc:import[@type="schema"]) then
        <span>
          <h3>Imported Schemas</h3>
          <ul>
          {
            for $schema in $node/../xqdoc:imports/xqdoc:import[@type="schema"]
            let $targetUri := $schema/xqdoc:uri/text()
            return <li><a href="{c:filename-from-uri($targetUri) || '-schema.html'}">{$targetUri}</a></li>
          }
          </ul>
          <p>Please note that the schemas are not automatically imported in the modules that import this module.</p>
          <p>In order to import and use the schemas, please add:</p>
          <pre class="ace-static" ace-mode="xquery">{
            let $namespaces := $node/../xqdoc:module//xqdoc:custom[@tag = "namespaces"]
            return
              string-join(
                for $import in $node/../xqdoc:imports//xqdoc:import[@type = "schema"]
                return
                  concat('import schema namespace ',
                         $namespaces//xqdoc:namespace[(@uri = $import/xqdoc:uri/text()) and (@isSchema = "true")]/@prefix,
                         ' =  "',
                         string($import/xqdoc:uri/text()),'";'),"&#xA;")
           }</pre>
        </span>
      else ""
    }
    {
      if ($node/../xqdoc:imports/xqdoc:import[@type="library"]) then
        <span>
          <h3>Imported modules</h3>
          <ul>
          {
            for $module in $node/../xqdoc:imports/xqdoc:import[@type="library"]
            let $targetUri := $module/xqdoc:uri/text()
            let $targetUri := if(contains($targetUri,"#"))
                              then substring-before($targetUri,"#")
                              else $targetUri
            return <li><a href="{c:filename-from-uri($targetUri) || '-module.html'}">{$targetUri}</a></li>
          }
          </ul>
        </span>
      else ""
    }
    {
      if ($node/xqdoc:comment/xqdoc:see) then
        <span>
          <h3>See also</h3><ul>
          {
            for $see in $node/xqdoc:comment/xqdoc:see
            let $see := if(exists($see/a) and exists($see/text()))
                        then $see/node()
                        else if(exists($see/node()))
                             then if (c:is-zorba-module(xs:string($see/node())))
                                  then <a href="{c:filename-from-uri($see/node()) || '.html'}">{$see/node()}</a>
                                  else <a href="{$see/node()}">{$see/node()}</a>
                             else ""
            return <p>{$see}</p>
          }
        </ul></span>
      else ""
    }
    { (:There is no Author tag for instance in FunctX:)
      if ($node/xqdoc:comment/xqdoc:author) then
        (<h3>Authors</h3>,
         <p>{$node/xqdoc:comment/xqdoc:author/text()}</p>)
      else ""
    }
    {
      let $language := if (exists($node/xqdoc:comment/xqdoc:custom[@tag = "language"]))
                       then $node/xqdoc:comment/xqdoc:custom[@tag = "language"]
                       else "xquery"
(:
  according to http://www.w3.org/TR/xquery-30/#doc-xquery30-VersionDecl:
  If the version declaration is not present or the version is not included in the declaration, an XQuery 3.0 processor assumes a version of "3.0".
:)
      let $version  := if (exists($node/xqdoc:comment/xqdoc:custom[@tag = "version"]))
                       then $node/xqdoc:comment/xqdoc:custom[@tag = "version"]/text()
                       else "3.0" 
      let $encoding := if (exists($node/xqdoc:comment/xqdoc:custom[@tag = "encoding"]))
                       then $node/xqdoc:comment/xqdoc:custom[@tag = "encoding"]/text()
                       else ()
      return
      <span>
        <h3>Version Declaration</h3>
        <pre class="ace-static" ace-mode="xquery">{$language} version "{$version}"{if(exists($encoding)) then (' encoding "' || $encoding || '"') else ()};</pre>
      </span>
    }
    {(:Namespaces may be missing: see W3C F&O:)
      if($node/xqdoc:custom/xqdoc:namespace) then
      (<h2>Namespaces</h2>,
      <table class="table table-bordered table-striped">
      { for $namespace in $node/xqdoc:custom/xqdoc:namespace
        return
          <tr><td>{xs:string($namespace/@prefix)}</td><td>{xs:string($namespace/@uri)}</td></tr>
      }
      </table>)
      else ""
    }
  </div>
};

declare function c:xdoc-function-summary($node as node(), $version as xs:string, $api as xs:string)
{
  <div>
  <h2>Function Summary</h2>
  <table class="table table-bordered table-striped">
  <tbody>
  {
    for $function in $node/xqdoc:function
    let $name := xs:string($function/xqdoc:name/text()/substring-after(., ":"))
    let $arity := number($function/@arity)
    let $desc := string-join($function/xqdoc:comment/xqdoc:description/node(), " ")
    let $short-desc := {
      if ( contains($desc, "." )) then
      substring-before( $desc, ".")
      else
      $desc
    }
    return
      <tr>
        <td>
        <a href="#{$name}-{$arity}">{$name}</a>{substring-after($function/xqdoc:signature/text(), $function/xqdoc:name/text())}
        <p>{if (not($short-desc = ""))
           then (concat($short-desc,'.'))
           else ()}
        </p>
        </td>
      </tr>
  }
  </tbody>
  </table>
  </div>
};

declare function c:to-string($arg1 as node()) as xs:string
{
  let $result:=
    for $arg in $arg1
      return xs:string($arg)
  return $result
};

declare %private function c:serialize-params($params as element(xqdoc:parameters)?)
as xs:string*
{
  let $params :=
    for $param in $params/xqdoc:parameter
    return
      concat("$", $param/xqdoc:name/text(), " as ", $param/xqdoc:type/text(), $param/xqdoc:type/@occurrence)
  return
    if(exists($params)) then
      concat("
    ", string-join($params, ",
    "), "
")
    else ()
};

declare %private function c:serialize-annotations($annotations as element(xqdoc:annotations)?)
as xs:string?
{
  let $result :=
    string-join(
      let $namespaces := $annotations/ancestor::*[empty(..)]//xqdoc:module/xqdoc:custom[@tag = "namespaces"]/xqdoc:namespace
      for $annotation in $annotations/xqdoc:annotation
      let $ns := $annotation/@namespace/string(.)
      let $prefix := $annotation/@prefix/string(.)
      return
        concat("%", if(exists($prefix)) then concat($prefix, ":") else (), $annotation/@localname)
    , " ")
  return
    if($result != "") then
      concat(" ", $result)
    else
      $result
};

declare function c:is-function-updating($function as element(xqdoc:function))
as xs:boolean
{
  $function/xqdoc:signature/text()/contains(substring-before(., $function/xqdoc:name/text()), " updating ")
};

declare %private function c:is-function-external($function as element(xqdoc:function))
as xs:boolean
{
  $function/xqdoc:signature/text()/ends-with(., " external")
};

declare function c:xdoc-functions($node as node(), $version as xs:string, $api as xs:string)
{
  <div>
  <h2>Functions</h2>
  <table>
  {
    for $function in $node/xqdoc:function
    let $uri := xs:string($node/../xqdoc:module/xqdoc:uri)
    let $name := xs:string($function/xqdoc:name/text()/substring-after(., ":"))
    let $arity := number($function/@arity)
    let $description := $function/xqdoc:comment/xqdoc:description/node()
    let $signature := xs:string($function/xqdoc:signature/text())
    return
      <tr><td class="container">
        <h3 id="{$name}-{$arity}">{$name}#{$arity}</h3>
        <pre class="ace-static" ace-mode="xquery">{concat("declare", c:serialize-annotations($function/xqdoc:annotations), if(c:is-function-updating($function)) then " updating " else " ")}function {$function/xqdoc:name/text()}({c:serialize-params($function/xqdoc:parameters)}) as {let $return := $function/xqdoc:return/xqdoc:type/text() return if(empty($return)) then "item()*" else $return}{if(c:is-function-external($function)) then " external" else ()}</pre>
        {c:xdoc-description($description)}
        { if ($function/xqdoc:comment/xqdoc:param) then
            <span>
            <h4>Parameters</h4>
            <ul>{
              for $parameter in $function/xqdoc:comment/xqdoc:param
                let $xparam := c:to-string($parameter)
                let $param := substring-before($xparam, " ")
                let $desc := substring-after($xparam, " ")
              return
                <li><code>{$param}</code><p class="param-description">{$desc}</p>
                </li>
            }
            </ul>
            </span>
          else "" }
        { if ($function/xqdoc:return/xqdoc:type) then
            <span>
            <h4>Returns</h4>
            <ul><li><code>{$function/xqdoc:return/xqdoc:type/text()}</code>
                  <p class="param-description">{
                  if ($function/xqdoc:comment/xqdoc:return) then
                    c:to-string($function/xqdoc:comment/xqdoc:return)
                  else ""}</p>
            </li></ul>
            </span>
          else "" }
        { if ($function/xqdoc:comment/xqdoc:error) then
            <span>
            <h4>Errors</h4>
            <ul>{
              for $errors in $function/xqdoc:comment/xqdoc:error
                let $xerror := c:to-string($errors)
                let $error := if(contains($xerror," ")) then substring-before($xerror, " ") else $xerror
                let $desc := substring-after($xerror, " ")
              return
                <li><code>{$error}</code><p class="param-description">{$desc}</p>
                </li>
            }
            </ul>
            </span>
          else "" }
        { if ($function/xqdoc:comment/xqdoc:custom[@tag="example"]) then
            <span>
            <h4>Examples</h4>
            <ul>{
              for $example in $function/xqdoc:comment/xqdoc:custom[@tag="example"]
              let $name := substring-before(tokenize($example,"/")[last()],".xq")
              let $path := tokenize($uri,"/")[last()] || "_" || $name || "-example.html"
              return
                <li><a href="{$path}">{$name || ".xq"}</a></li>
            }
            </ul>
            </span>
          else "" }
      </td></tr>
  }
  </table>
  </div>
  
};

declare function c:xdoc-variables($node as node(), $version as xs:string, $api as xs:string)
{
  <div>
  <h2>Variables</h2>
  <table class="table table-bordered table-striped">
  {
    for $variable in $node/xqdoc:variable
    let $name := xs:string($variable/xqdoc:uri/text())
    let $description := $variable/xqdoc:comment/xqdoc:description/node()
    return
      <tr><td>{$name}{if ($variable/xqdoc:comment/xqdoc:custom[@tag="type"])
                    then <span> as {$variable/xqdoc:comment/xqdoc:custom[@tag="type"]}</span>
                    else ""}<p>{c:xdoc-description($description)}</p></td>
      </tr>
  }
  </table>
  </div>
  
};

declare function c:html($nodes as node()*, $version as xs:string, $api as xs:string)
{ 
  for $node in $nodes
  return
    typeswitch($node)
    
      case element(xqdoc:module)
      return 
        c:xdoc-header($node, $version, $api)

      case element(xqdoc:functions)
      return
      {if ($node/xqdoc:function) then
        <span>
          {c:xdoc-function-summary($node, $version, $api)}
          {c:xdoc-functions($node, $version, $api)}
        </span>
        else ""}
      case element(xqdoc:imports)
      return ""
      case element(xqdoc:control)
      return ""
      case element(xqdoc:variables)
      return 
      { if ($node/xqdoc:variable) then
        <span>
          {c:xdoc-variables($node, $version, $api)}
        </span>
        else ""}
      case element(xqdoc:collections)
      return ""
      case element(xqdoc:indexes)
      return ""
      
      
      case element(basecompoundref)
      return 
        <p class="inherited">
          Inherited from:
          <a href="{$node/@refid}.html">
            {$node/text()}
          </a>
        </p>

      case element(includes)
      return 
        let $tokens := tokenize($node/@refid, "_1")
        let $href := $tokens[count($tokens)]
        return
        <p class="include">
            #include &lt;{$node/text()}&gt;
        </p>
      
      case element(compound)
      return
        if ($node/@kind = "class") then
          let $refid := $node/@refid
          let $tokens := tokenize($node/name/text(), "::")
          let $maxcount := count($tokens)
          return
            <div class="classname">
              <a href="{$refid}.html" >
                {$tokens[$maxcount]}
                <span>&#160;</span>
              </a>
              {"("}
              {
                let $path := { 
                  let $final := count($tokens)-1
                  for $i in (1 to $final)
                  let $index := ($maxcount - xs:int($i))
                  return
                    $tokens[$index]
                  }
                return {string-join($path, "::")}
              }
              {")"}
            </div>
        else
          ""

      case element(compounddef)
      return <div>
        { 
          if ($node/title) then
            let $title:=$node/title/text()
            return <h1 class="title">{$title}</h1>
          else 
            let $classname :=$node/compoundname/text()
            return 
              <h1 class="title">{$classname}</h1>
        }
        {c:html($node/includes, $version, $api)}
        {
        if ($node/basecompoundref) then
          c:html($node/basecompoundref, $version, $api)
        else ""
        }
        {c:html($node/briefdescription/node(), $version, $api)}
        {c:html($node/detaileddescription/node(), $version, $api)}
        {c:html($node/sectiondef, $version, $api)}
        {c:section-details($node/sectiondef, $version, $api)}
      </div>
      case element(sectiondef)
      return
        <div class="section">
          <h2>{ let $kind := string($node/@kind)
                return c:section-name($kind) }</h2>
          <table class="parameters table table-bordered">
          {
            for $memberdef in $node/memberdef
            let $anchor := c:split-id($memberdef/@id)[2]
            return
            <tr>
              <td class="return-type"><p class="signature">{c:html($memberdef/type/node(), $version, $api)}</p></td>
              <td><p class="signature"><a href="#{$anchor}">{$memberdef/name/text()}</a> {$memberdef/argsstring/text()}</p>
              <span class="signature-description">{c:html($memberdef/briefdescription/node(), $version, $api)}</span>
              </td>
            </tr>
          }
          </table>
        </div>
      case element(para)
      return
        {c:html($node/node(), $version, $api)}
      
      case element(ref)
      return c:ref($node, $version, $api)
       
      case element(simplesect)
      return
        let $kind := string($node/@kind)
        return
          if($kind = "note") then
            <div class="note">
              {c:html($node/node(), $version, $api)}
            </div>
          else
            <div>
              <h4>Returns</h4>
              {c:html($node/node(), $version, $api)}
            </div>
 
      case element(parameterlist)
      return <div>
        <h4>Parameters</h4>
        <table class="parameters table table-bordered">
        {
          for $param in $node//parameteritem
          return
          <tr>
            <td>{$param//parametername/text()}</td>
            <td>{c:html($param//parameterdescription/node(), $version, $api)}</td>
          </tr>
        }
        </table>
      </div>

      case element(programlisting)
      return
        switch($api)
        case "c"      return <pre class="ace-static" ace-mode="c_cpp"> {c:html($node/node(), $version, $api)}</pre>
        case "cxx"    return <pre class="ace-static" ace-mode="c_cpp"> {c:html($node/node(), $version, $api)}</pre>
        case "php"    return <pre class="ace-static" ace-mode="php">{c:html($node/node(), $version, $api)}</pre>
        case "zorba"  return <pre class="ace-static" ace-mode="xquery">{c:html($node/node(), $version, $api)}</pre>
        case "xqj"    return <pre class="ace-static" ace-mode="java">{c:html($node/node(), $version, $api)}</pre>
        case "java"   return <pre class="ace-static" ace-mode="java">{c:html($node/node(), $version, $api)}</pre>
        case "python" return <pre class="ace-static" ace-mode="python">{c:html($node/node(), $version, $api)}</pre>
        case "ruby"   return <pre class="ace-static" ace-mode="ruby">{c:html($node/node(), $version, $api)}</pre>
        case "modules"
        return
              if(exists($node[@type="schema"])) then
                <pre class="ace-static" ace-mode="xml">{c:html($node/node(), $version, $api)}</pre>
              else
                <pre class="ace-static" ace-mode="xquery">{c:html($node/node(), $version, $api)}</pre>
        default  return <pre>{c:html($node/node(), $version, $api)}</pre>

      case element(codeline)
      return c:html($node/node(), $version, $api)

      (: change space to &#160;  :)
      case element(sp)
      return <span>&#160;</span>
     
      (: change space to &#160;  :)
      case element(nonbreakablespace)
      return <span>&#160;</span>

      case element(highlight)
      return <span class="{$node/@class}">{c:html($node/node(), $version, $api)}</span>

      case element(heading)
      return
        switch($node/@level)
        case "1" return <h1>{c:html($node/node(), $version, $api)}</h1>
        case "2" return <h2>{c:html($node/node(), $version, $api)}</h2>
        case "3" return <h3>{c:html($node/node(), $version, $api)}</h3>
        default  return <h4>{c:html($node/node(), $version, $api)}</h4>

      case element(anchor)
      return
        let $tokens := tokenize($node/@id, "_1")
        return <a name="{$tokens[2]}"></a>

      case element(itemizedlist)
      return <ul>{c:html($node/node(), $version, $api)}</ul>

      case element(orderedlist)
      return <ol>{c:html($node/node(), $version, $api)}</ol>


      case element(listitem)
      return <li>{c:html($node/node(), $version, $api)}</li>

      case element(ulink)
      return 
        let $root := $node//ancestor::*[empty(..)]
        let $version := string($root/@doc-version[1])
        let $api := string($root/@doc-api[1])
        let $link := string($node/@url)
        let $link := replace($link, "/xqdoc/xhtml/", "../modules/")
        return
          if($link = "http:" or $link = "file:" or $link = "file://") then
            <pre class="ace-static" ace-mode="xquery">{c:html($node/text(), $version, $api)}</pre>
          else
            <a href="{$link}" target="_blank">{c:html($node/node(), $version, $api)}</a>
      
      case element(emphasis)
      return <em>{c:html($node/node(), $version, $api)}</em>

      case element(bold)
      return <b>{c:html($node/node(), $version, $api)}</b>

      case element(computeroutput)
      return
        if(exists($node/text())) then
          <tt>{$node/text()}</tt>
        else()

      case element(verbatim)
      return
        <pre>{$node/node()}</pre>

      case element(linebreak)
      return <br/>

      case element(image)
      return
        <p><img src="/images/doxygen/{xs:string($node/@name)}" width="100%"/></p>

      case element(table)
      return  <table class="table table-bordered">
                {c:html($node/node(), $version, $api)}
              </table>

      case element(row)
      return <tr>{c:html($node/node(), $version, $api)}</tr>

      case element(entry)
      return
        let $name := if($node/@thead = "yes") then "th" else "td"
        let $cell := element { $name } { c:html($node/node(), $version, $api) }
        return $cell

      case element(center)
      return
        <div class="center">{c:html($node/node(), $version, $api)}</div>

      case element(doxygen)
      return <div class="doxygen">{c:html($node/node(), $version, $api)}</div>

      case element(compoundname)
      return <div class="compoundname" data-compoundname="{$node/text()}"></div>

      case element(detaileddescription)
      return <div class="detaileddescription">{c:html($node/node(), $version, $api)}</div>

      case element(sect1)
      return
        let $anchor := c:split-id($node/@id)[2]
        return
        <div id="{$anchor}" class="sect1">
          <h2>{c:html($node/title/node(), $version, $api)}</h2>
          {c:html($node/title/following-sibling::node(), $version, $api)}
        </div>

      case element(sect2)
      return
        let $anchor := c:split-id($node/@id)[2]
        return
        <div id="{$anchor}" class="sect2">
          <h3>{c:html($node/title/node(), $version, $api)}</h3>
          {c:html($node/title/following-sibling::node(), $version, $api)}
        </div>

      case element(sect3)
      return
       let $anchor := c:split-id($node/@id)[2]
       return
        <div id="{$node/@id}" class="sect3">
          <h4>{c:html($node/title/node(), $version, $api)}</h4>
          {c:html($node/title/following-sibling::node(), $version, $api)}
        </div>

      case element(sect4)
      return
       let $anchor := c:split-id($node/@id)[2]
       return
        <div id="{$node/@id}" class="sect4">
          <h5>{c:html($node/title/node(), $version, $api)}</h5>
          {c:html($node/title/following-sibling::node(), $version, $api)}
        </div>
     
      case element(htmlonly)
        return fn:parse-xml(fn:replace($node/node(),"&amp;nbsp;","&#160;"))
      
    default return $node
};

