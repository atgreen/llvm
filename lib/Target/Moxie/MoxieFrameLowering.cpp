//===-- MoxieFrameLowering.cpp - Moxie Frame Information ------------------===//
//
//                     The LLVM Compiler Infrastructure
//
// This file is distributed under the University of Illinois Open Source
// License. See LICENSE.TXT for details.
//
//===----------------------------------------------------------------------===//
//
// This file contains the Moxie implementation of TargetFrameLowering class.
//
//===----------------------------------------------------------------------===//

#include "MoxieFrameLowering.h"
#include "MoxieInstrInfo.h"
#include "MoxieSubtarget.h"
#include "llvm/CodeGen/MachineFrameInfo.h"
#include "llvm/CodeGen/MachineFunction.h"
#include "llvm/CodeGen/MachineInstrBuilder.h"
#include "llvm/CodeGen/MachineRegisterInfo.h"

using namespace llvm;

bool MoxieFrameLowering::hasFP(const MachineFunction &MF) const { return true; }

void MoxieFrameLowering::emitPrologue(MachineFunction &MF,
                                    MachineBasicBlock &MBB) const {}

void MoxieFrameLowering::emitEpilogue(MachineFunction &MF,
                                    MachineBasicBlock &MBB) const {}

void MoxieFrameLowering::determineCalleeSaves(MachineFunction &MF,
                                            BitVector &SavedRegs,
                                            RegScavenger *RS) const {
  TargetFrameLowering::determineCalleeSaves(MF, SavedRegs, RS);
  SavedRegs.reset(Moxie::R6);
  SavedRegs.reset(Moxie::R7);
  SavedRegs.reset(Moxie::R8);
  SavedRegs.reset(Moxie::R9);
}
