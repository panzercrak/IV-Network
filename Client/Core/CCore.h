//================ IV:Multiplayer - https://github.com/IVMultiplayer/IVMultiplayer ================
//
// File: CCore.h
// Project: Client.Core
// Author: FRi<FRi.developing@gmail.com>
// License: See LICENSE in root directory
//
//==========================================================================================

#ifndef CCore_h
#define CCore_h

#include <Common.h>
#include <d3d9.h>

#include <CLogFile.h>
#include <CSettings.h>
#include <SharedUtility.h>
#include <Patcher/CPatcher.h>

#include <Game/eGame.h>
#include <IV/CIVScriptHook.h>

#include <Hooks/CXLive.h>

#include "Game/CGame.h"
#include "Graphics/CGraphics.h"
#include "Graphics/CChat.h"
#include "Game/COffsets.h"
#include "Game/CPatches.h"
#include "Game/CHooks.h"
#include "Graphics/CFPSCounter.h"

#include "Network/CLocalPlayer.h"
#include "Game/Entity/CPlayerEntity.h"
#include "Game/Entity/CNetworkEntity.h"


class CCore {
private:

	bool							m_bInitialised;
	bool							m_bGameLoaded;
	unsigned						m_uiBaseAddress;
	unsigned						m_uiLocalPlayerIndex;

	CGame							* m_pGame;
	CGraphics						* m_pGraphics;
	CChat							* m_pChat;
	CFPSCounter						* m_pFPSCounter;

	eGAMEStates						m_eGameState;
public:

									CCore();
									~CCore();

	bool							Initialise();

	void							OnGameLoad();
	void							OnGamePreLoad();

	void							OnGameProcess();

	void							SetGameLoaded(bool bLoaded) { m_bGameLoaded = bLoaded; }
	bool							IsGameLoaded() { return m_bGameLoaded; }

	void							OnDeviceCreate(IDirect3DDevice9 * pDevice, D3DPRESENT_PARAMETERS * pPresentationParameters);
	void							OnDeviceLost(IDirect3DDevice9 * pDevice);
	void							OnDeviceReset(IDirect3DDevice9 * pDevice);
	void							OnDevicePreRender();
	void							OnDeviceRender(IDirect3DDevice9 * pDevice);

	unsigned						GetBase() { return m_uiBaseAddress; }
	unsigned						GetBaseAddress() { return m_uiBaseAddress; }

	CGame							* GetGame() { return m_pGame; }
	CGraphics						* GetGraphics() { return m_pGraphics; }
	CChat							* GetChat() { return m_pChat; }
	CFPSCounter						* GetFPSCounter() { return m_pFPSCounter; }

	void							SetClientState(eGAMEStates pState) { m_eGameState = pState; }
	eGAMEStates						GetClientState() { return m_eGameState; }

	void							SetLocalPlayerIndex(unsigned iIndex) { m_uiLocalPlayerIndex = iIndex; }
	unsigned						GetLocalPlayerIndex() { return m_uiLocalPlayerIndex; }
};

#endif // CCore_h