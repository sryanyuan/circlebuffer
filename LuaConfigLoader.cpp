#include "LuaConfigLoader.h"
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
	assert(m_nInitStackTop == lua_gettop(m_L));
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
//////////////////////////////////////////////////////////////////////////
bool LuaConfigLoader::LoadItemConfig(lua_State* L, const char* _pszName, LuaItemConfigMap& _refItemMap)
{
	LuaStackGuard stackChecker(L);

	lua_getglobal(L, _pszName);
	if (!lua_istable(L, -1))
	{
		// LUA_TNIL
		lua_pop(L, 1);
		return false;
	}

	int tableIndex = lua_gettop(L);
	// push the first key
	lua_pushnil(L);
	while (0 != lua_next(L, tableIndex))
	{
		// stack : table key value
		if (!lua_isnumber(L, -2))
		{
			// ignore the key
			lua_pop(L, 1);
			continue;
		}
		LuaItemConfig config;
		memset(&config, 0, sizeof(config));
		// get the id (value)
		config.nID = int(lua_tonumber(L, -2));
		
		if (!lua_istable(L, -1))
		{
			// ignore the value
			lua_pop(L, 1);
			continue;
		}

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

		// Done, pop all fields
		lua_pop(L, 2); // stack : table key

		_refItemMap.insert(std::make_pair(config.nID, config));
	}
	// last key will pop the key, stack : table
	lua_pop(L, 1);

	return true;
}