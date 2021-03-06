//===-- MoxieTargetInfo.cpp - Moxie Target Implementation -----------------===//
//
//                     The LLVM Compiler Infrastructure
//
// This file is distributed under the University of Illinois Open Source
// License. See LICENSE.TXT for details.
//
//===----------------------------------------------------------------------===//

#include "Moxie.h"
#include "llvm/IR/Module.h"
#include "llvm/Support/TargetRegistry.h"
using namespace llvm;

Target llvm::TheMoxieTarget;

extern "C" void LLVMInitializeMoxieTargetInfo() { 
  RegisterTarget<Triple::moxie> 
    X(TheMoxieTarget, "moxie", "Moxie [experimental]");
}
