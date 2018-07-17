#include "LuaDataLoader.h"
extern "C"
{
#include "lua.h"
};
#include "LuaIterator.h"
#include "LuaStackGuard.h"
#include "item.h"
#include <Windows.h>

bool LuaDataLoader::loadKeyString(lua_State *L, const char *pKeyName, char *pBuf) {
    // now we get the config table , read all need fields
    // stack : bottom | table key value | top
    // get Grade
    lua_getfield(L, -1, pKeyName);
    if (!lua_isstring(L, -1))
    {
        // invalid value
        // stack : table key value nil
        lua_pop(L, 1);
        //lua_pop(L, 4);
        return false;
    }
    // OK, stack : table key value Grade
    strcpy(pBuf, lua_tostring(L, -1));
    // pop the grade value
    lua_pop(L, 1);
    return true;
}

bool LuaDataLoader::loadKeyIntArray(lua_State *L, const char* pKeyName, vector<int> &refVals) {
    // Stack: bottom | table key value | top
    // Get exprs from value table
    lua_getfield(L, -1, pKeyName);
    if (!lua_istable(L, -1)) {
        lua_pop(L, 1);
        return false;
    }
    // Stack: table key table table
    // Index from 1
    for (int i = 1; ;i++) {
        // table key table table index
        lua_pushnumber(L, i);
        lua_rawget(L, -2);
        if (!lua_isnumber(L, -1)) {
            // table key table table nil
            // Pop the top 1 vals
            lua_pop(L, 1);
            break;
        }
        refVals.push_back(lua_tonumber(L, -1));
        // Pop the value
        lua_pop(L, 1);
    }
    /*LuaIterator it(L);
    if (!it.Begin())
    {
        return false;
    }
    while (it.Next()) {
        if (it.GetKeyType() != LUA_TNUMBER) {
            // Pop key and value
            lua_pop(L, 2);
            return false;
        }
        if (it.GetValueType() != LUA_TNUMBER) {
            // Pop key and value
            lua_pop(L, 2);
            return false;
        }
        refVals.push_back(it.GetValueInt());
    }*/
    // Pop the table
    lua_pop(L, 1);
    return true;
}

bool LuaDataLoader::loadKeyInt(lua_State *L, const char *pKeyName, int &refValue) {
    // now we get the config table , read all need fields
    // stack : bottom | table key value | top
    // get Grade
    lua_getfield(L, -1, pKeyName);
    if (!lua_isnumber(L, -1))
    {
        // invalid value
        // stack : table key value nil
        //lua_pop(L, 4);
        // Just pop the nil value
        lua_pop(L, 1);
        return false;
    }
    // OK, stack : table key value Grade
    refValue = int(lua_tonumber(L, -1));
    // pop the grade value
    lua_pop(L, 1);
    return true;
}

bool LuaDataLoader::loadKeyInt(lua_State *L, const char *pKeyName, char &refValue) {
    int value;
    if (!loadKeyInt(L, pKeyName, value)) {
        return false;
    }
    refValue = (char)value;
    return true;
}

bool LuaDataLoader::loadKeyInt(lua_State *L, const char *pKeyName, short &refValue) {
    int value;
    if (!loadKeyInt(L, pKeyName, value)) {
        return false;
    }
    refValue = (short)value;
    return true;
}

bool LuaDataLoader::LoadItemAttrib(lua_State* L, const char *pKeyName, std::map<int, ItemFullAttrib> &refAttribs) {
    LuaStackGuard guard(L);

    lua_getglobal(L, pKeyName);
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

    char szDesc[255];
    szDesc[0] = 0;

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

        ItemFullAttrib config;
        // get the id (value)
        config.baseAttrib.id = it.GetKeyInt();

        // now we get the config table , read all need fields
        // stack : bottom | table key value | top
        // get Grade
        if (!loadKeyInt(L, "Grade", config.nGrade)) {
            //return false;
        }
        // Get name
        if (!loadKeyString(L, "Name", config.baseAttrib.name)) {
            return false;
        }
        // Get weight
        if (!loadKeyInt(L, "Weight", config.baseAttrib.weight)) {
            //return false;
        }
        // Get Type
        if (!loadKeyInt(L, "Type", config.baseAttrib.type)) {
            //return false;
        }
        // Get Lucky
        if (!loadKeyInt(L, "Lucky", config.baseAttrib.lucky)) {
            //return false;
        }
        // Get Curse
        if (!loadKeyInt(L, "Curse", config.baseAttrib.curse)) {
            //return false;
        }
        // Get Hide
        if (!loadKeyInt(L, "Hide", config.baseAttrib.hide)) {
            //return false;
        }
        // Get Accuracy
        if (!loadKeyInt(L, "Accuracy", config.baseAttrib.accuracy)) {
            //return false;
        }
        // Get AtkSpeed
        if (!loadKeyInt(L, "AtkSpeed", config.baseAttrib.atkSpeed)) {
            //return false;
        }
        // Get AtkPalsy
        if (!loadKeyInt(L, "AtkPalsy", config.baseAttrib.atkPalsy)) {
            //return false;
        }
        // Get AtkPois
        if (!loadKeyInt(L, "AtkPois", config.baseAttrib.atkPois)) {
            //return false;
        }
        // Get MoveSpeed
        if (!loadKeyInt(L, "MoveSpeed", config.baseAttrib.moveSpeed)) {
            //return false;
        }
        // Get ReqType
        if (!loadKeyInt(L, "ReqType", config.baseAttrib.reqType)) {
            //return false;
        }
        // Get ReqValue
        if (!loadKeyInt(L, "ReqValue", config.baseAttrib.reqValue)) {
            //return false;
        }
        // Get Sex
        if (!loadKeyInt(L, "Sex", config.baseAttrib.sex)) {
            //return false;
        }
        // Get MaxDC
        if (!loadKeyInt(L, "MaxDC", config.baseAttrib.maxDC)) {
            //return false;
        }
        // Get DC
        if (!loadKeyInt(L, "DC", config.baseAttrib.DC)) {
            //return false;
        }
        // Get MaxAC
        if (!loadKeyInt(L, "MaxAC", config.baseAttrib.maxAC)) {
            //return false;
        }
        // Get AC
        if (!loadKeyInt(L, "AC", config.baseAttrib.AC)) {
            //return false;
        }
        // Get maxMAC
        if (!loadKeyInt(L, "MaxMAC", config.baseAttrib.maxMAC)) {
            //return false;
        }
        // Get MAC
        if (!loadKeyInt(L, "MAC", config.baseAttrib.MAC)) {
            //return false;
        }
        // Get MaxSC
        if (!loadKeyInt(L, "MaxSC", config.baseAttrib.maxSC)) {
            //return false;
        }
        // Get SC
        if (!loadKeyInt(L, "SC", config.baseAttrib.SC)) {
            //return false;
        }
        // Get MaxMC
        if (!loadKeyInt(L, "MaxMC", config.baseAttrib.maxMC)) {
            //return false;
        }
        // Get MC
        if (!loadKeyInt(L, "MC", config.baseAttrib.MC)) {
            //return false;
        }
        // Get MaxHP
        if (!loadKeyInt(L, "MaxHP", config.baseAttrib.maxHP)) {
            //return false;
        }
        // Get HP
        if (!loadKeyInt(L, "HP", config.baseAttrib.HP)) {
            //return false;
        }
        // Get MaxMP
        if (!loadKeyInt(L, "MaxMP", config.baseAttrib.maxMP)) {
            //return false;
        }
        // Get MP
        if (!loadKeyInt(L, "MP", config.baseAttrib.MP)) {
            //return false;
        }
        // Get MaxEXPR
        if (!loadKeyInt(L, "MaxEXPR", config.baseAttrib.maxEXPR)) {
            //return false;
        }
        // Get EXPR
        if (!loadKeyInt(L, "EXPR", config.baseAttrib.EXPR)) {
            //return false;
        }
        // Get Level
        if (!loadKeyInt(L, "Level", config.baseAttrib.level)) {
            //return false;
        }
        // Get Tex
        if (!loadKeyInt(L, "Tex", config.baseAttrib.tex)) {
            //return false;
        }
        // Get Price
        if (!loadKeyInt(L, "Price", config.baseAttrib.price)) {
            //return false;
        }
        // Get Desc
        if (!loadKeyString(L, "Desc", szDesc)) {
            //return false;
        }
        config.strDesc = szDesc;

        refAttribs.insert(std::make_pair(config.baseAttrib.id, config));
    }

    // pop the table
    lua_pop(L, 1);

    return true;
}

static bool loadMonsDropItems(lua_State *L, const char* pKeyName, MonsFullAttrib &ma) {
    bool bRet = true;
    // Top must be a table
    // Stack table
    lua_getfield(L, -1, pKeyName);
    if (!lua_istable(L, -1)) {
        lua_pop(L, 1);
        return false;
    }
    char buf[20] = {0};
    for (int i = 1; ;i++) {
        lua_pushnumber(L, i);
        lua_rawget(L, -2);
        if (!lua_istable(L, -1)) {
            lua_pop(L, 1);
            break;
        }
        // Read keys from top table
        // Stack: table table
        MonsDropItemInfo di;
        if (!LuaDataLoader::loadKeyString(L, "Item", buf)) {
            lua_pop(L, 1);
            bRet = false;
            break;
        }
        di.strItemName = buf;
        if (!LuaDataLoader::loadKeyInt(L, "Prob", di.nProb)) {
            lua_pop(L, 1);
            bRet = false;
            break;
        }
        // Push result
        ma.xDropItems.push_back(di);
        // Pop the table value
        lua_pop(L, 1);
    }
    // Pop the value table
    lua_pop(L, 1);
    return bRet;
}

bool LuaDataLoader::LoadMonsAttrib(lua_State* L, const char *pKeyName, std::map<int, MonsFullAttrib> &refMons) {
    LuaStackGuard guard(L);
    bool bRet = true;

    lua_getglobal(L, pKeyName);
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

    char szDesc[255];
    szDesc[0] = 0;

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

        MonsFullAttrib config;
        // get the id (value)
        config.baseAttrib.id = it.GetKeyInt();

        // now we get the config table , read all need fields
        // stack : bottom | table key value | top
        // Get name
        if (!loadKeyString(L, "Name", config.baseAttrib.name)) {
            return false;
        }
        // Get weight
        if (!loadKeyInt(L, "Weight", config.baseAttrib.weight)) {
            //return false;
        }
        // Get Type
        if (!loadKeyInt(L, "Type", config.baseAttrib.type)) {
            //return false;
        }
        // Get Lucky
        if (!loadKeyInt(L, "Lucky", config.baseAttrib.lucky)) {
            //return false;
        }
        // Get Curse
        if (!loadKeyInt(L, "Curse", config.baseAttrib.curse)) {
            //return false;
        }
        // Get Hide
        if (!loadKeyInt(L, "Hide", config.baseAttrib.hide)) {
            //return false;
        }
        // Get Accuracy
        if (!loadKeyInt(L, "Accuracy", config.baseAttrib.accuracy)) {
            //return false;
        }
        // Get AtkSpeed
        if (!loadKeyInt(L, "AtkSpeed", config.baseAttrib.atkSpeed)) {
            //return false;
        }
        // Get AtkPalsy
        if (!loadKeyInt(L, "AtkPalsy", config.baseAttrib.atkPalsy)) {
            //return false;
        }
        // Get AtkPois
        if (!loadKeyInt(L, "AtkPois", config.baseAttrib.atkPois)) {
            //return false;
        }
        // Get MoveSpeed
        if (!loadKeyInt(L, "MoveSpeed", config.baseAttrib.moveSpeed)) {
            //return false;
        }
        // Get ReqType
        if (!loadKeyInt(L, "ReqType", config.baseAttrib.reqType)) {
            //return false;
        }
        // Get ReqValue
        if (!loadKeyInt(L, "ReqValue", config.baseAttrib.reqValue)) {
            //return false;
        }
        // Get Sex
        if (!loadKeyInt(L, "Sex", config.baseAttrib.sex)) {
            //return false;
        }
        // Get MaxDC
        if (!loadKeyInt(L, "MaxDC", config.baseAttrib.maxDC)) {
            //return false;
        }
        // Get DC
        if (!loadKeyInt(L, "DC", config.baseAttrib.DC)) {
            //return false;
        }
        // Get MaxAC
        if (!loadKeyInt(L, "MaxAC", config.baseAttrib.maxAC)) {
            //return false;
        }
        // Get AC
        if (!loadKeyInt(L, "AC", config.baseAttrib.AC)) {
            //return false;
        }
        // Get maxMAC
        if (!loadKeyInt(L, "MaxMAC", config.baseAttrib.maxMAC)) {
            //return false;
        }
        // Get MAC
        if (!loadKeyInt(L, "MAC", config.baseAttrib.MAC)) {
            //return false;
        }
        // Get MaxSC
        if (!loadKeyInt(L, "MaxSC", config.baseAttrib.maxSC)) {
            //return false;
        }
        // Get SC
        if (!loadKeyInt(L, "SC", config.baseAttrib.SC)) {
            //return false;
        }
        // Get MaxMC
        if (!loadKeyInt(L, "MaxMC", config.baseAttrib.maxMC)) {
            //return false;
        }
        // Get MC
        if (!loadKeyInt(L, "MC", config.baseAttrib.MC)) {
            //return false;
        }
        // Get MaxHP
        if (!loadKeyInt(L, "MaxHP", config.baseAttrib.maxHP)) {
            //return false;
        }
        // Get HP
        if (!loadKeyInt(L, "HP", config.baseAttrib.HP)) {
            //return false;
        }
        // Get MaxMP
        if (!loadKeyInt(L, "MaxMP", config.baseAttrib.maxMP)) {
            //return false;
        }
        // Get MP
        if (!loadKeyInt(L, "MP", config.baseAttrib.MP)) {
            //return false;
        }
        // Get MaxEXPR
        if (!loadKeyInt(L, "MaxEXPR", config.baseAttrib.maxEXPR)) {
            //return false;
        }
        // Get EXPR
        if (!loadKeyInt(L, "EXPR", config.baseAttrib.EXPR)) {
            //return false;
        }
        // Get Level
        if (!loadKeyInt(L, "Level", config.baseAttrib.level)) {
            //return false;
        }
        // Get Tex
        if (!loadKeyInt(L, "Tex", config.baseAttrib.tex)) {
            //return false;
        }
        // Get Price
        if (!loadKeyInt(L, "Price", config.baseAttrib.price)) {
            //return false;
        }
        // Get Desc
        if (!loadKeyString(L, "Desc", szDesc)) {
            //return false;
        }
        // Get drop items
        if (!loadMonsDropItems(L, "DropItems", config)) {
            lua_pop(L, 2);
            bRet = false;
            break;
        }
        config.strDesc = szDesc;

        refMons.insert(std::make_pair(config.baseAttrib.id, config));
    }

    // pop the table
    lua_pop(L, 1);

    return bRet;
}

bool LuaDataLoader::LoadLifeSkill(lua_State *L, const char* pKeyName, LifeSkillInfo (&refSkills)[kLifeSkill_Total]) {
    LuaStackGuard guard(L);
    bool bRet = true;

    lua_getglobal(L, pKeyName);
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

    int nSkillCount = 0;
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
        
        int nSkillID = it.GetKeyInt();
        if (nSkillID >= sizeof(refSkills) / sizeof(refSkills[0])) {
            // Pop key and value
            lua_pop(L, 2);
            bRet = false;
            break;
        }
        LifeSkillInfo& si = refSkills[nSkillID];
        if (si.nMaxLevel != 0 || si.nSkillType != 0) {
            // Skill conflict
            // Pop key and value
            lua_pop(L, 2);
            bRet = false;
            break;
        }
        memset(&si, 0, sizeof(si));
        // get the skill type (as lua table key)
        si.nSkillType = it.GetKeyInt();
        // Get the skill exprs
        vector<int> exprs;
        if (!loadKeyIntArray(L, "exprs", exprs)) {
            // Pop key and value
            lua_pop(L, 2);
            bRet = false;
            break;
        }
        if (exprs.size() > sizeof(si.uExp) / sizeof(si.uExp[0])) {
            // Pop key and value
            lua_pop(L, 2);
            bRet = false;
            break;
        }
        for (int i = 0; i < exprs.size(); i++) {
            si.uExp[i] = exprs[i];
        }
        si.nMaxLevel = exprs.size() + 1;
        ++nSkillCount;
    }

    // pop the table
    lua_pop(L, 1);

    // Check skill all load
    for (int i = 0; i < nSkillCount; i++) {
        if (refSkills[i].nMaxLevel == 0) {
            return false;
        }
    }

    return bRet;
}

static bool loadMakeEquipMaterials(lua_State *L, const char* pKeyName, MakeEquipInfo &ei) {
    bool bRet = true;
    // Top must be a table
    // Stack table
    lua_getfield(L, -1, pKeyName);
    if (!lua_istable(L, -1)) {
        lua_pop(L, 1);
        return false;
    }
    for (int i = 1; ;i++) {
        if (i - 1 >= sizeof(ei.nMaterialsCount) / sizeof(ei.nMaterialsCount[0])) {
            bRet = false;
            break;
        }
        lua_pushnumber(L, i);
        lua_rawget(L, -2);
        if (!lua_istable(L, -1)) {
            lua_pop(L, 1);
            ei.nMaterialCount = i - 1;
            break;
        }
        // Read keys from top table
        // Stack: table table
        if (!LuaDataLoader::loadKeyInt(L, "id", ei.nMaterialsId[i - 1])) {
            lua_pop(L, 1);
            bRet = false;
            break;
        }
        if (!LuaDataLoader::loadKeyInt(L, "count", ei.nMaterialsCount[i - 1])) {
            lua_pop(L, 1);
            bRet = false;
            break;
        }
        // Pop the table value
        lua_pop(L, 1);
    }
    // Pop the value table
    lua_pop(L, 1);
    return bRet;
}

bool LuaDataLoader::LoadMakeEquip(lua_State *L, const char* pKeyName, MakeEquipInfoMap &refEquip) {
    LuaStackGuard guard(L);
    bool bRet = true;

    lua_getglobal(L, pKeyName);
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

    int nSkillCount = 0;
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

        MakeEquipInfo mi;
        memset(&mi, 0, sizeof(mi));
        mi.nItemId = it.GetKeyInt();
        // Read need level
        if (!loadKeyInt(L, "needLevel", mi.nNeedLevel)) {
            lua_pop(L, 2);
            bRet = false;
            break;
        }
        // Read needMoney
        if (!loadKeyInt(L, "needMoney", mi.nNeedMoney)) {
            lua_pop(L, 2);
            bRet = false;
            break;
        }
        // Read expr
        if (!loadKeyInt(L, "expr", mi.nExp)) {
            lua_pop(L, 2);
            bRet = false;
            break;
        }
        // Read materials
        if (!loadMakeEquipMaterials(L, "materials", mi)) {
            lua_pop(L, 2);
            bRet = false;
            break;
        }
        refEquip.insert(std::make_pair(mi.nItemId, mi));
    }

    // pop the table
    lua_pop(L, 1);

    return bRet;
}

static bool loadStoveAttribs(lua_State *L, const char* pKeyName, StoveAttribInfo &si) {
    bool bRet = true;
    // Top must be a table
    // Stack table
    lua_getfield(L, -1, pKeyName);
    if (!lua_istable(L, -1)) {
        lua_pop(L, 1);
        return false;
    }
    for (int i = 1; ;i++) {
        if (i - 1 >= sizeof(si.dwAttribs) / sizeof(si.dwAttribs[0])) {
            bRet = false;
            break;
        }
        lua_pushnumber(L, i);
        lua_rawget(L, -2);
        if (!lua_istable(L, -1)) {
            lua_pop(L, 1);
            si.nAttribCount = i - 1;
            break;
        }
        // Read keys from top table
        // Stack: table table
        int nId = 0;
        if (!LuaDataLoader::loadKeyInt(L, "id", nId)) {
            lua_pop(L, 1);
            bRet = false;
            break;
        }
        int nValue = 0;
        if (!LuaDataLoader::loadKeyInt(L, "value", nValue)) {
            lua_pop(L, 1);
            bRet = false;
            break;
        }
        if (0 == nId || 0 == nValue) {
            lua_pop(L, 1);
            bRet = false;
            break;
        }
        si.dwAttribs[i - 1] = MAKELONG(nId, nValue);
        // Pop the table value
        lua_pop(L, 1);
    }
    // Pop the value table
    lua_pop(L, 1);
    return bRet;
}

bool LuaDataLoader::LoadStoveAttrib(lua_State *L, const char* pKeyName, StoveAttribVector &refAttribs) {
    LuaStackGuard guard(L);
    bool bRet = true;

    lua_getglobal(L, pKeyName);
    if (!lua_istable(L, -1))
    {
        // LUA_TNIL
        lua_pop(L, 1);
        return false;
    }

    int nAttribCount = 0;
    for (int i = 1; ;i++)
    {
        lua_pushnumber(L, i);
        lua_rawget(L, -2);
        if (!lua_istable(L, -1)) {
            // Pop nil value
            lua_pop(L, 1);
            break;
        }

        StoveAttribInfo si;
        memset(&si, 0, sizeof(si));
        si.nAttribId = i - 1;
        // Read name
        if (!loadKeyString(L, "name", si.szName)) {
            lua_pop(L, 1);
            bRet = false;
            break;
        }
        // Read level
        if (!loadKeyInt(L, "level", si.nLevel)) {
            lua_pop(L, 1);
            bRet = false;
            break;
        }
        // Read expr
        vector<int> vals;
        if (!loadKeyIntArray(L, "types", vals)) {
            lua_pop(L, 1);
            bRet = false;
            break;
        }
        unsigned int uFlag = 0;
        for (int i = 0; i < vals.size(); i++) {
            uFlag |= (1 << vals[i]);
        }
        si.dwActiveItemType = uFlag;
        // Read attribs
        if (!loadStoveAttribs(L, "attribs", si)) {
            lua_pop(L, 1);
            bRet = false;
            break;
        }
        refAttribs.push_back(si);
        // Pop the value
        lua_pop(L, 1);
    }

    // pop the table
    lua_pop(L, 1);

    return bRet;
}

static bool loadSuitActives(lua_State *L, const char* pKeyName, ItemExtraAttribList &si) {
    bool bRet = true;
    // Top must be a table
    // Stack table
    lua_getfield(L, -1, pKeyName);
    if (!lua_istable(L, -1)) {
        lua_pop(L, 1);
        return false;
    }
    for (int i = 1; ;i++) {
        if (i - 1 >= sizeof(si.nActiveSum) / sizeof(si.nActiveSum[0])) {
            bRet = false;
            break;
        }
        lua_pushnumber(L, i);
        lua_rawget(L, -2);
        if (!lua_istable(L, -1)) {
            lua_pop(L, 1);
            break;
        }
        // Read keys from top table
        // Stack: table table
        if (!LuaDataLoader::loadKeyInt(L, "count", si.nActiveSum[i - 1])) {
            lua_pop(L, 1);
            bRet = false;
            break;
        }
        if (!LuaDataLoader::loadKeyInt(L, "active", si.nActiveAttribSum[i - 1])) {
            lua_pop(L, 1);
            bRet = false;
            break;
        }
        // Pop the table value
        lua_pop(L, 1);
    }
    // Pop the value table
    lua_pop(L, 1);
    return bRet;
}

static bool loadSuitAttribs(lua_State *L, const char* pKeyName, ItemExtraAttribList &si) {
    bool bRet = true;
    // Top must be a table
    // Stack table
    lua_getfield(L, -1, pKeyName);
    if (!lua_istable(L, -1)) {
        lua_pop(L, 1);
        return false;
    }
    for (int i = 1; ;i++) {
        if (i - 1 >= sizeof(si.stExtraAttrib) / sizeof(si.stExtraAttrib[0])) {
            bRet = false;
            break;
        }
        lua_pushnumber(L, i);
        lua_rawget(L, -2);
        if (!lua_istable(L, -1)) {
            lua_pop(L, 1);
            break;
        }
        // Read keys from top table
        // Stack: table table
        if (!LuaDataLoader::loadKeyInt(L, "id", si.stExtraAttrib[i - 1].nAttribID)) {
            lua_pop(L, 1);
            bRet = false;
            break;
        }
        if (!LuaDataLoader::loadKeyInt(L, "value", si.stExtraAttrib[i - 1].nAttribValue)) {
            lua_pop(L, 1);
            bRet = false;
            break;
        }
        // Pop the table value
        lua_pop(L, 1);
    }
    // Pop the value table
    lua_pop(L, 1);
    return bRet;
}

bool LuaDataLoader::LoadSuitAttrib(lua_State *L, const char* pKeyName, std::map<int, ItemExtraAttribList*> &refSuits) {
    LuaStackGuard guard(L);
    bool bRet = true;

    lua_getglobal(L, pKeyName);
    if (!lua_istable(L, -1))
    {
        // LUA_TNIL
        lua_pop(L, 1);
        return false;
    }

    int nAttribCount = 0;
    for (int i = 1; ;i++)
    {
        lua_pushnumber(L, i);
        lua_rawget(L, -2);
        if (!lua_istable(L, -1)) {
            // Pop nil value
            lua_pop(L, 1);
            break;
        }

        ItemExtraAttribList si;
        memset(&si, 0, sizeof(si));
        si.nSuitID = i;
        // Read name
        if (!loadKeyString(L, "name", si.szSuitChName)) {
            lua_pop(L, 1);
            bRet = false;
            break;
        }
        // Read level
        vector<int> vals;
        if (!loadKeyIntArray(L, "items", vals)) {
            lua_pop(L, 1);
            bRet = false;
            break;
        }
        if (vals.size() > sizeof(si.nSuitEquipID) / sizeof(si.nSuitEquipID[0])) {
            lua_pop(L, 1);
            bRet = false;
            break;
        }
        for (int i = 0; i < vals.size(); i++) {
            si.nSuitEquipID[i] = vals[i];
        }
        vals.clear();
        // Read actives
        if (!loadSuitActives(L, "actives", si)) {
            lua_pop(L, 1);
            bRet = false;
            break;
        }
        // Read attribs
        if (!loadSuitAttribs(L, "attribs", si)) {
            lua_pop(L, 1);
            bRet = false;
            break;
        }
        // Read look
        if (!loadKeyInt(L, "look", si.nSuitShowType)) {
            lua_pop(L, 1);
            bRet = false;
            break;
        }
        // Insert copy
        ItemExtraAttribList *pCopy = new ItemExtraAttribList;
        memcpy(pCopy, &si, sizeof(ItemExtraAttribList));
        refSuits.insert(std::make_pair(pCopy->nSuitID, pCopy));
        // Pop the value
        lua_pop(L, 1);
    }

    // pop the table
    lua_pop(L, 1);

    return bRet;
}