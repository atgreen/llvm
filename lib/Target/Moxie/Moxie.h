//==-- Moxie.h - Top-level interface for Moxie representation ----*- C++ -*-==//
//
//                     The LLVM Compiler Infrastructure
//
// This file is distributed under the University of Illinois Open Source
// License. See LICENSE.TXT for details.
//
//===----------------------------------------------------------------------===//
//
// This file contains the entry points for global functions defined in
// the LLVM Moxie backend.
//
//===----------------------------------------------------------------------===//

#ifndef LLVM_LIB_TARGET_MOXIE_MOXIE_H
#define LLVM_LIB_TARGET_MOXIE_MOXIE_H

#include "MCTargetDesc/MoxieMCTargetDesc.h"
#include "llvm/Target/TargetMachine.h"

namespace llvm {
  class MoxieTargetMachine;
  class FunctionPass;
  class formatted_raw_ostream;

  FunctionPass *createMoxieISelDag(MoxieTargetMachine &TM);

  FunctionPass *createMoxieBranchSelectionPass();

} // end namespace llvm;

#endif
