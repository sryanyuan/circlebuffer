#include "LuaConfigLoader.h"
#include "LuaIterator.h"
extern "C"
{
	#include "lua.h"
};
#include <assert.h>
//////////////////////////////////////////////////////////////////////////
LuaStackGuard::LuaStackGuard(lua_State* L)
{
	m_L = L;
	m_nInitStackTop = lua_gettop(L);
}

LuaStackGuard::~LuaStackGuard()
{
	int nCurrStack = lua_gettop(m_L);
	assert(m_nInitStackTop == nCurrStack);
}
//////////////////////////////////////////////////////////////////////////
static void stackDump(lua_State *L)  
{  
	int i;  
	int top = lua_gettop(L);  
	printf("the size of stack is:%d\n",top);  
	for ( i = 1;i <= top;i++ )  
	{  
		int type = lua_type(L, i);  
		switch(type)  
		{  
		case LUA_TSTRING:  
			{  
				printf("%s",lua_tostring(L, i));  
				break;  
			}  

		case LUA_TBOOLEAN:  
			{  
				printf(lua_toboolean(L, i)?"true":"false");  
				break;  
			}  
		case LUA_TNUMBER:  
			{  
				printf("%g",lua_tonumber(L, i));  
				break;  
			}  
		case LUA_TTABLE:  
			{  
				printf("this is a table!");  
				break;  
			}  
		default:  
			{  
				printf("%s",lua_typename(L ,i));  
				break;  
			}  
		}  
		printf(" ");  
	}  
	printf("\n");  
}

bool LuaConfigLoader::LoadItemAttrib(lua_State* L, const char* _pszName, LuaItemAttribMap& _refItemMap)
{
	LuaStackGuard stackChecker(L);

	lua_getglobal(L, _pszName);
	if (!lua_istable(L, -1))
	{
		// LUA_TNIL
		lua_pop(L, 1);
		return false;
	}

	LuaIterator it(L);
	if (!it.Begin())
	{
		return false;
	}

	while (it.Next())
	{
		if (LUA_TNUMBER != it.GetKeyType())
		{
			continue;
		}
		if (LUA_TTABLE != it.GetValueType())
		{
			continue;
		}

		LuaItemAttrib config;
		memset(&config, 0, sizeof(config));
		// get the id (value)
		config.nID = it.GetKeyInt();

		// now we get the config table , read all need fields
		// stack : bottom | table key value | top
		// get Grade
		lua_getfield(L, -1, "Grade");
		if (!lua_isnumber(L, -1))
		{
			// invalid value
			// stack : table key value nil
			lua_pop(L, 4);
			return false;
		}
		// OK, stack : table key value Grade
		config.nGrade = int(lua_tonumber(L, -1));
		// pop the grade value
		lua_pop(L, 1);

		_refItemMap.insert(std::make_pair(config.nID, config));
	}

	// pop the table
	lua_pop(L, 1);

	return true;
}

bool LuaConfigLoader::LoadMapInfo(lua_State* L, const char* _pszName, LuaMapInfoVector& _refMapVector)
{
	LuaStackGuard stackChecker(L);

	lua_getglobal(L, _pszName);
	if (!lua_istable(L, -1))
	{
		// LUA_TNIL
		lua_pop(L, 1);
		return false;
	}

	int len = lua_objlen(L, -1);
	if (len <= 0)
	{
		return true;
	}
	_refMapVector.resize(len);

	for (int i = 1; i <= len; ++i)
	{
		lua_pushinteger(L, i);
		lua_gettable(L, -2);

		if (!lua_istable(L, -1))
		{
			// stack : table nil
			lua_pop(L, 2);
			return false;
		}

		LuaMapInfo info;
		memset(&info, 0, sizeof(info));
		info.nResID = i - 1;

		// stack : table table
		lua_pushstring(L, "MapType"); // table table string
		lua_gettable(L, -2);

		if (!lua_isnumber(L, -1))
		{
			// table table nil
			lua_pop(L, 3);
			return false;
		}

		// stack : table table number
		info.nMapType = lua_tointeger(L, -1);
		lua_pop(L, 1);

		lua_pushstring(L, "MapResFile"); // table table string
		lua_gettable(L, -2);

		if (!lua_isstring(L, -1))
		{
			// table table nil
			lua_pop(L, 3);
			return false;
		}

		// stack : table table string
		const char* pszMapResFile = lua_tostring(L, -1);
		if (strlen(pszMapResFile) >= sizeof(info.szMapResFile))
		{
			lua_pop(L, 3);
			return false;
		}
		strcpy_s(info.szMapResFile, pszMapResFile);
		lua_pop(L, 1);

		lua_pushstring(L, "MapChName"); // table table string
		lua_gettable(L, -2);

		if (!lua_isstring(L, -1))
		{
			// table table nil
			lua_pop(L, 3);
			return false;
		}

		// stack : table table string
		const char* pszMapChName = lua_tostring(L, -1);
		if (strlen(pszMapChName) > sizeof(info.szMapChName))
		{
			lua_pop(L, 3);
			return false;
		}
		strcpy_s(info.szMapChName, pszMapChName);
		lua_pop(L, 1);

		// pop the second table
		lua_pop(L, 1);

		_refMapVector[i - 1] = info;
	}

	// pop the table
	lua_pop(L, 1);

	return true;
}

bool LuaConfigLoader::LoadFixedMaps(lua_State* L, const char* _pszName, std::vector<std::string>& _refFixedMapIDs)
{
	LuaStackGuard stackChecker(L);

	lua_getglobal(L, _pszName);
	if (!lua_istable(L, -1))
	{
		// LUA_TNIL
		lua_pop(L, 1);
		return false;
	}

	int len = lua_objlen(L, -1);
	if (len <= 0)
	{
		return true;
	}
	_refFixedMapIDs.resize(len);

	for (int i = 1; i <= len; ++i)
	{
		lua_pushinteger(L, i);
		lua_gettable(L, -2);

		if (!lua_isstring(L, -1))
		{
			// stack : table nil
			lua_pop(L, 2);
			return false;
		}

		_refFixedMapIDs[i - 1] = lua_tostring(L, -1);
		lua_pop(L, 1);
	}

	// pop the table
	lua_pop(L, 1);

	return true;
}