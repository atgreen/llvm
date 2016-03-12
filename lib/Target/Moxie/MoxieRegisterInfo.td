//===-- MoxieRegisterInfo.td - Moxie Register defs -------*- tablegen ---*-===//
//
//                     The LLVM Compiler Infrastructure
//
// This file is distributed under the University of Illinois Open Source 
// License. See LICENSE.TXT for details.
//
//===----------------------------------------------------------------------===//

//===----------------------------------------------------------------------===//
//  Declarations that describe the Moxie register file
//===----------------------------------------------------------------------===//

class MoxieReg<bits<4> num, string n> : Register<n> {
  field bits<4> Num = num;
  let Namespace = "Moxie";
}

class MoxieRegWithSubregs<bits<4> num, string n, list<Register> subregs> 
  : RegisterWithSubRegs<n, subregs> {
  field bits<4> Num = num;
  let Namespace = "Moxie";
}

//===----------------------------------------------------------------------===//
//  Registers
//===----------------------------------------------------------------------===//

def FPB  : MoxieReg<0,  "$fp">;
def SPB  : MoxieReg<1,  "$sp">;
def R0B  : MoxieReg<2,  "$r0">;
def R1B  : MoxieReg<3,  "$r1">;
def R2B  : MoxieReg<4,  "$r2">;
def R3B  : MoxieReg<5,  "$r3">;
def R4B  : MoxieReg<6,  "$r4">;
def R5B  : MoxieReg<7,  "$r5">;
def R6B  : MoxieReg<8,  "$r6">;
def R7B  : MoxieReg<9,  "$r7">;
def R8B  : MoxieReg<10, "$r8">;
def R9B  : MoxieReg<11, "$r9">;
def R10B : MoxieReg<12, "$r10">;
def R11B : MoxieReg<13, "$r11">;
def R12B : MoxieReg<14, "$r12">;
def R13B : MoxieReg<15, "$r13">;

def subreg_8bit : SubRegIndex<8> { let Namespace = "Moxie"; }

let SubRegIndices = [subreg_8bit] in {
def FP  : MoxieRegWithSubregs<0,  "$fp",  [FPB]>;
def SP  : MoxieRegWithSubregs<1,  "$sp",  [SPB]>;
def R0  : MoxieRegWithSubregs<2,  "$r0",  [R0B]>;
def R1  : MoxieRegWithSubregs<3,  "$r1",  [R1B]>;
def R2  : MoxieRegWithSubregs<4,  "$r2",  [R2B]>;
def R3  : MoxieRegWithSubregs<5,  "$r3",  [R3B]>;
def R4  : MoxieRegWithSubregs<6,  "$r4",  [R4B]>;
def R5  : MoxieRegWithSubregs<7,  "$r5",  [R5B]>;
def R6  : MoxieRegWithSubregs<8,  "$r6",  [R6B]>;
def R7  : MoxieRegWithSubregs<9,  "$r7",  [R7B]>;
def R8  : MoxieRegWithSubregs<10, "$r8",  [R8B]>;
def R9  : MoxieRegWithSubregs<11, "$r9",  [R9B]>;
def R10 : MoxieRegWithSubregs<12, "$r10", [R10B]>;
def R11 : MoxieRegWithSubregs<13, "$r11", [R11B]>;
def R12 : MoxieRegWithSubregs<14, "$r12", [R12B]>;
def R13 : MoxieRegWithSubregs<15, "$r13", [R13B]>;
}

// Register classes.
//
def GRRegs : RegisterClass<"Moxie", [i32], 32,
   // Volatile registers
  (add R13B, R12B, R11B, R10B, R9B, R8B, R7B, R6B, R5B, R4B, R3B, R2B, R1B, R0B,
   // Frame pointer, sometimes allocable
   FPB,
   // Volatile, but not allocable
   SPB)>;

// Reserved
def RRegs : RegisterClass<"Moxie", [i32], 32,
   // Volatile registers
  (add R13, R12, R11, R10, R9, R8, R7, R6, R5, R4, R3, R2, R1, R0,
   // Frame pointer, sometimes allocable
   FP,
   // Volatile, but not allocable
   SP)> {
  let isAllocatable = 0;
}

