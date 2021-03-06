/************************************************************************************

	AstroMenace
	Hardcore 3D space scroll-shooter with spaceship upgrade possibilities.
	Copyright (c) 2006-2018 Mikhail Kurinnoi, Viewizard


	AstroMenace is free software: you can redistribute it and/or modify
	it under the terms of the GNU General Public License as published by
	the Free Software Foundation, either version 3 of the License, or
	(at your option) any later version.

	AstroMenace is distributed in the hope that it will be useful,
	but WITHOUT ANY WARRANTY; without even the implied warranty of
	MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
	GNU General Public License for more details.

	You should have received a copy of the GNU General Public License
	along with AstroMenace. If not, see <http://www.gnu.org/licenses/>.


	Web Site: http://www.viewizard.com/
	Project: https://github.com/viewizard/astromenace
	E-mail: viewizard@viewizard.com

*************************************************************************************/

// FIXME this is really wrong, all this mess should be sorted to headers

#ifndef GAME_H
#define GAME_H

#include "core/core.h"
#include "struct.h"
#include "config.h"

class cSpaceStars;
class cScriptEngine;
class cEarthSpaceFighter;



//------------------------------------------------------------------------------------
// Main.cpp
//------------------------------------------------------------------------------------
extern sGameSetup Setup;
extern eMenuStatus MenuStatus;
extern SDL_Joystick *Joystick;
extern sVECTOR3D GamePoint;
extern sVECTOR3D GameCameraMovement;

extern sVideoModes *VideoModes;
extern int VideoModesNum;
extern sVideoModes CurrentVideoMode;

extern bool LoadedTypes[1000];
extern std::string ConfigFileName;
extern char ProgrammDir[MAX_PATH];
extern char ScreenshotDir[MAX_PATH];
extern char UserPath[MAX_PATH];
extern bool Quit;
extern bool CanQuit;
extern bool NeedReCreate;
extern bool SDL_MouseCurrentStatus[8];
extern int JoystickAxisX;
extern int JoystickAxisY;
extern bool JoysticButtons[100];

void SaveGameData();
void CodeXOR(char *Text, char *Key, int Count);


struct sFontList {
	const char *FontTitle;
	const char *FontFileName;
};

constexpr int FontQuantity = 8;
const sFontList FontList[FontQuantity] = {
	{"Linux Biolinum", "font/LinBiolinumBold.ttf"},
	{"Linux Libertine", "font/LinLibertineBold.ttf"},
	{"Liberation Mono", "font/LiberationMono-Bold.ttf"},
	{"Liberation Sans", "font/LiberationSans-Bold.ttf"},
	{"Liberation Serif", "font/LiberationSerif-Bold.ttf"},
	{"FreeFont Mono", "font/FreeMonoBold.ttf"},
	{"FreeFont Sans", "font/FreeSansBold.ttf"},
	{"FreeFont Serif", "font/FreeSerifBold.ttf"},
};




//------------------------------------------------------------------------------------
// MainFS2VFS.cpp
//------------------------------------------------------------------------------------
int ConvertFS2VFS(const std::string RawDataDir, const std::string VFSFileNamePath);




//------------------------------------------------------------------------------------
// Setup.cpp
//------------------------------------------------------------------------------------
bool LoadXMLSetupFile(bool NeedSafeMode);
void SaveXMLSetupFile();






//------------------------------------------------------------------------------------
// loop_proc.cpp
//------------------------------------------------------------------------------------
extern cScriptEngine *Script;

extern eCommand ComBuffer;
extern int CurrentCursorStatus;
extern bool DrawGameCursor;

void Loop_Proc();








//------------------------------------------------------------------------------------
// loop_audio.cpp
//------------------------------------------------------------------------------------
unsigned int Audio_PlaySound2D(unsigned int SoundID, float LocalVolume);
unsigned int Audio_PlayVoice(unsigned int VoiceID, float LocalVolume);
void Audio_LoopProc();
void StartMusicWithFade(eMusicTheme StartMusic, uint32_t FadeInTicks, uint32_t FadeOutTicks);
void Audio_SetSound2DGlobalVolume(float NewGlobalVolume);
void Audio_SetVoiceGlobalVolume(float NewGlobalVolume);




//------------------------------------------------------------------------------------
// loading.cpp
//------------------------------------------------------------------------------------
void LoadGameData(eLoading LoadType);






//------------------------------------------------------------------------------------
// Camera.cpp, GameCamera.cpp, CameraMath.cpp
//------------------------------------------------------------------------------------
void GameCameraUpdate(float Time);
void InitGameCamera();
void ResetGameCamera();
float GameCameraGetDeviation();
float GameCameraGetSpeed();
void GameCameraSetExplosion(sVECTOR3D Location, float Power);











//------------------------------------------------------------------------------------
// Button.cpp
//------------------------------------------------------------------------------------
extern int CurrentActiveMenuElement;
extern int CurrentKeyboardSelectMenuElement;

bool DrawButton384(int X, int Y, const char *Text, float Transp, float *ButTransp, float *Update);
bool DrawButton256(int X, int Y, const char *Text, float Transp, float *ButTransp, float *Update, bool Off=false);
bool DrawButton128_2(int X, int Y, const char *Text, float Transp, bool Off, bool SoundClick = true);
bool DrawButton200_2(int X, int Y, const char *Text, float Transp, bool Off);
void DrawCheckBox(int X, int Y, bool *CheckBoxStatus, const char *Text, float Transp);
bool DrawListUpButton(int X, int Y, float Transp, bool Off);
bool DrawListDownButton(int X, int Y, float Transp, bool Off);







//------------------------------------------------------------------------------------
// Menu.cpp
//------------------------------------------------------------------------------------
extern float Button1Transp;
extern float LastButton1UpdateTime;
extern float Button2Transp;
extern float LastButton2UpdateTime;
extern float Button3Transp;
extern float LastButton3UpdateTime;
extern float Button4Transp;
extern float LastButton4UpdateTime;
extern float Button5Transp;
extern float LastButton5UpdateTime;
extern float Button6Transp;
extern float LastButton6UpdateTime;
extern float Button7Transp;
extern float LastButton7UpdateTime;
extern float Button8Transp;
extern float LastButton8UpdateTime;
extern float Button9Transp;
extern float LastButton9UpdateTime;
extern float Button10Transp;
extern float LastButton10UpdateTime;
extern float Button11Transp;
extern float LastButton11UpdateTime;
extern float Button12Transp;
extern float LastButton12UpdateTime;
extern float Button13Transp;
extern float LastButton13UpdateTime;
extern float Button14Transp;
extern float LastButton14UpdateTime;
extern float MenuContentTransp;
extern float LastMenuOnOffUpdateTime;

void InitMenu();
void SetOptionsMenu(eMenuStatus Menu);
void SetMenu(eMenuStatus Menu);
void DrawMenu();
void MainMenu();










//------------------------------------------------------------------------------------
// Menu_Credits.cpp
//------------------------------------------------------------------------------------
void InitCreditsMenu(float Time);
void CreditsMenu();









//------------------------------------------------------------------------------------
// Menu_Options.cpp
//------------------------------------------------------------------------------------
extern int Options_Width;
extern int Options_Height;
extern int Options_BPP;
extern int Options_VSync;
extern int Options_iAspectRatioWidth;

void OptionsMenu(float ContentTransp, float *ButtonTransp1, float *LastButtonUpdateTime1, float *ButtonTransp2, float *LastButtonUpdateTime2);
void SaveOptionsMenuTmpData();








//------------------------------------------------------------------------------------
// Menu_ConfControl.cpp
//------------------------------------------------------------------------------------
extern int NeedCheck;
extern int ButQuant;
extern float But[10];

void ConfControlMenu(float ContentTransp, float *ButtonTransp1, float *LastButtonUpdateTime1);
const char * MouseCodeName(char Num);
const char * JoystickCodeName(int Num);
void CheckMouseKeybJState();









//------------------------------------------------------------------------------------
// Menu_Interface.cpp
//------------------------------------------------------------------------------------
void InterfaceMenu(float ContentTransp, float *ButtonTransp1, float *LastButtonUpdateTime1);







//------------------------------------------------------------------------------------
// Menu_OptionsAdvMenu.cpp
//------------------------------------------------------------------------------------
extern int Options_TexturesAnisotropyLevel;
extern int Options_TexturesCompressionType;
extern int Options_UseGLSL120;
extern int Options_MSAA;
extern int Options_CSAA;
extern int Options_ShadowMap;
extern int Options_TexturesQuality;

void OptionsAdvMenu(float ContentTransp, float *ButtonTransp1, float *LastButtonUpdateTime1, float *ButtonTransp2, float *LastButtonUpdateTime2);
void SaveOptionsAdvMenuTmpData();







//------------------------------------------------------------------------------------
// Menu_Profile.cpp
//------------------------------------------------------------------------------------
extern int CurrentProfile;
extern std::u32string NewProfileName;

void ProfileMenu();
void DeleteRecord();








//------------------------------------------------------------------------------------
// Menu_Information.cpp
//------------------------------------------------------------------------------------
extern int CreateNum;

void InformationMenu();
void InformationDrawObject();
void CreateInfoObject();
void DestroyInfoObject();









//------------------------------------------------------------------------------------
// Menu_TopScores.cpp
//------------------------------------------------------------------------------------
extern char GameName[10][PROFILE_NAME_SIZE];
extern int GameScore[10];

void TopScoresMenu();
void AddTopScores(int Score, char Name[PROFILE_NAME_SIZE], bool Type);








//------------------------------------------------------------------------------------
// Menu_Difficulty.cpp
//------------------------------------------------------------------------------------
void DifficultyMenu();







//------------------------------------------------------------------------------------
// Menu_Mission.cpp
//------------------------------------------------------------------------------------
extern int CurrentMission;
extern int AllMission;
extern int StartMission;
extern int EndMission;

void MissionMenu();
char *GetMissionFileName();
void MissionsListRelease();
void MissionsListInit();








//------------------------------------------------------------------------------------
// Menu_Workshop.cpp
//------------------------------------------------------------------------------------
extern int CurrentWorkshop;
extern int NewWeaponControlType;
extern int NewWeaponControlTypeData;
extern unsigned int VoiceNeedMoreEnergy;
extern unsigned int VoiceAmmoOut;

void WorkshopMenu();
void WorkshopCreate();
void WorkshopDestroyData();
const char *GetWeaponIconName(int Num);










//------------------------------------------------------------------------------------
// game.cpp
//------------------------------------------------------------------------------------
extern cEarthSpaceFighter *PlayerFighter;

extern int GameNPCWeaponPenalty;
extern int GameNPCArmorPenalty;
extern int GameNPCTargetingSpeedPenalty;
extern int GameLimitedAmmo;
extern int GameDestroyableWeapon;
extern int GameWeaponTargetingMode;
extern int GameSpaceShipControlMode;
extern int GameEngineSystem;
extern int GameTargetingSystem;
extern int GameAdvancedProtectionSystem;
extern int GamePowerSystem;
extern int GameTargetingMechanicSystem;
extern eGameMenuStatus GameMenuStatus;
extern float GameContentTransp;
extern float GameButton1Transp;
extern float LastGameButton1UpdateTime;
extern bool NeedShowGameMenu;
extern bool NeedHideGameMenu;
extern bool GameMissionCompleteStatus;

void InitGame();
void DrawGame();
void ExitGame();
void ExitGameWithSave();
void SetGameMissionComplete();









//------------------------------------------------------------------------------------
// Dialog.cpp
//------------------------------------------------------------------------------------
void InitDialogBoxes();
void SetCurrentDialogBox(eDialogBox DialogBox);
bool isDialogBoxDrawing();
void DrawDialogBox();









//------------------------------------------------------------------------------------
// Game_Mission.cpp
//------------------------------------------------------------------------------------
void GameSetMissionTitleData(float ShowTime, int Num);
void GameDrawMissionTitle();
void GameSetMissionFailedData(float ShowTime);
void GameDrawMissionFailed();








//------------------------------------------------------------------------------------
// Game_WeaponSlot.cpp
//------------------------------------------------------------------------------------
void DrawGameWeaponSlots();












#endif // GAME_H
