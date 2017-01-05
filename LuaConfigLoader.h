#ifndef _INC_LUACONFIGLOADER_
#define _INC_LUACONFIGLOADER_
//////////////////////////////////////////////////////////////////////////
#include <map>
#include <vector>
#include <string>
//////////////////////////////////////////////////////////////////////////
struct lua_State;

struct LuaItemAttrib
{
	int nID;
	int nGrade;
};
typedef std::map<int, LuaItemAttrib> LuaItemAttribMap;

struct LuaMapInfo
{
	// 0:normal 1:instance
	int nMapType;
	int nResID;
	char szMapResFile[20];
	char szMapChName[20];
};
typedef std::vector<LuaMapInfo> LuaMapInfoVector;

class LuaStackGuard
{
public:
	LuaStackGuard(lua_State* L);
	~LuaStackGuard();

private:
	lua_State* m_L;
	int m_nInitStackTop;
};

class LuaConfigLoader
{
public:
	static bool LoadItemAttrib(lua_State* _L, const char* _pszName, LuaItemAttribMap& _refItemMap);
	static bool LoadMapInfo(lua_State* L, const char* _pszName, LuaMapInfoVector& _refMapVector);
	static bool LoadFixedMaps(lua_State* L, const char* _pszName, std::vector<std::string>& _refFixedMapIDs);
};
//////////////////////////////////////////////////////////////////////////
#endif