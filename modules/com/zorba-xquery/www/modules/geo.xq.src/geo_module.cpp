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

#include "geo_module.h"
#include "geo_functions.h"

namespace zorba { namespace geomodule {

  ItemFactory* GeoModule::theFactory = 0;

#ifdef WIN32
#  define DLL_EXPORT __declspec(dllexport)
#else
#  define DLL_EXPORT __attribute__ ((visibility("default")))
#endif

extern "C" DLL_EXPORT zorba::ExternalModule* createModule() {
  return new zorba::geomodule::GeoModule();
}

GeoModule::~GeoModule()
{
  for (FuncMap_t::const_iterator lIter = theFunctions.begin();
       lIter != theFunctions.end(); ++lIter) {
    delete lIter->second;
  }
  theFunctions.clear();
}
  
StatelessExternalFunction*
GeoModule::getExternalFunction(String aLocalname) const
{
  StatelessExternalFunction*& lFunc = theFunctions[aLocalname];
  if (!lFunc) {
    if (1 == 0) {

    }
    else if (aLocalname.equals("dimension")) {
      lFunc = new SFDimensionFunction(this);
    }
    else if (aLocalname.equals("coordinate-dimension")) {
      lFunc = new SFCoordinateDimensionFunction(this);
    }
    else if (aLocalname.equals("geometry-type")) {
      lFunc = new SFGeometryTypeFunction(this);
    }
    else if (aLocalname.equals("envelope")) {
      lFunc = new SFEnvelopeFunction(this);
    }
    else if (aLocalname.equals("as-text")) {
      lFunc = new SFAsTextFunction(this);
    }
    else if (aLocalname.equals("as-binary")) {
      lFunc = new SFAsBinaryFunction(this);
    }
    else if (aLocalname.equals("is-empty")) {
      lFunc = new SFIsEmptyFunction(this);
    }
    else if (aLocalname.equals("is-simple")) {
      lFunc = new SFIsSimpleFunction(this);
    }
    else if (aLocalname.equals("is-3D")) {
      lFunc = new SFIs3DFunction(this);
    }
    //else if (aLocalname.equals("isMeasured")) {
    //  lFunc = new SFIsMeasuredFunction(this);
    //}
    else if (aLocalname.equals("boundary")) {
      lFunc = new SFBoundaryFunction(this);
    }
    else if (aLocalname.equals("equals")) {
      lFunc = new SFEqualsFunction(this);
    }
    else if (aLocalname.equals("covers")) {
      lFunc = new SFCoversFunction(this);
    }
    else if (aLocalname.equals("disjoint")) {
      lFunc = new SFDisjointFunction(this);
    }
    else if (aLocalname.equals("intersects")) {
      lFunc = new SFIntersectsFunction(this);
    }
    else if (aLocalname.equals("touches")) {
      lFunc = new SFTouchesFunction(this);
    }
    else if (aLocalname.equals("crosses")) {
      lFunc = new SFCrossesFunction(this);
    }
    else if (aLocalname.equals("within")) {
      lFunc = new SFWithinFunction(this);
    }
    else if (aLocalname.equals("contains")) {
      lFunc = new SFContainsFunction(this);
    }
    else if (aLocalname.equals("overlaps")) {
      lFunc = new SFOverlapsFunction(this);
    }
    else if (aLocalname.equals("relate")) {
      lFunc = new SFRelateFunction(this);
    }
    else if (aLocalname.equals("distance")) {
      lFunc = new SFDistanceFunction(this);
    }
    else if (aLocalname.equals("buffer")) {
      lFunc = new SFBufferFunction(this);
    }
    else if (aLocalname.equals("convex-hull")) {
      lFunc = new SFConvexHullFunction(this);
    }
    else if (aLocalname.equals("intersection")) {
      lFunc = new SFIntersectionFunction(this);
    }
    else if (aLocalname.equals("union")) {
      lFunc = new SFUnionFunction(this);
    }
    else if (aLocalname.equals("difference")) {
      lFunc = new SFDifferenceFunction(this);
    }
    else if (aLocalname.equals("sym-difference")) {
      lFunc = new SFSymDifferenceFunction(this);
    }
    else if (aLocalname.equals("area")) {
      lFunc = new SFAreaFunction(this);
    }
    else if (aLocalname.equals("length")) {
      lFunc = new SFLengthFunction(this);
    }
    else if (aLocalname.equals("is-within-distance")) {
      lFunc = new SFIsWithinDistanceFunction(this);
    }
    else if (aLocalname.equals("centroid")) {
      lFunc = new SFCentroidFunction(this);
    }
    else if (aLocalname.equals("interior-point")) {
      lFunc = new SFInteriorPointFunction(this);
    }
  }
  return lFunc;
}

void
GeoModule::destroy()
{
  if (!dynamic_cast<GeoModule*>(this)) {
    return;
  }
  delete this;
}

} /* namespace GeoModule */ } /* namespace zorba */
