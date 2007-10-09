declare namespace 
  env="http://www.w3.org/2003/05/soap-envelope";
declare namespace 
  m="http://travelcompany.example.org/reservation";
declare namespace 
  n="http://mycompany.example.com/employees";
declare namespace 
  p="http://travelcompany.example.org/reservation/travel";

(:  A clarification is needed only if there are no
 :  airports or more than one for a given city. If
 :  there is precisely one, there is no need to
 :  ask for information on that city.
 :)

declare function local:airportChoices($city as xs:string)
{
  let $airports := collection("airports")[CITY = $city]
  return
    if (count($airports) = 0)
    then 
       <error> No airports found for {$city}!</error>
    else if (count($airports) > 1) 
    then 
       <airportChoices>
        { 
          for $c in $airports/CODE
          return (string-value( $c ), " ")
        }
       </airportChoices>
    else ()
};

(:  Make sure that each airport is unambiguous. If there is
 :  more than one airport for a city, ask for clarification.
 :
 :  The primer only shows the error condition, so it is not
 :  clear what to do if there are no errors. Here, we simply
 :  return the airports in the itinerary.
 :)

declare function local:airports($in as element(env:Envelope))
{
    let $departureDeparting := 
      $in//p:departure/p:departing
    let $departureDepartingAirports := 
      collection("airports")[CITY = $departureDeparting]
    let $departureArriving := 
      $in//p:departure/p:arriving
    let $departureArrivingAirports := 
      collection("airports")[CITY = $departureArriving]
    let $returnDeparting := 
      $in//p:return/p:departing
    let $returnDepartingAirports := 
      collection("airports")[CITY = $returnDeparting]
    let $returnArriving := 
      $in//p:return/p:arriving
    let $returnArrivingAirports := 
      collection("airports")[CITY = $returnArriving]
    return
       if ( count($departureDepartingAirports)=0 or 
            count($departureDepartingAirports)>1 or 
            count($departureArrivingAirports)=0 or 
            count($departureArrivingAirports)>1 or 
            count($returnDepartingAirports)=0 or 
            count($returnDepartingAirports)>1 or 
            count($returnArrivingAirports)=0 or 
            count($returnArrivingAirports)>1 )
         then
          <p:itineraryClarification>
            <p:departure>
              <p:departing>
                { local:airportChoices($departureDeparting) }
              </p:departing>
              <p:arriving>
                { local:airportChoices($departureArriving) }
              </p:arriving> 
            </p:departure>
            <p:return>
              <p:departing>
                { local:airportChoices($returnDeparting) }
              </p:departing>
              <p:arriving>
                { local:airportChoices($returnArriving) }
              </p:arriving>
            </p:return>
          </p:itineraryClarification>
         else 
          <p:itinerary>
            <p:departure>
              <p:departing>{$departureDeparting}</p:departing>
              <p:arriving>{$departureArriving}</p:arriving>
            </p:departure>
            <p:return>
              <p:departing>{$returnDeparting}</p:departing>
              <p:arriving>{$returnArriving}</p:arriving>
            </p:return>
          </p:itinerary>
};

declare variable $msg external;

transform 
  copy $out := $msg/env:Envelope
  modify (
    do replace value of $out//m:dateAndTime 
       with fn:currentDateTime(),
    do replace $out//env:Body 
    with <env:Body>
          { local:airports($in) }
         </env:Body>
  )
  return $out
