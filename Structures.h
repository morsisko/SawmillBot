#pragma once

//Generated using ReClass 2013 Mod by CypherPresents

class MiniGame_1;
class TimingShotGame;
class MiniGameManagerList;

class MiniGame_1
{
public:
	char _0x0000[1439];
	__int8 m_bIsOn; //0x059F 
	char _0x05A0[1052];
	TimingShotGame* leftPaddle; //0x09BC 
	TimingShotGame* rightPaddle; //0x09C0 
	__int8 m_bHp; //0x09C4 
	char _0x09C5[3];
	__int32 m_iPoints; //0x09C8 
	__int8 m_bCombo; //0x09CC 
	char _0x09CD[51];

};//Size=0x0A00

class TimingShotGame
{
public:
	char _0x0000[36];
	void* data; //0x0024 
	char _0x0028[36];
	MiniGame_1* miniGame; //0x004C 

};//Size=0x0050

class MiniGameManagerList
{
private:
	void* basePointer; //0x0000
	MiniGame_1** pointerToArray; //0x0004
	int currentSize; //0x0008
	int paddle[2];

public:

	MiniGame_1* getMiniGame()
	{
		if (currentSize <= 6)
			return nullptr;
		else
			return pointerToArray[6];
	}

};//Size=0x0014

class TMiniGameManager
{
public:
	char _0x0000[32];
	MiniGameManagerList* miniGameManagerList; //0x0020 

};//Size=0x0024