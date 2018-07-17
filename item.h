#ifndef _INC_ITEM_
#define _INC_ITEM_

#include <string>
#include <map>

struct ItemAttrib {
    char name[20];
    int id;
    char weight;
    char type;
    char lucky;
    char curse;
    char hide;
    char accuracy;
    char atkSpeed;
    char atkPalsy;
    char atkPois;
    char moveSpeed;
    char reqType;
    char reqValue;
    char sex;
    short maxDC;
    short DC;
    short maxAC;
    short AC;
    short maxMAC;
    short MAC;
    short maxSC;
    short SC;
    short maxMC;
    short MC;
    short maxHP;
    short HP;
    short maxMP;
    short MP;
    short maxEXPR;
    short EXPR;
    short level;
    short tex;
    short price;
};

struct ItemFullAttrib {
    ItemAttrib baseAttrib;
    int nGrade;
    std::string strDesc;

    ItemFullAttrib() {
        memset(&baseAttrib, 0, sizeof(baseAttrib));
        nGrade = 0;
    }
};

struct MonsDropItemInfo {
    std::string strItemName;
    int nItemId;
    int nProb;

    MonsDropItemInfo() {
        nItemId = 0;
        nProb = 0;
    }
};

typedef std::vector<MonsDropItemInfo> MonsDropItemInfoVec;

struct MonsFullAttrib {
    ItemAttrib baseAttrib;
    std::string strDesc;
    MonsDropItemInfoVec xDropItems;

    MonsFullAttrib() {
        memset(&baseAttrib, 0, sizeof(baseAttrib));
    }
};

struct RenderInfo {
    int id;
    int atkbegin;
    int atkframe;
    int atktotal;
    int deadbegin;
    int deadframe;
    int deadtotal;
    int hurtbegin;
    int hurtframe;
    int hurttotal;
    int magicbegin;
    int magicframe;
    int magicend;
    int standbegin;
    int standframe;
    int standtotal;
    int walkbegin;
    int walkframe;
    int walktotal;
    int atkeftbeginl;
    int atkeftframe;
    int atkefttotal;
    int drts;
    int index;
    int showbegin;
    int showframe;
    int sndindex;
};

enum LifeSkillType
{
    //	冶炼矿石
    kLifeSkill_SmeltOre = 0,
    kLifeSkill_SmeltWood,
    kLifeSkill_SmeltCloth,
    kLifeSkill_SmeltGem,
    kLifeSkill_SmeltEquip,
    kLifeSkill_Total,
};

struct LifeSkillInfo
{
    int nSkillType;
    int nMaxLevel;
    short uExp[15];
};

struct MakeEquipInfo
{
    int nItemId;
    int nNeedLevel;
    int nNeedMoney;
    int nExp;
    int nMaterialCount;
    int nMaterialsId[5];
    int nMaterialsCount[5];
};

typedef std::map<int, MakeEquipInfo> MakeEquipInfoMap;

#define MAX_STOVE_ATTRIB	6

struct StoveAttribInfo
{
    int nAttribId;
    int nLevel;
    int nAttribCount;
    char szName[20];
    unsigned int dwActiveItemType;
    unsigned int dwAttribs[MAX_STOVE_ATTRIB];
};
typedef std::vector<StoveAttribInfo> StoveAttribVector;

enum ExtraAttribID
{
	EAID_NONE,
	EAID_AC,
	EAID_MAC,
	EAID_DC,
	EAID_SC,
	EAID_MC,
	EAID_LUCKY,
	EAID_ATKSPEED,
	EAID_ACCURACY,
	EAID_MOVESPEED,
	EAID_MAGICITEM,
	EAID_MOUNTAIN,
	EAID_HURTTRANS,
	EAID_NEARPALSY,
	EAID_FARPALSY,
	EAID_MOVEPOS,
	EAID_STEALHP,
	EAID_SUCKDAMAGE,
	EAID_IGNOREAC,
	EAID_CRITICAL,
	EAID_CRITICALPEC,
	EAID_REVIVE,
	EAID_ADDLIEHUO,
	EAID_ADDICEROARADD,
	EAID_ADDSHENSHOU,
	EAID_ADDSLIEHUO,
	EAID_ADDSKYFIRE,
	EAID_ADDTIGER,
	EAID_CRITICALLIMIT,
	EAID_IGNOREDCDAM,
	EAID_IGNOREMCDAM,
	EAID_SUMMONWHITETIGER,
	EAID_DCDAMAGE,
	EAID_MCDAMAGE,
	EAID_SCDAMAGE,
	EAID_DCHIDE,
	EAID_MAGICHIDE,
	EAID_DCDEFENSE,
	EAID_MAGICDEFENSE,
	EAID_POISRECOVER,
	EAID_STONERECOVER,
	EAID_ADDHPSECOND,
	EAID_ADDMPSECOND,
	EAID_TOTAL
};

extern const char* g_szExtraAttribDescriptor[EAID_TOTAL];

#define MAX_EXTRAATTIRB 10
struct ItemExtraAttribItem
{
	int nAttribID;
	int nAttribValue;
};

/*
enum PLAYER_ITEM_TYPE
{
	PLAYER_ITEM_WEAPON,
	PLAYER_ITEM_CLOTH,
	PLAYER_ITEM_HELMET,
	PLAYER_ITEM_NECKLACE,
	PLAYER_ITEM_BRACELAT1,
	PLAYER_ITEM_BRACELAT2,
	PLAYER_ITEM_RING1,
	PLAYER_ITEM_RING2,
	PLAYER_ITEM_MEDAL,
	PLAYER_ITEM_BELT,
	PLAYER_ITEM_SHOE,
	PLAYER_ITEM_GEM,
	PLAYER_ITEM_CHARM,
	PLAYER_ITEM_TOTAL,
};*/

struct ItemExtraAttribList
{
	//	套装编号
	int nSuitID;
	//	套装名称 加过密
	char szSuitChName[20];
	//	套装效果显示 (0为套装效果 1为特殊效果) >1 都是潜能属性ID
	int nSuitShowType;
	//	套装中的每个物品
	int nSuitEquipID[10];
	//	套装中每个激活数量对应的激活属性数量 比如2件激活1个属性 3件激活2个属性
	int nActiveSum[10];
	int nActiveAttribSum[10];
	//	套装的属性 比如2件激活了一个属性 那么就激活了stExtraAttrib[0]
	ItemExtraAttribItem stExtraAttrib[MAX_EXTRAATTIRB];
};

extern std::map<int, ItemExtraAttribList*> g_xSuitExtraAttrib;

#endif
