//========== IV:Network - https://github.com/GTA-Network/IV-Network ============
//
// File: CPauseMenu.h
// Project: Client.Core
// Author: ViruZz <blazee14@gmail.com>
// License: See LICENSE in root directory
//
//==============================================================================

#ifndef CPauseMenu_h
#define CPauseMenu_h

#include <Common.h>
#include "CGUI.h"

class CPauseMenu
{
private:
	CGUI * m_pGUI;
	bool			  m_bVisible;
	bool			  m_bQuickConnectVisible;
	bool			  m_bSettingsVisible;

	// Main Menu Stuff
	CGUIStaticImage	* m_pBackground;
	CGUIStaticText	* m_pQuickConnectButton;
	CGUIStaticText  * m_pServerBrowserButton;
	CGUIStaticText  * m_pSettingsButton;
	CGUIStaticText  * m_pCreditsButton;
	CGUIStaticText  * m_pExitButton;
	CGUIStaticText	* CreateButton(char * szText, CEGUI::UVector2 vecSize, CEGUI::UVector2 vecPosition);

	// Quick Connect Stuff
	CGUIFrameWindow	* m_pQuickConnectWindow;
	CGUIStaticText	* m_pQuickConnectNicknameText;
	CGUIEditBox		* m_pQuickConnectNamenameEditBox;
	CGUIStaticText	* m_pQuickConnectIPStaticText;
	CGUIEditBox		* m_pQuickConnectIPEditBox;
	CGUIStaticText	* m_pQuickConnectPasswordStaticText;
	CGUIEditBox		* m_pQuickConnectPasswordEditBox;
	CGUIButton		* m_pQuickConnectConnectButton;

	// Settings Stuff
	CGUIFrameWindow * m_pSettingsWindow;
	CGUIStaticText  * m_pSettingsStaticText;
	CGUIEditBox     * m_pSettingsEditBox;
	CGUIButton      * m_pSettingsButtonEx;

	bool OnQuickConnectButtonMouseEnter(const CEGUI::EventArgs &eventArgs);
	bool OnQuickConnectButtonMouseExit(const CEGUI::EventArgs &eventArgs);
	bool OnQuickConnectButtonMouseClick(const CEGUI::EventArgs &eventArgs);
	bool OnServerBrowserButtonMouseEnter(const CEGUI::EventArgs &eventArgs);
	bool OnServerBrowserButtonMouseExit(const CEGUI::EventArgs &eventArgs);
	bool OnServerBrowserButtonMouseClick(const CEGUI::EventArgs &eventArgs);
	bool OnSettingsButtonMouseEnter(const CEGUI::EventArgs &eventArgs);
	bool OnSettingsButtonMouseExit(const CEGUI::EventArgs &eventArgs);
	bool OnCreditsButtonMouseEnter(const CEGUI::EventArgs &eventArgs);
	bool OnCreditsButtonMouseExit(const CEGUI::EventArgs &eventArgs);
	bool OnCreditsButtonMouseClick(const CEGUI::EventArgs &eventArgs);
	bool OnExitButtonMouseEnter(const CEGUI::EventArgs &eventArgs);
	bool OnExitButtonMouseExit(const CEGUI::EventArgs &eventArgs);
	bool OnExitButtonMouseClick(const CEGUI::EventArgs &eventArgs);
	bool OnQuickConnectCloseClick(const CEGUI::EventArgs &eventArgs);
	bool OnQuickConnectIPEditBoxKeyUp(const CEGUI::EventArgs &eventArgs);
	bool OnQuickConnectConnectButtonClick(const CEGUI::EventArgs &eventArgs);
	void OnQuickConnectSubmit();
	bool OnSettingsButtonMouseClick(const CEGUI::EventArgs &eventArgs);
	bool OnSettingsCloseClick(const CEGUI::EventArgs &eventArgs);
	bool OnSettingsEditBoxKeyUp(const CEGUI::EventArgs &eventArgs);
	void OnSettingsApply();
	bool OnSettingsMouseClick(const CEGUI::EventArgs &eventArgs);


public:
	CPauseMenu(CGUI * pGUI);
	~CPauseMenu();

	bool Initialize();

	void SetVisible(bool bVisible);
	void SetQuickConnectVisible(bool bVisible);
	void SetSettingsVisible(bool bVisible);
	bool IsPauseMenuVisible() { return m_bVisible; }

	static void OnExitButtonMouseClickConfirm(eGUIMessageBoxResponse type);
};

#endif