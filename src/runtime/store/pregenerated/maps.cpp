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
 
// ******************************************
// *                                        *
// * THIS IS A GENERATED FILE. DO NOT EDIT! *
// * SEE .xml FILE WITH SAME NAME           *
// *                                        *
// ******************************************

#include "stdafx.h"
#include "zorbatypes/rchandle.h"
#include "zorbatypes/zstring.h"
#include "runtime/visitors/planiter_visitor.h"
#include "runtime/store/maps.h"
#include "system/globalenv.h"


#include "store/api/iterator.h"
#include "store/api/index.h"

namespace zorba {

// <MapCreateIterator>
MapCreateIterator::class_factory<MapCreateIterator>
MapCreateIterator::g_class_factory;


void MapCreateIterator::accept(PlanIterVisitor& v) const {
  v.beginVisit(*this);

  std::vector<PlanIter_t>::const_iterator lIter = theChildren.begin();
  std::vector<PlanIter_t>::const_iterator lEnd = theChildren.end();
  for ( ; lIter != lEnd; ++lIter ){
    (*lIter)->accept(v);
  }

  v.endVisit(*this);
}

MapCreateIterator::~MapCreateIterator() {}

// </MapCreateIterator>


// <MapDestroyIterator>
MapDestroyIterator::class_factory<MapDestroyIterator>
MapDestroyIterator::g_class_factory;


void MapDestroyIterator::accept(PlanIterVisitor& v) const {
  v.beginVisit(*this);

  std::vector<PlanIter_t>::const_iterator lIter = theChildren.begin();
  std::vector<PlanIter_t>::const_iterator lEnd = theChildren.end();
  for ( ; lIter != lEnd; ++lIter ){
    (*lIter)->accept(v);
  }

  v.endVisit(*this);
}

MapDestroyIterator::~MapDestroyIterator() {}

// </MapDestroyIterator>


// <MapGetIterator>
MapGetIterator::class_factory<MapGetIterator>
MapGetIterator::g_class_factory;


void MapGetIterator::accept(PlanIterVisitor& v) const {
  v.beginVisit(*this);

  std::vector<PlanIter_t>::const_iterator lIter = theChildren.begin();
  std::vector<PlanIter_t>::const_iterator lEnd = theChildren.end();
  for ( ; lIter != lEnd; ++lIter ){
    (*lIter)->accept(v);
  }

  v.endVisit(*this);
}

MapGetIterator::~MapGetIterator() {}

MapGetIteratorState::MapGetIteratorState() {}

MapGetIteratorState::~MapGetIteratorState() {}


void MapGetIteratorState::init(PlanState& planState) {
  PlanIteratorState::init(planState);
}

void MapGetIteratorState::reset(PlanState& planState) {
  PlanIteratorState::reset(planState);
}
// </MapGetIterator>


// <MapInsertIterator>
MapInsertIterator::class_factory<MapInsertIterator>
MapInsertIterator::g_class_factory;


void MapInsertIterator::accept(PlanIterVisitor& v) const {
  v.beginVisit(*this);

  std::vector<PlanIter_t>::const_iterator lIter = theChildren.begin();
  std::vector<PlanIter_t>::const_iterator lEnd = theChildren.end();
  for ( ; lIter != lEnd; ++lIter ){
    (*lIter)->accept(v);
  }

  v.endVisit(*this);
}

MapInsertIterator::~MapInsertIterator() {}

// </MapInsertIterator>


// <MapRemoveIterator>
MapRemoveIterator::class_factory<MapRemoveIterator>
MapRemoveIterator::g_class_factory;


void MapRemoveIterator::accept(PlanIterVisitor& v) const {
  v.beginVisit(*this);

  std::vector<PlanIter_t>::const_iterator lIter = theChildren.begin();
  std::vector<PlanIter_t>::const_iterator lEnd = theChildren.end();
  for ( ; lIter != lEnd; ++lIter ){
    (*lIter)->accept(v);
  }

  v.endVisit(*this);
}

MapRemoveIterator::~MapRemoveIterator() {}

// </MapRemoveIterator>


// <MapKeysIterator>
MapKeysIterator::class_factory<MapKeysIterator>
MapKeysIterator::g_class_factory;


void MapKeysIterator::accept(PlanIterVisitor& v) const {
  v.beginVisit(*this);

  std::vector<PlanIter_t>::const_iterator lIter = theChildren.begin();
  std::vector<PlanIter_t>::const_iterator lEnd = theChildren.end();
  for ( ; lIter != lEnd; ++lIter ){
    (*lIter)->accept(v);
  }

  v.endVisit(*this);
}

MapKeysIterator::~MapKeysIterator() {}

MapKeysIteratorState::MapKeysIteratorState() {}

MapKeysIteratorState::~MapKeysIteratorState() {}


void MapKeysIteratorState::init(PlanState& planState) {
  PlanIteratorState::init(planState);
}

void MapKeysIteratorState::reset(PlanState& planState) {
  PlanIteratorState::reset(planState);
}
// </MapKeysIterator>


// <MapSizeIterator>
MapSizeIterator::class_factory<MapSizeIterator>
MapSizeIterator::g_class_factory;


void MapSizeIterator::accept(PlanIterVisitor& v) const {
  v.beginVisit(*this);

  std::vector<PlanIter_t>::const_iterator lIter = theChildren.begin();
  std::vector<PlanIter_t>::const_iterator lEnd = theChildren.end();
  for ( ; lIter != lEnd; ++lIter ){
    (*lIter)->accept(v);
  }

  v.endVisit(*this);
}

MapSizeIterator::~MapSizeIterator() {}

// </MapSizeIterator>


// <AvailableMapsIterator>
AvailableMapsIterator::class_factory<AvailableMapsIterator>
AvailableMapsIterator::g_class_factory;


void AvailableMapsIterator::accept(PlanIterVisitor& v) const {
  v.beginVisit(*this);

  std::vector<PlanIter_t>::const_iterator lIter = theChildren.begin();
  std::vector<PlanIter_t>::const_iterator lEnd = theChildren.end();
  for ( ; lIter != lEnd; ++lIter ){
    (*lIter)->accept(v);
  }

  v.endVisit(*this);
}

AvailableMapsIterator::~AvailableMapsIterator() {}

AvailableMapsIteratorState::AvailableMapsIteratorState() {}

// </AvailableMapsIterator>



}


