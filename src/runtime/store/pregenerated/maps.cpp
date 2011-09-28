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
const char* MapCreateIterator::class_name_str = "MapCreateIterator";
MapCreateIterator::class_factory<MapCreateIterator>
MapCreateIterator::g_class_factory;

const serialization::ClassVersion 
MapCreateIterator::class_versions[] ={{ 1, 0x000905, false}};

const int MapCreateIterator::class_versions_count =
sizeof(MapCreateIterator::class_versions)/sizeof(struct serialization::ClassVersion);

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
const char* MapDestroyIterator::class_name_str = "MapDestroyIterator";
MapDestroyIterator::class_factory<MapDestroyIterator>
MapDestroyIterator::g_class_factory;

const serialization::ClassVersion 
MapDestroyIterator::class_versions[] ={{ 1, 0x000905, false}};

const int MapDestroyIterator::class_versions_count =
sizeof(MapDestroyIterator::class_versions)/sizeof(struct serialization::ClassVersion);

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
const char* MapGetIterator::class_name_str = "MapGetIterator";
MapGetIterator::class_factory<MapGetIterator>
MapGetIterator::g_class_factory;

const serialization::ClassVersion 
MapGetIterator::class_versions[] ={{ 1, 0x000905, false}};

const int MapGetIterator::class_versions_count =
sizeof(MapGetIterator::class_versions)/sizeof(struct serialization::ClassVersion);

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
const char* MapInsertIterator::class_name_str = "MapInsertIterator";
MapInsertIterator::class_factory<MapInsertIterator>
MapInsertIterator::g_class_factory;

const serialization::ClassVersion 
MapInsertIterator::class_versions[] ={{ 1, 0x000905, false}};

const int MapInsertIterator::class_versions_count =
sizeof(MapInsertIterator::class_versions)/sizeof(struct serialization::ClassVersion);

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
const char* MapRemoveIterator::class_name_str = "MapRemoveIterator";
MapRemoveIterator::class_factory<MapRemoveIterator>
MapRemoveIterator::g_class_factory;

const serialization::ClassVersion 
MapRemoveIterator::class_versions[] ={{ 1, 0x000905, false}};

const int MapRemoveIterator::class_versions_count =
sizeof(MapRemoveIterator::class_versions)/sizeof(struct serialization::ClassVersion);

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
const char* MapKeysIterator::class_name_str = "MapKeysIterator";
MapKeysIterator::class_factory<MapKeysIterator>
MapKeysIterator::g_class_factory;

const serialization::ClassVersion 
MapKeysIterator::class_versions[] ={{ 1, 0x000905, false}};

const int MapKeysIterator::class_versions_count =
sizeof(MapKeysIterator::class_versions)/sizeof(struct serialization::ClassVersion);

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
const char* MapSizeIterator::class_name_str = "MapSizeIterator";
MapSizeIterator::class_factory<MapSizeIterator>
MapSizeIterator::g_class_factory;

const serialization::ClassVersion 
MapSizeIterator::class_versions[] ={{ 1, 0x000905, false}};

const int MapSizeIterator::class_versions_count =
sizeof(MapSizeIterator::class_versions)/sizeof(struct serialization::ClassVersion);

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
const char* AvailableMapsIterator::class_name_str = "AvailableMapsIterator";
AvailableMapsIterator::class_factory<AvailableMapsIterator>
AvailableMapsIterator::g_class_factory;

const serialization::ClassVersion 
AvailableMapsIterator::class_versions[] ={{ 1, 0x000905, false}};

const int AvailableMapsIterator::class_versions_count =
sizeof(AvailableMapsIterator::class_versions)/sizeof(struct serialization::ClassVersion);

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


