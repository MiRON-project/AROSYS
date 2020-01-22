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
#include "BaseStateQueryHandler.hh"
#include "ComponentWebotsPioneer3DX.hh"

BaseStateQueryHandler::BaseStateQueryHandler(IQueryServer *server)
:	BaseStateQueryHandlerCore(server)
{
  
}


void BaseStateQueryHandler::handleQuery(const Smart::QueryIdPtr &id, const CommBasicObjects::CommVoid& request)
{

	CommBasicObjects::CommBaseState answer;

	// implement your query handling logic here and fill in the answer object

	this->server->answer(id, answer);


	/*
	CommBasicObjects::CommBaseState base_state;


	std::cout << "Query for basestate \n";

	// acquisition
	COMP->PioneerMutex.acquire();

	//COMP->robot->ReadIfWaiting();
	webotsGPS->getValues()
	base_position.set_x(webotsGPS->getValues(0), 1.0); // in m
	base_position.set_y(webotsGPS->getValues(1), 1.0); // in m
	base_position.set_z(webotsGPS->getValues(2), 1.0); // in m
	//base_position.set_base_azimuth(webotsInertialUnit->getRollPitchYaw(2)); // in rad
	//base_position.set_base_elevation(webotsInertialUnit->getRollPitchYaw(0)); // in rad
	base_velocity.set_vX(webotsGPS->getSpeed() * 100.0); // in cm/s

	//double yawSpeed;
	//yawSpeed = COMP->position_2d_proxy->GetYawSpeed();
	//base_velocity.set_WX_base(yawSpeed);

	// release
	COMP->PioneerMutex.release();

	base_state.set_base_position(base_position);
	base_state.set_base_velocity(base_velocity);

	//base_state.set_base_raw_position(COMP->rawPos); // TODO: check!

	this->server->answer(id, base_state);
	*/
}
