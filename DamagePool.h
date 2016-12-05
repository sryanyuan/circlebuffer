#ifndef _INC_DAMAGEPOOL_
#define _INC_DAMAGEPOOL_
//////////////////////////////////////////////////////////////////////////
#include <map>
#include <vector>

// accumulated damage info
struct AccumulatedInfo
{
	time_t nLastActiveTime;
	int nAccumulatedValue;
	int nUid;
};
typedef std::map<int, AccumulatedInfo> AccumulatedInfoMap;

typedef std::vector<AccumulatedInfo> AccumulatedInfoResults;

// sorter
bool SortAccumulatedInfoGreater(const AccumulatedInfo& _refLeft, const AccumulatedInfo& _refRight);

class DamagePool
{
public:
	DamagePool();
	~DamagePool();

public:
	void Insert(int _nUid, int _nValue);
	void GetSortedAccumulatedInfo(AccumulatedInfoResults& _refResults);
	void Clear();
	const AccumulatedInfoMap& GetAccumulatedInfoMap() {return m_xAccumulatedInfoMap;}

protected:
	AccumulatedInfoMap m_xAccumulatedInfoMap;
	int m_nExpireTime;
};
//////////////////////////////////////////////////////////////////////////
#endif