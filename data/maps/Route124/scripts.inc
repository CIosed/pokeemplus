Route124_MapScripts:: @ 81F656C
	map_script MAP_SCRIPT_ON_TRANSITION, Route124_OnTransition
	.byte 0

Route124_OnTransition: @ 81F6572
	call_if_set FLAG_SYS_WEATHER_CTRL, Common_EventScript_SetAbnormalWeather
	end

Route124_EventScript_HuntersHouseSign:: @ 81F657C
	msgbox Route124_Text_HuntersHouse, MSGBOX_SIGN
	end

Route124_EventScript_Spencer:: @ 81F6585
	trainerbattle_single TRAINER_SPENCER, Route124_Text_SpencerIntro, Route124_Text_SpencerDefeat
	msgbox Route124_Text_SpencerPostBattle, MSGBOX_AUTOCLOSE
	end

Route124_EventScript_Roland:: @ 81F659C
	trainerbattle_single TRAINER_ROLAND, Route124_Text_RolandIntro, Route124_Text_RolandDefeat
	msgbox Route124_Text_RolandPostBattle, MSGBOX_AUTOCLOSE
	end

Route124_EventScript_Jenny:: @ 81F65B3
	trainerbattle_single TRAINER_JENNY, Route124_Text_JennyIntro, Route124_Text_JennyDefeat
	msgbox Route124_Text_JennyPostBattle, MSGBOX_DEFAULT
	release
	end

Route124_EventScript_Grace:: @ 81F6615
	trainerbattle_single TRAINER_GRACE, Route124_Text_GraceIntro, Route124_Text_GraceDefeat
	msgbox Route124_Text_GracePostBattle, MSGBOX_AUTOCLOSE
	end

Route124_EventScript_Chad:: @ 81F662C
	trainerbattle_single TRAINER_CHAD, Route124_Text_ChadIntro, Route124_Text_ChadDefeat
	msgbox Route124_Text_ChadPostBattle, MSGBOX_AUTOCLOSE
	end

Route124_EventScript_Lila:: @ 81F6643
	trainerbattle_double TRAINER_LILA_AND_ROY, Route124_Text_LilaIntro, Route124_Text_LilaDefeat, Route124_Text_LilaNotEnoughMons
	msgbox Route124_Text_LilaPostBattle, MSGBOX_DEFAULT
	release
	end

Route124_EventScript_Roy:: @ 81F66A7
	trainerbattle_double TRAINER_LILA_AND_ROY, Route124_Text_RoyIntro, Route124_Text_RoyDefeat, Route124_Text_RoyNotEnoughMons
	msgbox Route124_Text_RoyPostBattle, MSGBOX_DEFAULT
	release
	end

Route124_EventScript_Declan:: @ 81F670B
	trainerbattle_single TRAINER_DECLAN, Route124_Text_DeclanIntro, Route124_Text_DeclanDefeat
	msgbox Route124_Text_DeclanPostBattle, MSGBOX_AUTOCLOSE
	end

Route124_EventScript_Isabella:: @ 81F6722
	trainerbattle_single TRAINER_ISABELLA, Route124_Text_IsabellaIntro, Route124_Text_IsabellaDefeat
	msgbox Route124_Text_IsabellaPostBattle, MSGBOX_AUTOCLOSE
	end

Route124_Text_HuntersHouse: @ 81F6739
	.string "HUNTER'S HOUSE$"

