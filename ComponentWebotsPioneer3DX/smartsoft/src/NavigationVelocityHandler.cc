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
#include "NavigationVelocityHandler.hh"
#include "ComponentWebotsPioneer3DX.hh"

#include <iostream>

NavigationVelocityHandler::NavigationVelocityHandler(Smart::InputSubject<CommBasicObjects::CommNavigationVelocity> *subject, const int &prescaleFactor)
:	NavigationVelocityHandlerCore(subject, prescaleFactor)
{
  std::cout << "constructor NavigationVelocityHandler\n";
}
NavigationVelocityHandler::~NavigationVelocityHandler()
{
  std::cout << "destructor NavigationVelocityHandler\n";
}


void NavigationVelocityHandler::on_NavigationVelocityServiceIn(const CommBasicObjects::CommNavigationVelocity &input)
{
  // implement business logic here
  // (do not use blocking calls here, otherwise this might block the InputPort NavigationVelocityServiceIn)

  // print output
  //std::cout << "Velocity - input = " << input     << std::endl;
  //std::cout << " => vX = "    << input.get_vX(1.0)   << std::endl;
  //std::cout << " => vY = "    << input.get_vY(1.0)   << std::endl;
  //std::cout << " => omega = " << input.getOmega() << std::endl;

  // get from the port and pass to ComponentPioneer3DXCore to be accessible
  COMP->PioneerMutex.acquire();

  COMP->vX = input.get_vX(1.0);
  COMP->vY = input.get_vY(1.0);
  COMP->vW = input.get_omega();

  COMP->PioneerMutex.release();
}
