#ifndef _SETTINGS_HPP_
#define _SETTINGS_HPP_

class settings {
	public:
		settings();
		~settings();
		char*	Server_Name;
		char	Start_Time[20];
		char*	SERVER_SIGN;
		char*	SERVER_COPYRIGHT;
		ushort	Start_Count;
		ushort	PLAYER_COUNT;
		ushort	Player_Max;
		bool	Packets_Fill_Size;
		bool	AutoAccount;
		bool	newHP;
		bool	Stamina4Speed;
		struct Dirs {
			std::string Saves;
			std::string Logs;
			std::string OpCodes;
			std::string DB;
			std::string WWW;
			std::string Guild_Logo;
			struct Settings {
				std::string Account;
				std::string Chat;
				std::string User;
			} Settings;
		} Dirs;
		struct Thread {
			ushort	Broadcast;
			ushort	Httpd;
			struct DataBase {
				ushort Fast;
				ushort Slow;
			} DataBase;
		} Thread;
		struct DataBase {
			char	IP[8*4+7+1];
			ushort	Port;
			char*	Login;
			char*	Pass;
			char*	Name;
		} DataBase;
		struct Net {
			bool	localhost;
			struct Ports {
				ushort	Game;
				ushort	Httpd;
				ushort	Bridge;
			} Ports;
		} Net;
};

extern settings* Settings;

#endif // _SETTINGS_HPP_
