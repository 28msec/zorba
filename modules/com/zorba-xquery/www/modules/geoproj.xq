(:
 : Copyright 2006-2009 The FLWOR Foundation.
 :
 : Licensed under the Apache License, Version 2.0 (the "License");
 : you may not use this file except in compliance with the License.
 : You may obtain a copy of the License at
 :
 : http://www.apache.org/licenses/LICENSE-2.0
 :
 : Unless required by applicable law or agreed to in writing, software
 : distributed under the License is distributed on an "AS IS" BASIS,
 : WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 : See the License for the specific language governing permissions and
 : limitations under the License.
:)

(:~
 : Geographic projection module.<br/>
 : Forward and inverse projection from WGS84 lat-long coordinates to Oblique Mercator x-y projection.<br/>
 : Oblique Mercator projection is a sphere to cylinder projection.<br/>
 : This projection results in a conformal output, meaning the shape of small areas is preserved,
 : no matter the distance from the origin. But it is not equal area, meaning the area size increases heavily
 : when getting closer to North or South. The area size increases with the same amount on x and y axes,
 : so the relative shape remains almost the same.   <br/>
 : Mercator projection is the oldest projection, and it is still widely used because it produces a rectangular map.
 : This projection is used in Google Maps because of its conformal output. <br/>
 : For military or measurements purposes the UTM projection is used (or variants). This splits the Earth into small
 : areas and computes the cartesian coordinates relative to each area.<br/>
 : <br/>
 : Here we use Oblique Mercator projection. Its advantage over the normal Mercator is that you can set the tangent point
 : between the cylinder and the sphere to be anywhere on Earth. So you can set the center of the map to be close
 : to the area you want projected and be able to measure accurately the distances between points and lines.
 : The map deformation is minimal close to the center point and close to the "equator" line.<br/>
 : The advantage over the UTM projection is that it can also produce a global rectangular map, like Mercator, 
 : which is great for viewing.<br/>
 : The disadvantage over Mercator is that it needs more processing power.<br/>
 : <br/>
 : WGS84 is the ellipsoid aproximation of the Earth, with big radius of 6,378,137 m and small radius of 6,356,752.3 m.
 : The geographic coordinates expressed for this ellipsoid are widely used today in maps and gps coordinates. 
 : It is the default standard for representing geographic coordinates.<br/>
 : <br/>
 : The purpose of this module is to provide convertion from polar to cartesian coordinates, so you can 
 : process the geographic data with the Simple Features API functions implemented in the geo module.
 : That module works only with cartesian coordinates, but most maps have polar coordinates. <br/>
 : <br/>
 : The projection formulas are taken from lib_proj library and implemented in XQuery. 
 :
 : @author Daniel Turcanu
 : @library <a href="http://trac.osgeo.org/geos/">GEOS (Geometry Engine - Open Source)</a>
 :)
module namespace geoproj = "http://www.zorba-xquery.com/modules/geoproj";
import module namespace math = "http://www.zorba-xquery.com/modules/math";
declare namespace gml="http://www.opengis.net/gml";

(:~
 : Convert angle from degrees to radians. <br/>
 : The parameter is first reduced to value range of (-360, 360).
 : 
 : @param $deg angle in  degrees
 : @return value in radians (-2PI, 2PI)
 :)
declare function geoproj:deg-to-rad($deg as xs:double) as xs:double
{
  ($deg mod 360) * 2 * math:pi() div 360
};

(:~
 : Convert angle from radians to degrees. <br/>
 : 
 : @param $rad value in radians
 : @return value in degrees (-360, 360)
 :)
declare function geoproj:rad-to-deg($rad as xs:double) as xs:double
{
  ($rad * 360 div 2 div math:pi()) mod 360
};


(:~
 : Compute the isometric latitude of $phi latitude.
 : 
 : @param $phi a latitude
 : @return isometric latitude in radians
 :)
declare %private function geoproj:proj-tsfn($phi as xs:double) as xs:double
{
   let $e := 0.0818192
   return
   math:tan(math:pi() div 4 - $phi div 2) div math:pow((1 - $e * math:sin($phi)) div (1 + $e * math:sin($phi)), $e div 2)
};

(:~
 : Forward projection from geographic coordinates lat-long on WGS84 ellipsoid to Oblique Mercator cylinder.<br/>
 : The Oblique Mercator projection is like the standard Mercator projection, but you can choose the point of origin.<br/>
 : Specify the coordinates of the center point somewhere near the points being projected, 
 : so the projection deformation is small.<br/>
 : The azimuth in the center point, alpha, is hardcoded to zero, so the true north is preserved.
 : This is a simplification of the standard Oblique Mercator projection. <br/>
 : Gamma, the azimuth of the rectified bearing of center line is also zero, calculated from alpha.<br/>
 : <br/>
 : The radius of the Earth in WGS84 is 6378137 m.<br/>
 : Reverse flatening 298.257223563.<br/>
 : Eccentricity e 0.0818192.<br/>
 :<br/>
 : @param $lat_0 is the latitude for center point, in degrees (-90, 90)
 : @param $long_c is the longitude for center point, in degrees (-180, 180)
 : @param $k0 is the scale in the center point. The scale will increase when going far to north and south.
 :        Use value 1 to get the true distances between points, in meters.
 :        At equator, the distance for 1 degree is aproximately 110 km.
 : @param $lat_long_degrees a sequence of nodes of type <br/>
 :   &lt;latlong&gt;&lt;lat&gt;<i>latitude degree</i>&lt;/lat&gt;&lt;long&gt;<i>longitude degree</i>&lt;/long&gt;&lt;/latlong&gt;
 : @return a sequence of x-y coordinates in format <br/>
 :   &lt;coord&gt;&lt;x&gt;<i>x</i>&lt;/x&gt;&lt;y&gt;<i>y</i>&lt;/y&gt;&lt;/coord&gt; <br/>
 :   Note that the x coordinate corresponds to the longitude, and y coordinate to the latitude.<br/>
 :   The coordinates are expressed in meters.<br/>
 :   The coordinates are relative to the center point.
 :)
declare function geoproj:wgs84-to-omerc( $lat_0 as xs:double,
                                         $long_c as xs:double,
                                         $k0 as xs:double,
                                         $lat_long_degrees as node()*) as node()*
{
  let $e := 0.0818192
  let $e2 := $e*$e
  let $phi0 := geoproj:deg-to-rad($lat_0)
  let $lambda0 := geoproj:deg-to-rad($long_c)
  let $sin_phi0 := math:sin($phi0)
  let $sin2_phi0 := $sin_phi0 * $sin_phi0
  let $cos_phi0 := math:cos($phi0)
  let $aphi0 := abs($phi0)
  let $B := if ($aphi0 gt 1e-10) then math:sqrt(1 + $e2 div (1 - $e2) * math:pow($cos_phi0, 4)) else math:sqrt(1 - $e2)
  let $A := if ($aphi0 gt 1e-10) then $B * $k0 * math:sqrt(1 - $e2) div (1 - $e2*$sin2_phi0) else $k0
  let $t0 := geoproj:proj-tsfn($phi0)
  let $D := if ($aphi0 gt 1e-10) then $B * math:sqrt(1 - $e2) div ($cos_phi0 * math:sqrt(1 - $e2*$sin2_phi0)) else 1
  let $D := if ($D*$D < 1) then 1 else $D
  let $F := if ($aphi0 gt 1e-10) then if ($phi0 < 0) then $D - math:sqrt($D*$D - 1) else $D + math:sqrt($D*$D - 1) else 1
  let $E := if ($aphi0 gt 1e-10) then math:pow($t0, $B) * $F else 1
  
  let $G := ($F - 1 div $F) div 2
  let $uc := abs($A div $B * math:atan2(math:sqrt($D*$D - 1), 1))
  let $uc := if ($phi0 < 0) then -$uc else $uc
  
  for $latlong in $lat_long_degrees
  let $phi := geoproj:deg-to-rad(normalize-space(string($latlong/lat)) cast as xs:double)
  let $lambda := geoproj:deg-to-rad(normalize-space(string($latlong/long)) cast as xs:double)
  let $V := math:sin($B * ($lambda - $lambda0))
	return
    	if (abs($phi) lt (math:pi() div 2 - 1.e-10)) then
    	  let $Q := $E div math:pow(geoproj:proj-tsfn($phi) , $B)
    	  let $S := ($Q - 1 div $Q) div 2
    	  let $T := ($Q + 1 div $Q) div 2
    	  let $U := -$V div $T
          let $v := if (abs($U) ne 1) then $A div (2 * $B) * math:log((1 - $U) div (1 + $U)) else 1 div 0
          let $M := math:cos($B * ($lambda - $lambda0))
          let $u := if ($M gt 1e-7) then $A div $B * math:atan2($S, $M) else $A*$B*($lambda - $lambda0)
          let $u := $u - $uc
          let $x := $v
          let $x := $x * 6378137
          let $y := $u
          let $y := $y * 6378137
          return <coord><x>{$x}</x> <y>{$y}</y></coord>
        else
          let $v := $A div $B * -4.2897288031186085136750723197195
          let $u := $phi * $A div $B
          let $u := $u - $uc
          let $x := $v
          let $x := $x * 6378137
          let $y := $u
          let $y := $y * 6378137
          return <coord><x>{$x}</x> <y>{$y}</y></coord>
};

(:~
 : Forward projection from geographic coordinates lat-long on WGS84 ellipsoid to Oblique Mercator cylinder.<br/>
 : This is an intermediate function for wgs84-to-omerc.<br/>
 : The difference is that it returns the x-y coordinates in gml:pos format,
 : gml being the prefix for the GML namespace "http://www.opengis.net/gml".<br/>
 :<br/>
 : @param $lat_0 is the latitude for center point, in degrees (-90, 90)
 : @param $long_c is the longitude for center point, in degrees (-180, 180)
 : @param $k0 is the scale in the center point. 
 : @param $lat_long_degrees a sequence of nodes of type <br/>
 :   &lt;latlong&gt;&lt;lat&gt;<i>latitude degree</i>&lt;/lat&gt;&lt;long&gt;<i>longitude degree</i>&lt;/long&gt;&lt;/latlong&gt;
 : @return a sequence of x-y coordinates in format <br/>
 :   &lt;gml:pos&gt;<i>x</i> <i>y</i>&lt;/gml:pos&gt; <br/>
 :)
declare function geoproj:wgs84-to-omerc-gmlpos( $lat_0 as xs:double,
                                         $long_c as xs:double,
                                         $k0 as xs:double,
                                         $lat_long_degrees as node()*) as node()*
{
  for $coord in geoproj:wgs84-to-omerc($lat_0, $long_c, $k0, $lat_long_degrees)
  return
    <gml:pos>{string($coord/x)}{" "}{string($coord/y)}</gml:pos>
};

(:~
 : Function for iterative computing of the inverse isometric latitude.
 : 
 : @param $i the maximum iterations
 : @param $ts precomputed value
 : @param $e the Earth eccentricity. For WGS84 is hardcoded to 0.0818192.
 : @param $prev_phi previous computed inverse isometric latitude
 : @return isometric latitude in radians
 :)
declare %private function geoproj:proj-phi2-helper($i as xs:integer, 
                                          $ts as xs:double , $e as xs:double,
                                          $prev_phi as xs:double) as xs:double
{
    if($i eq 0) then
      $prev_phi
    else
      let $phi := math:pi() div 2 - 2 * math:atan($ts * math:pow((1 - $e * math:sin($prev_phi[1])) div (1 + $e * math:sin($prev_phi[1])), $e div 2))
      return 
        if (abs($prev_phi - $phi) le 1.0e-10) then
          $phi
        else
          geoproj:proj-phi2-helper($i - 1, $ts, $e, $phi)
};

(:~
 : Function for computing the inverse isometric latitude.
 : 
 : @param $ts precomputed value, based on an initial latitude.
 : @param $e the Earth eccentricity. For WGS84 is hardcoded to 0.0818192.
 : @return inverse isometric latitude in radians
 :)
declare %private function geoproj:proj-phi2($ts as xs:double, $e as xs:double) as xs:double
{
  let $phi := math:pi() div 2 - 2 * math:atan($ts)
  return
     geoproj:proj-phi2-helper(15, $ts, $e, ($phi))
};

(:~
 : Inverse projection from cartesian coordinates on Oblique Mercator cylinder
 : to geographic coordinates lat-long on WGS84 ellipsoid.<br/>
 : The parameters for center point and scale should be the same as for the initial forward projection,
 : otherwise you will get wrong results.<br/>
 : <br/>
 :<br/>
 : @param $lat_0 is the latitude for center point, in degrees (-90, 90)
 : @param $long_c is the longitude for center point, in degrees (-180, 180)
 : @param $k0 is the scale in the center point.
 : @param $coords a sequence of nodes of type <br/>
 :   &lt;coord&gt;&lt;x&gt;<i>x</i>&lt;/x&gt;&lt;y&gt;<i>y</i>&lt;/y&gt;&lt;/coord&gt; <br/>
 :   The coordinates are expressed in meters.
 : @return a sequence of geographic coordinates in format <br/>
 :   &lt;latlong&gt;&lt;lat&gt;<i>latitude degree</i>&lt;/lat&gt;&lt;long&gt;<i>longitude degree</i>&lt;/long&gt;&lt;/latlong&gt;<br/>
 :   Note that the longitude corresponds to the x coordinate, and the latitude to the y coordinate.<br/>
 :)
declare function geoproj:omerc-to-wgs84($lat_0 as xs:double,
                                         $long_c as xs:double,
                                         $k0 as xs:double,
                                         $coords as node()*) as node()*
{
  let $e := 0.0818192
  let $e2 := $e*$e
  let $phi0 := geoproj:deg-to-rad($lat_0)
  let $lambda0 := geoproj:deg-to-rad($long_c)
  let $sin_phi0 := math:sin($phi0)
  let $sin2_phi0 := $sin_phi0 * $sin_phi0
  let $cos_phi0 := math:cos($phi0)
  let $aphi0 := abs($phi0)
  let $B := if ($aphi0 gt 1.e-10) then math:sqrt(1 + $e2 div (1 - $e2) * math:pow($cos_phi0, 4)) else math:sqrt(1 - $e2)
  let $A := if ($aphi0 gt 1.e-10) then $B * $k0 * math:sqrt(1 - $e2) div (1 - $e2*$sin2_phi0) else $k0
  let $t0 := geoproj:proj-tsfn($phi0)
  let $D := if ($aphi0 gt 1.e-10) then $B * math:sqrt(1 - $e2) div ($cos_phi0 * math:sqrt(1 - $e2*$sin2_phi0)) else 1
  let $D := if ($D*$D < 1) then 1 else $D
  let $F := if ($aphi0 gt 1.e-10) then if ($phi0 < 0) then $D - math:sqrt($D*$D - 1) else $D + math:sqrt($D*$D - 1) else 1
  let $E := if ($aphi0 gt 1.e-10) then math:pow($t0, $B) * $F else 1
  
  let $G := ($F - 1 div $F) div 2
  let $uc := abs($A div $B * math:atan2(math:sqrt($D*$D - 1), 1))
  let $uc := if ($phi0 < 0) then -$uc else $uc
  
  for $coord in $coords
  let $x := (normalize-space($coord/x) cast as xs:double) div 6378137
  let $y := (normalize-space($coord/y) cast as xs:double) div 6378137
  let $v := $x
  let $u := $y + $uc
  let $Qp := math:exp(-$B * $v div $A)
  let $Sp := ($Qp - 1 div $Qp) div 2
  let $Tp := ($Qp + 1 div $Qp) div 2
  let $Vp := math:sin($B * $u div $A)
  let $Up := $Vp div $Tp
  return
    if(abs(abs($Up) - 1) lt 1e-10) then
      if ($Up gt 0) then
        <latlong><lat>90</lat> <long>{$long_c}</long></latlong>
      else
        <latlong><lat>-90</lat> <long>{$long_c}</long></latlong>
    else
      let $phi := $E div math:sqrt((1 + $Up) div (1 - $Up))
      let $phi := geoproj:proj-phi2(math:pow($phi, 1 div $B), $e)
      let $lambda := - 1 div $B * math:atan2($Sp, math:cos($B * $u div $A))
      return
        <latlong><lat>{geoproj:rad-to-deg($phi)}</lat> <long>{geoproj:rad-to-deg($lambda+$lambda0)}</long></latlong>
};

(:~
 : Inverse projection from cartesian coordinates on Oblique Mercator cylinder
 : to geographic coordinates lat-long on WGS84 ellipsoid.<br/>
 : This is an intermediate function for omerc-to-wgs84.<br/>
 : The difference is that it works with coordinates in gml:pos format,
 : gml being the prefix for the GML namespace "http://www.opengis.net/gml".<br/>
 :<br/>
 : @param $lat_0 is the latitude for center point, in degrees (-90, 90)
 : @param $long_c is the longitude for center point, in degrees (-180, 180)
 : @param $k0 is the scale in the center point. 
 : @param $gmlposs a sequence of nodes of type <br/>
 :   &lt;gml:pos&gt;<i>x</i> <i>y</i>&lt;/gml:pos&gt; <br/>
 : @return a sequence of geographic coordinates in format <br/>
 :   &lt;latlong&gt;&lt;lat&gt;<i>latitude degree</i>&lt;/lat&gt;&lt;long&gt;<i>longitude degree</i>&lt;/long&gt;&lt;/latlong&gt;
 :)
declare function geoproj:omerc-gmlpos-to-wgs84($lat_0 as xs:double,
                                         $long_c as xs:double,
                                         $k0 as xs:double,
                                         $gmlposs as node()*) as node()*
{
  geoproj:omerc-to-wgs84($lat_0, $long_c, $k0,
                  (for $gmlpos in $gmlposs
                  let $xystring := normalize-space(fn:string($gmlpos))
                  let $xy := tokenize($xystring, "[ \t\r\n]+")
                  let $x := $xy[1]
                  let $y := $xy[2]
                  return <coord><x>{$x}</x><y>{$y}</y></coord>))
};

(:~
 : Convertion from Degrees-Minutes-Seconds (DMS) to Degrees.<br/>
 : The values for DMS can be like 11d12'13", meaning 11 degrees, 12 minutes and 13 seconds.<br/>
 : One degree has 60 minutes, and one minute has 60 seconds.<br/>
 : The separator for degrees can be one of the characters [dDoO].<br/>
 : The separator for minutes can be one of the characters ['m].<br/>
 : The separator for seconds can be " or nothing.<br/>
 : The seconds can be a floating point number.<br/>
 : <br/>
 : The seconds can be missing, and if it is missing, the minutes can be missing too.<br/>
 : The negative value can be expressed as -11d12'13" or 11d12'13"S or 11d12'13"W.
 : Values for N (North) and E (East) are positive, and S (South) and W (West) are negative.
 :<br/>
 : @param $dms the degree-minutes-seconds string expressed in the format described above
 : @return the value in degrees 
 :)
declare function geoproj:dms-to-deg($dms as xs:string) as xs:double
{
  let $dms := normalize-space($dms)
  let $dtok := tokenize($dms, "([DdOo])|([SNEW]$)")
  let $d := $dtok[1] cast as xs:double
  let $dsign := if($d < 0) then -1 else 1
  let $d := abs($d)
  return
    if(count($dtok) eq 1) then
      $dsign*$d
    else
      if(string-length($dtok[2]) eq 0) then
        if(matches($dms, "[SW]$")) then
          -$d
        else
          $dsign*$d
      else
        let $ms := substring($dms, string-length($dtok[1]) + 1 + 1)
        let $mtok := tokenize($ms, "(['m])|([SNEW]$)")
        let $m := abs($mtok[1] cast as xs:double)
        let $d := $d + $m div 60
        return
        if(count($mtok) eq 1) then
          $dsign*$d
        else
          if(string-length($mtok[2]) eq 0) then
            if(matches($dms, "[SW]$")) then
              -$d
            else
              $dsign*$d
          else
            let $ss := substring($ms, string-length($mtok[1]) + 1 + 1)
            let $stok := tokenize($ss, '"|([SNEW]$)')
            let $s := abs($stok[1] cast as xs:double)
            let $d := $d + $s div 3600
            return
              if(matches($dms, "[SW]$")) then
                -$d
              else
                $dsign*$d
};

(:~
 : Convertion from Degrees to Degrees-Minutes-Seconds (DMS).<br/>
 : <br/>
 : @param $deg the degree value
 : @return the value in DMS format, <i>[-]degree</i><b>d</b><i>minutes</i><b>'</b><i>seconds</i> 
 :)
declare function geoproj:deg-to-dms($deg as xs:double) as xs:string
{
  let $d := $deg cast as xs:integer
  let $ms := abs($deg - $d) * 60
  let $m := $ms cast as xs:integer
  let $s := $ms - $m
  let $s := $s * 60
  let $m := if($s ge (60 - 1e-10)) then $m + 1 else $m
  let $d := if($m ge (60 - 1e-10)) then $d + 1 else $d
  let $m := if($m ge (60 - 1e-10)) then $m - 60 else $m
  let $s := if($s ge (60 - 1e-10)) then 0 else $s
  return
    concat($d, "d", $m, "'", $s)
};
