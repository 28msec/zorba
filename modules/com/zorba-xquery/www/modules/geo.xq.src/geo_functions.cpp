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

#include <string.h>
#include <stdio.h>
#include <math.h>
#include <stdlib.h>

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
#include <geos/geom/CoordinateArraySequenceFactory.h>
#include <geos/geom/IntersectionMatrix.h>
#include <geos/io/WKBReader.h>
#include <geos/io/WKBWriter.h>
#include <geos/io/WKTWriter.h>
#include <geos/util/GeometricShapeFactory.h>
#include <geos/util/GEOSException.h>
#include <geos/util/IllegalArgumentException.h>
#include <geos/opLinemerge.h>
#include <geos/opPolygonize.h>
#include <geos/version.h>
#include <vector>
#include <sstream>
#include <iomanip>

#include <zorba/zorba.h>
#include <zorba/store_consts.h>
#include <zorba/singleton_item_sequence.h>
#include <zorba/vector_item_sequence.h>
#include <zorba/empty_sequence.h>

#include "geo_module.h"

#if GEOS_VERSION_MAJOR < 3 || (GEOS_VERSION_MAJOR == 3 && GEOS_VERSION_MINOR < 2) || \
  (GEOS_VERSION_MAJOR == 3 && GEOS_VERSION_MINOR == 2 && GEOS_VERSION_PATCH < 2)
#error Zorba geo module can be linked only with GEOS version 3.2.2 or above, preferably 3.3
#endif

#define DONT_CHECK_FOR_CURVE_SURFACE true

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
  else if(localname.byteEqual("PolygonPatch", 12))
    return GMLSF_POLYGON;
  else if(localname.byteEqual("MultiPoint", 10))
    return GMLSF_MULTIPOINT;
  else if(localname.byteEqual("MultiCurve", 10))
    return GMLSF_MULTICURVE;
  else if(localname.byteEqual("MultiSurface", 12))
    return GMLSF_MULTISURFACE;
  else if(localname.byteEqual("MultiGeometry", 13))///from GML3
    return GMLSF_MULTIGEOMETRY;
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
    if(!item_namespace.byteEqual(ns, (unsigned int)strlen(ns)))
    {
      continue;//next child
    }
    String  item_name = child_name.getLocalName();
    if(!item_name.byteEqual(localname, (unsigned int)strlen(localname)))
    {
      continue;//next child
    }
    return true;
  }
  return false;
}

bool GeoFunction::getAttribute(  zorba::Item &item, 
                                 const char *name, 
                                 const char *ns,
                                 zorba::Item &attr_item) const
{
  Iterator_t    children;
  children = item.getAttributes();
  children->open();
  while(children->next(attr_item))
  {
    zorba::Item   attr_qname;
    attr_item.getNodeName(attr_qname);
    String  attr_name = attr_qname.getLocalName();
    if(!attr_name.byteEqual(name, (unsigned int)strlen(name)))
    {
      continue;//next attr
    }
    if(!ns)
    {
      children->close();
      return true;
   }
    String  attr_ns= attr_qname.getNamespace();
    if(attr_ns.byteEqual(ns, (unsigned int)strlen(ns)))
    {
      children->close();
      return true;
    }
  }
  children->close();
  return false;
}

bool GeoFunction::checkOptionalAttribute(zorba::Item &item, 
                                         const char *name, 
                                         const char *ns,
                                         const char *value) const
{
  zorba::Item attr_item;
  if(!getAttribute(  item, 
                     name, 
                     ns,
                     attr_item))
     return true;
  String  attr_value = attr_item.getStringValue();
  return attr_value.byteEqual(value, (unsigned int)strlen(value));
}

int GeoFunction::get_srsDimension(zorba::Item &item, int prev_srsdimension) const
{
  zorba::Item attr_item;
  if(getAttribute(item, 
                   "srsDimension", 
                   NULL,
                   attr_item))
  {
    String  attr_value = attr_item.getStringValue();
    String  trimed_value = attr_value.trim();
    int srs_dim = atoi(trimed_value.c_str());
    if((srs_dim != 2) && (srs_dim != 3))
    {
      std::stringstream lErrorMessage;
      lErrorMessage << "Geo module's supported values for srsDimension in GML are 2 and 3.";
      throwError(lErrorMessage.str(), XPTY0004);
    }
    return srs_dim;
  }
  return prev_srsdimension;
}

const geos::geom::GeometryFactory   *GeoFunction::get_geometryFactory() const
{
//  if(!geo_factory)
//    geo_factory = new geos::geom::GeometryFactory;
//  return geo_factory;
  return geos::geom::GeometryFactory::getDefaultInstance();
}

void GeoFunction::readPointPosCoordinates(zorba::Item &lItem, 
                                          double *x, 
                                          double *y,
                                          double *z,
                                          int &srs_dim) const
{
  Iterator_t    children;
  children = lItem.getChildren();
  children->open();
  bool retval = readPointPosCoordinates(children, x, y, z, srs_dim);
  children->close();
  if(!retval)
  {
    std::stringstream lErrorMessage;
    lErrorMessage << "gml node must have a gml:pos child";
    throwError(lErrorMessage.str(), XPTY0004);
  }
}

bool GeoFunction::readPointPosCoordinates(zorba::Iterator_t children, 
                                          double *x, 
                                          double *y,
                                          double *z,
                                          int &srs_dim) const
{
  zorba::Item   pos_item;
  if(!getChild(children, "pos", "http://www.opengis.net/gml", pos_item))
  {//get upset
    //std::stringstream lErrorMessage;
    //lErrorMessage << "gml:Point node must have a gml:pos child";
    //throwError(lErrorMessage.str(), XPTY0004);
    return false;
  }
  srs_dim = get_srsDimension(pos_item, srs_dim);

  String    pos_string;
  pos_string = pos_item.getStringValue();
  *x = 0;
  *y = 0;
  *z = 0;
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
  if(srs_dim == 3)
  {
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
    sscanf(str, "%lf", z);
  }
  return true;
}

void GeoFunction::readPosListCoordinates(zorba::Item &lItem, 
                                         geos::geom::CoordinateSequence *&cl,
                                         int &srs_dim) const
{
  zorba::Item   poslist_item;
  if(srs_dim != 3)
    srs_dim = 2;
  if(getChild(lItem, "posList", "http://www.opengis.net/gml", poslist_item))
  {
    srs_dim = get_srsDimension(poslist_item, srs_dim);
    if(!cl)
      cl = geos::geom::CoordinateArraySequenceFactory::instance()->create((std::size_t)0, srs_dim);

    String    poslist_string;
    poslist_string = poslist_item.getStringValue();
    double x, y, z;
    int load_x = 0;
    const char *str_poslist = poslist_string.c_str();
    while(((*str_poslist == ' ') ||
          (*str_poslist == '\t') ||
          (*str_poslist == '\n') ||
          (*str_poslist == '\r')) &&
          (*str_poslist != 0))
       str_poslist++;
    x = 0; y = 0; z = 0;
    while(str_poslist[0])
    {
      if(load_x == 0)
        x = atof(str_poslist);
      else if(load_x == 1)
      {
        y = atof(str_poslist);
        if(srs_dim == 2)
        {
          cl->add(geos::geom::Coordinate(x, y));
          x = 0; y = 0;
        }
      }
      else if(load_x == 2)
      {
        z = atof(str_poslist);
        cl->add(geos::geom::Coordinate(x, y, z));
        x = 0; y = 0; z = 0;
      }
      load_x = (load_x + 1)%srs_dim;
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
    double x = 0, y = 0, z = 0;
    while(readPointPosCoordinates(children, &x, &y, &z, srs_dim))
    {
      if(!cl)
        cl = geos::geom::CoordinateArraySequenceFactory::instance()->create((std::size_t)0, srs_dim);

      if(srs_dim == 3)
      {
        cl->add(geos::geom::Coordinate(x, y, z));
      }
      else
      {
        cl->add(geos::geom::Coordinate(x, y));
      }
      x = 0; y = 0; z = 0;
    }
    children->close();
  }
  else
  {//get upset
    std::stringstream lErrorMessage;
    zorba::Item item_qname;
    lItem.getNodeName(item_qname);
    lErrorMessage << item_qname.getLocalName() << " node must have a gml:posList child";
    throwError(lErrorMessage.str(), XPTY0004);
  }

}

int GeoFunction::getCoordinateDimension(const geos::geom::Geometry *geos_geometry) const
{
  if(!geos_geometry)
    return 2;
  switch(geos_geometry->getGeometryTypeId())
  {
  case 	geos::geom::GEOS_POINT:
  {
    const geos::geom::Coordinate  *c;
    c = geos_geometry->getCoordinate();
      if(!ISNAN(c->z))
        return 3;
      else
        return 2;
  }
	/// a linestring
  case geos::geom::GEOS_LINESTRING:
	/// a linear ring (linestring with 1st point == last point)
  case geos::geom::GEOS_LINEARRING:
  {
    geos::geom::CoordinateSequence  *cs;
    cs = geos_geometry->getCoordinates();
    size_t    cs_size = cs->getSize();
    for(size_t i=0;i<cs_size;i++)
    {
      if(!ISNAN(cs->getAt(i).z))
        return 3;
    }
    return 2;
  }
	/// a polygon
  case geos::geom::GEOS_POLYGON:
  {
    const geos::geom::LineString*   exterior_ring;
    const geos::geom::Polygon   *polygon = dynamic_cast<const geos::geom::Polygon*>(geos_geometry);
    exterior_ring = polygon->getExteriorRing();
    int exterior_dim = getCoordinateDimension(exterior_ring);
    if(exterior_dim == 3)
      return 3;

    size_t interior_rings = polygon->getNumInteriorRing();
    for(size_t i=0;i<interior_rings;i++)
    {
      const geos::geom::LineString*   interior_ring;
      interior_ring = polygon->getInteriorRingN(i);
      int interior_dim = getCoordinateDimension(interior_ring);
      if(interior_dim == 3)
        return 3;
    }
    return 2;
  }
	/// a collection of points
  case geos::geom::GEOS_MULTIPOINT:
  {
    size_t    nr_geoms = geos_geometry->getNumGeometries();
    for(size_t i=0;i<nr_geoms;i++)
    {
      const geos::geom::Geometry  *point;
      point = geos_geometry->getGeometryN(i);
      if(getCoordinateDimension(point) == 3)
        return 3;
    }
    return 2;
  }
	/// a collection of linestrings
  case geos::geom::GEOS_MULTILINESTRING:
  {
    size_t    nr_geoms = geos_geometry->getNumGeometries();
    for(size_t i=0;i<nr_geoms;i++)
    {
      const geos::geom::Geometry  *linestring;
      linestring = geos_geometry->getGeometryN(i);
      if(getCoordinateDimension(linestring) == 3)
        return 3;
    }
    return 2;
  }
	/// a collection of polygons
  case geos::geom::GEOS_MULTIPOLYGON:
  {
    size_t    nr_geoms = geos_geometry->getNumGeometries();
    for(size_t i=0;i<nr_geoms;i++)
    {
      const geos::geom::Geometry  *polygon;
      polygon = geos_geometry->getGeometryN(i);
      if(getCoordinateDimension(polygon) == 3)
        return 3;
    }
    return 2;
  }
	/// a collection of heterogeneus geometries
  case geos::geom::GEOS_GEOMETRYCOLLECTION:
  {
    //can be either gml:Surface or gml:Curve
    size_t    nr_geoms = geos_geometry->getNumGeometries();
    if(!nr_geoms)
      return 2;//unreachable
    for(size_t i=0;i<nr_geoms;i++)
    {
      const geos::geom::Geometry *child;
      child = geos_geometry->getGeometryN(i);
      if(getCoordinateDimension(child) == 3)
        return 3;
    }
    return 2;
  }
  default:
  {
    std::stringstream lErrorMessage;
    lErrorMessage << "Geometry type " << geos_geometry->getGeometryType() << " is not supported";
    throwError(lErrorMessage.str(), XPTY0004);
  }
  }

  return 2;
}

void GeoFunction::getSrsName(zorba::Item lItem, zorba::Item &srs_uri) const
{
  zorba::Item attr_item;
  if(getAttribute(lItem, 
                   "srsName", 
                   NULL,
                   attr_item))
  {
    String attr_value = attr_item.getStringValue();
    srs_uri = theModule->getItemFactory()->createAnyURI(attr_value);
    return;
  }

  zorba::Item parent_item = lItem.getParent();
  if(parent_item.isNull())
    return;
  zorba::Item bounded_item;
  zorba::Item envelope_item;
  if(getChild(parent_item, "boundedBy", "http://www.opengis.net/gml", bounded_item) &&
     getChild(bounded_item, "Envelope", "http://www.opengis.net/gml", envelope_item))
  {
    getSrsName(envelope_item, srs_uri);
    if(!srs_uri.isNull())
      return;
  }
  getSrsName(parent_item, srs_uri);
  if(!srs_uri.isNull())
    return;
}

geos::geom::Geometry  *GeoFunction::buildGeosGeometryFromItem(zorba::Item &lItem, 
                                                              enum GeoFunction::gmlsf_types geometric_type,
                                                              int srs_dim,
                                                              zorba::Item *srs_uri,
                                                              enum GeoFunction::action_item what_action,
                                                              uint32_t *optional_child_index_or_count,
                                                              zorba::Item *result_item) const
{
  srs_dim = get_srsDimension(lItem, srs_dim);
  if(srs_uri)
    getSrsName(lItem, *srs_uri);
  geos::geom::Geometry *result;

  switch(geometric_type)
  {
  case GMLSF_POINT:
  {
    if(what_action == BUILD_GEOS_GEOMETRY)
    {
      double x, y, z;
      readPointPosCoordinates(lItem, &x, &y, &z, srs_dim);
	    geos::geom::Coordinate c(x, y);
      if(srs_dim == 3)
        c.z = z;
      try{
      result = get_geometryFactory()->createPoint(c);
      result->setUserData((void*)GMLSF_POINT);
      return result;
      }catch(std::exception &excep)                                        
      {                                                                               
        std::stringstream lErrorMessage;                                              
        lErrorMessage << "Error in GEOS function createPoint : " << excep.what();  
        throwError(lErrorMessage.str(), XPTY0004);                                    
      }                                                                               
    }
    else if(what_action == COUNT_CHILDREN)
      (*optional_child_index_or_count) = 1;
    else if(what_action == GET_NTH_CHILD)
    {
      if((*optional_child_index_or_count) == 0)
        *result_item = lItem;
    }
    else
    {
      std::stringstream lErrorMessage;                                              
      lErrorMessage << "Error in GMLSF_POINT";  
      throwError(lErrorMessage.str(), XQP0019_INTERNAL_ERROR);                                    
    }
  }break;
  case GMLSF_LINESTRING:
  {
    geos::geom::CoordinateSequence *cl = NULL;//new geos::geom::CoordinateArraySequence();
    readPosListCoordinates(lItem, cl, srs_dim);
    uint32_t  last_index = (uint32_t)cl->size()-1;
    if(what_action == GET_END_POINT)
    {
      optional_child_index_or_count = &last_index;
      what_action = GET_NTH_POINT;
    }
    if(what_action == BUILD_GEOS_GEOMETRY)
    {
      try{
      result = get_geometryFactory()->createLineString(cl);
      result->setUserData((void*)GMLSF_LINESTRING);
      return result;
      }catch(std::exception &excep)                                        
      {                                                                               
        //delete cl;                                                        
        std::stringstream lErrorMessage;                                              
        lErrorMessage << "Error in GEOS function createLineString : " << excep.what();  
        throwError(lErrorMessage.str(), XPTY0004);                                    
      }                                                                               
    }
    else if((what_action == COUNT_CHILDREN) || (what_action == GET_NUM_POINTS))
    {
      (*optional_child_index_or_count) = (uint32_t)cl->size();
      delete cl;
    }
    else if((what_action == GET_NTH_CHILD) || (what_action == GET_NTH_POINT))
    {
      if((*optional_child_index_or_count) < cl->size())
      {
        Item  item_name;
        Item  item_type;
        zorba::Item   null_parent;                                                      
        item_name = theModule->getItemFactory()->createQName("http://www.opengis.net/gml", "gml", "Point");
        std::vector<std::pair<String, String> >   ns_binding;
        ns_binding.push_back(std::pair<String, String>("gml", "http://www.opengis.net/gml"));
        item_type = theModule->getItemFactory()->createQName("http://www.w3.org/2001/XMLSchema", "untyped");
        *result_item = theModule->getItemFactory()->createElementNode(null_parent, item_name, item_type, false, false, ns_binding);


        zorba::Item pos_item;
        item_type = theModule->getItemFactory()->createQName("http://www.w3.org/2001/XMLSchema", "untyped");
        item_name = theModule->getItemFactory()->createQName("http://www.opengis.net/gml", "gml", "pos");
        addNewLineIndentText(*result_item, 2);
        pos_item = theModule->getItemFactory()->createElementNode(*result_item, item_name, item_type, false, false, ns_binding);
        
        if(srs_dim == 3)
        {
          zorba::Item attr_value_item;
          item_type = theModule->getItemFactory()->createQName("http://www.w3.org/2001/XMLSchema", "untyped");
          item_name = theModule->getItemFactory()->createQName("http://www.opengis.net/gml", "gml", "srsDimension");
          char  strdim[10];
          sprintf(strdim, "%d", srs_dim);
          zorba::String   strvalue(strdim);
          attr_value_item = theModule->getItemFactory()->createString(strvalue);
          theModule->getItemFactory()->createAttributeNode(pos_item, item_name, item_type, attr_value_item);
        }
        char strtemp[100];
        if(srs_dim == 3)
        {
          if(!ISNAN(cl->getAt((*optional_child_index_or_count)).z))
            sprintf(strtemp, "%lf %lf %lf", cl->getAt((*optional_child_index_or_count)).x, 
                                          cl->getAt((*optional_child_index_or_count)).y,
                                          cl->getAt((*optional_child_index_or_count)).z);
          else
            sprintf(strtemp, "%lf %lf 0", cl->getAt((*optional_child_index_or_count)).x, 
                                          cl->getAt((*optional_child_index_or_count)).y);
        }
        else
        {
          sprintf(strtemp, "%lf %lf", cl->getAt((*optional_child_index_or_count)).x, 
                                      cl->getAt((*optional_child_index_or_count)).y);
        }

        zorba::Item text_item;
        text_item = theModule->getItemFactory()->createTextNode(pos_item, strtemp);
        addNewLineIndentText(*result_item, 0);
      }
      delete cl;
    }
    else
    {
      delete cl;
      std::stringstream lErrorMessage;                                              
      lErrorMessage << "Error in GMLSF_LINESTRING";  
      throwError(lErrorMessage.str(), XQP0019_INTERNAL_ERROR);                                    
    }
  }break;
  case GMLSF_CURVE:
  {  //not supported in GEOS; emulate through MultiLineString
    zorba::Item   segments_item;
    if(!getChild(lItem, "segments", "http://www.opengis.net/gml", segments_item))
    {//get upset
      std::stringstream lErrorMessage;
      lErrorMessage << "gml:Curve node must have a gml:segments child";
      throwError(lErrorMessage.str(), XPTY0004);
    }
    if((what_action == COUNT_CHILDREN) || (what_action == GET_NUM_POINTS))
    {
      (*optional_child_index_or_count) = 0;
    }
    unsigned int   child_nr = 0;
    unsigned int   point_nr = 0;
    Iterator_t    segments_children;
    Item          line_segment_item;
    std::vector<geos::geom::Geometry*>    *segments_vector = NULL;
    if(what_action == BUILD_GEOS_GEOMETRY)
    {
      segments_vector = new std::vector<geos::geom::Geometry*>;
    }
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
      if(!checkOptionalAttribute(line_segment_item, "interpolation", "http://www.opengis.net/gml", "linear"))
      {
        std::stringstream lErrorMessage;
        lErrorMessage << "gml:Curve/gml:segments/gml:LineStringSegment supports only linear interpolation";
        throwError(lErrorMessage.str(), XPTY0004);
      }
  	  
      if(what_action == BUILD_GEOS_GEOMETRY)
      {
        segments_vector->push_back(buildGeosGeometryFromItem(line_segment_item, GMLSF_LINESTRING, srs_dim));
      }
      else if(what_action == COUNT_CHILDREN)
      {
        (*optional_child_index_or_count)++;
      }
      else if(what_action == GET_NUM_POINTS)
      {
        uint32_t    nr_points;
        buildGeosGeometryFromItem(line_segment_item, GMLSF_LINESTRING, srs_dim, NULL, GET_NUM_POINTS, &nr_points);
        (*optional_child_index_or_count) += nr_points;
      }
      else if(what_action == GET_NTH_CHILD)
      {
        if((*optional_child_index_or_count) == child_nr)
        {
          *result_item = line_segment_item;
          return NULL;
        }
      }
      else if(what_action == GET_NTH_POINT)
      {
        geos::geom::Geometry *nth_point = buildGeosGeometryFromItem(line_segment_item, GMLSF_LINESTRING, srs_dim, NULL, GET_NTH_POINT, optional_child_index_or_count, result_item);
        if(!result_item->isNull())
          return NULL;
        uint32_t    nr_points;
        buildGeosGeometryFromItem(line_segment_item, GMLSF_LINESTRING, srs_dim, NULL, GET_NUM_POINTS, &nr_points);
        (*optional_child_index_or_count) -= nr_points;
      }
      else
      {
        std::stringstream lErrorMessage;                                              
        lErrorMessage << "Error in GMLSF_CURVE";  
        throwError(lErrorMessage.str(), XQP0019_INTERNAL_ERROR);                                    
      }
      child_nr++;
   }

    if(what_action == BUILD_GEOS_GEOMETRY)
    {
      try{
        result = get_geometryFactory()->createMultiLineString(segments_vector);
        result->setUserData((void*)GMLSF_CURVE);
        return result;
      }catch(std::exception &excep)                                        
      {                      
        std::vector<geos::geom::Geometry*>::iterator  vec_it;
        for(vec_it = segments_vector->begin(); vec_it != segments_vector->end(); vec_it++)
        {
          delete (*vec_it);
        }
        delete segments_vector;                                                        
        std::stringstream lErrorMessage;                                              
        lErrorMessage << "Error in GEOS function createGeometryCollection for gml:Curve: " << excep.what();  
        throwError(lErrorMessage.str(), XPTY0004);                                    
      }                                                                               
    }
  }break;
  case GMLSF_LINEARRING:
  {
    geos::geom::CoordinateSequence *cl = NULL;//new geos::geom::CoordinateArraySequence();
    readPosListCoordinates(lItem, cl, srs_dim);
    uint32_t  last_index = (uint32_t)cl->size()-1;
    if(what_action == GET_END_POINT)
    {
      optional_child_index_or_count = &last_index;
      what_action = GET_NTH_POINT;
    }
    if(what_action == BUILD_GEOS_GEOMETRY)
    {
      try{
      result = get_geometryFactory()->createLinearRing(cl);
      result->setUserData((void*)GMLSF_LINEARRING);
      return result;
      }catch(std::exception &excep)                                        
      {                                                                               
        //delete cl;                                                        
        std::stringstream lErrorMessage;                                              
        lErrorMessage << "Error in GEOS function createLinearRing : " << excep.what();  
        throwError(lErrorMessage.str(), XPTY0004);                                    
      }  
    }
    else if((what_action == COUNT_CHILDREN) || (what_action == GET_NUM_POINTS))
    {
      (*optional_child_index_or_count) = (uint32_t)cl->size();
      delete cl;
    }
    else if((what_action == GET_NTH_CHILD) || (what_action == GET_NTH_POINT))
    {
      if((*optional_child_index_or_count) < cl->size())
      {
        Item  item_name;
        Item  item_type;
        zorba::Item   null_parent;                                                      
        item_name = theModule->getItemFactory()->createQName("http://www.opengis.net/gml", "gml", "Point");
        std::vector<std::pair<String, String> >   ns_binding;
        ns_binding.push_back(std::pair<String, String>("gml", "http://www.opengis.net/gml"));
        item_type = theModule->getItemFactory()->createQName("http://www.w3.org/2001/XMLSchema", "untyped");
        *result_item = theModule->getItemFactory()->createElementNode(null_parent, item_name, item_type, false, false, ns_binding);

        zorba::Item pos_item;
        item_type = theModule->getItemFactory()->createQName("http://www.w3.org/2001/XMLSchema", "untyped");
        item_name = theModule->getItemFactory()->createQName("http://www.opengis.net/gml", "gml", "pos");
        addNewLineIndentText(*result_item, 2);
        pos_item = theModule->getItemFactory()->createElementNode(*result_item, item_name, item_type, false, false, ns_binding);
        
        if(srs_dim == 3)
        {
          zorba::Item attr_value_item;
          item_type = theModule->getItemFactory()->createQName("http://www.w3.org/2001/XMLSchema", "untyped");
          item_name = theModule->getItemFactory()->createQName("http://www.opengis.net/gml", "gml", "srsDimension");
          char  strdim[10];
          sprintf(strdim, "%d", srs_dim);
          zorba::String   strvalue(strdim);
          attr_value_item = theModule->getItemFactory()->createString(strvalue);
          theModule->getItemFactory()->createAttributeNode(pos_item, item_name, item_type, attr_value_item);
        }
        char strtemp[100];
        if(srs_dim == 3)
        {
          if(!ISNAN(cl->getAt((*optional_child_index_or_count)).z))
            sprintf(strtemp, "%lf %lf %lf", cl->getAt((*optional_child_index_or_count)).x, 
                                          cl->getAt((*optional_child_index_or_count)).y,
                                          cl->getAt((*optional_child_index_or_count)).z);
          else
            sprintf(strtemp, "%lf %lf 0", cl->getAt((*optional_child_index_or_count)).x, 
                                          cl->getAt((*optional_child_index_or_count)).y);
        }
        else
        {
          sprintf(strtemp, "%lf %lf", cl->getAt((*optional_child_index_or_count)).x, 
                                      cl->getAt((*optional_child_index_or_count)).y);
        }

        zorba::Item text_item;
        text_item = theModule->getItemFactory()->createTextNode(pos_item, strtemp);
        addNewLineIndentText(*result_item, 0);
      }
      delete cl;
    }
    else
    {
      delete cl;
      std::stringstream lErrorMessage;                                              
      lErrorMessage << "Error in GMLSF_LINEARRING";  
      throwError(lErrorMessage.str(), XQP0019_INTERNAL_ERROR);                                    
    }
  }break;
  case GMLSF_SURFACE:
  {  //not supported in GEOS; emulate through MultiPolygon
    zorba::Item   patches_item;
    if(!getChild(lItem, "patches", "http://www.opengis.net/gml", patches_item))
    {//get upset
      std::stringstream lErrorMessage;
      lErrorMessage << "gml:Surface node must have a gml:patches child";
      throwError(lErrorMessage.str(), XPTY0004);
    }
    if(what_action == COUNT_CHILDREN)
    {
      (*optional_child_index_or_count) = 0;
    }
    unsigned int   child_nr = 0;
    Iterator_t    patches_children;
    Item          polygon_patch_item;
    std::vector<geos::geom::Geometry*>    *polygon_vector = NULL;
    if(what_action == BUILD_GEOS_GEOMETRY)
    {
      polygon_vector = new std::vector<geos::geom::Geometry*>;
    }
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

      if(what_action == BUILD_GEOS_GEOMETRY)
      {
        polygon_vector->push_back(buildGeosGeometryFromItem(polygon_patch_item, GMLSF_POLYGON, srs_dim));
      }
      else if(what_action == COUNT_CHILDREN)
      {
        (*optional_child_index_or_count)++;
      }
      else if(what_action == GET_NTH_CHILD)
      {
        if((*optional_child_index_or_count) == child_nr)
        {
          *result_item = polygon_patch_item;
          return NULL;
        }
      }
      else
      {
        std::stringstream lErrorMessage;                                              
        lErrorMessage << "Error in GMLSF_CURVE";  
        throwError(lErrorMessage.str(), XQP0019_INTERNAL_ERROR);                                    
      }
      child_nr++;
    }

    if(what_action == BUILD_GEOS_GEOMETRY)
    {
      try{
        result = get_geometryFactory()->createMultiPolygon(polygon_vector);
        result->setUserData((void*)GMLSF_SURFACE);
        return result;
      }catch(std::exception &excep)                                        
      {                                                                               
        std::vector<geos::geom::Geometry*>::iterator  vec_it;
        for(vec_it = polygon_vector->begin(); vec_it != polygon_vector->end(); vec_it++)
        {
          delete (*vec_it);
        }
        delete polygon_vector;                                                        
        std::stringstream lErrorMessage;                                              
        lErrorMessage << "Error in GEOS function createGeometryCollection for gml:Surface : " << excep.what();  
        throwError(lErrorMessage.str(), XPTY0004);                                    
      }                                                                               
    }
  }break;
  case GMLSF_POLYGON:
  {
    Iterator_t    polygon_children;
    Item          extint_item;
    unsigned int           nr_child = 0;
    geos::geom::LinearRing    *exterior = NULL;
    std::vector<geos::geom::Geometry*>    *interior_vector = NULL;
    if(what_action == BUILD_GEOS_GEOMETRY)
    {
      interior_vector = new std::vector<geos::geom::Geometry*>;
    }
    else if(what_action == COUNT_CHILDREN)
    {
      (*optional_child_index_or_count) = 0;
    }
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
        if(what_action == BUILD_GEOS_GEOMETRY)
        {
          exterior = dynamic_cast<geos::geom::LinearRing*>(buildGeosGeometryFromItem(linearring_item, GMLSF_LINEARRING, srs_dim));
        }
        else if(what_action == GET_EXTERIOR_RING)
        {
          *result_item = linearring_item;
          return NULL;
        }
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
        if(what_action == BUILD_GEOS_GEOMETRY)
        {
          interior_vector->push_back(buildGeosGeometryFromItem(linearring_item, GMLSF_LINEARRING, srs_dim));
        }
        else if(what_action == COUNT_CHILDREN)
        {
          (*optional_child_index_or_count)++;
        }
        else if(what_action == GET_NTH_CHILD)
        {
          if((*optional_child_index_or_count) == (nr_child-1))
          {
            *result_item = linearring_item;
            return NULL;
          }
        }
        else
        {
          std::stringstream lErrorMessage;                                              
          lErrorMessage << "Error in GMLSF_POLYGON";  
          throwError(lErrorMessage.str(), XQP0019_INTERNAL_ERROR);                                    
        }
      }
      nr_child++;
    }
    if(what_action == BUILD_GEOS_GEOMETRY)
    {
      try{
      result = get_geometryFactory()->createPolygon(exterior, interior_vector);
      result->setUserData((void*)GMLSF_POLYGON);
      return result;
      }catch(std::exception &excep)                                        
      {      
        delete exterior;
        std::vector<geos::geom::Geometry*>::iterator  vec_it;
        for(vec_it = interior_vector->begin(); vec_it != interior_vector->end(); vec_it++)
        {
          delete (*vec_it);
        }
        delete interior_vector;                                                        
        std::stringstream lErrorMessage;                                              
        lErrorMessage << "Error in GEOS function createPolygon : " << excep.what();  
        throwError(lErrorMessage.str(), XPTY0004);                                    
      }                                                                               
    }    
  }break;
  case GMLSF_MULTIPOINT:
  {
    Iterator_t    multipoint_children;
    Item          point_item;
    std::vector<geos::geom::Geometry*>    *point_vector = NULL;
    if(what_action == BUILD_GEOS_GEOMETRY)
    {
      point_vector = new std::vector<geos::geom::Geometry*>;
    }
    else if(what_action == COUNT_CHILDREN)
    {
      (*optional_child_index_or_count) = 0;
    }
    unsigned int nr_child = 0;
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
        lErrorMessage << "First child of gml:MultiPoint must be gml:Point";
        throwError(lErrorMessage.str(), XPTY0004);
      }
      if(what_action == BUILD_GEOS_GEOMETRY)
      {
        point_vector->push_back(buildGeosGeometryFromItem(point_item, GMLSF_POINT, srs_dim));
      }
      else if(what_action == COUNT_CHILDREN)
      {
        (*optional_child_index_or_count)++;
      }
      else if(what_action == GET_NTH_CHILD)
      {
        if((*optional_child_index_or_count) == nr_child)
        {
          *result_item = point_item;
          return NULL;
        }
      }
      else
      {
        std::stringstream lErrorMessage;                                              
        lErrorMessage << "Error in GMLSF_MULTIPOINT";  
        throwError(lErrorMessage.str(), XQP0019_INTERNAL_ERROR);                                    
      }
      nr_child++;
    }
    if(what_action == BUILD_GEOS_GEOMETRY)
    {
      try{
      result = get_geometryFactory()->createMultiPoint(point_vector);
      result->setUserData((void*)GMLSF_MULTIPOINT);
      return result;
      }catch(std::exception &excep)                                        
      {                                                                               
        std::vector<geos::geom::Geometry*>::iterator  vec_it;
        for(vec_it = point_vector->begin(); vec_it != point_vector->end(); vec_it++)
        {
          delete (*vec_it);
        }
        delete point_vector;
        std::stringstream lErrorMessage;                                              
        lErrorMessage << "Error in GEOS function createMultiPoint : " << excep.what();  
        throwError(lErrorMessage.str(), XPTY0004);                                    
      }                                                                               
    }
  }break;
  case GMLSF_MULTICURVE:
  {
    Iterator_t    multicurve_children;
    Item          curve_item;
    std::vector<geos::geom::Geometry*>    *curve_vector = NULL;
    if(what_action == BUILD_GEOS_GEOMETRY)
    {
      curve_vector = new std::vector<geos::geom::Geometry*>;
    }
    else if((what_action == COUNT_CHILDREN) || (what_action == GET_NUM_POINTS))
    {
      (*optional_child_index_or_count) = 0;
    }
    unsigned int nr_child = 0;
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
      if(what_action == BUILD_GEOS_GEOMETRY)
      {
        curve_vector->push_back(buildGeosGeometryFromItem(curve_item, GMLSF_LINESTRING, srs_dim));
      }
      else if(what_action == COUNT_CHILDREN)
      {
        (*optional_child_index_or_count)++;
      }
      else if(what_action == GET_NUM_POINTS)
      {
        uint32_t  nr_points;
        buildGeosGeometryFromItem(curve_item, GMLSF_LINESTRING, srs_dim, NULL, GET_NUM_POINTS, &nr_points);
        (*optional_child_index_or_count) += nr_points;
      }
      else if(what_action == GET_NTH_CHILD)
      {
        if((*optional_child_index_or_count) == nr_child)
        {
          *result_item = curve_item;
          return NULL;
        }
      }
      else if(what_action == GET_NTH_POINT)
      {
        buildGeosGeometryFromItem(curve_item, GMLSF_LINESTRING, srs_dim, NULL, GET_NTH_POINT, optional_child_index_or_count, result_item);
        if(!result_item->isNull())
          return NULL;
        uint32_t  nr_points;
        buildGeosGeometryFromItem(curve_item, GMLSF_LINESTRING, srs_dim, NULL, GET_NUM_POINTS, &nr_points);
        (*optional_child_index_or_count) -= nr_points;
      }
      else
      {
        std::stringstream lErrorMessage;                                              
        lErrorMessage << "Error in GMLSF_MULTICURVE";  
        throwError(lErrorMessage.str(), XQP0019_INTERNAL_ERROR);                                    
      }
      nr_child++;
    }
    if(what_action == BUILD_GEOS_GEOMETRY)
    {
      try{
      result = get_geometryFactory()->createMultiLineString(curve_vector);
      result->setUserData((void*)GMLSF_MULTICURVE);
      return result;
      }catch(std::exception &excep)                                        
      {                                                                               
        std::vector<geos::geom::Geometry*>::iterator  vec_it;
        for(vec_it = curve_vector->begin(); vec_it != curve_vector->end(); vec_it++)
        {
          delete (*vec_it);
        }
        delete curve_vector;
        std::stringstream lErrorMessage;                                              
        lErrorMessage << "Error in GEOS function createMultiLineString : " << excep.what();  
        throwError(lErrorMessage.str(), XPTY0004);                                    
      }                                                                               
    }
  }break;
  case GMLSF_MULTISURFACE:
  {
    Iterator_t    multisurface_children;
    Item          surface_item;
    std::vector<geos::geom::Geometry*>    *surface_vector = NULL;
    if(what_action == BUILD_GEOS_GEOMETRY)
    {
      surface_vector = new std::vector<geos::geom::Geometry*>;
    }
    else if(what_action == COUNT_CHILDREN)
    {
      (*optional_child_index_or_count) = 0;
    }
    unsigned int nr_child = 0;
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
      if(what_action == BUILD_GEOS_GEOMETRY)
      {
        surface_vector->push_back(buildGeosGeometryFromItem(surface_item, GMLSF_POLYGON, srs_dim));
      }
      else if(what_action == COUNT_CHILDREN)
      {
        (*optional_child_index_or_count)++;
      }
      else if(what_action == GET_NTH_CHILD)
      {
        if((*optional_child_index_or_count) == nr_child)
        {
          *result_item = surface_item;
          return NULL;
        }
      }
      else
      {
        std::stringstream lErrorMessage;                                              
        lErrorMessage << "Error in GMLSF_MULTICURVE";  
        throwError(lErrorMessage.str(), XQP0019_INTERNAL_ERROR);                                    
      }
      nr_child++;
    }
    if(what_action == BUILD_GEOS_GEOMETRY)
    {
      try{
      result = get_geometryFactory()->createMultiPolygon(surface_vector);
      result->setUserData((void*)GMLSF_MULTISURFACE);
      return result;
      }catch(std::exception &excep)                                        
      {                                                                               
        std::vector<geos::geom::Geometry*>::iterator  vec_it;
        for(vec_it = surface_vector->begin(); vec_it != surface_vector->end(); vec_it++)
        {
          delete (*vec_it);
        }
        delete surface_vector;
        std::stringstream lErrorMessage;                                              
        lErrorMessage << "Error in GEOS function createMultiPolygon : " << excep.what();  
        throwError(lErrorMessage.str(), XPTY0004);                                    
      }                                                                               
    }
  }break;
  case GMLSF_MULTIGEOMETRY:
  {
    Iterator_t    multigeometry_children;
    Item          geometry_item;
    std::vector<geos::geom::Geometry*>    *geometry_vector = NULL;
    if(what_action == BUILD_GEOS_GEOMETRY)
    {
      geometry_vector = new std::vector<geos::geom::Geometry*>;
    }
    else if(what_action == COUNT_CHILDREN)
    {
      (*optional_child_index_or_count) = 0;
    }
    unsigned int nr_child = 0;
    multigeometry_children = lItem.getChildren();
    multigeometry_children->open();
    while(multigeometry_children->next(geometry_item))
    {
      if(geometry_item.getNodeKind() != store::StoreConsts::elementNode)
        continue;
      Item    item_qname;
      geometry_item.getNodeName(item_qname);
      String  item_namespace = item_qname.getNamespace();
      if(!item_namespace.byteEqual("http://www.opengis.net/gml", 26))
      {
        std::stringstream lErrorMessage;
        lErrorMessage << "Children of gml:MultiGeometry must be gml:geometryMember or gml:geometryMembers";
        throwError(lErrorMessage.str(), XPTY0004);
      }
      String  item_name = item_qname.getLocalName();
      if(item_name.byteEqual("geometryMember", 14) || item_name.byteEqual("geometryMembers", 15))
      {
        Iterator_t    member_children;
        Item          member_item;
        member_children = geometry_item.getChildren();
        member_children->open();
        while(member_children->next(member_item))
        {
          if(what_action == BUILD_GEOS_GEOMETRY)
          {
            geometry_vector->push_back(buildGeosGeometryFromItem(member_item, getGmlSFGeometricType(member_item), srs_dim));
          }
          else if(what_action == COUNT_CHILDREN)
          {
            (*optional_child_index_or_count)++;
          }
          else if(what_action == GET_NTH_CHILD)
          {
            if((*optional_child_index_or_count) == nr_child)
            {
              *result_item = member_item;
              return NULL;
            }
          }
          else
          {
            std::stringstream lErrorMessage;                                              
            lErrorMessage << "Error in GMLSF_MULTIGEOMETRY";  
            throwError(lErrorMessage.str(), XQP0019_INTERNAL_ERROR);                                    
          }
          nr_child++;
        }
      }
      else
      {
        std::stringstream lErrorMessage;
        lErrorMessage << "Children of gml:MultiGeometry must be gml:geometryMember or gml:geometryMembers";
        throwError(lErrorMessage.str(), XPTY0004);
      }
    }
    if(what_action == BUILD_GEOS_GEOMETRY)
    {
      try{
        result = get_geometryFactory()->createGeometryCollection(geometry_vector);
        result->setUserData((void*)GMLSF_MULTIGEOMETRY);
        return result;
      }catch(std::exception &excep)                                        
      {                                                                               
        std::vector<geos::geom::Geometry*>::iterator  vec_it;
        for(vec_it = geometry_vector->begin(); vec_it != geometry_vector->end(); vec_it++)
        {
          delete (*vec_it);
        }
        delete geometry_vector;
        std::stringstream lErrorMessage;                                              
        lErrorMessage << "Error in GEOS function createGeometryCollection : " << excep.what();  
        throwError(lErrorMessage.str(), XPTY0004);                                    
      }                                                                               
    }
  }break;
  case GMLSF_INVALID:
  default:
  {
    std::stringstream lErrorMessage;
    zorba::Item item_qname;
    lItem.getNodeName(item_qname);
    lErrorMessage << "Unrecognized geometric type for element " 
         << item_qname.getPrefix() <<":"<<item_qname.getLocalName() << ".";
    throwError(lErrorMessage.str(), XPTY0004);
  }
  break;
  }

  return NULL;
}

void GeoFunction::addNewLineIndentText(zorba::Item &parent, unsigned int indent) const 
{
/*  zorba::Item text_item;
  if(indent > 100)
    indent = 100;
  char *strtemp;
  strtemp = new char[indent+10];
  strtemp[0] = '\n';
  memset(strtemp+1, ' ', indent);
  strtemp[1+indent] = 0;
  text_item = theModule->getItemFactory()->createTextNode(parent, strtemp);
  delete[] strtemp;
*/
}

void GeoFunction::appendIndent(char *&strtemp2, unsigned int indent) const
{
  strtemp2[0] = '\n';
  memset(strtemp2+1, ' ', indent);
  strtemp2 += indent+1;
  strtemp2[0] = 0;
}

zorba::Item GeoFunction::getGMLItemFromGeosGeometry(zorba::Item &parent, 
                                                    const geos::geom::Geometry *geos_geometry,
                                                    const zorba::Item *srs_uri,
                                                    unsigned int indent,
                                                    const char *tag_name,
                                                    bool dont_check_for_curve_surface
                                                    ) const
{
  zorba::Item   result_item;
  zorba::Item   item_name;
  zorba::Item   item_type;
  std::vector<std::pair<String, String> >   ns_binding;
  ns_binding.push_back(std::pair<String, String>("gml", "http://www.opengis.net/gml"));
  item_type = theModule->getItemFactory()->createQName("http://www.w3.org/2001/XMLSchema", "untyped");

  if(!parent.isNull())
    addNewLineIndentText(parent, indent);

  switch(geos_geometry->getGeometryTypeId())
  {
  case 	geos::geom::GEOS_POINT:
  {
    item_name = theModule->getItemFactory()->createQName("http://www.opengis.net/gml", "gml", "Point");
    result_item = theModule->getItemFactory()->createElementNode(parent, item_name, item_type, false, false, ns_binding);

    zorba::Item pos_item;
    item_type = theModule->getItemFactory()->createQName("http://www.w3.org/2001/XMLSchema", "untyped");
    item_name = theModule->getItemFactory()->createQName("http://www.opengis.net/gml", "gml", "pos");
    addNewLineIndentText(result_item, indent+2);
    pos_item = theModule->getItemFactory()->createElementNode(result_item, item_name, item_type, false, false, ns_binding);
    
    char strtemp[100];
    const geos::geom::Coordinate  *c;
    c = geos_geometry->getCoordinate();
#if GEOS_VERSION_MAJOR > 3 || (GEOS_VERSION_MAJOR == 3 && GEOS_VERSION_MINOR > 2)
    if(geos_geometry->getCoordinateDimension() == 3)
#else
    if(getCoordinateDimension(geos_geometry) == 3)
#endif
    {
      zorba::Item attr_value_item;
      item_type = theModule->getItemFactory()->createQName("http://www.w3.org/2001/XMLSchema", "untyped");
      item_name = theModule->getItemFactory()->createQName("http://www.opengis.net/gml", "gml", "srsDimension");
      zorba::String   strvalue("3");
      attr_value_item = theModule->getItemFactory()->createString(strvalue);
      theModule->getItemFactory()->createAttributeNode(pos_item, item_name, item_type, attr_value_item);
      if(!ISNAN(c->z))
        sprintf(strtemp, "%lf %lf %lf", c->x, c->y, c->z);
      else
        sprintf(strtemp, "%lf %lf 0", c->x, c->y);
    }
    else
      sprintf(strtemp, "%lf %lf", c->x, c->y);

    zorba::Item text_item;
    text_item = theModule->getItemFactory()->createTextNode(pos_item, strtemp);
    addNewLineIndentText(result_item, indent);
    break;
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
    addNewLineIndentText(result_item, indent+2);
    pos_item = theModule->getItemFactory()->createElementNode(result_item, item_name, item_type, false, false, ns_binding);
    
#if GEOS_VERSION_MAJOR > 3 || (GEOS_VERSION_MAJOR == 3 && GEOS_VERSION_MINOR > 2)
    int coord_dim = geos_geometry->getCoordinateDimension();
#else
    int coord_dim = getCoordinateDimension(geos_geometry);
#endif
    if(coord_dim == 3)
    {
      zorba::Item attr_value_item;
      item_type = theModule->getItemFactory()->createQName("http://www.w3.org/2001/XMLSchema", "untyped");
      item_name = theModule->getItemFactory()->createQName("http://www.opengis.net/gml", "gml", "srsDimension");
      zorba::String   strvalue("3");
      attr_value_item = theModule->getItemFactory()->createString(strvalue);
      theModule->getItemFactory()->createAttributeNode(pos_item, item_name, item_type, attr_value_item);
    }
    char *strtemp;
    geos::geom::CoordinateSequence  *cs;
    cs = geos_geometry->getCoordinates();
    size_t    cs_size = cs->getSize();
    strtemp = (char*)malloc((50+indent)*(cs_size+1) + 1);
    strtemp[0] = 0;
    char  *strtemp2 = strtemp;
    for(size_t i=0;i<cs_size;i++)
    {
      appendIndent(strtemp2, indent+4);
      if(coord_dim == 3)
      {
        if(!ISNAN(cs->getAt(i).z))
          sprintf(strtemp2, "%lf %lf %lf", cs->getAt(i).x, cs->getAt(i).y, cs->getAt(i).z);
        else
          sprintf(strtemp2, "%lf %lf 0", cs->getAt(i).x, cs->getAt(i).y);
      }
      else
        sprintf(strtemp2, "%lf %lf", cs->getAt(i).x, cs->getAt(i).y);
      strtemp2 += strlen(strtemp2);
    }

    if(cs_size)
    {
      appendIndent(strtemp2, indent+2);
      zorba::Item text_item;
      text_item = theModule->getItemFactory()->createTextNode(pos_item, strtemp);
      addNewLineIndentText(result_item, indent);
    }
    free(strtemp);
    break;
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
      addNewLineIndentText(result_item, indent+2);
      exterior_item = theModule->getItemFactory()->createElementNode(result_item, item_name, item_type, false, false, ns_binding);
      getGMLItemFromGeosGeometry(exterior_item, exterior_ring, NULL, indent+4);
      addNewLineIndentText(exterior_item, indent+2);
    }
    size_t interior_rings = polygon->getNumInteriorRing();
    for(size_t i=0;i<interior_rings;i++)
    {
      const geos::geom::LineString*   interior_ring;
      interior_ring = polygon->getInteriorRingN(i);

      zorba::Item interior_item;
      item_type = theModule->getItemFactory()->createQName("http://www.w3.org/2001/XMLSchema", "untyped");
      item_name = theModule->getItemFactory()->createQName("http://www.opengis.net/gml", "gml", "interior");
      addNewLineIndentText(result_item, indent+2);
      interior_item = theModule->getItemFactory()->createElementNode(result_item, item_name, item_type, false, false, ns_binding);
      getGMLItemFromGeosGeometry(interior_item, interior_ring, NULL, indent+4);
      addNewLineIndentText(interior_item, indent+2);
    }
    if(exterior_ring || interior_rings)
      addNewLineIndentText(result_item, indent);
    break;
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
      getGMLItemFromGeosGeometry(result_item, point, NULL, indent+2);
    }
    if(nr_geoms)
      addNewLineIndentText(result_item, indent);
    break;
  }
	/// a collection of linestrings
  case geos::geom::GEOS_MULTILINESTRING:
  {
    const geos::geom::MultiLineString *multiline = dynamic_cast<const geos::geom::MultiLineString*>(geos_geometry);
    if(!dont_check_for_curve_surface && isCurve(multiline))
    {
      item_name = theModule->getItemFactory()->createQName("http://www.opengis.net/gml", "gml", "Curve");
      result_item = theModule->getItemFactory()->createElementNode(parent, item_name, item_type, false, false, ns_binding);
      zorba::Item segments_item;
      item_type = theModule->getItemFactory()->createQName("http://www.w3.org/2001/XMLSchema", "untyped");
      item_name = theModule->getItemFactory()->createQName("http://www.opengis.net/gml", "gml", "segments");
      addNewLineIndentText(result_item, indent+2);
      segments_item = theModule->getItemFactory()->createElementNode(result_item, item_name, item_type, false, false, ns_binding);

      size_t    nr_geoms = multiline->getNumGeometries();
      for(size_t i=0;i<nr_geoms;i++)
      {
        const geos::geom::Geometry  *linestring;
        linestring = multiline->getGeometryN(i);

        zorba::Item   linestring_item;
        linestring_item = getGMLItemFromGeosGeometry(segments_item, linestring, NULL, indent+4, "LineStringSegment");

        zorba::Item attr_value_item;
        item_type = theModule->getItemFactory()->createQName("http://www.w3.org/2001/XMLSchema", "untyped");
        item_name = theModule->getItemFactory()->createQName("http://www.opengis.net/gml", "gml", "interpolation");
        zorba::String   strvalue("liniar");
        attr_value_item = theModule->getItemFactory()->createString(strvalue);
        theModule->getItemFactory()->createAttributeNode(linestring_item, item_name, item_type, attr_value_item);
      }
      if(nr_geoms)
        addNewLineIndentText(segments_item, indent+2);
      addNewLineIndentText(result_item, indent);
    }
    else
    {
      item_name = theModule->getItemFactory()->createQName("http://www.opengis.net/gml", "gml", "MultiCurve");
      result_item = theModule->getItemFactory()->createElementNode(parent, item_name, item_type, false, false, ns_binding);

      size_t    nr_geoms = geos_geometry->getNumGeometries();
      for(size_t i=0;i<nr_geoms;i++)
      {
        const geos::geom::Geometry  *linestring;
        linestring = geos_geometry->getGeometryN(i);
        getGMLItemFromGeosGeometry(result_item, linestring, NULL, indent+2);
      }
      if(nr_geoms)
        addNewLineIndentText(result_item, indent);
    }
    break;
  }
	/// a collection of polygons
  case geos::geom::GEOS_MULTIPOLYGON:
  {
    const geos::geom::MultiPolygon *multipoly = dynamic_cast<const geos::geom::MultiPolygon*>(geos_geometry);
    if(!dont_check_for_curve_surface && isSurface(multipoly))
    {
      item_name = theModule->getItemFactory()->createQName("http://www.opengis.net/gml", "gml", "Surface");
      result_item = theModule->getItemFactory()->createElementNode(parent, item_name, item_type, false, false, ns_binding);
      zorba::Item patches_item;
      item_type = theModule->getItemFactory()->createQName("http://www.w3.org/2001/XMLSchema", "untyped");
      item_name = theModule->getItemFactory()->createQName("http://www.opengis.net/gml", "gml", "patches");
      addNewLineIndentText(result_item, indent+2);
      patches_item = theModule->getItemFactory()->createElementNode(result_item, item_name, item_type, false, false, ns_binding);

      size_t    nr_geoms = multipoly->getNumGeometries();
      for(size_t i=0;i<nr_geoms;i++)
      {
        const geos::geom::Geometry  *polygon;
        polygon = multipoly->getGeometryN(i);

        zorba::Item   polygon_item;
        polygon_item = getGMLItemFromGeosGeometry(patches_item, polygon, NULL, indent+4, "PolygonPatch");
      }
      if(nr_geoms)
        addNewLineIndentText(patches_item, indent+2);
      addNewLineIndentText(result_item, indent);
    }
    else
    {
      item_name = theModule->getItemFactory()->createQName("http://www.opengis.net/gml", "gml", "MultiSurface");
      result_item = theModule->getItemFactory()->createElementNode(parent, item_name, item_type, false, false, ns_binding);

      size_t    nr_geoms = geos_geometry->getNumGeometries();
      for(size_t i=0;i<nr_geoms;i++)
      {
        const geos::geom::Geometry  *polygon;
        polygon = geos_geometry->getGeometryN(i);
        getGMLItemFromGeosGeometry(result_item, polygon, NULL, indent+2);
      }
      if(nr_geoms)
        addNewLineIndentText(result_item, indent);
    }
    break;
  }
	/// a collection of heterogeneus geometries
  case geos::geom::GEOS_GEOMETRYCOLLECTION:
  {
    size_t    nr_geoms = geos_geometry->getNumGeometries();
    //if(!nr_geoms)
    //  break;
    item_name = theModule->getItemFactory()->createQName("http://www.opengis.net/gml", "gml", "MultiGeometry");
    result_item = theModule->getItemFactory()->createElementNode(parent, item_name, item_type, false, false, ns_binding);

    for(size_t i=0;i<nr_geoms;i++)
    {
      zorba::Item geometryMember_item;
      item_type = theModule->getItemFactory()->createQName("http://www.w3.org/2001/XMLSchema", "untyped");
      item_name = theModule->getItemFactory()->createQName("http://www.opengis.net/gml", "gml", "geometryMember");
      addNewLineIndentText(result_item, indent+2);
      geometryMember_item = theModule->getItemFactory()->createElementNode(result_item, item_name, item_type, false, false, ns_binding);
      const geos::geom::Geometry  *member;
      member = geos_geometry->getGeometryN(i);

      zorba::Item   geometry_item;
      geometry_item = getGMLItemFromGeosGeometry(geometryMember_item, member, NULL, indent+4 );
      if(!geometry_item.isNull())
        addNewLineIndentText(geometryMember_item, indent+2);
    }
    if(nr_geoms)
      addNewLineIndentText(result_item, indent);
    break;
  }
  default:
  {
    std::stringstream lErrorMessage;
    lErrorMessage << "Geometry type " << geos_geometry->getGeometryType() << " is not supported";
    throwError(lErrorMessage.str(), XPTY0004);
  }
  }

  if(!result_item.isNull() && srs_uri && !srs_uri->isNull())
  {
    item_type = theModule->getItemFactory()->createQName("http://www.w3.org/2001/XMLSchema", "untyped");
    item_name = theModule->getItemFactory()->createQName("", "srsName");
    zorba::String   strvalue = srs_uri->getStringValue();
    zorba::Item attr_value_item = theModule->getItemFactory()->createString(strvalue);
    theModule->getItemFactory()->createAttributeNode(result_item, item_name, item_type, attr_value_item);
  }

//  if(!parent.isNull())
//    addNewLineIndentText(parent, indent);
  return result_item;
}

/*see if the end point from one segment is the start point for the next segment*/
bool GeoFunction::isCurve(const geos::geom::MultiLineString *multiline) const
{
  geos::geom::MultiLineString::const_iterator line_it;
  geos::geom::Point *end_point = NULL;
  for(line_it = multiline->begin(); line_it != multiline->end(); line_it++)
  {
    const geos::geom::LineString   *linestring = dynamic_cast<const geos::geom::LineString*>(*line_it);
    if(end_point)
    {
      geos::geom::Point *start_point;
      start_point = linestring->getStartPoint();
      if(start_point->compareTo(end_point))
        return false;
    }
    end_point = linestring->getEndPoint();
  }
  return true;
}

bool GeoFunction::isClosedCurve(const geos::geom::Geometry *geos_geometry) const 
{
  //Curve is a MultiLineString
  const geos::geom::MultiLineString *curve = dynamic_cast<const geos::geom::MultiLineString *>(geos_geometry);
  unsigned int num_segments = (unsigned int)curve->getNumGeometries();
  if(!num_segments)
    return false;
  unsigned int i;
  //see if last point of a segment is the first of the next
  const geos::geom::LineString *segment1 = dynamic_cast<const geos::geom::LineString *>(curve->getGeometryN(0));
  const geos::geom::CoordinateSequence *coords1 = segment1->getCoordinates();
  const geos::geom::LineString *segment2;
  const geos::geom::CoordinateSequence *coords2;
  for(i=1;i<num_segments;i++)
  {
    segment2 = dynamic_cast<const geos::geom::LineString *>(curve->getGeometryN(i));
    coords2 = segment2->getCoordinates();
    if(!coords1->getAt(coords1->size()-1).equals(coords2->getAt(0)))
      return false;
    coords1 = coords2;
    segment1 = segment2;
  }
  //check if last point is the same as the first point of the curve
  segment2 = dynamic_cast<const geos::geom::LineString *>(curve->getGeometryN(0));
  coords2 = segment2->getCoordinates();
  if(!coords1->getAt(coords1->size()-1).equals(coords2->getAt(0)))
    return false;
  
  return true;
}

geos::geom::LineString *GeoFunction::curveToLineString(const geos::geom::Geometry *geos_geometry) const
{
  const geos::geom::MultiLineString *curve = dynamic_cast<const geos::geom::MultiLineString *>(geos_geometry);
  if(!isCurve(curve))
    return NULL;
  unsigned int num_segments = (unsigned int)curve->getNumGeometries();
  if(!num_segments)
    return NULL;
  const geos::geom::LineString *segment;
  const geos::geom::CoordinateSequence *coords;
  geos::geom::CoordinateSequence *linestring_coords = geos::geom::CoordinateArraySequenceFactory::instance()->create((std::size_t)0, 2);
  unsigned int i;
  for(i=0;i<num_segments;i++)
  {
    segment = dynamic_cast<const geos::geom::LineString *>(curve->getGeometryN(i));
    coords = segment->getCoordinates();
    linestring_coords->add(coords, true, true);
  }
  geos::geom::LineString *linestring = get_geometryFactory()->createLineString(linestring_coords);
  linestring->setUserData((void*)GMLSF_LINESTRING);

  return linestring;
}

bool GeoFunction::isRingCurve(const geos::geom::Geometry *geos_geometry) const 
{
  geos::geom::LineString *linestring;
  linestring = curveToLineString(geos_geometry);
  if(!linestring)
    return false;
  //use GEOS
  bool retval;
  retval = linestring->isRing();
  delete linestring;

  return retval;
}

bool GeoFunction::isSimpleCurve(const geos::geom::Geometry *geos_geometry) const 
{
  geos::geom::LineString *linestring;
  linestring = curveToLineString(geos_geometry);
  if(!linestring)
    return false;
  //use GEOS
  bool retval;
  retval = linestring->isSimple();
  delete linestring;

  return retval;
}

/*see if each polygon touches another polygon by at least a segment of external line and they are all connected together*/
bool GeoFunction::isSurface(const geos::geom::MultiPolygon *multipolygon,
                            bool *is_closed,
                            geos::geom::LinearRing **exterior_boundary) const
{
/*
  struct _tline
  {
    double x1, y1, x2, y2;
    //bool taken;
  };
  struct _tpoly
  {
    std::vector<struct _tline> lines;
    bool processed, touched;
  };
  std::vector<struct _tpoly>  polys;
  int p = 0;
  //init the data
  if(!multipolygon->getNumGeometries())
    return false;
  polys.reserve(multipolygon->getNumGeometries());
  geos::geom::MultiPolygon::const_iterator poly_it;
  for(poly_it = multipolygon->begin(); poly_it != multipolygon->end(); poly_it++, p++)
  {
    polys[p].processed = false;
    polys[p].touched = false;
    const geos::geom::Polygon   *polygon = dynamic_cast<const geos::geom::Polygon*>(*poly_it);
    const geos::geom::LineString*   exterior_ring;
    int l, nr_points;
    const geos::geom::Point *point;
    exterior_ring = polygon->getExteriorRing();
    nr_points = exterior_ring->getNumPoints();
    polys[p].lines.reserve(nr_points);
    for(l=0; l<nr_points; l++)
    {
      point = dynamic_cast<const geos::geom::Point*>(exterior_ring->getGeometryN(l));
      //polys[p].lines[l].taken = false;
      polys[p].lines[l].x1 = point->getX();
      polys[p].lines[l].y1 = point->getY();
      if(l)
      {
        polys[p].lines[l-1].x2 = point->getX();
        polys[p].lines[l-1].y2 = point->getY();
      }
      else
      {
        polys[p].lines[nr_points-1].x2 = point->getX();
        polys[p].lines[nr_points-1].y2 = point->getY();
      }
    }
  }

  //now check
  std::vector<struct _tpoly>::iterator  tpoly_it;
  bool first_round = true;
  while(1)
  {
    if(first_round)
      tpoly_it = polys.begin();
    else
    {
      int total = 0;
      int processed = 0;
      for(tpoly_it = polys.begin(); tpoly_it != polys.end(); tpoly_it++)
      {
        total++;
        if((*tpoly_it).processed)
          processed++;
        else if((*tpoly_it).touched)
          break;
      }
      if(tpoly_it == polys.end())
      {
        if(total == processed)
          return true;
        else
          return false;
      }
    }
    first_round = false;
    (*tpoly_it).processed = true;
    //for every line, check there is at most one match with other line from other polygon
    std::vector<struct _tline>::iterator line_it;
    int all_matches = 0;
    for(line_it = (*tpoly_it).lines.begin(); line_it != (*tpoly_it).lines.end(); line_it++)
    {
      int matches = 0;
      std::vector<struct _tpoly>::iterator  tpoly_it2;
      for(tpoly_it2 = polys.begin(); tpoly_it2 != polys.end(); tpoly_it2++)
      {
        if((*tpoly_it2).processed)
          continue;
        std::vector<struct _tline>::iterator line_it2;
        for(line_it2 = (*tpoly_it2).lines.begin(); line_it2 != (*tpoly_it2).lines.end(); line_it2++)
        {
          if(((*line_it2).x1 == (*line_it).x1) && ((*line_it2).y1 == (*line_it).y1) &&
            ((*line_it2).x2 == (*line_it).x2) && ((*line_it2).y2 == (*line_it).y2) ||
            ((*line_it2).x1 == (*line_it).x2) && ((*line_it2).y1 == (*line_it).y2) &&
            ((*line_it2).x2 == (*line_it).x1) && ((*line_it2).y2 == (*line_it).y1))
          {
            (*tpoly_it2).touched = true;
            matches++;
          }
        }
      }
      if(matches > 1)
        return false;
      all_matches += matches;
    }
    if(!all_matches)
      return false;
  }
  return true;
*/

  //another approach, using LineString::overlaps and LineString::intersection
  //test each polygon if it touches another polygon and if they form a united surface
  //all common boundaries should be disjoint

  std::vector<int>    ids;
  unsigned int i;
  unsigned int nr_patches = (unsigned int)multipolygon->getNumGeometries();
  if(!nr_patches)
    return false;
  ids.resize(nr_patches);
  for(i=0;i<nr_patches;i++)
  {
    ids[i] = 1;//will be set -i-1 if it is touched by another polygon, and to zero when processed
  }

  if(is_closed)
    *is_closed = true;
  if(exterior_boundary)
    *exterior_boundary = NULL;

  std::vector<geos::geom::Geometry*> boundary_segments;//for computing exterior_boundary
  bool is_united;

  ids[0] = -1;
  while(1)
  {
    is_united = true;
    for(i=0;i<nr_patches;i++)
      if(ids[i] > 0)
        is_united = false;
      else if(ids[i] < 0)
        break;
    if(i == nr_patches)
      break;
    ids[i] = 0;
    std::vector<geos::geom::Geometry*>   common_segments;
    const geos::geom::Polygon *patch1 = dynamic_cast<const geos::geom::Polygon *>(multipolygon->getGeometryN(i));
    const geos::geom::LineString  *ring1 = patch1->getExteriorRing();

    for(unsigned int j=0;(j<nr_patches);j++)
    {
      if(j==i)
        continue;
      const geos::geom::Polygon *patch2 = dynamic_cast<const geos::geom::Polygon *>(multipolygon->getGeometryN(j));
      const geos::geom::LineString  *ring2 = patch2->getExteriorRing();
      geos::geom::Geometry*  segment;
      segment = ring1->intersection(ring2);
      if(segment)
      {
        for(unsigned int s=0;s<segment->getNumGeometries();s++)
        {
          const geos::geom::Geometry *seg_piece = segment->getGeometryN(s);

          if((seg_piece->getGeometryTypeId() == geos::geom::GEOS_LINESTRING) ||
            (seg_piece->getGeometryTypeId() == geos::geom::GEOS_MULTILINESTRING))
          {
            if(ids[j] > 0)
              ids[j] = -1;
            for(unsigned int k=0;k<common_segments.size();k++)
            {
              if(seg_piece->overlaps(common_segments[k]))
              {
                delete segment;
                for(unsigned int c=0;c<common_segments.size();c++)
                  delete common_segments[c];
                for(unsigned int b=0;b<boundary_segments.size();b++)
                  delete boundary_segments[b];
                return false;
              }
            }
            common_segments.push_back(seg_piece->clone());
          }
        }
        delete segment;
      }//end if(segment)
    }
    if(is_closed && *is_closed || exterior_boundary)
    {
      if(!common_segments.size())
      {
        if(is_closed)
          *is_closed = false;
      }
      else
      {
        geos::geom::Geometry *segment_union;
        geos::geom::Geometry *temp_union;
        segment_union = common_segments[0]->clone();
        for(unsigned int c=1;c<common_segments.size();c++)
        {
          temp_union = segment_union->Union(common_segments[c]);
          delete segment_union;
          segment_union = temp_union;
        }
        if(!segment_union->equals(ring1))
        {
          if(is_closed)
            *is_closed = false;
          if(exterior_boundary)
          {
            geos::geom::Geometry *diff;
            diff = ring1->difference(segment_union);
            boundary_segments.push_back(diff);
          }
        }
        delete segment_union;
      }
    }
    for(unsigned int c=0;c<common_segments.size();c++)
      delete common_segments[c];
    common_segments.clear();
  }

  if(is_united && exterior_boundary)
  {
    //do manual union of boundary_segments
    //std::vector<const geos::geom::Point *> points;
    geos::geom::CoordinateSequence      *cl = NULL;

    std::vector<const geos::geom::LineString *> segments;
    size_t nr_segments = 0; 
    for(unsigned int b=0;b<boundary_segments.size();b++)
    {
      nr_segments += boundary_segments[b]->getNumGeometries();
    }
    //points.reserve(nr_segments*4);
    segments.reserve(nr_segments);
    for(unsigned int b=0;b<boundary_segments.size();b++)
    {
      geos::geom::Geometry* segm = boundary_segments[b];
      for(unsigned int s=0;s<segm->getNumGeometries();s++)
      {
        const geos::geom::Geometry* part = segm->getGeometryN(s);
        if(part->getGeometryTypeId() == geos::geom::GEOS_LINESTRING)
        {
          segments.push_back(dynamic_cast<const geos::geom::LineString *>(part));
        }
      }
    }
    const geos::geom::Geometry* part = segments[0];
    if(!cl)
    {
      int srs_dim;
#if GEOS_VERSION_MAJOR > 3 || (GEOS_VERSION_MAJOR == 3 && GEOS_VERSION_MINOR > 2)
      srs_dim = part->getCoordinateDimension();
#else
      srs_dim = getCoordinateDimension(part);
#endif
      cl = geos::geom::CoordinateArraySequenceFactory::instance()->create((std::size_t)0, srs_dim);
    }
    cl->add(part->getCoordinates(), false, true);

    segments[0] = NULL;
    while(1)
    {
      const geos::geom::Coordinate &last_point = cl->getAt(cl->size()-1);
      bool added_points = false;
      for(unsigned int s=1;s<segments.size();s++)
      {
        if(!segments[s])
          continue;
        const geos::geom::Geometry *segmn = segments[s];
        geos::geom::CoordinateSequence* coords = segmn->getCoordinates();
        geos::geom::Coordinate point = coords->getAt(0);
        if(last_point.equals(point))
        {
          cl->add(coords, false, true);
          segments[s] = NULL;
          added_points = true;
          break;
        }
        else
        {
          point = coords->getAt(coords->size()-1);
          if(last_point.equals(point))
          {
            cl->add(coords, false, false);
            segments[s] = NULL;
            added_points = true;
            break;
          }
        }
      }
      if(!added_points)
        break;
    }
    cl->add(cl->getAt(0), false);
    *exterior_boundary = get_geometryFactory()->createLinearRing(cl);
    (*exterior_boundary)->setUserData((void*)GMLSF_LINEARRING);
    for(unsigned int b=0;b<boundary_segments.size();b++)
      delete boundary_segments[b];
  }
  return is_united;
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

  geos::geom::Geometry  *geos_geometry;                                                 
  geos_geometry = buildGeosGeometryFromItem(lItem, geometric_type, -1);                     
                                                                                        
  geos::geom::Dimension::DimensionType   dim_type = geos::geom::Dimension::DONTCARE;                                                
  try{                                                                                  
    dim_type = geos_geometry->getDimension();                                  
  }catch(std::exception &excep)                                              
  {                                                                                     
    delete geos_geometry;                                                               
    std::stringstream lErrorMessage;                                                    
    lErrorMessage << "Error in GEOS function getDimension : " << excep.what();  
    throwError(lErrorMessage.str(), XPTY0004);                                          
  }                                                                                     
  delete geos_geometry;                                                               

  return ItemSequence_t(new SingletonItemSequence(
      theModule->getItemFactory()->createInteger((int)dim_type)));
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
      zorba::Item item_qname;
      lItem.getNodeName(item_qname);
      lErrorMessage << "Unrecognized geometric type for element " 
           << item_qname.getPrefix() <<":"<<item_qname.getLocalName() << ".";
      throwError(lErrorMessage.str(), XPTY0004);
    }
    break;
  default:
    break;
  }

  geos::geom::Geometry  *geos_geometry;                                                 
  geos_geometry = buildGeosGeometryFromItem(lItem, geometric_type, -1);   

#if GEOS_VERSION_MAJOR > 3 || (GEOS_VERSION_MAJOR == 3 && GEOS_VERSION_MINOR > 2)
  int   coord_dim = geos_geometry->getCoordinateDimension();
#else
  int coord_dim = getCoordinateDimension(geos_geometry);
#endif
  delete geos_geometry;
  return ItemSequence_t(new SingletonItemSequence(
      theModule->getItemFactory()->createInteger(coord_dim)));
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
   type_string = "LineString";break;
  case GMLSF_SURFACE:
   type_string = "Surface";break;
  case GMLSF_POLYGON:
  //case GMLSF_POLYGONPATCH:
   type_string = "Polygon";break;
  case GMLSF_MULTIPOINT:
   type_string = "MultiPoint";break;
  case GMLSF_MULTICURVE:
   type_string = "MultiCurve";break;
  case GMLSF_MULTISURFACE:
   type_string = "MultiSurface";break;
  case GMLSF_MULTIGEOMETRY:
   type_string = "MultiGeometry";break;

  case GMLSF_INVALID:
  default:
  /*  {
      std::stringstream lErrorMessage;
      zorba::Item item_qname;
      lItem.getNodeName(item_qname);
      lErrorMessage << "Unrecognized geometric type for element " 
           << item_qname.getPrefix() <<":"<<item_qname.getLocalName() << ".";
      throwError(lErrorMessage.str(), XPTY0004);
    }
  */  break;
  }

  if(!type_string.empty())
  {
    String gmlns("http://www.opengis.net/gml");
    String gmlprefix("gml");
    return ItemSequence_t(new SingletonItemSequence(
      theModule->getItemFactory()->createQName(gmlns, gmlprefix, type_string)));
  }
  else
  {
    return ItemSequence_t(new EmptySequence());
  }
}

///////////////////////////////////////////////////////////////////////
ItemSequence_t 
SFNumGeometriesFunction::evaluate(const StatelessExternalFunction::Arguments_t& args,
         const StaticContext* aSctxCtx,
         const DynamicContext* aDynCtx) const
{
  Item lItem;
  gmlsf_types   geometric_type;
  geometric_type = getGeometryNodeType(args, 0, lItem);

  switch(geometric_type)
  {
  case GMLSF_POINT:
  case GMLSF_LINESTRING:
  //case GMLSF_CURVE:
  case GMLSF_LINEARRING:
  //case GMLSF_SURFACE:
  case GMLSF_POLYGON:
    return ItemSequence_t(new SingletonItemSequence(
      theModule->getItemFactory()->createUnsignedInt(1)));
  case GMLSF_INVALID:
    {
      std::stringstream lErrorMessage;
      zorba::Item item_qname;
      lItem.getNodeName(item_qname);
      lErrorMessage << "Unrecognized geometric type for element " 
           << item_qname.getPrefix() <<":"<<item_qname.getLocalName() << ".";
      throwError(lErrorMessage.str(), XPTY0004);
    }
    break;
  default:
    break;
  }

  uint32_t    num_geos = 0;
  buildGeosGeometryFromItem(lItem, geometric_type, -1, NULL, COUNT_CHILDREN, &num_geos);

  return ItemSequence_t(new SingletonItemSequence(
     theModule->getItemFactory()->createUnsignedInt(num_geos)));
}

ItemSequence_t                                                                          
SFGeometryNFunction::evaluate(const StatelessExternalFunction::Arguments_t& args,              
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
      zorba::Item item_qname1;
      lItem1.getNodeName(item_qname1);
      lErrorMessage << "Unrecognized geometric type for element "                 
           << item_qname1.getPrefix() <<":"<<item_qname1.getLocalName() << " in first parameter.";    
      throwError(lErrorMessage.str(), XPTY0004);                                  
    }                                                                             
    break;                                                                        
  default:                                                                        
    break;                                                                        
  }                                                                               
                                                                                  
  Item lItem2;                                                                           
  if (!args[1]->next(lItem2)) 
  {
    std::stringstream lErrorMessage;
    lErrorMessage << "An empty-sequence is not allowed as second parameter";
    throwError(lErrorMessage.str(), XPTY0004);
  }

  uint32_t n;
  n = lItem2.getUnsignedIntValue();
                                               
  switch(geometric_type1)                                                         
  {                                                                               
  case GMLSF_POINT:
  case GMLSF_LINESTRING:
  //case GMLSF_CURVE:
  case GMLSF_LINEARRING:
  //case GMLSF_SURFACE:
  case GMLSF_POLYGON:
    if(n == 0)
      return ItemSequence_t(new SingletonItemSequence(lItem1));                  
    else
    {
      std::stringstream lErrorMessage;                                              
      lErrorMessage << "Index n (" << n << ") is outside the range ";  
      throwError(lErrorMessage.str(), XPTY0004);                                    
    }
    break;
  default:break;
  }

  Item    nth_child;
  buildGeosGeometryFromItem(lItem1, geometric_type1, -1, NULL, GET_NTH_CHILD, &n, &nth_child);

  if(nth_child.isNull())
  {
    std::stringstream lErrorMessage;                                              
    lErrorMessage << "Index n (" << n << ") is outside the range ";  
    throwError(lErrorMessage.str(), XPTY0004);                                    
  }
  return ItemSequence_t(new SingletonItemSequence(nth_child));                  
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
      zorba::Item item_qname;                                                           \
      lItem.getNodeName(item_qname);                                                    \
      lErrorMessage << "Unrecognized geometric type for element "                       \
           << item_qname.getPrefix() <<":"<<item_qname.getLocalName() << ".";           \
      throwError(lErrorMessage.str(), XPTY0004);                                        \
    }                                                                                   \
    break;                                                                              \
  default:                                                                              \
    break;                                                                              \
  }                                                                                     \
                                                                                        \
  geos::geom::Geometry  *geos_geometry;                                                 \
  zorba::Item srs_uri;                                                                  \
  geos_geometry = buildGeosGeometryFromItem(lItem, geometric_type, -1, &srs_uri);       \
                                                                                        \
  geos::geom::Geometry  *geos_result = NULL;                                            \
  try{                                                                                  \
    geos_result = geos_geometry->geos_function_name();                                  \
  }catch(std::exception &excep)                                                         \
  {                                                                                     \
    delete geos_geometry;                                                               \
    std::stringstream lErrorMessage;                                                    \
    lErrorMessage << "Error in GEOS function " #geos_function_name " : " << excep.what();  \
    throwError(lErrorMessage.str(), XPTY0004);                                          \
  }                                                                                     \
                                                                                        \
  zorba::Item   null_parent;                                                            \
  zorba::Item   result_item;                                                            \
  result_item = getGMLItemFromGeosGeometry(null_parent, geos_result, &srs_uri);         \
  delete geos_geometry;                                                                 \
  delete geos_result;                                                                   \
                                                                                        \
  return ItemSequence_t(new SingletonItemSequence(result_item));                        \
}

//DEFINE_EVALUATE_ONE_GEOMETRY_RETURN_GEOMETRY(SFBoundaryFunction, getBoundary)
DEFINE_EVALUATE_ONE_GEOMETRY_RETURN_GEOMETRY(SFConvexHullFunction, convexHull)
DEFINE_EVALUATE_ONE_GEOMETRY_RETURN_GEOMETRY(SFCentroidFunction, getCentroid)
DEFINE_EVALUATE_ONE_GEOMETRY_RETURN_GEOMETRY(SFPointOnSurfaceFunction, getInteriorPoint)

zorba::Item GeoFunction::getBoundary(geos::geom::Geometry *geos_geometry, zorba::Item srs_uri) const 
{
  geos::geom::Geometry  *geos_result = NULL;                                            
  if(geos_geometry->getUserData() == (void*)GMLSF_SURFACE)
  {
    geos::geom::LinearRing *exterior_ring;
    geos::geom::MultiPolygon* surface = dynamic_cast<geos::geom::MultiPolygon*>(geos_geometry);
    if(!isSurface(surface, NULL, &exterior_ring))
    {
      delete geos_geometry;                                                               
      std::stringstream lErrorMessage;                                                    
      lErrorMessage << "Error in Surface : the patches do not form a polyhedral surface";  
      throwError(lErrorMessage.str(), XPTY0004);                                          
    }
    std::vector<geos::geom::Geometry*> *rings = new std::vector<geos::geom::Geometry*>;
    rings->push_back(exterior_ring);
    for(unsigned int i=0;i<surface->getNumGeometries();i++)
    {
      const geos::geom::Polygon* polygon = dynamic_cast<const geos::geom::Polygon*>(geos_geometry->getGeometryN(i));
      for(unsigned int r=0;r<polygon->getNumInteriorRing();r++)
      {
        rings->push_back((geos::geom::LineString*)polygon->getInteriorRingN(r));
      }
    }
    geos_result = get_geometryFactory()->createMultiLineString(rings);
  }
  /*else if(geometric_type == GMLSF_CURVE)
  {
    geos::geom::LineString *linestring = curveToLineString(geos_geometry);
    try{                                                                                  
      geos_result = linestring->getBoundary();                                  
    }catch(std::exception &excep)                                                         
    {                                                                                     
      delete geos_geometry;                                                               
      std::stringstream lErrorMessage;                                                    
      lErrorMessage << "Error in GEOS function getBoundary : " << excep.what();  
      throwError(lErrorMessage.str(), XPTY0004);                                          
    }         
    delete linestring;
  }
  */
  else
  {
    try{                                                                                  
      geos_result = geos_geometry->getBoundary();                                  
    }catch(std::exception &excep)                                                         
    {                                                                                     
      delete geos_geometry;                                                               
      std::stringstream lErrorMessage;                                                    
      lErrorMessage << "Error in GEOS function getBoundary : " << excep.what();  
      throwError(lErrorMessage.str(), XPTY0004);                                          
    }                                                                                     
  }

  zorba::Item   null_parent;                                                            
  zorba::Item   result_item;                                                            
  result_item = getGMLItemFromGeosGeometry(null_parent, geos_result, &srs_uri, 0, NULL, DONT_CHECK_FOR_CURVE_SURFACE);         
  delete geos_result;  
  return result_item;
}

void GeoFunction::getMultiGeometryBoundary(geos::geom::Geometry *geos_geometry, 
                                           std::vector<zorba::Item> *boundaries,
                                           zorba::Item srs_uri) const 
{
  for(unsigned int i=0;i<geos_geometry->getNumGeometries();i++)
  {
    geos::geom::Geometry *geom = (geos::geom::Geometry *)geos_geometry->getGeometryN(i);
    if(geom->getGeometryTypeId() == geos::geom::GEOS_GEOMETRYCOLLECTION)
      getMultiGeometryBoundary(geom, boundaries, srs_uri);
    else
    {
      zorba::Item boundary;
      boundary = getBoundary(geom, srs_uri);
      boundaries->push_back(boundary);
    }
  }
}

ItemSequence_t                                                                          
SFBoundaryFunction::evaluate(const StatelessExternalFunction::Arguments_t& args,              
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
      zorba::Item item_qname;                                                           
      lItem.getNodeName(item_qname);                                                    
      lErrorMessage << "Unrecognized geometric type for element "                       
           << item_qname.getPrefix() <<":"<<item_qname.getLocalName() << ".";           
      throwError(lErrorMessage.str(), XPTY0004);                                        
    }                                                                                   
    break;                                                                              
  default:                                                                              
    break;                                                                              
  }                                                                                     
                                                                                        
  geos::geom::Geometry  *geos_geometry;                                                 
  zorba::Item srs_uri;                                                                  
  geos_geometry = buildGeosGeometryFromItem(lItem, geometric_type, -1, &srs_uri);       

  if(geometric_type != GMLSF_MULTIGEOMETRY)
  {
    zorba::Item result_item;
    result_item = getBoundary(geos_geometry, srs_uri);
    delete geos_geometry;                                                                 
    return ItemSequence_t(new SingletonItemSequence(result_item));                        
  }
  else
  {
    std::vector<zorba::Item>  boundaries;
    getMultiGeometryBoundary(geos_geometry, &boundaries, srs_uri);
    delete geos_geometry;
    return ItemSequence_t(new VectorItemSequence(boundaries));
  }
                                                                                        
}

///////////////////////////////////////////////////////////////////////
ItemSequence_t 
SFSridFunction::evaluate(const StatelessExternalFunction::Arguments_t& args,
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
      zorba::Item item_qname;
      lItem.getNodeName(item_qname);
      lErrorMessage << "Unrecognized geometric type for element " 
           << item_qname.getPrefix() <<":"<<item_qname.getLocalName() << ".";
      throwError(lErrorMessage.str(), XPTY0004);
    }
    break;
  default:
    break;
  }

  geos::geom::Geometry  *geos_geometry;
  zorba::Item  srs_uri;
  geos_geometry = buildGeosGeometryFromItem(lItem, geometric_type, -1, &srs_uri);

  delete geos_geometry;

  if(!srs_uri.isNull())
    return ItemSequence_t(new SingletonItemSequence(srs_uri));
  else
    return ItemSequence_t(NULL);
}

///////////////////////////////////////////////////////////////////////
ItemSequence_t 
SFEnvelopeFunction::evaluate(const StatelessExternalFunction::Arguments_t& args,
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
      zorba::Item item_qname;
      lItem.getNodeName(item_qname);
      lErrorMessage << "Unrecognized geometric type for element " 
           << item_qname.getPrefix() <<":"<<item_qname.getLocalName() << ".";
      throwError(lErrorMessage.str(), XPTY0004);
    }
    break;
  default:
    break;
  }

  geos::geom::Geometry  *geos_geometry;
  zorba::Item  srs_uri;
  geos_geometry = buildGeosGeometryFromItem(lItem, geometric_type, -1, &srs_uri);

  const geos::geom::Envelope  *envelope = NULL;                                            
  try{                                                                                  
    envelope = geos_geometry->getEnvelopeInternal();                                  
  }catch(std::exception &excep)                                                         
  {                                                                                     
    delete geos_geometry;                                                               
    std::stringstream lErrorMessage;                                                    
    lErrorMessage << "Error in GEOS function getEnvelopeInternal : " << excep.what();  
    throwError(lErrorMessage.str(), XPTY0004);                                          
  }                                                                                     


  zorba::Item   envelope_item;
  zorba::Item   corner_item;
  zorba::Item   item_name;
  zorba::Item   item_type;
  zorba::Item   null_parent;                                                      
  std::vector<std::pair<String, String> >   ns_binding;
  char strtemp[100];
  ns_binding.push_back(std::pair<String, String>("gml", "http://www.opengis.net/gml"));
  item_type = theModule->getItemFactory()->createQName("http://www.w3.org/2001/XMLSchema", "untyped");
  item_name = theModule->getItemFactory()->createQName("http://www.opengis.net/gml", "gml", "Envelope");
  envelope_item = theModule->getItemFactory()->createElementNode(null_parent, item_name, item_type, false, false, ns_binding);

  if(!srs_uri.isNull())
  {
    item_type = theModule->getItemFactory()->createQName("http://www.w3.org/2001/XMLSchema", "untyped");
    item_name = theModule->getItemFactory()->createQName("", "srsName");
    zorba::String   strvalue = srs_uri.getStringValue();
    zorba::Item attr_value_item = theModule->getItemFactory()->createString(strvalue);
    theModule->getItemFactory()->createAttributeNode(envelope_item, item_name, item_type, attr_value_item);
  }
  item_type = theModule->getItemFactory()->createQName("http://www.w3.org/2001/XMLSchema", "untyped");
  item_name = theModule->getItemFactory()->createQName("http://www.opengis.net/gml", "gml", "lowerCorner");
  addNewLineIndentText(envelope_item, 2);
  corner_item = theModule->getItemFactory()->createElementNode(envelope_item, item_name, item_type, false, false, ns_binding);

  sprintf(strtemp, "%lf %lf", envelope->getMinX(), envelope->getMinY());
  theModule->getItemFactory()->createTextNode(corner_item, strtemp);

  item_type = theModule->getItemFactory()->createQName("http://www.w3.org/2001/XMLSchema", "untyped");
  item_name = theModule->getItemFactory()->createQName("http://www.opengis.net/gml", "gml", "upperCorner");
  addNewLineIndentText(envelope_item, 2);
  corner_item = theModule->getItemFactory()->createElementNode(envelope_item, item_name, item_type, false, false, ns_binding);

  sprintf(strtemp, "%lf %lf", envelope->getMaxX(), envelope->getMaxY());
  theModule->getItemFactory()->createTextNode(corner_item, strtemp);
  addNewLineIndentText(envelope_item, 0);

  delete geos_geometry;
  return ItemSequence_t(new SingletonItemSequence(envelope_item));
}

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
      zorba::Item item_qname;
      lItem.getNodeName(item_qname);
      lErrorMessage << "Unrecognized geometric type for element " 
           << item_qname.getPrefix() <<":"<<item_qname.getLocalName() << ".";
      throwError(lErrorMessage.str(), XPTY0004);
    }
    break;
  default:
    break;
  }

  geos::geom::Geometry  *geos_geometry;
  geos_geometry = buildGeosGeometryFromItem(lItem, geometric_type, -1);

  std::string as_text;
  as_text = geos_geometry->toString();
  delete geos_geometry;

  return ItemSequence_t(new SingletonItemSequence(
      theModule->getItemFactory()->createString(as_text)));
}

unsigned char GeoFunction::hex_to_bin(char hex) const
{
  if((hex >= '0') && (hex <= '9'))
    return hex-'0';
  else if((hex >= 'a') && (hex <= 'f'))
    return hex-'a'+10;
  else if((hex >= 'A') && (hex <= 'F'))
    return hex-'A'+10;
  else
    return 0;
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
      zorba::Item item_qname;
      lItem.getNodeName(item_qname);
      lErrorMessage << "Unrecognized geometric type for element " 
           << item_qname.getPrefix() <<":"<<item_qname.getLocalName() << ".";
      throwError(lErrorMessage.str(), XPTY0004);
    }
    break;
  default:
    break;
  }

  geos::geom::Geometry  *geos_geometry;
  geos_geometry = buildGeosGeometryFromItem(lItem, geometric_type, -1);

  std::ostringstream as_binary;
  as_binary << *geos_geometry;
  delete geos_geometry;
  
  std::string binary_hex = as_binary.str();
  size_t binary_len = binary_hex.size() / 2;
  const char *hex_str = binary_hex.c_str();
  unsigned char *binary_bin = new unsigned char[binary_len];
  for(size_t i=0;i<binary_len;i++)
  {
    binary_bin[i] = ((hex_to_bin(hex_str[i*2]) << 4) | hex_to_bin(hex_str[i*2+1]));
  }

  zorba::Item base64_item = theModule->getItemFactory()->createBase64Binary(binary_bin, binary_len);
  delete[] binary_bin;

  return ItemSequence_t(new SingletonItemSequence(base64_item));
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
  if(geotype == GMLSF_INVALID)
  {
    return ItemSequence_t(new SingletonItemSequence(
      theModule->getItemFactory()->createBoolean(true)));
  }
  
  geos::geom::Geometry  *geos_geometry;
  geos_geometry = buildGeosGeometryFromItem(lItem, geotype, -1);

  bool is_empty = false;
  try{
  is_empty = (geos_geometry->getNumPoints() == 0);
  delete geos_geometry;
  }catch(std::exception &excep)                                              
  {                                                                                     
    delete geos_geometry;                                                               
    std::stringstream lErrorMessage;                                                    
    lErrorMessage << "Error in GEOS function getNumGeometries : " << excep.what();  
    throwError(lErrorMessage.str(), XPTY0004);                                          
  }                                                                                     

  return ItemSequence_t(new SingletonItemSequence(
     theModule->getItemFactory()->createBoolean(is_empty)));
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
      zorba::Item item_qname;
      lItem.getNodeName(item_qname);
      lErrorMessage << "Unrecognized geometric type for element " 
           << item_qname.getPrefix() <<":"<<item_qname.getLocalName() << ".";
      throwError(lErrorMessage.str(), XPTY0004);
    }
    break;
  default:
    break;
  }

  geos::geom::Geometry  *geos_geometry;
  geos_geometry = buildGeosGeometryFromItem(lItem, geometric_type, -1);

  bool is_simple = false;
  if(geometric_type == GMLSF_CURVE)
  {
    is_simple = isSimpleCurve(geos_geometry);
  }
  else
  {
    try{
    is_simple = geos_geometry->isSimple();
    }catch(std::exception &excep)                                              
    {                                                                                     
      delete geos_geometry;                                                               
      std::stringstream lErrorMessage;                                                    
      lErrorMessage << "Error in GEOS function isSimple : " << excep.what();  
      throwError(lErrorMessage.str(), XPTY0004);                                          
    }                                                                                     
  }
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
      zorba::Item item_qname;
      lItem.getNodeName(item_qname);
      lErrorMessage << "Unrecognized geometric type for element " 
           << item_qname.getPrefix() <<":"<<item_qname.getLocalName() << ".";
      throwError(lErrorMessage.str(), XPTY0004);
    }
    break;
  default:
    break;
  }

  geos::geom::Geometry  *geos_geometry;
  geos_geometry = buildGeosGeometryFromItem(lItem, geometric_type, -1);

#if GEOS_VERSION_MAJOR > 3 || (GEOS_VERSION_MAJOR == 3 && GEOS_VERSION_MINOR > 2)
  bool is_3D = (geos_geometry->getCoordinateDimension() == 3);
#else
  bool is_3D = (getCoordinateDimension(geos_geometry) == 3);//for GEOS 3.2.2
#endif
  delete geos_geometry;

  return ItemSequence_t(new SingletonItemSequence(
     theModule->getItemFactory()->createBoolean(is_3D)));
}

///////////////////////////////////////////////////////////////////////
ItemSequence_t 
SFIsMeasuredFunction::evaluate(const StatelessExternalFunction::Arguments_t& args,
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
      zorba::Item item_qname;
      lItem.getNodeName(item_qname);
      lErrorMessage << "Unrecognized geometric type for element " 
           << item_qname.getPrefix() <<":"<<item_qname.getLocalName() << ".";
      throwError(lErrorMessage.str(), XPTY0004);
    }
    break;
  default:
    break;
  }

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
      zorba::Item item_qname1;                                                    \
      lItem1.getNodeName(item_qname1);                                            \
      lErrorMessage << "Unrecognized geometric type for element "                 \
           << item_qname1.getPrefix() <<":"<<item_qname1.getLocalName() << " in first parameter.";    \
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
      zorba::Item item_qname2;                                                    \
      lItem2.getNodeName(item_qname2);                                            \
      lErrorMessage << "Unrecognized geometric type for element "                 \
           << item_qname2.getPrefix() <<":"<<item_qname2.getLocalName() << " in second parameter.";   \
      throwError(lErrorMessage.str(), XPTY0004);                                  \
    }                                                                             \
    break;                                                                        \
  default:                                                                        \
    break;                                                                        \
  }                                                                               \
                                                                                  \
  geos::geom::Geometry  *geos_geometry1;                                          \
  zorba::Item srs_uri1;                                                           \
  geos_geometry1 = buildGeosGeometryFromItem(lItem1, geometric_type1, -1, &srs_uri1);            \
                                                                                  \
  geos::geom::Geometry  *geos_geometry2;                                          \
  zorba::Item srs_uri2;                                                           \
  geos_geometry2 = buildGeosGeometryFromItem(lItem2, geometric_type2, -1, &srs_uri1);            \
                                                                                  \
  if(!srs_uri1.isNull() && !srs_uri2.isNull() &&                                  \
    !srs_uri1.getStringValue().equals(srs_uri2.getStringValue()))                 \
  {                                                                               \
    delete geos_geometry1;                                                        \
    delete geos_geometry2;                                                        \
    std::stringstream lErrorMessage;                                              \
    lErrorMessage << "SrsName is not the same in the two geometries: " <<         \
                  srs_uri1.getStringValue() << " vs. " << srs_uri2.getStringValue();  \
    throwError(lErrorMessage.str(), XPTY0004);                                    \
  }                                                                               \
                                                                                  \
  bool retval = false;                                                            \
  try{                                                                            \
  retval = geos_geometry1->geos_function_name(geos_geometry2);                    \
  }catch(std::exception &excep)                                                   \
  {                                                                               \
    delete geos_geometry1;                                                        \
    delete geos_geometry2;                                                        \
    std::stringstream lErrorMessage;                                              \
    lErrorMessage << "Error in GEOS function " #geos_function_name " : " << excep.what();  \
    throwError(lErrorMessage.str(), XPTY0004);                                    \
  }                                                                               \
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
  switch(geometric_type1)                                                         \
  {                                                                               \
  case GMLSF_INVALID:                                                             \
    {                                                                             \
      std::stringstream lErrorMessage;                                            \
      zorba::Item item_qname1;                                                    \
      lItem1.getNodeName(item_qname1);                                            \
      lErrorMessage << "Unrecognized geometric type for element "                 \
           << item_qname1.getPrefix() <<":"<<item_qname1.getLocalName() << " in first parameter.";    \
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
      zorba::Item item_qname2;                                                    \
      lItem2.getNodeName(item_qname2);                                            \
      lErrorMessage << "Unrecognized geometric type for element "                 \
           << item_qname2.getPrefix() <<":"<<item_qname2.getLocalName() << " in second parameter.";   \
      throwError(lErrorMessage.str(), XPTY0004);                                  \
    }                                                                             \
    break;                                                                        \
  default:                                                                        \
    break;                                                                        \
  }                                                                               \
                                                                                  \
  geos::geom::Geometry  *geos_geometry1;                                          \
  zorba::Item srs_uri1;                                                           \
  geos_geometry1 = buildGeosGeometryFromItem(lItem1, geometric_type1, -1, &srs_uri1);            \
                                                                                  \
  geos::geom::Geometry  *geos_geometry2;                                          \
  zorba::Item srs_uri2;                                                           \
  geos_geometry2 = buildGeosGeometryFromItem(lItem2, geometric_type2, -1, &srs_uri2);            \
                                                                                  \
  if(!srs_uri1.isNull() && !srs_uri2.isNull() &&                                  \
    !srs_uri1.getStringValue().equals(srs_uri2.getStringValue()))                 \
  {                                                                               \
    delete geos_geometry1;                                                        \
    delete geos_geometry2;                                                        \
    std::stringstream lErrorMessage;                                              \
    lErrorMessage << "SrsName is not the same in the two geometries: " <<         \
                  srs_uri1.getStringValue() << " vs. " << srs_uri2.getStringValue();  \
    throwError(lErrorMessage.str(), XPTY0004);                                    \
  }                                                                               \
                                                                                  \
  geos::geom::Geometry  *geos_result = NULL;                                      \
  try{                                                                            \
  geos_result = geos_geometry1->geos_function_name(geos_geometry2);               \
  }catch(std::exception &excep)                                                   \
  {                                                                               \
    delete geos_geometry1;                                                        \
    delete geos_geometry2;                                                        \
    std::stringstream lErrorMessage;                                              \
    lErrorMessage << "Error in GEOS function " #geos_function_name " : " << excep.what();  \
    throwError(lErrorMessage.str(), XPTY0004);                                    \
  }                                                                               \
                                                                                  \
                                                                                  \
  if(srs_uri1.isNull())                                                           \
    srs_uri1 = srs_uri2;                                                          \
  zorba::Item   null_parent;                                                      \
  zorba::Item   result_item;                                                      \
  result_item = getGMLItemFromGeosGeometry(null_parent, geos_result, &srs_uri1);   \
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
      zorba::Item item_qname;                                                           \
      lItem.getNodeName(item_qname);                                                    \
      lErrorMessage << "Unrecognized geometric type for element "                       \
           << item_qname.getPrefix() <<":"<<item_qname.getLocalName() << ".";           \
      throwError(lErrorMessage.str(), XPTY0004);                                        \
    }                                                                                   \
    break;                                                                              \
  default:                                                                              \
    break;                                                                              \
  }                                                                                     \
                                                                                        \
  geos::geom::Geometry  *geos_geometry;                                                 \
  geos_geometry = buildGeosGeometryFromItem(lItem, geometric_type, -1);                 \
                                                                                        \
  double  retval = 0;                                                                   \
  try{                                                                                  \
  retval = geos_geometry->geos_function_name();                                         \
  }catch(std::exception &excep)                                                         \
  {                                                                                     \
    delete geos_geometry;                                                               \
    std::stringstream lErrorMessage;                                                    \
    lErrorMessage << "Error in GEOS function " #geos_function_name " : " << excep.what();  \
    throwError(lErrorMessage.str(), XPTY0004);                                          \
  }                                                                                     \
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
      zorba::Item item_qname1;
      lItem1.getNodeName(item_qname1);
      lErrorMessage << "Unrecognized geometric type for element "                 
           << item_qname1.getPrefix() <<":"<<item_qname1.getLocalName() << " in first parameter.";    
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
      zorba::Item item_qname2;
      lItem2.getNodeName(item_qname2);
      lErrorMessage << "Unrecognized geometric type for third element "                 
           << item_qname2.getPrefix() <<":"<<item_qname2.getLocalName() << " in second parameter.";   
      throwError(lErrorMessage.str(), XPTY0004);                                  
    }                                                                             
    break;                                                                        
  default:                                                                        
    break;                                                                        
  }                                                                               
                                                                                  
  geos::geom::Geometry  *geos_geometry1;          
  zorba::Item  srs_uri1;
  geos_geometry1 = buildGeosGeometryFromItem(lItem1, geometric_type1, -1, &srs_uri1);            
                                                                                  
  geos::geom::Geometry  *geos_geometry2;                                          
  zorba::Item  srs_uri2;
  geos_geometry2 = buildGeosGeometryFromItem(lItem2, geometric_type2, -1, &srs_uri2);            
                                                                                  
  if(!srs_uri1.isNull() && !srs_uri2.isNull() &&                                  
    !srs_uri1.getStringValue().equals(srs_uri2.getStringValue()))                 
  {                                                                               
    delete geos_geometry1;                                                        
    delete geos_geometry2;                                                        
    std::stringstream lErrorMessage;                                              
    lErrorMessage << "SrsName is not the same in the two geometries: " <<         
                  srs_uri1.getStringValue() << " vs. " << srs_uri2.getStringValue();  
    throwError(lErrorMessage.str(), XPTY0004);                                    
  }                                                                               
                                                                                  
                                                                                        
  Item lItem3;                                                                           
  if (!args[2]->next(lItem3)) 
  {
    std::stringstream lErrorMessage;
    lErrorMessage << "An empty-sequence is not allowed as parameter";
    throwError(lErrorMessage.str(), XPTY0004);
  }

  zorba::String intersection_matrix;
  intersection_matrix = lItem3.getStringValue();

  bool is_relate = false;                                                   
  try{
    is_relate = geos_geometry1->relate(geos_geometry2, intersection_matrix.c_str());                                    
  }catch(std::exception &excep)
  {
    delete geos_geometry1;
    delete geos_geometry2;
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
      zorba::Item item_qname1;
      lItem1.getNodeName(item_qname1);
      lErrorMessage << "Unrecognized geometric type for element "                 
           << item_qname1.getPrefix() <<":"<<item_qname1.getLocalName() << " in first parameter.";    
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
      zorba::Item item_qname2;
      lItem2.getNodeName(item_qname2);
      lErrorMessage << "Unrecognized geometric type for element "                 
           << item_qname2.getPrefix() <<":"<<item_qname2.getLocalName() << " in second parameter.";   
      throwError(lErrorMessage.str(), XPTY0004);                                  
    }                                                                             
    break;                                                                        
  default:                                                                        
    break;                                                                        
  }                                                                               
                                                                                  
  geos::geom::Geometry  *geos_geometry1; 
  zorba::Item  srs_uri1;
  geos_geometry1 = buildGeosGeometryFromItem(lItem1, geometric_type1, -1, &srs_uri1);            
                                                                                  
  geos::geom::Geometry  *geos_geometry2;                                          
  zorba::Item  srs_uri2;
  geos_geometry2 = buildGeosGeometryFromItem(lItem2, geometric_type2, -1, &srs_uri2);            
                                                                                  
  if(!srs_uri1.isNull() && !srs_uri2.isNull() &&                                  
    !srs_uri1.getStringValue().equals(srs_uri2.getStringValue()))                 
  {                                                                               
    delete geos_geometry1;                                                        
    delete geos_geometry2;                                                        
    std::stringstream lErrorMessage;                                              
    lErrorMessage << "SrsName is not the same in the two geometries: " <<         
                  srs_uri1.getStringValue() << " vs. " << srs_uri2.getStringValue();  
    throwError(lErrorMessage.str(), XPTY0004);                                    
  }                                                                               
                                                                                        
  Item lItem3;                                                                           
  if (!args[2]->next(lItem3)) 
  {
    std::stringstream lErrorMessage;
    lErrorMessage << "An empty-sequence is not allowed as third parameter";
    throwError(lErrorMessage.str(), XPTY0004);
  }

  double distance;
  distance = lItem3.getDoubleValue();

  bool is_within_distance = false;                                                   
  try{
  is_within_distance = geos_geometry1->isWithinDistance(geos_geometry2, distance);                                    
  }catch(std::exception &excep)                                        
  {                                                                               
    delete geos_geometry1;                                                        
    delete geos_geometry2;                                                        
    std::stringstream lErrorMessage;                                              
    lErrorMessage << "Error in GEOS function isWithinDistance : " << excep.what();  
    throwError(lErrorMessage.str(), XPTY0004);                                    
  }                                                                               
                                                                                        
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
      zorba::Item item_qname1;
      lItem1.getNodeName(item_qname1);
      lErrorMessage << "Unrecognized geometric type for element "                 
           << item_qname1.getPrefix() <<":"<<item_qname1.getLocalName() << " in first parameter.";    
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
      zorba::Item item_qname2;
      lItem2.getNodeName(item_qname2);
      lErrorMessage << "Unrecognized geometric type for element "                 
           << item_qname2.getPrefix() <<":"<<item_qname2.getLocalName() << " in second parameter.";   
      throwError(lErrorMessage.str(), XPTY0004);                                  
    }                                                                             
    break;                                                                        
  default:                                                                        
    break;                                                                        
  }                                                                               
                                                                                  
  geos::geom::Geometry  *geos_geometry1; 
  zorba::Item  srs_uri1;
  geos_geometry1 = buildGeosGeometryFromItem(lItem1, geometric_type1, -1, &srs_uri1);            
                                                                                  
  geos::geom::Geometry  *geos_geometry2;                                          
  zorba::Item  srs_uri2;
  geos_geometry2 = buildGeosGeometryFromItem(lItem2, geometric_type2, -1, &srs_uri2);            
                                                                                  
  if(!srs_uri1.isNull() && !srs_uri2.isNull() &&                                  
    !srs_uri1.getStringValue().equals(srs_uri2.getStringValue()))                 
  {                                                                               
    delete geos_geometry1;                                                        
    delete geos_geometry2;                                                        
    std::stringstream lErrorMessage;                                              
    lErrorMessage << "SrsName is not the same in the two geometries: " <<         
                  srs_uri1.getStringValue() << " vs. " << srs_uri2.getStringValue();  
    throwError(lErrorMessage.str(), XPTY0004);                                    
  }
                                                                                        
  double min_distance = 0;                                                   
  try{
  min_distance = geos_geometry1->distance(geos_geometry2);                                    
  }catch(std::exception &excep)                                        
  {                                                                               
    delete geos_geometry1;                                                        
    delete geos_geometry2;                                                        
    std::stringstream lErrorMessage;                                              
    lErrorMessage << "Error in GEOS function distance : " << excep.what();  
    throwError(lErrorMessage.str(), XPTY0004);                                    
  }                                                                               
                                                                                        
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
      zorba::Item item_qname1;
      lItem1.getNodeName(item_qname1);
      lErrorMessage << "Unrecognized geometric type for element "                 
           << item_qname1.getPrefix() <<":"<<item_qname1.getLocalName() << " in first parameter.";    
      throwError(lErrorMessage.str(), XPTY0004);                                  
    }                                                                             
    break;                                                                        
  default:                                                                        
    break;                                                                        
  }                                                                               
                                                                                  
  geos::geom::Geometry  *geos_geometry1;                                          
  zorba::Item srs_uri;
  geos_geometry1 = buildGeosGeometryFromItem(lItem1, geometric_type1, -1, &srs_uri);            
                                                                                  
                                                                                        
  Item lItem2;                                                                           
  if (!args[1]->next(lItem2)) 
  {
    std::stringstream lErrorMessage;
    lErrorMessage << "An empty-sequence is not allowed as second parameter";
    throwError(lErrorMessage.str(), XPTY0004);
  }

  double distance;
  distance = lItem2.getDoubleValue();
                                                                                        
  geos::geom::Geometry  *geos_result = NULL;                                          
  try{
  geos_result = geos_geometry1->buffer(distance);                                    
  }catch(std::exception &excep)                                        
  {                                                                               
    delete geos_geometry1;                                                        
    std::stringstream lErrorMessage;                                              
    lErrorMessage << "Error in GEOS function buffer : " << excep.what();  
    throwError(lErrorMessage.str(), XPTY0004);                                    
  }                                                                               

  zorba::Item   null_parent;                                                      
  zorba::Item   result_item;                                                      
  result_item = getGMLItemFromGeosGeometry(null_parent, geos_result, &srs_uri);             
  delete geos_geometry1;                                                          
  delete geos_result;                                                             
                                                                                  
  return ItemSequence_t(new SingletonItemSequence(result_item));                  
}

///////////////////////////////////////////////////////////////////////
#define DEFINE_EVALUATE_ONE_POINT_RETURN_DOUBLE(sfclass_name, geos_function_name)       \
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
      zorba::Item item_qname;                                                           \
      lItem.getNodeName(item_qname);                                                    \
      lErrorMessage << "Unrecognized geometric type for element "                       \
           << item_qname.getPrefix() <<":"<<item_qname.getLocalName() << ".";           \
      throwError(lErrorMessage.str(), XPTY0004);                                        \
    }                                                                                   \
    break;                                                                              \
  case GMLSF_POINT:                                                                     \
    break;                                                                              \
  default:                                                                              \
    {                                                                                   \
      std::stringstream lErrorMessage;                                                  \
      zorba::Item item_qname;                                                           \
      lItem.getNodeName(item_qname);                                                    \
      lErrorMessage << "Geometry must be a point: "                                     \
           << item_qname.getPrefix() <<":"<<item_qname.getLocalName() << ".";           \
      throwError(lErrorMessage.str(), XPTY0004);                                        \
    }                                                                                   \
    break;                                                                              \
  }                                                                                     \
                                                                                        \
  geos::geom::Geometry  *geos_geometry;                                                 \
  geos_geometry = buildGeosGeometryFromItem(lItem, geometric_type, -1);                     \
  geos::geom::Point   *geos_point = dynamic_cast<geos::geom::Point*>(geos_geometry);    \
                                                                                        \
  double  retval = 0;                                                                   \
  try{                                                                                  \
  retval = geos_point->geos_function_name();                                            \
  }catch(std::exception &excep)                                                         \
  {                                                                                     \
    delete geos_geometry;                                                               \
    std::stringstream lErrorMessage;                                                    \
    lErrorMessage << "Error in GEOS function " #geos_function_name " : " << excep.what();  \
    throwError(lErrorMessage.str(), XPTY0004);                                          \
  }                                                                                     \
                                                                                        \
  return ItemSequence_t(new SingletonItemSequence(                                      \
     theModule->getItemFactory()->createDouble(retval)));                               \
}

DEFINE_EVALUATE_ONE_POINT_RETURN_DOUBLE(SFXFunction, getX)
DEFINE_EVALUATE_ONE_POINT_RETURN_DOUBLE(SFYFunction, getY)

ItemSequence_t                                                                          
SFZFunction::evaluate(const StatelessExternalFunction::Arguments_t& args,              
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
      zorba::Item item_qname;                                                           
      lItem.getNodeName(item_qname);                                                    
      lErrorMessage << "Unrecognized geometric type for element "                       
           << item_qname.getPrefix() <<":"<<item_qname.getLocalName() << ".";           
      throwError(lErrorMessage.str(), XPTY0004);                                        
    }                                                                                   
    break;                                                                              
  case GMLSF_POINT:                                                                     
    break;                                                                              
  default:                                                                              
    {                                                                                   
      std::stringstream lErrorMessage;                                                  
      zorba::Item item_qname;                                                           
      lItem.getNodeName(item_qname);                                                    
      lErrorMessage << "Geometry must be a point: "                                     
           << item_qname.getPrefix() <<":"<<item_qname.getLocalName() << ".";           
      throwError(lErrorMessage.str(), XPTY0004);                                        
    }                                                                                   
    break;                                                                              
  }                                                                                     
  geos::geom::Geometry  *geos_geometry;                                                 
  geos_geometry = buildGeosGeometryFromItem(lItem, geometric_type, -1);                     

  const geos::geom::Coordinate  *c;
  c = geos_geometry->getCoordinate();
#if GEOS_VERSION_MAJOR > 3 || (GEOS_VERSION_MAJOR == 3 && GEOS_VERSION_MINOR > 2)
  if(geos_geometry->getCoordinateDimension() == 3)
#else
  if(getCoordinateDimension(geos_geometry) == 3)
#endif
  {
    double z = c->z;
    delete geos_geometry;
    return ItemSequence_t(new SingletonItemSequence(                                      
       theModule->getItemFactory()->createDouble(z)));                               
  }
  else
  {
    delete geos_geometry;
    return zorba::ItemSequence_t(NULL);
  }

}

ItemSequence_t                                                                          
SFMFunction::evaluate(const StatelessExternalFunction::Arguments_t& args,              
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
      zorba::Item item_qname;                                                           
      lItem.getNodeName(item_qname);                                                    
      lErrorMessage << "Unrecognized geometric type for element "                       
           << item_qname.getPrefix() <<":"<<item_qname.getLocalName() << ".";           
      throwError(lErrorMessage.str(), XPTY0004);                                        
    }                                                                                   
    break;                                                                              
  case GMLSF_POINT:                                                                     
    break;                                                                              
  default:                                                                              
    {                                                                                   
      std::stringstream lErrorMessage;                                                  
      zorba::Item item_qname;                                                           
      lItem.getNodeName(item_qname);                                                    
      lErrorMessage << "Geometry must be a point: "                                     
           << item_qname.getPrefix() <<":"<<item_qname.getLocalName() << ".";           
      throwError(lErrorMessage.str(), XPTY0004);                                        
    }                                                                                   
    break;                                                                              
  }                                                                                     

  //don't know how to get the Measure from Point
  return zorba::ItemSequence_t(NULL);

}


ItemSequence_t                                                                          
SFStartPointFunction::evaluate(const StatelessExternalFunction::Arguments_t& args,              
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
      zorba::Item item_qname1;
      lItem1.getNodeName(item_qname1);
      lErrorMessage << "Unrecognized geometric type for element "                 
           << item_qname1.getPrefix() <<":"<<item_qname1.getLocalName() << " in first parameter.";    
      throwError(lErrorMessage.str(), XPTY0004);                                  
    }                                                                             
    break;                                                                        
  case GMLSF_LINESTRING:                                                                
  case GMLSF_LINEARRING:                                                                
  case GMLSF_CURVE:
    break;                                                                              
  default:                                                                              
    {                                                                                   
      std::stringstream lErrorMessage;                                                  
      zorba::Item item_qname1;                                                           
      lItem1.getNodeName(item_qname1);                                                    
      lErrorMessage << "Geometry must be a line: "                                      
           << item_qname1.getPrefix() <<":"<<item_qname1.getLocalName() << ".";           
      throwError(lErrorMessage.str(), XPTY0004);                                        
    }                                                                                   
    break;                                                                              
  }                                                                               
                                                                                  
  uint32_t n = 0;
                                               
  Item    nth_child;
  buildGeosGeometryFromItem(lItem1, geometric_type1, -1, NULL, GET_NTH_POINT, &n, &nth_child);

  if(nth_child.isNull())
  {
    std::stringstream lErrorMessage;                                              
    lErrorMessage << "LineString has no points ";  
    throwError(lErrorMessage.str(), XPTY0004);                                    
  }
                                                                                  
  return ItemSequence_t(new SingletonItemSequence(nth_child));                  
}

ItemSequence_t                                                                          
SFEndPointFunction::evaluate(const StatelessExternalFunction::Arguments_t& args,              
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
      zorba::Item item_qname1;
      lItem1.getNodeName(item_qname1);
      lErrorMessage << "Unrecognized geometric type for element "                 
           << item_qname1.getPrefix() <<":"<<item_qname1.getLocalName() << " in first parameter.";    
      throwError(lErrorMessage.str(), XPTY0004);                                  
    }                                                                             
    break;                                                                        
  case GMLSF_LINESTRING:                                                                
  case GMLSF_LINEARRING:                                                                
  case GMLSF_CURVE:
    break;                                                                              
  default:                                                                              
    {                                                                                   
      std::stringstream lErrorMessage;                                                  
      zorba::Item item_qname1;                                                           
      lItem1.getNodeName(item_qname1);                                                    
      lErrorMessage << "Geometry must be a line: "                                      
           << item_qname1.getPrefix() <<":"<<item_qname1.getLocalName() << ".";           
      throwError(lErrorMessage.str(), XPTY0004);                                        
    }                                                                                   
    break;                                                                              
  }                                                                               
                                                                                  
  Item    nth_child;
  buildGeosGeometryFromItem(lItem1, geometric_type1, -1, NULL, GET_END_POINT, NULL, &nth_child);

  if(nth_child.isNull())
  {
    std::stringstream lErrorMessage;                                              
    lErrorMessage << "LineString has no points ";  
    throwError(lErrorMessage.str(), XPTY0004);                                    
  }
                                                                                  
  return ItemSequence_t(new SingletonItemSequence(nth_child));                  
}

///////////////////////////////////////////////////////////////////////
ItemSequence_t                                                                         
SFIsClosedFunction::evaluate(const StatelessExternalFunction::Arguments_t& args,              
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
      zorba::Item item_qname;                                                           
      lItem.getNodeName(item_qname);                                                    
      lErrorMessage << "Unrecognized geometric type for element "                       
           << item_qname.getPrefix() <<":"<<item_qname.getLocalName() << ".";           
      throwError(lErrorMessage.str(), XPTY0004);                                        
    }                                                                                   
    break;                                                                              
  case GMLSF_LINESTRING:
  case GMLSF_LINEARRING:
  case GMLSF_CURVE:
  case GMLSF_MULTICURVE:
  case GMLSF_SURFACE:
    break;                                                                              
  default:                                                                              
    {                                                                                   
      std::stringstream lErrorMessage;                                                  
      zorba::Item item_qname;                                                           
      lItem.getNodeName(item_qname);                                                    
      lErrorMessage << "Geometry must be a line or Surface: "                                      
           << item_qname.getPrefix() <<":"<<item_qname.getLocalName() << ".";           
      throwError(lErrorMessage.str(), XPTY0004);                                        
    }                                                                                   
    break;                                                                              
  }                                                                                     
                                                                                        
  geos::geom::Geometry  *geos_geometry;                                                 
  geos_geometry = buildGeosGeometryFromItem(lItem, geometric_type, -1);                     
                                                                                        
  bool  retval = 0;                                                               
  if(geometric_type == GMLSF_SURFACE)
  {
    if(!isSurface(dynamic_cast<geos::geom::MultiPolygon*>(geos_geometry), &retval))
      retval = false;
  }
  else if(geometric_type == GMLSF_CURVE)                                                     
  {                                                                                     
    retval = isClosedCurve(geos_geometry);                                  
  }
  else
  {
    try{                                                                                  
    if(geometric_type != GMLSF_MULTICURVE)
    {
      geos::geom::LineString   *geos_line = dynamic_cast<geos::geom::LineString*>(geos_geometry);    
      retval = geos_line->isClosed();                                             
    }
    else
    {
      geos::geom::MultiLineString   *geos_multiline = dynamic_cast<geos::geom::MultiLineString*>(geos_geometry);    
      retval = geos_multiline->isClosed();                                             
    }
    }catch(std::exception &excep)                                                         
    {                                                                                     
      delete geos_geometry;                                                               
      std::stringstream lErrorMessage;                                                    
      lErrorMessage << "Error in GEOS function SFIsClosedFunction : " << excep.what();  
      throwError(lErrorMessage.str(), XPTY0004);                                          
    }                                                                                     
  }                                                                                     
  delete geos_geometry;                                                                 
  return ItemSequence_t(new SingletonItemSequence(                                      
     theModule->getItemFactory()->createBoolean(retval)));                           
}

ItemSequence_t                                                                         
SFIsRingFunction::evaluate(const StatelessExternalFunction::Arguments_t& args,              
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
      zorba::Item item_qname;                                                           
      lItem.getNodeName(item_qname);                                                    
      lErrorMessage << "Unrecognized geometric type for element "                       
           << item_qname.getPrefix() <<":"<<item_qname.getLocalName() << ".";           
      throwError(lErrorMessage.str(), XPTY0004);                                        
    }                                                                                   
    break;                                                                              
  case GMLSF_LINESTRING:                                                                
  case GMLSF_LINEARRING:                                                                
  case GMLSF_CURVE:                                                                     
    break;                                                                              
  default:                                                                              
    {                                                                                   
      std::stringstream lErrorMessage;                                                  
      zorba::Item item_qname;                                                           
      lItem.getNodeName(item_qname);                                                    
      lErrorMessage << "Geometry must be a line: "                                      
           << item_qname.getPrefix() <<":"<<item_qname.getLocalName() << ".";           
      throwError(lErrorMessage.str(), XPTY0004);                                        
    }                                                                                   
    break;                                                                              
  }                                                                                     
                                                                                        
  geos::geom::Geometry  *geos_geometry;                                                 
  geos_geometry = buildGeosGeometryFromItem(lItem, geometric_type, -1);                     
                                                                                        
  bool  retval = 0;                                                               
  if(geometric_type != GMLSF_CURVE)                                                     
  {                                                                                     
  try{                                                                                  
    geos::geom::LineString   *geos_line = dynamic_cast<geos::geom::LineString*>(geos_geometry);    
    retval = geos_line->isClosed();                                             
  }catch(std::exception &excep)                                                         
  {                                                                                     
    delete geos_geometry;                                                               
    std::stringstream lErrorMessage;                                                    
    lErrorMessage << "Error in GEOS function SFIsRingFunction : " << excep.what();  
    throwError(lErrorMessage.str(), XPTY0004);                                          
  }                                                                                     
  }                                                                                     
  else                                                                                  
  {                                                                                     
    retval = isRingCurve(geos_geometry);                                  
  }                                                                                     
  delete geos_geometry;                                                                 
  return ItemSequence_t(new SingletonItemSequence(                                      
     theModule->getItemFactory()->createBoolean(retval)));                           
}

ItemSequence_t                                                                          
SFNumPointsFunction::evaluate(const StatelessExternalFunction::Arguments_t& args,              
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
      zorba::Item item_qname;
      lItem.getNodeName(item_qname);
      lErrorMessage << "Unrecognized geometric type for element "                 
           << item_qname.getPrefix() <<":"<<item_qname.getLocalName() << " in first parameter.";    
      throwError(lErrorMessage.str(), XPTY0004);                                  
    }                                                                             
    break;                                                                        
  case GMLSF_LINESTRING:                                                                
  case GMLSF_LINEARRING:                                                                
  case GMLSF_CURVE:
  case GMLSF_MULTICURVE:
    break;                                                                              
  default:                                                                              
    {                                                                                   
      std::stringstream lErrorMessage;                                                  
      zorba::Item item_qname;                                                           
      lItem.getNodeName(item_qname);                                                    
      lErrorMessage << "Geometry must be a line: "                                      
           << item_qname.getPrefix() <<":"<<item_qname.getLocalName() << ".";           
      throwError(lErrorMessage.str(), XPTY0004);                                        
    }                                                                                   
    break;                                                                              
  }                                                                               
                                                                                        
  uint32_t  num_children;
  buildGeosGeometryFromItem(lItem, geometric_type, -1, NULL, GET_NUM_POINTS, &num_children);

  return ItemSequence_t(new SingletonItemSequence(                                      
     theModule->getItemFactory()->createUnsignedInt(num_children)));                           
}

ItemSequence_t                                                                          
SFPointNFunction::evaluate(const StatelessExternalFunction::Arguments_t& args,              
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
      zorba::Item item_qname1;
      lItem1.getNodeName(item_qname1);
      lErrorMessage << "Unrecognized geometric type for element "                 
           << item_qname1.getPrefix() <<":"<<item_qname1.getLocalName() << " in first parameter.";    
      throwError(lErrorMessage.str(), XPTY0004);                                  
    }                                                                             
    break;                                                                        
  case GMLSF_LINESTRING:                                                                
  case GMLSF_LINEARRING:                                                                
  case GMLSF_CURVE:
  case GMLSF_MULTICURVE:
    break;                                                                              
  default:                                                                              
    {                                                                                   
      std::stringstream lErrorMessage;                                                  
      zorba::Item item_qname1;                                                           
      lItem1.getNodeName(item_qname1);                                                    
      lErrorMessage << "Geometry must be a line: "                                      
           << item_qname1.getPrefix() <<":"<<item_qname1.getLocalName() << ".";           
      throwError(lErrorMessage.str(), XPTY0004);                                        
    }                                                                                   
    break;                                                                              
  }                                                                               
                                                                                  
                                                                                        
  Item lItem2;                                                                           
  if (!args[1]->next(lItem2)) 
  {
    std::stringstream lErrorMessage;
    lErrorMessage << "An empty-sequence is not allowed as second parameter";
    throwError(lErrorMessage.str(), XPTY0004);
  }

  uint32_t n;
  n = lItem2.getUnsignedIntValue();
                                               
  Item    nth_child;
  buildGeosGeometryFromItem(lItem1, geometric_type1, -1, NULL, GET_NTH_POINT, &n, &nth_child);

  if(nth_child.isNull())
  {
    std::stringstream lErrorMessage;                                              
    lErrorMessage << "Index n (" << n << ") is outside the range ";  
    throwError(lErrorMessage.str(), XPTY0004);                                    
  }
                                                                                  
  return ItemSequence_t(new SingletonItemSequence(nth_child));                  
}

///////////////////////////////////////////////////////////////////////
ItemSequence_t                                                                          
SFExteriorRingFunction::evaluate(const StatelessExternalFunction::Arguments_t& args,              
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
      zorba::Item item_qname;                                                           
      lItem.getNodeName(item_qname);                                                    
      lErrorMessage << "Unrecognized geometric type for element "                       
           << item_qname.getPrefix() <<":"<<item_qname.getLocalName() << ".";                
      throwError(lErrorMessage.str(), XPTY0004);                                        
    }                                                                                   
    break;                                                                              
  case GMLSF_POLYGON:                                                                
    break;                                                                              
  default:                                                                              
    {                                                                                   
      std::stringstream lErrorMessage;                                                  
      zorba::Item item_qname;                                                           
      lItem.getNodeName(item_qname);                                                    
      lErrorMessage << "Geometry must be a polygon: "                                      
           << item_qname.getPrefix() <<":"<<item_qname.getLocalName() << ".";           
      throwError(lErrorMessage.str(), XPTY0004);                                        
    }                                                                                   
    break;                                                                              
  }                                                                                     
      
  Item  result_item;
  buildGeosGeometryFromItem(lItem, geometric_type, -1, NULL, GET_EXTERIOR_RING, NULL, &result_item);
                                                                                        
  return ItemSequence_t(new SingletonItemSequence(result_item));                        
}

ItemSequence_t                                                                          
SFNumInteriorRingFunction::evaluate(const StatelessExternalFunction::Arguments_t& args,              
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
      zorba::Item item_qname;                                                           
      lItem.getNodeName(item_qname);                                                    
      lErrorMessage << "Unrecognized geometric type for element "                       
           << item_qname.getPrefix() <<":"<<item_qname.getLocalName() << ".";           
      throwError(lErrorMessage.str(), XPTY0004);                                        
    }                                                                                   
    break;                                                                              
  case GMLSF_POLYGON:                                                                
    break;                                                                              
  default:                                                                              
    {                                                                                   
      std::stringstream lErrorMessage;                                                  
      zorba::Item item_qname;                                                           
      lItem.getNodeName(item_qname);                                                    
      lErrorMessage << "Geometry must be a polygon: "                                      
           << item_qname.getPrefix() <<":"<<item_qname.getLocalName() << ".";           
      throwError(lErrorMessage.str(), XPTY0004);                                        
    }                                                                                   
    break;                                                                              
  }                                                                                     
                                                                                        
  uint32_t  num_children;
  buildGeosGeometryFromItem(lItem, geometric_type, -1, NULL, COUNT_CHILDREN, &num_children);

  return ItemSequence_t(new SingletonItemSequence(                                      
     theModule->getItemFactory()->createUnsignedInt(num_children)));                           
}

ItemSequence_t                                                                          
SFInteriorRingNFunction::evaluate(const StatelessExternalFunction::Arguments_t& args,              
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
      zorba::Item item_qname1;
      lItem1.getNodeName(item_qname1);
      lErrorMessage << "Unrecognized geometric type for element "                 
           << item_qname1.getPrefix() <<":"<<item_qname1.getLocalName() << " in first parameter.";    
      throwError(lErrorMessage.str(), XPTY0004);                                  
    }                                                                             
    break;                                                                        
  case GMLSF_POLYGON:                                                                
    break;                                                                              
  default:                                                                              
    {                                                                                   
      std::stringstream lErrorMessage;                                                  
      zorba::Item item_qname1;                                                           
      lItem1.getNodeName(item_qname1);                                                    
      lErrorMessage << "Geometry must be a polygon: "                                      
           << item_qname1.getPrefix() <<":"<<item_qname1.getLocalName() << ".";           
      throwError(lErrorMessage.str(), XPTY0004);                                        
    }                                                                                   
    break;                                                                              
  }                                                                               
                                                                                  
                                                                                  
                                                                                        
  Item lItem2;                                                                           
  if (!args[1]->next(lItem2)) 
  {
    std::stringstream lErrorMessage;
    lErrorMessage << "An empty-sequence is not allowed as second parameter";
    throwError(lErrorMessage.str(), XPTY0004);
  }

  uint32_t n;
  n = lItem2.getUnsignedIntValue();
                                      
  Item    nth_child;
  buildGeosGeometryFromItem(lItem1, geometric_type1, -1, NULL, GET_NTH_CHILD, &n, &nth_child);

  if(nth_child.isNull())
  {
    std::stringstream lErrorMessage;                                              
    lErrorMessage << "Index n (" << n << ") is outside the range ";  
    throwError(lErrorMessage.str(), XPTY0004);                                    
  }
                                                                                  
  return ItemSequence_t(new SingletonItemSequence(nth_child));                  
}

ItemSequence_t                                                                          
SFNumPatchesFunction::evaluate(const StatelessExternalFunction::Arguments_t& args,              
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
      zorba::Item item_qname;                                                           
      lItem.getNodeName(item_qname);                                                    
      lErrorMessage << "Unrecognized geometric type for element "                       
           << item_qname.getPrefix() <<":"<<item_qname.getLocalName() << ".";           
      throwError(lErrorMessage.str(), XPTY0004);                                        
    }                                                                                   
    break;                                                                              
  case GMLSF_SURFACE:                                                                
    break;                                                                              
  default:                                                                              
    {                                                                                   
      std::stringstream lErrorMessage;                                                  
      zorba::Item item_qname;                                                           
      lItem.getNodeName(item_qname);                                                    
      lErrorMessage << "Geometry must be a Surface: "                                      
           << item_qname.getPrefix() <<":"<<item_qname.getLocalName() << ".";           
      throwError(lErrorMessage.str(), XPTY0004);                                        
    }                                                                                   
    break;                                                                              
  }                                                                                     
                                                                                        
  uint32_t  num_children;
  buildGeosGeometryFromItem(lItem, geometric_type, -1, NULL, COUNT_CHILDREN, &num_children);

  return ItemSequence_t(new SingletonItemSequence(                                      
     theModule->getItemFactory()->createUnsignedInt(num_children)));                           
}

ItemSequence_t                                                                          
SFPatchNFunction::evaluate(const StatelessExternalFunction::Arguments_t& args,              
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
      zorba::Item item_qname1;
      lItem1.getNodeName(item_qname1);
      lErrorMessage << "Unrecognized geometric type for element "                 
           << item_qname1.getPrefix() <<":"<<item_qname1.getLocalName() << " in first parameter.";    
      throwError(lErrorMessage.str(), XPTY0004);                                  
    }                                                                             
    break;                                                                        
  case GMLSF_SURFACE:                                                                
    break;                                                                              
  default:                                                                              
    {                                                                                   
      std::stringstream lErrorMessage;                                                  
      zorba::Item item_qname1;                                                           
      lItem1.getNodeName(item_qname1);                                                    
      lErrorMessage << "Geometry must be a Surface: "                                      
           << item_qname1.getPrefix() <<":"<<item_qname1.getLocalName() << ".";           
      throwError(lErrorMessage.str(), XPTY0004);                                        
    }                                                                                   
    break;                                                                              
  }                                                                               
                                                                                  
                                                                                  
                                                                                        
  Item lItem2;                                                                           
  if (!args[1]->next(lItem2)) 
  {
    std::stringstream lErrorMessage;
    lErrorMessage << "An empty-sequence is not allowed as second parameter";
    throwError(lErrorMessage.str(), XPTY0004);
  }

  uint32_t n;
  n = lItem2.getUnsignedIntValue();
                                      
  Item    nth_child;
  buildGeosGeometryFromItem(lItem1, geometric_type1, -1, NULL, GET_NTH_CHILD, &n, &nth_child);

  if(nth_child.isNull())
  {
    std::stringstream lErrorMessage;                                              
    lErrorMessage << "Index n (" << n << ") is outside the range ";  
    throwError(lErrorMessage.str(), XPTY0004);                                    
  }
                                                                                  
  return ItemSequence_t(new SingletonItemSequence(nth_child));                  
}


ItemSequence_t                                                                          
SFBoundingPolygonsFunction::evaluate(const StatelessExternalFunction::Arguments_t& args,              
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
      zorba::Item item_qname1;
      lItem1.getNodeName(item_qname1);
      lErrorMessage << "Unrecognized geometric type for element "                 
           << item_qname1.getPrefix() <<":"<<item_qname1.getLocalName() << " in first parameter.";    
      throwError(lErrorMessage.str(), XPTY0004);                                  
    }                                                                             
    break;                                                                        
  case GMLSF_SURFACE:                                                                
    break;                                                                              
  default:                                                                              
    {                                                                                   
      std::stringstream lErrorMessage;                                                  
      zorba::Item item_qname1;                                                           
      lItem1.getNodeName(item_qname1);                                                    
      lErrorMessage << "Parameter 1 must be a Surface: "                                      
           << item_qname1.getPrefix() <<":"<<item_qname1.getLocalName() << ".";           
      throwError(lErrorMessage.str(), XPTY0004);                                        
    }                                                                                   
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
      zorba::Item item_qname2;
      lItem2.getNodeName(item_qname2);
      lErrorMessage << "Unrecognized geometric type for element "                 
           << item_qname2.getPrefix() <<":"<<item_qname2.getLocalName() << " in first parameter.";    
      throwError(lErrorMessage.str(), XPTY0004);                                  
    }                                                                             
    break;                                                                        
  case GMLSF_POLYGON:
  //case GMLSF_POLYGONPATCH:
    break;                                                                              
  default:                                                                              
    {                                                                                   
      std::stringstream lErrorMessage;                                                  
      zorba::Item item_qname2;                                                           
      lItem2.getNodeName(item_qname2);                                                    
      lErrorMessage << "Parameter 2 must be a Polygon or PolygonPatch: "                                      
           << item_qname2.getPrefix() <<":"<<item_qname2.getLocalName() << ".";           
      throwError(lErrorMessage.str(), XPTY0004);                                        
    }                                                                                   
    break;                                                                              
  }                                                                               
                                                                                  
  std::vector<Item>   result;
  zorba::Item   patches_item;
  if(!getChild(lItem1, "patches", "http://www.opengis.net/gml", patches_item))
  {//get upset
    std::stringstream lErrorMessage;
    lErrorMessage << "gml:Surface node must have a gml:patches child";
    throwError(lErrorMessage.str(), XPTY0004);
  }

  Iterator_t    patches_children;
  Item          polygon_patch_item;

  patches_children = patches_item.getChildren();
  patches_children->open();
  unsigned int patch_nr = 0;
                                     
  geos::geom::Geometry *geos_geometry1 = buildGeosGeometryFromItem(lItem1, geometric_type1, -1);
  geos::geom::Geometry *geos_geometry2 = buildGeosGeometryFromItem(lItem2, GMLSF_POLYGON, -1);

  const geos::geom::MultiPolygon *surface = dynamic_cast<const geos::geom::MultiPolygon*>(geos_geometry1);
  const geos::geom::Polygon *polygon = dynamic_cast<const geos::geom::Polygon*>(geos_geometry2);
  const geos::geom::LineString *exterior_ring = polygon->getExteriorRing();
  //const geos::geom::CoordinateSequence *coords = exterior_ring->getCoordinates();


  unsigned int nr_patches = (unsigned int)surface->getNumGeometries();
  unsigned int i;
  for(i=0;i<nr_patches;i++)
  {
    const geos::geom::Polygon *patch= dynamic_cast<const geos::geom::Polygon*>(surface->getGeometryN(i));
    const geos::geom::LineString *patch_exterior_ring = patch->getExteriorRing();
    //const geos::geom::CoordinateSequence *patch_coords = patch_exterior_ring->getCoordinates();
    //see if this patch touches the input polygon
    bool is_touching = false;
    /*
    for(unsigned int j=0;j<patch_coords->size();j++)
    {
      for(unsigned int k=0;k<coords->size();k++)
      {
        if(coords->getAt(k).equals(patch_coords->getAt(j)))
        {
          geos::geom::Coordinate next1;
          geos::geom::Coordinate next2;
          if(k == (coords->size()-1))
            next1 = coords->getAt(0);
          else
            next1 = coords->getAt(k+1);
          if(j == (patch_coords->size()-1))
            next2 = patch_coords->getAt(0);
          else
            next2 = patch_coords->getAt(j+1);
          if(next1.equals(next2))
          {
            is_touching = true;
            break;
          }
          if(j == 0)
            next2 = patch_coords->getAt(patch_coords->size()-1);
          else
            next2 = patch_coords->getAt(j-1);
          if(next1.equals(next2))
          {
            is_touching = true;
            break;
          }
        }
      }
      if(is_touching)
        break;
    }
    */
    if(patch_exterior_ring->overlaps(exterior_ring))
      is_touching = true;
    if(is_touching)
    {
      //add the coresponding patch item to the list
      while(patch_nr <= i)
      {
        patches_children->next(polygon_patch_item);       
        patch_nr++;
      }
      result.push_back(polygon_patch_item);
    }
  }
  
  delete geos_geometry1;
  delete geos_geometry2;
  return ItemSequence_t(new VectorItemSequence(result));                  
}


} /* namespace geomodule */ } /* namespace zorba */
