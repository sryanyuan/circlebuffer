#ifndef _INC_MAPCONFIGMANAGER_
#define _INC_MAPCONFIGMANAGER_
//////////////////////////////////////////////////////////////////////////
#define LUA_CONFIGKEY_MAPINFO	"config_mapInfo"
#define LUA_CONFIGKEY_FIXEDMAPS	"config_fixedLoadMaps"
//////////////////////////////////////////////////////////////////////////
#include "LuaConfigLoader.h"
//////////////////////////////////////////////////////////////////////////
struct lua_State;

class MapConfigManager
{
public:
	MapConfigManager();
	~MapConfigManager();

public:
	bool Init(lua_State* L);

	const LuaMapInfo* GetLuaMapInfo(int _nMapResID);
	const std::vector<int>& GetFixedMaps();

private:
	LuaMapInfoVector m_xMapInfoVector;
	std::vector<int> m_xFixedMapIDVector;
};
//////////////////////////////////////////////////////////////////////////
#endif