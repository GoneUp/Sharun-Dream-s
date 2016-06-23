#include "Sharun.hpp"
#include "internal/version.hpp"

#include <ctime>
#include <cstring>

settings::~settings()
{
	free(Server_Name);
	free(SERVER_SIGN);
	free(SERVER_COPYRIGHT);
	if (DataBase.Login)
		free(DataBase.Login);
	if (DataBase.Pass)
		free(DataBase.Pass);
	if (DataBase.Name)
		free(DataBase.Name);
}

settings::settings()
{
// Server common's defaults
	Player_Max	= 5;
	Packets_Fill_Size = false;
	Net.localhost	= false;
	Server_Name	= strdump(DEFAULT_SERVER_NAME);
	SERVER_SIGN	= strdump("<!-- Signature from team of this server -->");
	SERVER_COPYRIGHT = strdump("<!-- Copyright from team of this server -->");
	AutoAccount	= false;
	newHP		= true;
	Stamina4Speed	= false;

// Database
	strcpy(DataBase.IP, "127.0.0.1");
	DataBase.Port	= 3306;
	DataBase.Login	= NULL;
	DataBase.Pass	= NULL;
	DataBase.Name	= NULL;

// Thread
	Thread.DataBase.Fast	= 1;
	Thread.DataBase.Slow	= 0;
	Thread.Broadcast	= 1;
	Thread.Httpd		= 1;

// Ports defaults
	Net.Ports.Game	 = 14752;
	Net.Ports.Httpd	 = 8080;
	Net.Ports.Bridge = 0;//14750;

// Directory defaults path
	Dirs.Saves	= "Sharun_Saves";

// Load From File...
	FILE *fp = fopen("config.ini", "r");
	while (!feof(fp)) {
		char lib[126], val[126], *p;
		fscanf(fp, " %s = %[^\n]s", lib, val);
		p = strchr(lib, '\r');
		if (p) p[0] = 0;
		p = strchr(val, '\r');
		if (p) p[0] = 0;
		if (!strcmp(lib, "Player_Max"))		Player_Max	= atoi(val);
		if (!strcmp(lib, "Packets_Fill_Size"))	Packets_Fill_Size = atob(val);
		if (!strcmp(lib, "Net.localhost"))	Net.localhost	= atob(val);
		if (!strcmp(lib, "Server_Name"))	strupdate(&Server_Name, val);
		if (!strcmp(lib, "SERVER_SIGN"))	strupdate(&SERVER_SIGN, val);
		if (!strcmp(lib, "SERVER_COPYRIGHT"))	strupdate(&SERVER_COPYRIGHT, val);
		if (!strcmp(lib, "AutoAccount"))	AutoAccount= atob(val);
		if (!strcmp(lib, "newHP"))		newHP	= atob(val);
		if (!strcmp(lib, "Stamina4Speed"))	Stamina4Speed	= atob(val);
		if (!strcmp(lib, "Server_Name"))	strupdate(&Server_Name, val);
		if (!strcmp(lib, "DataBase.IP"))	strcpy(DataBase.IP, val);
		if (!strcmp(lib, "DataBase.Port"))	DataBase.Port	= atoi(val);
		if (!strcmp(lib, "DataBase.Login"))	strupdate(&DataBase.Login, val);
		if (!strcmp(lib, "DataBase.Pass"))	strupdate(&DataBase.Pass, val);
		if (!strcmp(lib, "DataBase.Name"))	strupdate(&DataBase.Name, val);
		if (!strcmp(lib, "Thread.DataBase.Fast")) Thread.DataBase.Fast	= atoi(val);
		if (!strcmp(lib, "Thread.DataBase.Slow")) Thread.DataBase.Slow	= atoi(val);
		if (!strcmp(lib, "Thread.Broadcast"))	Thread.Broadcast	= atoi(val);
		if (!strcmp(lib, "Thread.Httpd"))	Thread.Httpd	= atoi(val);
		if (!strcmp(lib, "Net.Ports.Game"))	Net.Ports.Game	= atoi(val);
		if (!strcmp(lib, "Net.Ports.Httpd"))	Net.Ports.Bridge	= atoi(val);
		if (!strcmp(lib, "Net.Ports.Bridge"))	Net.Ports.Bridge	= atoi(val);
		if (!strcmp(lib, "Dirs.Saves"))		Dirs.Saves = val;
		
	}
	fclose(fp);

// Set other directories...
	Dirs.Logs	= Dirs.Saves + "/Logs";
	Dirs.OpCodes	= Dirs.Saves + "/OpCodes";
	Dirs.DB 	= Dirs.Saves + "/DB";
	Dirs.WWW	= Dirs.Saves + "/www";
	Dirs.Guild_Logo	= Dirs.Saves + "/Guild_Logo";
	Dirs.Settings.Account	= Dirs.Saves + "/Settings/Account";
	Dirs.Settings.Chat	= Dirs.Saves + "/Settings/Chat";
	Dirs.Settings.User	= Dirs.Saves + "/Settings/User";

// DON'T TOUCH !
	PLAYER_COUNT = 0;
	Start_Count = 0;

	time_t rawtime;
	struct tm * t_info;
	time ( &rawtime );
	t_info = localtime ( &rawtime );
	sprintf(Start_Time, "%04i-%02i-%02i %02i:%02i:%02i", t_info->tm_year+1900, t_info->tm_mon+1, t_info->tm_mday, t_info->tm_hour, t_info->tm_min, t_info->tm_sec);

	srand(rawtime);
}