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
#include "stdafx.h"

#include "zorbaserialization/class_serializer.h"
#include "zorbaserialization/archiver.h"
#include "zorbaserialization/mem_archiver.h"

#include "diagnostics/xquery_diagnostics.h"
#include "diagnostics/assert.h"

#include "zorbautils/hashmap.h"

namespace zorba
{

namespace serialization
{


/*******************************************************************************

********************************************************************************/
const unsigned long ClassSerializer::g_zorba_classes_version = 25;


/*******************************************************************************

********************************************************************************/
ClassSerializer::ClassSerializer() 
{
  theClassFactories.resize(TYPE_LAST);

  t0 = clock();

  harcoded_objects_archive = new MemArchiver(true, true);
}


/*******************************************************************************

********************************************************************************/
ClassSerializer::~ClassSerializer()
{
  delete harcoded_objects_archive;
}


/*******************************************************************************

********************************************************************************/
ClassSerializer* ClassSerializer::getInstance()
{
  static ClassSerializer theInstance;
  return &theInstance;
}


/*******************************************************************************

********************************************************************************/
void ClassSerializer::register_class_factory(
    TypeCode code,
    ClassDeserializer* class_factory)
{
  assert(code < TYPE_LAST);
  theClassFactories[code] = class_factory;

  t1 = clock();
}


/*******************************************************************************

********************************************************************************/
ClassDeserializer* ClassSerializer::get_class_factory(TypeCode code)
{
  assert(code < TYPE_LAST);
  return theClassFactories[code];
}


/*******************************************************************************

********************************************************************************/
Archiver* ClassSerializer::getArchiverForHardcodedObjects()
{
  return harcoded_objects_archive;
}


/*******************************************************************************
  called at shutdown
********************************************************************************/
void ClassSerializer::destroyArchiverForHardcodedObjects()
{
  delete harcoded_objects_archive;
  harcoded_objects_archive = NULL;
  harcoded_objects_archive = new MemArchiver(true, true);
}


} // namespace serialization
} // namespace zorba
/* vim:set et sw=2 ts=2: */
