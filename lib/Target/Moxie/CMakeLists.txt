set(LLVM_TARGET_DEFINITIONS Moxie.td)


tablegen(LLVM MoxieGenRegisterInfo.inc -gen-register-info)
tablegen(LLVM MoxieGenInstrInfo.inc -gen-instr-info)
tablegen(LLVM MoxieGenAsmWriter.inc -gen-asm-writer)
tablegen(LLVM MoxieGenDAGISel.inc -gen-dag-isel)
<<<<<<< HEAD
tablegen(LLVM MoxieGenCallingConv.inc -gen-callingconv)
=======
>>>>>>> 04fdfe34d2a8f883e0ef4ddf2c252a4d7c2274fd
tablegen(LLVM MoxieGenSubtargetInfo.inc -gen-subtarget)
add_public_tablegen_target(MoxieCommonTableGen)

set(MoxieCodeGen_sources
  MoxieAsmPrinter.cpp
  MoxieFrameLowering.cpp
  MoxieInstrInfo.cpp
  MoxieISelLowering.cpp
<<<<<<< HEAD
  MoxieISelDAGtoDAG.cpp
=======
>>>>>>> 04fdfe34d2a8f883e0ef4ddf2c252a4d7c2274fd
  MoxieMCInstLower.cpp
  MoxieRegisterInfo.cpp
  MoxieSubtarget.cpp
  MoxieTargetMachine.cpp
  )

add_llvm_target(MoxieCodeGen ${MoxieCodeGen_sources})

add_subdirectory(InstPrinter)
add_subdirectory(TargetInfo)
add_subdirectory(MCTargetDesc)
