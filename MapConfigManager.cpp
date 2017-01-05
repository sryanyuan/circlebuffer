#include "MapConfigManager.h"

MapConfigManager::MapConfigManager()
{

}

MapConfigManager::~MapConfigManager()
{

}


bool MapConfigManager::Init(lua_State* L)
{
	if (!LuaConfigLoader::LoadMapInfo(L, LUA_CONFIGKEY_MAPINFO, m_xMapInfoVector))
	{
		return false;
	}

	std::vector<std::string> xFixedMapNames;
	if (!LuaConfigLoader::LoadFixedMaps(L, LUA_CONFIGKEY_FIXEDMAPS, xFixedMapNames))
	{
		return false;
	}

	// switch names to res id
	m_xFixedMapIDVector.resize(xFixedMapNames.size());

	for (size_t i = 0; i < xFixedMapNames.size(); ++i)
	{
		int nResID = -1;

		for (size_t j = 0; j < m_xMapInfoVector.size(); ++j)
		{
			if (xFixedMapNames[i] == m_xMapInfoVector[j].szMapResFile)
			{
				nResID = j;
				break;
			}
		}

		if (-1 == nResID)
		{
			return false;
		}
		m_xFixedMapIDVector[i] = nResID;
	}

	return true;
}

const LuaMapInfo* MapConfigManager::GetLuaMapInfo(int _nMapResID)
{
	if (_nMapResID < 0 ||
		_nMapResID >= int(m_xMapInfoVector.size()))
	{
		return NULL;
	}
	return &m_xMapInfoVector[_nMapResID];
}

const std::vector<int>& MapConfigManager::GetFixedMaps()
{
	return m_xFixedMapIDVector;
}