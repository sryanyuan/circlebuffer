#ifndef _INC_CIRCLEBUFFER_
#define _INC_CIRCLEBUFFER_
//////////////////////////////////////////////////////////////////////////
template <class T>
class CircleBuffer
{
public:
	CircleBuffer()
	{
		m_pItems = NULL;
		Clear();
	}
	~CircleBuffer()
	{
		Clear();
	}

public:
	bool Init(int _nItemCount, int _nItemPerPage)
	{
		Clear();
		m_pItems = new T[_nItemCount];
		m_nBufferSize = _nItemCount;
		m_nItemPerPage = _nItemPerPage;
	}
	void Clear()
	{
		if(NULL != m_pItems)
		{
			delete[] m_pItems;
			m_pItems = NULL;
		}
		m_nTailPtr = 0;
		m_nBufferSize = 0;
		m_nCurPtr = 0;
		m_nItemPerPage = 0;
	}

	void AppendItem(T* _pItem)
	{
		int nNextPtr = m_nTail + 1;
		if(nNextPtr >= m_nBufferSize)
		{
			nNextPtr %= m_nBufferSize;
		}

		//	copy the content
		memcpy(&m_pItems[nNextPtr], _pItem, sizeof(T));

		//	update the tail ptr
		++m_nTailPtr;
	}

	T* GetNextItem()
	{
		int nNextPtr = m_nTailPtr + 1;
		if(nNextPtr >= m_nBufferSize)
		{
			nNextPtr %= m_nBufferSize;
		}

		return &m_pItems[nNextPtr];
	}
	const T* GetNextItem()
	{
		int nNextPtr = m_nTailPtr + 1;
		if(nNextPtr >= m_nBufferSize)
		{
			nNextPtr %= m_nBufferSize;
		}

		return &m_pItems[nNextPtr];
	}

	T* GetCurrentItem()
	{
		return &m_pItems[m_nTailPtr % m_nBufferSize];
	}
	const T* GetCurrentItem()
	{
		return &m_pItems[m_nTailPtr % m_nBufferSize];
	}

	T* GetItemFromTail(int _nTailOffset)
	{
		if(m_nTailPtr < m_nBufferSize)
		{
			//	normal
			int nIndex = m_nTailPtr + _nTailOffset;
			if(nIndex < 0)
			{
				return NULL;
			}

			return &m_pItems[nIndex];
		}
		else
		{
			//	reverse
			int nFinalIndex = m_nTailPtr % m_nBufferSize;
			int nIndex = nFinalIndex + _nTailOffset;

			if(nIndex >= 0)
			{
				return &m_pItems[nIndex];
			}
		}
	}

protected:
	T* m_pItems;
	int m_nTailPtr;
	int m_nBufferSize;
	int m_nCurPtr;
	int m_nItemPerPage;
};
//////////////////////////////////////////////////////////////////////////
#endif