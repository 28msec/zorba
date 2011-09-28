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
#include "runtime/maths/maths.h"
#include "system/globalenv.h"



namespace zorba {

// <SqrtIterator>
const char* SqrtIterator::class_name_str = "SqrtIterator";
SqrtIterator::class_factory<SqrtIterator>
SqrtIterator::g_class_factory;

const serialization::ClassVersion 
SqrtIterator::class_versions[] ={{ 1, 0x000905, false}};

const int SqrtIterator::class_versions_count =
sizeof(SqrtIterator::class_versions)/sizeof(struct serialization::ClassVersion);

void SqrtIterator::accept(PlanIterVisitor& v) const {
  v.beginVisit(*this);

  theChild->accept(v);

  v.endVisit(*this);
}

SqrtIterator::~SqrtIterator() {}

// </SqrtIterator>


// <ExpIterator>
const char* ExpIterator::class_name_str = "ExpIterator";
ExpIterator::class_factory<ExpIterator>
ExpIterator::g_class_factory;

const serialization::ClassVersion 
ExpIterator::class_versions[] ={{ 1, 0x000905, false}};

const int ExpIterator::class_versions_count =
sizeof(ExpIterator::class_versions)/sizeof(struct serialization::ClassVersion);

void ExpIterator::accept(PlanIterVisitor& v) const {
  v.beginVisit(*this);

  theChild->accept(v);

  v.endVisit(*this);
}

ExpIterator::~ExpIterator() {}

// </ExpIterator>


// <Exp10Iterator>
const char* Exp10Iterator::class_name_str = "Exp10Iterator";
Exp10Iterator::class_factory<Exp10Iterator>
Exp10Iterator::g_class_factory;

const serialization::ClassVersion 
Exp10Iterator::class_versions[] ={{ 1, 0x000905, false}};

const int Exp10Iterator::class_versions_count =
sizeof(Exp10Iterator::class_versions)/sizeof(struct serialization::ClassVersion);

void Exp10Iterator::accept(PlanIterVisitor& v) const {
  v.beginVisit(*this);

  theChild->accept(v);

  v.endVisit(*this);
}

Exp10Iterator::~Exp10Iterator() {}

// </Exp10Iterator>


// <LogIterator>
const char* LogIterator::class_name_str = "LogIterator";
LogIterator::class_factory<LogIterator>
LogIterator::g_class_factory;

const serialization::ClassVersion 
LogIterator::class_versions[] ={{ 1, 0x000905, false}};

const int LogIterator::class_versions_count =
sizeof(LogIterator::class_versions)/sizeof(struct serialization::ClassVersion);

void LogIterator::accept(PlanIterVisitor& v) const {
  v.beginVisit(*this);

  theChild->accept(v);

  v.endVisit(*this);
}

LogIterator::~LogIterator() {}

// </LogIterator>


// <Log10Iterator>
const char* Log10Iterator::class_name_str = "Log10Iterator";
Log10Iterator::class_factory<Log10Iterator>
Log10Iterator::g_class_factory;

const serialization::ClassVersion 
Log10Iterator::class_versions[] ={{ 1, 0x000905, false}};

const int Log10Iterator::class_versions_count =
sizeof(Log10Iterator::class_versions)/sizeof(struct serialization::ClassVersion);

void Log10Iterator::accept(PlanIterVisitor& v) const {
  v.beginVisit(*this);

  theChild->accept(v);

  v.endVisit(*this);
}

Log10Iterator::~Log10Iterator() {}

// </Log10Iterator>


// <SinIterator>
const char* SinIterator::class_name_str = "SinIterator";
SinIterator::class_factory<SinIterator>
SinIterator::g_class_factory;

const serialization::ClassVersion 
SinIterator::class_versions[] ={{ 1, 0x000905, false}};

const int SinIterator::class_versions_count =
sizeof(SinIterator::class_versions)/sizeof(struct serialization::ClassVersion);

void SinIterator::accept(PlanIterVisitor& v) const {
  v.beginVisit(*this);

  theChild->accept(v);

  v.endVisit(*this);
}

SinIterator::~SinIterator() {}

// </SinIterator>


// <CosIterator>
const char* CosIterator::class_name_str = "CosIterator";
CosIterator::class_factory<CosIterator>
CosIterator::g_class_factory;

const serialization::ClassVersion 
CosIterator::class_versions[] ={{ 1, 0x000905, false}};

const int CosIterator::class_versions_count =
sizeof(CosIterator::class_versions)/sizeof(struct serialization::ClassVersion);

void CosIterator::accept(PlanIterVisitor& v) const {
  v.beginVisit(*this);

  theChild->accept(v);

  v.endVisit(*this);
}

CosIterator::~CosIterator() {}

// </CosIterator>


// <TanIterator>
const char* TanIterator::class_name_str = "TanIterator";
TanIterator::class_factory<TanIterator>
TanIterator::g_class_factory;

const serialization::ClassVersion 
TanIterator::class_versions[] ={{ 1, 0x000905, false}};

const int TanIterator::class_versions_count =
sizeof(TanIterator::class_versions)/sizeof(struct serialization::ClassVersion);

void TanIterator::accept(PlanIterVisitor& v) const {
  v.beginVisit(*this);

  theChild->accept(v);

  v.endVisit(*this);
}

TanIterator::~TanIterator() {}

// </TanIterator>


// <ArcSinIterator>
const char* ArcSinIterator::class_name_str = "ArcSinIterator";
ArcSinIterator::class_factory<ArcSinIterator>
ArcSinIterator::g_class_factory;

const serialization::ClassVersion 
ArcSinIterator::class_versions[] ={{ 1, 0x000905, false}};

const int ArcSinIterator::class_versions_count =
sizeof(ArcSinIterator::class_versions)/sizeof(struct serialization::ClassVersion);

void ArcSinIterator::accept(PlanIterVisitor& v) const {
  v.beginVisit(*this);

  theChild->accept(v);

  v.endVisit(*this);
}

ArcSinIterator::~ArcSinIterator() {}

// </ArcSinIterator>


// <ArcCosIterator>
const char* ArcCosIterator::class_name_str = "ArcCosIterator";
ArcCosIterator::class_factory<ArcCosIterator>
ArcCosIterator::g_class_factory;

const serialization::ClassVersion 
ArcCosIterator::class_versions[] ={{ 1, 0x000905, false}};

const int ArcCosIterator::class_versions_count =
sizeof(ArcCosIterator::class_versions)/sizeof(struct serialization::ClassVersion);

void ArcCosIterator::accept(PlanIterVisitor& v) const {
  v.beginVisit(*this);

  theChild->accept(v);

  v.endVisit(*this);
}

ArcCosIterator::~ArcCosIterator() {}

// </ArcCosIterator>


// <ArcTanIterator>
const char* ArcTanIterator::class_name_str = "ArcTanIterator";
ArcTanIterator::class_factory<ArcTanIterator>
ArcTanIterator::g_class_factory;

const serialization::ClassVersion 
ArcTanIterator::class_versions[] ={{ 1, 0x000905, false}};

const int ArcTanIterator::class_versions_count =
sizeof(ArcTanIterator::class_versions)/sizeof(struct serialization::ClassVersion);

void ArcTanIterator::accept(PlanIterVisitor& v) const {
  v.beginVisit(*this);

  theChild->accept(v);

  v.endVisit(*this);
}

ArcTanIterator::~ArcTanIterator() {}

// </ArcTanIterator>


// <Atan2Iterator>
const char* Atan2Iterator::class_name_str = "Atan2Iterator";
Atan2Iterator::class_factory<Atan2Iterator>
Atan2Iterator::g_class_factory;

const serialization::ClassVersion 
Atan2Iterator::class_versions[] ={{ 1, 0x000905, false}};

const int Atan2Iterator::class_versions_count =
sizeof(Atan2Iterator::class_versions)/sizeof(struct serialization::ClassVersion);

void Atan2Iterator::accept(PlanIterVisitor& v) const {
  v.beginVisit(*this);

  theChild0->accept(v);
theChild1->accept(v);

  v.endVisit(*this);
}

Atan2Iterator::~Atan2Iterator() {}

// </Atan2Iterator>


// <CoshIterator>
const char* CoshIterator::class_name_str = "CoshIterator";
CoshIterator::class_factory<CoshIterator>
CoshIterator::g_class_factory;

const serialization::ClassVersion 
CoshIterator::class_versions[] ={{ 1, 0x000905, false}};

const int CoshIterator::class_versions_count =
sizeof(CoshIterator::class_versions)/sizeof(struct serialization::ClassVersion);

void CoshIterator::accept(PlanIterVisitor& v) const {
  v.beginVisit(*this);

  theChild->accept(v);

  v.endVisit(*this);
}

CoshIterator::~CoshIterator() {}

// </CoshIterator>


// <AcoshIterator>
const char* AcoshIterator::class_name_str = "AcoshIterator";
AcoshIterator::class_factory<AcoshIterator>
AcoshIterator::g_class_factory;

const serialization::ClassVersion 
AcoshIterator::class_versions[] ={{ 1, 0x000905, false}};

const int AcoshIterator::class_versions_count =
sizeof(AcoshIterator::class_versions)/sizeof(struct serialization::ClassVersion);

void AcoshIterator::accept(PlanIterVisitor& v) const {
  v.beginVisit(*this);

  theChild->accept(v);

  v.endVisit(*this);
}

AcoshIterator::~AcoshIterator() {}

// </AcoshIterator>


// <FmodIterator>
const char* FmodIterator::class_name_str = "FmodIterator";
FmodIterator::class_factory<FmodIterator>
FmodIterator::g_class_factory;

const serialization::ClassVersion 
FmodIterator::class_versions[] ={{ 1, 0x000905, false}};

const int FmodIterator::class_versions_count =
sizeof(FmodIterator::class_versions)/sizeof(struct serialization::ClassVersion);

void FmodIterator::accept(PlanIterVisitor& v) const {
  v.beginVisit(*this);

  theChild0->accept(v);
theChild1->accept(v);

  v.endVisit(*this);
}

FmodIterator::~FmodIterator() {}

// </FmodIterator>


// <LdexpIterator>
const char* LdexpIterator::class_name_str = "LdexpIterator";
LdexpIterator::class_factory<LdexpIterator>
LdexpIterator::g_class_factory;

const serialization::ClassVersion 
LdexpIterator::class_versions[] ={{ 1, 0x000905, false}};

const int LdexpIterator::class_versions_count =
sizeof(LdexpIterator::class_versions)/sizeof(struct serialization::ClassVersion);

void LdexpIterator::accept(PlanIterVisitor& v) const {
  v.beginVisit(*this);

  theChild0->accept(v);
theChild1->accept(v);

  v.endVisit(*this);
}

LdexpIterator::~LdexpIterator() {}

// </LdexpIterator>


// <PowIterator>
const char* PowIterator::class_name_str = "PowIterator";
PowIterator::class_factory<PowIterator>
PowIterator::g_class_factory;

const serialization::ClassVersion 
PowIterator::class_versions[] ={{ 1, 0x000905, false}};

const int PowIterator::class_versions_count =
sizeof(PowIterator::class_versions)/sizeof(struct serialization::ClassVersion);

void PowIterator::accept(PlanIterVisitor& v) const {
  v.beginVisit(*this);

  theChild0->accept(v);
theChild1->accept(v);

  v.endVisit(*this);
}

PowIterator::~PowIterator() {}

// </PowIterator>


// <SinhIterator>
const char* SinhIterator::class_name_str = "SinhIterator";
SinhIterator::class_factory<SinhIterator>
SinhIterator::g_class_factory;

const serialization::ClassVersion 
SinhIterator::class_versions[] ={{ 1, 0x000905, false}};

const int SinhIterator::class_versions_count =
sizeof(SinhIterator::class_versions)/sizeof(struct serialization::ClassVersion);

void SinhIterator::accept(PlanIterVisitor& v) const {
  v.beginVisit(*this);

  theChild->accept(v);

  v.endVisit(*this);
}

SinhIterator::~SinhIterator() {}

// </SinhIterator>


// <AsinhIterator>
const char* AsinhIterator::class_name_str = "AsinhIterator";
AsinhIterator::class_factory<AsinhIterator>
AsinhIterator::g_class_factory;

const serialization::ClassVersion 
AsinhIterator::class_versions[] ={{ 1, 0x000905, false}};

const int AsinhIterator::class_versions_count =
sizeof(AsinhIterator::class_versions)/sizeof(struct serialization::ClassVersion);

void AsinhIterator::accept(PlanIterVisitor& v) const {
  v.beginVisit(*this);

  theChild->accept(v);

  v.endVisit(*this);
}

AsinhIterator::~AsinhIterator() {}

// </AsinhIterator>


// <TanhIterator>
const char* TanhIterator::class_name_str = "TanhIterator";
TanhIterator::class_factory<TanhIterator>
TanhIterator::g_class_factory;

const serialization::ClassVersion 
TanhIterator::class_versions[] ={{ 1, 0x000905, false}};

const int TanhIterator::class_versions_count =
sizeof(TanhIterator::class_versions)/sizeof(struct serialization::ClassVersion);

void TanhIterator::accept(PlanIterVisitor& v) const {
  v.beginVisit(*this);

  theChild->accept(v);

  v.endVisit(*this);
}

TanhIterator::~TanhIterator() {}

// </TanhIterator>


// <AtanhIterator>
const char* AtanhIterator::class_name_str = "AtanhIterator";
AtanhIterator::class_factory<AtanhIterator>
AtanhIterator::g_class_factory;

const serialization::ClassVersion 
AtanhIterator::class_versions[] ={{ 1, 0x000905, false}};

const int AtanhIterator::class_versions_count =
sizeof(AtanhIterator::class_versions)/sizeof(struct serialization::ClassVersion);

void AtanhIterator::accept(PlanIterVisitor& v) const {
  v.beginVisit(*this);

  theChild->accept(v);

  v.endVisit(*this);
}

AtanhIterator::~AtanhIterator() {}

// </AtanhIterator>


// <PiNumberIterator>
const char* PiNumberIterator::class_name_str = "PiNumberIterator";
PiNumberIterator::class_factory<PiNumberIterator>
PiNumberIterator::g_class_factory;

const serialization::ClassVersion 
PiNumberIterator::class_versions[] ={{ 1, 0x000905, false}};

const int PiNumberIterator::class_versions_count =
sizeof(PiNumberIterator::class_versions)/sizeof(struct serialization::ClassVersion);

void PiNumberIterator::accept(PlanIterVisitor& v) const {
  v.beginVisit(*this);

  

  v.endVisit(*this);
}

PiNumberIterator::~PiNumberIterator() {}

// </PiNumberIterator>


// <IsInfIterator>
const char* IsInfIterator::class_name_str = "IsInfIterator";
IsInfIterator::class_factory<IsInfIterator>
IsInfIterator::g_class_factory;

const serialization::ClassVersion 
IsInfIterator::class_versions[] ={{ 1, 0x000905, false}};

const int IsInfIterator::class_versions_count =
sizeof(IsInfIterator::class_versions)/sizeof(struct serialization::ClassVersion);

void IsInfIterator::accept(PlanIterVisitor& v) const {
  v.beginVisit(*this);

  theChild->accept(v);

  v.endVisit(*this);
}

IsInfIterator::~IsInfIterator() {}

// </IsInfIterator>


// <IsNaNIterator>
const char* IsNaNIterator::class_name_str = "IsNaNIterator";
IsNaNIterator::class_factory<IsNaNIterator>
IsNaNIterator::g_class_factory;

const serialization::ClassVersion 
IsNaNIterator::class_versions[] ={{ 1, 0x000905, false}};

const int IsNaNIterator::class_versions_count =
sizeof(IsNaNIterator::class_versions)/sizeof(struct serialization::ClassVersion);

void IsNaNIterator::accept(PlanIterVisitor& v) const {
  v.beginVisit(*this);

  theChild->accept(v);

  v.endVisit(*this);
}

IsNaNIterator::~IsNaNIterator() {}

// </IsNaNIterator>


// <ModfIterator>
const char* ModfIterator::class_name_str = "ModfIterator";
ModfIterator::class_factory<ModfIterator>
ModfIterator::g_class_factory;

const serialization::ClassVersion 
ModfIterator::class_versions[] ={{ 1, 0x000905, false}};

const int ModfIterator::class_versions_count =
sizeof(ModfIterator::class_versions)/sizeof(struct serialization::ClassVersion);

void ModfIterator::accept(PlanIterVisitor& v) const {
  v.beginVisit(*this);

  theChild->accept(v);

  v.endVisit(*this);
}

ModfIterator::~ModfIterator() {}

ModfIteratorState::ModfIteratorState() {}

ModfIteratorState::~ModfIteratorState() {}


void ModfIteratorState::init(PlanState& planState) {
  PlanIteratorState::init(planState);
  theDoubInteger = xs_double::zero();
}

void ModfIteratorState::reset(PlanState& planState) {
  PlanIteratorState::reset(planState);
  theDoubInteger = xs_double::zero();
}
// </ModfIterator>


// <FrexpIterator>
const char* FrexpIterator::class_name_str = "FrexpIterator";
FrexpIterator::class_factory<FrexpIterator>
FrexpIterator::g_class_factory;

const serialization::ClassVersion 
FrexpIterator::class_versions[] ={{ 1, 0x000905, false}};

const int FrexpIterator::class_versions_count =
sizeof(FrexpIterator::class_versions)/sizeof(struct serialization::ClassVersion);

void FrexpIterator::accept(PlanIterVisitor& v) const {
  v.beginVisit(*this);

  theChild->accept(v);

  v.endVisit(*this);
}

FrexpIterator::~FrexpIterator() {}

FrexpIteratorState::FrexpIteratorState() {}

FrexpIteratorState::~FrexpIteratorState() {}


void FrexpIteratorState::init(PlanState& planState) {
  PlanIteratorState::init(planState);
  theIntExponent = xs_integer::zero();
}

void FrexpIteratorState::reset(PlanState& planState) {
  PlanIteratorState::reset(planState);
  theIntExponent = xs_integer::zero();
}
// </FrexpIterator>



}


