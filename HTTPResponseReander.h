#ifndef _INC_HTTPRESPONSEREADER_
#define _INC_HTTPRESPONSEREADER_
//////////////////////////////////////////////////////////////////////////
#include "include/json/json.h"
//////////////////////////////////////////////////////////////////////////
class HTTPRespnseReader
{
public:
	template <int _Size>
	static int Read(const char* _pData, int* _pCode, char (&_refArray) [_Size])
	{
		Json::Reader reader;
		Json::Value root;
		std::string respContent = _pData;
		if (!reader.parse(respContent, root))
		{
			return -1;
		}

		if (NULL != _pCode)
		{
			int nCode = root["code"].asInt();
			*_pCode = nCode;
		}
		const char* pszMsg = root["message"].asCString();
		if (strlen(pszMsg) + 1 > _Size)
		{
			// buffer overflow
			memcpy(_refArray, pszMsg, _Size - 1);
			_refArray[_Size - 1] = 0;
			return -2;
		}
		strcpy_s(_refArray, pszMsg);

		return 0;
	}
};
//////////////////////////////////////////////////////////////////////////
#endif