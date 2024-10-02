// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#pragma once

#include "Constants.h"
#include "frc2/command/FunctionalCommand.h"

#include <frc2/command/SubsystemBase.h>
#include <frc/drive/MecanumDrive.h>
#include <frc2/command/Command.h>
#include <frc2/command/Commands.h>
#include <frc2/command/FunctionalCommand.h>

#include <rev/CANSparkMax.h>

class Drive : public frc2::SubsystemBase {
 public:
  Drive();

  /**
   * Will be called periodically whenever the CommandScheduler runs.
   */
  void Periodic() override;

  frc2::CommandPtr drive_command(
    std::function<double(void)> drive_power,
    std::function<double(void)> strafe_power,
    std::function<double(void)> rot_power
  );

 private:
  frc::MecanumDrive *m_mecanumdrive;

  rev::CANSparkMax m_fr_motor {
    OperatorConstants::k_fr_id,
    rev::CANSparkMax::MotorType::kBrushless
  };

  rev::CANSparkMax m_fl_motor {
    OperatorConstants::k_fl_id,
    rev::CANSparkMax::MotorType::kBrushless
  };

  rev::CANSparkMax m_br_motor {
    OperatorConstants::k_br_id,
    rev::CANSparkMax::MotorType::kBrushless
  };

  rev::CANSparkMax m_bl_motor {
    OperatorConstants::k_bl_id,
    rev::CANSparkMax::MotorType::kBrushless
  };

  // Components (e.g. motor controllers and sensors) should generally be
  // declared private and exposed only through public methods.
};
