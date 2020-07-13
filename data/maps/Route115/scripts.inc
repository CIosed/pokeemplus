Route115_MapScripts:: @ 81F2920
	map_script MAP_SCRIPT_ON_LOAD, Route115_OnLoad
	map_script MAP_SCRIPT_ON_TRANSITION, Route115_OnTransition
	map_script MAP_SCRIPT_ON_FRAME_TABLE, Route115_OnFrame
	.byte 0

Route115_OnLoad: @ 81F2930
	compare VAR_ABNORMAL_WEATHER_LOCATION, ABNORMAL_WEATHER_ROUTE_115_WEST
	call_if_eq AbnormalWeather_EventScript_PlaceTilesRoute115West
	compare VAR_ABNORMAL_WEATHER_LOCATION, ABNORMAL_WEATHER_ROUTE_115_EAST
	call_if_eq AbnormalWeather_EventScript_PlaceTilesRoute115East
	end

Route115_OnTransition: @ 81F2947
	compare VAR_SHOULD_END_ABNORMAL_WEATHER, 1
	call_if_eq AbnormalWeather_EventScript_HideMapNamePopup
	compare VAR_ABNORMAL_WEATHER_LOCATION, ABNORMAL_WEATHER_ROUTE_115_WEST
	call_if_eq AbnormalWeather_StartGroudonWeather
	compare VAR_ABNORMAL_WEATHER_LOCATION, ABNORMAL_WEATHER_ROUTE_115_EAST
	call_if_eq AbnormalWeather_StartGroudonWeather
	end

Route115_OnFrame: @ 81F2969
	map_script_2 VAR_SHOULD_END_ABNORMAL_WEATHER, 1, AbnormalWeather_EventScript_EndEventAndCleanup_1
	.2byte 0

Route115_EventScript_Woman:: @ 81F2973
	msgbox Route115_Text_NeverKnowWhenCavePokemonWillAppear, MSGBOX_NPC
	end

Route115_EventScript_RouteSignRustboro:: @ 81F297C
	msgbox Route115_Text_RouteSignRustboro, MSGBOX_SIGN
	end

Route115_EventScript_MeteorFallsSign:: @ 81F2985
	msgbox Route115_Text_MeteorFallsSign, MSGBOX_SIGN
	end

Route115_EventScript_Timothy:: @ 81F298E
	trainerbattle_single TRAINER_TIMOTHY, Route115_Text_TimothyIntro, Route115_Text_TimothyDefeat
	msgbox Route115_Text_TimothyPostBattle, MSGBOX_DEFAULT
	release
	end

Route115_EventScript_Koichi:: @ 81F29F0
	trainerbattle_single TRAINER_KOICHI, Route115_Text_KoichiIntro, Route115_Text_KoichiDefeat
	msgbox Route115_Text_KoichiPostBattle, MSGBOX_AUTOCLOSE
	end

Route115_EventScript_Nob:: @ 81F2A07
	trainerbattle_single TRAINER_NOB, Route115_Text_NobIntro, Route115_Text_NobDefeat
	msgbox Route115_Text_NobPostBattle, MSGBOX_DEFAULT
	release
	end

Route115_EventScript_Cyndy:: @ 81F2A69
	trainerbattle_single TRAINER_CYNDY, Route115_Text_CyndyIntro, Route115_Text_CyndyDefeat
	msgbox Route115_Text_CyndyPostBattle, MSGBOX_DEFAULT
	release
	end

Route115_EventScript_Hector:: @ 81F2ACB
	trainerbattle_single TRAINER_HECTOR, Route115_Text_HectorIntro, Route115_Text_HectorDefeat
	msgbox Route115_Text_HectorPostBattle, MSGBOX_AUTOCLOSE
	end

Route115_EventScript_Kyra:: @ 81F2AE2
	trainerbattle_single TRAINER_KYRA, Route115_Text_KyraIntro, Route115_Text_KyraDefeat
	msgbox Route115_Text_KyraPostBattle, MSGBOX_AUTOCLOSE
	end

Route115_EventScript_Jaiden:: @ 81F2AF9
	trainerbattle_single TRAINER_JAIDEN, Route115_Text_JaidenIntro, Route115_Text_JaidenDefeat
	msgbox Route115_Text_JaidenPostBattle, MSGBOX_AUTOCLOSE
	end

Route115_EventScript_Alix:: @ 81F2B10
	trainerbattle_single TRAINER_ALIX, Route115_Text_AlixIntro, Route115_Text_AlixDefeat
	msgbox Route115_Text_AlixPostBattle, MSGBOX_AUTOCLOSE
	end

Route115_EventScript_Helene:: @ 81F2B27
	trainerbattle_single TRAINER_HELENE, Route115_Text_HeleneIntro, Route115_Text_HeleneDefeat
	msgbox Route115_Text_HelenePostBattle, MSGBOX_AUTOCLOSE
	end

Route115_EventScript_Marlene:: @ 81F2B3E
	trainerbattle_single TRAINER_MARLENE, Route115_Text_MarleneIntro, Route115_Text_MarleneDefeat
	msgbox Route115_Text_MarlenePostBattle, MSGBOX_AUTOCLOSE
	end

Route115_Text_NeverKnowWhenCavePokemonWillAppear: @ 81F2B55
	.string "Exploring a cave isn't like walking\n"
	.string "on a road.\p"
	.string "You never know when wild POKéMON will\n"
	.string "appear. It's full of suspense.$"

Route115_Text_RouteSignRustboro: @ 81F2BC9
	.string "ROUTE 115\n"
	.string "{DOWN_ARROW} RUSTBORO CITY$"

Route115_Text_MeteorFallsSign: @ 81F2BE3
	.string "METEOR FALLS\n"
	.string "FALLARBOR TOWN THROUGH HERE$"

