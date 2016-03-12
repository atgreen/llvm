//===-- MoxieTargetMachine.h - Define TargetMachine for Moxie ---*- C++ -*-===//
//
//                     The LLVM Compiler Infrastructure
//
// This file is distributed under the University of Illinois Open Source
// License. See LICENSE.TXT for details.
//
//===----------------------------------------------------------------------===//
//
// This file declares the Moxie specific subclass of TargetMachine.
//
//===----------------------------------------------------------------------===//


#ifndef LLVM_LIB_TARGET_MOXIE_MOXIETARGETMACHINE_H
#define LLVM_LIB_TARGET_MOXIE_MOXIETARGETMACHINE_H

#include "MoxieSubtarget.h"
#include "llvm/Target/TargetFrameLowering.h"
#include "llvm/Target/TargetMachine.h"

namespace llvm {

/// MoxieTargetMachine
///
class MoxieTargetMachine : public LLVMTargetMachine {
  std::unique_ptr<TargetLoweringObjectFile> TLOF;
  MoxieSubtarget Subtarget;

public:
  MoxieTargetMachine(const Target &T, const Triple &TT, StringRef CPU,
                     StringRef FS, const TargetOptions &Options,
		     Reloc::Model RM, CodeModel::Model CM,
                     CodeGenOpt::Level OL);
  ~MoxieTargetMachine() override;

  const MoxieSubtarget *getSubtargetImpl() const { return &Subtarget; }
  const MoxieSubtarget *getSubtargetImpl(const Function &) const override {
    return &Subtarget;
  }

  TargetPassConfig *createPassConfig(PassManagerBase &PM) override;

  TargetLoweringObjectFile *getObjFileLowering() const override {
    return TLOF.get();
  }
}; // MoxieTargetMachine.

} // end namespace llvm

#endif
