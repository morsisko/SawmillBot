#pragma once

//Generated using ReClass 2013 Mod by CypherPresents

class MiniGame_1;
class TimingShotGame;
class MiniGameManagerList;
class HitBox;

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
	char _0x0028[8];
	HitBox* hitBox; //0x0030 
	char _0x0034[24];
	MiniGame_1* miniGame; //0x004C 

};//Size=0x0050


class TMiniGameManager
{
public:
	char _0x0000[104];
	__int32 m_iCurrentMiniGame; //0x0068
	char _0x006C[4];
	void* miniGame_2; //0x0070 
	MiniGame_1* miniGame_1; //0x0074 
	void* miniGame_3; //0x0078 
	void* miniGame_4; //0x007C 
	void* miniGame_6; //0x0080 
	void* miniGame_5; //0x0084 

};//Size=0x0088

class HitBox
{
public:
	__int32 first; //0x0000 
	__int32 second; //0x0004 

};//Size=0x0008