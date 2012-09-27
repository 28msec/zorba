/*
 * Copyright 2006-2012 The FLWOR Foundation.
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
SERIALIZABLE_CLASS_VERSIONS(MapCreateIterator)

void MapCreateIterator::serialize(::zorba::serialization::Archiver& ar)
{
  serialize_baseclass(ar,
  (NaryBaseIterator<MapCreateIterator, PlanIteratorState>*)this);
}


void MapCreateIterator::accept(PlanIterVisitor& v) const
{
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


// <MapCreateTransientIterator>
SERIALIZABLE_CLASS_VERSIONS(MapCreateTransientIterator)

void MapCreateTransientIterator::serialize(::zorba::serialization::Archiver& ar)
{
  serialize_baseclass(ar,
  (NaryBaseIterator<MapCreateTransientIterator, PlanIteratorState>*)this);
}


void MapCreateTransientIterator::accept(PlanIterVisitor& v) const
{
  v.beginVisit(*this);

  std::vector<PlanIter_t>::const_iterator lIter = theChildren.begin();
  std::vector<PlanIter_t>::const_iterator lEnd = theChildren.end();
  for ( ; lIter != lEnd; ++lIter ){
    (*lIter)->accept(v);
  }

  v.endVisit(*this);
}

MapCreateTransientIterator::~MapCreateTransientIterator() {}

// </MapCreateTransientIterator>


// <MapDestroyIterator>
SERIALIZABLE_CLASS_VERSIONS(MapDestroyIterator)

void MapDestroyIterator::serialize(::zorba::serialization::Archiver& ar)
{
  serialize_baseclass(ar,
  (NaryBaseIterator<MapDestroyIterator, PlanIteratorState>*)this);
}


void MapDestroyIterator::accept(PlanIterVisitor& v) const
{
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
SERIALIZABLE_CLASS_VERSIONS(MapGetIterator)

void MapGetIterator::serialize(::zorba::serialization::Archiver& ar)
{
  serialize_baseclass(ar,
  (NaryBaseIterator<MapGetIterator, MapGetIteratorState>*)this);
}


void MapGetIterator::accept(PlanIterVisitor& v) const
{
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
SERIALIZABLE_CLASS_VERSIONS(MapInsertIterator)

void MapInsertIterator::serialize(::zorba::serialization::Archiver& ar)
{
  serialize_baseclass(ar,
  (NaryBaseIterator<MapInsertIterator, PlanIteratorState>*)this);
}


void MapInsertIterator::accept(PlanIterVisitor& v) const
{
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
SERIALIZABLE_CLASS_VERSIONS(MapRemoveIterator)

void MapRemoveIterator::serialize(::zorba::serialization::Archiver& ar)
{
  serialize_baseclass(ar,
  (NaryBaseIterator<MapRemoveIterator, PlanIteratorState>*)this);
}


void MapRemoveIterator::accept(PlanIterVisitor& v) const
{
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
SERIALIZABLE_CLASS_VERSIONS(MapKeysIterator)

void MapKeysIterator::serialize(::zorba::serialization::Archiver& ar)
{
  serialize_baseclass(ar,
  (NaryBaseIterator<MapKeysIterator, MapKeysIteratorState>*)this);

    ar & theNSBindings;
}


void MapKeysIterator::accept(PlanIterVisitor& v) const
{
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
SERIALIZABLE_CLASS_VERSIONS(MapSizeIterator)

void MapSizeIterator::serialize(::zorba::serialization::Archiver& ar)
{
  serialize_baseclass(ar,
  (NaryBaseIterator<MapSizeIterator, PlanIteratorState>*)this);
}


void MapSizeIterator::accept(PlanIterVisitor& v) const
{
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
SERIALIZABLE_CLASS_VERSIONS(AvailableMapsIterator)

void AvailableMapsIterator::serialize(::zorba::serialization::Archiver& ar)
{
  serialize_baseclass(ar,
  (NaryBaseIterator<AvailableMapsIterator, AvailableMapsIteratorState>*)this);
}


void AvailableMapsIterator::accept(PlanIterVisitor& v) const
{
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


// <MapIsTransientIterator>
SERIALIZABLE_CLASS_VERSIONS(MapIsTransientIterator)

void MapIsTransientIterator::serialize(::zorba::serialization::Archiver& ar)
{
  serialize_baseclass(ar,
  (NaryBaseIterator<MapIsTransientIterator, PlanIteratorState>*)this);
}


void MapIsTransientIterator::accept(PlanIterVisitor& v) const
{
  v.beginVisit(*this);

  std::vector<PlanIter_t>::const_iterator lIter = theChildren.begin();
  std::vector<PlanIter_t>::const_iterator lEnd = theChildren.end();
  for ( ; lIter != lEnd; ++lIter ){
    (*lIter)->accept(v);
  }

  v.endVisit(*this);
}

MapIsTransientIterator::~MapIsTransientIterator() {}

// </MapIsTransientIterator>



}


