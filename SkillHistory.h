#ifndef _INC_SKILL_HISTORY_
#define _INC_SKILL_HISTORY_

#include <map>

struct MagicInfo
{
    short wID;
    short wLevel[7];
    char bJob;
    char bMultiple;
    short wIncrease;
    char bBaseCost;
    unsigned int dwDelay;
};

class SkillHistory {
public:
    SkillHistory();
    ~SkillHistory();

public:
    void AddHistory(int nSkillID, unsigned int utm);
    unsigned int GetPreviousTm(int nSkillID);

private:
    std::map<int, unsigned int> m_xSkillHistroy;
};

#endif
