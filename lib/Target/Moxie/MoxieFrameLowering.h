//===-- MoxieFrameLowering.h - Define frame lowering for Moxie -*- C++ -*--===//
//
//                     The LLVM Compiler Infrastructure
//
// This file is distributed under the University of Illinois Open Source
// License. See LICENSE.TXT for details.
//
//===----------------------------------------------------------------------===//
//
// This class implements Moxie-specific bits of TargetFrameLowering class.
//
//===----------------------------------------------------------------------===//

#ifndef LLVM_LIB_TARGET_MOXIE_MOXIEFRAMELOWERING_H
#define LLVM_LIB_TARGET_MOXIE_MOXIEFRAMELOWERING_H

#include "llvm/Target/TargetFrameLowering.h"

namespace llvm {
class MoxieSubtarget;

class MoxieFrameLowering : public TargetFrameLowering {
public:
  explicit MoxieFrameLowering(const MoxieSubtarget &sti)
      : TargetFrameLowering(TargetFrameLowering::StackGrowsDown, 8, 0) {}

  void emitPrologue(MachineFunction &MF, MachineBasicBlock &MBB) const override;
  void emitEpilogue(MachineFunction &MF, MachineBasicBlock &MBB) const override;

  bool hasFP(const MachineFunction &MF) const override;
  void determineCalleeSaves(MachineFunction &MF, BitVector &SavedRegs,
                            RegScavenger *RS) const override;

  void
  eliminateCallFramePseudoInstr(MachineFunction &MF, MachineBasicBlock &MBB,
                                MachineBasicBlock::iterator MI) const override {
    MBB.erase(MI);
  }
};
}
#endif
