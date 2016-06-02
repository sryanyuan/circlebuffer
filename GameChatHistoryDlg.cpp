#include "GameChatHistoryDlg.h"
//////////////////////////////////////////////////////////////////////////
GameChatHistoryEx::GameChatHistoryEx()
{
	m_nShowIndex = 0;
	m_nInsertCount = 0;
	//m_dwAlpha = LOSEFOCUS_ALPHA;
	//m_bVisible = true;
	m_bIsMaxSize = true;
	memset(m_pChatDataItems, 0, sizeof(m_pChatDataItems));

	/*m_rcClient.left = 230 + 15;
	m_rcClient.top = 450 + 60;
	m_rcClient.right = 486 + 15 + 100;
	m_rcClient.bottom = 450 + 60 + 145;*/

	/*m_hBk = GameScene::sThis->GetMainOpt()->GetResourceMgr()->GetTexture("bmcolor");
	m_pRender = new hgeSprite(m_hBk, 0, 0, m_rcClient.right - m_rcClient.left,
		m_rcClient.bottom - m_rcClient.top);*/
}

GameChatHistoryEx::~GameChatHistoryEx()
{
	//SAFE_DELETE(m_pRender);
}

//////////////////////////////////////////////////////////////////////////
void GameChatHistoryEx::Render()
{
	/*if(!m_pRender)
	{
		return;
	}
	if(!IsVisible())
	{
		return;
	}

	hgeResourceManager* pResMgr = pTheGame->GetGameRes();
	HTEXTURE tex = 0;*/

	//	back ground

	for(int i = 0; i < CHAT_SHOW_LINE; ++i)
	{
		ChatDataItem* pItem = m_pChatDataItems[i];
		if(NULL == pItem)
		{
			break;
		}
		if(pItem->szMsg[0] == 0)
		{
			break;
		}

		//	render text
		DWORD dwUseColor = pItem->dwExtraMsg;
		/*AfxGetPrinter()->SetColor(dwUseColor);

		AfxGetPrinter()->PrintWithoutStroke(m_rcClient.left + 5,
			m_rcClient.top + 5 + i * 13,
			pItem->szMsg);*/
	}
}

void GameChatHistoryEx::Update(float _dt)
{

}

bool GameChatHistoryEx::ProcUserCmd(const POINT& _mp)
{
	/*if(!PtInRect(&GetRect(),_mp))
	{
		return false;
	}*/

	/*int nLine = (_mp.y - m_rcClient.top - 5) / 13;
	if(nLine >= 0 &&
		nLine < CHAT_SHOW_LINE)
	{
		if(AfxGetHge()->Input_KeyUp(HGEK_RBUTTON))
		{
			ChatDataItem* pNode = m_pChatDataItems[nLine];
			if((pNode->nNodeType == MSGNODE_PRIVAECHAT || pNode->nNodeType == MSGNODE_PUBLICCHAT) &&
				pNode->szSender[0] != 0)
			{
				GameMainOptUI::GetInstance()->GetChatDlg()->GetEdit()->GainFocus();
				GameMainOptUI::GetInstance()->GetChatDlg()->GetEdit()->ClearText();
				GameMainOptUI::GetInstance()->GetChatDlg()->GetEdit()->SetText("/");
				GameMainOptUI::GetInstance()->GetChatDlg()->GetEdit()->SetText(pNode->szSender);
				GameMainOptUI::GetInstance()->GetChatDlg()->GetEdit()->SetText(" ");
				GameMainOptUI::GetInstance()->GetChatDlg()->GetEdit()->SetVisible(true);
			}
		}
	}*/
	return true;
}

void GameChatHistoryEx::ScrollUp()
{
	m_xChatDataModel.ScrollUp();
}

void GameChatHistoryEx::SetMaxSize(bool _b)
{
	
}

void GameChatHistoryEx::ScrollDown()
{
	m_xChatDataModel.ScrollDown();
}

void GameChatHistoryEx::InsertPrivateSelfChatMessage(const char* _pszSender, const char* _pszMsg)
{
	InsertRawMessage(_pszSender, _pszMsg, MSGNODE_PRIVAECHAT, COLOR_PRIVATECHAT);
}

void GameChatHistoryEx::InsertPrivateChatMessage(const char* _pszSender, const char* _pszMsg)
{
	InsertRawMessage(_pszSender, _pszMsg, MSGNODE_PRIVAECHAT, COLOR_PRIVATECHAT);
}

void GameChatHistoryEx::InsertPublicChatMessage(const char* _pszSender, const char* _pszMsg, DWORD _dwColor /* = 0 */)
{
	InsertRawMessage(_pszSender, _pszMsg, MSGNODE_PUBLICCHAT, _dwColor);
}

void GameChatHistoryEx::InsertChatMessage(const char* _pszMsg, DWORD _dwExtra /* = 0 */)
{
	InsertRawMessage(NULL, _pszMsg, MSGNODE_NORMAL, _dwExtra);
}

void GameChatHistoryEx::InsertChatMessage(const char* _pszName, const char* _pszMsg, DWORD _dwExtra /* = 0 */)
{
	if(strlen(_pszName) + strlen(_pszMsg) >= CHAT_MESSAGE_LENGTH)
	{
		return;
	}

	char szText[CHAT_MESSAGE_LENGTH] = {0};
	sprintf(szText, "%s :%s", _pszName, _pszMsg);
	InsertRawMessage(NULL, szText, MSGNODE_NORMAL, _dwExtra);
}

void GameChatHistoryEx::InsertMapSelfChatMessage(const char* _pszName, const char* _pszMsg, DWORD _dwExtra/* = 0*/)
{
	if(strlen(_pszName) + strlen(_pszMsg) >= CHAT_MESSAGE_LENGTH)
	{
		return;
	}

	char szText[CHAT_MESSAGE_LENGTH] = {0};
	sprintf(szText, "[地图]%s说:%s", _pszName, _pszMsg);
	InsertRawMessage(NULL, szText, MSGNODE_NORMAL, _dwExtra);
}

void GameChatHistoryEx::InsertMapChatMessage(const char* _pszSender, const char* _pszMsg, DWORD _dwColor/* = 0*/)
{
	if(strlen(_pszSender) + strlen(_pszMsg) >= CHAT_MESSAGE_LENGTH)
	{
		return;
	}

	char szText[CHAT_MESSAGE_LENGTH] = {0};
	sprintf(szText, "[地图]%s说:%s", _pszSender, _pszMsg);
	InsertRawMessage(_pszSender, szText, MSGNODE_PUBLICCHAT, _dwColor);
}

void GameChatHistoryEx::ClearChatMessage()
{

}

void GameChatHistoryEx::InsertRawMessage(const char *_pszSender, const char *_pszMsg, int _nNodeType, DWORD _dwExtra /*= 0*/)
{
	if(NULL == _pszMsg)
	{
		return;
	}

	if(_nNodeType != MSGNODE_NORMAL &&
		_nNodeType != MSGNODE_PRIVAECHAT &&
		_nNodeType != MSGNODE_PUBLICCHAT)
	{
		return;
	}

	if(_nNodeType == MSGNODE_NORMAL ||
		_nNodeType == MSGNODE_PUBLICCHAT)
	{
		//	nothing
	}
	else if(_nNodeType == MSGNODE_PRIVAECHAT)
	{
		if(NULL == _pszSender)
		{
			return;
		}
	}

	if(strlen(_pszMsg) >= CHAT_MESSAGE_LENGTH)
	{
		return;
	}
	if(NULL != _pszSender)
	{
		if(strlen(_pszSender) > 19)
		{
			return;
		}
	}

	StringList xStrings;
	int nLines = SplitTextWithLength(_pszMsg, 12, TEXT_WIDTH, xStrings);

	if(0 == nLines)
	{
		return;
	}

	for(StringList::iterator begIter = xStrings.begin();
		begIter != xStrings.end();
		++begIter)
	{
		//	add one item
		string& refStringItem = *begIter;
		ChatDataItem* pNewItem = m_xChatDataModel.AddChatDataItem(refStringItem.c_str());

		//	sender
		if(NULL != _pszSender)
		{
			strcpy(pNewItem->szSender, _pszSender);
		}
		else
		{
			pNewItem->szSender[0] = 0;
		}
		
		pNewItem->dwExtraMsg = _dwExtra;
		pNewItem->nNodeType = _nNodeType;

		if(_nNodeType == MSGNODE_PRIVAECHAT)
		{
			pNewItem->dwExtraMsg = COLOR_PRIVATECHAT;
		}
	}
}