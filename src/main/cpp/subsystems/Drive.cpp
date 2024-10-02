// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include "subsystems/Drive.h"

Drive::Drive()
{
    m_mecanumdrive = new frc::MecanumDrive(m_fl_motor, m_bl_motor, m_fr_motor, m_br_motor);
}

// This method will be called once per scheduler run
void Drive::Periodic() {}

frc2::CommandPtr Drive::drive_command(
    std::function<double(void)> drive_power,
    std::function<double(void)> strafe_power,
    std::function<double(void)> rot_power)
{
    return this->RunEnd(
        [this, drive_power, strafe_power, rot_power]() {
            m_mecanumdrive->DriveCartesian(
                drive_power(), strafe_power(), rot_power()
            );
        },
        [this]() { m_mecanumdrive->DriveCartesian(0.0, 0.0, 0.0); }
    );
}