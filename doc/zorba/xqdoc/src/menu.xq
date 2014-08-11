xquery version "3.0";

(:~
 : Generate navigation for XQDoc batches.
 : 
 : @author William Candillon
 : @project Zorba/XQDoc/Menu
 :)
module namespace menu = "http://www.zorba-xquery.com/modules/xqdoc/menu";

declare namespace ver = "http://zorba.io/options/versioning";
declare option ver:module-version "2.0";

declare variable $menu:not-found as xs:QName := xs:QName('menu:not-found');

declare function menu:categories-as-js($url-prefix as xs:string, $cats as element())
as xs:string
{
  concat("URLPrefix = '", $url-prefix, "';categories = { children: [", string-join(menu:categories($cats), ","), "]};")
};

declare function menu:categories($top as element()) as xs:string* {
  for $child in $top/*
  return
    typeswitch($child)
    case element(module) return
      concat(
              "{ type: 'module', label: '",
              $child/@label,
              "', id: '",
              $child/@id,
              "', ns: '",
              $child/@ns,
              "'}"
            )
    case element(section) return
      concat(
              "{type: 'section', label: '",
              $child/@label,
              "', id: '",
              $child/@id,
              "', children: [",
              string-join(menu:categories($child), ", "), 
              "]}"
            )
    default return ""
};

(: Fetch an item from the category tree according to it's path. The path is split as a sequence of items  :)
declare function menu:item($ctx as element()?, $path as xs:string*)
as element()?
{
  if(empty($ctx)) then
    error($menu:not-found) 
  else if(empty($path)) then
    $ctx
  else
    menu:item($ctx/*[@id = $path[1]], subsequence($path, 2))
};

declare function menu:item-uri($item as element())
as xs:string
{
  let $path := menu:item-uri($item, ())
  return concat(string-join($path, "_"), ".html")
};

declare function menu:item-uri($item as element()?, $result as xs:string*)
as xs:string+
{
  if(empty($item)) then
    $result
  else
    menu:item-uri($item/parent::*, ($item/@id, $result))
};

declare function menu:closed-tabs($item as element(section), $url-prefix as xs:string)
as element(li)*
{
  menu:closed-tabs($item, (), $url-prefix)
};

declare function menu:closed-tabs($item as element()?, $result as element()*, $url-prefix as xs:string)
as element(li)*
{
  if(empty($item)) then
    $result
  else
    let $li := <li class="tab">
      <div class="button">
        <div class="holder">
          <a href="{concat($url-prefix, menu:item-uri($item))}" class="closed-tab">{string($item/@label)}</a>
        </div>
      </div>
    </li>
    return
      menu:closed-tabs($item/parent::section, ($li, $result), $url-prefix)
};

declare function menu:menu($item as element(), $url-prefix as xs:string)
{
<ul class="sub-menu" id="xqdoc-menu">
{
  let $parent := if($item instance of element(module)) then $item/parent::section/parent::section else $item/parent::section
  return
    if(exists($parent)) then
      menu:closed-tabs($parent, $url-prefix)
    else ()
}
{
  let $section := if($item instance of element(section)) then $item else $item/parent::section
  return
    <li class="tab active">
      <div class="button opened">
        <div class="holder">
          <a href="{concat($url-prefix, menu:item-uri($section))}" class="opened-tab">{string($section/@label)}</a>
        </div>
      </div>
      <ul>
      {
        for $element in $section/*
        return
          <li>
            {if($element/@id = $item/@id) then attribute class { "active" } else ()}
            <a href="{concat($url-prefix, menu:item-uri($element))}">
            {if($element instance of element(section)) then attribute class { "subsection" } else ()}
            {string($element/@label)}
            </a>
          </li>
      }
      </ul>
    </li>
}
</ul>
};
