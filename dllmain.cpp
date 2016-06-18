// dllmain.cpp : Defines the entry point for the DLL application.
#include <Windows.h>
#include "Structures.h"
#include "PatternScanner.h"

#define KEY_DOWN 0x100
#define KEY_UP 0x101
#define VK_LEFT 0x25
#define VK_RIGHT 0x27

#define WOOD 1
#define BOMB 2

DWORD WINAPI DLLStart(LPVOID param)
{
	//Get pointer that points to TMiniGameManager pointer
	TMiniGameManager* manager = **(TMiniGameManager***)(FindPattern((BYTE*)0x500000, 
					0x200000, 
					(BYTE*)("\xA1\x00\x00\x00\x00\x8B\x08\xFF\x51\x44\xA1\x00\x00\x00\x00\xE8\x00\x00\x00\x00\x33\xD2"), "x????xxxxxx????x????xx") + 1);

	MiniGame_1* game = manager->miniGame_1;

	//Check if the pointer to MiniGame_1 is correct
	if (IsBadReadPtr(game, sizeof(MiniGame_1)))
		return -1;

	//Get the paddles data
	BYTE* leftPaddleData = game->leftPaddle->data;
	BYTE* rightPaddleData = game->rightPaddle->data;

	//Get size of the area where we can hit
	//You can use it if you do randomize shots, not only the "perfect shots"
	//HitBox* hitbox = game->leftPaddle->hitBox;

	//Get the value when we should end our iterate:

	//Paddle hitbox area(the place where we can hit) has 110(game->leftPaddle->hitBox->first) bytes.
	//If the wood is between byte 40 and byte 70 we get the "Nice" result, and as a result, the "combo x"
	//Really the front of the paddle is at the back of memory, so at offset 397 is the start of the paddle, and at 287(387-110) is the end of paddle

	
	//int iterateTo = 397 - hitbox->first; - If you want to hit the wood extremally fast when it appear on the hitbox area
	
	//We iterate the last(really first) 70 bytes, because we don't want to lose wood, when it will be at the byte lower than 40, but we still prefer to get combo
	DWORD iterateTo = 397 - 70;

	//Find hwnd of NosTale window
	HWND hwnd = FindWindowA("TNosTaleMainF", "NosTale");

	while (true)
	{
		//Check if minigame is on
		if (game->m_bIsOn)
		{
			for (DWORD i = 397; i != iterateTo; --i)
			{
				if (leftPaddleData[i] == WOOD)
				{
					PostMessage(hwnd, KEY_DOWN, VK_LEFT, 0);
					PostMessage(hwnd, KEY_UP, VK_LEFT, 0);
					Sleep(2);
					break;
				}

				if (rightPaddleData[i] == WOOD)
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

