#pragma once

#define IGameEngineHostCreateBarrierDefinition(index) virtual void Function##index() final; 

void IGameEngineHostEmptyFunction();

#pragma pack(push, 1)

struct s_session_membership;
struct s_session_info_part;

enum IGameEngineHostVirtualFunctionIndex
{
	__game_engine_virtual_function_frame_start,
	__game_engine_virtual_function_frame_end,
	__game_engine_virtual_function_function2,
	__game_engine_virtual_function_engine_state_update,
	__game_engine_virtual_function_game_exited,
	__game_engine_virtual_function_save_game_state,
	__game_engine_virtual_function_submit_game_results,
	__game_engine_virtual_function_function7,
	__game_engine_virtual_function_function8,
	__game_engine_virtual_function_function9,
	__game_engine_virtual_function_get_game_events,
	__game_engine_virtual_function_save_game_variant,
	__game_engine_virtual_function_save_map_variant,
	__game_engine_virtual_function_function13,
	__game_engine_virtual_function_function14,
	__game_engine_virtual_function_function15,
	__game_engine_virtual_function_get_next_level_info,
	__game_engine_virtual_function_function17,
	__game_engine_virtual_function_function18,
	__game_engine_virtual_function_map_load_percent_status,
	__game_engine_virtual_function_function20,
	__game_engine_virtual_function_get_machine_identifier,
	__game_engine_virtual_function_function22,
	__game_engine_virtual_function_function23,
	__game_engine_virtual_function_get_session_info,
	__game_engine_virtual_function_membership_update,
	__game_engine_virtual_function_function26,
	__game_engine_virtual_function_function27,
	__game_engine_virtual_function_update_graphics,
	__game_engine_virtual_function_get_player_configuration,
	__game_engine_virtual_function_update_player_configuration,
	__game_engine_virtual_function_update_input,
	__game_engine_virtual_function_function32,
	__game_engine_virtual_function_function33,
	__game_engine_virtual_function_xinput_set_state,
	__game_engine_virtual_function_update_player_names,
	__game_engine_virtual_function_function36,
	__game_engine_virtual_function_function37,
	__game_engine_virtual_function_network_send_to,
	__game_engine_virtual_function_network_recieve_from,
	__game_engine_virtual_function_function40,
	__game_engine_virtual_function_function41,
	__game_engine_virtual_function_function42,
	__game_engine_virtual_function_firefight_new,
	__game_engine_virtual_function_function44,
	__game_engine_virtual_function_get_path_by_type,
	__game_engine_virtual_function_get_path_by_type_wide,
	__game_engine_virtual_function_function47,
	__game_engine_virtual_function_function48,
	__game_engine_virtual_function_function49,
	__game_engine_virtual_function_function50,
	__game_engine_virtual_function_function51,
};

class IGameEngineHost
{
public:
	static constexpr size_t kTableSize = 128;
	void* __vtbl_dynamic;

	IGameEngineHost(e_engine_type engine_type, e_build build, IGameEvents* game_events);
	IGameEngineHost* GetDynamicGameEngineHost();

	enum class PathType : int
	{
		DebugLogs,
		Config,
		Temporary,
		Root
	};

	enum class NetworkID : unsigned __int64
	{
		Invalid,
		Unknown1,
		Unknown2,
		Unknown3,
		k_NumNetworkID
	};

#pragma pack(push, 1)
	enum class InputSource : int
	{
		Gamepad,
		MouseAndKeyboard
	};

	struct InputBuffer
	{

		InputSource		inputSource;
		char			keyboardState[256];
		float			MouseX;
		float			MouseY;
		float			UnknownA;
		float			UnknownB;
		char			mouseButtonBits;
		char			__padding[3];
		DWORD           wButtons;
		BYTE            bLeftTrigger;
		BYTE            bRightTrigger;
		SHORT           sThumbLX;
		SHORT           sThumbLY;
		SHORT           sThumbRX;
		SHORT           sThumbRY;
		char			__padding2[2];
	};
	CHECK_STRUCTURE_SIZE(InputBuffer, 0x128);
#pragma pack(pop)

	struct GameResultsData
	{
		char unknown0[0x58738];
	};
	CHECK_STRUCTURE_SIZE(GameResultsData, 0x58738);

	struct Function22Structure
	{
		char data[0x110];
	};
	CHECK_STRUCTURE_SIZE(Function22Structure, 0x110);

#pragma pack(push, 1)
	struct UpdateGraphicsData
	{
		int VIDEO_SizeX;
		int VIDEO_SizeY;
		int VIDEO_TextureQuality;					 // between 0 and 2
		int VIDEO_AF_Qual;							 // between 0 and 2
		int VIDEO_SSAOQuality;						 // between 0 and 2
		int unknown10_4;
		int VIDEO_ShadowMapQual;					 // between 0 and 2
		int VIDEO_LodDistQualityFactor;				 // between 0 and 2
		int unknown20;
		int WindowMode;
		bool VIDEO_UseEdgeAA;
		bool VIDEO_Wait_VSync;
		bool VIDEO_FPS_Lock;
		char unknown2B;
		char unknown2C[168]; // unknown
		float unknownD4_0;
		float unknownD4_4;
		float unknownD4_8;
		float unknownD4_C;
		float unknownD4_10;
		float unknownD4_14;
		float unknownD4_18;
		float unknownD4_1C;
		float unknownD4_20;
		float unknownD4_24;
		float unknownD4_28;
		float unknownD4_2C;
		float unknownD4_30;
		float unknownD4_34;
		float unknownD4_38;
		float unknownD4_3C;
		float unknownD4_40;
		float unknownD4_44;
		float unknownD4_48;
		float unknownD4_4C;
		float unknownD4_50;
		float unknownD4_54;
		float unknownD4_58;
		float unknownD4_5C;
		float unknownD4_60;
		float unknownD4_64;
		float unknownD4_68;
		float unknownD4_6C;
		float unknownD4_70;
		float unknownD4_74;
		float unknownD4_78;
		float unknownD4_7C;
		float unknownD4_80;
		float unknownD4_84;
		long unknownD4_88;
		long unknownD4_8C;
		long unknownD4_90;
		long unknownD4_94;
		long unknownD4_98;
		long unknownD4_9C;
		long unknownD4_A0;
		long unknownD4_A4;
		long unknownD4_A8;
	};
	CHECK_STRUCTURE_SIZE(UpdateGraphicsData, 0x180);
#pragma pack(pop)

	struct s_transport_address;

	/* 0  */ virtual char FrameStart();
	/* 1  */ virtual void FrameEnd(IDXGISwapChain* swap_chain, _QWORD);
	/* 2  */ virtual void Function02(__int64 player_identifier, unsigned int, __int64, float, float, float, float);
	/* 3  */ virtual void EngineStateUpdate(eEngineState state);
	/* 4  */ virtual __int64 GameExited(unsigned int, char*, int);
	/* 5  */ virtual __int64 __fastcall SaveGameState(LPVOID buffer, size_t buffer_size);
	/* 6  */ virtual void SubmitGameResults(GameResultsData* game_results_data);
	/* 7  */ virtual void Function07(unsigned int);
	/* 8  */ virtual void Function08(const wchar_t*, const wchar_t*);
	/* 9  */ virtual void Function09(wchar_t[1024], wchar_t[1024]);
	/* 10 */ virtual IGameEvents* GetGameEvents();
	/* 11 */ virtual void SaveGameVariant(IGameVariant* game_variant);
	/* 12 */ virtual void SaveMapVariant(IMapVariant* map_variant);
	/* 13 */ virtual void Function13(const wchar_t*, const wchar_t*, const void*, unsigned int);
	/* 14 */ virtual char InvertLookControls(int controller_index, bool inverted);
	/* 15 */ virtual char GetGameSpecificBindings(int controller_index, char(*buffer)[256]);
	/* 16 */ virtual char GetNextLevelInfo(e_map_id* pMapID, int* campaign_insertion_point, FILETIME* file_time, _DWORD*);
	/* 17 */ virtual bool Function17(int);
	/* 18 */ virtual void Function18(int);
	/* 19 */ virtual __int64 __fastcall MapLoadPecentStatus(__int64, __int64, float);
	/* 20 */ virtual void Function20(__int64, __int8);
	/* 21 */ virtual __int64 __fastcall GetMachineIdentifier(_QWORD);
	/* 22 */ virtual __int64 Function22(Function22Structure* buffer, __int64);
	/* 23 */ virtual char Function23(__int64, __int64);
	/* 24 */ virtual void GetSessionInfo(s_session_info_part* session_info_part);
	/* 25 */ virtual void __fastcall MembershipUpdate(s_session_membership* session_membership, uint32_t player_count);
	/* 26 */ virtual bool __fastcall Function26();
	/* 27 */ virtual bool __fastcall Function27();
	/* 28 */ virtual bool __fastcall UpdateGraphics(UpdateGraphicsData* update_graphics_data);
	/* 29 */ virtual c_player_configuration* __fastcall GetPlayerConfiguration(__int64 value);
	/* 30 */ virtual __int64 __fastcall UpdatePlayerConfiguration(wchar_t player_names[4][16], c_player_configuration* player_configuration);
	/* 31 */ virtual bool __fastcall __fastcall UpdateInput(_QWORD, InputBuffer* input_buffer);
	/* 32 */ virtual void Function32(_QWORD, float*);
	/* 33 */ virtual void Function33();
	/* 34 */ virtual void XInputSetState(DWORD user_index, XINPUT_VIBRATION* xinput_vibration);
	/* 35 */ virtual bool __fastcall __fastcall UpdatePlayerNames(__int64*, wchar_t player_names[4][16], size_t data_size);
	/* 36 */ virtual void __fastcall Function36(const wchar_t*, const wchar_t*);
	/* 37 */ virtual bool __fastcall Function37(wchar_t*, __int64);
	/* 38 */ virtual __int64 __fastcall NetworkSendTo(NetworkID network_id, char* buffer, uint32_t buffer_size, int a4);
	/* 39 */ virtual __int64 __fastcall NetworkReceiveFrom(char* buffer, uint32_t buffer_size, __int64, s_transport_address* pTransportAddress);
	/* 40 */ virtual char* __fastcall Function40(unsigned int);
	/* 41 */ virtual int __fastcall Function41(BYTE* buffer);
	/* 42 */ virtual bool __fastcall Function42(signed int, __int64, __int64);
	/* 43 */ virtual void __fastcall FirefightNew(__int64, float);
	/* 44 */ virtual BOOL __fastcall Function44(__int64, __int64);
	/* 45 */ virtual bool __fastcall get_pathByType(PathType path_type, LPSTR buffer, size_t buffer_length);
	/* 46 */ virtual bool __fastcall GetWidePathByType(PathType path_type, LPWSTR buffer, size_t buffer_length);
	/* 47 */ virtual unsigned __int8* __fastcall Function47(_QWORD, unsigned __int8*, _QWORD);
	/* 48 */ virtual __int64 __fastcall Function48(_QWORD, __int64);
	/* 49 */ virtual char* __fastcall Function49(char* str); /* added in 1377 */
	/* 50 */ virtual __int64  __fastcall Function58(); /* added in 1629 */
	/* 51 */ virtual __int64 __fastcall Function59(__int64 a1, unsigned int a2); /* added in 1629 */

	/* barrier functions to prevent new versions of games calling our functions */
	IGameEngineHostCreateBarrierDefinition(50);
	IGameEngineHostCreateBarrierDefinition(51);
	IGameEngineHostCreateBarrierDefinition(52);
	IGameEngineHostCreateBarrierDefinition(53);
	IGameEngineHostCreateBarrierDefinition(54);
	IGameEngineHostCreateBarrierDefinition(55);
	IGameEngineHostCreateBarrierDefinition(56);
	IGameEngineHostCreateBarrierDefinition(57);

	// IGameEngineHost data
	IGameEvents* game_events_ptr = nullptr;
	QWORD data1[5863] = {};

	// begin custom data
	e_engine_type engine_type;
	e_build build;
	bool game_engine_host_configured;
	void ConfigureGameEngineHost();

	void* __vtbl_dynamic_data[kTableSize];
	/*
	These two values make up known addresses. If a virtual function is called and the expected value of __vtbl_known_address1 is found __vtbl_known_address0
	then that means that the virtual function being called has had its 'this' value shifted to offset the __vtbl to use __vtbl_dynamic.
	This check allows each virtual function to run itself and correct the address
	*/
	static constexpr uintptr_t known_address0 = static_cast<uintptr_t>(0xe23a921724befda0);
	static constexpr uintptr_t known_address1 = static_cast<uintptr_t>(0xdaeb9e926aca55b7);
	uintptr_t __vtbl_known_address0 = known_address0;
	uintptr_t __vtbl_known_address1 = known_address1;

	bool PlayerConfigurationFromBuild(e_build build, c_player_configuration** player_configuration);
	void ConfigurePlayerConfiguration(c_player_configuration& player_configuration);
};
//CHECK_STRUCTURE_SIZE(IGameEngineHost, 0xB748);
#pragma pack(pop)

#undef IGameEngineHostCreateBarrierDefinition
