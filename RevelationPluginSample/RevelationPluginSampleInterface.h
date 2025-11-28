#include "IExtensionInterface.h"
#include "IRevelationInterface.h"
#include <QLabel>

class RevelationPluginSampleInterface : public IExtensionInterface
{
  public:
    RevelationPluginSampleInterface(IRevelationInterface* intf);
    ~RevelationPluginSampleInterface();

    virtual void Initialize() override;
    virtual void Uninitialize() override;

    virtual void HandleBroadcast(BroadcastType broadcastType, const std::any& param /* = std::any() */) override;

  private:
    void AddNavigationView();
    void AddSettingsItem();

  private:
    IRevelationInterface* m_interface = nullptr;

    QLabel* m_label = nullptr;
};