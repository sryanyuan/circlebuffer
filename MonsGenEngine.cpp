#include "MonsGenEngine.h"
//////////////////////////////////////////////////////////////////////////
static int s_nMonsGenRecordIDSeed = 0;
//////////////////////////////////////////////////////////////////////////
MonsGenEngine::MonsGenEngine()
{
	m_nGenCount = 0;
}

MonsGenEngine::~MonsGenEngine()
{
	Clear();
}

int MonsGenEngine::Insert(const MonsGenRecord* _pRecord)
{
	if (0 == _pRecord->nMonsID ||
		0 == _pRecord->nOffset)
	{
		// invalid record
		return 0;
	}
	MonsGenRecord* pRecord = new MonsGenRecord;
	memcpy(pRecord, _pRecord, sizeof(MonsGenRecord));
	pRecord->nRecordID = ++s_nMonsGenRecordIDSeed;
	m_xMonsGenRecords.push_back(pRecord);
	// update total mons count
	MonsGenCountMap::iterator fndIter = m_xMonsGenTotalMap.find(pRecord->nMonsID);
	if (fndIter != m_xMonsGenTotalMap.end())
	{
		// update previous value
		fndIter->second += pRecord->nCount;
	}
	else
	{
		// new record
		m_xMonsGenTotalMap.insert(std::make_pair(pRecord->nMonsID, pRecord->nCount));
	}
	return pRecord->nRecordID;
}

int MonsGenEngine::DeleteByMonsID(int _nMonsID)
{
	MonsGenRecordList::iterator it = m_xMonsGenRecords.begin();
	int nRemoveCount = 0;

	for (it;
		it != m_xMonsGenRecords.end();
		)
	{
		MonsGenRecord* pRecord = *it;
		if (pRecord->nMonsID == _nMonsID)
		{
			delete pRecord;
			pRecord = NULL;
			it = m_xMonsGenRecords.erase(it);
			++nRemoveCount;
		}
		else
		{
			++it;
		}
	}

	return nRemoveCount;
}

int MonsGenEngine::DeleteByRecordID(int _nRecordID)
{
	MonsGenRecordList::iterator it = m_xMonsGenRecords.begin();
	int nRemoveCount = 0;

	for (it;
		it != m_xMonsGenRecords.end();
		)
	{
		MonsGenRecord* pRecord = *it;
		if (pRecord->nRecordID == _nRecordID)
		{
			delete pRecord;
			pRecord = NULL;
			return 1;
		}
		else
		{
			++it;
		}
	}

	return 0;
}

void MonsGenEngine::Clear()
{
	MonsGenRecordList::iterator it = m_xMonsGenRecords.begin();
	for (it;
		it != m_xMonsGenRecords.end();
		++it)
	{
		MonsGenRecord* pRecord = *it;
		delete pRecord;
		pRecord = NULL;
	}
	m_xMonsGenRecords.clear();
}

int MonsGenEngine::DoGen(const MonsGenCountMap& _refCurrentMonsCount)
{
	int nTotalGenCount = 0;
	MonsGenCountMap xCurrentGenCountMap;
	++m_nGenCount;

	if (m_nGenCount % 2 == 0)
	{
		// forward
		MonsGenRecordList::const_iterator it = m_xMonsGenRecords.begin();
		for (it;
			it != m_xMonsGenRecords.end();
			++it)
		{
			const MonsGenRecord* pRecord = *it;

			// gen mons
			int nMonsExistsCount = 0;
			// find in already exists map
			MonsGenCountMap::const_iterator existsIter = _refCurrentMonsCount.find(pRecord->nMonsID);
			if (existsIter != _refCurrentMonsCount.end())
			{
				nMonsExistsCount += existsIter->second;
			}
			// find in gen map
			MonsGenCountMap::const_iterator genIter = xCurrentGenCountMap.find(pRecord->nMonsID);
			if (genIter != xCurrentGenCountMap.end())
			{
				nMonsExistsCount += genIter->second;
			}

			// gen monster
			int nFinalGenCount = GenWithRecord(nMonsExistsCount, pRecord);
			if (0 != nFinalGenCount)
			{
				// record the gen count
				MonsGenCountMap::iterator finalGenIter = xCurrentGenCountMap.find(pRecord->nMonsID);
				if (finalGenIter != xCurrentGenCountMap.end())
				{
					finalGenIter->second += nFinalGenCount;
				}
				else
				{
					xCurrentGenCountMap.insert(std::make_pair(pRecord->nMonsID, nFinalGenCount));
				}
				nTotalGenCount += nFinalGenCount;
			}
		}
	}
	else
	{
		// backward
		MonsGenRecordList::const_reverse_iterator it = m_xMonsGenRecords.rbegin();
		for (it;
			it != m_xMonsGenRecords.rend();
			++it)
		{
			const MonsGenRecord* pRecord = *it;

			// gen mons
			int nMonsExistsCount = 0;
			// find in already exists map
			MonsGenCountMap::const_iterator existsIter = _refCurrentMonsCount.find(pRecord->nMonsID);
			if (existsIter != _refCurrentMonsCount.end())
			{
				nMonsExistsCount += existsIter->second;
			}
			// find in gen map
			MonsGenCountMap::const_iterator genIter = xCurrentGenCountMap.find(pRecord->nMonsID);
			if (genIter != xCurrentGenCountMap.end())
			{
				nMonsExistsCount += genIter->second;
			}

			// gen monster
			int nFinalGenCount = GenWithRecord(nMonsExistsCount, pRecord);
			if (0 != nFinalGenCount)
			{
				// record the gen count
				MonsGenCountMap::iterator finalGenIter = xCurrentGenCountMap.find(pRecord->nMonsID);
				if (finalGenIter != xCurrentGenCountMap.end())
				{
					finalGenIter->second += nFinalGenCount;
				}
				else
				{
					xCurrentGenCountMap.insert(std::make_pair(pRecord->nMonsID, nFinalGenCount));
				}
				nTotalGenCount += nFinalGenCount;
			}
		}
	}

	return nTotalGenCount;
}

int MonsGenEngine::GenWithRecord(int _nExistsCount, const MonsGenRecord* _pRecord)
{
	// gen mons
	int nCanGenMonsCount = 0;
	int nMonsExistsCount = _nExistsCount;
	int nTotalCanGenCount = 0;
	int nTotalGenCount = 0;
	// find total count
	MonsGenCountMap::const_iterator totalIter = m_xMonsGenTotalMap.find(_pRecord->nMonsID);
	if (totalIter != m_xMonsGenTotalMap.end())
	{
		nTotalCanGenCount = totalIter->second;
	}

	nCanGenMonsCount = nTotalCanGenCount - nMonsExistsCount;
	if (nCanGenMonsCount <= 0)
	{
		// mons count over limit
		return 0;
	}
	if (nCanGenMonsCount > _pRecord->nCount)
	{
		nCanGenMonsCount = _pRecord->nCount;
	}

	// gen monster
	int nFinalGenCount = 0;
	for (int i = 0; i < nCanGenMonsCount; ++i)
	{
		int nGenPosX = _pRecord->nPosX - _pRecord->nOffset + 2 * (rand() % (_pRecord->nOffset + 1));
		int nGenPosY = _pRecord->nPosY - _pRecord->nOffset + 2 * (rand() % (_pRecord->nOffset + 1));

		if (m_cbGenMons)
		{
			if (0 != m_cbGenMons(_pRecord->nMonsID, nGenPosX, nGenPosY))
			{
				++nFinalGenCount;
			}
		}
	}
	return nFinalGenCount;
}