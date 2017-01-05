#include "LuaIterator.h"
#include <stdio.h>
#include <assert.h>
extern "C"
{
	#include "lua.h"
};

LuaIterator::LuaIterator(lua_State* L)
{
	Reset();
	m_L = L;
	m_nOriginStackIndex = lua_gettop(L);
}

LuaIterator::~LuaIterator()
{
	Reset();
}

void LuaIterator::Reset()
{
	m_L = NULL;
	m_nTableIndex = 0;
	m_bKeyValueAvailable = false;
}

bool LuaIterator::IsValid()
{
	return m_L != NULL;
}

lua_State* LuaIterator::GetState()
{
	return m_L;
}

bool LuaIterator::Begin()
{
	if (!IsValid())
	{
		return false;
	}

	m_nTableIndex = lua_gettop(m_L);
	if (!lua_istable(m_L, m_nTableIndex))
	{
		return false;
	}

	// push the initialize key
	lua_pushnil(m_L);

	// after call, stack -> top : table nil
	return true;
}

bool LuaIterator::Next()
{
	if (!IsValid())
	{
		return false;
	}

	if (m_bKeyValueAvailable)
	{
		// not the first call, must clear the previous value
		// stack : table key
		lua_pop(m_L, 1);
		m_bKeyValueAvailable = false;
	}

	if (lua_next(m_L, m_nTableIndex))
	{
		// stack : table key value
		m_bKeyValueAvailable = true;
	}
	else
	{
		// reach the last key
		int nFinalTop = lua_gettop(m_L);
		assert(nFinalTop == m_nOriginStackIndex);
		Reset();

		return false;
	}

	return true;
}

int LuaIterator::GetKeyType()
{
	if (!m_bKeyValueAvailable ||
		!IsValid())
	{
		return LUA_TNIL;
	}

	// stack : table key value
	return lua_type(m_L, -2);
}

int LuaIterator::GetValueType()
{
	if (!m_bKeyValueAvailable ||
		!IsValid())
	{
		return LUA_TNIL;
	}

	// stack : table key value
	return lua_type(m_L, -1);
}

const char* LuaIterator::GetKeyString()
{
	if (LUA_TSTRING != GetKeyType())
	{
		return "";
	}

	return lua_tostring(m_L, -2);
}

int LuaIterator::GetKeyInt()
{
	if (LUA_TNUMBER != GetKeyType())
	{
		return 0;
	}

	return lua_tointeger(m_L, -2);
}

const char* LuaIterator::GetValueString()
{
	if (LUA_TSTRING != GetValueType())
	{
		return "";
	}

	return lua_tostring(m_L, -1);
}

int LuaIterator::GetValueInt()
{
	if (LUA_TNUMBER != GetValueType())
	{
		return 0;
	}

	return lua_tointeger(m_L, -1);
}