//===-- MoxieInstrInfo.cpp - Moxie Instruction Information ------*- C++ -*-===//
//
//                     The LLVM Compiler Infrastructure
//
// This file is distributed under the University of Illinois Open Source
// License. See LICENSE.TXT for details.
//
//===----------------------------------------------------------------------===//
//
// This file contains the Moxie implementation of the TargetInstrInfo class.
//
//===----------------------------------------------------------------------===//

#include "Moxie.h"
#include "MoxieInstrInfo.h"
#include "MoxieSubtarget.h"
#include "MoxieTargetMachine.h"
#include "llvm/CodeGen/MachineFunctionPass.h"
#include "llvm/CodeGen/MachineInstrBuilder.h"
#include "llvm/CodeGen/MachineRegisterInfo.h"
#include "llvm/Support/ErrorHandling.h"
#include "llvm/Support/TargetRegistry.h"
#include "llvm/ADT/STLExtras.h"
#include "llvm/ADT/SmallVector.h"

#define GET_INSTRINFO_CTOR_DTOR
#include "MoxieGenInstrInfo.inc"

using namespace llvm;

MoxieInstrInfo::MoxieInstrInfo()
    : MoxieGenInstrInfo() {}

void MoxieInstrInfo::copyPhysReg(MachineBasicBlock &MBB,
                               MachineBasicBlock::iterator I, DebugLoc DL,
                               unsigned DestReg, unsigned SrcReg,
                               bool KillSrc) const {
  // FIXME
  assert(0 && "Unimplemented");
}

void MoxieInstrInfo::storeRegToStackSlot(MachineBasicBlock &MBB,
                                       MachineBasicBlock::iterator I,
                                       unsigned SrcReg, bool IsKill, int FI,
                                       const TargetRegisterClass *RC,
                                       const TargetRegisterInfo *TRI) const {
  // FIXME
  assert(0 && "Unimplemented");
}

void MoxieInstrInfo::loadRegFromStackSlot(MachineBasicBlock &MBB,
                                        MachineBasicBlock::iterator I,
                                        unsigned DestReg, int FI,
                                        const TargetRegisterClass *RC,
                                        const TargetRegisterInfo *TRI) const {
  // FIXME
  assert(0 && "Unimplemented");
}

bool MoxieInstrInfo::AnalyzeBranch(MachineBasicBlock &MBB,
                                 MachineBasicBlock *&TBB,
                                 MachineBasicBlock *&FBB,
                                 SmallVectorImpl<MachineOperand> &Cond,
                                 bool AllowModify) const {
  // FIXME
  assert(0 && "Unimplemented");
  return false;
}

unsigned MoxieInstrInfo::InsertBranch(MachineBasicBlock &MBB,
                                    MachineBasicBlock *TBB,
                                    MachineBasicBlock *FBB,
                                    ArrayRef<MachineOperand> Cond,
                                    DebugLoc DL) const {
  // FIXME
  assert(0 && "Unimplemented");
  return 0;
}

unsigned MoxieInstrInfo::RemoveBranch(MachineBasicBlock &MBB) const {
  // FIXME
  assert(0 && "Unimplemented");
  return 0;
}
