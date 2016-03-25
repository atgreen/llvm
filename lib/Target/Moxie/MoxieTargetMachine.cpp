//===-- MoxieTargetMachine.cpp - Define TargetMachine for Moxie ---------===//
//
//                     The LLVM Compiler Infrastructure
//
// This file is distributed under the University of Illinois Open Source
// License. See LICENSE.TXT for details.
//
//===----------------------------------------------------------------------===//
//
// Top-level implementation for the Moxie target.
//
//===----------------------------------------------------------------------===//

#include "MoxieTargetMachine.h"
#include "llvm/CodeGen/TargetLoweringObjectFileImpl.h"
#include "Moxie.h"
#include "llvm/CodeGen/Passes.h"
#include "llvm/MC/MCAsmInfo.h"
#include "llvm/IR/PassManager.h"
#include "llvm/Support/TargetRegistry.h"
using namespace llvm;

extern "C" void LLVMInitializeMoxieTarget() {
  // Register the target.
  RegisterTargetMachine<MoxieTargetMachine> X(TheMoxieTarget);
}

// DataLayout: little or big endian
static std::string computeDataLayout(const Triple &TT) {
  if (TT.getArch() == Triple::moxie)
    return "E-m:e-p:64:64-i64:64-n32:64-S128";
  else
    return "e-m:e-p:64:64-i64:64-n32:64-S128";
}

MoxieTargetMachine::MoxieTargetMachine(const Target &T, const Triple &TT,
				       StringRef CPU, StringRef FS,
				       const TargetOptions &Options,
				       Reloc::Model RM, CodeModel::Model CM,
				       CodeGenOpt::Level OL)
    : LLVMTargetMachine(T, computeDataLayout(TT), TT, CPU, FS, Options, RM, CM,
                        OL),
      TLOF(make_unique<TargetLoweringObjectFileELF>()),
      Subtarget(TT, CPU, FS, *this) {
  initAsmInfo();
}

MoxieTargetMachine::~MoxieTargetMachine() {}

namespace {
// Moxie Code Generator Pass Configuration Options.
class MoxiePassConfig : public TargetPassConfig {
public:
  MoxiePassConfig(MoxieTargetMachine *TM, PassManagerBase &PM)
      : TargetPassConfig(TM, PM) {}

  MoxieTargetMachine &getMoxieTargetMachine() const {
    return getTM<MoxieTargetMachine>();
  }

  bool addInstSelector() override;
};
}

TargetPassConfig *MoxieTargetMachine::createPassConfig(PassManagerBase &PM) {
  return new MoxiePassConfig(this, PM);
}

// Install an instruction selector pass using
// the ISelDag to gen Moxie code.
bool MoxiePassConfig::addInstSelector() {
  addPass(createMoxieISelDag(getMoxieTargetMachine()));

  return false;
}
