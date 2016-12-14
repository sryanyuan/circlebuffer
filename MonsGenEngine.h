#ifndef _INC_MONSGENENGINE_
#define _INC_MONSGENENGINE_
//////////////////////////////////////////////////////////////////////////
#include <list>
#include <map>
#include "fastdelegate.h"
#include "FastDelegateBind.h"
//////////////////////////////////////////////////////////////////////////
typedef fastdelegate::FastDelegate3<int, int, int, int> GenMonsCallback;
//////////////////////////////////////////////////////////////////////////
struct MonsGenRecord
{
	int nMonsID;
	int nCount;
	int nPosX;
	int nPosY;
	int nOffset;

	// private fields
	int nRecordID;

	MonsGenRecord()
	{
		nRecordID = 0;
		nMonsID = 0;
		nCount = 0;
		nPosX = nPosY = nOffset = 0;
	}
};
typedef std::list<MonsGenRecord*> MonsGenRecordList;
typedef std::map<int, int> MonsGenCountMap;

class MonsGenEngine
{
public:
	MonsGenEngine();
	~MonsGenEngine();

public:
	int Insert(const MonsGenRecord* _pRecord);
	void Clear();
	int DeleteByMonsID(int _nMonsID);
	int DeleteByRecordID(int _nRecordID);

	int DoGen(const MonsGenCountMap& _refCurrentMonsCount);

	void SetGenMonsCallback(GenMonsCallback _cb)			{m_cbGenMons = _cb;}

private:
	int GenWithRecord(int _nExistsCount, const MonsGenRecord* _pRecord);
	int GetMonsGenCountMapValue(const MonsGenCountMap& _refMap, int _nKey);
	void IncMonsGenCountMapValue(MonsGenCountMap& _refMap, int _nKey, int _nInc);

private:
	MonsGenRecordList m_xMonsGenRecords;
	MonsGenCountMap m_xMonsGenTotalMap;
	GenMonsCallback m_cbGenMons;
	// for gen balance
	int m_nGenCount;
};
//////////////////////////////////////////////////////////////////////////
#endif