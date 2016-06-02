#ifndef _INC_GAMECHATHISTORYDLG_
#define _INC_GAMECHATHISTORYDLG_
//////////////////////////////////////////////////////////////////////////
#include <Windows.h>
#include "ChatDataModel.h"
//////////////////////////////////////////////////////////////////////////
#define CHAT_SHOW_LINE		4
#define MSGNODE_NORMAL				0
#define MSGNODE_PRIVAECHAT			1
#define MSGNODE_PUBLICCHAT			2
//////////////////////////////////////////////////////////////////////////
class GameChatHistoryEx
{
public:
	GameChatHistoryEx();
	virtual ~GameChatHistoryEx();

public:
	virtual void Render();
	virtual void Update(float _dt);
	virtual bool ProcUserCmd(const POINT& _mp);

public:
	void InsertChatMessage(const char* _pszMsg, DWORD _dwExtra = 0);
	void InsertChatMessage(const char* _pszName, const char* _pszMsg, DWORD _dwExtra = 0);
	void InsertMapSelfChatMessage(const char* _pszName, const char* _pszMsg, DWORD _dwExtra = 0);
	void InsertMapChatMessage(const char* _pszSender, const char* _pszMsg, DWORD _dwColor = 0);
	void InsertPrivateChatMessage(const char* _pszSender, const char* _pszMsg);
	void InsertPrivateSelfChatMessage(const char* _pszSender, const char* _pszMsg);
	void InsertPublicChatMessage(const char* _pszSender, const char* _pszMsg, DWORD _dwColor = 0);
	void ClearChatMessage();

	inline void SetDlgFocus(bool _bFocus)
	{
		/*if(_bFocus)
		{
			m_dwAlpha = GETFOCUS_ALPHA;
		}
		else
		{
			m_dwAlpha = LOSEFOCUS_ALPHA;
		}*/
	}

	void ScrollUp();
	void ScrollDown();
	void SetMaxSize(bool _b);

protected:
	void InsertRawMessage(const char* _pszSender, const char* _pszMsg, int _nNodeType, DWORD _dwExtra = 0);

private:
	RECT m_stRcScroll;
	RECT m_stRcUp;
	RECT m_stRcDown;
	DWORD m_dwAlpha;

	ChatDataModel m_xChatDataModel;
	ChatDataItem* m_pChatDataItems[CHAT_SHOW_LINE];
	int m_nShowIndex;
	int m_nInsertCount;

	//HTEXTURE m_hBk;
	bool m_bIsMaxSize;
};
//////////////////////////////////////////////////////////////////////////
#endif