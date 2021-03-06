//===-- MoxieSubtarget.h - Define Subtarget for the Moxie -------*- C++ -*-===//
//
//                     The LLVM Compiler Infrastructure
//
// This file is distributed under the University of Illinois Open Source
// License. See LICENSE.TXT for details.
//
//===----------------------------------------------------------------------===//
//
// This file declares the Moxie specific subclass of TargetSubtargetInfo.
//
//===----------------------------------------------------------------------===//

#ifndef LLVM_LIB_TARGET_Moxie_MoxieSUBTARGET_H
#define LLVM_LIB_TARGET_Moxie_MoxieSUBTARGET_H

#include "MoxieFrameLowering.h"
#include "MoxieISelLowering.h"
#include "MoxieInstrInfo.h"
#include "llvm/CodeGen/SelectionDAGTargetInfo.h"
#include "llvm/IR/DataLayout.h"
#include "llvm/Target/TargetMachine.h"
#include "llvm/Target/TargetSubtargetInfo.h"

#define GET_SUBTARGETINFO_HEADER
#include "MoxieGenSubtargetInfo.inc"

namespace llvm {
class StringRef;

class MoxieSubtarget : public MoxieGenSubtargetInfo {
  virtual void anchor();
  MoxieInstrInfo InstrInfo;
  MoxieFrameLowering FrameLowering;
  MoxieTargetLowering TLInfo;
  SelectionDAGTargetInfo TSInfo;

public:
  // This constructor initializes the data members to match that
  // of the specified triple.
  MoxieSubtarget(const Triple &TT, const std::string &CPU, const std::string &FS,
               const TargetMachine &TM);

  // ParseSubtargetFeatures - Parses features string setting specified
  // subtarget options.  Definition of function is auto generated by tblgen.
  void ParseSubtargetFeatures(StringRef CPU, StringRef FS);

  const MoxieInstrInfo *getInstrInfo() const override { return &InstrInfo; }
  const MoxieFrameLowering *getFrameLowering() const override {
    return &FrameLowering;
  }
  const MoxieTargetLowering *getTargetLowering() const override {
    return &TLInfo;
  }
  const SelectionDAGTargetInfo *getSelectionDAGInfo() const override {
    return &TSInfo;
  }
  const TargetRegisterInfo *getRegisterInfo() const override {
    return &InstrInfo.getRegisterInfo();
  }
};
} // End llvm namespace

#endif
