#ifndef _INC_LUA_STACK_GUARD_
#define _INC_LUA_STACK_GUARD_

extern "C"
{
#include "lua.h"
};
#include <assert.h>

class LuaStackGuard
{
public:
    LuaStackGuard(lua_State* L) {
        m_L = L;
        m_nInitStackTop = lua_gettop(L);
    }
    ~LuaStackGuard() {
        int nCurrStack = lua_gettop(m_L);
        assert(m_nInitStackTop == nCurrStack);
    }

public:
    static void stackDump(lua_State *L) {
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

private:
    lua_State* m_L;
    int m_nInitStackTop;
};

#endif
