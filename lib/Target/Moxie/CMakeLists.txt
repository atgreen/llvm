set(LLVM_TARGET_DEFINITIONS Moxie.td)


tablegen(LLVM MoxieGenRegisterInfo.inc -gen-register-info)
tablegen(LLVM MoxieGenInstrInfo.inc -gen-instr-info)
tablegen(LLVM MoxieGenAsmWriter.inc -gen-asm-writer)
tablegen(LLVM MoxieGenDAGISel.inc -gen-dag-isel)
tablegen(LLVM MoxieGenCallingConv.inc -gen-callingconv)
tablegen(LLVM MoxieGenSubtargetInfo.inc -gen-subtarget)
add_public_tablegen_target(MoxieCommonTableGen)

set(MoxieCodeGen_sources
  MoxieAsmPrinter.cpp
  MoxieFrameLowering.cpp
  MoxieInstrInfo.cpp
  MoxieISelLowering.cpp
  MoxieISelDAGtoDAG.cpp
  MoxieMCInstLower.cpp
  MoxieRegisterInfo.cpp
  MoxieSubtarget.cpp
  MoxieTargetMachine.cpp
  )

add_llvm_target(MoxieCodeGen ${MoxieCodeGen_sources})

add_subdirectory(InstPrinter)
add_subdirectory(TargetInfo)
add_subdirectory(MCTargetDesc)
