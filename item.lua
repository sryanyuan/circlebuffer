-- items constant attribute
itemsConstantAttribute = {
	-- 1:
	[1] =
	{
		Grade = 0
	},
	-- 2:
	[2] =
	{
		Grade = 1
	},
	-- 4:
	[4] =
	{
		Grade = 3,
		Upgrade = 5
	},
}

-- map info
config_mapInfo = {
	-- 0
	{
		MapType = 0,
		MapResFile = "xzz",
		MapChName = "��֪��"
	},
	-- 1
	{
		MapType = 0,
		MapResFile = "tty",
		MapChName = "��"
	},
	-- 2
	{
		MapType = 0,
		MapResFile = "hte",
		MapChName = "��"
	}
}

-- fix maps, MapID == MapResID
config_fixedLoadMaps = {
	"hte",
	"tty",
	"xzz",
	"tty",
	"tty",
	"xzz"
}