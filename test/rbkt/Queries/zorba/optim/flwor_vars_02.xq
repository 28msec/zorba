
declare %private function local:serialize-request-as-xml()
{
  ()
};


declare function local:serialize-request-as-html()
{
  let $request := local:serialize-request-as-xml()
  return
    for $section in $request/element()
    return
      for $info in $section/element()
      return
        for $value in $info/value
        let $content := switch(false())
                        case false() return ()
                        default return $value/text()
        return
          switch(string($value/@class))
          case "error" return $content
          default return $content
};


local:serialize-request-as-html()


