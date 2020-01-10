//--------------------------------------------------------------------------
// Code generated by the SmartSoft MDSD Toolchain
// The SmartSoft Toolchain has been developed by:
//
// Service Robotics Research Center
// University of Applied Sciences Ulm
// Prittwitzstr. 10
// 89075 Ulm (Germany)
//
// Information about the SmartSoft MDSD Toolchain is available at:
// www.servicerobotik-ulm.de
//
// This file is generated once. Modify this file to your needs.
// If you want the toolchain to re-generate this file, please
// delete it before running the code generator.
//--------------------------------------------------------------------------
#include "RobotTask.hh"
#include "ComponentLaserObstacleAvoidTest.hh"
#include "AvoidanceAlgo.hh"
#include <iostream>

RobotTask::RobotTask(SmartACE::SmartComponent *comp)
:	RobotTaskCore(comp)
{
	std::cout << "constructor RobotTask\n";
}
RobotTask::~RobotTask()
{
	std::cout << "destructor RobotTask\n";
}


void RobotTask::on_LaserServiceIn(const CommBasicObjects::CommMobileLaserScan &input)
{
	std::cout << "LASER IN EVENT: " << input.get_scan_distance(0) << std::endl;
	// upcall triggered from InputPort LaserServiceIn
	// - use a local mutex here, because this upcal is called asynchroneously from outside of this task
	// - do not use longer blocking calls here since this upcall blocks the InputPort LaserServiceIn
	// - if you need to implement a long-running procedure, do so within the on_execute() method and in
	//   there, use the method laserServiceInGetUpdate(input) to get a copy of the input object
}

int RobotTask::on_entry()
{
	// do initialization procedures here, which are called once, each time the task is started
	// it is possible to return != 0 (e.g. when initialization fails) then the task is not executed further
	return 0;
}

int RobotTask::on_execute()
{
	// this method is called from an outside loop,
	// hence, NEVER use an infinite loop (like "while(1)") here inside!!!
	// also do not use blocking calls which do not result from smartsoft kernel

	Smart::StatusCode status;

	/////////////////////////////////////////////
	// to get the incoming data, use this methods:

	// get laser scan:
	status = COMP->laserServiceIn->getUpdateWait(laserScan);

	// Check if the transmission worked
	if (status != Smart::SMART_OK)
	{
		std::cout << "Error receiving laserScan: " << status << std::endl;
			if(status == Smart::SMART_UNSUBSCRIBED)
			{
				std::cout << "laserClient is unsubscribed -> try to subscribe again" << std::endl;
				status = COMP->laserServiceIn->subscribe();
				std::cout << "laserClient subscription returned with " << status << std::endl;
			}
			sleep(1);
	}
	else
		std::cout << "LaserScan received" << std::endl;



	std::cout << "Hello from RobotTask TEST" << std::endl;

	//////////////////////////////////////////////
	// Do something with laserScan to get v and w
	double velocity = 0.0;
	double turnrate = 0.0;
	AvoidanceAlgo::run_cycle(laserScan, velocity, turnrate);

/*
	// TEST => Worked
		updateCounter++;
		uint count = laserScan.get_scan_size();
		for (uint j=0; j < count; ++j) {
			if (laserScan.get_scan_distance(j) > 0.0)
			std::cout << "2OBS["<< j << "] dist: " << laserScan.get_scan_distance(j) << std::endl;
		}

		// Calculate v and w
	// END TEST

//////////////////////////////////////////////
// Provide v and w to the service port

// Check the speed limits
// threshold speed:
//if(velocity >  500) {velocity= 500; up = false;}  // { ,...} useless, just for test
//if(velocity < -500) {velocity=-500; up = true;}
//if(turnrate >  20)  {turnrate= 20;  up = false;}
//if(turnrate < -20)  {turnrate=-20;  up = true;}

if (up){  // useless, just for test
	if (velocity>500) {
		velocity= 500;
		up = false;
	}
	else if (turnrate>20) {
		turnrate= 20;
		up = false;
	}
	else{
		velocity +=10;
		turnrate +=0.01;
	}
}
else{  // useless, just for test
	if (velocity<-500) {
		velocity=-500;
		up = true;
	}
	else if (turnrate<-20) {
		turnrate=-20;
		up = true;
	}
	else{
		velocity -=10;
		turnrate -=0.01;
	}
}
*/

	// TODO: Remove the following 2 lines. Used to check lidar's value
	//velocity = 0.0;
	//turnrate = 0.0;


	// Create and fill the communication object
	CommBasicObjects::CommNavigationVelocity navigationVelocity;
	navigationVelocity.set_vX(velocity, 0.001);
	navigationVelocity.set_omega(turnrate);

	std::cout << "1_Velocity : " << velocity << std::endl;
	std::cout << "1_Turnrate : " << turnrate << std::endl;

	// Provide result to output port, thereby command the robot:
	status = this->navigationVelocityServiceOutPut(navigationVelocity);

	// Check if the transmission worked
	if(status != Smart::SMART_OK) {
		std::cerr << status << std::endl;
		std::cout << "Error providing navigation velocity: " << status << std::endl;
		sleep(1);
	}
	else {
		std::cout << "Sent navigation velocity " << navigationVelocity << std::endl;
	}


	// it is possible to return != 0 (e.g. when the task detects errors), then the outer loop breaks and the task stops
	return 0;
}
int RobotTask::on_exit()
{
	// use this method to clean-up resources which are initialized in on_entry() and needs to be freed before the on_execute() can be called again
	return 0;
}
