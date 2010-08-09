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

#include "geo_functions.h"

#include <geos/geom/PrecisionModel.h>
#include <geos/geom/GeometryFactory.h>
#include <geos/geom/Geometry.h>
#include <geos/geom/Point.h>
#include <geos/geom/LinearRing.h>
#include <geos/geom/LineString.h>
#include <geos/geom/Polygon.h>
#include <geos/geom/GeometryCollection.h>
#include <geos/geom/MultiPoint.h>
#include <geos/geom/MultiLineString.h>
#include <geos/geom/MultiPolygon.h>
#include <geos/geom/Coordinate.h>
#include <geos/geom/CoordinateSequence.h>
#include <geos/geom/CoordinateArraySequence.h>
#include <geos/geom/IntersectionMatrix.h>
#include <geos/io/WKBReader.h>
#include <geos/io/WKBWriter.h>
#include <geos/io/WKTWriter.h>
#include <geos/util/GeometricShapeFactory.h>
#include <geos/util/GEOSException.h>
#include <geos/util/IllegalArgumentException.h>
#include <geos/opLinemerge.h>
#include <geos/opPolygonize.h>
#include <vector>
#include <sstream>
#include <iomanip>

#include <zorba/zorba.h>
#include <zorba/store_consts.h>
#include <zorba/singleton_item_sequence.h>

#include "geo_module.h"

namespace zorba { namespace geomodule {

GeoFunction::GeoFunction(const GeoModule* aModule)
        : theModule(aModule)
{
//  geo_factory = NULL;
}

GeoFunction::~GeoFunction()
{
//  delete geo_factory;
}

String
GeoFunction::getURI() const
{
  return theModule->getURI();
}

void
GeoFunction::throwError(
    const std::string aErrorMessage,
    const XQUERY_ERROR& aErrorType)
{
  throw zorba::ExternalFunctionData::createZorbaException(aErrorType,
      aErrorMessage.c_str(), __FILE__, __LINE__);
}

enum GeoFunction::gmlsf_types GeoFunction::getGmlSFGeometricType(Item item) const
{
  Item  item_qname;
  item.getNodeName(item_qname);
  String  item_namespace = item_qname.getNamespace();
  if(!item_namespace.byteEqual("http://www.opengis.net/gml", 26))
    return GMLSF_INVALID;
  String  localname = item_qname.getLocalName();

  if(localname.byteEqual("Point", 5))
    return GMLSF_POINT;
  else if(localname.byteEqual("LineString", 10))
    return GMLSF_LINESTRING;
  else if(localname.byteEqual("Curve", 5))
    return GMLSF_CURVE;
  else if(localname.byteEqual("LinearRing", 10))
    return GMLSF_LINEARRING;
  else if(localname.byteEqual("Surface", 7))
    return GMLSF_SURFACE;
  else if(localname.byteEqual("Polygon", 7))
    return GMLSF_POLYGON;
  else if(localname.byteEqual("MultiPoint", 10))
    return GMLSF_MULTIPOINT;
  else if(localname.byteEqual("MultiCurve", 10))
    return GMLSF_MULTICURVE;
  else if(localname.byteEqual("MultiSurface", 12))
    return GMLSF_MULTISURFACE;
  else
    return GMLSF_INVALID;
}

enum GeoFunction::gmlsf_types GeoFunction::getGeometryNodeType(const StatelessExternalFunction::Arguments_t& args,
                                                               int arg_pos, zorba::Item &lItem) const
{
  if (!args[arg_pos]->next(lItem)) 
  {
    std::stringstream lErrorMessage;
    lErrorMessage << "An empty-sequence is not allowed as parameter";
    throwError(lErrorMessage.str(), XPTY0004);
  }

  if(!lItem.isNode() || (lItem.getNodeKind() != store::StoreConsts::elementNode))
  {
    std::stringstream lErrorMessage;
    lErrorMessage << "Argument must be a geometric node ";
    throwError(lErrorMessage.str(), XPTY0004);
  }
  return getGmlSFGeometricType(lItem);
}

bool GeoFunction::getChild(zorba::Item &lItem, const char *localname, const char *ns, 
                           zorba::Item &child_item) const
{
  Iterator_t    children;
  children = lItem.getChildren();
  children->open();
  bool retval = getChild(children, localname, ns, child_item);
  children->close();
  return retval;
}

bool GeoFunction::getChild(zorba::Iterator_t children, const char *localname, const char *ns, 
                           zorba::Item &child_item) const
{
  while(children->next(child_item))
  {
    if(child_item.getNodeKind() != store::StoreConsts::elementNode)
      continue;
    Item    child_name;
    child_item.getNodeName(child_name);
    String  item_namespace = child_name.getNamespace();
    if(!item_namespace.byteEqual(ns, strlen(ns)))
    {
      continue;//next child
    }
    String  item_name = child_name.getLocalName();
    if(!item_name.byteEqual(localname, strlen(localname)))
    {
      continue;//next child
    }
    return true;
  }
  return false;
}

bool GeoFunction::checkOptionalAttribute(zorba::Item &item, const char *name, const char *value) const
{
  Iterator_t    children;
  zorba::Item   attr_item;
  children = item.getAttributes();
  children->open();
  while(children->next(attr_item))
  {
    String  attr_name = attr_item.getLocalName();
    if(!attr_name.byteEqual(name, strlen(name)))
    {
      continue;//next attr
    }
    String  attr_value = attr_item.getStringValue();
    if(!attr_value.byteEqual(value, strlen(value)))
    {
      children->close();
      return false;
    }
    children->close();
    return true;
  }
  children->close();
  return true;
}

const geos::geom::GeometryFactory   *GeoFunction::get_geometryFactory() const
{
//  if(!geo_factory)
//    geo_factory = new geos::geom::GeometryFactory;
//  return geo_factory;
  return geos::geom::GeometryFactory::getDefaultInstance();
}

void GeoFunction::readPointPosCoordinates(zorba::Item &lItem, double *x, double *y) const
{
  Iterator_t    children;
  children = lItem.getChildren();
  children->open();
  bool retval = readPointPosCoordinates(children, x, y);
  children->close();
  if(!retval)
  {
    std::stringstream lErrorMessage;
    lErrorMessage << "gml node must have a gml:pos child";
    throwError(lErrorMessage.str(), XPTY0004);
  }
}
bool GeoFunction::readPointPosCoordinates(zorba::Iterator_t children, double *x, double *y) const
{
  zorba::Item   pos_item;
  if(!getChild(children, "pos", "http://www.opengis.net/gml", pos_item))
  {//get upset
    //std::stringstream lErrorMessage;
    //lErrorMessage << "gml:Point node must have a gml:pos child";
    //throwError(lErrorMessage.str(), XPTY0004);
    return false;
  }

  String    pos_string;
  pos_string = pos_item.getStringValue();
  *x = 0;
  *y = 0;
  const char *str = pos_string.c_str();
  while(((*str == ' ') ||
        (*str == '\t') ||
        (*str == '\n') ||
        (*str == '\r')) &&
        (*str != 0))
     str++;
  sscanf(str, "%lf", x);
  while((*str != ' ') &&
        (*str != '\t') &&
        (*str != '\n') &&
        (*str != '\r') &&
        (*str != 0))
     str++;
  while(((*str == ' ') ||
      (*str == '\t') ||
      (*str == '\n') ||
      (*str == '\r')) &&
      (*str != 0))
     str++;
  sscanf(str, "%lf", y);
  return true;
}

void GeoFunction::readPosListCoordinates(zorba::Item &lItem, geos::geom::CoordinateSequence *cl) const
{
  zorba::Item   poslist_item;
  if(getChild(lItem, "posList", "http://www.opengis.net/gml", poslist_item))
  {
    String    poslist_string;
    poslist_string = poslist_item.getStringValue();
    double x, y;
    bool load_x = true;
    const char *str_poslist = poslist_string.c_str();
    while(((*str_poslist == ' ') ||
          (*str_poslist == '\t') ||
          (*str_poslist == '\n') ||
          (*str_poslist == '\r')) &&
          (*str_poslist != 0))
       str_poslist++;
    x = 0; y = 0;
    while(str_poslist[0])
    {
      if(load_x)
        x = atof(str_poslist);
      else
      {
        y = atof(str_poslist);
        cl->add(geos::geom::Coordinate(x, y));
        x = 0; y = 0;
      }
      load_x = !load_x;
      while((*str_poslist != ' ') &&
            (*str_poslist != '\t') &&
            (*str_poslist != '\n') &&
            (*str_poslist != '\r') &&
            (*str_poslist != 0))
         str_poslist++;
      while(((*str_poslist == ' ') ||
          (*str_poslist == '\t') ||
          (*str_poslist == '\n') ||
          (*str_poslist == '\r')) &&
          (*str_poslist != 0))
         str_poslist++;
    }
  }
  else if(getChild(lItem, "pos", "http://www.opengis.net/gml", poslist_item))
  {
    Iterator_t    children;
    children = lItem.getChildren();
    children->open();
    double x = 0, y = 0;
    while(readPointPosCoordinates(children, &x, &y))
    {
      cl->add(geos::geom::Coordinate(x, y));
    }
    children->close();
  }
  else
  {//get upset
    std::stringstream lErrorMessage;
    lErrorMessage << lItem.getLocalName() << " node must have a gml:posList child";
    throwError(lErrorMessage.str(), XPTY0004);
  }
}

geos::geom::Geometry  *GeoFunction::buildGeosGeometryFromItem(zorba::Item &lItem, enum GeoFunction::gmlsf_types geometric_type) const
{
  switch(geometric_type)
  {
  case GMLSF_POINT:
  {
    double x, y;
    readPointPosCoordinates(lItem, &x, &y);
  	geos::geom::Coordinate c(x, y);
    return get_geometryFactory()->createPoint(c);
  }
  case GMLSF_LINESTRING:
  {
    geos::geom::CoordinateSequence *cl = new geos::geom::CoordinateArraySequence();
    readPosListCoordinates(lItem, cl);
    return get_geometryFactory()->createLineString(cl);
  }
  case GMLSF_CURVE:
  {  //not supported in GEOS; emulate through Geometry Collection
    zorba::Item   segments_item;
    if(!getChild(lItem, "segments", "http://www.opengis.net/gml", segments_item))
    {//get upset
      std::stringstream lErrorMessage;
      lErrorMessage << "gml:Curve node must have a gml:segments child";
      throwError(lErrorMessage.str(), XPTY0004);
    }
    Iterator_t    segments_children;
    Item          line_segment_item;
    std::vector<geos::geom::Geometry*>    *segments_vector = new std::vector<geos::geom::Geometry*>;
    segments_children = segments_item.getChildren();
    segments_children->open();
    while(segments_children->next(line_segment_item))
    {
      if(line_segment_item.getNodeKind() != store::StoreConsts::elementNode)
        continue;
      Item    item_qname;
      line_segment_item.getNodeName(item_qname);
      String  item_namespace = item_qname.getNamespace();
      if(!item_namespace.byteEqual("http://www.opengis.net/gml", 26))
      {
        std::stringstream lErrorMessage;
        lErrorMessage << "Children of gml:Curve/gml:segments must be of type gml:LineStringSegment only";
        throwError(lErrorMessage.str(), XPTY0004);
      }
      String  local_name = item_qname.getLocalName();
      if(!local_name.byteEqual("LineStringSegment", 17))
      {
        std::stringstream lErrorMessage;
        lErrorMessage << "Children of gml:Curve/gml:segments must be of type gml:LineStringSegment only";
        throwError(lErrorMessage.str(), XPTY0004);
      }
      if(!checkOptionalAttribute(line_segment_item, "interpolation", "linear"))
      {
        std::stringstream lErrorMessage;
        lErrorMessage << "gml:Curve/gml:segments/gml:LineStringSegment supports only linear interpolation";
        throwError(lErrorMessage.str(), XPTY0004);
      }
  	  
      segments_vector->push_back(buildGeosGeometryFromItem(line_segment_item, GMLSF_LINESTRING));
    }

    return get_geometryFactory()->createGeometryCollection(segments_vector);
  }
  case GMLSF_LINEARRING:
  {
    geos::geom::CoordinateSequence *cl = new geos::geom::CoordinateArraySequence();
    readPosListCoordinates(lItem, cl);
    return get_geometryFactory()->createLinearRing(cl);
  }
  case GMLSF_SURFACE:
  {  //not supported in GEOS; emulate through Geometry Collection
    zorba::Item   patches_item;
    if(!getChild(lItem, "patches", "http://www.opengis.net/gml", patches_item))
    {//get upset
      std::stringstream lErrorMessage;
      lErrorMessage << "gml:Surface node must have a gml:patches child";
      throwError(lErrorMessage.str(), XPTY0004);
    }
    Iterator_t    patches_children;
    Item          polygon_patch_item;
    std::vector<geos::geom::Geometry*>    *polygon_vector = new std::vector<geos::geom::Geometry*>;
    patches_children = patches_item.getChildren();
    patches_children->open();
    while(patches_children->next(polygon_patch_item))
    {
      if(polygon_patch_item.getNodeKind() != store::StoreConsts::elementNode)
        continue;
      Item    item_qname;
      polygon_patch_item.getNodeName(item_qname);
      String  item_namespace = item_qname.getNamespace();
      if(!item_namespace.byteEqual("http://www.opengis.net/gml", 26))
      {
        std::stringstream lErrorMessage;
        lErrorMessage << "Children of gml:Surface/gml:patches must be of type gml:PolygonPatch only";
        throwError(lErrorMessage.str(), XPTY0004);
      }
      String  item_name = item_qname.getLocalName();
      if(!item_name.byteEqual("PolygonPatch", 12))
      {
        std::stringstream lErrorMessage;
        lErrorMessage << "Children of gml:Surface/gml:patches must be of type gml:PolygonPatch only";
        throwError(lErrorMessage.str(), XPTY0004);
      }

      polygon_vector->push_back(buildGeosGeometryFromItem(polygon_patch_item, GMLSF_POLYGON));
    }

    return get_geometryFactory()->createGeometryCollection(polygon_vector);
  }
  case GMLSF_POLYGON:
  {
    Iterator_t    polygon_children;
    Item          extint_item;
    int           nr_child = 0;
    geos::geom::LinearRing    *exterior;
    std::vector<geos::geom::Geometry*>    *interior_vector = new std::vector<geos::geom::Geometry*>;
    polygon_children = lItem.getChildren();
    polygon_children->open();
    while(polygon_children->next(extint_item))
    {
      if(extint_item.getNodeKind() != store::StoreConsts::elementNode)
        continue;
      Item    item_qname;
      extint_item.getNodeName(item_qname);
      String  item_namespace = item_qname.getNamespace();
      if(!item_namespace.byteEqual("http://www.opengis.net/gml", 26))
      {
        std::stringstream lErrorMessage;
        lErrorMessage << "Children of gml:Polygon must be gml:exterior or gml:interior";
        throwError(lErrorMessage.str(), XPTY0004);
      }
      String  item_name = item_qname.getLocalName();
      if(nr_child == 0)
      {
        if(!item_name.byteEqual("exterior", 8))
        {
          std::stringstream lErrorMessage;
          lErrorMessage << "First child of gml:Polygon must be gml:exterior";
          throwError(lErrorMessage.str(), XPTY0004);
        }
        zorba::Item   linearring_item;
        if(!getChild(extint_item, "LinearRing", "http://www.opengis.net/gml", linearring_item))
        {//get upset
          std::stringstream lErrorMessage;
          lErrorMessage << "gml:Polygon/gml:exterior node must have a gml:LinearRing child";
          throwError(lErrorMessage.str(), XPTY0004);
        }
        exterior = dynamic_cast<geos::geom::LinearRing*>(buildGeosGeometryFromItem(linearring_item, GMLSF_LINEARRING));
      }
      else
      {
        if(!item_name.byteEqual("interior", 8))
        {
          std::stringstream lErrorMessage;
          lErrorMessage << "Non-first child of gml:Polygon must be gml:interior";
          throwError(lErrorMessage.str(), XPTY0004);
        }
        zorba::Item   linearring_item;
        if(!getChild(extint_item, "LinearRing", "http://www.opengis.net/gml", linearring_item))
        {//get upset
          std::stringstream lErrorMessage;
          lErrorMessage << "gml:Polygon/gml:interior node must have a gml:LinearRing child";
          throwError(lErrorMessage.str(), XPTY0004);
        }
        interior_vector->push_back(buildGeosGeometryFromItem(linearring_item, GMLSF_LINEARRING));
      }
      nr_child++;
    }
    return get_geometryFactory()->createPolygon(exterior, interior_vector);
    
  }
  case GMLSF_MULTIPOINT:
  {
    Iterator_t    multipoint_children;
    Item          point_item;
    std::vector<geos::geom::Geometry*>    *point_vector = new std::vector<geos::geom::Geometry*>;
    multipoint_children = lItem.getChildren();
    multipoint_children->open();
    while(multipoint_children->next(point_item))
    {
      if(point_item.getNodeKind() != store::StoreConsts::elementNode)
        continue;
      Item    item_qname;
      point_item.getNodeName(item_qname);
      String  item_namespace = item_qname.getNamespace();
      if(!item_namespace.byteEqual("http://www.opengis.net/gml", 26))
      {
        std::stringstream lErrorMessage;
        lErrorMessage << "Children of gml:MultiPoint must be gml:Point";
        throwError(lErrorMessage.str(), XPTY0004);
      }
      String  item_name = item_qname.getLocalName();
      if(!item_name.byteEqual("Point", 5))
      {
        std::stringstream lErrorMessage;
        lErrorMessage << "First child of gml:Polygon must be gml:Point";
        throwError(lErrorMessage.str(), XPTY0004);
      }
      point_vector->push_back(buildGeosGeometryFromItem(point_item, GMLSF_POINT));
    }
    return get_geometryFactory()->createMultiPoint(point_vector);

  }
  case GMLSF_MULTICURVE:
  {
    Iterator_t    multicurve_children;
    Item          curve_item;
    std::vector<geos::geom::Geometry*>    *curve_vector = new std::vector<geos::geom::Geometry*>;
    multicurve_children = lItem.getChildren();
    multicurve_children->open();
    while(multicurve_children->next(curve_item))
    {
      if(curve_item.getNodeKind() != store::StoreConsts::elementNode)
        continue;
      Item    item_qname;
      curve_item.getNodeName(item_qname);
      String  item_namespace = item_qname.getNamespace();
      if(!item_namespace.byteEqual("http://www.opengis.net/gml", 26))
      {
        std::stringstream lErrorMessage;
        lErrorMessage << "Children of gml:MultiCurve must be gml:LineString";
        throwError(lErrorMessage.str(), XPTY0004);
      }
      String  item_name = item_qname.getLocalName();
      if(!item_name.byteEqual("LineString", 10))
      {
        std::stringstream lErrorMessage;
        lErrorMessage << "Children of gml:MultiCurve must be gml:LineString";
        throwError(lErrorMessage.str(), XPTY0004);
      }
      curve_vector->push_back(buildGeosGeometryFromItem(curve_item, GMLSF_LINESTRING));
    }
    return get_geometryFactory()->createMultiLineString(curve_vector);

  }
  case GMLSF_MULTISURFACE:
  {
    Iterator_t    multisurface_children;
    Item          surface_item;
    std::vector<geos::geom::Geometry*>    *surface_vector = new std::vector<geos::geom::Geometry*>;
    multisurface_children = lItem.getChildren();
    multisurface_children->open();
    while(multisurface_children->next(surface_item))
    {
      if(surface_item.getNodeKind() != store::StoreConsts::elementNode)
        continue;
      Item    item_qname;
      surface_item.getNodeName(item_qname);
      String  item_namespace = item_qname.getNamespace();
      if(!item_namespace.byteEqual("http://www.opengis.net/gml", 26))
      {
        std::stringstream lErrorMessage;
        lErrorMessage << "Children of gml:MultiSurface must be gml:Polygon";
        throwError(lErrorMessage.str(), XPTY0004);
      }
      String  item_name = item_qname.getLocalName();
      if(!item_name.byteEqual("Polygon", 7))
      {
        std::stringstream lErrorMessage;
        lErrorMessage << "Children of gml:MultiSurface must be gml:Polygon";
        throwError(lErrorMessage.str(), XPTY0004);
      }
      surface_vector->push_back(buildGeosGeometryFromItem(surface_item, GMLSF_POLYGON));
    }
    return get_geometryFactory()->createMultiPolygon(surface_vector);

  }
  case GMLSF_INVALID:
  default:
  {
    std::stringstream lErrorMessage;
    lErrorMessage << "Unrecognized geometric type for element " 
         << lItem.getPrefix() <<":"<<lItem.getLocalName() << ".";
    throwError(lErrorMessage.str(), XPTY0004);
  }
  break;
  }

  return NULL;
}

zorba::Item GeoFunction::getGMLItemFromGeosGeometry(zorba::Item &parent, 
                                                    const geos::geom::Geometry *geos_geometry,
                                                    const char *tag_name) const
{
  zorba::Item   result_item;
  zorba::Item   item_name;
  zorba::Item   item_type;
  std::vector<std::pair<String, String> >   ns_binding;
  ns_binding.push_back(std::pair<String, String>("gml", "http://www.opengis.net/gml"));
  item_type = theModule->getItemFactory()->createQName("http://www.w3.org/2001/XMLSchema", "untyped");

  switch(geos_geometry->getGeometryTypeId())
  {
  case 	geos::geom::GEOS_POINT:
  {
      item_name = theModule->getItemFactory()->createQName("http://www.opengis.net/gml", "gml", "Point");
      result_item = theModule->getItemFactory()->createElementNode(parent, item_name, item_type, false, false, ns_binding);

      zorba::Item pos_item;
      item_type = theModule->getItemFactory()->createQName("http://www.w3.org/2001/XMLSchema", "untyped");
      item_name = theModule->getItemFactory()->createQName("http://www.opengis.net/gml", "gml", "pos");
      pos_item = theModule->getItemFactory()->createElementNode(result_item, item_name, item_type, false, false, ns_binding);
      
      char strtemp[100];
      const geos::geom::Coordinate  *c;
      c = geos_geometry->getCoordinate();
      sprintf(strtemp, "%lf %lf", c->x, c->y);

      zorba::Item text_item;
      text_item = theModule->getItemFactory()->createTextNode(pos_item, strtemp);
      return result_item;
  }
	/// a linestring
  case geos::geom::GEOS_LINESTRING:
	/// a linear ring (linestring with 1st point == last point)
  case geos::geom::GEOS_LINEARRING:
  {
    item_name = theModule->getItemFactory()->createQName("http://www.opengis.net/gml", "gml", 
      tag_name ? tag_name : ((geos_geometry->getGeometryTypeId() == geos::geom::GEOS_LINESTRING) ? "LineString" : "LinearRing"));
    result_item = theModule->getItemFactory()->createElementNode(parent, item_name, item_type, false, false, ns_binding);

    zorba::Item pos_item;
    item_type = theModule->getItemFactory()->createQName("http://www.w3.org/2001/XMLSchema", "untyped");
    item_name = theModule->getItemFactory()->createQName("http://www.opengis.net/gml", "gml", "posList");
    pos_item = theModule->getItemFactory()->createElementNode(result_item, item_name, item_type, false, false, ns_binding);
    
    char *strtemp;
    geos::geom::CoordinateSequence  *cs;
    cs = geos_geometry->getCoordinates();
    size_t    cs_size = cs->getSize();
    strtemp = (char*)malloc(50*cs_size + 1);
    strtemp[0] = 0;
    char  *strtemp2 = strtemp;
    sprintf(strtemp2, "\n");
    strtemp2 += strlen(strtemp2);
    for(size_t i=0;i<cs_size;i++)
    {
      sprintf(strtemp2, "%lf %lf\n", cs->getAt(i).x, cs->getAt(i).y);
      strtemp2 += strlen(strtemp2);
    }

    zorba::Item text_item;
    text_item = theModule->getItemFactory()->createTextNode(pos_item, strtemp);
    return result_item;
  }
	/// a polygon
  case geos::geom::GEOS_POLYGON:
  {
    item_name = theModule->getItemFactory()->createQName("http://www.opengis.net/gml", "gml", tag_name ? tag_name : "Polygon");
    result_item = theModule->getItemFactory()->createElementNode(parent, item_name, item_type, false, false, ns_binding);

    const geos::geom::LineString*   exterior_ring;
    const geos::geom::Polygon   *polygon = dynamic_cast<const geos::geom::Polygon*>(geos_geometry);
    exterior_ring = polygon->getExteriorRing();
    if(exterior_ring)
    {
      zorba::Item exterior_item;
      item_type = theModule->getItemFactory()->createQName("http://www.w3.org/2001/XMLSchema", "untyped");
      item_name = theModule->getItemFactory()->createQName("http://www.opengis.net/gml", "gml", "exterior");
      exterior_item = theModule->getItemFactory()->createElementNode(result_item, item_name, item_type, false, false, ns_binding);
      getGMLItemFromGeosGeometry(exterior_item, exterior_ring);
    }
    size_t interior_rings = polygon->getNumInteriorRing();
    for(size_t i=0;i<interior_rings;i++)
    {
      const geos::geom::LineString*   interior_ring;
      interior_ring = polygon->getInteriorRingN(i);

      zorba::Item interior_item;
      item_type = theModule->getItemFactory()->createQName("http://www.w3.org/2001/XMLSchema", "untyped");
      item_name = theModule->getItemFactory()->createQName("http://www.opengis.net/gml", "gml", "interior");
      interior_item = theModule->getItemFactory()->createElementNode(result_item, item_name, item_type, false, false, ns_binding);
      getGMLItemFromGeosGeometry(interior_item, interior_ring);
    }
    return result_item;
  }
	/// a collection of points
  case geos::geom::GEOS_MULTIPOINT:
  {
    item_name = theModule->getItemFactory()->createQName("http://www.opengis.net/gml", "gml", "MultiPoint");
    result_item = theModule->getItemFactory()->createElementNode(parent, item_name, item_type, false, false, ns_binding);

    size_t    nr_geoms = geos_geometry->getNumGeometries();
    for(size_t i=0;i<nr_geoms;i++)
    {
      const geos::geom::Geometry  *point;
      point = geos_geometry->getGeometryN(i);
      getGMLItemFromGeosGeometry(result_item, point);
    }
    return result_item;
  }
	/// a collection of linestrings
  case geos::geom::GEOS_MULTILINESTRING:
  {
    item_name = theModule->getItemFactory()->createQName("http://www.opengis.net/gml", "gml", "MultiCurve");
    result_item = theModule->getItemFactory()->createElementNode(parent, item_name, item_type, false, false, ns_binding);

    size_t    nr_geoms = geos_geometry->getNumGeometries();
    for(size_t i=0;i<nr_geoms;i++)
    {
      const geos::geom::Geometry  *linestring;
      linestring = geos_geometry->getGeometryN(i);
      getGMLItemFromGeosGeometry(result_item, linestring);
    }
    return result_item;
  }
	/// a collection of polygons
  case geos::geom::GEOS_MULTIPOLYGON:
  {
    item_name = theModule->getItemFactory()->createQName("http://www.opengis.net/gml", "gml", "MultiSurface");
    result_item = theModule->getItemFactory()->createElementNode(parent, item_name, item_type, false, false, ns_binding);

    size_t    nr_geoms = geos_geometry->getNumGeometries();
    for(size_t i=0;i<nr_geoms;i++)
    {
      const geos::geom::Geometry  *polygon;
      polygon = geos_geometry->getGeometryN(i);
      getGMLItemFromGeosGeometry(result_item, polygon);
    }
    return result_item;
  }
	/// a collection of heterogeneus geometries
  case geos::geom::GEOS_GEOMETRYCOLLECTION:
  {
    //can be either gml:Surface or gml:Curve
    size_t    nr_geoms = geos_geometry->getNumGeometries();
    if(!nr_geoms)
      break;//unreachable
    //if all childs are LineString then it is gml:Curve
    //if all childs are Polygon then it is gml:Surface
    bool is_curve = true;
    bool is_surface = true;
    size_t    i;
    for(i=0;i<nr_geoms;i++)
    {
      const geos::geom::Geometry *child;
      child = geos_geometry->getGeometryN(i);
      if(child->getGeometryTypeId() != geos::geom::GEOS_POLYGON)
        is_surface = false;
      if(child->getGeometryTypeId() != geos::geom::GEOS_LINESTRING)
        is_curve = false;
    }
    if(is_curve)
    {
      item_name = theModule->getItemFactory()->createQName("http://www.opengis.net/gml", "gml", "Curve");
      result_item = theModule->getItemFactory()->createElementNode(parent, item_name, item_type, false, false, ns_binding);
      zorba::Item segments_item;
      item_type = theModule->getItemFactory()->createQName("http://www.w3.org/2001/XMLSchema", "untyped");
      item_name = theModule->getItemFactory()->createQName("http://www.opengis.net/gml", "gml", "segments");
      segments_item = theModule->getItemFactory()->createElementNode(result_item, item_name, item_type, false, false, ns_binding);

      size_t    nr_geoms = geos_geometry->getNumGeometries();
      for(size_t i=0;i<nr_geoms;i++)
      {
        const geos::geom::Geometry  *linestring;
        linestring = geos_geometry->getGeometryN(i);

        zorba::Item   linestring_item;
        linestring_item = getGMLItemFromGeosGeometry(segments_item, linestring, "LineStringSegment");

        zorba::Item attr_value_item;
        item_type = theModule->getItemFactory()->createQName("http://www.w3.org/2001/XMLSchema", "untyped");
        item_name = theModule->getItemFactory()->createQName("http://www.opengis.net/gml", "gml", "interpolation");
        zorba::String   strvalue("liniar");
        attr_value_item = theModule->getItemFactory()->createString(strvalue);
        theModule->getItemFactory()->createAttributeNode(linestring_item, item_name, item_type, attr_value_item);
      }
      return result_item;
    }
    else if(is_surface)
    {
      item_name = theModule->getItemFactory()->createQName("http://www.opengis.net/gml", "gml", "Surface");
      result_item = theModule->getItemFactory()->createElementNode(parent, item_name, item_type, false, false, ns_binding);
      zorba::Item patches_item;
      item_type = theModule->getItemFactory()->createQName("http://www.w3.org/2001/XMLSchema", "untyped");
      item_name = theModule->getItemFactory()->createQName("http://www.opengis.net/gml", "gml", "patches");
      patches_item = theModule->getItemFactory()->createElementNode(result_item, item_name, item_type, false, false, ns_binding);

      size_t    nr_geoms = geos_geometry->getNumGeometries();
      for(size_t i=0;i<nr_geoms;i++)
      {
        const geos::geom::Geometry  *polygon;
        polygon = geos_geometry->getGeometryN(i);

        zorba::Item   polygon_item;
        polygon_item = getGMLItemFromGeosGeometry(patches_item, polygon, "PolygonPatch");
      }
      return result_item;
    }
    else
    {
      std::stringstream lErrorMessage;
      lErrorMessage << "Geometry Collections are not supported in GMLSF";
      throwError(lErrorMessage.str(), XPTY0004);
    }
  }
  default:
  {
    std::stringstream lErrorMessage;
    lErrorMessage << "Geometry type " << geos_geometry->getGeometryType() << " is not supported";
    throwError(lErrorMessage.str(), XPTY0004);
  }
  }

  return result_item;
}


///////////////////////////////////////////////////////////////////////
ItemSequence_t 
SFDimensionFunction::evaluate(const StatelessExternalFunction::Arguments_t& args,
         const StaticContext* aSctxCtx,
         const DynamicContext* aDynCtx) const
{
  Item lItem;
  gmlsf_types   geometric_type;
  geometric_type = getGeometryNodeType(args, 0, lItem);

  int   nr_dim = -1;
  switch(geometric_type)
  {
  case GMLSF_POINT:
    nr_dim = 0;break;
  case GMLSF_LINESTRING:
  case GMLSF_CURVE:
    nr_dim = 1;break;
  case GMLSF_LINEARRING:
  case GMLSF_SURFACE:
  case GMLSF_POLYGON:
    nr_dim = 2;break;
  case GMLSF_MULTIPOINT:
    nr_dim = 0;break;
  case GMLSF_MULTICURVE:
    nr_dim = 1;break;
  case GMLSF_MULTISURFACE:
    nr_dim = 2;break;

  case GMLSF_INVALID:
  default:
    {
      std::stringstream lErrorMessage;
      lErrorMessage << "Unrecognized geometric type for element " 
           << lItem.getPrefix() <<":"<<lItem.getLocalName() << ".";
      throwError(lErrorMessage.str(), XPTY0004);
    }
    break;
  }

  return ItemSequence_t(new SingletonItemSequence(
      theModule->getItemFactory()->createInteger(nr_dim)));
}

///////////////////////////////////////////////////////////////////////
ItemSequence_t 
SFCoordinateDimensionFunction::evaluate(const StatelessExternalFunction::Arguments_t& args,
         const StaticContext* aSctxCtx,
         const DynamicContext* aDynCtx) const
{
  Item lItem;
  gmlsf_types   geometric_type;
  geometric_type = getGeometryNodeType(args, 0, lItem);

  switch(geometric_type)
  {
  case GMLSF_INVALID:
    {
      std::stringstream lErrorMessage;
      lErrorMessage << "Unrecognized geometric type for element " 
           << lItem.getPrefix() <<":"<<lItem.getLocalName() << ".";
      throwError(lErrorMessage.str(), XPTY0004);
    }
    break;
  default:
    break;
  }

  return ItemSequence_t(new SingletonItemSequence(
      theModule->getItemFactory()->createInteger(2)));//hardcode the coordinate sistem for 2D
}

///////////////////////////////////////////////////////////////////////
ItemSequence_t 
SFGeometryTypeFunction::evaluate(const StatelessExternalFunction::Arguments_t& args,
         const StaticContext* aSctxCtx,
         const DynamicContext* aDynCtx) const
{
  Item lItem;
  gmlsf_types   geometric_type;
  geometric_type = getGeometryNodeType(args, 0, lItem);

  zorba::String type_string;
  switch(geometric_type)
  {
  case GMLSF_POINT:
   type_string = "Point";break;
  case GMLSF_LINESTRING:
   type_string = "LineString";break;
  case GMLSF_CURVE:
   type_string = "Curve";break;
  case GMLSF_LINEARRING:
   type_string = "LinearRing";break;
  case GMLSF_SURFACE:
   type_string = "Surface";break;
  case GMLSF_POLYGON:
   type_string = "Polygon";break;
  case GMLSF_MULTIPOINT:
   type_string = "MultiPoint";break;
  case GMLSF_MULTICURVE:
   type_string = "MultiCurve";break;
  case GMLSF_MULTISURFACE:
   type_string = "MultiSurface";break;

  case GMLSF_INVALID:
  default:
    {
      std::stringstream lErrorMessage;
      lErrorMessage << "Unrecognized geometric type for element " 
           << lItem.getPrefix() <<":"<<lItem.getLocalName() << ".";
      throwError(lErrorMessage.str(), XPTY0004);
    }
    break;
  }

  return ItemSequence_t(new SingletonItemSequence(
      theModule->getItemFactory()->createString(type_string)));
}

///////////////////////////////////////////////////////////////////////
#define DEFINE_EVALUATE_ONE_GEOMETRY_RETURN_GEOMETRY(sfclass_name, geos_function_name)  \
ItemSequence_t                                                                          \
sfclass_name::evaluate(const StatelessExternalFunction::Arguments_t& args,              \
         const StaticContext* aSctxCtx,                                                 \
         const DynamicContext* aDynCtx) const                                           \
{                                                                                       \
  Item lItem;                                                                           \
  gmlsf_types   geometric_type;                                                         \
  geometric_type = getGeometryNodeType(args, 0, lItem);                                 \
                                                                                        \
  switch(geometric_type)                                                                \
  {                                                                                     \
  case GMLSF_INVALID:                                                                   \
    {                                                                                   \
      std::stringstream lErrorMessage;                                                  \
      lErrorMessage << "Unrecognized geometric type for element "                       \
           << lItem.getPrefix() <<":"<<lItem.getLocalName() << ".";                     \
      throwError(lErrorMessage.str(), XPTY0004);                                        \
    }                                                                                   \
    break;                                                                              \
  default:                                                                              \
    break;                                                                              \
  }                                                                                     \
                                                                                        \
  geos::geom::Geometry  *geos_geometry;                                                 \
  geos_geometry = buildGeosGeometryFromItem(lItem, geometric_type);                     \
                                                                                        \
  geos::geom::Geometry  *geos_result;                                                   \
  geos_result = geos_geometry->geos_function_name();                                    \
                                                                                        \
  zorba::Item   null_parent;                                                            \
  zorba::Item   result_item;                                                            \
  result_item = getGMLItemFromGeosGeometry(null_parent, geos_result);                   \
  delete geos_geometry;                                                                 \
  delete geos_result;                                                                   \
                                                                                        \
  return ItemSequence_t(new SingletonItemSequence(result_item));                        \
}

DEFINE_EVALUATE_ONE_GEOMETRY_RETURN_GEOMETRY(SFEnvelopeFunction, getEnvelope)
DEFINE_EVALUATE_ONE_GEOMETRY_RETURN_GEOMETRY(SFBoundaryFunction, getBoundary)
DEFINE_EVALUATE_ONE_GEOMETRY_RETURN_GEOMETRY(SFConvexHullFunction, convexHull)
DEFINE_EVALUATE_ONE_GEOMETRY_RETURN_GEOMETRY(SFCentroidFunction, getCentroid)
DEFINE_EVALUATE_ONE_GEOMETRY_RETURN_GEOMETRY(SFInteriorPointFunction, getInteriorPoint)

///////////////////////////////////////////////////////////////////////
ItemSequence_t 
SFAsTextFunction::evaluate(const StatelessExternalFunction::Arguments_t& args,
         const StaticContext* aSctxCtx,
         const DynamicContext* aDynCtx) const
{
  Item lItem;
  gmlsf_types   geometric_type;
  geometric_type = getGeometryNodeType(args, 0, lItem);

  switch(geometric_type)
  {
  case GMLSF_INVALID:
    {
      std::stringstream lErrorMessage;
      lErrorMessage << "Unrecognized geometric type for element " 
           << lItem.getPrefix() <<":"<<lItem.getLocalName() << ".";
      throwError(lErrorMessage.str(), XPTY0004);
    }
    break;
  default:
    break;
  }

  geos::geom::Geometry  *geos_geometry;
  geos_geometry = buildGeosGeometryFromItem(lItem, geometric_type);

  std::string as_text;
  as_text = geos_geometry->toString();
  delete geos_geometry;

  return ItemSequence_t(new SingletonItemSequence(
      theModule->getItemFactory()->createString(as_text)));
}

///////////////////////////////////////////////////////////////////////
ItemSequence_t 
SFAsBinaryFunction::evaluate(const StatelessExternalFunction::Arguments_t& args,
         const StaticContext* aSctxCtx,
         const DynamicContext* aDynCtx) const
{
  Item lItem;
  gmlsf_types   geometric_type;
  geometric_type = getGeometryNodeType(args, 0, lItem);

  switch(geometric_type)
  {
  case GMLSF_INVALID:
    {
      std::stringstream lErrorMessage;
      lErrorMessage << "Unrecognized geometric type for element " 
           << lItem.getPrefix() <<":"<<lItem.getLocalName() << ".";
      throwError(lErrorMessage.str(), XPTY0004);
    }
    break;
  default:
    break;
  }

  geos::geom::Geometry  *geos_geometry;
  geos_geometry = buildGeosGeometryFromItem(lItem, geometric_type);

  std::ostringstream as_binary;
  as_binary << *geos_geometry;
  delete geos_geometry;

  return ItemSequence_t(new SingletonItemSequence(
      theModule->getItemFactory()->createString(as_binary.str())));
}

///////////////////////////////////////////////////////////////////////
ItemSequence_t 
SFIsEmptyFunction::evaluate(const StatelessExternalFunction::Arguments_t& args,
         const StaticContext* aSctxCtx,
         const DynamicContext* aDynCtx) const
{
  Item lItem;
  if (!args[0]->next(lItem)) 
  {
    return ItemSequence_t(new SingletonItemSequence(
       theModule->getItemFactory()->createBoolean(true)));
  }

  if(!lItem.isNode() || (lItem.getNodeKind() != store::StoreConsts::elementNode))
  {
    return ItemSequence_t(new SingletonItemSequence(
       theModule->getItemFactory()->createBoolean(true)));
  }

  GeoFunction::gmlsf_types geotype = getGmlSFGeometricType(lItem);

  return ItemSequence_t(new SingletonItemSequence(
     theModule->getItemFactory()->createBoolean(geotype == GMLSF_INVALID)));
}

///////////////////////////////////////////////////////////////////////
ItemSequence_t 
SFIsSimpleFunction::evaluate(const StatelessExternalFunction::Arguments_t& args,
         const StaticContext* aSctxCtx,
         const DynamicContext* aDynCtx) const
{
  Item lItem;
  gmlsf_types   geometric_type;
  geometric_type = getGeometryNodeType(args, 0, lItem);

  switch(geometric_type)
  {
  case GMLSF_INVALID:
    {
      std::stringstream lErrorMessage;
      lErrorMessage << "Unrecognized geometric type for element " 
           << lItem.getPrefix() <<":"<<lItem.getLocalName() << ".";
      throwError(lErrorMessage.str(), XPTY0004);
    }
    break;
  default:
    break;
  }

  geos::geom::Geometry  *geos_geometry;
  geos_geometry = buildGeosGeometryFromItem(lItem, geometric_type);

  bool is_simple;
  is_simple = geos_geometry->isSimple();
  delete geos_geometry;

  return ItemSequence_t(new SingletonItemSequence(
     theModule->getItemFactory()->createBoolean(is_simple)));
}

///////////////////////////////////////////////////////////////////////
ItemSequence_t 
SFIs3DFunction::evaluate(const StatelessExternalFunction::Arguments_t& args,
         const StaticContext* aSctxCtx,
         const DynamicContext* aDynCtx) const
{
  Item lItem;
  gmlsf_types   geometric_type;
  geometric_type = getGeometryNodeType(args, 0, lItem);

  switch(geometric_type)
  {
  case GMLSF_INVALID:
    {
      std::stringstream lErrorMessage;
      lErrorMessage << "Unrecognized geometric type for element " 
           << lItem.getPrefix() <<":"<<lItem.getLocalName() << ".";
      throwError(lErrorMessage.str(), XPTY0004);
    }
    break;
  default:
    break;
  }

  geos::geom::Geometry  *geos_geometry;
  geos_geometry = buildGeosGeometryFromItem(lItem, geometric_type);

  //To Be Implemented; now is only 2D
  delete geos_geometry;

  return ItemSequence_t(new SingletonItemSequence(
     theModule->getItemFactory()->createBoolean(false)));
}

///////////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////////////
#define DEFINE_EVALUATE_TWO_GEOMETRIES_RETURN_BOOLEAN(sfclass_name, geos_function_name)  \
ItemSequence_t                                                                    \
sfclass_name::evaluate(const StatelessExternalFunction::Arguments_t& args,        \
         const StaticContext* aSctxCtx,                                           \
         const DynamicContext* aDynCtx) const                                     \
{                                                                                 \
  Item lItem1;                                                                    \
  gmlsf_types   geometric_type1;                                                  \
  geometric_type1 = getGeometryNodeType(args, 0, lItem1);                         \
                                                                                  \
  switch(geometric_type1)                                                         \
  {                                                                               \
  case GMLSF_INVALID:                                                             \
    {                                                                             \
      std::stringstream lErrorMessage;                                            \
      lErrorMessage << "Unrecognized geometric type for element "                 \
           << lItem1.getPrefix() <<":"<<lItem1.getLocalName() << " in first parameter.";    \
      throwError(lErrorMessage.str(), XPTY0004);                                  \
    }                                                                             \
    break;                                                                        \
  default:                                                                        \
    break;                                                                        \
  }                                                                               \
                                                                                  \
  Item lItem2;                                                                    \
  gmlsf_types   geometric_type2;                                                  \
  geometric_type2 = getGeometryNodeType(args, 1, lItem2);                         \
                                                                                  \
  switch(geometric_type2)                                                         \
  {                                                                               \
  case GMLSF_INVALID:                                                             \
    {                                                                             \
      std::stringstream lErrorMessage;                                            \
      lErrorMessage << "Unrecognized geometric type for element "                 \
           << lItem2.getPrefix() <<":"<<lItem2.getLocalName() << " in second parameter.";   \
      throwError(lErrorMessage.str(), XPTY0004);                                  \
    }                                                                             \
    break;                                                                        \
  default:                                                                        \
    break;                                                                        \
  }                                                                               \
                                                                                  \
  geos::geom::Geometry  *geos_geometry1;                                          \
  geos_geometry1 = buildGeosGeometryFromItem(lItem1, geometric_type1);            \
                                                                                  \
  geos::geom::Geometry  *geos_geometry2;                                          \
  geos_geometry2 = buildGeosGeometryFromItem(lItem2, geometric_type2);            \
                                                                                  \
  bool retval;                                                                    \
  retval = geos_geometry1->geos_function_name(geos_geometry2);                    \
                                                                                  \
  delete geos_geometry1;                                                          \
  delete geos_geometry2;                                                          \
                                                                                  \
  return ItemSequence_t(new SingletonItemSequence(                                \
     theModule->getItemFactory()->createBoolean(retval)));                        \
}

DEFINE_EVALUATE_TWO_GEOMETRIES_RETURN_BOOLEAN(SFEqualsFunction, equals)
DEFINE_EVALUATE_TWO_GEOMETRIES_RETURN_BOOLEAN(SFCoversFunction, covers)
DEFINE_EVALUATE_TWO_GEOMETRIES_RETURN_BOOLEAN(SFDisjointFunction, disjoint)
DEFINE_EVALUATE_TWO_GEOMETRIES_RETURN_BOOLEAN(SFIntersectsFunction, intersects)
DEFINE_EVALUATE_TWO_GEOMETRIES_RETURN_BOOLEAN(SFTouchesFunction, touches)
DEFINE_EVALUATE_TWO_GEOMETRIES_RETURN_BOOLEAN(SFCrossesFunction, crosses)
DEFINE_EVALUATE_TWO_GEOMETRIES_RETURN_BOOLEAN(SFWithinFunction, within)
DEFINE_EVALUATE_TWO_GEOMETRIES_RETURN_BOOLEAN(SFContainsFunction, contains)
DEFINE_EVALUATE_TWO_GEOMETRIES_RETURN_BOOLEAN(SFOverlapsFunction, overlaps)

///////////////////////////////////////////////////////////////////////
#define DEFINE_EVALUATE_TWO_GEOMETRIES_RETURN_GEOMETRY(sfclass_name, geos_function_name)  \
ItemSequence_t                                                                    \
sfclass_name::evaluate(const StatelessExternalFunction::Arguments_t& args,        \
         const StaticContext* aSctxCtx,                                           \
         const DynamicContext* aDynCtx) const                                     \
{                                                                                 \
  Item lItem1;                                                                    \
  gmlsf_types   geometric_type1;                                                  \
  geometric_type1 = getGeometryNodeType(args, 0, lItem1);                         \
                                                                                  \
  switch(geometric_type1)                                                          \
  {                                                                               \
  case GMLSF_INVALID:                                                             \
    {                                                                             \
      std::stringstream lErrorMessage;                                            \
      lErrorMessage << "Unrecognized geometric type for element "                 \
           << lItem1.getPrefix() <<":"<<lItem1.getLocalName() << " in first parameter.";    \
      throwError(lErrorMessage.str(), XPTY0004);                                  \
    }                                                                             \
    break;                                                                        \
  default:                                                                        \
    break;                                                                        \
  }                                                                               \
                                                                                  \
  Item lItem2;                                                                    \
  gmlsf_types   geometric_type2;                                                  \
  geometric_type2 = getGeometryNodeType(args, 1, lItem2);                         \
                                                                                  \
  switch(geometric_type2)                                                          \
  {                                                                               \
  case GMLSF_INVALID:                                                             \
    {                                                                             \
      std::stringstream lErrorMessage;                                            \
      lErrorMessage << "Unrecognized geometric type for element "                 \
           << lItem2.getPrefix() <<":"<<lItem2.getLocalName() << " in second parameter.";   \
      throwError(lErrorMessage.str(), XPTY0004);                                  \
    }                                                                             \
    break;                                                                        \
  default:                                                                        \
    break;                                                                        \
  }                                                                               \
                                                                                  \
  geos::geom::Geometry  *geos_geometry1;                                          \
  geos_geometry1 = buildGeosGeometryFromItem(lItem1, geometric_type1);            \
                                                                                  \
  geos::geom::Geometry  *geos_geometry2;                                          \
  geos_geometry2 = buildGeosGeometryFromItem(lItem2, geometric_type2);            \
                                                                                  \
  geos::geom::Geometry  *geos_result;                                             \
  geos_result = geos_geometry1->geos_function_name(geos_geometry2);               \
                                                                                  \
                                                                                  \
  zorba::Item   null_parent;                                                      \
  zorba::Item   result_item;                                                      \
  result_item = getGMLItemFromGeosGeometry(null_parent, geos_result);             \
  delete geos_geometry1;                                                          \
  delete geos_geometry2;                                                          \
  delete geos_result;                                                             \
                                                                                  \
  return ItemSequence_t(new SingletonItemSequence(result_item));                  \
}


DEFINE_EVALUATE_TWO_GEOMETRIES_RETURN_GEOMETRY(SFIntersectionFunction, intersection)
DEFINE_EVALUATE_TWO_GEOMETRIES_RETURN_GEOMETRY(SFUnionFunction, Union)
DEFINE_EVALUATE_TWO_GEOMETRIES_RETURN_GEOMETRY(SFDifferenceFunction, difference)
DEFINE_EVALUATE_TWO_GEOMETRIES_RETURN_GEOMETRY(SFSymDifferenceFunction, symDifference)


///////////////////////////////////////////////////////////////////////
#define DEFINE_EVALUATE_ONE_GEOMETRY_RETURN_DOUBLE(sfclass_name, geos_function_name)    \
ItemSequence_t                                                                          \
sfclass_name::evaluate(const StatelessExternalFunction::Arguments_t& args,              \
         const StaticContext* aSctxCtx,                                                 \
         const DynamicContext* aDynCtx) const                                           \
{                                                                                       \
  Item lItem;                                                                           \
  gmlsf_types   geometric_type;                                                         \
  geometric_type = getGeometryNodeType(args, 0, lItem);                                 \
                                                                                        \
  switch(geometric_type)                                                                \
  {                                                                                     \
  case GMLSF_INVALID:                                                                   \
    {                                                                                   \
      std::stringstream lErrorMessage;                                                  \
      lErrorMessage << "Unrecognized geometric type for element "                       \
           << lItem.getPrefix() <<":"<<lItem.getLocalName() << ".";                     \
      throwError(lErrorMessage.str(), XPTY0004);                                        \
    }                                                                                   \
    break;                                                                              \
  default:                                                                              \
    break;                                                                              \
  }                                                                                     \
                                                                                        \
  geos::geom::Geometry  *geos_geometry;                                                 \
  geos_geometry = buildGeosGeometryFromItem(lItem, geometric_type);                     \
                                                                                        \
  double  retval;                                                                       \
  retval = geos_geometry->geos_function_name();                                         \
                                                                                        \
  return ItemSequence_t(new SingletonItemSequence(                                      \
     theModule->getItemFactory()->createDouble(retval)));                               \
}

DEFINE_EVALUATE_ONE_GEOMETRY_RETURN_DOUBLE(SFAreaFunction, getArea)
DEFINE_EVALUATE_ONE_GEOMETRY_RETURN_DOUBLE(SFLengthFunction, getLength)

ItemSequence_t                                                                          
SFRelateFunction::evaluate(const StatelessExternalFunction::Arguments_t& args,              
         const StaticContext* aSctxCtx,                                                 
         const DynamicContext* aDynCtx) const                                           
{                                                                                       
  Item lItem1;                                                                    
  gmlsf_types   geometric_type1;                                                  
  geometric_type1 = getGeometryNodeType(args, 0, lItem1);                         
                                                                                  
  switch(geometric_type1)                                                         
  {                                                                               
  case GMLSF_INVALID:                                                             
    {                                                                             
      std::stringstream lErrorMessage;                                            
      lErrorMessage << "Unrecognized geometric type for element "                 
           << lItem1.getPrefix() <<":"<<lItem1.getLocalName() << " in first parameter.";    
      throwError(lErrorMessage.str(), XPTY0004);                                  
    }                                                                             
    break;                                                                        
  default:                                                                        
    break;                                                                        
  }                                                                               
                                                                                  
  Item lItem2;                                                                    
  gmlsf_types   geometric_type2;                                                  
  geometric_type2 = getGeometryNodeType(args, 1, lItem2);                         
                                                                                  
  switch(geometric_type2)                                                          
  {                                                                               
  case GMLSF_INVALID:                                                             
    {                                                                             
      std::stringstream lErrorMessage;                                            
      lErrorMessage << "Unrecognized geometric type for third element "                 
           << lItem2.getPrefix() <<":"<<lItem2.getLocalName() << " in second parameter.";   
      throwError(lErrorMessage.str(), XPTY0004);                                  
    }                                                                             
    break;                                                                        
  default:                                                                        
    break;                                                                        
  }                                                                               
                                                                                  
  geos::geom::Geometry  *geos_geometry1;                                          
  geos_geometry1 = buildGeosGeometryFromItem(lItem1, geometric_type1);            
                                                                                  
  geos::geom::Geometry  *geos_geometry2;                                          
  geos_geometry2 = buildGeosGeometryFromItem(lItem2, geometric_type2);            
                                                                                  
                                                                                        
  Item lItem3;                                                                           
  if (!args[2]->next(lItem3)) 
  {
    std::stringstream lErrorMessage;
    lErrorMessage << "An empty-sequence is not allowed as parameter";
    throwError(lErrorMessage.str(), XPTY0004);
  }

  zorba::String intersection_matrix;
  intersection_matrix = lItem3.getStringValue();

  bool is_relate;                                                   
  try{
    is_relate = geos_geometry1->relate(geos_geometry2, intersection_matrix.c_str());                                    
  }catch(geos::util::GEOSException &excep)
  {
    std::stringstream lErrorMessage;
    lErrorMessage << "Error in relate function: " << excep.what();
    throwError(lErrorMessage.str(), XPTY0004);
  }
                                                                                        
  return ItemSequence_t(new SingletonItemSequence(
     theModule->getItemFactory()->createBoolean(is_relate)));
}

ItemSequence_t                                                                          
SFIsWithinDistanceFunction::evaluate(const StatelessExternalFunction::Arguments_t& args,              
         const StaticContext* aSctxCtx,                                                 
         const DynamicContext* aDynCtx) const                                           
{                                                                                       
  Item lItem1;                                                                    
  gmlsf_types   geometric_type1;                                                  
  geometric_type1 = getGeometryNodeType(args, 0, lItem1);                         
                                                                                  
  switch(geometric_type1)                                                         
  {                                                                               
  case GMLSF_INVALID:                                                             
    {                                                                             
      std::stringstream lErrorMessage;                                            
      lErrorMessage << "Unrecognized geometric type for element "                 
           << lItem1.getPrefix() <<":"<<lItem1.getLocalName() << " in first parameter.";    
      throwError(lErrorMessage.str(), XPTY0004);                                  
    }                                                                             
    break;                                                                        
  default:                                                                        
    break;                                                                        
  }                                                                               
                                                                                  
  Item lItem2;                                                                    
  gmlsf_types   geometric_type2;                                                  
  geometric_type2 = getGeometryNodeType(args, 1, lItem2);                         
                                                                                  
  switch(geometric_type2)                                                          
  {                                                                               
  case GMLSF_INVALID:                                                             
    {                                                                             
      std::stringstream lErrorMessage;                                            
      lErrorMessage << "Unrecognized geometric type for element "                 
           << lItem2.getPrefix() <<":"<<lItem2.getLocalName() << " in second parameter.";   
      throwError(lErrorMessage.str(), XPTY0004);                                  
    }                                                                             
    break;                                                                        
  default:                                                                        
    break;                                                                        
  }                                                                               
                                                                                  
  geos::geom::Geometry  *geos_geometry1;                                          
  geos_geometry1 = buildGeosGeometryFromItem(lItem1, geometric_type1);            
                                                                                  
  geos::geom::Geometry  *geos_geometry2;                                          
  geos_geometry2 = buildGeosGeometryFromItem(lItem2, geometric_type2);            
                                                                                  
                                                                                        
  Item lItem3;                                                                           
  if (!args[2]->next(lItem3)) 
  {
    std::stringstream lErrorMessage;
    lErrorMessage << "An empty-sequence is not allowed as third parameter";
    throwError(lErrorMessage.str(), XPTY0004);
  }

  double distance;
  distance = lItem3.getDoubleValue();

  bool is_within_distance;                                                   
  is_within_distance = geos_geometry1->isWithinDistance(geos_geometry2, distance);                                    
                                                                                        
  return ItemSequence_t(new SingletonItemSequence(
     theModule->getItemFactory()->createBoolean(is_within_distance)));
}

ItemSequence_t                                                                          
SFDistanceFunction::evaluate(const StatelessExternalFunction::Arguments_t& args,              
         const StaticContext* aSctxCtx,                                                 
         const DynamicContext* aDynCtx) const                                           
{                                                                                       
  Item lItem1;                                                                    
  gmlsf_types   geometric_type1;                                                  
  geometric_type1 = getGeometryNodeType(args, 0, lItem1);                         
                                                                                  
  switch(geometric_type1)                                                         
  {                                                                               
  case GMLSF_INVALID:                                                             
    {                                                                             
      std::stringstream lErrorMessage;                                            
      lErrorMessage << "Unrecognized geometric type for element "                 
           << lItem1.getPrefix() <<":"<<lItem1.getLocalName() << " in first parameter.";    
      throwError(lErrorMessage.str(), XPTY0004);                                  
    }                                                                             
    break;                                                                        
  default:                                                                        
    break;                                                                        
  }                                                                               
                                                                                  
  Item lItem2;                                                                    
  gmlsf_types   geometric_type2;                                                  
  geometric_type2 = getGeometryNodeType(args, 1, lItem2);                         
                                                                                  
  switch(geometric_type2)                                                          
  {                                                                               
  case GMLSF_INVALID:                                                             
    {                                                                             
      std::stringstream lErrorMessage;                                            
      lErrorMessage << "Unrecognized geometric type for element "                 
           << lItem2.getPrefix() <<":"<<lItem2.getLocalName() << " in second parameter.";   
      throwError(lErrorMessage.str(), XPTY0004);                                  
    }                                                                             
    break;                                                                        
  default:                                                                        
    break;                                                                        
  }                                                                               
                                                                                  
  geos::geom::Geometry  *geos_geometry1;                                          
  geos_geometry1 = buildGeosGeometryFromItem(lItem1, geometric_type1);            
                                                                                  
  geos::geom::Geometry  *geos_geometry2;                                          
  geos_geometry2 = buildGeosGeometryFromItem(lItem2, geometric_type2);            
                                                                                  
                                                                                        
  double min_distance;                                                   
  min_distance = geos_geometry1->distance(geos_geometry2);                                    
                                                                                        
  return ItemSequence_t(new SingletonItemSequence(
     theModule->getItemFactory()->createDouble(min_distance)));
}

ItemSequence_t                                                                          
SFBufferFunction::evaluate(const StatelessExternalFunction::Arguments_t& args,              
         const StaticContext* aSctxCtx,                                                 
         const DynamicContext* aDynCtx) const                                           
{                                                                                       
  Item lItem1;                                                                    
  gmlsf_types   geometric_type1;                                                  
  geometric_type1 = getGeometryNodeType(args, 0, lItem1);                         
                                                                                  
  switch(geometric_type1)                                                         
  {                                                                               
  case GMLSF_INVALID:                                                             
    {                                                                             
      std::stringstream lErrorMessage;                                            
      lErrorMessage << "Unrecognized geometric type for element "                 
           << lItem1.getPrefix() <<":"<<lItem1.getLocalName() << " in first parameter.";    
      throwError(lErrorMessage.str(), XPTY0004);                                  
    }                                                                             
    break;                                                                        
  default:                                                                        
    break;                                                                        
  }                                                                               
                                                                                  
  geos::geom::Geometry  *geos_geometry1;                                          
  geos_geometry1 = buildGeosGeometryFromItem(lItem1, geometric_type1);            
                                                                                  
                                                                                        
  Item lItem2;                                                                           
  if (!args[1]->next(lItem2)) 
  {
    std::stringstream lErrorMessage;
    lErrorMessage << "An empty-sequence is not allowed as second parameter";
    throwError(lErrorMessage.str(), XPTY0004);
  }

  double distance;
  distance = lItem2.getDoubleValue();
                                                                                        
  geos::geom::Geometry  *geos_result;                                          
  geos_result = geos_geometry1->buffer(distance);                                    

  zorba::Item   null_parent;                                                      
  zorba::Item   result_item;                                                      
  result_item = getGMLItemFromGeosGeometry(null_parent, geos_result);             
  delete geos_geometry1;                                                          
  delete geos_result;                                                             
                                                                                  
  return ItemSequence_t(new SingletonItemSequence(result_item));                  
}


} /* namespace geomodule */ } /* namespace zorba */
