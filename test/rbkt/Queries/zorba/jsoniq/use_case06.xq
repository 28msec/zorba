import module namespace j = "http://www.jsoniq.org/functions";

declare variable $input :=
  {
   "color" : "blue",
   "closed" : true(),
   "points" : [[10,10], [20,10], [20,20], [10,20]]
  };

declare variable $stroke := attribute stroke { $input("color") };
declare variable $points := attribute points { j:flatten($input("points")) };

if ($input("closed")) then
  <svg><polygon>{ $stroke, $points }</polygon></svg>
else
  <svg><polyline>{ $stroke, $points }</polyline></svg>
