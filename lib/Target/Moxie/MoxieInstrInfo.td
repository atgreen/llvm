//===-- MoxieInstrInfo.td - Moxie Instruction defs ---------*- tablegen -*-===//
//
//                     The LLVM Compiler Infrastructure
//
// This file is distributed under the University of Illinois Open Source 
// License. See LICENSE.TXT for details.
//
//===----------------------------------------------------------------------===//
//
// This file describes the Moxie instructions in TableGen format.
//
//===----------------------------------------------------------------------===//

include "MoxieInstrFormats.td"

// NOP
// No-operation instruction
// ---------
// <|0000|0000|0000|0000>
def NOP : F1<0b000000,
              (outs),
              (ins),
              "nop",
              []>;
