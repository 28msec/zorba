module namespace xhtml = "http://www.zorba-xquery.com/modules/internal/xqdoc-xhtml";

import module namespace util = "http://www.zorba-xquery.com/zorba/util-functions";

declare namespace xqdoc = "http://www.xqdoc.org/1.0";

declare function xhtml:doc($xqdoc, $menu, $indexCollector, $schemasCollector)
{
<html>
  <head>
    <title>Documentation for {xhtml:module-uri($xqdoc)}</title>
    <meta content="text/html; charset=UTF-8" http-equiv="content-type" />
    <meta content="PRIVATE" http-equiv="CACHE-CONTROL" />
    <meta content="-1" http-equiv="Expires" />
    <title>Zorba - XQuery API XQDoc Documentation</title>
    <link rel="stylesheet" type="text/css" href="css/main.css" />
    <link rel="stylesheet" href="css/jquery.treeview.css" />
    <link rel="stylesheet" href="css/screen.css" />
    <script src="lib/jquery.js" type="text/javascript"> </script>
    <script src="lib/jquery.cookie.js" type="text/javascript"> </script>
    <script src="lib/jquery.treeview.js" type="text/javascript"> </script>
    <script type="text/javascript">
      $(function() &#123;
        $("#documentation").treeview(&#123;
            animated: "fast",
            collapsed: true,
            unique: false,
            persist: "cookie"
        &#125;);
      &#125;)
    </script>
  </head>
  <body>
  <div id="main">
    <div id="leftMenu">
    {$menu}
    </div>
    <div id="rightcontent">{xhtml:body($xqdoc, $indexCollector, $schemasCollector)}
    </div>
  </div>
  </body>
</html>
};

declare function xhtml:header($xqdoc)
{
    <head>
        <title>Documentation for {xhtml:module-uri($xqdoc)}</title>
        <link rel="stylesheet" type="text/css" href="" />
    </head>
};

declare function xhtml:body($xqdoc, $indexCollector, $schemasCollector)
{
    <body>
        <h1>{xhtml:module-uri($xqdoc)}</h1>
        {            
            xhtml:module-description($xqdoc/xqdoc:module),
            xhtml:module-dependencies($xqdoc, $indexCollector, $schemasCollector),
            xhtml:module-external-specifications($xqdoc/xqdoc:module),
            xhtml:module-variables($xqdoc/xqdoc:variables),
            xhtml:module-function-summary($xqdoc/xqdoc:functions),
            xhtml:module-functions($xqdoc/xqdoc:functions)
        }
    </body>
};

declare function xhtml:module-uri($xqdoc) as xs:string
{
    $xqdoc/xqdoc:module/xqdoc:uri/text()
};

declare function xhtml:parameters($comment) {
    let $params := $comment/xqdoc:param
    return
        if (exists($params)) then (
            <div class="subsubsection">Parameters:</div>,
            for $param in $params
            let $text := string($param/node()[1])
            return
                if (starts-with($text, "$")) then
                    let $name := substring-before($text, " ")
                    let $description := (substring-after($text, " "), subsequence($param/node(), 2))
                    return
                        <table class="parameter"><tr>
                            <td class="parameter"><code>{$name}</code></td>
                            <td class="parameter"> - </td>
                            <td class="parameter">{$description}</td></tr>
                        </table> 
                else
                    ()
        ) else ()
};

declare function xhtml:errors($comment) {
    let $errors := $comment/xqdoc:error
    return
        if (exists($errors)) then (
            <div class="subsubsection">Errors</div>,
            for $error in $errors
            return
                <table class="parameter">
                    <tr>
                        <td class="parameter">{$error/node()}</td>
                    </tr>
                </table> 
        ) else ()
};

declare function xhtml:annotations-see($comment) {
  let $see := $comment/xqdoc:*[local-name(.) = ("see")]
  return
    if (count($see) = 0) then ()
    else
(: **********************************************************     :)
(: this hack should be replaced with links everywhere in text     :)
(: replace the @see nodes that start with http:// with HTML a tag :)
    (<div class="subsubsection">See:</div>,<ul>
    {for $annotation in $see
    return
      if(fn:count($annotation/node()) eq 1 
         and fn:starts-with(fn:lower-case($annotation/node()), "http://")) then
        <li class="none">{<a href="{$annotation/node()}" target="_blank">{$annotation/node()}</a>}</li>
    else
        <li class="none">{$annotation/node()}</li>}</ul>
    )
(: **********************************************************     :)
};

declare function xhtml:annotations-example($comment) {
  let $example := $comment/xqdoc:*[local-name(.) = ("example")]
  return
    if (count($example) = 0) then ()
    else
    (<div class="subsubsection">Examples:</div>,<ul>
    {for $annotation in $example
    return
        <li class="none">{$annotation/node()}</li>}</ul>
    )
};

declare function xhtml:annotations($comment) {
  let $annotations := $comment/xqdoc:*[not((local-name(.) = ("description", "param", "return", "error", "deprecated", "see", "example")))]
  return
    for $annotation in $annotations
    let $annName := local-name($annotation)
    return 
    ( 
      <div class="subsubsection">{
        concat(upper-case(substring($annName, 1, 1)), substring($annName, 2), ":")
      }</div>,    
      <p class="annotationText">{$annotation/node()}</p>
    )
};

declare function xhtml:annotationsModule($comment) {
  let $annotations := $comment/xqdoc:*[not((local-name(.) = ("description", "param", "return", "error", "deprecated", "see", "library")))]
  return
    for $annotation in $annotations
    let $annName := local-name($annotation)
    return 
    ( 
      <div class="subsubsection">{
        concat(upper-case(substring($annName, 1, 1)), substring($annName, 2), ":")
      }</div>,    
      <p class="annotationText">{$annotation/node()}</p>
    )
};


declare function xhtml:return($comment) {
    let $return := $comment/xqdoc:return
    return
        if (exists($return)) then (
            <div class="subsubsection">Returns:</div>,
            <p class="annotationText">{$return/node()}</p>
        ) else ()
};

declare function xhtml:description($comment) {
     <p>{
        if ($comment/xqdoc:description) then
            $comment/xqdoc:description/node()
        else
            "No description available."
     }</p>
};

declare function xhtml:module-dependencies($xqdoc, $indexCollector, $schemasCollector) {
  if (fn:count($xqdoc/xqdoc:imports/xqdoc:import) > 0 or
      fn:count($xqdoc/xqdoc:module/xqdoc:comment/xqdoc:*[(local-name(.) = ("library"))]) > 0) then
    (<div class="section"><span class="section" id="module_dependencies">Module Dependencies</span></div>,
    xhtml:imports($xqdoc, $indexCollector, $schemasCollector))
  else
    ()
};

declare function xhtml:imports($xqdoc, $indexCollector, $schemasCollector) {
  (
  if (fn:count($xqdoc/xqdoc:imports//xqdoc:import[@type = "library"]) > 0) then
    <p>Imported modules:<ul>
    {
      for $import in $xqdoc/xqdoc:imports//xqdoc:import[@type = "library"]
      return
        if (exists($indexCollector/module[@uri=$import/xqdoc:uri/text()])) then
          <li><a href="{$indexCollector/module[@uri=$import/xqdoc:uri/text()]/@file}">{string($import/xqdoc:uri/text())}</a></li>
        else
          <li>{string($import/xqdoc:uri/text())}</li>          
    }
    </ul></p>
  else (),
  if (fn:count($xqdoc/xqdoc:imports//xqdoc:import[@type = "schema"]) > 0) then
    <p>Imported schemas:<ul>
    {
      for $import in $xqdoc/xqdoc:imports//xqdoc:import[@type = "schema"]
      return
        if (exists($schemasCollector/module[@uri=$import/xqdoc:uri/text()])) then
          <li><a href="{$schemasCollector/module[@uri=$import/xqdoc:uri/text()]/@file}" target="_blank">{string($import/xqdoc:uri/text())}</a></li>
        else
          <li>{string($import/xqdoc:uri/text())}</li>  
    }
    </ul></p>
  else (),
  if (fn:count($xqdoc/xqdoc:module/xqdoc:comment/xqdoc:*[(local-name(.) = ("library"))]) > 0) then
    <p>External C++ library dependencies:<ul>
      {
      for $library in $xqdoc/xqdoc:module/xqdoc:comment/xqdoc:*[(local-name(.) = ("library"))]
        return
         <li>{$library/node()}</li>
      }
    </ul></p>
  else ()
  )
};

declare function xhtml:module-description($module) {
    (<div class="section"><span class="section" id="module_description">Module Description</span></div>,
     xhtml:description($module/xqdoc:comment),
     xhtml:annotationsModule($module/xqdoc:comment))
};

declare function xhtml:module-external-specifications($module) {
  if(fn:count($module/xqdoc:comment/xqdoc:*[(local-name(.) = ("see"))]) >0) then
    (<div class="section"><span class="section" id="external_specifications">External Specifications</span></div>,
    <p>For more details please check out these resources:<ul>
    {
      let $annotations := $module/xqdoc:comment/xqdoc:*[(local-name(.) = ("see"))]
      return
        for $annotation in $annotations
          return
          if(fn:count($annotation/node()) eq 1 
             and fn:starts-with(fn:lower-case($annotation/node()), "http://") ) then
            <li><a href="{$annotation/node()}" target="_blank">{$annotation/node()}</a></li>
          else
            <li>{$annotation/node()}</li>
    }
    </ul></p>)
  else
  ()
};

declare function xhtml:module-variables($variables)
{
    if($variables/xqdoc:variable) then
        (<div class="section"><span class="section" id="variables">Variables</span></div>,
        for $variable in $variables/xqdoc:variable
        let $varName := $variable/xqdoc:uri/text()
        order by $varName
        return (<div class="subsection">{$variable/xqdoc:uri/text()}</div>,
                xhtml:description($variable/xqdoc:comment),
                xhtml:annotations($variable/xqdoc:comment))
        )
    else
        ()
};

declare function xhtml:module-function-summary($functions)
{
    <div class="section"><span class="section" id="function_summary">Function Summary</span></div>,
    if(count($functions/xqdoc:function)) then
        <table class="funclist">{
            for $function in $functions/xqdoc:function
            let $name := $function/xqdoc:name/text(),
                $signature := $function/xqdoc:signature/text(),
                $param-number := $function/@arity,
                $isDeprecated := fn:exists($function/xqdoc:comment/xqdoc:deprecated)
            order by $name, $param-number 
            return
                let $type := normalize-space(substring-after(substring-before($signature, "function"), "declare")),
                    $isExternal := ends-with($signature, "external"),    
                    $paramsAndReturn :=
                        let $searchCrit := concat(":", $name)
                        return
                            if ($isExternal)
                                then normalize-space(substring-before(substring-after($signature, $searchCrit), "external"))
                                else normalize-space(substring-after($signature, $searchCrit))
                return
                    <tr>
                        <td class="type">{$type}</td>
                        <td>
                            <tt>{
                                if ($isDeprecated) then
                                    <del><a href="#{$name}-{$param-number}">{$name}</a></del>
                                else
                                    <a href="#{$name}-{$param-number}">{$name}</a>
                            }{$paramsAndReturn}</tt>
                        </td>
                    </tr>
        }</table>
    else
        <p>No <a href="http://www.w3.org/TR/xquery-11/#doc-xquery11-PrivateOption">public</a> functions declared.</p>
};

declare function xhtml:module-function-link($name as xs:string, $signature) {

let $lcSignature := fn:lower-case($signature)
return
  if(contains($lcSignature, 'updating')) then
    concat('updating ',$name)
  else if(contains($lcSignature, 'sequential')) then
    concat('sequential ',$name)
  else if(contains($lcSignature, 'nondeterministic')) then
    concat('nondeterministic ',$name)
  else 
    $name
};

declare function xhtml:module-functions($functions) {
    if(count($functions/xqdoc:function)) then (
        <div class="section"><span class="section" id="functions">Functions</span></div>,
        for $function in $functions/xqdoc:function
        let $name := $function/xqdoc:name/text(),
            $signature := $function/xqdoc:signature/text(),
            $param-number := $function/@arity,
            $comment := $function/xqdoc:comment,
            $isDeprecated := fn:exists($comment/xqdoc:deprecated)
        order by $name, $param-number
        return (
            <div class="subsection" id="{$name}-{$param-number}">{
                if ($isDeprecated) then
                    <del>{xhtml:module-function-link($name, $signature)}</del>
                else
                    xhtml:module-function-link($name, $signature)
            }</div>,
            if ($isDeprecated) then
                <p><span class="deprecated">Deprecated</span>{
                    if (exists($comment/xqdoc:deprecated/node())) then
                        (" - ", $comment/xqdoc:deprecated/node())
                    else
                        ()
                }</p>
            else
                (),
            <pre class="signature">{xhtml:split-function-signature($signature)}</pre>,
            xhtml:description($comment),
            xhtml:parameters($comment),
            xhtml:return($comment),
            xhtml:errors($comment),
            xhtml:annotations($comment),
            xhtml:annotations-see($comment),
            xhtml:annotations-example($comment),
            <div id="allignright"><a href="#function_summary" title="Back to 'Function Summary'">'Function Summary'</a></div>,  
            <hr />)                
         )
    else ()
};

declare function xhtml:split-function-signature($signature as xs:string) {
    let $line1 := substring-before($signature, "(")
    let $rest := substring-after($signature, "(")
    let $params :=
        (: if the function has parameter :)
        if (matches($rest, "\$")) then
            let $tmp := substring-before($rest, ") as ")
            return 
                (: if we don't have a return type specified :)
                if ($tmp eq "") then
                    (: en external function declaration :)
                    if (ends-with($rest, ") external")) then
                        substring-before($rest, ") external")
                    (: no external function :)
                    else
                        $rest
                (: the return type is specified :)
                else
                    $tmp
        (: no parameters :)
        else
            ""
    let $after := substring-after($signature, concat($params, ")"))
    return (
        concat($line1, " ("),
        <br />,
        for $param at $pos in tokenize($params, "\$")
        where $pos > 1
        return (
            concat("            $", normalize-space($param)),
            <br/>                    
        ),
        concat(")", $after)
    )
};
