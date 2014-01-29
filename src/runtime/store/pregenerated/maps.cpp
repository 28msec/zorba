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


zstring MapCreateIterator::getNameAsString() const {
  return "zorba-store-unordered-maps:create";
}
// </MapCreateIterator>


// <MapDropIterator>
SERIALIZABLE_CLASS_VERSIONS(MapDropIterator)

void MapDropIterator::serialize(::zorba::serialization::Archiver& ar)
{
  serialize_baseclass(ar,
  (NaryBaseIterator<MapDropIterator, PlanIteratorState>*)this);
}


void MapDropIterator::accept(PlanIterVisitor& v) const
{
  v.beginVisit(*this);

  std::vector<PlanIter_t>::const_iterator lIter = theChildren.begin();
  std::vector<PlanIter_t>::const_iterator lEnd = theChildren.end();
  for ( ; lIter != lEnd; ++lIter ){
    (*lIter)->accept(v);
  }

  v.endVisit(*this);
}

MapDropIterator::~MapDropIterator() {}


zstring MapDropIterator::getNameAsString() const {
  return "zorba-store-unordered-maps:drop";
}
// </MapDropIterator>


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

zstring MapGetIterator::getNameAsString() const {
  return "zorba-store-unordered-maps:get";
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


zstring MapInsertIterator::getNameAsString() const {
  return "zorba-store-unordered-maps:insert";
}
// </MapInsertIterator>


// <MapDeleteIterator>
SERIALIZABLE_CLASS_VERSIONS(MapDeleteIterator)

void MapDeleteIterator::serialize(::zorba::serialization::Archiver& ar)
{
  serialize_baseclass(ar,
  (NaryBaseIterator<MapDeleteIterator, PlanIteratorState>*)this);
}


void MapDeleteIterator::accept(PlanIterVisitor& v) const
{
  v.beginVisit(*this);

  std::vector<PlanIter_t>::const_iterator lIter = theChildren.begin();
  std::vector<PlanIter_t>::const_iterator lEnd = theChildren.end();
  for ( ; lIter != lEnd; ++lIter ){
    (*lIter)->accept(v);
  }

  v.endVisit(*this);
}

MapDeleteIterator::~MapDeleteIterator() {}


zstring MapDeleteIterator::getNameAsString() const {
  return "zorba-store-unordered-maps:delete";
}
// </MapDeleteIterator>


// <MapKeysIterator>
SERIALIZABLE_CLASS_VERSIONS(MapKeysIterator)

void MapKeysIterator::serialize(::zorba::serialization::Archiver& ar)
{
  serialize_baseclass(ar,
  (NaryBaseIterator<MapKeysIterator, MapKeysIteratorState>*)this);
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

zstring MapKeysIterator::getNameAsString() const {
  return "zorba-store-unordered-maps:keys";
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


zstring MapSizeIterator::getNameAsString() const {
  return "zorba-store-unordered-maps:size";
}
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


zstring AvailableMapsIterator::getNameAsString() const {
  return "zorba-store-unordered-maps:available-maps";
}
// </AvailableMapsIterator>


// <MapOptionsIterator>
SERIALIZABLE_CLASS_VERSIONS(MapOptionsIterator)

void MapOptionsIterator::serialize(::zorba::serialization::Archiver& ar)
{
  serialize_baseclass(ar,
  (NaryBaseIterator<MapOptionsIterator, PlanIteratorState>*)this);
}


void MapOptionsIterator::accept(PlanIterVisitor& v) const
{
  v.beginVisit(*this);

  std::vector<PlanIter_t>::const_iterator lIter = theChildren.begin();
  std::vector<PlanIter_t>::const_iterator lEnd = theChildren.end();
  for ( ; lIter != lEnd; ++lIter ){
    (*lIter)->accept(v);
  }

  v.endVisit(*this);
}

MapOptionsIterator::~MapOptionsIterator() {}


zstring MapOptionsIterator::getNameAsString() const {
  return "zorba-store-unordered-maps:options";
}
// </MapOptionsIterator>



}


