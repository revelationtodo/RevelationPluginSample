#include "IRevelationInterface.h"
#include "RevelationPluginSampleInterface.h"

DLL_EXPORT IExtensionInterface* ExtensionEntrance(IRevelationInterface* intf)
{
    return new RevelationPluginSampleInterface(intf);
}