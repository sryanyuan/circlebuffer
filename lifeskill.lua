-- items constant attribute
config_constLifeSKill = {
	-- ұ����ʯ:
	[0] =
	{
		exprs = {20, 50, 150, 600, 1200}
	},
	-- ұ��ľ��:
	[1] =
	{
		exprs = {20, 50, 150, 600, 1200}
	},
	-- ұ������:
	[2] =
	{
		exprs = {20, 50, 150, 600, 1200}
	},
	-- ұ����ʯ:
	[3] =
	{
		exprs = {20, 50, 150, 600, 1200}
	},
	-- ұ��װ��:
	[4] =
	{
		exprs = {5, 10, 20, 50, 100, 500, 1000, 1600, 2500}
	}
}

config_constMakeEquip = {
	-- ֮ͭ����
	[1020] = {
		needLevel = 1,
		needMoney = 2000,
		expr = 2,
		materials = {
			{
				id = 353,
				count = 3
			}
		}
	},
	-- ��֮����
	[1046] = {
		needLevel = 1,
		needMoney = 4000,
		expr = 3,
		materials = {
			{
				id = 350,
				count = 3
			},
			{
				id = 353,
				count = 2
			}
		}
	},
	-- ��֮����
	[1084] = {
		needLevel = 2,
		needMoney = 6000,
		expr = 4,
		materials = {
			{
				id = 352,
				count = 3
			},
			{
				id = 350,
				count = 2
			}
		}
	},
	-- ��֮����
	[1089] = {
		needLevel = 4,
		needMoney = 8000,
		expr = 5,
		materials = {
			{
				id = 349,
				count = 3
			},
			{
				id = 352,
				count = 2
			}
		}
	},
	-- ��������
	[1163] = {
		needLevel = 6,
		needMoney = 15000,
		expr = 7,
		materials = {
			{
				id = 351,
				count = 4
			},
			{
				id = 349,
				count = 3
			}
		}
	},
	-- �Ͻ𻤷�
	[1164] = {
		needLevel = 7,
		needMoney = 25000,
		expr = 9,
		materials = {
			{
				id = 354,
				count = 4
			},
			{
				id = 351,
				count = 3
			},
			{
				id = 349,
				count = 2
			}
		}
	},
	-- ħѪ��
	[1405] = {
		needLevel = 7,
		needMoney = 1000000,
		expr = 15,
		materials = {
			{
				id = 1266,
				count = 1
			},
			{
				id = 1420,
				count = 1
			},
			{
				id = 354,
				count = 4
			},
			{
				id = 351,
				count = 4
			}
		}
	},
	-- ��Ѫ��
	[1406] = {
		needLevel = 7,
		needMoney = 1000000,
		expr = 15,
		materials = {
			{
				id = 1268,
				count = 1
			},
			{
				id = 1421,
				count = 1
			},
			{
				id = 354,
				count = 4
			},
			{
				id = 351,
				count = 4
			}
		}
	},
	-- ��Ѫǹ
	[1407] = {
		needLevel = 7,
		needMoney = 1000000,
		expr = 15,
		materials = {
			{
				id = 1267,
				count = 1
			},
			{
				id = 1410,
				count = 1
			},
			{
				id = 354,
				count = 4
			},
			{
				id = 351,
				count = 4
			}
		}
	},
	-- ��ľѫ��
	[389] = {
		needLevel = 1,
		needMoney = 2000,
		expr = 2,
		materials = {
			{
				id = 356,
				count = 3
			},
			{
				id = 358,
				count = 2
			}
		}
	},
	-- ��ľѫ��
	[861] = {
		needLevel = 3,
		needMoney = 20000,
		expr = 4,
		materials = {
			{
				id = 360,
				count = 3
			},
			{
				id = 362,
				count = 2
			}
		}
	},
	-- ��̴ѫ��
	[862] = {
		needLevel = 6,
		needMoney = 40000,
		expr = 9,
		materials = {
			{
				id = 364,
				count = 3
			},
			{
				id = 366,
				count = 3
			}
		}
	},
	-- ����� սʿ
	[727] = {
		needLevel = 7,
		needMoney = 1000000,
		expr = 15,
		materials = {
			{
				id = 737,
				count = 1
			},
			{
				id = 366,
				count = 3
			},
			{
				id = 364,
				count = 3
			},
			{
				id = 864,
				count = 3
			}
		}
	},
	-- ����� ��ʦ
	[728] = {
		needLevel = 7,
		needMoney = 1000000,
		expr = 15,
		materials = {
			{
				id = 738,
				count = 1
			},
			{
				id = 366,
				count = 3
			},
			{
				id = 364,
				count = 3
			},
			{
				id = 866,
				count = 3
			}
		}
	},
	-- ����� ��ʿ
	[729] = {
		needLevel = 7,
		needMoney = 1000000,
		expr = 15,
		materials = {
			{
				id = 739,
				count = 1
			},
			{
				id = 366,
				count = 3
			},
			{
				id = 364,
				count = 3
			},
			{
				id = 865,
				count = 3
			}
		}
	},
	-- �Ϲ�ͷ
	[1085] = {
		needLevel = 5,
		needMoney = 50000,
		expr = 5,
		materials = {
			{
				id = 853,
				count = 3
			},
			{
				id = 362,
				count = 3
			},
			{
				id = 349,
				count = 3
			}
		}
	},
}

config_constStoveAttrib = {
	-- 0 = ����|1|2,6,7,14,15|2,20
	{
		name = "����",
		level = 1,
		types = {2, 6, 7, 14, 15},
		attribs = {
			{id = 2, value = 20},
		}
	},
	-- 1 = ����|2|2,6,7,14,15|2,40
	{
		name = "����",
		level = 2,
		types = {2, 6, 7, 14, 15},
		attribs = {
			{id = 2, value = 40},
		}
	},
	-- 2 = ����|3|2,6,7,14,15|2,60
	{
		name = "����",
		level = 3,
		types = {2, 6, 7, 14, 15},
		attribs = {
			{id = 2, value = 60},
		}
	},
	-- 3 = ����|1|3,4,5,7,16,17|1,20
	{
		name = "����",
		level = 1,
		types = {3, 4, 5, 7, 16, 17},
		attribs = {
			{id = 1, value = 20},
		}
	},
	-- 4 = ĥ��|2|3,4,5,7,16,17|1,30
	{
		name = "ĥ��",
		level = 2,
		types = {3, 4, 5, 7, 16, 17},
		attribs = {
			{id = 1, value = 30},
		}
	},
	-- 5 = ����|3|3,4,5,7,16,17|1,40
	{
		name = "����",
		level = 3,
		types = {3, 4, 5, 7, 16, 17},
		attribs = {
			{id = 1, value = 40},
		}
	},
	-- 6 = רע|3|6,17|3,5|4,1
	{
		name = "רע",
		level = 3,
		types = {6, 17},
		attribs = {
			{id = 3, value = 5},
			{id = 4, value = 1},
		}
	},
	-- 7 = ����|4|6,17|3,5|4,3
	{
		name = "����",
		level = 4,
		types = {6, 17},
		attribs = {
			{id = 3, value = 5},
			{id = 4, value = 3},
		}
	},
	-- 8 = ��|5|6,17|3,5|4,5
	{
		name = "��",
		level = 5,
		types = {6, 17},
		attribs = {
			{id = 3, value = 5},
			{id = 4, value = 5},
		}
	},
	-- 9 = ����|5|9|1,5|5,1
	{
		name = "����",
		level = 5,
		types = {9},
		attribs = {
			{id = 1, value = 5},
			{id = 5, value = 1},
		}
	},
	-- 10 = ����|6|9|1,10|5,2
	{
		name = "����",
		level = 6,
		types = {9},
		attribs = {
			{id = 1, value = 10},
			{id = 5, value = 2},
		}
	},
	-- 11 = ����|1|9|1,5
	{
		name = "����",
		level = 1,
		types = {9},
		attribs = {
			{id = 1, value = 5}
		}
	},
	-- 12 = ĥ��|2|9|1,7
	{
		name = "ĥ��",
		level = 2,
		types = {9},
		attribs = {
			{id = 1, value = 7}
		}
	},
	-- 13 = ����|3|9|1,10
	{
		name = "����",
		level = 3,
		types = {9},
		attribs = {
			{id = 1, value = 10}
		}
	},
	-- 14 = �޺�|4|9|1,13
	{
		name = "�޺�",
		level = 4,
		types = {9},
		attribs = {
			{id = 1, value = 13}
		}
	},
	-- 15 = �޷�|5|9|1,15
	{
		name = "�޷�",
		level = 5,
		types = {9},
		attribs = {
			{id = 1, value = 15}
		}
	},
	-- 16 = �ƾ�|5|9|1,18
	{
		name = "�ƾ�",
		level = 5,
		types = {9},
		attribs = {
			{id = 1, value = 18}
		}
	},
	-- 17 = �鳾|6|9|1,20
	{
		name = "�鳾",
		level = 6,
		types = {9},
		attribs = {
			{id = 1, value = 20}
		}
	},
	-- 18 = ����|5|9|6,15
	{
		name = "����",
		level = 5,
		types = {9},
		attribs = {
			{id = 6, value = 15}
		}
	},
	-- 19 = ��Ѫ|6|9|6,20
	{
		name = "��Ѫ",
		level = 6,
		types = {9},
		attribs = {
			{id = 6, value = 20}
		}
	},
	-- 20 = ����|5|9|3,5
	{
		name = "����",
		level = 5,
		types = {9},
		attribs = {
			{id = 3, value = 5}
		}
	},
	-- 21 = ��|6|9|3,5|4,7
	{
		name = "��",
		level = 6,
		types = {9},
		attribs = {
			{id = 3, value = 5},
			{id = 4, value = 7}
		}
	},
	-- 22 = ɱ¾|6|9|3,7|4,5
	{
		name = "ɱ¾",
		level = 6,
		types = {9},
		attribs = {
			{id = 3, value = 7},
			{id = 4, value = 5}
		}
	},
	-- 23 = ���|5|9|8,4|1,5
	{
		name = "���",
		level = 5,
		types = {9},
		attribs = {
			{id = 8, value = 4},
			{id = 1, value = 5}
		}
	},
	-- 24 = ʯ��|6|9|8,8|1,8
	{
		name = "ʯ��",
		level = 6,
		types = {9},
		attribs = {
			{id = 8, value = 8},
			{id = 1, value = 8}
		}
	},
	-- 25 = ��ʯ|5|6|9,1
	{
		name = "��ʯ",
		level = 5,
		types = {6},
		attribs = {
			{id = 9, value = 1}
		}
	},
	-- 26 = ̩ɽ|6|6|9,3
	{
		name = "̩ɽ",
		level = 6,
		types = {6},
		attribs = {
			{id = 9, value = 3}
		}
	},
	-- 27 = ���|5|7|10,2
	{
		name = "���",
		level = 5,
		types = {7},
		attribs = {
			{id = 10, value = 2}
		}
	},
	-- 28 = ��ʯ|5|7|11,2
	{
		name = "��ʯ",
		level = 5,
		types = {7},
		attribs = {
			{id = 11, value = 2}
		}
	},
	-- 29 = �嶾|6|7|10,4
	{
		name = "�嶾",
		level = 6,
		types = {7},
		attribs = {
			{id = 10, value = 4}
		}
	},
	-- 30 = Ǩɽ|6|7|11,4
	{
		name = "Ǩɽ",
		level = 6,
		types = {7},
		attribs = {
			{id = 11, value = 4}
		}
	}
}