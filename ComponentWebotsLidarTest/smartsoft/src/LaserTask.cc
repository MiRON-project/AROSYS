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
#include "LaserTask.hh"
#include "ComponentWebotsLidarTest.hh"

#include <iostream>


LaserTask::LaserTask(SmartACE::SmartComponent *comp) 
:	LaserTaskCore(comp)
{
	std::cout << "constructor LaserTask\n";
}
LaserTask::~LaserTask() 
{
	std::cout << "destructor LaserTask\n";
}



int LaserTask::on_entry()
{
	// do initialization procedures here, which are called once, each time the task is started
	// it is possible to return != 0 (e.g. when initialization fails) then the task is not executed further

	// create Robot Instance
	robot = new webots::Robot();

	// set Lidar
	lidar=robot->getLidar("Sick LMS 291");
	lidar->enable(TIME_STEP);
	lidar->enablePointCloud();

	// Set Webots Lidar properties to CommMobileLaserScan Domain Model
	std::cout << "LaserTask 2" << std::endl;

	// --- Properties
	// --- doc: servicerobotik-ulm.de/drupal/doxygen/components_commrep/classCommBasicObjects_1_1CommMobileLaserScan.html
	scan.set_scan_integer_field_of_view(27000, 18000); //  -50*180, 50
	scan.set_min_distance(lidar->getMinRange()*1000.0); // in mm
	scan.set_max_distance(lidar->getMaxRange()*1000.0); // in mm
	scan.set_scan_length_unit(0.001); // unit = mm, for meter use 1.0
	std::cout << "LaserTask 3" << std::endl;

	// --- Points
	unsigned int num_valid_points = lidar->getNumberOfPoints();
	scan.set_scan_size(num_valid_points);

	return 0;
}


int LaserTask::on_execute()
{
	// this method is called from an outside loop,
	// hence, NEVER use an infinite loop (like "while(1)") here inside!!!
	// also do not use blocking calls which do not result from smartsoft kernel
	
	std::cout << "Hello from LaserTask TEST" << std::endl;

    //Controller Code that is in "while loop" if run from Simulator should be inside "if statement" below,
    //otherwise the values will not be updated
	if (robot->step(TIME_STEP) != -1) {
		// --- Time settings
		timeval _receive_time;
		gettimeofday(&_receive_time, 0);
		scan.set_scan_time_stamp  (CommBasicObjects::CommTimeStamp(_receive_time));

		scan.set_scan_update_count(scan_count);

		// Get Lidar value using the DomainModel
		// --- Points
		unsigned int num_valid_points = lidar->getNumberOfPoints();
		scan.set_scan_size(num_valid_points);
		scan.set_scan_update_count(scan_count);
		std::cout << "LaserTask TEST 4" << std::endl;

		// Create an array of Lidar's values
		const float *rangeImageVector;
		rangeImageVector = (const float *)(void *)lidar->getRangeImage(); // in m
		std::cout << "LaserTask TEST 5" << std::endl;

		// Pass Lidar's values to CommMobileLaserScan
		for(unsigned int i=0; i<num_valid_points; ++i)
		{
			const unsigned int dist = (unsigned int)(rangeImageVector[i]*1000.0); // in mm

			scan.set_scan_index(i, i);
			scan.set_scan_integer_distance(i, dist); // in mm
			std::cout << "LID["<< i << "] dist: " << scan.get_scan_distance(i) << std::endl;
		}
		std::cout << "LaserTask TEST 6" << std::endl;
		scan.set_scan_valid(true);

	}

	// Send LaserScan out
    laserServiceOutPut(scan);
    ++scan_count;
    scan.set_scan_valid(false);


//    if (COMP->getGlobalState().getServices().getActivate_push_newest()) {
//		Smart::StatusCode push_status = COMP->laserPushNewestServer->put(scan);
//		if (push_status != Smart::SMART_OK) {
//			std::cerr << "[Laser Task] WARNING: error on push (" << Smart::StatusCodeConversion(push_status)
//					<< ")" << std::endl;
//		}
//	}

	// it is possible to return != 0 (e.g. when the task detects errors), then the outer loop breaks and the task stops
	return 0;
}


int LaserTask::on_exit()
{
	delete robot;

	// use this method to clean-up resources which are initialized in on_entry() and needs to be freed before the on_execute() can be called again
	return 0;
}
