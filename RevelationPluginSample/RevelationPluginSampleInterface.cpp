#include "RevelationPluginSampleInterface.h"
#include "ICommonWidgetInterface.h"
#include "FluDef.h"
#include "FluThemeUtils.h"
#include "FluSettingsVersionBox.h"

RevelationPluginSampleInterface::RevelationPluginSampleInterface(IRevelationInterface* intf)
    : m_interface(intf)
{
}

RevelationPluginSampleInterface::~RevelationPluginSampleInterface()
{
    delete m_label;
}

void RevelationPluginSampleInterface::Initialize()
{
}

void RevelationPluginSampleInterface::Uninitialize()
{
}

void RevelationPluginSampleInterface::HandleBroadcast(BroadcastType broadcastType, const std::any& param /* = std::any() */)
{
    if (broadcastType == BroadcastType::CollectNavigationView)
    {
        AddNavigationView();
    }
    else if (broadcastType == BroadcastType::CollectSettingsItem)
    {
        AddSettingsItem();
    }
    else if (broadcastType == BroadcastType::ChangeTheme)
    {
        FluTheme theme = std::any_cast<FluTheme>(param);
        FluThemeUtils::getUtils()->setTheme(theme);
    }
}

void RevelationPluginSampleInterface::AddNavigationView()
{
    auto commonWidgetIntf = m_interface->GetCommonWidgetInterface();
    if (nullptr != commonWidgetIntf)
    {
        m_label = new QLabel("Revelation Plugin Sample");
        commonWidgetIntf->AddStackedWidget(m_label, QObject::tr("Revelation Plugin Sample"), FluAwesomeType::Emoji, Qt::AlignCenter);
    }
}

void RevelationPluginSampleInterface::AddSettingsItem()
{
    auto        timeMachineItem = new FluSettingsVersionBox;
    timeMachineItem->getTitleLabel()->setText("RevelationPluginSample");
    timeMachineItem->getInfoLabel()->setText("This is a plugin setting sample.");
    timeMachineItem->getVersionLabel()->setText(QString::fromStdString("1.0.0"));

    QIcon icon = FluIconUtils::getFluentIcon(FluAwesomeType::Emoji);
    timeMachineItem->getIconLabel()->setPixmap(icon.pixmap(40, 40));
    timeMachineItem->getIconLabel()->setFixedSize(40, 40);

    m_interface->GetCommonWidgetInterface()->AddSettingsItem(timeMachineItem);
}
