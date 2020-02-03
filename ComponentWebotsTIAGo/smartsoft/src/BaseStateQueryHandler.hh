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
#ifndef _BASESTATEQUERYHANDLER_USER_HH
#define _BASESTATEQUERYHANDLER_USER_HH

#include "BaseStateQueryHandlerCore.hh"

class BaseStateQueryHandler : public BaseStateQueryHandlerCore
{
private:
  CommBasicObjects::CommTimeStamp timeStamp;
  CommBasicObjects::CommBaseVelocity baseVelocity;

public:
  BaseStateQueryHandler(IQueryServer *server);
  virtual ~BaseStateQueryHandler() = default;
  virtual void handleQuery(const QueryId &id, const CommBasicObjects::CommVoid& request);
};
#endif
