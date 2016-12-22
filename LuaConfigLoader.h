#ifndef _INC_LUACONFIGLOADER_
#define _INC_LUACONFIGLOADER_
//////////////////////////////////////////////////////////////////////////
#include <map>
//////////////////////////////////////////////////////////////////////////
struct lua_State;

struct LuaItemConfig
{
	int nID;
	int nGrade;
};
typedef std::map<int, LuaItemConfig> LuaItemConfigMap;

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
	static bool LoadItemConfig(lua_State* _L, const char* _pszName, LuaItemConfigMap& _refItemMap);
};
//////////////////////////////////////////////////////////////////////////
#endif