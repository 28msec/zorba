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
SqrtIterator::class_factory<SqrtIterator>
SqrtIterator::g_class_factory;


void SqrtIterator::accept(PlanIterVisitor& v) const {
  v.beginVisit(*this);

  theChild->accept(v);

  v.endVisit(*this);
}

SqrtIterator::~SqrtIterator() {}

// </SqrtIterator>


// <ExpIterator>
ExpIterator::class_factory<ExpIterator>
ExpIterator::g_class_factory;


void ExpIterator::accept(PlanIterVisitor& v) const {
  v.beginVisit(*this);

  theChild->accept(v);

  v.endVisit(*this);
}

ExpIterator::~ExpIterator() {}

// </ExpIterator>


// <Exp10Iterator>
Exp10Iterator::class_factory<Exp10Iterator>
Exp10Iterator::g_class_factory;


void Exp10Iterator::accept(PlanIterVisitor& v) const {
  v.beginVisit(*this);

  theChild->accept(v);

  v.endVisit(*this);
}

Exp10Iterator::~Exp10Iterator() {}

// </Exp10Iterator>


// <LogIterator>
LogIterator::class_factory<LogIterator>
LogIterator::g_class_factory;


void LogIterator::accept(PlanIterVisitor& v) const {
  v.beginVisit(*this);

  theChild->accept(v);

  v.endVisit(*this);
}

LogIterator::~LogIterator() {}

// </LogIterator>


// <Log10Iterator>
Log10Iterator::class_factory<Log10Iterator>
Log10Iterator::g_class_factory;


void Log10Iterator::accept(PlanIterVisitor& v) const {
  v.beginVisit(*this);

  theChild->accept(v);

  v.endVisit(*this);
}

Log10Iterator::~Log10Iterator() {}

// </Log10Iterator>


// <SinIterator>
SinIterator::class_factory<SinIterator>
SinIterator::g_class_factory;


void SinIterator::accept(PlanIterVisitor& v) const {
  v.beginVisit(*this);

  theChild->accept(v);

  v.endVisit(*this);
}

SinIterator::~SinIterator() {}

// </SinIterator>


// <CosIterator>
CosIterator::class_factory<CosIterator>
CosIterator::g_class_factory;


void CosIterator::accept(PlanIterVisitor& v) const {
  v.beginVisit(*this);

  theChild->accept(v);

  v.endVisit(*this);
}

CosIterator::~CosIterator() {}

// </CosIterator>


// <TanIterator>
TanIterator::class_factory<TanIterator>
TanIterator::g_class_factory;


void TanIterator::accept(PlanIterVisitor& v) const {
  v.beginVisit(*this);

  theChild->accept(v);

  v.endVisit(*this);
}

TanIterator::~TanIterator() {}

// </TanIterator>


// <ArcSinIterator>
ArcSinIterator::class_factory<ArcSinIterator>
ArcSinIterator::g_class_factory;


void ArcSinIterator::accept(PlanIterVisitor& v) const {
  v.beginVisit(*this);

  theChild->accept(v);

  v.endVisit(*this);
}

ArcSinIterator::~ArcSinIterator() {}

// </ArcSinIterator>


// <ArcCosIterator>
ArcCosIterator::class_factory<ArcCosIterator>
ArcCosIterator::g_class_factory;


void ArcCosIterator::accept(PlanIterVisitor& v) const {
  v.beginVisit(*this);

  theChild->accept(v);

  v.endVisit(*this);
}

ArcCosIterator::~ArcCosIterator() {}

// </ArcCosIterator>


// <ArcTanIterator>
ArcTanIterator::class_factory<ArcTanIterator>
ArcTanIterator::g_class_factory;


void ArcTanIterator::accept(PlanIterVisitor& v) const {
  v.beginVisit(*this);

  theChild->accept(v);

  v.endVisit(*this);
}

ArcTanIterator::~ArcTanIterator() {}

// </ArcTanIterator>


// <Atan2Iterator>
Atan2Iterator::class_factory<Atan2Iterator>
Atan2Iterator::g_class_factory;


void Atan2Iterator::accept(PlanIterVisitor& v) const {
  v.beginVisit(*this);

  theChild0->accept(v);
theChild1->accept(v);

  v.endVisit(*this);
}

Atan2Iterator::~Atan2Iterator() {}

// </Atan2Iterator>


// <CoshIterator>
CoshIterator::class_factory<CoshIterator>
CoshIterator::g_class_factory;


void CoshIterator::accept(PlanIterVisitor& v) const {
  v.beginVisit(*this);

  theChild->accept(v);

  v.endVisit(*this);
}

CoshIterator::~CoshIterator() {}

// </CoshIterator>


// <AcoshIterator>
AcoshIterator::class_factory<AcoshIterator>
AcoshIterator::g_class_factory;


void AcoshIterator::accept(PlanIterVisitor& v) const {
  v.beginVisit(*this);

  theChild->accept(v);

  v.endVisit(*this);
}

AcoshIterator::~AcoshIterator() {}

// </AcoshIterator>


// <FmodIterator>
FmodIterator::class_factory<FmodIterator>
FmodIterator::g_class_factory;


void FmodIterator::accept(PlanIterVisitor& v) const {
  v.beginVisit(*this);

  theChild0->accept(v);
theChild1->accept(v);

  v.endVisit(*this);
}

FmodIterator::~FmodIterator() {}

// </FmodIterator>


// <LdexpIterator>
LdexpIterator::class_factory<LdexpIterator>
LdexpIterator::g_class_factory;


void LdexpIterator::accept(PlanIterVisitor& v) const {
  v.beginVisit(*this);

  theChild0->accept(v);
theChild1->accept(v);

  v.endVisit(*this);
}

LdexpIterator::~LdexpIterator() {}

// </LdexpIterator>


// <PowIterator>
PowIterator::class_factory<PowIterator>
PowIterator::g_class_factory;


void PowIterator::accept(PlanIterVisitor& v) const {
  v.beginVisit(*this);

  theChild0->accept(v);
theChild1->accept(v);

  v.endVisit(*this);
}

PowIterator::~PowIterator() {}

// </PowIterator>


// <SinhIterator>
SinhIterator::class_factory<SinhIterator>
SinhIterator::g_class_factory;


void SinhIterator::accept(PlanIterVisitor& v) const {
  v.beginVisit(*this);

  theChild->accept(v);

  v.endVisit(*this);
}

SinhIterator::~SinhIterator() {}

// </SinhIterator>


// <AsinhIterator>
AsinhIterator::class_factory<AsinhIterator>
AsinhIterator::g_class_factory;


void AsinhIterator::accept(PlanIterVisitor& v) const {
  v.beginVisit(*this);

  theChild->accept(v);

  v.endVisit(*this);
}

AsinhIterator::~AsinhIterator() {}

// </AsinhIterator>


// <TanhIterator>
TanhIterator::class_factory<TanhIterator>
TanhIterator::g_class_factory;


void TanhIterator::accept(PlanIterVisitor& v) const {
  v.beginVisit(*this);

  theChild->accept(v);

  v.endVisit(*this);
}

TanhIterator::~TanhIterator() {}

// </TanhIterator>


// <AtanhIterator>
AtanhIterator::class_factory<AtanhIterator>
AtanhIterator::g_class_factory;


void AtanhIterator::accept(PlanIterVisitor& v) const {
  v.beginVisit(*this);

  theChild->accept(v);

  v.endVisit(*this);
}

AtanhIterator::~AtanhIterator() {}

// </AtanhIterator>


// <PiNumberIterator>
PiNumberIterator::class_factory<PiNumberIterator>
PiNumberIterator::g_class_factory;


void PiNumberIterator::accept(PlanIterVisitor& v) const {
  v.beginVisit(*this);

  

  v.endVisit(*this);
}

PiNumberIterator::~PiNumberIterator() {}

// </PiNumberIterator>


// <IsInfIterator>
IsInfIterator::class_factory<IsInfIterator>
IsInfIterator::g_class_factory;


void IsInfIterator::accept(PlanIterVisitor& v) const {
  v.beginVisit(*this);

  theChild->accept(v);

  v.endVisit(*this);
}

IsInfIterator::~IsInfIterator() {}

// </IsInfIterator>


// <IsNaNIterator>
IsNaNIterator::class_factory<IsNaNIterator>
IsNaNIterator::g_class_factory;


void IsNaNIterator::accept(PlanIterVisitor& v) const {
  v.beginVisit(*this);

  theChild->accept(v);

  v.endVisit(*this);
}

IsNaNIterator::~IsNaNIterator() {}

// </IsNaNIterator>


// <ModfIterator>
ModfIterator::class_factory<ModfIterator>
ModfIterator::g_class_factory;


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
FrexpIterator::class_factory<FrexpIterator>
FrexpIterator::g_class_factory;


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


