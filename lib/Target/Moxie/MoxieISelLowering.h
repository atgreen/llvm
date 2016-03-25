//===-- MoxieISelLowering.h - Moxie DAG Lowering Interface ------*- C++ -*-===//
//
//                     The LLVM Compiler Infrastructure
//
// This file is distributed under the University of Illinois Open Source
// License. See LICENSE.TXT for details.
//
//===----------------------------------------------------------------------===//
//
// This file defines the interfaces that Moxie uses to lower LLVM code into a
// selection DAG.
//
//===----------------------------------------------------------------------===//

#ifndef LLVM_LIB_TARGET_MOXIE_MOXIEISELLOWERING_H
#define LLVM_LIB_TARGET_MOXIE_MOXIEISELLOWERING_H

#include "Moxie.h"
#include "llvm/CodeGen/SelectionDAG.h"
#include "llvm/Target/TargetLowering.h"

namespace llvm {
class MoxieSubtarget;
namespace MoxieISD {
enum NodeType : unsigned {
  FIRST_NUMBER = ISD::BUILTIN_OP_END,
<<<<<<< HEAD
  RET,
=======
>>>>>>> 04fdfe34d2a8f883e0ef4ddf2c252a4d7c2274fd
  RET_FLAG,
  CALL,
  SELECT_CC,
  BR_CC,
  Wrapper
};
}

class MoxieTargetLowering : public TargetLowering {
public:
  explicit MoxieTargetLowering(const TargetMachine &TM, const MoxieSubtarget &STI);

  // Provide custom lowering hooks for some operations.
  SDValue LowerOperation(SDValue Op, SelectionDAG &DAG) const override;

  // This method returns the name of a target specific DAG node.
  const char *getTargetNodeName(unsigned Opcode) const override;

  MachineBasicBlock *
  EmitInstrWithCustomInserter(MachineInstr *MI,
                              MachineBasicBlock *BB) const override;

private:
  SDValue LowerBR_CC(SDValue Op, SelectionDAG &DAG) const;
  SDValue LowerSELECT_CC(SDValue Op, SelectionDAG &DAG) const;
  SDValue LowerGlobalAddress(SDValue Op, SelectionDAG &DAG) const;

  // Lower the result values of a call, copying them out of physregs into vregs
  SDValue LowerCallResult(SDValue Chain, SDValue InFlag,
                          CallingConv::ID CallConv, bool IsVarArg,
                          const SmallVectorImpl<ISD::InputArg> &Ins, SDLoc DL,
                          SelectionDAG &DAG,
                          SmallVectorImpl<SDValue> &InVals) const;

  // Lower a call into CALLSEQ_START - MoxieISD:CALL - CALLSEQ_END chain
  SDValue LowerCall(TargetLowering::CallLoweringInfo &CLI,
                    SmallVectorImpl<SDValue> &InVals) const override;

  // Lower incoming arguments, copy physregs into vregs
  SDValue LowerFormalArguments(SDValue Chain, CallingConv::ID CallConv,
                               bool IsVarArg,
                               const SmallVectorImpl<ISD::InputArg> &Ins,
                               SDLoc DL, SelectionDAG &DAG,
                               SmallVectorImpl<SDValue> &InVals) const override;

  SDValue LowerReturn(SDValue Chain, CallingConv::ID CallConv, bool IsVarArg,
                      const SmallVectorImpl<ISD::OutputArg> &Outs,
                      const SmallVectorImpl<SDValue> &OutVals, SDLoc DL,
                      SelectionDAG &DAG) const override;

  EVT getOptimalMemOpType(uint64_t Size, unsigned DstAlign, unsigned SrcAlign,
                          bool IsMemset, bool ZeroMemset, bool MemcpyStrSrc,
                          MachineFunction &MF) const override {
    return Size >= 8 ? MVT::i64 : MVT::i32;
  }

  bool shouldConvertConstantLoadToIntImm(const APInt &Imm,
                                         Type *Ty) const override {
    return true;
  }
};
}

#endif
