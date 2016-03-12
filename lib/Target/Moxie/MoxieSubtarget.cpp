//===-- MoxieSubtarget.cpp - Moxie Subtarget Information ------------------===//
//
//                     The LLVM Compiler Infrastructure
//
// This file is distributed under the University of Illinois Open Source
// License. See LICENSE.TXT for details.
//
//===----------------------------------------------------------------------===//
//
// This file implements the Moxie specific subclass of TargetSubtargetInfo.
//
//===----------------------------------------------------------------------===//

#include "MoxieSubtarget.h"
#include "Moxie.h"
#include "llvm/Support/TargetRegistry.h"

using namespace llvm;

#define DEBUG_TYPE "moxie-subtarget"

#define GET_SUBTARGETINFO_TARGET_DESC
#define GET_SUBTARGETINFO_CTOR
#include "MoxieGenSubtargetInfo.inc"

void MoxieSubtarget::anchor() {}

MoxieSubtarget::MoxieSubtarget(const Triple &TT, const std::string &CPU,
                           const std::string &FS, const TargetMachine &TM)
    : MoxieGenSubtargetInfo(TT, CPU, FS), InstrInfo(), FrameLowering(*this),
      TLInfo(TM, *this) {}
