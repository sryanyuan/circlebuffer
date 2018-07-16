#ifndef _INC_LUA_ITEM_ATTRIB_LOADER_
#define _INC_LUA_ITEM_ATTRIB_LOADER_

#include <map>
#include "item.h"

struct ItemFullAttrib;
struct lua_State;

#define pszDefaultItemFullAttribTableName  "config_constItemAttrib"
#define pszDefaultMonsAttribTableName  "config_constMonsAttrib"

class LuaDataLoader {
public:
    static bool LoadItemAttrib(lua_State *L, const char *pKeyName, std::map<int, ItemFullAttrib> &refAttribs);
    static bool LoadMonsAttrib(lua_State *L, const char* pKeyName, std::map<int, MonsFullAttrib> &refMons);

private:
    static bool loadKeyString(lua_State *L, const char *pKeyName, char *pBuf);
    static bool loadKeyInt(lua_State *L, const char *pKeyName, int &refValue);
    static bool loadKeyInt(lua_State *L, const char *pKeyName, char &refValue);
    static bool loadKeyInt(lua_State *L, const char *pKeyName, short &refValue);
};

#endif
