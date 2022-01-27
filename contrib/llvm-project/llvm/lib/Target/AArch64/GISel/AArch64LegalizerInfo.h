//===- AArch64LegalizerInfo --------------------------------------*- C++ -*-==//
//
// Part of the LLVM Project, under the Apache License v2.0 with LLVM Exceptions.
// See https://llvm.org/LICENSE.txt for license information.
// SPDX-License-Identifier: Apache-2.0 WITH LLVM-exception
//
//===----------------------------------------------------------------------===//
/// \file
/// This file declares the targeting of the Machinelegalizer class for
/// AArch64.
/// \todo This should be generated by TableGen.
//===----------------------------------------------------------------------===//

#ifndef LLVM_LIB_TARGET_AARCH64_AARCH64MACHINELEGALIZER_H
#define LLVM_LIB_TARGET_AARCH64_AARCH64MACHINELEGALIZER_H

#include "llvm/CodeGen/GlobalISel/GISelChangeObserver.h"
#include "llvm/CodeGen/GlobalISel/LegalizerHelper.h"
#include "llvm/CodeGen/GlobalISel/LegalizerInfo.h"
#include "llvm/CodeGen/MachineRegisterInfo.h"

namespace llvm {

class AArch64Subtarget;

/// This class provides the information for the target register banks.
class AArch64LegalizerInfo : public LegalizerInfo {
public:
  AArch64LegalizerInfo(const AArch64Subtarget &ST);

  bool legalizeCustom(LegalizerHelper &Helper, MachineInstr &MI) const override;

  bool legalizeIntrinsic(LegalizerHelper &Helper,
                         MachineInstr &MI) const override;

private:
  bool legalizeVaArg(MachineInstr &MI, MachineRegisterInfo &MRI,
                     MachineIRBuilder &MIRBuilder) const;
  bool legalizeLoadStore(MachineInstr &MI, MachineRegisterInfo &MRI,
                         MachineIRBuilder &MIRBuilder,
                         GISelChangeObserver &Observer) const;
  bool legalizeShlAshrLshr(MachineInstr &MI, MachineRegisterInfo &MRI,
                           MachineIRBuilder &MIRBuilder,
                           GISelChangeObserver &Observer) const;

  bool legalizeSmallCMGlobalValue(MachineInstr &MI, MachineRegisterInfo &MRI,
                                  MachineIRBuilder &MIRBuilder,
                                  GISelChangeObserver &Observer) const;
  bool legalizeVectorTrunc(MachineInstr &MI, LegalizerHelper &Helper) const;
  bool legalizeBitfieldExtract(MachineInstr &MI, MachineRegisterInfo &MRI,
                               LegalizerHelper &Helper) const;
  bool legalizeRotate(MachineInstr &MI, MachineRegisterInfo &MRI,
                      LegalizerHelper &Helper) const;
  bool legalizeCTPOP(MachineInstr &MI, MachineRegisterInfo &MRI,
                     LegalizerHelper &Helper) const;
  bool legalizeAtomicCmpxchg128(MachineInstr &MI, MachineRegisterInfo &MRI,
                                LegalizerHelper &Helper) const;
  bool legalizeCTTZ(MachineInstr &MI, LegalizerHelper &Helper) const;
  const AArch64Subtarget *ST;
};
} // End llvm namespace.
#endif
