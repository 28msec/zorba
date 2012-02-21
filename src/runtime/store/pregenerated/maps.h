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
#ifndef ZORBA_RUNTIME_STORE_MAPS_H
#define ZORBA_RUNTIME_STORE_MAPS_H


#include "common/shared_types.h"



#include "runtime/base/narybase.h"
#include "store/api/index.h"


namespace zorba {

/**
 * 
 *    
 * Author: Matthias Brantner
 */
class MapCreateIterator : public NaryBaseIterator<MapCreateIterator, PlanIteratorState>
{ 
public:
  SERIALIZABLE_CLASS(MapCreateIterator);

  SERIALIZABLE_CLASS_CONSTRUCTOR2T(MapCreateIterator,
    NaryBaseIterator<MapCreateIterator, PlanIteratorState>);

  void serialize( ::zorba::serialization::Archiver& ar)
  {
    serialize_baseclass(ar,
    (NaryBaseIterator<MapCreateIterator, PlanIteratorState>*)this);
  }

  MapCreateIterator(
    static_context* sctx,
    const QueryLoc& loc,
    std::vector<PlanIter_t>& children)
    : 
    NaryBaseIterator<MapCreateIterator, PlanIteratorState>(sctx, loc, children)
  {}

  virtual ~MapCreateIterator();

  void accept(PlanIterVisitor& v) const;

  bool nextImpl(store::Item_t& result, PlanState& aPlanState) const;
};


/**
 * 
 *    
 * Author: Matthias Brantner
 */
class MapDestroyIterator : public NaryBaseIterator<MapDestroyIterator, PlanIteratorState>
{ 
public:
  SERIALIZABLE_CLASS(MapDestroyIterator);

  SERIALIZABLE_CLASS_CONSTRUCTOR2T(MapDestroyIterator,
    NaryBaseIterator<MapDestroyIterator, PlanIteratorState>);

  void serialize( ::zorba::serialization::Archiver& ar)
  {
    serialize_baseclass(ar,
    (NaryBaseIterator<MapDestroyIterator, PlanIteratorState>*)this);
  }

  MapDestroyIterator(
    static_context* sctx,
    const QueryLoc& loc,
    std::vector<PlanIter_t>& children)
    : 
    NaryBaseIterator<MapDestroyIterator, PlanIteratorState>(sctx, loc, children)
  {}

  virtual ~MapDestroyIterator();

  void accept(PlanIterVisitor& v) const;

  bool nextImpl(store::Item_t& result, PlanState& aPlanState) const;
};


/**
 * 
 *    
 * Author: Matthias Brantner
 */
class MapGetIteratorState : public PlanIteratorState
{
public:
  store::IndexProbeIterator_t theIter; //
  store::IndexCondition_t theCond; //

  MapGetIteratorState();

  ~MapGetIteratorState();

  void init(PlanState&);
  void reset(PlanState&);
};

class MapGetIterator : public NaryBaseIterator<MapGetIterator, MapGetIteratorState>
{ 
public:
  SERIALIZABLE_CLASS(MapGetIterator);

  SERIALIZABLE_CLASS_CONSTRUCTOR2T(MapGetIterator,
    NaryBaseIterator<MapGetIterator, MapGetIteratorState>);

  void serialize( ::zorba::serialization::Archiver& ar)
  {
    serialize_baseclass(ar,
    (NaryBaseIterator<MapGetIterator, MapGetIteratorState>*)this);
  }

  MapGetIterator(
    static_context* sctx,
    const QueryLoc& loc,
    std::vector<PlanIter_t>& children)
    : 
    NaryBaseIterator<MapGetIterator, MapGetIteratorState>(sctx, loc, children)
  {}

  virtual ~MapGetIterator();

  void accept(PlanIterVisitor& v) const;

  bool nextImpl(store::Item_t& result, PlanState& aPlanState) const;
};


/**
 * 
 *    
 * Author: Matthias Brantner
 */
class MapInsertIterator : public NaryBaseIterator<MapInsertIterator, PlanIteratorState>
{ 
public:
  SERIALIZABLE_CLASS(MapInsertIterator);

  SERIALIZABLE_CLASS_CONSTRUCTOR2T(MapInsertIterator,
    NaryBaseIterator<MapInsertIterator, PlanIteratorState>);

  void serialize( ::zorba::serialization::Archiver& ar)
  {
    serialize_baseclass(ar,
    (NaryBaseIterator<MapInsertIterator, PlanIteratorState>*)this);
  }

  MapInsertIterator(
    static_context* sctx,
    const QueryLoc& loc,
    std::vector<PlanIter_t>& children)
    : 
    NaryBaseIterator<MapInsertIterator, PlanIteratorState>(sctx, loc, children)
  {}

  virtual ~MapInsertIterator();

  void accept(PlanIterVisitor& v) const;

  bool nextImpl(store::Item_t& result, PlanState& aPlanState) const;
};


/**
 * 
 *    
 * Author: Matthias Brantner
 */
class MapRemoveIterator : public NaryBaseIterator<MapRemoveIterator, PlanIteratorState>
{ 
public:
  SERIALIZABLE_CLASS(MapRemoveIterator);

  SERIALIZABLE_CLASS_CONSTRUCTOR2T(MapRemoveIterator,
    NaryBaseIterator<MapRemoveIterator, PlanIteratorState>);

  void serialize( ::zorba::serialization::Archiver& ar)
  {
    serialize_baseclass(ar,
    (NaryBaseIterator<MapRemoveIterator, PlanIteratorState>*)this);
  }

  MapRemoveIterator(
    static_context* sctx,
    const QueryLoc& loc,
    std::vector<PlanIter_t>& children)
    : 
    NaryBaseIterator<MapRemoveIterator, PlanIteratorState>(sctx, loc, children)
  {}

  virtual ~MapRemoveIterator();

  void accept(PlanIterVisitor& v) const;

  bool nextImpl(store::Item_t& result, PlanState& aPlanState) const;
};


/**
 * 
 *    
 * Author: Matthias Brantner
 */
class MapKeysIteratorState : public PlanIteratorState
{
public:
  store::Index::KeyIterator_t theIter; //

  MapKeysIteratorState();

  ~MapKeysIteratorState();

  void init(PlanState&);
  void reset(PlanState&);
};

class MapKeysIterator : public NaryBaseIterator<MapKeysIterator, MapKeysIteratorState>
{ 
protected:
  store::NsBindings theNSBindings; //
public:
  SERIALIZABLE_CLASS(MapKeysIterator);

  SERIALIZABLE_CLASS_CONSTRUCTOR2T(MapKeysIterator,
    NaryBaseIterator<MapKeysIterator, MapKeysIteratorState>);

  void serialize( ::zorba::serialization::Archiver& ar)
  {
    serialize_baseclass(ar,
    (NaryBaseIterator<MapKeysIterator, MapKeysIteratorState>*)this);

    ar & theNSBindings;
  }

  MapKeysIterator(
    static_context* sctx,
    const QueryLoc& loc,
    std::vector<PlanIter_t>& children)
    : 
    NaryBaseIterator<MapKeysIterator, MapKeysIteratorState>(sctx, loc, children),
    theNSBindings()
  {}

  virtual ~MapKeysIterator();

  void accept(PlanIterVisitor& v) const;

  bool nextImpl(store::Item_t& result, PlanState& aPlanState) const;
};


/**
 * 
 *    
 * Author: Matthias Brantner
 */
class MapSizeIterator : public NaryBaseIterator<MapSizeIterator, PlanIteratorState>
{ 
public:
  SERIALIZABLE_CLASS(MapSizeIterator);

  SERIALIZABLE_CLASS_CONSTRUCTOR2T(MapSizeIterator,
    NaryBaseIterator<MapSizeIterator, PlanIteratorState>);

  void serialize( ::zorba::serialization::Archiver& ar)
  {
    serialize_baseclass(ar,
    (NaryBaseIterator<MapSizeIterator, PlanIteratorState>*)this);
  }

  MapSizeIterator(
    static_context* sctx,
    const QueryLoc& loc,
    std::vector<PlanIter_t>& children)
    : 
    NaryBaseIterator<MapSizeIterator, PlanIteratorState>(sctx, loc, children)
  {}

  virtual ~MapSizeIterator();

  void accept(PlanIterVisitor& v) const;

  bool nextImpl(store::Item_t& result, PlanState& aPlanState) const;
};


/**
 * 
 *    
 * Author: Matthias Brantner
 */
class AvailableMapsIteratorState : public PlanIteratorState
{
public:
  store::Iterator_t nameItState; //the current iterator

  AvailableMapsIteratorState();

  ~AvailableMapsIteratorState();

  void init(PlanState&);
  void reset(PlanState&);
};

class AvailableMapsIterator : public NaryBaseIterator<AvailableMapsIterator, AvailableMapsIteratorState>
{ 
public:
  SERIALIZABLE_CLASS(AvailableMapsIterator);

  SERIALIZABLE_CLASS_CONSTRUCTOR2T(AvailableMapsIterator,
    NaryBaseIterator<AvailableMapsIterator, AvailableMapsIteratorState>);

  void serialize( ::zorba::serialization::Archiver& ar)
  {
    serialize_baseclass(ar,
    (NaryBaseIterator<AvailableMapsIterator, AvailableMapsIteratorState>*)this);
  }

  AvailableMapsIterator(
    static_context* sctx,
    const QueryLoc& loc,
    std::vector<PlanIter_t>& children)
    : 
    NaryBaseIterator<AvailableMapsIterator, AvailableMapsIteratorState>(sctx, loc, children)
  {}

  virtual ~AvailableMapsIterator();

  void accept(PlanIterVisitor& v) const;

  bool nextImpl(store::Item_t& result, PlanState& aPlanState) const;
};


}
#endif
/*
 * Local variables:
 * mode: c++
 * End:
 */ 
