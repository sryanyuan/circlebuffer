#include "SkillHistory.h"

SkillHistory::SkillHistory() {

}

SkillHistory::~SkillHistory() {

}

void SkillHistory::AddHistory(int nSkillID, unsigned int utm) {
    std::map<int, unsigned int>::iterator it = m_xSkillHistroy.find(nSkillID);
    if (it == m_xSkillHistroy.end()) {
        m_xSkillHistroy.insert(std::make_pair(nSkillID, utm));
    } else {
        it->second = utm = utm;
    }
}

unsigned int SkillHistory::GetPreviousTm(int nSkillID) {
    std::map<int, unsigned int>::const_iterator it = m_xSkillHistroy.find(nSkillID);
    if (it == m_xSkillHistroy.end()) {
        return 0;
    }
    return it->second;
}
