
#include "CMainMenu.h"
#include <CCore.h>


extern CCore* g_pCore;

CMainMenu::CMainMenu(CGUI* pGUI)
: m_pGUI(pGUI)
{

}

CMainMenu::~CMainMenu()
{
}


bool CMainMenu::OnQuickConnectButtonMouseClick(const CEGUI::EventArgs &eventArgs)
{
	g_pCore->ConnectToServer();
	m_pWindow->setVisible(false);
	return true;
}

bool CMainMenu::Initialize()
{

	try
	{
		CEGUI::ImagesetManager::getSingleton().createFromImageFile("Background", "Background.png");
	}
	catch (CEGUI::InvalidRequestException e)
	{
		MessageBox(NULL, "Failed to load Main Menu Background", "IV:Network Error", MB_OK || MB_ICONERROR);
		TerminateProcess(GetCurrentProcess, 0);
	}
	catch (CEGUI::Exception e)
	{
		MessageBox(NULL, "IV:Network failed to load, please check the CEGUI.log for more details", "IV:Network Error", MB_OK || MB_ICONERROR);
		TerminateProcess(GetCurrentProcess, 0);
	}

	m_pWindow = m_pGUI->GetWindowManager()->createWindow(STYLE_PREFIX "/FrameWindow", "Keks");
	if (m_pWindow)
	{
		CEGUI::Window * pParent = m_pGUI->GetDefaultWindow();
		pParent->addChildWindow(m_pWindow);
		m_pWindow->setSize(CEGUI::UVector2(CEGUI::UDim(0, 100), CEGUI::UDim(0, 100)));
		m_pWindow->setPosition(CEGUI::UVector2(CEGUI::UDim(0, 100), CEGUI::UDim(0, 100)));
	}

	CEGUI::Window* pQuickConnect = m_pGUI->GetWindowManager()->createWindow(STYLE_PREFIX "/Button", "KeksButton");
	if (pQuickConnect)
	{
		pQuickConnect->setSize(CEGUI::UVector2(CEGUI::UDim(0, 50), CEGUI::UDim(0, 50)));
		pQuickConnect->setPosition(CEGUI::UVector2(CEGUI::UDim(0, 50), CEGUI::UDim(0, 50)));
		//pQuickConnect->subscribeEvent(CEGUI::Window::EventMouseEnters, CEGUI::Event::Subscriber(&CMainMenu::OnQuickConnectButtonMouseEnter, this));
		//pQuickConnect->subscribeEvent(CEGUI::Window::EventMouseLeaves, CEGUI::Event::Subscriber(&CMainMenu::OnQuickConnectButtonMouseLeave, this));
		pQuickConnect->subscribeEvent(CEGUI::Window::EventMouseClick, CEGUI::Event::Subscriber(&CMainMenu::OnQuickConnectButtonMouseClick, this));
		m_pWindow->addChildWindow(pQuickConnect);
	}

	SetVisible(true);

	return true;
}

void CMainMenu::SetVisible(bool bVisible)
{
	m_bVisible = bVisible;

	g_pCore->GetGUI()->SetCursorVisible(bVisible);
}