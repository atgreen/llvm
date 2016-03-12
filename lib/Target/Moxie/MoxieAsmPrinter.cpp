//===-- MoxieAsmPrinter.cpp - Moxie LLVM assembly writer ------------------===//
//
//                     The LLVM Compiler Infrastructure
//
// This file is distributed under the University of Illinois Open Source
// License. See LICENSE.TXT for details.
//
//===----------------------------------------------------------------------===//
//
// This file contains a printer that converts from our internal representation
// of machine-dependent LLVM code to the Moxie assembly language.
//
//===----------------------------------------------------------------------===//

#include "Moxie.h"
#include "MoxieInstrInfo.h"
#include "MoxieMCInstLower.h"
#include "MoxieTargetMachine.h"
#include "InstPrinter/MoxieInstPrinter.h"
#include "llvm/CodeGen/AsmPrinter.h"
#include "llvm/CodeGen/MachineModuleInfo.h"
#include "llvm/CodeGen/MachineFunctionPass.h"
#include "llvm/CodeGen/MachineConstantPool.h"
#include "llvm/CodeGen/MachineInstr.h"
#include "llvm/MC/MCAsmInfo.h"
#include "llvm/MC/MCInst.h"
#include "llvm/MC/MCStreamer.h"
#include "llvm/MC/MCSymbol.h"
#include "llvm/Support/TargetRegistry.h"
#include "llvm/Support/raw_ostream.h"
using namespace llvm;

#define DEBUG_TYPE "asm-printer"

namespace {
class MoxieAsmPrinter : public AsmPrinter {
public:
  explicit MoxieAsmPrinter(TargetMachine &TM, std::unique_ptr<MCStreamer> Streamer)
      : AsmPrinter(TM, std::move(Streamer)) {}

  const char *getPassName() const override { return "Moxie Assembly Printer"; }

  void printOperand(const MachineInstr *MI, int OpNum, raw_ostream &O,
                    const char *Modifier = nullptr);
  void EmitInstruction(const MachineInstr *MI) override;
};
}

void MoxieAsmPrinter::printOperand(const MachineInstr *MI, int OpNum,
                                 raw_ostream &O, const char *Modifier) {
  const MachineOperand &MO = MI->getOperand(OpNum);

  switch (MO.getType()) {
  case MachineOperand::MO_Register:
    O << MoxieInstPrinter::getRegisterName(MO.getReg());
    break;

  case MachineOperand::MO_Immediate:
    O << MO.getImm();
    break;

  case MachineOperand::MO_MachineBasicBlock:
    O << *MO.getMBB()->getSymbol();
    break;

  case MachineOperand::MO_GlobalAddress:
    O << *getSymbol(MO.getGlobal());
    break;

  default:
    llvm_unreachable("<unknown operand type>");
  }
}

void MoxieAsmPrinter::EmitInstruction(const MachineInstr *MI) {

  MoxieMCInstLower MCInstLowering(OutContext, *this);

  MCInst TmpInst;
  MCInstLowering.Lower(MI, TmpInst);
  EmitToStreamer(*OutStreamer, TmpInst);
}

// Force static initialization.
extern "C" void LLVMInitializeMoxieAsmPrinter() {
  RegisterAsmPrinter<MoxieAsmPrinter> Z(TheMoxieTarget);
}
