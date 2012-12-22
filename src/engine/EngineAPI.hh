/***
Copyright 2012 Devsim LLC

Licensed under the Apache License, Version 2.0 (the "License");
you may not use this file except in compliance with the License.
You may obtain a copy of the License at

    http://www.apache.org/licenses/LICENSE-2.0

Unless required by applicable law or agreed to in writing, software
distributed under the License is distributed on an "AS IS" BASIS,
WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
See the License for the specific language governing permissions and
limitations under the License.
***/

#ifndef ENGINEAPI_HH
#define ENGINEAPI_HH
#include "dsmemory.hh"
#include "import.hh"
#include <string>
#include <vector>
namespace Eqo {
class EquationObject;
typedef std::tr1::shared_ptr<EquationObject> EqObjPtr;
}

namespace EngineAPI {
typedef Eqo::EqObjPtr (*EqUnaryFuncPtr) (Eqo::EqObjPtr);
typedef Eqo::EqObjPtr (*EqBinaryFuncPtr) (Eqo::EqObjPtr, Eqo::EqObjPtr);

Eqo::EqObjPtr DLL_PUBLIC createUnaryLogical(const std::string &/*unaryOp*/, Eqo::EqObjPtr /*arg*/);
Eqo::EqObjPtr DLL_PUBLIC createBinaryLogical(const std::string &/*unaryOp*/, Eqo::EqObjPtr /*arg*/, Eqo::EqObjPtr /*arg*/);
Eqo::EqObjPtr DLL_PUBLIC createIfObj(Eqo::EqObjPtr /*test*/, Eqo::EqObjPtr /*result*/);
Eqo::EqObjPtr DLL_PUBLIC createIfElseObj(Eqo::EqObjPtr /*test*/, Eqo::EqObjPtr /*left*/, Eqo::EqObjPtr /*right*/);
/// Non member functions for intuitive math operations
Eqo::EqObjPtr DLL_PUBLIC operator* (Eqo::EqObjPtr x, Eqo::EqObjPtr y);
Eqo::EqObjPtr DLL_PUBLIC pow (Eqo::EqObjPtr x, Eqo::EqObjPtr y);
Eqo::EqObjPtr DLL_PUBLIC operator/ (Eqo::EqObjPtr x, Eqo::EqObjPtr y);
Eqo::EqObjPtr DLL_PUBLIC operator+ (Eqo::EqObjPtr x, Eqo::EqObjPtr y);
Eqo::EqObjPtr DLL_PUBLIC operator- (Eqo::EqObjPtr x, Eqo::EqObjPtr y);

Eqo::EqObjPtr DLL_PUBLIC exp (Eqo::EqObjPtr x);

Eqo::EqObjPtr DLL_PUBLIC pow (Eqo::EqObjPtr x, Eqo::EqObjPtr y);

Eqo::EqObjPtr DLL_PUBLIC log (Eqo::EqObjPtr x);

Eqo::EqObjPtr DLL_PUBLIC diff(Eqo::EqObjPtr x, Eqo::EqObjPtr y);

Eqo::EqObjPtr DLL_PUBLIC con(double x);

Eqo::EqObjPtr DLL_PUBLIC var(const char *x);

Eqo::EqObjPtr DLL_PUBLIC var(const std::string &x);

Eqo::EqObjPtr DLL_PUBLIC sqrt(Eqo::EqObjPtr x);

Eqo::EqObjPtr DLL_PUBLIC reciprocal_sqrt(Eqo::EqObjPtr x);

/// how we print things
std::ostream & operator<< (std::ostream &os, Eqo::EqObjPtr foo);

/// keeps simplifying expression until string value doesn't change
Eqo::EqObjPtr DLL_PUBLIC Simplify(Eqo::EqObjPtr x);

Eqo::EqObjPtr DLL_PUBLIC getConstantFactor(Eqo::EqObjPtr x);

Eqo::EqObjPtr DLL_PUBLIC Expand(Eqo::EqObjPtr x);

Eqo::EqObjPtr DLL_PUBLIC getUnscaledValue(Eqo::EqObjPtr x);

Eqo::EqObjPtr DLL_PUBLIC getUnsignedValue(Eqo::EqObjPtr x);

Eqo::EqObjPtr DLL_PUBLIC getSign(Eqo::EqObjPtr x);

/// Sorts in order of constants, variables, then other objects
void SortEqVector(std::vector<Eqo::EqObjPtr> &v1);

Eqo::EqObjPtr DLL_PUBLIC subst(Eqo::EqObjPtr a, Eqo::EqObjPtr b, Eqo::EqObjPtr c);

Eqo::EqObjPtr DLL_PUBLIC getNegation(Eqo::EqObjPtr x);

bool DLL_PUBLIC isBinaryFunction(const std::string &str);
bool DLL_PUBLIC isUnaryFunction(const std::string &str);

EqBinaryFuncPtr DLL_PUBLIC getBinaryFuncPtr(const std::string &);
EqUnaryFuncPtr DLL_PUBLIC getUnaryFuncPtr(const std::string &);
}
#endif
