import module namespace datetime = "http://zorba.io/modules/datetime";

declare namespace ann = "http://zorba.io/annotations";

declare %ann:sequential function local:index()
{ 
  variable $table :=
      for $i in 1 to 10000
      return
          {
            variable $local:datetime;
            variable $local:date;
            variable $local:time;
            $local:datetime := datetime:current-dateTime();
            $local:date     := datetime:current-date();
            $local:time     := datetime:current-time();
            <tr>
              <td> { $local:datetime } </td>
              <td> { $local:date } </td>
              <td> { $local:time } </td>                                                                               
            </tr>
          };

  let $wrapped := <table> { $table } </table>
  return
      <html>
        <body>
          <b> Different DateTimes: { count(fn:distinct-values($wrapped//tr/td[1])) gt 1 } </b><br/>
          <b> Different Dates: { count(fn:distinct-values($wrapped//tr/td[2])) gt 1 } </b><br/>
          <b> Different Times: { count(fn:distinct-values($wrapped//tr/td[3])) gt 1 } </b><br/>
        </body>
      </html>
};


local:index()
