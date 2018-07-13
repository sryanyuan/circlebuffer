#include "LuaItemAttribLoader.h"
extern "C"
{
#include "lua.h"
};
#include "LuaIterator.h"
#include "item.h"

bool LuaItemAttribLoader::loadKeyString(lua_State *L, const char *pKeyName, char *pBuf) {
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

bool LuaItemAttribLoader::loadKeyInt(lua_State *L, const char *pKeyName, int &refValue) {
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

bool LuaItemAttribLoader::loadKeyInt(lua_State *L, const char *pKeyName, char &refValue) {
    int value;
    if (!loadKeyInt(L, pKeyName, value)) {
        return false;
    }
    refValue = (char)value;
    return true;
}

bool LuaItemAttribLoader::loadKeyInt(lua_State *L, const char *pKeyName, short &refValue) {
    int value;
    if (!loadKeyInt(L, pKeyName, value)) {
        return false;
    }
    refValue = (short)value;
    return true;
}

bool LuaItemAttribLoader::LoadItemAttrib(lua_State* L, const char *pKeyName, std::map<int, ItemFullAttrib> &refAttribs) {
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
        memset(&config, 0, sizeof(config));
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
        if (!loadKeyInt(L, "moveSpeed", config.baseAttrib.moveSpeed)) {
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
