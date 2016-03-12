//===-- MoxieMCTargetDesc.cpp - Moxie Target Descriptions -----------------===//
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

#include "Moxie.h"
#include "MoxieMCTargetDesc.h"
#include "MoxieMCAsmInfo.h"
#include "InstPrinter/MoxieInstPrinter.h"
#include "llvm/MC/MCCodeGenInfo.h"
#include "llvm/MC/MCInstrInfo.h"
#include "llvm/MC/MCRegisterInfo.h"
#include "llvm/MC/MCStreamer.h"
#include "llvm/MC/MCSubtargetInfo.h"
#include "llvm/Support/ErrorHandling.h"
#include "llvm/Support/TargetRegistry.h"

#define GET_INSTRINFO_MC_DESC
#include "MoxieGenInstrInfo.inc"

#define GET_SUBTARGETINFO_MC_DESC
#include "MoxieGenSubtargetInfo.inc"

#define GET_REGINFO_MC_DESC
#include "MoxieGenRegisterInfo.inc"

using namespace llvm;

static MCInstrInfo *createMoxieMCInstrInfo() {
  MCInstrInfo *X = new MCInstrInfo();
  InitMoxieMCInstrInfo(X);
  return X;
}

static MCRegisterInfo *createMoxieMCRegisterInfo(const Triple &TT) {
  MCRegisterInfo *X = new MCRegisterInfo();
  InitMoxieMCRegisterInfo(X, Moxie::FP);
  return X;
}

static MCSubtargetInfo *createMoxieMCSubtargetInfo(const Triple &TT,
						   StringRef CPU, StringRef FS) {
  return createMoxieMCSubtargetInfoImpl(TT, CPU, FS);
}

static MCCodeGenInfo *createMoxieMCCodeGenInfo(const Triple &TT, Reloc::Model RM,
					       CodeModel::Model CM,
					       CodeGenOpt::Level OL) {
  MCCodeGenInfo *X = new MCCodeGenInfo();
  X->initMCCodeGenInfo(RM, CM, OL);
  return X;
}

static MCStreamer *createMoxieMCStreamer(const Triple &T,
					 MCContext &Ctx, MCAsmBackend &MAB,
					 raw_pwrite_stream &OS, MCCodeEmitter *Emitter,
					 bool RelaxAll) {
  return createELFStreamer(Ctx, MAB, OS, Emitter, RelaxAll);
}

static MCInstPrinter *createMoxieMCInstPrinter(const Triple &T,
					       unsigned SyntaxVariant,
					       const MCAsmInfo &MAI,
					       const MCInstrInfo &MII,
					       const MCRegisterInfo &MRI) {
  if (SyntaxVariant == 0)
    return new MoxieInstPrinter(MAI, MII, MRI);
  return 0;
}

extern "C" void LLVMInitializeMoxieTargetMC() {

  for (Target *T : {&TheMoxieTarget}) {
    // Register the MC asm info.
    RegisterMCAsmInfo<MoxieMCAsmInfo> X(*T);

    // Register the MC codegen info.
    TargetRegistry::RegisterMCCodeGenInfo(*T, createMoxieMCCodeGenInfo);

    // Register the MC instruction info.
    TargetRegistry::RegisterMCInstrInfo(*T, createMoxieMCInstrInfo);

    // Register the MC register info.
    TargetRegistry::RegisterMCRegInfo(*T, createMoxieMCRegisterInfo);

    // Register the MC subtarget info.
    TargetRegistry::RegisterMCSubtargetInfo(*T,
                                            createMoxieMCSubtargetInfo);

    // Register the object streamer
    TargetRegistry::RegisterELFStreamer(*T, createMoxieMCStreamer);

    // Register the MCInstPrinter.
    TargetRegistry::RegisterMCInstPrinter(*T, createMoxieMCInstPrinter);
  }

  // Register the MC code emitter
  // TargetRegistry::RegisterMCCodeEmitter(TheMoxieTarget, createMoxieMCCodeEmitter);

  // Register the ASM Backend
  TargetRegistry::RegisterMCAsmBackend(TheMoxieTarget, createMoxieAsmBackend);
}

