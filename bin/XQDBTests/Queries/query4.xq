<html>
  <head />
  <body>
  {
    for $act in <doc>
                  <ACT>
                    <TITLE foo="foo">T</TITLE>
                    <SPEAKER>S1</SPEAKER>
                    <SPEAKER>S2</SPEAKER>
                  </ACT>
                </doc>
    let $speakers := distinct-values($act//SPEAKER)
    return
      <span>
        <h1>{$act/TITLE/text()}</h1>
        <ul>
        {
          for $speaker in $speakers
          return <li>{ $speaker }</li>
        }
        </ul>
      </span>
  }
  </body>
</html>
