//===-- MoxieCallingConv.td - Calling Conventions Moxie ----*- tablegen -*-===//
//
//                     The LLVM Compiler Infrastructure
//
// This file is distributed under the University of Illinois Open Source
// License. See LICENSE.TXT for details.
//
//===----------------------------------------------------------------------===//
//
// This describes the calling conventions for the Moxie architecture.
//
//===----------------------------------------------------------------------===//

def CSR : CalleeSavedRegs<(add R6, R7, R8, R9, R10, R11)>;

def RetCC_MoxieEABI : CallingConv<[
  // i32 are returned in registers r0 
  CCIfType<[i32], CCAssignToReg<[R0]>>
  ]>;
  