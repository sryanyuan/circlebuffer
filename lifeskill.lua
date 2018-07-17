-- items constant attribute
config_constLifeSKill = {
	-- Ò±Á¶¿óÊ¯:
	[0] =
	{
		exprs = {20, 50, 150, 600, 1200}
	},
	-- Ò±Á¶Ä¾²Ä:
	[1] =
	{
		exprs = {20, 50, 150, 600, 1200}
	},
	-- Ò±Á¶²¼ÁÏ:
	[2] =
	{
		exprs = {20, 50, 150, 600, 1200}
	},
	-- Ò±Á¶±¦Ê¯:
	[3] =
	{
		exprs = {20, 50, 150, 600, 1200}
	},
	-- Ò±Á¶×°±¸:
	[4] =
	{
		exprs = {5, 10, 20, 50, 100, 500, 1000, 1600, 2500}
	}
}

config_constMakeEquip = {
	-- Í­Ö®»¤·û
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
	-- ¸ÖÖ®»¤·û
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
	-- ÒøÖ®»¤·û
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
	-- ½ðÖ®»¤·û
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
	-- ºÚÌú»¤·û
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
	-- ×Ï½ð»¤·û
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
	-- Ä§Ñª½£
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
	-- ÁúÑª½£
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
	-- ÉñÑªÇ¹
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
	-- ÔæÄ¾Ñ«ÕÂ
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
	-- ·ãÄ¾Ñ«ÕÂ
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
	-- ×ÏÌ´Ñ«ÕÂ
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
	-- Íö»ê¹× Õ½Ê¿
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
	-- Íö»ê¹× ·¨Ê¦
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
	-- Íö»ê¹× µÀÊ¿
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
	-- ÄÏ¹ÏÍ·
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
	-- 0 = ¼áÈÍ|1|2,6,7,14,15|2,20
	{
		name = "¼áÈÍ",
		level = 1,
		types = {2, 6, 7, 14, 15},
		attribs = {
			{id = 2, value = 20},
		}
	},
	-- 1 = ¼áÒã|2|2,6,7,14,15|2,40
	{
		name = "¼áÒã",
		level = 2,
		types = {2, 6, 7, 14, 15},
		attribs = {
			{id = 2, value = 40},
		}
	},
	-- 2 = ¸ÕÒã|3|2,6,7,14,15|2,60
	{
		name = "¸ÕÒã",
		level = 3,
		types = {2, 6, 7, 14, 15},
		attribs = {
			{id = 2, value = 60},
		}
	},
	-- 3 = ·æÀû|1|3,4,5,7,16,17|1,20
	{
		name = "·æÀû",
		level = 1,
		types = {3, 4, 5, 7, 16, 17},
		attribs = {
			{id = 1, value = 20},
		}
	},
	-- 4 = Ä¥íÃ|2|3,4,5,7,16,17|1,30
	{
		name = "Ä¥íÃ",
		level = 2,
		types = {3, 4, 5, 7, 16, 17},
		attribs = {
			{id = 1, value = 30},
		}
	},
	-- 5 = Á¢¶Ï|3|3,4,5,7,16,17|1,40
	{
		name = "Á¢¶Ï",
		level = 3,
		types = {3, 4, 5, 7, 16, 17},
		attribs = {
			{id = 1, value = 40},
		}
	},
	-- 6 = ×¨×¢|3|6,17|3,5|4,1
	{
		name = "×¨×¢",
		level = 3,
		types = {6, 17},
		attribs = {
			{id = 3, value = 5},
			{id = 4, value = 1},
		}
	},
	-- 7 = »áÐÄ|4|6,17|3,5|4,3
	{
		name = "»áÐÄ",
		level = 4,
		types = {6, 17},
		attribs = {
			{id = 3, value = 5},
			{id = 4, value = 3},
		}
	},
	-- 8 = ¿ñ±©|5|6,17|3,5|4,5
	{
		name = "¿ñ±©",
		level = 5,
		types = {6, 17},
		attribs = {
			{id = 3, value = 5},
			{id = 4, value = 5},
		}
	},
	-- 9 = ÇáÎè|5|9|1,5|5,1
	{
		name = "ÇáÎè",
		level = 5,
		types = {9},
		attribs = {
			{id = 1, value = 5},
			{id = 5, value = 1},
		}
	},
	-- 10 = ·ÉÑà|6|9|1,10|5,2
	{
		name = "·ÉÑà",
		level = 6,
		types = {9},
		attribs = {
			{id = 1, value = 10},
			{id = 5, value = 2},
		}
	},
	-- 11 = ·æÀû|1|9|1,5
	{
		name = "·æÀû",
		level = 1,
		types = {9},
		attribs = {
			{id = 1, value = 5}
		}
	},
	-- 12 = Ä¥íÃ|2|9|1,7
	{
		name = "Ä¥íÃ",
		level = 2,
		types = {9},
		attribs = {
			{id = 1, value = 7}
		}
	},
	-- 13 = Á¢¶Ï|3|9|1,10
	{
		name = "Á¢¶Ï",
		level = 3,
		types = {9},
		attribs = {
			{id = 1, value = 10}
		}
	},
	-- 14 = ÎÞºÛ|4|9|1,13
	{
		name = "ÎÞºÛ",
		level = 4,
		types = {9},
		attribs = {
			{id = 1, value = 13}
		}
	},
	-- 15 = ÎÞ·æ|5|9|1,15
	{
		name = "ÎÞ·æ",
		level = 5,
		types = {9},
		attribs = {
			{id = 1, value = 15}
		}
	},
	-- 16 = ÆÆ¾ü|5|9|1,18
	{
		name = "ÆÆ¾ü",
		level = 5,
		types = {9},
		attribs = {
			{id = 1, value = 18}
		}
	},
	-- 17 = Ëé³¾|6|9|1,20
	{
		name = "Ëé³¾",
		level = 6,
		types = {9},
		attribs = {
			{id = 1, value = 20}
		}
	},
	-- 18 = ÎüÐÇ|5|9|6,15
	{
		name = "ÎüÐÇ",
		level = 5,
		types = {9},
		attribs = {
			{id = 6, value = 15}
		}
	},
	-- 19 = ÊÈÑª|6|9|6,20
	{
		name = "ÊÈÑª",
		level = 6,
		types = {9},
		attribs = {
			{id = 6, value = 20}
		}
	},
	-- 20 = »áÐÄ|5|9|3,5
	{
		name = "»áÐÄ",
		level = 5,
		types = {9},
		attribs = {
			{id = 3, value = 5}
		}
	},
	-- 21 = ¿ñ±©|6|9|3,5|4,7
	{
		name = "¿ñ±©",
		level = 6,
		types = {9},
		attribs = {
			{id = 3, value = 5},
			{id = 4, value = 7}
		}
	},
	-- 22 = É±Â¾|6|9|3,7|4,5
	{
		name = "É±Â¾",
		level = 6,
		types = {9},
		attribs = {
			{id = 3, value = 7},
			{id = 4, value = 5}
		}
	},
	-- 23 = Âé±Ô|5|9|8,4|1,5
	{
		name = "Âé±Ô",
		level = 5,
		types = {9},
		attribs = {
			{id = 8, value = 4},
			{id = 1, value = 5}
		}
	},
	-- 24 = Ê¯»¯|6|9|8,8|1,8
	{
		name = "Ê¯»¯",
		level = 6,
		types = {9},
		attribs = {
			{id = 8, value = 8},
			{id = 1, value = 8}
		}
	},
	-- 25 = ÅÍÊ¯|5|6|9,1
	{
		name = "ÅÍÊ¯",
		level = 5,
		types = {6},
		attribs = {
			{id = 9, value = 1}
		}
	},
	-- 26 = Ì©É½|6|6|9,3
	{
		name = "Ì©É½",
		level = 6,
		types = {6},
		attribs = {
			{id = 9, value = 3}
		}
	},
	-- 27 = Öìó¸|5|7|10,2
	{
		name = "Öìó¸",
		level = 5,
		types = {7},
		attribs = {
			{id = 10, value = 2}
		}
	},
	-- 28 = ·üÊ¯|5|7|11,2
	{
		name = "·üÊ¯",
		level = 5,
		types = {7},
		attribs = {
			{id = 11, value = 2}
		}
	},
	-- 29 = Îå¶¾|6|7|10,4
	{
		name = "Îå¶¾",
		level = 6,
		types = {7},
		attribs = {
			{id = 10, value = 4}
		}
	},
	-- 30 = Ç¨É½|6|7|11,4
	{
		name = "Ç¨É½",
		level = 6,
		types = {7},
		attribs = {
			{id = 11, value = 4}
		}
	}
}