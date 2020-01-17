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
#ifndef _COMPONENTWEBOTSPIONEER3DXCORE_HH
#define _COMPONENTWEBOTSPIONEER3DXCORE_HH

#include "aceSmartSoft.hh"
#include <iostream>

class ComponentWebotsPioneer3DXCore
{
private:

public:
  ComponentWebotsPioneer3DXCore();
  SmartACE::SmartMutex PioneerMutex;
  double vX;
  double vY;
  double vW;
};

#endif
