// dllmain.cpp : Defines the entry point for the DLL application.
#include <Windows.h>
#include "Structures.h"
#include "PatternScanner.h"
#include <random>

#define KEY_DOWN 0x100
#define KEY_UP 0x101
#define VK_LEFT 0x25
#define VK_RIGHT 0x27

#define WOOD 1
#define BOMB 2
DWORD WINAPI DLLStart(LPVOID param)
{
	TMiniGameManager* manager = **(TMiniGameManager***)(FindPattern((BYTE*)0x500000, 0x200000, (BYTE*)("\xA1\x00\x00\x00\x00\x8B\x08\xFF\x51\x44\xA1\x00\x00\x00\x00\xE8\x00\x00\x00\x00\x33\xD2"), "x????xxxxxx????x????xx") + 1);
	MiniGame_1* game = manager->miniGameManagerList->getMiniGame();

	if (IsBadReadPtr(game, sizeof(game)))
		return -1;

	void* leftPaddleData = game->leftPaddle->data;
	void* rightPaddleData = game->rightPaddle->data;

	HWND hwnd = FindWindowA("TNosTaleMainF", "NosTale");

	while (true)
	{
		if (game->m_bIsOn)
		{

			for (int i = 397; i != 327; --i)
			{
				if (*(BYTE*)((DWORD)leftPaddleData + (DWORD)i) == WOOD)
				{
					PostMessage(hwnd, KEY_DOWN, VK_LEFT, 0);
					PostMessage(hwnd, KEY_UP, VK_LEFT, 0);
					Sleep(2);
					break;
				}

				if (*(BYTE*)((DWORD)rightPaddleData + (DWORD)i) == WOOD)
				{
					PostMessage(hwnd, KEY_DOWN, VK_RIGHT, 0);
					PostMessage(hwnd, KEY_UP, VK_RIGHT, 0);
					Sleep(2);
					break;
				}
			}
		}

		Sleep(1);
	}

	
	return 0;
}

BOOL APIENTRY DllMain( HMODULE hModule,
                       DWORD  ul_reason_for_call,
                       LPVOID lpReserved
					 )
{
	switch (ul_reason_for_call)
	{
	case DLL_PROCESS_ATTACH:
		CreateThread(0, 0, DLLStart, 0, 0, 0);
	case DLL_THREAD_ATTACH:
	case DLL_THREAD_DETACH:
	case DLL_PROCESS_DETACH:
		break;
	}
	return TRUE;
}

