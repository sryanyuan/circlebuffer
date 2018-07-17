#ifndef _INC_LUA_ITEM_ATTRIB_LOADER_
#define _INC_LUA_ITEM_ATTRIB_LOADER_

#include <map>
#include <vector>
using std::vector;
#include "item.h"

struct ItemFullAttrib;
struct lua_State;

#define pszDefaultItemFullAttribTableName  "config_constItemAttrib"
#define pszDefaultMonsFullAttribTableName  "config_constMonsAttrib"
#define pszDefaultLifeSkillTableName "config_constLifeSKill"
#define pszDefaultMakeEquipTableName "config_constMakeEquip"
#define pszDefaultStoveAttribTableName "config_constStoveAttrib"
#define pszDefaultSuitAttribTableName "config_constSuitAttrib"

class LuaDataLoader {
public:
    static bool LoadItemAttrib(lua_State *L, const char *pKeyName, std::map<int, ItemFullAttrib> &refAttribs);
    static bool LoadMonsAttrib(lua_State *L, const char* pKeyName, std::map<int, MonsFullAttrib> &refMons);
    static bool LoadLifeSkill(lua_State *L, const char* pKeyName, LifeSkillInfo (&refSkills)[kLifeSkill_Total]);
    static bool LoadMakeEquip(lua_State *L, const char* pKeyName, MakeEquipInfoMap &refEquip);
    static bool LoadStoveAttrib(lua_State *L, const char* pKeyName, StoveAttribVector &refAttribs);
    static bool LoadSuitAttrib(lua_State *L, const char* pKeyName, std::map<int, ItemExtraAttribList*> &refSuits);

public:
    static bool loadKeyString(lua_State *L, const char *pKeyName, char *pBuf);
    static bool loadKeyInt(lua_State *L, const char *pKeyName, int &refValue);
    static bool loadKeyInt(lua_State *L, const char *pKeyName, char &refValue);
    static bool loadKeyInt(lua_State *L, const char *pKeyName, short &refValue);
    static bool loadKeyIntArray(lua_State *L, const char* pKeyName, vector<int> &refVals);
};

#endif
