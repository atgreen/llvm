//===-- MoxieMCTargetDesc.h - Moxie Target Descriptions ---------*- C++ -*-===//
//
//                     The LLVM Compiler Infrastructure
//
// This file is distributed under the University of Illinois Open Source
// License. See LICENSE.TXT for details.
//
//===----------------------------------------------------------------------===//
//
// This file provides Moxie specific target descriptions.
//
//===----------------------------------------------------------------------===//

#ifndef LLVM_LIB_TARGET_MOXIE_MCTARGETDESC_MOXIEMCTARGETDESC_H
#define LLVM_LIB_TARGET_MOXIE_MCTARGETDESC_MOXIEMCTARGETDESC_H

#include "llvm/MC/MCAsmBackend.h"
#include "llvm/MC/MCRegisterInfo.h"
#include "llvm/ADT/Triple.h"
#include "llvm/Support/DataTypes.h"
#include "llvm/Config/config.h"

namespace llvm {
class Target;

extern Target TheMoxieTarget;

MCAsmBackend *createMoxieAsmBackend(const Target &T, const MCRegisterInfo &MRI,
				    const Triple &TT, StringRef CPU);

} // End llvm namespace

// Defines symbolic names for Moxie registers.
// This defines a mapping from register name to register number.
#define GET_REGINFO_ENUM
#include "MoxieGenRegisterInfo.inc"

// Defines symbolic names for the Moxie instructions.
#define GET_INSTRINFO_ENUM
#include "MoxieGenInstrInfo.inc"

#define GET_SUBTARGETINFO_ENUM
#include "MoxieGenSubtargetInfo.inc"
#endif
