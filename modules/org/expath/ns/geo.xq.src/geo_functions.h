/*
 * Copyright 2006-2008 The FLWOR Foundation.
 * 
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 * 
 * http://www.apache.org/licenses/LICENSE-2.0
 * 
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#ifndef ZORBA_GEOMODULE_GEOFUNCTION_H
#define ZORBA_GEOMODULE_GEOFUNCTION_H

#include <zorba/external_function.h>

namespace geos{
namespace geom{
class GeometryFactory;
class Geometry;
class CoordinateSequence;
class MultiLineString;
class MultiPolygon;
class LineString;
class LinearRing;
}}

namespace zorba { namespace geomodule {

  class GeoModule;

  class GeoFunction : public NonePureStatelessExternalFunction
  {
    protected:
      const GeoModule* theModule;
      //geos::geom::GeometryFactory   *geo_factory;

      static void
        throwError(
              const char *err_localname,
              const std::string aErrorMessage);


    public:
      enum gmlsf_types{
        GMLSF_POINT,
        GMLSF_LINESTRING,
        GMLSF_CURVE,
        GMLSF_LINEARRING,
        GMLSF_SURFACE,
        GMLSF_POLYGON,
        //GMLSF_POLYGONPATCH,
        GMLSF_MULTIPOINT,
        GMLSF_MULTICURVE,
        GMLSF_MULTISURFACE,
        GMLSF_MULTIGEOMETRY,

        GMLSF_INVALID
      };

      enum action_item{
        BUILD_GEOS_GEOMETRY,
        COUNT_CHILDREN,
        GET_NTH_CHILD,
        GET_EXTERIOR_RING,
        GET_NUM_POINTS,
        GET_NTH_POINT,
        GET_END_POINT
      };
    protected:
      bool getChild(zorba::Item &lItem, const char *localname, const char *ns, 
                    zorba::Item &child_item) const;
      bool getChild(zorba::Iterator_t children, const char *localname, const char *ns, 
                    zorba::Item &child_item) const;
      bool getAttribute(  zorba::Item &item, 
                           const char *name, 
                           const char *ns,
                           zorba::Item &attr_item) const;
      bool checkOptionalAttribute(zorba::Item &item, const char *attr_name, const char *ns, const char *attr_value) const;
      int get_srsDimension(zorba::Item &item, int prev_srsdimension) const;
      const geos::geom::GeometryFactory   *get_geometryFactory() const;
      void readPointPosCoordinates(zorba::Item &lItem, double *x, double *y, double *z, int &srs_dim) const;
      bool readPointPosCoordinates(zorba::Iterator_t children, double *x, double *y, double *z, int &srs_dim) const;
      void readPosListCoordinates(zorba::Item &lItem, geos::geom::CoordinateSequence *&cl, int &srs_dim) const;
      int  getCoordinateDimension(const geos::geom::Geometry *geos_geometry) const;
      void getSrsName(zorba::Item lItem, zorba::Item &srs_uri) const;
      bool isCurve(const geos::geom::MultiLineString *multiline) const;
      bool isSurface(const geos::geom::MultiPolygon *multipolygon,
                     bool *is_closed = NULL,
                     geos::geom::LinearRing **exterior_boundary = NULL) const;
      geos::geom::LineString *curveToLineString(const geos::geom::Geometry *geos_geometry) const;
      bool isClosedCurve(const geos::geom::Geometry *geos_geometry) const;
      bool isRingCurve(const geos::geom::Geometry *geos_geometry) const;
      bool isSimpleCurve(const geos::geom::Geometry *geos_geometry) const;
      
      zorba::Item getBoundary(geos::geom::Geometry *geos_geometry, zorba::Item srs_uri) const;
      void getMultiGeometryBoundary(geos::geom::Geometry *geos_geometry, 
                                    std::vector<zorba::Item> *boundaries,
                                    zorba::Item srs_uri) const;
      void addNewLineIndentText(zorba::Item &parent, unsigned int indent) const;
      void appendIndent(char *&strtemp2, unsigned int indent) const;
      unsigned char hex_to_bin(char hex) const;

    public:
      GeoFunction(const GeoModule* module);
      virtual ~GeoFunction();

      virtual String
      getURI() const;

      enum gmlsf_types getGmlSFGeometricType(Item item) const;
      enum gmlsf_types getGeometryNodeType(const StatelessExternalFunction::Arguments_t& args, int arg_pos, zorba::Item &lItem) const;
      
      geos::geom::Geometry  *buildGeosGeometryFromItem(zorba::Item &lItem, 
                                                      enum GeoFunction::gmlsf_types geometric_type,
                                                      int  srs_dim,
                                                      zorba::Item *srs_uri = NULL,
                                                      enum GeoFunction::action_item what_action = BUILD_GEOS_GEOMETRY,
                                                      uint32_t *optional_child_index_or_count = NULL,
                                                      zorba::Item *result_item = NULL) const;
      zorba::Item getGMLItemFromGeosGeometry(zorba::Item &parent, 
                                              const geos::geom::Geometry *geos_geometry,
                                              const zorba::Item *srs_uri = NULL,
                                              unsigned int indent = 0,
                                              const char *tag_name = NULL,
                                              bool dont_check_for_curve_surface = false) const;
  };


//*****************************************************************************
#define DECLARE_GEOFUNCTION_CLASS(geoclass_name, function_name)                 \
  class geoclass_name : public GeoFunction                                      \
  {                                                                             \
    public:                                                                     \
      geoclass_name(const GeoModule* aModule) : GeoFunction(aModule) {}         \
                                                                                \
      virtual String                                                            \
      getLocalName() const { return #function_name; }                           \
                                                                                \
      virtual ItemSequence_t                                                    \
      evaluate(const StatelessExternalFunction::Arguments_t& args,              \
               const StaticContext* aSctxCtx,                                   \
               const DynamicContext* aDynCtx) const;                            \
  };

DECLARE_GEOFUNCTION_CLASS(SFDimensionFunction, dimension)
DECLARE_GEOFUNCTION_CLASS(SFCoordinateDimensionFunction, coordinate-dimension)
DECLARE_GEOFUNCTION_CLASS(SFGeometryTypeFunction, geometry-type)
DECLARE_GEOFUNCTION_CLASS(SFSridFunction, srid)
DECLARE_GEOFUNCTION_CLASS(SFNumGeometriesFunction, num-geometries)
DECLARE_GEOFUNCTION_CLASS(SFGeometryNFunction, geometry-n)
DECLARE_GEOFUNCTION_CLASS(SFEnvelopeFunction, envelope)
DECLARE_GEOFUNCTION_CLASS(SFAsTextFunction, as-text)
DECLARE_GEOFUNCTION_CLASS(SFAsBinaryFunction, as-binary)
DECLARE_GEOFUNCTION_CLASS(SFIsEmptyFunction, is-empty)
DECLARE_GEOFUNCTION_CLASS(SFIsSimpleFunction, is-simple)
DECLARE_GEOFUNCTION_CLASS(SFIs3DFunction, is-3d)
DECLARE_GEOFUNCTION_CLASS(SFIsMeasuredFunction, is-measured)
DECLARE_GEOFUNCTION_CLASS(SFBoundaryFunction, boundary)
DECLARE_GEOFUNCTION_CLASS(SFEqualsFunction, equals)
DECLARE_GEOFUNCTION_CLASS(SFCoversFunction, covers)
DECLARE_GEOFUNCTION_CLASS(SFDisjointFunction, disjoint)
DECLARE_GEOFUNCTION_CLASS(SFIntersectsFunction, intersects)
DECLARE_GEOFUNCTION_CLASS(SFTouchesFunction, touches)
DECLARE_GEOFUNCTION_CLASS(SFCrossesFunction, crosses)
DECLARE_GEOFUNCTION_CLASS(SFWithinFunction, within)
DECLARE_GEOFUNCTION_CLASS(SFContainsFunction, contains)
DECLARE_GEOFUNCTION_CLASS(SFOverlapsFunction, overlaps)
DECLARE_GEOFUNCTION_CLASS(SFRelateFunction, relate)
DECLARE_GEOFUNCTION_CLASS(SFDistanceFunction, distance)
DECLARE_GEOFUNCTION_CLASS(SFBufferFunction, buffer)
DECLARE_GEOFUNCTION_CLASS(SFConvexHullFunction, convex-hull)
DECLARE_GEOFUNCTION_CLASS(SFIntersectionFunction, intersection)
DECLARE_GEOFUNCTION_CLASS(SFUnionFunction, union)
DECLARE_GEOFUNCTION_CLASS(SFDifferenceFunction, difference)
DECLARE_GEOFUNCTION_CLASS(SFSymDifferenceFunction, sym-difference)
DECLARE_GEOFUNCTION_CLASS(SFAreaFunction, area)
DECLARE_GEOFUNCTION_CLASS(SFLengthFunction, length)
DECLARE_GEOFUNCTION_CLASS(SFIsWithinDistanceFunction, is-within-distance)
DECLARE_GEOFUNCTION_CLASS(SFCentroidFunction, centroid)
DECLARE_GEOFUNCTION_CLASS(SFPointOnSurfaceFunction, point-on-surface)

DECLARE_GEOFUNCTION_CLASS(SFXFunction, x)
DECLARE_GEOFUNCTION_CLASS(SFYFunction, y)
DECLARE_GEOFUNCTION_CLASS(SFZFunction, z)
DECLARE_GEOFUNCTION_CLASS(SFMFunction, m)

DECLARE_GEOFUNCTION_CLASS(SFStartPointFunction, start-point)
DECLARE_GEOFUNCTION_CLASS(SFEndPointFunction, end-point)
DECLARE_GEOFUNCTION_CLASS(SFIsClosedFunction, is-closed)
DECLARE_GEOFUNCTION_CLASS(SFIsRingFunction, is-ring)
DECLARE_GEOFUNCTION_CLASS(SFNumPointsFunction, num-points)
DECLARE_GEOFUNCTION_CLASS(SFPointNFunction, point-n)

DECLARE_GEOFUNCTION_CLASS(SFExteriorRingFunction, exterior-ring)
DECLARE_GEOFUNCTION_CLASS(SFNumInteriorRingFunction, num-interior-ring)
DECLARE_GEOFUNCTION_CLASS(SFInteriorRingNFunction, interior-ring-n)

DECLARE_GEOFUNCTION_CLASS(SFNumPatchesFunction, num-patches)
DECLARE_GEOFUNCTION_CLASS(SFPatchNFunction, patch-n)
DECLARE_GEOFUNCTION_CLASS(SFBoundingPolygonsFunction, bounding-polygons)
} /* namespace geomodule */
} /* namespace zorba */

#endif /* ZORBA_FILEMODULE_FILEFUNCTION_H */
