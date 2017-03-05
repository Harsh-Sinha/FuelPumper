/*
 * Autonomous.h
 *
 *  Created on: Feb 13, 2017
 *      Author: Joey
 */
#include <RelativeMovement.h>
#include <WPILib.h>

#ifndef SRC_AUTONOMOUS_H_
#define SRC_AUTONOMOUS_H_
#include "TankDrive.h"
#include "BoilerVision.h"
#include "TrapezoidalMove.h"
using namespace cs;
using namespace grip;
class Autonomous {
	CameraServer *m_cameraServer = nullptr;
	cs::CvSource m_outputStream;
	cs::UsbCamera camera;
	grip::BoilerVision m_boilerVision;
	TankDrive &m_tank;
	Shooter &m_shooter;

	ChainCommands m_chain;
	RelativeMovement m_relMove;
	int m_state = 0;
	TrapezoidalMove m_move;
	Timer m_timer;
public:
	Autonomous(
		CameraServer *,
		CvSource &m_outputStream,
		UsbCamera &camera,
		TankDrive &m_tank,
		Shooter &shooter
	);
	virtual ~Autonomous();

	void AutonomousPeriodic();
	void AutonomousInit();
};

#endif /* SRC_AUTONOMOUS_H_ */
