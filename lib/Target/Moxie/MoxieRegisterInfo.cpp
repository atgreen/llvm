//===-- MoxieRegisterInfo.cpp - Moxie Register Information ----------------===//
//
//                     The LLVM Compiler Infrastructure
//
// This file is distributed under the University of Illinois Open Source
// License. See LICENSE.TXT for details.
//
//===----------------------------------------------------------------------===//
//
// This file contains the Moxie implementation of the TargetRegisterInfo class.
//
//===----------------------------------------------------------------------===//

#include "Moxie.h"
#include "MoxieRegisterInfo.h"
#include "MoxieSubtarget.h"
#include "llvm/ADT/BitVector.h"
#include "llvm/CodeGen/MachineFrameInfo.h"
#include "llvm/CodeGen/MachineFunction.h"
#include "llvm/CodeGen/MachineInstrBuilder.h"
#include "llvm/IR/Function.h"
#include "llvm/Support/ErrorHandling.h"
#include "llvm/Target/TargetMachine.h"
#include "llvm/Target/TargetOptions.h"

#define GET_REGINFO_TARGET_DESC
#include "MoxieGenRegisterInfo.inc"
using namespace llvm;

#define DEBUG_TYPE "moxie-reg-info"

// FIXME: Provide proper call frame setup / destroy opcodes.
MoxieRegisterInfo::MoxieRegisterInfo()
  : MoxieGenRegisterInfo(Moxie::FP) {}

BitVector MoxieRegisterInfo::getReservedRegs(const MachineFunction &MF) const {
  BitVector Reserved(getNumRegs());
  Reserved.set(Moxie::FP);
  Reserved.set(Moxie::SP);
  return Reserved;
}

const MCPhysReg*
MoxieRegisterInfo::getCalleeSavedRegs(const MachineFunction *MF) const {
  return CSR_SaveList;
}

const TargetRegisterClass *
MoxieRegisterInfo::getPointerRegClass(const MachineFunction &MF, unsigned Kind)
                                                                         const {
  return &Moxie::GRRegsRegClass;
}

void MoxieRegisterInfo::eliminateFrameIndex(MachineBasicBlock::iterator II,
                                          int SPAdj, unsigned FIOperandNum,
                                          RegScavenger *RS) const {
  assert(0 && "unimplemented");
}

unsigned MoxieRegisterInfo::getFrameRegister(const MachineFunction &MF) const {
  return Moxie::FP;
}
