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
 : Function library providing geo processing using Simple Features api over
 : GMLSF format. <br/>
 : It uses the GEOS external library, license LGPL. Version 3.2.2 or above.<br/>
 : <br/>
 : The data format supported now is GMLSF 0/1. GMLSF 2 will be supported soon.<br/>
 : This is a subset of GML, and covers the basic geometries of Point, Line and Surface and collections of those.<br/>
 : GMLSF nodes have the namespace "http://www.opengis.net/gml".<br/>
 : <br/>
 : Possible GMLSF geometric structures are:
 : <dl>
 :  <dt><b>Point</b></dt>
 :  <dd>&lt;gml:Point&gt;<br/>
 :    &#160;&#160;&lt;gml:pos&gt;double_x double_y &lt;/gml:pos&gt;<br/>
 :  &lt;/gml:Point&gt;</dd>
 :  <dt><b>LineString</b></dt>
 :  <dd>&lt;gml:LineString&gt;<br/>
 :    &#160;&#160;&lt;gml:posList&gt; double_x1 double_y1 double_x2 double_y2 ... &lt;/gml:posList&gt;<br/>
 :    &lt;/gml:LineString&gt;</dd>
 :  <dt><b>Curve</b></dt>
 :  <dd>&lt;gml:Curve&gt;<br/>
 :    &lt;gml:segments&gt; <br/>
 :    [&lt;gml:LineStringSegment interpolation="linear"&gt;<br/>
 :     &#160;&#160;&lt;gml:posList&gt; double_x1 double_y1 double_x2 double_y2 ... &lt;/gml:posList&gt;<br/>
 :     &lt;gml:LineStringSegment&gt;]*<br/>
 :    &lt;/gml:segments&gt;<br/>
 :    &lt;/gml:Curve&gt;
 :   </dd>
 :  <dt><b>LinearRing</b></dt>
 :  <dd>&lt;gml:LinearRing&gt;<br/>
 :   &#160;&#160;&lt;gml:posList&gt; double_x1 double_y1 double_x2 double_y2 ... &lt;/gml:posList&gt;<br/>
 :   &lt;/gml:LinearRing&gt;</dd>
 :  <dt><b>Surface</b></dt>
 :  <dd>&lt;gml:Surface&gt;<br/>
 :    &lt;gml:patches&gt; <br/>
 :    [&lt;gml:PolygonPatch&gt;<br/>
 :     &#160;&#160;&lt;gml:exterior&gt;<br/>
 :     &#160;&#160;&#160;&#160;&lt;gml:LinearRing&gt; ... &lt;/gml:LinearRing&gt;<br/>
 :     &#160;&#160;&lt;/gml:exterior&gt;<br/>
 :     &#160;&#160;[&lt;gml:interior&gt;<br/>
 :     &#160;&#160;&#160;&#160;&lt;gml:LinearRing&gt; ... &lt;/gml:LinearRing&gt;<br/>
 :     &#160;&#160;&lt;/gml:interior&gt;]*<br/>
 :     &lt;/gml:PolygonPatch&gt;]*<br/>
 :    &lt;/gml:patches&gt;<br/>
 :    &lt;/gml:Surface&gt;
 :  </dd>
 :  <dt><b>Polygon</b></dt>
 :  <dd>&lt;gml:Polygon&gt;<br/>
 :     &#160;&#160;&lt;gml:exterior&gt;<br/>
 :     &#160;&#160;&#160;&#160;&lt;gml:LinearRing&gt; ... &lt;/gml:LinearRing&gt;<br/>
 :     &#160;&#160;&lt;/gml:exterior&gt;<br/>
 :     &#160;&#160;[&lt;gml:interior&gt;<br/>
 :     &#160;&#160;&#160;&#160;&lt;gml:LinearRing&gt; ... &lt;/gml:LinearRing&gt;<br/>
 :     &#160;&#160;&lt;/gml:interior&gt;]*<br/>
 :    &lt;/gml:Polygon&gt;
 :  </dd>
 :  <dt><b>MultiPoint</b></dt>
 :  <dd>&lt;gml:MultiPoint&gt;<br/>
 :     &#160;&#160;[&lt;gml:Point&gt; ... &lt;/gml:Point&gt;]*<br/>
 :    &lt;/gml:MultiPoint&gt;
 :  </dd>
 :  <dt><b>MultiCurve</b></dt>
 :  <dd>&lt;gml:MultiCurve&gt;<br/>
 :     &#160;&#160;[&lt;gml:LineString&gt; ... &lt;/gml:LineString&gt;]*<br/>
 :    &lt;/gml:MultiCurve&gt;
 :  </dd>
 :  <dt><b>MultiSurface</b></dt>
 :  <dd>&lt;gml:MultiSurface&gt;<br/>
 :     &#160;&#160;[&lt;gml:Polygon&gt; ... &lt;/gml:Polygon&gt;]*<br/>
 :    &lt;/gml:MultiSurface&gt;
 :  </dd>
 : </dl><br/><br/>
 : Note: When using gml:posList, it is possible to replace this element with a list of gml:pos.<br/>
 : <br/>
 : For operations between two geometries, the DE-9IM matrix is used. The DE-9IM matrix is defined like this:
 : <table>
 :	<tr>
 :		 <td></td>
 :		 <td><b>Interior</b></td>
 :		 <td><b>Boundary</b></td>
 :		 <td><b>Exterior</b></td>
 :		</tr>
 :		<tr>
 :		 <td><b>Interior</b></td>
 :		 <td>dim(intersection of interior1 and interior2)</td>
 :		 <td>dim(intersection of interior1 and boundary2)</td>
 :		 <td>dim(intersection of interior1 and exterior2)</td>
 :		</tr>
 :		<tr>
 :		 <td><b>Boundary</b></td>
 :		 <td>dim(intersection of boundary1 and interior2)</td>
 :		 <td>dim(intersection of boundary1 and boundary2)</td>
 :		 <td>dim(intersection of boundary1 and exterior2)</td>
 :		</tr>
 :		<tr>
 :		 <td><b>Exterior</b></td>
 :		 <td>dim(intersection of exterior1 and interior2)</td>
 :		 <td>dim(intersection of exterior1 and boundary2)</td>
 :		 <td>dim(intersection of exterior1 and exterior2)</td>
 :		</tr>
 :	</table>
 :	<br/>
 :	The values in the DE-9IM can be T, F, *, 0, 1, 2 .<br/>
 :  - T means the intersection gives a non-empty result.<br/>
 :  - F means the intersection gives an empty result.<br/>
 :  - * means any result.<br/>
 :  - 0, 1, 2 gives the expected dimension of the result (point, curve, surface)<br/>
 : <br/><br/>
 :
 : @version 1.0 
 : @author Daniel Turcanu
 :
 : @see http://www.opengeospatial.org/standards/sfa
 : @see http://www.opengeospatial.org/standards/gml
 : @see http://trac.osgeo.org/geos/
 :)
module namespace zorba-geo = "http://www.zorba-xquery.com/modules/geo";

(:~
 : Return the dimension of the geo object. 
 : 
 : @param $geometry node of one of GMLSF objects: gml:Point, gml:LineString, gml:Curve,
 :    gml:LinearRing, gml:Surface, gml:Polygon, gml:MultiPoint, gml:MultiCurve, gml:MultiSurface
 : @return 0 for point, 1 for line, 2 for surface.
 : @error XPTY0004 - unrecognized geometric object
:)
declare function zorba-geo:dimension( $geometry as node()) as xs:integer external;

(:~
 : Return the coordinate dimension of the geo object. 
 : 
 : @param $geometry node of one of GMLSF objects: gml:Point, gml:LineString, gml:Curve,
 :    gml:LinearRing, gml:Surface, gml:Polygon, gml:MultiPoint, gml:MultiCurve, gml:MultiSurface
 : @return 2 for 2D, 3 for 3D. For now only 2D is supported.
 : @error XPTY0004 - unrecognized geometric object
:)
declare function zorba-geo:coordinate-dimension( $geometry as node()) as xs:integer external;

(:~
 : Return the string type of geo object. 
 : 
 : @param $geometry node of one of GMLSF objects: gml:Point, gml:LineString, gml:Curve,
 :    gml:LinearRing, gml:Surface, gml:Polygon, gml:MultiPoint, gml:MultiCurve, gml:MultiSurface
 : @return "Point" for Point, "LineString" for LineString, "Curve" for Curve, "LinearRing" for LinearRing,
 :     "Surface" for Surface, "Polygon" for Polygon, "MultiPoint" for MultiPoint, "MultiCurve" for MultiCurve,
 :     "MultiSurface" for MultiSurface
 : @error XPTY0004 - unrecognized geometric object
:)
declare function zorba-geo:geometry-type( $geometry as node()) as xs:string external;

(:~
 : Return the number of geometries in the collection, or 1 for non-collection. 
 : 
 : @param $geometry node of one of GMLSF objects: gml:Point, gml:LineString, gml:Curve,
 :    gml:LinearRing, gml:Surface, gml:Polygon, gml:MultiPoint, gml:MultiCurve, gml:MultiSurface
 : @return number of geometries in collection
 : @error XPTY0004 - unrecognized geometric object
:)
declare function zorba-geo:num-geometries( $geometry as node()) as xs:unsignedInt external;

(:~
 : Return the n-th geometry in the collection. 
 : Return this geometry if it is not a collection.
 : N is zero based.
 : 
 : @param $geometry node of one of GMLSF objects: gml:Point, gml:LineString, gml:Curve,
 :    gml:LinearRing, gml:Surface, gml:Polygon, gml:MultiPoint, gml:MultiCurve, gml:MultiSurface
 : @param $n zero-based index in the collection
 : @return n-th geometry in collection. The node is a copy of the original node.
 : @error XPTY0004 - unrecognized geometric object
:)
declare function zorba-geo:geometry-n( $geometry as node(), $n as xs:unsignedInt) as node() external;

(:~
 : The envelope is the minimum bounding box of this geometry.
 : 
 : @param $geometry node of one of GMLSF objects: gml:Point, gml:LineString, gml:Curve,
 :    gml:LinearRing, gml:Surface, gml:Polygon, gml:MultiPoint, gml:MultiCurve, gml:MultiSurface
 : @return A rectangle gml:Polygon with coordinates (minx, miny), (maxx, miny), (maxx, maxy), (minx, maxy), (minx, miny) <br/>
 :     Or a gml:Point for Point geometry.
 : @error XPTY0004 - unrecognized geometric object
:)
declare function zorba-geo:envelope( $geometry as node()) as node() external;

(:~
 : Return the Well-known Text Representation of Geometry. 
 : This is defined in the Simple Features spec from OGC.
 : 
 : @param $geometry node of one of GMLSF objects: gml:Point, gml:LineString, gml:Curve,
 :    gml:LinearRing, gml:Surface, gml:Polygon, gml:MultiPoint, gml:MultiCurve, gml:MultiSurface
 : @return the Well-known Text Representation for the geo object.
 : @error XPTY0004 - unrecognized geometric object
:)
declare function zorba-geo:as-text( $geometry as node()) as xs:string external;

(:~
 : Return the Well-known Binary Representation of Geometry. 
 : This is defined in the Simple Features spec from OGC.
 : 
 : @param $geometry node of one of GMLSF objects: gml:Point, gml:LineString, gml:Curve,
 :    gml:LinearRing, gml:Surface, gml:Polygon, gml:MultiPoint, gml:MultiCurve, gml:MultiSurface
 : @return the Well-known Binary Representation for the geo object as hex string.
 : @error XPTY0004 - unrecognized geometric object
:)
declare function zorba-geo:as-binary( $geometry as node()) as xs:string external;

(:~
 : Checks if the argument is empty or not and if it is a valid geometry or not. 
 : 
 : @param $geometry node of one of GMLSF objects: gml:Point, gml:LineString, gml:Curve,
 :    gml:LinearRing, gml:Surface, gml:Polygon, gml:MultiPoint, gml:MultiCurve, gml:MultiSurface
 : @return true if $geometry is not a valid gmlsf object.
:)
declare function zorba-geo:is-empty( $geometry as node()?) as xs:boolean external;

(:~
 : Checks if this geometric object has no anomalous geometric points, such
 :	as self intersection or self tangency. 
 : Does not work for gml:Curve and gml:Surface.
 : 
 : @param $geometry node of one of GMLSF objects: gml:Point, gml:LineString,
 :    gml:LinearRing, gml:Polygon, gml:MultiPoint, gml:MultiCurve, gml:MultiSurface
 : @return true if $geometry is simple.
 : @error XPTY0004 - unrecognized geometric object
:)
declare function zorba-geo:is-simple( $geometry as node()) as xs:boolean external;

(:~
 : Checks if this geometric object is 2D or 3D.<br/>
 : Only 2D objects are supported for now. 
 : 
 : @param $geometry node of one of GMLSF objects: gml:Point, gml:LineString, gml:Curve,
 :    gml:LinearRing, gml:Surface, gml:Polygon, gml:MultiPoint, gml:MultiCurve, gml:MultiSurface
 : @return true if $geometry is 3D. Result is hardcoded to false for now.
 : @error XPTY0004 - unrecognized geometric object
:)
declare function zorba-geo:is-3D( $geometry as node()) as xs:boolean external;

(:~
 : A boundary is a set that represents the limit of an geometry.<br/>
 : For a Point, the boundary is the empty geometry.<br/>
 : For a LineString, the boundary is the set of start point and end point.<br/>
 : For a LinearRing, the boundary is empty MultiPoint.<br/>
 : For a Polygon, the boundary is the set of exterior and interior rings.<br/>
 :<br/>
 : Note: For MultiCurve, the boundary processes only the first LineString.<br/>
 : Note: This operation is not supported for gml:Curve and gml:Surface.<br/>
 : 
 : @param $geometry node of one of GMLSF objects: gml:Point, gml:LineString, gml:Curve,
 :    gml:LinearRing, gml:Surface, gml:Polygon, gml:MultiPoint, gml:MultiCurve, gml:MultiSurface
 : @return the boundary of a Geometry as a set of Geometries of the next lower dimension.
 : @error XPTY0004 - unrecognized geometric object
:)
declare function zorba-geo:boundary( $geometry as node()) as node() external;


(:~
 : Checks if the two geometries are equal.<br/>
 :<br/>
 : Note: Does not work for gml:Surface and gml:MultiSurface if they have multiple Polygons.<br/>
 : 
 : @param $geometry1 node of one of GMLSF objects: gml:Point, gml:LineString, gml:Curve,
 :    gml:LinearRing, gml:Surface, gml:Polygon, gml:MultiPoint, gml:MultiCurve, gml:MultiSurface
 : @param $geometry2 node of one of GMLSF objects: gml:Point, gml:LineString, gml:Curve,
 :    gml:LinearRing, gml:Surface, gml:Polygon, gml:MultiPoint, gml:MultiCurve, gml:MultiSurface
 : @return true if the DE-9IM intersection matrix for the two Geometrys is T*F**FFF*.
 : @error XPTY0004 - unrecognized geometric object
:)
declare function zorba-geo:equals( $geometry1 as node(),  $geometry2 as node()) as xs:boolean external;

(:~
 : Checks if geometry1 covers geometry2.<br/>
 : It has to fulfill one of these conditions:<br/>
 :  - every point of geometry2 is a point of geometry1<br/>
 :  - the DE-9IM Intersection Matrix for the two geometries is
 :     T*****FF* or *T****FF* or ***T**FF* or ****T*FF*.<br/>
 : <br/>
 : Unlike contains it does not distinguish between points in the boundary and in the interior of geometries.
 :
 : @param $geometry1 node of one of GMLSF objects: gml:Point, gml:LineString, gml:Curve,
 :    gml:LinearRing, gml:Surface, gml:Polygon, gml:MultiPoint, gml:MultiCurve, gml:MultiSurface
 : @param $geometry2 node of one of GMLSF objects: gml:Point, gml:LineString, gml:Curve,
 :    gml:LinearRing, gml:Surface, gml:Polygon, gml:MultiPoint, gml:MultiCurve, gml:MultiSurface
 : @return true if geometry1 covers geometry2.
 : @error XPTY0004 - unrecognized geometric object
:)
declare function zorba-geo:covers( $geometry1 as node(),  $geometry2 as node()) as xs:boolean external;

(:~
 : Checks if geometry1 does not touch or intersects geometry2.<br/>
 : It has to fulfill these conditions:<br/>
 :  - they have no point in common<br/>
 :  - the DE-9IM Intersection Matrix for the two geometries is
 :     FF*FF****.<br/>
 :  - geometry1 does not intersect geometry2<br/>
 :
 : @param $geometry1 node of one of GMLSF objects: gml:Point, gml:LineString, gml:Curve,
 :    gml:LinearRing, gml:Surface, gml:Polygon, gml:MultiPoint, gml:MultiCurve, gml:MultiSurface
 : @param $geometry2 node of one of GMLSF objects: gml:Point, gml:LineString, gml:Curve,
 :    gml:LinearRing, gml:Surface, gml:Polygon, gml:MultiPoint, gml:MultiCurve, gml:MultiSurface
 : @return true if geometry1 and geometry2 are disjoint.
 : @error XPTY0004 - unrecognized geometric object
:)
declare function zorba-geo:disjoint( $geometry1 as node(),  $geometry2 as node()) as xs:boolean external;

(:~
 : Checks if geometry1 intersects geometry2.<br/>
 : This is true if disjoint returns false.
 : <br/>
 :
 : @param $geometry1 node of one of GMLSF objects: gml:Point, gml:LineString, gml:Curve,
 :    gml:LinearRing, gml:Surface, gml:Polygon, gml:MultiPoint, gml:MultiCurve, gml:MultiSurface
 : @param $geometry2 node of one of GMLSF objects: gml:Point, gml:LineString, gml:Curve,
 :    gml:LinearRing, gml:Surface, gml:Polygon, gml:MultiPoint, gml:MultiCurve, gml:MultiSurface
 : @return true if geometry1 and geometry2 are disjoint.
 : @error XPTY0004 - unrecognized geometric object
:)
declare function zorba-geo:intersects( $geometry1 as node(),  $geometry2 as node()) as xs:boolean external;

(:~
 : Checks if geometry1 touches geometry2.<br/>
 : Returns true if the DE-9IM intersection matrix for the two
 : geometries is FT*******, F**T***** or F***T****.
 : <br/>
 :
 : @param $geometry1 node of one of GMLSF objects: gml:Point, gml:LineString, gml:Curve,
 :    gml:LinearRing, gml:Surface, gml:Polygon, gml:MultiPoint, gml:MultiCurve, gml:MultiSurface
 : @param $geometry2 node of one of GMLSF objects: gml:Point, gml:LineString, gml:Curve,
 :    gml:LinearRing, gml:Surface, gml:Polygon, gml:MultiPoint, gml:MultiCurve, gml:MultiSurface
 : @return true if geometry1 touches geometry2.
 : @error XPTY0004 - unrecognized geometric object
:)
declare function zorba-geo:touches( $geometry1 as node(),  $geometry2 as node()) as xs:boolean external;

(:~
 : Checks if geometry1 crosses geometry2.<br/>
 : That is if the geometries have some but not all interior points in common.
 : Returns true if the DE-9IM intersection matrix for the two
 : geometries is<br/>
 : T*T****** (for P/L, P/A, and L/A situations)<br/> 
 : T*****T** (for L/P, A/P, and A/L situations) <br/>
 : 0******** (for L/L situations).<br/>
 : <br/>
 : This applies for situations:  P/L, P/A, L/L, L/A, L/P, A/P and A/L.
 : For other situations it returns false.
 :
 : @param $geometry1 node of one of GMLSF objects: gml:Point, gml:LineString, gml:Curve,
 :    gml:LinearRing, gml:Surface, gml:Polygon, gml:MultiPoint, gml:MultiCurve, gml:MultiSurface
 : @param $geometry2 node of one of GMLSF objects: gml:Point, gml:LineString, gml:Curve,
 :    gml:LinearRing, gml:Surface, gml:Polygon, gml:MultiPoint, gml:MultiCurve, gml:MultiSurface
 : @return true if geometry1 crosses geometry2.
 : @error XPTY0004 - unrecognized geometric object
:)
declare function zorba-geo:crosses( $geometry1 as node(),  $geometry2 as node()) as xs:boolean external;

(:~
 : Checks if geometry1 is within geometry2.<br/>
 : Returns true if the DE-9IM intersection matrix for the two
 : geometries is T*F**F***.
 : <br/>
 :
 : @param $geometry1 node of one of GMLSF objects: gml:Point, gml:LineString, gml:Curve,
 :    gml:LinearRing, gml:Surface, gml:Polygon, gml:MultiPoint, gml:MultiCurve, gml:MultiSurface
 : @param $geometry2 node of one of GMLSF objects: gml:Point, gml:LineString, gml:Curve,
 :    gml:LinearRing, gml:Surface, gml:Polygon, gml:MultiPoint, gml:MultiCurve, gml:MultiSurface
 : @return true if geometry1 is within geometry2.
 : @error XPTY0004 - unrecognized geometric object
:)
declare function zorba-geo:within( $geometry1 as node(),  $geometry2 as node()) as xs:boolean external;

(:~
 : Checks if geometry1 contains geometry2.<br/>
 : Returns true if within(geometry2, geometry1) is true.
 : <br/>
 :
 : @param $geometry1 node of one of GMLSF objects: gml:Point, gml:LineString, gml:Curve,
 :    gml:LinearRing, gml:Surface, gml:Polygon, gml:MultiPoint, gml:MultiCurve, gml:MultiSurface
 : @param $geometry2 node of one of GMLSF objects: gml:Point, gml:LineString, gml:Curve,
 :    gml:LinearRing, gml:Surface, gml:Polygon, gml:MultiPoint, gml:MultiCurve, gml:MultiSurface
 : @return true if geometry1 contains geometry2.
 : @error XPTY0004 - unrecognized geometric object
:)
declare function zorba-geo:contains( $geometry1 as node(),  $geometry2 as node()) as xs:boolean external;

(:~
 : Checks if geometry1 overlaps with geometry2.<br/>
 : Returns true if DE-9IM intersection matrix for the two
 : geometries is T*T***T** (for two points or two surfaces)
 :	 or * 1*T***T** (for two curves).
 : <br/>
 :
 : @param $geometry1 node of one of GMLSF objects: gml:Point, gml:LineString, gml:Curve,
 :    gml:LinearRing, gml:Surface, gml:Polygon, gml:MultiPoint, gml:MultiCurve, gml:MultiSurface
 : @param $geometry2 node of one of GMLSF objects: gml:Point, gml:LineString, gml:Curve,
 :    gml:LinearRing, gml:Surface, gml:Polygon, gml:MultiPoint, gml:MultiCurve, gml:MultiSurface
 : @return true if geometry1 overlaps geometry2.
 : @error XPTY0004 - unrecognized geometric object
:)
declare function zorba-geo:overlaps( $geometry1 as node(),  $geometry2 as node()) as xs:boolean external;

(:~
 : Checks if geometry1 relates with geometry2 relative to a DE-9IM matrix.<br/>
 : The DE-9IM matrix is defined like this:
 : <table>
 :	<tr>
 :		 <td></td>
 :		 <td><b>Interior</b></td>
 :		 <td><b>Boundary</b></td>
 :		 <td><b>Exterior</b></td>
 :		</tr>
 :		<tr>
 :		 <td><b>Interior</b></td>
 :		 <td>dim(intersection of interior1 and interior2)</td>
 :		 <td>dim(intersection of interior1 and boundary2)</td>
 :		 <td>dim(intersection of interior1 and exterior2)</td>
 :		</tr>
 :		<tr>
 :		 <td><b>Boundary</b></td>
 :		 <td>dim(intersection of boundary1 and interior2)</td>
 :		 <td>dim(intersection of boundary1 and boundary2)</td>
 :		 <td>dim(intersection of boundary1 and exterior2)</td>
 :		</tr>
 :		<tr>
 :		 <td><b>Exterior</b></td>
 :		 <td>dim(intersection of exterior1 and interior2)</td>
 :		 <td>dim(intersection of exterior1 and boundary2)</td>
 :		 <td>dim(intersection of exterior1 and exterior2)</td>
 :		</tr>
 :	</table>
 :	<br/>
 :	The values in the DE-9IM can be T, F, *, 0, 1, 2 .<br/>
 :  - T means the intersection gives a non-empty result.<br/>
 :  - F means the intersection gives an empty result.<br/>
 :  - * means any result.<br/>
 :  - 0, 1, 2 gives the expected dimension of the result (point, curve, surface)<br/>
 : <br/><br/>
 : For example, the matrix of "T*T***T**" checks for intersections of interior1 with interior2,
 : interior1 with exterior2 and exterior1 with interior2.
 :
 : @param $geometry1 node of one of GMLSF objects: gml:Point, gml:LineString,
 :    gml:LinearRing, gml:Polygon
 : @param $geometry2 node of one of GMLSF objects: gml:Point, gml:LineString,
 :    gml:LinearRing, gml:Polygon
 : @param $intersection_matrix the DE-9IM matrix, with nine chars, three chars for each line in DE-9IM matrix.
 : @return true if geometry1 overlaps geometry2.
 : @error XPTY0004 - unrecognized geometric object
 : @error XPTY0004 - if any geometry is a collection
:)
declare function zorba-geo:relate( $geometry1 as node(),  $geometry2 as node(), $intersection_matrix as xs:string) as xs:boolean external;


(:~
 : Compute the shortest distance between any two Points in geometry1 and geometry2.<br/>
 : <br/>
 :
 : @param $geometry1 node of one of GMLSF objects: gml:Point, gml:LineString, gml:Curve,
 :    gml:LinearRing, gml:Surface, gml:Polygon, gml:MultiPoint, gml:MultiCurve, gml:MultiSurface
 : @param $geometry2 node of one of GMLSF objects: gml:Point, gml:LineString, gml:Curve,
 :    gml:LinearRing, gml:Surface, gml:Polygon, gml:MultiPoint, gml:MultiCurve, gml:MultiSurface
 : @return minimum distance as xs:double.
 : @error XPTY0004 - unrecognized geometric object
:)
declare function zorba-geo:distance( $geometry1 as node(),  $geometry2 as node()) as xs:double external;

(:~
 : Returns a polygon that represents all Points whose distance
 :   from this geometric object is less than or equal to distance.<br/>
 : <br/>
 :
 : @param $geometry node of one of GMLSF objects: gml:Point, gml:LineString, gml:Curve,
 :    gml:LinearRing, gml:Surface, gml:Polygon, gml:MultiPoint, gml:MultiCurve, gml:MultiSurface
 : @param $distance the distance from geometry, expressed in units of the current coordinate system
 : @return new geometry node.
 : @error XPTY0004 - unrecognized geometric object
:)
declare function zorba-geo:buffer( $geometry as node(),  $distance as xs:double) as node() external;

(:~
 : Returns the smallest convex Polygon that contains all the points in the Geometry.<br/>
 : Actually returns the object of smallest dimension possible (possible Point or LineString).<br/>
 : <br/>
 :
 : @param $geometry node of one of GMLSF objects: gml:Point, gml:LineString, gml:Curve,
 :    gml:LinearRing, gml:Surface, gml:Polygon, gml:MultiPoint, gml:MultiCurve, gml:MultiSurface
 : @return the convex polygon node.
 : @error XPTY0004 - unrecognized geometric object
:)
declare function zorba-geo:convex-hull( $geometry as node()) as node() external;

(:~
 : Returns a geometric object that represents the Point set intersection of
 :    geometry1 and geometry2.<br/>
 : For intersection of two polygons interiors, returns a polygon.
 : <br/>
 :
 : @param $geometry1 node of one of GMLSF objects: gml:Point, gml:LineString, gml:Curve,
 :    gml:LinearRing, gml:Surface, gml:Polygon, gml:MultiPoint, gml:MultiCurve, gml:MultiSurface
 : @param $geometry2 node of one of GMLSF objects: gml:Point, gml:LineString, gml:Curve,
 :    gml:LinearRing, gml:Surface, gml:Polygon, gml:MultiPoint, gml:MultiCurve, gml:MultiSurface
 : @return point set geometry node.
 : @error XPTY0004 - unrecognized geometric object
:)
declare function zorba-geo:intersection( $geometry1 as node(),  $geometry2 as node()) as node() external;

(:~
 : Returns a geometric object that represents the Point set union of
 :    geometry1 and geometry2.<br/>
 : <br/>
 :
 : @param $geometry1 node of one of GMLSF objects: gml:Point, gml:LineString, gml:Curve,
 :    gml:LinearRing, gml:Surface, gml:Polygon, gml:MultiPoint, gml:MultiCurve, gml:MultiSurface
 : @param $geometry2 node of one of GMLSF objects: gml:Point, gml:LineString, gml:Curve,
 :    gml:LinearRing, gml:Surface, gml:Polygon, gml:MultiPoint, gml:MultiCurve, gml:MultiSurface
 : @return point set geometry node.
 : @error XPTY0004 - unrecognized geometric object
:)
declare function zorba-geo:union( $geometry1 as node(),  $geometry2 as node()) as node() external;

(:~
 : Returns a geometric object that represents the Point set difference of
 :    geometry1 and geometry2. Points that are in geometry1 and are not in geometry2.<br/>
 : <br/>
 :
 : @param $geometry1 node of one of GMLSF objects: gml:Point, gml:LineString, gml:Curve,
 :    gml:LinearRing, gml:Surface, gml:Polygon, gml:MultiPoint, gml:MultiCurve, gml:MultiSurface
 : @param $geometry2 node of one of GMLSF objects: gml:Point, gml:LineString, gml:Curve,
 :    gml:LinearRing, gml:Surface, gml:Polygon, gml:MultiPoint, gml:MultiCurve, gml:MultiSurface
 : @return point set geometry node.
 : @error XPTY0004 - unrecognized geometric object
:)
declare function zorba-geo:difference( $geometry1 as node(),  $geometry2 as node()) as node() external;

(:~
 : Returns a geometric object that represents the Point set symmetric difference of
 :    geometry1 and geometry2. Points that are in geometry1 and are not in geometry2
 :    and points that are in geometry2 and are not in geometry1.<br/>
 : <br/>
 :
 : @param $geometry1 node of one of GMLSF objects: gml:Point, gml:LineString, gml:Curve,
 :    gml:LinearRing, gml:Surface, gml:Polygon, gml:MultiPoint, gml:MultiCurve, gml:MultiSurface
 : @param $geometry2 node of one of GMLSF objects: gml:Point, gml:LineString, gml:Curve,
 :    gml:LinearRing, gml:Surface, gml:Polygon, gml:MultiPoint, gml:MultiCurve, gml:MultiSurface
 : @return point set geometry node.
 : @error XPTY0004 - unrecognized geometric object
:)
declare function zorba-geo:sym-difference( $geometry1 as node(),  $geometry2 as node()) as node() external;


(:~
 : Returns the area of this geometry.<br/>
 : Returns zero for Point and Lines.<br/>
 : <br/>
 :
 : @param $geometry node of one of GMLSF objects: gml:Point, gml:LineString, gml:Curve,
 :    gml:LinearRing, gml:Surface, gml:Polygon, gml:MultiPoint, gml:MultiCurve, gml:MultiSurface
 : @return geometry area as xs:double.
 : @error XPTY0004 - unrecognized geometric object
:)
declare function zorba-geo:area( $geometry as node()) as xs:double external;

(:~
 : Returns the length of this geometry.<br/>
 : Returns zero for Points.<br/>
 : <br/>
 :
 : @param $geometry node of one of GMLSF objects: gml:Point, gml:LineString, gml:Curve,
 :    gml:LinearRing, gml:Surface, gml:Polygon, gml:MultiPoint, gml:MultiCurve, gml:MultiSurface
 : @return geometry length as xs:double.
 : @error XPTY0004 - unrecognized geometric object
:)
declare function zorba-geo:length( $geometry as node()) as xs:double external;

(:~
 : Checks if geometry2 is within a certain distance of geometry1.<br/>
 : <br/>
 :
 : @param $geometry1 node of one of GMLSF objects: gml:Point, gml:LineString, gml:Curve,
 :    gml:LinearRing, gml:Surface, gml:Polygon, gml:MultiPoint, gml:MultiCurve, gml:MultiSurface
 : @param $geometry2 node of one of GMLSF objects: gml:Point, gml:LineString, gml:Curve,
 :    gml:LinearRing, gml:Surface, gml:Polygon, gml:MultiPoint, gml:MultiCurve, gml:MultiSurface
 : @param $distance the distance from geometry1, expressed in units of the current coordinate system
 : @return true if distance from geometry1 to geometry2 is less than $distance.
 : @error XPTY0004 - unrecognized geometric object
:)
declare function zorba-geo:is-within-distance( $geometry1 as node(),  $geometry2 as node(), $distance as xs:double) as xs:boolean external;

(:~
 : Returns a Point that is the mathematical centroid of this geometry.
 : The result is not guaranteed to be on the surface. <br/>
 : <br/>
 :
 : @param $geometry node of one of GMLSF objects: gml:Point, gml:LineString, gml:Curve,
 :    gml:LinearRing, gml:Surface, gml:Polygon, gml:MultiPoint, gml:MultiCurve, gml:MultiSurface
 : @return centroid Point.
 : @error XPTY0004 - unrecognized geometric object
:)
declare function zorba-geo:centroid( $geometry as node()) as node() external;

(:~
 : Returns a Point that is interior of this geometry.
 : If it cannot be inside the geometry, then it will be on the boundary. <br/>
 : <br/>
 :
 : @param $geometry node of one of GMLSF objects: gml:Point, gml:LineString, gml:Curve,
 :    gml:LinearRing, gml:Surface, gml:Polygon, gml:MultiPoint, gml:MultiCurve, gml:MultiSurface
 : @return a Point inside the geometry.
 : @error XPTY0004 - unrecognized geometric object
:)
declare function zorba-geo:interior-point( $geometry as node()) as node() external;






(:~
 : Returns the X coordinate of a Point.
 : <br/>
 :
 : @param $point node of one of GMLSF objects: gml:Point
 : @return the X coordinate
 : @error XPTY0004 - unrecognized geometric object or not a gml:Point
:)
declare function zorba-geo:x( $point as node()) as xs:double external;

(:~
 : Returns the Y coordinate of a Point.
 : <br/>
 :
 : @param $point node of one of GMLSF objects: gml:Point
 : @return the Y coordinate
 : @error XPTY0004 - unrecognized geometric object or not a gml:Point
:)
declare function zorba-geo:y( $point as node()) as xs:double external;

(:~
 : Returns the Z coordinate of a Point, if is 3D.
 : <br/>
 :
 : @param $point node of one of GMLSF objects: gml:Point
 : @return the Z coordinate
 : @error XPTY0004 - unrecognized geometric object or not a gml:Point
:)
declare function zorba-geo:z( $point as node()) as xs:double external;







(:~
 : Returns the start Point of a line.
 : <br/>
 :
 : @param $line node of one of GMLSF objects: gml:LineString, gml:LinearRing
 : @return the starting gml:Point
 : @error XPTY0004 - unrecognized geometric object or not a line
:)
declare function zorba-geo:start-point( $line as node()) as node() external;

(:~
 : Returns the end Point of a line.
 : <br/>
 :
 : @param $line node of one of GMLSF objects: gml:LineString, gml:LinearRing
 : @return the end gml:Point
 : @error XPTY0004 - unrecognized geometric object or not a line
:)
declare function zorba-geo:end-point( $line as node()) as node() external;

(:~
 : Checks if the line is closed loop. That is, if the start Point is same with end Point.
 : <br/>
 :
 : @param $line node of one of GMLSF objects: gml:LineString, gml:LinearRing,
 :      gml:MultiCurve
 : @return true if the line is closed.
 : @error XPTY0004 - unrecognized geometric object or not a line
:)
declare function zorba-geo:is-closed( $line as node()) as xs:boolean external;

(:~
 : Checks if the line is a ring. That is, if the line is closed and simple.
 : <br/>
 :
 : @param $line node of one of GMLSF objects: gml:LineString, gml:LinearRing
 : @return true if the line is a closed ring.
 : @error XPTY0004 - unrecognized geometric object or not a line
:)
declare function zorba-geo:is-ring( $line as node()) as xs:boolean external;

(:~
 : Return the number of Points in a line.
 : <br/>
 :
 : @param $line node of one of GMLSF objects: gml:LineString, gml:LinearRing
 : @return number of points in the line
 : @error XPTY0004 - unrecognized geometric object or not a line
:)
declare function zorba-geo:num-points( $line as node()) as xs:unsignedInt external;

(:~
 : Return the n-th Point in a line
 : <br/>
 :
 : @param $line node of one of GMLSF objects: gml:LineString, gml:LinearRing
 : @param $n index in the list of nodes, zero based.
 : @return n-th point in the line. The node is a copy of the original node.
 : @error XPTY0004 - unrecognized geometric object or not a line
:)
declare function zorba-geo:point-n( $line as node(), $n as xs:unsignedInt) as node() external;






(:~
 : Return the exterior ring of a Polygon.
 : <br/>
 :
 : @param $polygon node of one of GMLSF objects: gml:Polygon
 : @return exterior ring as a gml:LinearRing
 : @error XPTY0004 - unrecognized geometric object or not a polygon
:)
declare function zorba-geo:exterior-ring( $polygon as node()) as node() external;

(:~
 : Return the number of interior rings of a Polygon.
 : <br/>
 :
 : @param $polygon node of one of GMLSF objects: gml:Polygon
 : @return the number of interior rings
 : @error XPTY0004 - unrecognized geometric object or not a polygon
:)
declare function zorba-geo:num-interior-ring( $polygon as node()) as xs:unsignedInt external;

(:~
 : Return the n-th interior ring of a Polygon.
 : <br/>
 :
 : @param $polygon node of one of GMLSF objects: gml:Polygon
 : @param $n index in the list of interior rings, zero based.
 : @return n-th interior ring. The node is a copy of the original node.
 : @error XPTY0004 - unrecognized geometric object or not a line
:)
declare function zorba-geo:interior-ring-n( $polygon as node(), $n as xs:unsignedInt) as node() external;




