#ifndef _INC_LUAITERATOR_
#define _INC_LUAITERATOR_
//////////////////////////////////////////////////////////////////////////
struct lua_State;

class LuaIterator
{
public:
	LuaIterator(lua_State* L);
	~LuaIterator();

public:
	bool Begin();
	bool Next();

	bool IsValid();
	
	int GetKeyType();
	int GetValueType();

	const char* GetKeyString();
	int GetKeyInt();

	const char* GetValueString();
	int GetValueInt();

	lua_State* GetState();
	void Reset();

protected:
	lua_State* m_L;
	int m_nTableIndex;
	int m_nOriginStackIndex;
	bool m_bKeyValueAvailable;
};
//////////////////////////////////////////////////////////////////////////
#endif