//===-- MoxieMCAsmInfo.h - Moxie asm erties -------------------*- C++ -*--====//
//
//                     The LLVM Compiler Infrastructure
//
// This file is distributed under the University of Illinois Open Source
// License. See LICENSE.TXT for details.
//
//===----------------------------------------------------------------------===//
//
// This file contains the declaration of the MoxieMCAsmInfo class.
//
//===----------------------------------------------------------------------===//

#ifndef LLVM_LIB_TARGET_MOXIE_MCTARGETDESC_MOXIEMCASMINFO_H
#define LLVM_LIB_TARGET_MOXIE_MCTARGETDESC_MOXIEMCASMINFO_H

#include "llvm/ADT/StringRef.h"
#include "llvm/MC/MCAsmInfo.h"
#include "llvm/ADT/Triple.h"

namespace llvm {
class Target;
class Triple;

class MoxieMCAsmInfo : public MCAsmInfo {
public:
  explicit MoxieMCAsmInfo(const Triple &TT) {
    IsLittleEndian = true;

    PrivateGlobalPrefix = ".L";
    WeakRefDirective = "\t.weak\t";

    UsesELFSectionDirectiveForBSS = true;
    HasSingleParameterDotFile = false;
    HasDotTypeDotSizeDirective = false;

    SupportsDebugInformation = true;
  }
};
}

#endif
