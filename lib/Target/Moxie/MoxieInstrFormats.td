//===-- MoxieInstrFormats.td - Moxie Instruction Formats -*- tablegen ---*-===//
//
//                     The LLVM Compiler Infrastructure
//
// This file is distributed under the University of Illinois Open Source 
// License. See LICENSE.TXT for details.
//
//===----------------------------------------------------------------------===//

//===----------------------------------------------------------------------===//
//  Describe Moxie instructions format here
//

class MoxieInstruction<dag outs, dag ins, string asmstr, list<dag> pattern> : Instruction {
  let Namespace = "Moxie";

  dag OutOperandList = outs;
  dag InOperandList = ins;
  let AsmString = asmstr;
  let Pattern = pattern;
}

// Format specifies the encoding used by the instruction.  This is part of the
// ad-hoc solution used to emit machine instruction encodings by our machine
// code emitter.
class Format<bits<2> val, dag outs, dag ins, string asmstr, list<dag> pattern>
  : MoxieInstruction<outs, ins, asmstr, pattern> {
  bits<2> Value = val;
}

class F1<bits<6> opcode, dag outs, dag ins, string asmstr, list<dag> pattern>
  : Format<0b00, outs, ins, asmstr, pattern>
{
//  let Inst = opcode;
}

class SourceMode<bits<2> val> {
  bits<2> Value = val;
}

def SrcReg      : SourceMode<0>;
def SrcMem      : SourceMode<1>;
def SrcIndReg   : SourceMode<2>;
def SrcPostInc  : SourceMode<3>;
def SrcImm      : SourceMode<3>;

class DestMode<bit val> {
  bit Value = val;
}

def DstReg      : DestMode<0>;
def DstMem      : DestMode<1>;

class SizeVal<bits<3> val> {
  bits<3> Value = val;
}

