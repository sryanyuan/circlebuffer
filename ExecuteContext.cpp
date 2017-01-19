#include "ExecuteContext.h"
#include <Windows.h>
//////////////////////////////////////////////////////////////////////////
int CExecuteUpdate(CExecuteContext* _pCtx)
{
	// check switch frame
	bool bEnterFirstFrame = false;
	if (0xffffffff == _pCtx->uLastUpdateTime)
	{
		// first frame
		_pCtx->uLastUpdateTime = GetTickCount();
		bEnterFirstFrame = true;
	}

	DWORD dwTick = GetTickCount();
	if (dwTick - _pCtx->uLastUpdateTime < _pCtx->uFrmIntervalMS &&
		!bEnterFirstFrame)
	{
		// nothing
		return EXECUTERESULT_DOING;
	}

	// first frame do not need to switch frame
	if (!bEnterFirstFrame)
	{
		int nNextFrm = _pCtx->nCurrentFrm + 1;
		if (nNextFrm >= _pCtx->nFrmTotal)
		{
			// last frame , done
			_pCtx->nCurrentFrm = 0;
			_pCtx->uLastUpdateTime = 0xffffffff;
		}
		else
		{
			_pCtx->nCurrentFrm = nNextFrm;
			_pCtx->uLastUpdateTime = dwTick;
		}
	}

	// check eff trigger
	if (0xffffffff != _pCtx->uLastUpdateTime)
	{
		if (_pCtx->nCurrentFrm == _pCtx->nFrmTriggerFrm)
		{
			// trigger the eff
			if (0 != _pCtx->nFrmTriggerEffID)
			{

			}
			else if (0 != _pCtx->nFrmTriggerStart)
			{
				// new eff
			}
		}
	}

	return _pCtx->uLastUpdateTime == 0xffffffff ? EXECUTERESULT_DONE : EXECUTERESULT_DOING;
}

void CRenderUpdate(const CExecuteContext* _pCtx)
{
	// calc the frame with direction info
	int nDrt = 0;
	int nRenderFrame = _pCtx->nFrmStart + _pCtx->nFrmTotal * nDrt + _pCtx->nCurrentFrm;

	// render the frame

	// if in transparent mode , draw effect
	if (0 != _pCtx->nEffStart)
	{
		// ignore some frame
		if (_pCtx->nCurrentFrm >= _pCtx->nEffIgnore)
		{
			// draw eff
			int nEffFrame = _pCtx->nEffStart + _pCtx->nEffTotal * nDrt + _pCtx->nCurrentFrm;
		}
	}

	// draw eff with offset
	if (0 != _pCtx->nEffOffset)
	{
		int nEffFrame = nRenderFrame + _pCtx->nEffOffset;
	}
}