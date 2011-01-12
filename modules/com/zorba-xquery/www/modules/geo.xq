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
 : It uses the GEOS external library, license LGPL. Version 3.2.2 or above is required.<br/>
 : <br/>
 : The data format supported is GML SF profile 0/1.<br/>
 : This is a subset of GML, and covers the basic geometries of Point, Line and Surface and collections of those.<br/>
 : GMLSF nodes have the namespace "http://www.opengis.net/gml".<br/>
 : <br/>
 : Possible GMLSF geometric structures are:
 : <dl>
 :  <dt><b>Point</b></dt>
 :  <dd>&lt;gml:Point [srsDimension='2|3']?&gt;<br/>
 :    &#160;&#160;&lt;gml:pos [srsDimension='2|3']?&gt;double_x double_y &lt;/gml:pos&gt;<br/>
 :  &lt;/gml:Point&gt;</dd>
 :  <dt><b>LineString</b></dt>
 :  <dd>&lt;gml:LineString [srsDimension='2|3']?&gt;<br/>
 :    &#160;&#160;&lt;gml:posList [srsDimension='2|3']?&gt; double_x1 double_y1 double_x2 double_y2 ... &lt;/gml:posList&gt;<br/>
 :    &lt;/gml:LineString&gt;</dd>
 :  <dt><b>Curve</b></dt>
 :  <dd>&lt;gml:Curve [srsDimension='2|3']?&gt;<br/>
 :    &lt;gml:segments&gt; <br/>
 :    [&lt;gml:LineStringSegment interpolation="linear" [srsDimension='2|3']?&gt;<br/>
 :     &#160;&#160;&lt;gml:posList [srsDimension='2|3']?&gt; double_x1 double_y1 double_x2 double_y2 ... &lt;/gml:posList&gt;<br/>
 :     &lt;gml:LineStringSegment&gt;]*<br/>
 :    &lt;/gml:segments&gt;<br/>
 :    &lt;/gml:Curve&gt;
 :   </dd>
 :  <dt><b>LinearRing</b></dt>
 :  <dd>&lt;gml:LinearRing [srsDimension='2|3']?&gt;<br/>
 :   &#160;&#160;&lt;gml:posList [srsDimension='2|3']?&gt; double_x1 double_y1 double_x2 double_y2 ... &lt;/gml:posList&gt;<br/>
 :   &lt;/gml:LinearRing&gt;</dd>
 :  <dt><b>Surface</b></dt>
 :  <dd>&lt;gml:Surface [srsDimension='2|3']?&gt;<br/>
 :    &lt;gml:patches&gt; <br/>
 :    [&lt;gml:PolygonPatch [srsDimension='2|3']?&gt;<br/>
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
 :  <dd>&lt;gml:Polygon [srsDimension='2|3']?&gt;<br/>
 :     &#160;&#160;&lt;gml:exterior&gt;<br/>
 :     &#160;&#160;&#160;&#160;&lt;gml:LinearRing&gt; ... &lt;/gml:LinearRing&gt;<br/>
 :     &#160;&#160;&lt;/gml:exterior&gt;<br/>
 :     &#160;&#160;[&lt;gml:interior&gt;<br/>
 :     &#160;&#160;&#160;&#160;&lt;gml:LinearRing&gt; ... &lt;/gml:LinearRing&gt;<br/>
 :     &#160;&#160;&lt;/gml:interior&gt;]*<br/>
 :    &lt;/gml:Polygon&gt;
 :  </dd>
 :  <dt><b>MultiPoint</b></dt>
 :  <dd>&lt;gml:MultiPoint [srsDimension='2|3']?&gt;<br/>
 :     &#160;&#160;[&lt;gml:Point&gt; ... &lt;/gml:Point&gt;]*<br/>
 :    &lt;/gml:MultiPoint&gt;
 :  </dd>
 :  <dt><b>MultiCurve</b></dt>
 :  <dd>&lt;gml:MultiCurve [srsDimension='2|3']?&gt;<br/>
 :     &#160;&#160;[&lt;gml:LineString&gt; ... &lt;/gml:LineString&gt;]*<br/>
 :    &lt;/gml:MultiCurve&gt;
 :  </dd>
 :  <dt><b>MultiSurface</b></dt>
 :  <dd>&lt;gml:MultiSurface [srsDimension='2|3']?&gt;<br/>
 :     &#160;&#160;[&lt;gml:Polygon&gt; ... &lt;/gml:Polygon&gt;]*<br/>
 :    &lt;/gml:MultiSurface&gt;
 :  </dd>
 :  <dt><b>MultiGeometry (this is from GML 3 schema)</b></dt>
 :  <dd>&lt;gml:MultiGeometry [srsDimension='2|3']?&gt;<br/>
 :     &#160;&#160;[&lt;gml:geometryMember&gt;<br/>
 :          &#160;&#160;&#160;&#160; ...one geometry...<br/>
 :     &#160;&#160;&lt;/gml:geometryMember&gt;]*<br/>
 :     &#160;&#160;[&lt;gml:geometryMembers&gt;<br/>
 :          &#160;&#160;&#160;&#160; ...a list of geometries...<br/>
 :     &#160;&#160;&lt;/gml:geometryMembers&gt;]?<br/>
 :    &lt;/gml:MultiGeometry&gt;
 :  </dd>
 : </dl><br/><br/>
 : Note: When using gml:posList, it is possible to replace this element with a list of gml:pos.<br/>
 : Note: XLink referencing is not supported.<br/>
 : Note: The <i>srsDimension</i> optional attribute specifies the coordinate dimension. The default value is 2 (for 2D).
 :    Another possible value is 3 (for 3D) in which case every point has to have three double values (x, y, z).
 :    This is an extension borrowed from GML 3 spec. <br/>
 : The operations made on 3D objects work only on x-y coordinates, the z coordinate is not taken into account.
 : When returning the result, the original z-coordinates of the points are preserved.
 : For computed points, the z-coordinate is interpolated.<br/>
 : <br/>
 : The coordinates values have to be in cartesian coordinates, not in polar coordinates. <br/>
 : Converting between coordinate systems and doing projections from polar to cartesian is outside the scope of this geo module. <br/>
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
 : @author Daniel Turcanu
 :
 : @see http://www.opengeospatial.org/standards/sfa
 : @see http://www.opengeospatial.org/standards/gml
 : @see http://trac.osgeo.org/geos/
 : @library <a href="http://trac.osgeo.org/geos/">GEOS (Geometry Engine - Open Source)</a>
 :)
module namespace zorba-geo = "http://www.zorba-xquery.com/modules/geo";

(:~
 : Declare the namespace for the gml geometry objects.
:)
declare namespace gml="http://www.opengis.net/gml";

(:~
 : Return the dimension of the geo object. 
 : 
 : @param $geometry node of one of GMLSF objects: gml:Point, gml:LineString, gml:Curve, gml:LinearRing, 
 :    gml:Surface, gml:Polygon, gml:MultiPoint, gml:MultiCurve, gml:MultiSurface, gml:MultiGeometry
 : @return 0 for point, 1 for line, 2 for surface.
 : @error XPTY0004 - unrecognized geometric object
 : @example dimension1.xq
 : @example dimension2.xq
 : @example dimension3.xq
 : @example dimension4.xq
 : @example dimension5.xq
 : @example dimension6.xq
 : @example dimension7.xq
 : @example dimension8.xq
 : @example dimension9.xq
 : @example dimension10.xq
:)
declare function zorba-geo:dimension( $geometry as element()) as xs:integer external;

(:~
 : Return the coordinate dimension of the geo object, as specified in the srsDimension attribute.<br/>
 : Only two-dimensional and three-dimensional coordinates are supported.
 : 
 : @param $geometry node of one of GMLSF objects: gml:Point, gml:LineString, gml:Curve, gml:LinearRing, 
 :    gml:Surface, gml:Polygon, gml:MultiPoint, gml:MultiCurve, gml:MultiSurface, gml:MultiGeometry
 : @return 2 for 2D, 3 for 3D.
 : @error XPTY0004 - unrecognized geometric object
 : @example coordinate_dimension1.xq
 : @example coordinate_dimension2.xq
 : @example coordinate_dimension3.xq
 : @example coordinate_dimension4.xq
 : @example coordinate_dimension5.xq
 : @example coordinate_dimension6.xq
:)
declare function zorba-geo:coordinate-dimension( $geometry as element()) as xs:integer external;

(:~
 : Return the qname type of geo object. <br/>
 : Returns empty sequence if the geometry is not recognized. <br/>
 : 
 : @param $geometry node of one of GMLSF objects: gml:Point, gml:LineString, gml:Curve, 
 :    gml:Surface, gml:Polygon, gml:MultiPoint, gml:MultiCurve, gml:MultiSurface, gml:MultiGeometry
 : @return "gml:Point" for Point, "gml:LineString" for LineString, "gml:Curve" for Curve, "gml:LineString" for LinearRing,
 :     "gml:Surface" for Surface, "gml:Polygon" for Polygon and PolygonPatch, 
 :     "gml:MultiPoint" for MultiPoint, "gml:MultiCurve" for MultiCurve,
 :     "gml:MultiSurface" for MultiSurface, "gml:MultiGeometry" for MultiGeometry
 : @error XPTY0004 - unrecognized geometric object
 : @example geometry_type1.xq
 : @example geometry_type2.xq
 : @example geometry_type3.xq
 : @example geometry_type4.xq
 : @example geometry_type5.xq
 : @example geometry_type6.xq
 : @example geometry_type7.xq
 : @example geometry_type8.xq
 : @example geometry_type9.xq
 : @example geometry_type10.xq
 : @example geometry_type11.xq
:)
declare function zorba-geo:geometry-type( $geometry as element()) as xs:QName? external;

(:~
 : Return the srid URI of geo object. 
 : SRID is contained in the srsName attribute in the geo element, or one of the parents,
 : or in the boundedBy/Envelope element in one of the parents.<br/>
 : This function searches recursively from this element up to the top-most parent.<br/>
 : 
 : @param $geometry node of one of GMLSF objects: gml:Point, gml:LineString, gml:Curve, 
 :    gml:Surface, gml:Polygon, gml:MultiPoint, gml:MultiCurve, gml:MultiSurface, gml:MultiGeometry
 : @return the SRID if it is found
 : @error XPTY0004 - unrecognized geometric object
 : @example srid1.xq
 : @example srid2.xq
 : @example srid3.xq
 : @example srid4.xq
 : @example srid5.xq
:)
declare function zorba-geo:srid( $geometry as element()) as xs:anyURI? external;

(:~
 : Return the number of geometries in the collection, or 1 for non-collection. 
 : For gml:Point, gml:LineString, gml:LinearRing, gml:Polygon, return 1.
 : For gml:Curve and gml:Surface, they are treated as geometric collections.
 : 
 : @param $geometry node of one of GMLSF objects: gml:Point, gml:LineString, gml:Curve, gml:LinearRing, 
 :    gml:Surface, gml:Polygon, gml:MultiPoint, gml:MultiCurve, gml:MultiSurface, gml:MultiGeometry
 : @return number of geometries in collection
 : @error XPTY0004 - unrecognized geometric object
 : @example num-geometries1.xq
 : @example num-geometries2.xq
 : @example num-geometries3.xq
:)
declare function zorba-geo:num-geometries( $geometry as element()) as xs:unsignedInt external;

(:~
 : Return the n-th geometry in the collection. 
 : Return this geometry if it is not a collection.
 : For gml:Point, gml:LineString, gml:LinearRing, gml:Polygon, return this item if n is zero, otherwise error.
 : For gml:Curve and gml:Surface, they are treated as geometric collections.
 : 
 : @param $geometry node of one of GMLSF objects: gml:Point, gml:LineString, gml:Curve, gml:LinearRing, 
 :    gml:Surface, gml:Polygon, gml:MultiPoint, gml:MultiCurve, gml:MultiSurface, gml:MultiGeometry
 : @param $n zero-based index in the collection
 : @return n-th geometry in collection. The node is the original node, not a copy.
 : @error XPTY0004 - unrecognized geometric object
 : @example geometry-n1.xq
 : @example geometry-n2.xq
 : @example geometry-n3.xq
 : @example geometry-n4.xq
:)
declare function zorba-geo:geometry-n( $geometry as element(), $n as xs:unsignedInt) as element() external;

(:~
 : The envelope is the minimum bounding box of this geometry.
 : 
 : @param $geometry node of one of GMLSF objects: gml:Point, gml:LineString, gml:Curve, gml:LinearRing, 
 :    gml:Surface, gml:Polygon, gml:MultiPoint, gml:MultiCurve, gml:MultiSurface, gml:MultiGeometry
 : @return An gml:Envelope element with content <br/>
 :         &lt;gml:Envelope><br/>
 :         &lt;gml:lowerCorner><i>minx miny</i>&lt;/gml:lowerCorner><br/>
 :         &lt;gml:upperCorner><i>maxx maxy</i>&lt;/gml:upperCorner><br/>
 :         &lt;/gml:Envelope>
 : @error XPTY0004 - unrecognized geometric object
 : @example envelope1.xq
 : @example envelope2.xq
 : @example envelope3.xq
 : @example envelope4.xq
 : @example envelope5.xq
 : @example envelope6.xq
 : @example envelope7.xq
 : @example envelope8.xq
 : @example envelope9.xq
 : @example envelope10.xq
 : @example envelope11.xq
 : @example envelope12.xq
:)
declare function zorba-geo:envelope( $geometry as element()) as element(gml:Envelope) external;

(:~
 : Return the Well-known Text Representation of Geometry. <br/>
 : This is defined in the Simple Features spec from OGC.<br/>
 : gml:Curve is represented as MultiLineString.<br/>
 : gml:Surface is represented as MultiPolygon.<br/>
 : 
 : @param $geometry node of one of GMLSF objects: gml:Point, gml:LineString, gml:Curve, gml:LinearRing, 
 :    gml:Surface, gml:Polygon, gml:MultiPoint, gml:MultiCurve, gml:MultiSurface, gml:MultiGeometry
 : @return the Well-known Text Representation for the geo object.
 : @error XPTY0004 - unrecognized geometric object
 : @example as_text1.xq
 : @example as_text2.xq
 : @example as_text3.xq
 : @example as_text4.xq
 : @example as_text5.xq
 : @example as_text6.xq
 : @example as_text7.xq
 : @example as_text8.xq
 : @example as_text9.xq
:)
declare function zorba-geo:as-text( $geometry as element()) as xs:string external;

(:~
 : Return the Well-known Binary Representation of Geometry. <br/>
 : This is defined in the Simple Features spec from OGC.<br/>
 : gml:Curve is represented as MultiLineString.<br/>
 : gml:Surface is represented as MultiPolygon.<br/>
 : 
 : @param $geometry node of one of GMLSF objects: gml:Point, gml:LineString, gml:Curve, gml:LinearRing, 
 :    gml:Surface, gml:Polygon, gml:MultiPoint, gml:MultiCurve, gml:MultiSurface, gml:MultiGeometry
 : @return the Well-known Binary Representation for the geo object as base64.
 : @error XPTY0004 - unrecognized geometric object
 : @example as_binary1.xq
:)
declare function zorba-geo:as-binary( $geometry as element()) as xs:base64Binary external;

(:~
 : Checks if the argument is empty or not and if it is a valid geometry or not. <br/>
 : A geometry is considered empty if it has no points.<br/>
 : 
 : @param $geometry node of one of GMLSF objects: gml:Point, gml:LineString, gml:Curve, gml:LinearRing, 
 :    gml:Surface, gml:Polygon, gml:MultiPoint, gml:MultiCurve, gml:MultiSurface, gml:MultiGeometry
 : @return true if $geometry is not a valid gmlsf object or if is empty.
 : @example is_empty1.xq
 : @example is_empty2.xq
 : @example is_empty3.xq
 : @example is_empty4.xq
 : @example is_empty5.xq
:)
declare function zorba-geo:is-empty( $geometry as element()?) as xs:boolean external;

(:~
 : Checks if this geometric object has no anomalous geometric points, such
 :	as self intersection or self tangency. <br/>
 : Does not work for gml:Surface and gml:MultiGeometry.
 : 
 : @param $geometry node of one of GMLSF objects: gml:Point, gml:LineString,
 :    gml:LinearRing, gml:Curve, gml:Polygon, gml:MultiPoint, gml:MultiCurve, gml:MultiSurface
 : @return true if $geometry is simple.
 : @error XPTY0004 - unrecognized geometric object
 : @example is_simple1.xq
 : @example is_simple2.xq
 : @example is_simple3.xq
 : @example is_simple4.xq
 : @example is_simple5.xq
 : @example is_simple6.xq
 : @example is_simple7.xq
 : @example is_simple8.xq
 : @example is_simple9.xq
 : @example is_simple10.xq
 : @example is_simple11.xq
 : @example is_simple12.xq
 : @example is_simple13.xq
 : @example is_simple14.xq
:)
declare function zorba-geo:is-simple( $geometry as element()) as xs:boolean external;

(:~
 : Checks if this geometric object is 2D or 3D, as specified in srsDimension optional attribute.<br/>
 : 
 : 
 : @param $geometry node of one of GMLSF objects: gml:Point, gml:LineString, gml:Curve, gml:LinearRing, 
 :    gml:Surface, gml:Polygon, gml:MultiPoint, gml:MultiCurve, gml:MultiSurface, gml:MultiGeometry
 : @return true if $geometry is 3D. 
 : @error XPTY0004 - unrecognized geometric object
 : @example is_3D1.xq
 : @example is_3D2.xq
:)
declare function zorba-geo:is-3d( $geometry as element()) as xs:boolean external;

(:~
 : Checks if this geometric object has measurements.<br/>
 : Measurements is not supported in this geo module, so the function returns false.
 : 
 : 
 : @param $geometry node of one of GMLSF objects: gml:Point, gml:LineString, gml:Curve, gml:LinearRing, 
 :    gml:Surface, gml:Polygon, gml:MultiPoint, gml:MultiCurve, gml:MultiSurface, gml:MultiGeometry
 : @return false. 
 : @error XPTY0004 - unrecognized geometric object
 : @example is_measured1.xq
:)
declare function zorba-geo:is-measured( $geometry as element()) as xs:boolean external;

(:~
 : A boundary is a set that represents the limit of an geometry.<br/>
 : For a Point or MultiPoint, the boundary is the empty geometry, nothing is returned.<br/>
 : For a LineString, the boundary is the MultiPoint set of start point and end point.<br/>
 : For a LinearRing, the boundary is empty MultiPoint.<br/>
 : For a Curve, it is treated as a MultiCurve.<br/>
 : For a Polygon, the boundary is the MultiCurve set of exterior and interior rings.<br/>
 : For a Surface, the boundary is the MultiCurve set formed from the exterior ring of all patches
 :  seen as a single surface and all the interior rings from all patches.<br/>
 : For MultiCurve, the boundary is the MultiPoint set of all start and end points that appear
 :  in an odd number of linestrings.<br/>
 : For MultiGeometry, a sequence of boundaries is returned, corresponding to each child geometry.<br/>
 : <br/>
 : 
 : @param $geometry node of one of GMLSF objects: gml:Point, gml:LineString, gml:LinearRing,
 :    gml:Curve, gml:Polygon, gml:Surface, gml:MultiPoint, gml:MultiCurve, gml:MultiSurface, gml:MultiGeometry
 : @return the boundary of a Geometry as a set of Geometries of the next lower dimension.
 : @error XPTY0004 - unrecognized geometric object
 : @example boundary1.xq
 : @example boundary2.xq
 : @example boundary3.xq
 : @example boundary4.xq
 : @example boundary5.xq
 : @example boundary6.xq
 : @example boundary7.xq
 : @example boundary8.xq
 : @example boundary9.xq
 : @example boundary10.xq
 : @example boundary11.xq
 : @example boundary12.xq
 : @example boundary13.xq
 : @example boundary14.xq
:)
declare function zorba-geo:boundary( $geometry as element()) as element()* external;





(:~
 : Checks if the two geometries are equal.<br/>
 :<br/>
 : Note: Does not work for gml:Surface and gml:MultiSurface if they have multiple Polygons.<br/>
 : 
 : @param $geometry1 node of one of GMLSF objects: gml:Point, gml:LineString, gml:Curve, gml:LinearRing, 
 :    gml:Surface, gml:Polygon, gml:MultiPoint, gml:MultiCurve, gml:MultiSurface, gml:MultiGeometry
 : @param $geometry2 node of one of GMLSF objects: gml:Point, gml:LineString, gml:Curve, gml:LinearRing, 
 :    gml:Surface, gml:Polygon, gml:MultiPoint, gml:MultiCurve, gml:MultiSurface, gml:MultiGeometry
 : @return true if the DE-9IM intersection matrix for the two Geometrys is T*F**FFF*.
 : @error XPTY0004 - unrecognized geometric object
 : @example equals1.xq
 : @example equals2.xq
 : @example equals3.xq
 : @example equals4.xq
 : @example equals5.xq
 : @example equals6.xq
 : @example equals7.xq
 : @example equals8.xq
 : @example equals9.xq
:)
declare function zorba-geo:equals( $geometry1 as element(),  $geometry2 as element()) as xs:boolean external;

(:~
 : Checks if geometry1 covers geometry2.<br/>
 : It has to fulfill one of these conditions:<br/>
 :  - every point of geometry2 is a point of geometry1<br/>
 :  - the DE-9IM Intersection Matrix for the two geometries is
 :     T*****FF* or *T****FF* or ***T**FF* or ****T*FF*.<br/>
 : <br/>
 : Unlike contains it does not distinguish between points in the boundary and in the interior of geometries.
 :
 : @param $geometry1 node of one of GMLSF objects: gml:Point, gml:LineString, gml:Curve, gml:LinearRing, 
 :    gml:Surface, gml:Polygon, gml:MultiPoint, gml:MultiCurve, gml:MultiSurface, gml:MultiGeometry
 : @param $geometry2 node of one of GMLSF objects: gml:Point, gml:LineString, gml:Curve, gml:LinearRing, 
 :    gml:Surface, gml:Polygon, gml:MultiPoint, gml:MultiCurve, gml:MultiSurface, gml:MultiGeometry
 : @return true if geometry1 covers geometry2.
 : @error XPTY0004 - unrecognized geometric object
 : @example covers6.xq
:)
declare function zorba-geo:covers( $geometry1 as element(),  $geometry2 as element()) as xs:boolean external;

(:~
 : Checks if geometry1 does not touch or intersects geometry2.<br/>
 : It has to fulfill these conditions:<br/>
 :  - they have no point in common<br/>
 :  - the DE-9IM Intersection Matrix for the two geometries is
 :     FF*FF****.<br/>
 :  - geometry1 does not intersect geometry2<br/>
 :
 : @param $geometry1 node of one of GMLSF objects: gml:Point, gml:LineString, gml:Curve, gml:LinearRing, 
 :    gml:Surface, gml:Polygon, gml:MultiPoint, gml:MultiCurve, gml:MultiSurface, gml:MultiGeometry
 : @param $geometry2 node of one of GMLSF objects: gml:Point, gml:LineString, gml:Curve, gml:LinearRing, 
 :    gml:Surface, gml:Polygon, gml:MultiPoint, gml:MultiCurve, gml:MultiSurface, gml:MultiGeometry
 : @return true if geometry1 and geometry2 are disjoint.
 : @error XPTY0004 - unrecognized geometric object
 : @example disjoint1.xq
 : @example disjoint2.xq
 : @example disjoint3.xq
 : @example disjoint4.xq
 : @example disjoint5.xq
 : @example disjoint6.xq
 : @example disjoint7.xq
 : @example disjoint8.xq
 : @example disjoint9.xq
:)
declare function zorba-geo:disjoint( $geometry1 as element(),  $geometry2 as element()) as xs:boolean external;

(:~
 : Checks if geometry1 intersects geometry2.<br/>
 : This is true if disjoint returns false.
 : <br/>
 :
 : @param $geometry1 node of one of GMLSF objects: gml:Point, gml:LineString, gml:Curve, gml:LinearRing, 
 :    gml:Surface, gml:Polygon, gml:MultiPoint, gml:MultiCurve, gml:MultiSurface, gml:MultiGeometry
 : @param $geometry2 node of one of GMLSF objects: gml:Point, gml:LineString, gml:Curve, gml:LinearRing, 
 :    gml:Surface, gml:Polygon, gml:MultiPoint, gml:MultiCurve, gml:MultiSurface, gml:MultiGeometry
 : @return true if geometry1 and geometry2 are not disjoint.
 : @error XPTY0004 - unrecognized geometric object
 : @example intersects1.xq
 : @example intersects2.xq
 : @example intersects3.xq
 : @example intersects4.xq
 : @example intersects5.xq
 : @example intersects6.xq
 : @example intersects6_3d.xq
 : @example intersects7.xq
 : @example intersects8.xq
 : @example intersects9.xq
:)
declare function zorba-geo:intersects( $geometry1 as element(),  $geometry2 as element()) as xs:boolean external;

(:~
 : Checks if geometry1 touches geometry2.<br/>
 : Returns true if the DE-9IM intersection matrix for the two
 : geometries is FT*******, F**T***** or F***T****.
 : <br/>
 :
 : @param $geometry1 node of one of GMLSF objects: gml:Point, gml:LineString, gml:Curve, gml:LinearRing, 
 :    gml:Surface, gml:Polygon, gml:MultiPoint, gml:MultiCurve, gml:MultiSurface, gml:MultiGeometry
 : @param $geometry2 node of one of GMLSF objects: gml:Point, gml:LineString, gml:Curve, gml:LinearRing, 
 :    gml:Surface, gml:Polygon, gml:MultiPoint, gml:MultiCurve, gml:MultiSurface, gml:MultiGeometry
 : @return true if geometry1 touches geometry2.
 : @error XPTY0004 - unrecognized geometric object
 : @example touches1.xq
 : @example touches2.xq
 : @example touches3.xq
 : @example touches4.xq
 : @example touches5.xq
 : @example touches6.xq
 : @example touches7.xq
 : @example touches8.xq
 : @example touches9.xq
:)
declare function zorba-geo:touches( $geometry1 as element(),  $geometry2 as element()) as xs:boolean external;

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
 : @param $geometry1 node of one of GMLSF objects: gml:Point, gml:LineString, gml:Curve, gml:LinearRing, 
 :    gml:Surface, gml:Polygon, gml:MultiPoint, gml:MultiCurve, gml:MultiSurface, gml:MultiGeometry
 : @param $geometry2 node of one of GMLSF objects: gml:Point, gml:LineString, gml:Curve, gml:LinearRing, 
 :    gml:Surface, gml:Polygon, gml:MultiPoint, gml:MultiCurve, gml:MultiSurface, gml:MultiGeometry
 : @return true if geometry1 crosses geometry2.
 : @error XPTY0004 - unrecognized geometric object
 : @example crosses1.xq
 : @example crosses2.xq
 : @example crosses3.xq
 : @example crosses4.xq
 : @example crosses5.xq
 : @example crosses6.xq
 : @example crosses7.xq
 : @example crosses8.xq
 : @example crosses9.xq
 : @example crosses10.xq
:)
declare function zorba-geo:crosses( $geometry1 as element(),  $geometry2 as element()) as xs:boolean external;

(:~
 : Checks if geometry1 is within geometry2.<br/>
 : Returns true if the DE-9IM intersection matrix for the two
 : geometries is T*F**F***.
 : <br/>
 :
 : @param $geometry1 node of one of GMLSF objects: gml:Point, gml:LineString, gml:Curve, gml:LinearRing, 
 :    gml:Surface, gml:Polygon, gml:MultiPoint, gml:MultiCurve, gml:MultiSurface, gml:MultiGeometry
 : @param $geometry2 node of one of GMLSF objects: gml:Point, gml:LineString, gml:Curve, gml:LinearRing, 
 :    gml:Surface, gml:Polygon, gml:MultiPoint, gml:MultiCurve, gml:MultiSurface, gml:MultiGeometry
 : @return true if geometry1 is within geometry2.
 : @error XPTY0004 - unrecognized geometric object
 : @example within1.xq
 : @example within2.xq
 : @example within3.xq
 : @example within4.xq
 : @example within5.xq
 : @example within6.xq
 : @example within7.xq
 : @example within8.xq
 : @example within9.xq
:)
declare function zorba-geo:within( $geometry1 as element(),  $geometry2 as element()) as xs:boolean external;

(:~
 : Checks if geometry1 contains geometry2.<br/>
 : Returns true if within(geometry2, geometry1) is true.
 : <br/>
 :
 : @param $geometry1 node of one of GMLSF objects: gml:Point, gml:LineString, gml:Curve, gml:LinearRing, 
 :    gml:Surface, gml:Polygon, gml:MultiPoint, gml:MultiCurve, gml:MultiSurface, gml:MultiGeometry
 : @param $geometry2 node of one of GMLSF objects: gml:Point, gml:LineString, gml:Curve, gml:LinearRing, 
 :    gml:Surface, gml:Polygon, gml:MultiPoint, gml:MultiCurve, gml:MultiSurface, gml:MultiGeometry
 : @return true if geometry1 contains geometry2.
 : @error XPTY0004 - unrecognized geometric object
 : @example contains1.xq
 : @example contains2.xq
 : @example contains3.xq
 : @example contains4.xq
 : @example contains5.xq
 : @example contains6.xq
 : @example contains7.xq
 : @example contains8.xq
 : @example contains9.xq
 : @example contains10.xq
:)
declare function zorba-geo:contains( $geometry1 as element(),  $geometry2 as element()) as xs:boolean external;

(:~
 : Checks if geometry1 overlaps with geometry2.<br/>
 : Returns true if DE-9IM intersection matrix for the two
 : geometries is T*T***T** (for two points or two surfaces)
 :	 or * 1*T***T** (for two curves).
 : <br/>
 :
 : @param $geometry1 node of one of GMLSF objects: gml:Point, gml:LineString, gml:Curve, gml:LinearRing, 
 :    gml:Surface, gml:Polygon, gml:MultiPoint, gml:MultiCurve, gml:MultiSurface, gml:MultiGeometry
 : @param $geometry2 node of one of GMLSF objects: gml:Point, gml:LineString, gml:Curve, gml:LinearRing, 
 :    gml:Surface, gml:Polygon, gml:MultiPoint, gml:MultiCurve, gml:MultiSurface, gml:MultiGeometry
 : @return true if geometry1 overlaps geometry2.
 : @error XPTY0004 - unrecognized geometric object
 : @example overlaps1.xq
 : @example overlaps2.xq
 : @example overlaps3.xq
 : @example overlaps4.xq
 : @example overlaps5.xq
 : @example overlaps6.xq
 : @example overlaps7.xq
 : @example overlaps8.xq
 : @example overlaps9.xq
 : @example overlaps10.xq
 : @example overlaps11.xq
 : @example overlaps12.xq
:)
declare function zorba-geo:overlaps( $geometry1 as element(),  $geometry2 as element()) as xs:boolean external;

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
 : @return true if geometry1 relates to geometry2 according to the intersection matrix.
 : @error XPTY0004 - unrecognized geometric object
 : @error XPTY0004 - if any geometry is a collection
 : @example relate1.xq
 : @example relate2.xq
 : @example relate3.xq
 : @example relate4.xq
:)
declare function zorba-geo:relate( $geometry1 as element(),  $geometry2 as element(), $intersection_matrix as xs:string) as xs:boolean external;




(:~
 : Compute the shortest distance between any two Points in geometry1 and geometry2.<br/>
 : <br/>
 :
 : @param $geometry1 node of one of GMLSF objects: gml:Point, gml:LineString, gml:Curve, gml:LinearRing, 
 :    gml:Surface, gml:Polygon, gml:MultiPoint, gml:MultiCurve, gml:MultiSurface, gml:MultiGeometry
 : @param $geometry2 node of one of GMLSF objects: gml:Point, gml:LineString, gml:Curve, gml:LinearRing, 
 :    gml:Surface, gml:Polygon, gml:MultiPoint, gml:MultiCurve, gml:MultiSurface, gml:MultiGeometry
 : @return minimum distance as xs:double.
 : @error XPTY0004 - unrecognized geometric object
 : @example distance1.xq
:)
declare function zorba-geo:distance( $geometry1 as element(),  $geometry2 as element()) as xs:double external;

(:~
 : Returns a polygon that represents all Points whose distance
 :   from this geometric object is less than or equal to distance.<br/>
 : <br/>
 :
 : @param $geometry node of one of GMLSF objects: gml:Point, gml:LineString, gml:Curve, gml:LinearRing, 
 :    gml:Surface, gml:Polygon, gml:MultiPoint, gml:MultiCurve, gml:MultiSurface, gml:MultiGeometry
 : @param $distance the distance from geometry, expressed in units of the current coordinate system
 : @return new geometry surrounding the input geometry.
 : @error XPTY0004 - unrecognized geometric object
 : @example buffer1.xq
 : @example buffer2.xq
 : @example buffer3.xq
 : @example buffer4.xq
 : @example buffer5.xq
 : @example buffer6.xq
 : @example buffer7.xq
 : @example buffer8.xq
 : @example buffer9.xq
 : @example buffer10.xq
:)
declare function zorba-geo:buffer( $geometry as element(),  $distance as xs:double) as element() external;

(:~
 : Returns the smallest convex Polygon that contains all the points in the Geometry.<br/>
 : Actually returns the object of smallest dimension possible (possible Point or LineString).<br/>
 : <br/>
 :
 : @param $geometry node of one of GMLSF objects: gml:Point, gml:LineString, gml:Curve, gml:LinearRing, 
 :    gml:Surface, gml:Polygon, gml:MultiPoint, gml:MultiCurve, gml:MultiSurface, gml:MultiGeometry
 : @return the convex polygon node.
 : @error XPTY0004 - unrecognized geometric object
 : @example convex-hull1.xq
 : @example convex-hull2.xq
 : @example convex-hull3.xq
 : @example convex-hull3_3d.xq
 : @example convex-hull4.xq
 : @example convex-hull5.xq
 : @example convex-hull6.xq
 : @example convex-hull7.xq
 : @example convex-hull8.xq
 : @example convex-hull9.xq
 : @example convex-hull10.xq
:)
declare function zorba-geo:convex-hull( $geometry as element()) as element() external;

(:~
 : Returns a geometric object that represents the Point set intersection of
 :    geometry1 and geometry2.<br/>
 : For intersection of two polygons interiors, returns a polygon.<br/>
 : If intersection is void, empty sequence is returned.
 : <br/>
 :
 : @param $geometry1 node of one of GMLSF objects: gml:Point, gml:LineString, gml:Curve, gml:LinearRing, 
 :    gml:Surface, gml:Polygon, gml:MultiPoint, gml:MultiCurve, gml:MultiSurface, gml:MultiGeometry
 : @param $geometry2 node of one of GMLSF objects: gml:Point, gml:LineString, gml:Curve, gml:LinearRing, 
 :    gml:Surface, gml:Polygon, gml:MultiPoint, gml:MultiCurve, gml:MultiSurface, gml:MultiGeometry
 : @return point set geometry node.
 : @error XPTY0004 - unrecognized geometric object
 : @example intersection1.xq
 : @example intersection2.xq
 : @example intersection3.xq
 : @example intersection4.xq
 : @example intersection5.xq
 : @example intersection6.xq
 : @example intersection7.xq
 : @example intersection8.xq
 : @example intersection8_3d.xq
 : @example intersection9.xq
 : @example intersection10.xq
:)
declare function zorba-geo:intersection( $geometry1 as element(),  $geometry2 as element()) as element()? external;

(:~
 : Returns a geometric object that represents the Point set union of
 :    geometry1 and geometry2.<br/>
 : <br/>
 :
 : @param $geometry1 node of one of GMLSF objects: gml:Point, gml:LineString, gml:Curve, gml:LinearRing, 
 :    gml:Surface, gml:Polygon, gml:MultiPoint, gml:MultiCurve, gml:MultiSurface, gml:MultiGeometry
 : @param $geometry2 node of one of GMLSF objects: gml:Point, gml:LineString, gml:Curve, gml:LinearRing, 
 :    gml:Surface, gml:Polygon, gml:MultiPoint, gml:MultiCurve, gml:MultiSurface, gml:MultiGeometry
 : @return point set geometry node.
 : @error XPTY0004 - unrecognized geometric object
 : @example union1.xq
 : @example union2.xq
 : @example union3.xq
 : @example union4.xq
 : @example union5.xq
 : @example union5_3d.xq
 : @example union6.xq
 : @example union7.xq
 : @example union8.xq
 : @example union9.xq
:)
declare function zorba-geo:union( $geometry1 as element(),  $geometry2 as element()) as element() external;

(:~
 : Returns a geometric object that represents the Point set difference of
 :    geometry1 and geometry2. Points that are in geometry1 and are not in geometry2.<br/>
 : If difference is empty geometry, empty sequence is returned.
 : <br/>
 :
 : @param $geometry1 node of one of GMLSF objects: gml:Point, gml:LineString, gml:Curve, gml:LinearRing, 
 :    gml:Surface, gml:Polygon, gml:MultiPoint, gml:MultiCurve, gml:MultiSurface, gml:MultiGeometry
 : @param $geometry2 node of one of GMLSF objects: gml:Point, gml:LineString, gml:Curve, gml:LinearRing, 
 :    gml:Surface, gml:Polygon, gml:MultiPoint, gml:MultiCurve, gml:MultiSurface, gml:MultiGeometry
 : @return point set geometry node.
 : @error XPTY0004 - unrecognized geometric object
 : @example difference1.xq
 : @example difference2.xq
 : @example difference3.xq
 : @example difference4.xq
 : @example difference5.xq
 : @example difference6.xq
 : @example difference7.xq
 : @example difference8.xq
 : @example difference9.xq
 : @example difference10.xq
:)
declare function zorba-geo:difference( $geometry1 as element(),  $geometry2 as element()) as element()? external;

(:~
 : Returns a geometric object that represents the Point set symmetric difference of
 :    geometry1 and geometry2. Points that are in geometry1 and are not in geometry2
 :    and points that are in geometry2 and are not in geometry1.<br/>
 : If difference is empty geometry, empty sequence is returned.
 : <br/>
 :
 : @param $geometry1 node of one of GMLSF objects: gml:Point, gml:LineString, gml:Curve, gml:LinearRing, 
 :    gml:Surface, gml:Polygon, gml:MultiPoint, gml:MultiCurve, gml:MultiSurface, gml:MultiGeometry
 : @param $geometry2 node of one of GMLSF objects: gml:Point, gml:LineString, gml:Curve, gml:LinearRing, 
 :    gml:Surface, gml:Polygon, gml:MultiPoint, gml:MultiCurve, gml:MultiSurface, gml:MultiGeometry
 : @return point set geometry node.
 : @error XPTY0004 - unrecognized geometric object
 : @example sym-difference1.xq
 : @example sym-difference2.xq
 : @example sym-difference3.xq
 : @example sym-difference4.xq
 : @example sym-difference5.xq
 : @example sym-difference6.xq
 : @example sym-difference7.xq
 : @example sym-difference8.xq
 : @example sym-difference9.xq
:)
declare function zorba-geo:sym-difference( $geometry1 as element(),  $geometry2 as element()) as element()? external;




(:~
 : Returns the area of this geometry.<br/>
 : Returns zero for Point and Lines.<br/>
 : <br/>
 :
 : @param $geometry node of one of GMLSF objects: gml:Point, gml:LineString, gml:Curve, gml:LinearRing, 
 :    gml:Surface, gml:Polygon, gml:MultiPoint, gml:MultiCurve, gml:MultiSurface, gml:MultiGeometry
 : @return geometry area as xs:double.
 : @error XPTY0004 - unrecognized geometric object
 : @example area1.xq
 : @example area2.xq
 : @example area3.xq
 : @example area4.xq
 : @example area5.xq
 : @example area6.xq
 : @example area7.xq
 : @example area8.xq
 : @example area9.xq
 : @example area10.xq
:)
declare function zorba-geo:area( $geometry as element()) as xs:double external;

(:~
 : Returns the length of the lines of this geometry.<br/>
 : Returns zero for Points.<br/>
 : <br/>
 :
 : @param $geometry node of one of GMLSF objects: gml:Point, gml:LineString, gml:Curve, gml:LinearRing, 
 :    gml:Surface, gml:Polygon, gml:MultiPoint, gml:MultiCurve, gml:MultiSurface, gml:MultiGeometry
 : @return geometry length as xs:double.
 : @error XPTY0004 - unrecognized geometric object
 : @example length1.xq
 : @example length2.xq
 : @example length3.xq
 : @example length4.xq
 : @example length5.xq
 : @example length6.xq
 : @example length7.xq
 : @example length8.xq
 : @example length9.xq
 : @example length10.xq
:)
declare function zorba-geo:length( $geometry as element()) as xs:double external;

(:~
 : Checks if geometry2 is within a certain distance of geometry1.<br/>
 : <br/>
 :
 : @param $geometry1 node of one of GMLSF objects: gml:Point, gml:LineString, gml:Curve, gml:LinearRing, 
 :    gml:Surface, gml:Polygon, gml:MultiPoint, gml:MultiCurve, gml:MultiSurface, gml:MultiGeometry
 : @param $geometry2 node of one of GMLSF objects: gml:Point, gml:LineString, gml:Curve, gml:LinearRing, 
 :    gml:Surface, gml:Polygon, gml:MultiPoint, gml:MultiCurve, gml:MultiSurface, gml:MultiGeometry
 : @param $distance the distance from geometry1, expressed in units of the current coordinate system
 : @return true if distance from geometry1 to geometry2 is less than $distance.
 : @error XPTY0004 - unrecognized geometric object
 : @example is-within-distance1.xq
 : @example is-within-distance2.xq
 : @example is-within-distance3.xq
 : @example is-within-distance4.xq
 : @example is-within-distance5.xq
 : @example is-within-distance6.xq
 : @example is-within-distance7.xq
 : @example is-within-distance8.xq
 : @example is-within-distance9.xq
:)
declare function zorba-geo:is-within-distance( $geometry1 as element(),  $geometry2 as element(), $distance as xs:double) as xs:boolean external;

(:~
 : Returns a Point that is the mathematical centroid of this geometry.
 : The result is not guaranteed to be on the surface. <br/>
 : <br/>
 :
 : @param $geometry node of one of GMLSF objects: gml:Point, gml:LineString, gml:Curve, gml:LinearRing, 
 :    gml:Surface, gml:Polygon, gml:MultiPoint, gml:MultiCurve, gml:MultiSurface, gml:MultiGeometry
 : @return centroid Point.
 : @error XPTY0004 - unrecognized geometric object
 : @example centroid1.xq
 : @example centroid2.xq
 : @example centroid3.xq
 : @example centroid4.xq
 : @example centroid5.xq
 : @example centroid6.xq
 : @example centroid7.xq
 : @example centroid8.xq
 : @example centroid9.xq
 : @example centroid10.xq
:)
declare function zorba-geo:centroid( $geometry as element()) as element(gml:Point) external;

(:~
 : Returns a Point that is interior of this geometry.
 : If it cannot be inside the geometry, then it will be on the boundary. <br/>
 : <br/>
 :
 : @param $geometry node of one of GMLSF objects: gml:Point, gml:LineString, gml:Curve, gml:LinearRing, 
 :    gml:Surface, gml:Polygon, gml:MultiPoint, gml:MultiCurve, gml:MultiSurface, gml:MultiGeometry
 : @return a Point inside the geometry.
 : @error XPTY0004 - unrecognized geometric object
 : @example interior-point1.xq
 : @example interior-point2.xq
 : @example interior-point3.xq
 : @example interior-point4.xq
 : @example interior-point5.xq
 : @example interior-point6.xq
 : @example interior-point7.xq
 : @example interior-point8.xq
 : @example interior-point9.xq
 : @example interior-point10.xq
:)
declare function zorba-geo:point-on-surface( $geometry as element()) as element(gml:Point) external;






(:~
 : Returns the X coordinate of a Point.
 : <br/>
 :
 : @param $point node of one of GMLSF objects: gml:Point
 : @return the X coordinate
 : @error XPTY0004 - unrecognized geometric object or not a gml:Point
 : @example point-xyz1.xq
 : @example point-xyz4.xq
:)
declare function zorba-geo:x( $point as element(gml:Point)) as xs:double external;

(:~
 : Returns the Y coordinate of a Point.
 : <br/>
 :
 : @param $point node of one of GMLSF objects: gml:Point
 : @return the Y coordinate
 : @error XPTY0004 - unrecognized geometric object or not a gml:Point
 : @example point-xyz2.xq
:)
declare function zorba-geo:y( $point as element(gml:Point)) as xs:double external;

(:~
 : Returns the Z coordinate of a Point, if is 3D.
 : <br/>
 :
 : @param $point node of one of GMLSF objects: gml:Point
 : @return the Z coordinate, or empty sequence if 2D
 : @error XPTY0004 - unrecognized geometric object or not a gml:Point
 : @example point-xyz3.xq
 : @example point-xyz5.xq
:)
declare function zorba-geo:z( $point as element(gml:Point)) as xs:double? external;

(:~
 : Should return the Measure of a Point, but is not implemented, 
 : because it is not specified in GMLSF.
 : <br/>
 :
 : @param $point node of one of GMLSF objects: gml:Point
 : @return always empty sequence
 : @error XPTY0004 - unrecognized geometric object or not a gml:Point
 : @example point-xyz6.xq
:)
declare function zorba-geo:m( $point as element(gml:Point)) as xs:double? external;







(:~
 : Returns the start Point of a line.
 : <br/>
 :
 : @param $line node of one of GMLSF objects: gml:LineString, gml:LinearRing, gml:Curve
 : @return the starting gml:Point, constructed with the first coordinates in the line.
 : @error XPTY0004 - unrecognized geometric object or not a line
 : @example start-point1.xq
 : @example start-point2.xq
 : @example start-point3.xq
:)
declare function zorba-geo:start-point( $line as element()) as element(gml:Point) external;

(:~
 : Returns the end Point of a line.
 : <br/>
 :
 : @param $line node of one of GMLSF objects: gml:LineString, gml:LinearRing, gml:Curve
 : @return the end gml:Point, constructed with the last coordinates in the line.
 : @error XPTY0004 - unrecognized geometric object or not a line
 : @example end-point1.xq
:)
declare function zorba-geo:end-point( $line as element()) as element(gml:Point) external;

(:~
 : Checks if the line is closed loop. That is, if the start Point is same with end Point.
 : For gml:Curve, checks if the start point of the first segment is the same with the
 :   last point of the last segment. It also checks that all the segments are connected together,
 :   and returns false if they aren't.<br/>
 : For gml:MultiCurve, checks recursively for each LineString.<br/>
 : For gml:Surface, checks if the exterior boundary of each patch touches completely other patches,
 :   so the Surface encloses a solid.
 :   For this to happen there is a need for 3D objects, and full 3D processing is not supported in GEOS library,
 :   so the function always returns false in this case.
 : <br/>
 :
 : @param $geom node of one of GMLSF objects: gml:LineString, gml:LinearRing, gml:Curve,
 :      gml:MultiCurve, gml:Surface
 : @return true if the line or surface is closed.
 : @error XPTY0004 - unrecognized geometric object or not a line
 : @example is-closed1.xq
 : @example is-closed2.xq
 : @example is-closed3.xq
 : @example is-closed4.xq
 : @example is-closed5.xq
 : @example is-closed6.xq
:)
declare function zorba-geo:is-closed( $geom as element()) as xs:boolean external;

(:~
 : Checks if the line is a ring. That is, if the line is closed and simple.
 : <br/>
 :
 : @param $line node of one of GMLSF objects: gml:LineString, gml:LinearRing, gml:Curve
 : @return true if the line is a closed ring.
 : @error XPTY0004 - unrecognized geometric object or not a line
 : @example is-ring1.xq
 : @example is-ring2.xq
 : @example is-ring3.xq
 : @example is-ring4.xq
:)
declare function zorba-geo:is-ring( $line as element()) as xs:boolean external;

(:~
 : Return the number of Points in a line.
 : <br/>
 :
 : @param $line node of one of GMLSF objects: gml:LineString, gml:LinearRing, gml:Curve,
 :   gml:MultiCurve
 : @return number of points in the line
 : @error XPTY0004 - unrecognized geometric object or not a line
 : @example num-points1.xq
 : @example num-points2.xq
 : @example num-points3.xq
:)
declare function zorba-geo:num-points( $line as element()) as xs:unsignedInt external;

(:~
 : Return the n-th Point in a line
 : <br/>
 :
 : @param $line node of one of GMLSF objects: gml:LineString, gml:LinearRing, gml:Curve,
 :    gml:MultiCurve
 : @param $n index in the list of coordinates, zero based.
 : @return n-th point in the line, zero-based. The node is gml:Point constructed with n-th coordinate from line.
 : @error XPTY0004 - unrecognized geometric object or not a line
 : @example point-n1.xq
 : @example point-n2.xq
 : @example point-n3.xq
:)
declare function zorba-geo:point-n( $line as element(), $n as xs:unsignedInt) as element(gml:Point) external;






(:~
 : Return the exterior ring of a Polygon.
 : <br/>
 :
 : @param $polygon node of one of GMLSF objects: gml:Polygon
 : @return the original gml:LinearRing node for exterior ring
 : @error XPTY0004 - unrecognized geometric object or not a polygon
 : @example exterior-ring1.xq
 : @example exterior-ring2.xq
:)
declare function zorba-geo:exterior-ring( $polygon as element(gml:Polygon)) as element(gml:LinearRing) external;

(:~
 : Return the number of interior rings of a Polygon.
 : <br/>
 :
 : @param $polygon node of one of GMLSF objects: gml:Polygon
 : @return the number of interior rings
 : @error XPTY0004 - unrecognized geometric object or not a polygon
 : @example num-interior-ring1.xq
:)
declare function zorba-geo:num-interior-ring( $polygon as element(gml:Polygon)) as xs:unsignedInt external;

(:~
 : Return the n-th interior ring of a Polygon.
 : <br/>
 :
 : @param $polygon node of one of GMLSF objects: gml:Polygon
 : @param $n index in the list of interior rings, zero based.
 : @return n-th interior ring. The node is the original node, not a copy.
 : @error XPTY0004 - unrecognized geometric object or not a Polygon
 : @error XPTY0004 - if n is outside the range
 : @example interior-ring-n1.xq
:)
declare function zorba-geo:interior-ring-n( $polygon as element(gml:Polygon), $n as xs:unsignedInt) as element(gml:LinearRing) external;

(:~
 : Return the number of surface patches inside a gml:Surface.<br/>
 : This function has the same effect as num-geometries(), only it is restricted to gml:Surface.
 : <br/>
 :
 : @param $polyhedral-surface node of one of GMLSF objects: gml:Surface
 : @return the number of surface patches
 : @error XPTY0004 - unrecognized geometric object or not a Surface
 : @example num-patches1.xq
 : @example num-patches2.xq
:)
declare function zorba-geo:num-patches($polyhedral-surface as element(gml:Surface)) as xs:integer external;

(:~
 : Return the n-th Surface patch of a Surface.<br/>
 : Only polygonal Surfaces are supported, so a gml:PolygonPatch is returned.<br/>
 : The gml:PolygonPatch has the same content as gml:Polygon.<br/>
 : This function has the same effect as geometry-n(), only it is restricted to gml:Surface.
 : <br/>
 :
 : @param $polyhedral-surface node of one of GMLSF objects: gml:Surface
 : @param $n index in the list of surface patches, zero based.
 : @return n-th polygon patch. The node is the original node, not a copy.
 : @error XPTY0004 - unrecognized geometric object or not a Surface
 : @error XPTY0004 - if n is outside the range
 : @example patch-n1.xq
 : @example patch-n2.xq
:)
declare function zorba-geo:patch-n($polyhedral-surface as element(gml:Surface), 
																		$n as xs:unsignedInt) as element(gml:PolygonPatch) external;


(:~
 : Return the list of PolygonPatches that share a boundary with the given $polygon.<br/>
 : The gml:PolygonPatch has the same content as gml:Polygon.<br/>
 : This function tests the exterior ring of each polygon patch if it overlaps
 : with the exterior ring of the given polygon.
 : <br/>
 :
 : @param $polyhedral-surface node of one of GMLSF objects: gml:Surface
 : @param $polygon, of type gml:Polygon or gml:PolygonPatch
 : @return the list of neibourghing gml:PolygonPatch-es
 : @error XPTY0004 - unrecognized geometric object or not a Surface
 : @example bounding-polygons1.xq
 : @example bounding-polygons2.xq
 : @example bounding-polygons3.xq
:)
declare function zorba-geo:bounding-polygons($polyhedral-surface as element(gml:Surface), 
																	 $polygon as element()) as element(gml:PolygonPatch)* external;