.set LOCALID_ARCHIE, 1
.set LOCALID_MAXIE, 2
.set LOCALID_TABITHA, 3
.set LOCALID_MAGMA_GRUNT_2, 22
.set LOCALID_MAGMA_GRUNT_1, 29


MtChimney_MapScripts:: @ 822EDC1
	map_script MAP_SCRIPT_ON_RESUME, MtChimney_OnResume
	map_script MAP_SCRIPT_ON_TRANSITION, MtChimney_OnTransition
	map_script MAP_SCRIPT_ON_LOAD, MtChimney_SetMetatiles
	.byte 0

MtChimney_OnTransition: @ 822EDCC
	setvar VAR_JAGGED_PASS_ASH_WEATHER, 1
	end

MtChimney_OnResume: @ 822EDD2
	setstepcallback STEP_CB_ASH
	end

MtChimney_SetMetatiles:
    compare VAR_ACTIVATE_MT_CHIMNEY, 2
	call_if_ge IncreaseLavaHeight
	end

MtChimney_EventScript_Archie:: @ 822EDD5
	lock
	faceplayer
	call_if_unset FLAG_EVIL_LEADER_PLEASE_STOP, MtChimney_EventScript_ArchieGoStopTeamMagma
	call_if_set FLAG_EVIL_LEADER_PLEASE_STOP, MtChimney_EventScript_ArchieBusyFighting
	closemessage
	applymovement LOCALID_ARCHIE, Common_Movement_FaceOriginalDirection
	waitmovement 0
	setflag FLAG_EVIL_LEADER_PLEASE_STOP
	release
	end

MtChimney_EventScript_ArchieGoStopTeamMagma:: @ 822EDF9
	msgbox MtChimney_Text_ArchieGoStopTeamMagma, MSGBOX_DEFAULT
	return

MtChimney_EventScript_ArchieBusyFighting:: @ 822EE02
	msgbox MtChimney_Text_ArchieIHaveMyHandsFull, MSGBOX_DEFAULT
	return

MtChimney_EventScript_Maxie:: @ 822EE0B
	lockall
	playbgm MUS_ENCOUNTER_MAGMA, 0
	msgbox MtChimney_Text_MeteoriteWillActivateVolcano, MSGBOX_DEFAULT
	applymovement LOCALID_MAXIE, Common_Movement_FacePlayer
	waitmovement 0
	playse SE_PIN
	applymovement LOCALID_MAXIE, Common_Movement_ExclamationMark
	waitmovement 0
	applymovement LOCALID_MAXIE, Common_Movement_Delay48
	waitmovement 0
	msgbox MtChimney_Text_MaxieIntro, MSGBOX_DEFAULT
	applymovement LOCALID_MAXIE, Common_Movement_WalkInPlaceFastestRight
	waitmovement 0
	msgbox MtChimney_Text_MaxieIntro2, MSGBOX_DEFAULT
	applymovement LOCALID_MAXIE, Common_Movement_FacePlayer
	waitmovement 0
	msgbox MtChimney_Text_MaxieIntro3, MSGBOX_YESNO
	compare VAR_RESULT, YES
	goto_if_eq TossMeteorite
	compare VAR_RESULT, NO
	goto_if_eq DontTossMeteorite

TossMeteorite::
    msgbox MtChimney_Text_MaxieIntro4, MSGBOX_DEFAULT
	closemessage
	call GetPlayerpos_MtChimney

DontTossMeteorite::
    msgbox MtChimney_Text_MaxieIntro18, MSGBOX_DEFAULT
	call FightMaxie

GetPlayerpos_MtChimney::
	getplayerxy VAR_TEMP_0, VAR_TEMP_1
	compare VAR_TEMP_0, 13
	goto_if_eq PlayerLocatedBot_MtChimney
	applymovement LOCALID_MAXIE, ArchieMoveToLava
	waitmovement 0
	call VolcanoErupt

GetPlayerpos_MtChimney2::
	getplayerxy VAR_TEMP_0, VAR_TEMP_1
	compare VAR_TEMP_1, 6
	goto_if_eq PlayerLocatedTop_MtChimney
	getplayerxy VAR_TEMP_0, VAR_TEMP_1
	compare VAR_TEMP_1, 7
	goto_if_eq PlayerLocatedBot2_MtChimney
    return

GetPlayerpos_MtChimney3::
	getplayerxy VAR_TEMP_0, VAR_TEMP_1
	compare VAR_TEMP_1, 6
	goto_if_eq PlayerLocatedTop2_MtChimney
	getplayerxy VAR_TEMP_0, VAR_TEMP_1
	compare VAR_TEMP_1, 7
	goto_if_eq PlayerLocatedBot3_MtChimney
    return

PlayerLocatedBot_MtChimney::
	applymovement LOCALID_MAXIE, ArchieMoveToLava
	applymovement OBJ_EVENT_ID_PLAYER, PlayerMoveOutofWay
    waitmovement 0
	call VolcanoErupt

PlayerLocatedTop_MtChimney:
	applymovement LOCALID_MAXIE, ArchieApproachPlayerTop
    waitmovement 0
	return

PlayerLocatedBot2_MtChimney:
	applymovement LOCALID_MAXIE, ArchieApproachPlayerBot
    waitmovement 0
	return

PlayerLocatedTop2_MtChimney:
	applymovement LOCALID_ARCHIE, ArchieApproachPlayerTop2
    waitmovement 0
	return

PlayerLocatedBot3_MtChimney:
	applymovement LOCALID_ARCHIE, ArchieApproachPlayerBot2
    waitmovement 0
	return

VolcanoErupt::
    setvar VAR_ACTIVATE_MT_CHIMNEY, 1
    fadeoutbgm 1
    msgbox MtChimney_Text_MaxieIntro5, MSGBOX_DEFAULT
	applymovement LOCALID_MAXIE, Common_Movement_WalkInPlaceFastestRight
	playse SE_FU_ZAKU
    waitmovement 0
	msgbox MtChimney_Text_MaxieIntro6, MSGBOX_DEFAULT
    applymovement LOCALID_MAXIE, Common_Movement_ExclamationMark
	waitmovement 0
	playbgm MUS_ENCOUNTER_MAGMA, 1
	playse SE_M_EARTHQUAKE
	setvar VAR_0x8004, 4  @ vertical pan
	setvar VAR_0x8005, 4  @ horizontal pan
	setvar VAR_0x8006, 20  @ num shakes
	setvar VAR_0x8007, 6  @ shake delay
	special ShakeCamera
	waitstate
	msgbox MtChimney_Text_MaxieIntro7, MSGBOX_DEFAULT
	applymovement LOCALID_MAXIE, Common_Movement_FacePlayer
	waitmovement 0
	playse SE_M_EARTHQUAKE
	setvar VAR_0x8004, 4  @ vertical pan
	setvar VAR_0x8005, 4  @ horizontal pan
	setvar VAR_0x8006, 20  @ num shakes
	setvar VAR_0x8007, 6  @ shake delay
	special ShakeCamera
	waitstate
	fadescreenspeed FADE_TO_WHITE 1
	playse SE_M_SACRED_FIRE2
	delay 16
	fadescreen FADE_FROM_WHITE
	msgbox MtChimney_Text_MaxieIntro8, MSGBOX_DEFAULT
	playse SE_M_EARTHQUAKE
	setvar VAR_0x8004, 4  @ vertical pan
	setvar VAR_0x8005, 4  @ horizontal pan
	setvar VAR_0x8006, 20  @ num shakes
	setvar VAR_0x8007, 6  @ shake delay
	special ShakeCamera
	waitstate
	fadescreenspeed FADE_TO_WHITE 1
	playse SE_M_SACRED_FIRE2
	delay 16
	fadescreen FADE_FROM_WHITE
	msgbox MtChimney_Text_MaxieIntro9, MSGBOX_DEFAULT
	closemessage
	applymovement 3, Tabitha_Move_MtChimney
	waitmovement 0
	msgbox MtChimney_Text_Tabitha1, MSGBOX_DEFAULT
	playse SE_M_EARTHQUAKE
	setvar VAR_0x8004, 4  @ vertical pan
	setvar VAR_0x8005, 4  @ horizontal pan
	setvar VAR_0x8006, 20  @ num shakes
	setvar VAR_0x8007, 6  @ shake delay
	special ShakeCamera
	waitstate
	fadescreenspeed FADE_TO_WHITE 1
	playse SE_M_SACRED_FIRE2
	delay 16
	fadescreen FADE_FROM_WHITE
	applymovement LOCALID_MAXIE, Common_Movement_WalkInPlaceFastestLeft
	waitmovement 0
	msgbox MtChimney_Text_MaxieIntro10, MSGBOX_DEFAULT
	applymovement LOCALID_MAXIE, Common_Movement_WalkInPlaceFastestUp
	waitmovement 0
	msgbox MtChimney_Text_MaxieIntro11, MSGBOX_DEFAULT
	applymovement LOCALID_MAXIE, Common_Movement_WalkInPlaceFastestLeft
	waitmovement 0
	msgbox MtChimney_Text_MaxieIntro12, MSGBOX_DEFAULT
	playse SE_M_EARTHQUAKE
	setvar VAR_0x8004, 4  @ vertical pan
	setvar VAR_0x8005, 4  @ horizontal pan
	setvar VAR_0x8006, 20  @ num shakes
	setvar VAR_0x8007, 6  @ shake delay
	special ShakeCamera
	waitstate
	fadescreenspeed FADE_TO_WHITE 1
	playse SE_M_SACRED_FIRE2
	closemessage
	delay 16
	fadescreen FADE_FROM_WHITE
	msgbox MtChimney_Text_ArchieInterfere, MSGBOX_DEFAULT
	closemessage
    playse SE_PIN
	applymovement LOCALID_MAXIE, Common_Movement_ExclamationMarkDown
	applymovement 3, Common_Movement_ExclamationMarkDown
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_ExclamationMarkDown
	delay 16
	waitmovement 0
	setobjectxyperm LOCALID_ARCHIE, 10, 14
	addobject LOCALID_ARCHIE
	applymovement LOCALID_ARCHIE, ArchieMoveToInterfere
	applymovement 3, TabithaWaitForBeingPushed
	waitmovement 0
	applymovement LOCALID_MAXIE, Common_Movement_WalkInPlaceLeft
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceLeft
	waitmovement 0
	msgbox MtChimney_Text_ArchieInterfere2, MSGBOX_DEFAULT
	applymovement LOCALID_MAXIE, Common_Movement_WalkInPlaceLeft
	waitmovement 0
	msgbox MtChimney_Text_MaxieIntro13, MSGBOX_DEFAULT
	applymovement LOCALID_ARCHIE, Common_Movement_WalkInPlaceRight
	waitmovement 0
	msgbox MtChimney_Text_ArchieInterfere3, MSGBOX_DEFAULT
	applymovement LOCALID_MAXIE, Common_Movement_WalkInPlaceLeft
	waitmovement 0
	msgbox MtChimney_Text_MaxieIntro14, MSGBOX_DEFAULT
	playse SE_M_EARTHQUAKE
	setvar VAR_0x8004, 6  @ vertical pan
	setvar VAR_0x8005, 6  @ horizontal pan
	setvar VAR_0x8006, 20  @ num shakes
	setvar VAR_0x8007, 3  @ shake delay
	special ShakeCamera
	waitstate
	fadescreenspeed FADE_TO_WHITE 1
	playse SE_INTRO_BLAST
	waitse
	playse SE_M_EXPLOSION
	delay 8
	playse SE_M_EXPLOSION
	delay 8
	playse SE_M_EXPLOSION
	delay 8
	playse SE_M_EXPLOSION
	delay 8
	closemessage
	delay 16
	call IncreaseLavaHeight
	special DrawWholeMapView
	fadescreen FADE_FROM_WHITE
	msgbox MtChimney_Text_ArchieInterfere4, MSGBOX_DEFAULT
    playse SE_PIN
	applymovement LOCALID_MAXIE, Common_Movement_ExclamationMarkRight
	applymovement 3, Common_Movement_ExclamationMarkRight
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_ExclamationMarkRight
	delay 16
	waitmovement 0
	applymovement LOCALID_MAXIE, Common_Movement_WalkInPlaceRight
	waitmovement 0
	msgbox MtChimney_Text_MaxieIntro15, MSGBOX_DEFAULT
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceLeft
	waitmovement 0
	msgbox MtChimney_Text_ArchieInterfere5, MSGBOX_DEFAULT
    playse SE_PIN
	applymovement LOCALID_MAXIE, Common_Movement_ExclamationMark
	delay 16
	msgbox MtChimney_Text_MaxieIntro16, MSGBOX_AUTOCLOSE
	call GetPlayerpos_MtChimney2
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceRight
	waitmovement 0
	msgbox MtChimney_Text_MaxieIntro17, MSGBOX_DEFAULT
	call FightMaxie

FightMaxie::
	trainerbattle_no_intro TRAINER_MAXIE_MT_CHIMNEY, MtChimney_Text_MaxieDefeat
	compare VAR_ACTIVATE_MT_CHIMNEY, 1
	call_if_eq SetVarTossedMeteorite
	compare VAR_ACTIVATE_MT_CHIMNEY, 2
	call_if_ge MtChimneyBeforeEndScript
	compare VAR_ACTIVATE_MT_CHIMNEY, 2
	call_if_lt MtChimneyBeforeEndScript2

MtChimneyBeforeEndScript2::
	msgbox MtChimney_Text_MaxieYouHaventSeenLastOfMagma, MSGBOX_DEFAULT
	giveitem ITEM_METEORITE
	closemessage
	setflag FLAG_RECEIVED_METEORITE
	call MtChimneyBeforeEndScript3

MtChimneyBeforeEndScript::
	msgbox MtChimney_Text_MaxieYouHaventSeenLastOfMagma2, MSGBOX_DEFAULT
	closemessage
	call MtChimneyBeforeEndScript3

MtChimneyBeforeEndScript3::
	delay 30
	fadescreen FADE_TO_BLACK
	removeobject LOCALID_MAXIE
	removeobject LOCALID_MAGMA_GRUNT_1
	removeobject LOCALID_TABITHA
	removeobject LOCALID_MAGMA_GRUNT_2
	setflag FLAG_HIDE_MT_CHIMNEY_TEAM_MAGMA
	fadescreen FADE_FROM_BLACK
	closemessage
	delay 16
	compare VAR_ACTIVATE_MT_CHIMNEY, 2
	call_if_eq TossedMeteorite
	setobjectxyperm LOCALID_ARCHIE, 10, 12
	addobject LOCALID_ARCHIE
	compare VAR_FACING, DIR_EAST
	call_if_eq MtChimney_EventScript_ArchieApproachPlayerEast
	compare VAR_FACING, DIR_NORTH
	call_if_eq MtChimney_EventScript_ArchieApproachPlayerNorth
	goto MtChimneyEndScript

TossedMeteorite::
	playse SE_M_EARTHQUAKE
	setvar VAR_0x8004, 4  @ vertical pan
	setvar VAR_0x8005, 4  @ horizontal pan
	setvar VAR_0x8006, 20  @ num shakes
	setvar VAR_0x8007, 6  @ shake delay
	special ShakeCamera
	waitstate
	fadescreenspeed FADE_TO_WHITE 1
	delay 16
	fadescreen FADE_FROM_WHITE
	playse SE_M_EARTHQUAKE
	setvar VAR_0x8004, 4  @ vertical pan
	setvar VAR_0x8005, 4  @ horizontal pan
	setvar VAR_0x8006, 20  @ num shakes
	setvar VAR_0x8007, 3  @ shake delay
	special ShakeCamera
	waitstate
	fadescreenspeed FADE_TO_WHITE 1
	closemessage
	delay 16
	fadescreen FADE_FROM_WHITE
    call GetPlayerpos_MtChimney3
	delay 16
	playse SE_CLICK
	applymovement LOCALID_ARCHIE, Common_Movement_WalkInPlaceFastestUp
	waitmovement 0
	fadeoutbgm 1
	msgbox MtChimney_ArchieTurnOnMachine, MSGBOX_AUTOCLOSE
	playse SE_M_EARTHQUAKE
	setvar VAR_0x8004, 6  @ vertical pan
	setvar VAR_0x8005, 6  @ horizontal pan
	setvar VAR_0x8006, 30  @ num shakes
	setvar VAR_0x8007, 3  @ shake delay
	special ShakeCamera
	waitstate
	fadescreenspeed FADE_TO_WHITE 1
	playse SE_INTRO_BLAST
	closemessage
	removeobject LOCALID_ARCHIE
	delay 48
	msgbox Ellipsis, MSGBOX_DEFAULT
	closemessage
	delay 42
	fadescreenspeed FADE_FROM_WHITE, 8
	playse SE_PIN
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_QuestionMark
	waitmovement 0
	delay 24
	applymovement OBJ_EVENT_ID_PLAYER, PetalburgWoods_Movement_DevonResearcherLookAround
	waitmovement 0
	playbgm MUS_MT_CHIMNEY, 0
	setflag FLAG_HIDE_MT_CHIMNEY_TEAM_AQUA
	setflag FLAG_DEFEATED_EVIL_TEAM_MT_CHIMNEY
	clearflag FLAG_HIDE_FALLARBOR_HOUSE_PROF_COZMO
	setflag FLAG_HIDE_METEOR_FALLS_1F_1R_COZMO
	clearflag FLAG_HIDE_MT_CHIMNEY_LAVA_COOKIE_LADY
	releaseall
	end

MtChimneyEndScript::
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFastestLeft
	waitmovement 0
	msgbox MtChimney_Text_ArchieThankYou, MSGBOX_DEFAULT
	closemessage
	compare VAR_FACING, DIR_EAST
	call_if_eq MtChimney_EventScript_ArchieExitEast
	compare VAR_FACING, DIR_NORTH
	call_if_eq MtChimney_EventScript_ArchieExitNorth
	removeobject LOCALID_ARCHIE
	setflag FLAG_HIDE_MT_CHIMNEY_TEAM_AQUA
	setflag FLAG_DEFEATED_EVIL_TEAM_MT_CHIMNEY
	clearflag FLAG_HIDE_FALLARBOR_HOUSE_PROF_COZMO
	setflag FLAG_HIDE_METEOR_FALLS_1F_1R_COZMO
	clearflag FLAG_HIDE_MT_CHIMNEY_LAVA_COOKIE_LADY
	releaseall
	end

SetVarTossedMeteorite:
    setvar VAR_ACTIVATE_MT_CHIMNEY, 2
	return

IncreaseLavaHeight::
	setmetatile 15, 0, METATILE_Lavaridge_Lava, 1
	setmetatile 15, 1, METATILE_Lavaridge_Lava, 1
	setmetatile 15, 2, METATILE_Lavaridge_Lava, 1
	setmetatile 14, 2, METATILE_Lavaridge_Lava, 1
	setmetatile 14, 3, METATILE_Lavaridge_Lava, 1
	setmetatile 14, 4, METATILE_Lavaridge_Lava, 1
	setmetatile 14, 5, METATILE_Lavaridge_Lava, 1
	setmetatile 14, 9, METATILE_Lavaridge_Lava, 1
	setmetatile 17, 11, METATILE_Lavaridge_Lava, 1
	setmetatile 18, 11, METATILE_Lavaridge_Lava, 1
	setmetatile 19, 11, METATILE_Lavaridge_Lava, 1
	setmetatile 20, 11, METATILE_Lavaridge_Lava, 1
	setmetatile 21, 11, METATILE_Lavaridge_Lava, 1
	setmetatile 21, 10, METATILE_Lavaridge_Lava, 1
	setmetatile 22, 10, METATILE_Lavaridge_Lava, 1
	setmetatile 24, 8, METATILE_Lavaridge_Lava, 1
	setmetatile 24, 7, METATILE_Lavaridge_Lava, 1
	setmetatile 24, 6, METATILE_Lavaridge_Lava, 1
	setmetatile 25, 6, METATILE_Lavaridge_Lava, 1
	setmetatile 24, 5, METATILE_Lavaridge_Lava, 1
	setmetatile 25, 5, METATILE_Lavaridge_Lava, 1
	setmetatile 25, 4, METATILE_Lavaridge_Lava, 1
	setmetatile 25, 3, METATILE_Lavaridge_Lava, 1
	setmetatile 25, 2, METATILE_Lavaridge_Lava, 1
	setmetatile 26, 2, METATILE_Lavaridge_Lava, 1
	setmetatile 25, 1, METATILE_Lavaridge_Lava, 1
	setmetatile 26, 1, METATILE_Lavaridge_Lava, 1
	setmetatile 26, 0, METATILE_Lavaridge_Lava, 1
	setmetatile 26, 0, METATILE_Lavaridge_Lava, 1
    setmetatile 14, 0, METATILE_Lavaridge_RockWallLava8, 1
    setmetatile 14, 1, METATILE_Lavaridge_RockWallLava5, 1
    setmetatile 13, 2, METATILE_Lavaridge_RockWallLava8, 1
    setmetatile 13, 2, METATILE_Lavaridge_RockWallLava8, 1
    setmetatile 13, 3, METATILE_Lavaridge_RockWallLava8, 1
    setmetatile 13, 4, METATILE_Lavaridge_RockWallLava8, 1
    setmetatile 13, 5, METATILE_Lavaridge_RockWallLava8, 1
    setmetatile 13, 9, METATILE_Lavaridge_RockWallLava8, 1
    setmetatile 14, 10, METATILE_Lavaridge_RockWallLava9, 1
    setmetatile 17, 12, METATILE_Lavaridge_RockWallLava9, 1
    setmetatile 18, 12, METATILE_Lavaridge_RockWallLava9, 1
    setmetatile 19, 12, METATILE_Lavaridge_RockWallLava9, 1
    setmetatile 20, 12, METATILE_Lavaridge_RockWallLava9, 1
    setmetatile 21, 12, METATILE_Lavaridge_RockWallLava9, 1
    setmetatile 22, 11, METATILE_Lavaridge_RockWallLava1, 1
    setmetatile 23, 10, METATILE_Lavaridge_RockWallLava6, 1
    setmetatile 25, 8, METATILE_Lavaridge_RockWallLava6, 1
    setmetatile 25, 7, METATILE_Lavaridge_RockWallLava1, 1
    setmetatile 26, 6, METATILE_Lavaridge_RockWallLava6, 1
    setmetatile 26, 5, METATILE_Lavaridge_RockWallLava6, 1
    setmetatile 26, 4, METATILE_Lavaridge_RockWallLava6, 1
    setmetatile 26, 3, METATILE_Lavaridge_RockWallLava1, 1
    setmetatile 27, 2, METATILE_Lavaridge_RockWallLava6, 1
    setmetatile 27, 1, METATILE_Lavaridge_RockWallLava6, 1
    setmetatile 27, 0, METATILE_Lavaridge_RockWallLava6, 1
	setmetatile 14, 5, METATILE_Lavaridge_MachineLava, 1
    setmetatile 18, 0, METATILE_Lavaridge_RockWallLava4, 1
    setmetatile 19, 1, METATILE_Lavaridge_RockWallLava4, 1
    setmetatile 20, 1, METATILE_Lavaridge_RockWallLava7, 1
    setmetatile 21, 1, METATILE_Lavaridge_RockWallLava5, 1
    setmetatile 22, 0, METATILE_Lavaridge_RockWallLava5, 1
    setmetatile 16, 11, METATILE_Lavaridge_RockWallLava8, 1
    setmetatile 14, 8, METATILE_Lavaridge_RockWallLava7, 1
	setmetatile 17, 0, METATILE_Lavaridge_Lava, 1
	setmetatile 17, 1, METATILE_Lavaridge_Lava, 1
	setmetatile 18, 1, METATILE_Lavaridge_Lava, 1
	setmetatile 18, 2, METATILE_Lavaridge_Lava, 1
	setmetatile 19, 2, METATILE_Lavaridge_Lava, 1
	setmetatile 20, 2, METATILE_Lavaridge_Lava, 1
	setmetatile 21, 2, METATILE_Lavaridge_Lava, 1
	setmetatile 22, 2, METATILE_Lavaridge_Lava, 1
	setmetatile 22, 1, METATILE_Lavaridge_Lava, 1
	setmetatile 23, 1, METATILE_Lavaridge_Lava, 1
	setmetatile 23, 0, METATILE_Lavaridge_Lava, 1
	return

MtChimney_EventScript_ArchieApproachPlayerEast:: @ 822EEC7
	applymovement LOCALID_ARCHIE, MtChimney_Movement_ArchieApproachPlayerEast
	waitmovement 0
	return

MtChimney_EventScript_ArchieApproachPlayerNorth:: @ 822EED2
	applymovement LOCALID_ARCHIE, MtChimney_Movement_ArchieApproachPlayerNorth
	waitmovement 0
	return

MtChimney_EventScript_ArchieExitEast:: @ 822EEDD
	applymovement LOCALID_ARCHIE, MtChimney_Movement_ArchieExitEast
	waitmovement 0
	return

MtChimney_EventScript_ArchieExitNorth:: @ 822EEE8
	applymovement LOCALID_ARCHIE, MtChimney_Movement_ArchieExitNorth
	waitmovement 0
	return

MtChimney_EventScript_LavaCookieLady:: @ 822EEF3
	lock
	faceplayer
	showmoneybox 0, 0, 0
	msgbox MtChimney_Text_LavaCookiesJust200, MSGBOX_YESNO
	compare VAR_RESULT, NO
	goto_if_eq MtChimney_EventScript_DeclineLavaCookie
	checkmoney 200, 0
	compare VAR_RESULT, FALSE
	goto_if_eq MtChimney_EventScript_NotEnoughMoney
	msgbox MtChimney_Text_ThankYouDear, MSGBOX_DEFAULT
	checkitemspace ITEM_LAVA_COOKIE, 1
	compare VAR_RESULT, TRUE
	call_if_eq MtChimney_EventScript_RemoveMoney
	giveitem ITEM_LAVA_COOKIE
	compare VAR_RESULT, FALSE
	goto_if_eq MtChimney_EventScript_BagIsFull
	hidemoneybox
	release
	end

MtChimney_EventScript_BagIsFull:: @ 822EF51
	msgbox gText_TooBadBagIsFull, MSGBOX_DEFAULT
	hidemoneybox
	release
	end

MtChimney_EventScript_RemoveMoney:: @ 822EF5E
	removemoney 200, 0
	updatemoneybox 0, 0
	return

MtChimney_EventScript_DeclineLavaCookie:: @ 822EF69
	msgbox MtChimney_Text_OhFineThen, MSGBOX_DEFAULT
	hidemoneybox
	release
	end

MtChimney_EventScript_NotEnoughMoney:: @ 822EF76
	msgbox MtChimney_Text_YouveNotGotTheMoney, MSGBOX_DEFAULT
	hidemoneybox
	release
	end

ArchieApproachPlayerTop::
    walk_left
	walk_up
	walk_in_place_fastest_left
	step_end

ArchieApproachPlayerBot::
    walk_left
	step_end

ArchieApproachPlayerTop2::
    walk_fast_right
    walk_fast_right
    walk_fast_right
    walk_fast_right
	walk_in_place_fastest_up
	step_end

ArchieApproachPlayerBot2::
    walk_fast_right
	walk_fast_up
    walk_fast_right
    walk_fast_right
	step_end

TabithaWaitForBeingPushed::
    delay_16
    delay_16
    delay_16
    lock_facing_direction
	walk_up
	unlock_facing_direction
	step_end

ArchieMoveToInterfere::
    walk_fast_up
	walk_fast_up
    walk_fast_up
	walk_fast_up
	walk_fast_up
    walk_fast_up
	walk_fast_up
	walk_in_place_fastest_right
	step_end

Tabitha_Move_MtChimney::
    walk_fast_left
    walk_fast_up
	walk_fast_up
    walk_fast_up
	walk_fast_up
	walk_in_place_fastest_right
	step_end

ArchieMoveToLava::
    walk_down
	walk_right
	step_end

PlayerMoveOutofWay::
    face_right
    lock_facing_direction
	walk_left
	unlock_facing_direction
	step_end

MtChimney_Movement_ArchieApproachPlayerEast: @ 822EF83
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_right
	step_end

MtChimney_Movement_ArchieExitEast: @ 822EF8B
	walk_left
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	step_end

MtChimney_Movement_ArchieApproachPlayerNorth: @ 822EF94
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_right
	walk_right
	step_end

MtChimney_Movement_ArchieExitNorth: @ 822EF9C
	walk_left
	walk_left
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	step_end

MtChimney_Movement_Unused1: @ 822EFA6
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_left
	walk_left
	walk_down
	walk_down
	walk_down
	walk_down
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_down
	step_end

MtChimney_Movement_Unused2: @ 822EFB8
	walk_down
	walk_down
	walk_down
	walk_down
	walk_left
	walk_left
	walk_left
	walk_down
	step_end

MtChimney_Movement_Unused3: @ 822EFC1
	walk_right
	walk_down
	walk_down
	walk_down
	walk_down
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_down
	walk_down
	walk_down
	walk_down
	step_end

MtChimney_Movement_Unused4: @ 822EFD0
	walk_fast_down
	walk_fast_down
	walk_fast_down
	walk_fast_down
	walk_fast_down
	walk_fast_down
	walk_fast_down
	walk_fast_down
	walk_fast_down
	walk_left
	walk_left
	walk_down
	walk_down
	walk_down
	walk_left
	walk_left
	walk_down
	walk_down
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_down
	step_end

MtChimney_Movement_Unused5: @ 822EFE9
	delay_16
	delay_16
	delay_16
	walk_down
	walk_down
	walk_down
	walk_left
	walk_left
	walk_left
	walk_down
	step_end

MtChimney_Movement_Unused6: @ 822EFF4
	delay_16
	walk_left
	walk_down
	walk_down
	walk_down
	walk_down
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_down
	walk_down
	walk_down
	walk_down
	step_end

MtChimney_Movement_Unused7: @ 822F004
	delay_16
	walk_left
	walk_left
	walk_down
	walk_down
	walk_down
	walk_left
	walk_left
	walk_down
	walk_down
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_down
	step_end

MtChimney_Movement_Unused8: @ 822F015
	delay_16
	walk_down
	walk_left
	walk_left
	walk_left
	walk_left
	walk_in_place_fastest_down
	step_end

MtChimney_Movement_Unused9: @ 822F01D
	walk_down
	walk_down
	walk_down
	walk_down
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_down
	walk_down
	walk_down
	walk_down
	step_end

MtChimney_Movement_Unused10: @ 822F02B
	walk_down
	step_end

MtChimney_Movement_Unused11: @ 822F02D
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	step_end

MtChimney_Movement_Unused12: @ 822F035
	delay_16
	delay_16
	walk_in_place_fastest_left
	delay_16
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	step_end

MtChimney_Movement_Unused13: @ 822F03F
	delay_16
	delay_16
	delay_16
	delay_16
	delay_16
	delay_16
	walk_in_place_fastest_left
	delay_16
	walk_down
	walk_down
	step_end

MtChimney_Movement_Unused14: @ 822F04A
	lock_facing_direction
	walk_fast_left
	unlock_facing_direction
	face_right
	step_end

MtChimney_Movement_Unused15: @ 822F04F
	walk_left
	walk_in_place_fastest_right
	delay_16
	step_end

MtChimney_EventScript_BusyAquaGrunt1:: @ 822F053
	msgbox MtChimney_Text_MagmaOutnumbersUs, MSGBOX_SIGN
	end

MtChimney_EventScript_BusyAquaGrunt2:: @ 822F05C
	msgbox MtChimney_Text_LessHabitatForWaterPokemon, MSGBOX_SIGN
	end

MtChimney_EventScript_BusyAquaGrunt3:: @ 822F065
	msgbox MtChimney_Text_MagmasNameSimilar, MSGBOX_SIGN
	end

MtChimney_EventScript_Tabitha:: @ 822F06E
	trainerbattle_single TRAINER_TABITHA_MT_CHIMNEY, MtChimney_Text_TabithaIntro, MtChimney_Text_TabithaDefeat
	msgbox MtChimney_Text_TabithaPostBattle, MSGBOX_AUTOCLOSE
	end

MtChimney_EventScript_Grunt2:: @ 822F085
	trainerbattle_single TRAINER_GRUNT_MT_CHIMNEY_2, MtChimney_Text_Grunt2Intro, MtChimney_Text_Grunt2Defeat
	msgbox MtChimney_Text_Grunt2PostBattle, MSGBOX_AUTOCLOSE
	end

MtChimney_EventScript_BusyMagmaGrunt1:: @ 822F09C
	msgbox MtChimney_Text_TeamAquaAlwaysMessingWithPlans, MSGBOX_SIGN
	end

MtChimney_EventScript_BusyMagmaGrunt2:: @ 822F0A5
	msgbox MtChimney_Text_MeteoritesPackAmazingPower, MSGBOX_SIGN
	end

MtChimney_EventScript_BusyMagmaGrunt3:: @ 822F0AE
	msgbox MtChimney_Text_YouBetterNotMessWithUs, MSGBOX_SIGN
	end

MtChimney_EventScript_BusyMagmaGrunt4:: @ 822F0B7
	msgbox MtChimney_Text_AquasNameSimilar, MSGBOX_SIGN
	end

MtChimney_EventScript_BusyMagmaGrunt5:: @ 822F0C0
	msgbox MtChimney_Text_DouseThemInFire, MSGBOX_SIGN
	end

MtChimney_EventScript_BusyMagmaGrunt6:: @ 822F0C9
	msgbox MtChimney_Text_KeepMakingMoreLand, MSGBOX_SIGN
	end

MtChimney_EventScript_MagmaPoochyena:: @ 822F0D2
	msgbox MtChimney_Text_Bufoh, MSGBOX_SIGN
	end

MtChimney_EventScript_AquaPoochyena:: @ 822F0DB
	msgbox MtChimney_Text_Bushaa, MSGBOX_SIGN
	end

MtChimney_EventScript_MeteoriteMachine:: @ 822F0E4
	msgbox MtChimney_Text_MachineMakesNoResponse, MSGBOX_SIGN
    end

MtChimney_EventScript_RouteSign:: @ 822F141
	msgbox MtChimney_Text_RouteSign, MSGBOX_SIGN
	end

MtChimney_EventScript_Shelby:: @ 822F14A
	trainerbattle_single TRAINER_SHELBY, MtChimney_Text_ShelbyIntro, MtChimney_Text_ShelbyDefeat
	msgbox MtChimney_Text_ShelbyPostBattle, MSGBOX_DEFAULT
	release
	end

MtChimney_EventScript_Melissa:: @ 822F1AC
	trainerbattle_single TRAINER_MELISSA, MtChimney_Text_MelissaIntro, MtChimney_Text_MelissaDefeat
	msgbox MtChimney_Text_MelissaPostBattle, MSGBOX_AUTOCLOSE
	end

MtChimney_EventScript_Sheila:: @ 822F1C3
	trainerbattle_single TRAINER_SHEILA, MtChimney_Text_SheilaIntro, MtChimney_Text_SheilaDefeat
	msgbox MtChimney_Text_SheilaPostBattle, MSGBOX_AUTOCLOSE
	end

MtChimney_EventScript_Shirley:: @ 822F1DA
	trainerbattle_single TRAINER_SHIRLEY, MtChimney_Text_ShirleyIntro, MtChimney_Text_ShirleyDefeat
	msgbox MtChimney_Text_ShirleyPostBattle, MSGBOX_AUTOCLOSE
	end

MtChimney_EventScript_Grunt1:: @ 822F1F1
	trainerbattle_single TRAINER_GRUNT_MT_CHIMNEY_1, MtChimney_Text_Grunt1Intro, MtChimney_Text_Grunt1Defeat
	msgbox MtChimney_Text_Grunt1PostBattle, MSGBOX_AUTOCLOSE
	end

MtChimney_EventScript_Sawyer:: @ 822F208
	trainerbattle_single TRAINER_SAWYER, MtChimney_Text_SawyerIntro, MtChimney_Text_SawyerDefeat
	msgbox MtChimney_Text_SawyerPostBattle, MSGBOX_DEFAULT
	release
	end

Ellipsis:
	.string "{COLOR DARK_GREY}… … … … … …\n"
	.string "… … … … … …\l"
	.string "… … … … … …\l"
	.string "… … … … … …\l"
	.string "… … … … … …$"

MtChimney_ArchieTurnOnMachine:
    .string "{COLOR DARK_GREY}ARCHIE turned on the machine!\p"
	.string "… … … … … …\n"
	.string "… … … … … …$"

MtChimney_Text_ArchieInterfere:
    .string "???: MAXIE! Cease this at once!$"

MtChimney_Text_ArchieInterfere2:
    .string "ARCHIE: You have to stop this, or\n"
	.string "we'll all dissapear!$"

MtChimney_Text_ArchieInterfere3:
    .string "ARCHIE: Have you lost it?!\n"
	.string "The whole mountain will erupt!$"

MtChimney_Text_ArchieInterfere4:
    .string "ARCHIE: Arghhh!\n"
	.string "MAXIE! It's scorching-hot here!\p"
	.string "The lava is raising!$"

MtChimney_Text_ArchieInterfere5:
    .string "My POKéMON are to exhausted to\n"
	.string "fight!\p"
	.string "You have to start the MACHINE or\n"
	.string "the volcano will erupt!$"

MtChimney_Text_Tabitha1:
    .string "TABITHA: B-Boss!\n"
	.string "We have to evacuate!\p"
	.string "The whole mountain is shaking!$"

MtChimney_Text_MeteoriteWillActivateVolcano: @ 822F26A
	.string "The power contained in the\n"
	.string "METEORITE…\p"
	.string "By amplifying its power with this\n"
	.string "machine, MT. CHIMNEY's volcanic\l"
	.string "activity will instantly cease to\l"
	.string "exist…\p"
	.string "However, If I were to do that\n"
	.string "instead…$"

MtChimney_Text_MaxieIntro: @ 822F32E
	.string "MAXIE: Hm?\n"
	.string "Who are you?\p"
	.string "… … … … … …\n"
	.string "… … … … … …\p"
	.string "I'd heard ARCHIE bemoaning a child\n"
	.string "who's been meddling in TEAM AQUA's\l"
	.string "affairs.\p"
	.string "It must be you he meant.\p"
	.string "Humph! So now you're also\n"
	.string "interfering with us, TEAM MAGMA?\p"
	.string "Words reached me of what happened\n"
	.string "in METEOR FALLS.\p"
	.string "Fortunatley we managed to snatch\n"
	.string "the METEORITE before TEAM AQUA did.$"

MtChimney_Text_MaxieIntro2:
	.string "Had we not, this machine here,\n"
	.string "beloning to TEAM AQUA would be able\l"
	.string "to extract the energy from the\l"
	.string "METEORITE, amplifying and modifying\l"
	.string "it.\p"
	.string "With that energy in this machine, it\n"
	.string "would be able to stop the volcanic\l"
	.string "activity of MT. CHIMNEY!$"

MtChimney_Text_MaxieIntro3:
	.string "Do you realise what that would mean?\p"
	.string "MT. CHIMNEY is an integral part of\n"
	.string "the HOENN region…\p"
	.string "Without it heating up the region,\n"
	.string "we would see a drastic increase\l"
	.string "in the water levels!\p"
	.string "You might not realise it but TEAM\n"
	.string "AQUA's ideals are not only to stop\l"
	.string "us.\p"
	.string "They want to wipe out the human\n"
	.string "civilization!\p"
	.string "Outnumbering them at this location\n"
	.string "was quite easy, however.\p"
	.string "So I, Maxie, has saved the whole\n"
	.string "region!\p"
	.string "You should be thanking me.\p"
	.string "Now… This METEORITE, in it's natural\n"
	.string "state…\p"
	.string "If I were to toss it into the\n"
	.string "volcano…\p"
	.string "What do you suppose would happen?\p"
	.string "… … … … … …\n"
	.string "… … … … … …\p"
	.string "Naturally, I'd stop the volcano from\n"
	.string "ever being threatened to being\l"
	.string "inactive ever again.\p"
	.string "So, if you'd please allow me.$"

MtChimney_Text_MaxieIntro4:
    .string "I see you posess some intellect after\n"
	.string "all.\p"
	.string "I honestly expected you to stop me.\p"
	.string "No matter. Let us get to it.$"

MtChimney_Text_MaxieIntro5:
	.string "… … … … … …\n"
	.string "… … … … … …$"

MtChimney_Text_MaxieIntro6:
	.string "{COLOR DARK_GREY}MAXIE tossed the METEORITE!\p"
	.string "{COLOR BLUE}MAXIE: …{PAUSE 15} …{PAUSE 15} …{PAUSE 15} …{PAUSE 15} …{PAUSE 15} …\p"
	.string "What's the meaning of this…?\p"
	.string "Did I miscalculate?\p"
	.string "… … … … … …\n"
	.string "… … … … … …\p"
	.string "Nothing is happening…$"

MtChimney_Text_MaxieIntro7:
    .string "…!\p"
	.string "What intense power!$"

MtChimney_Text_MaxieIntro8:
    .string "It's working! The volcano is reacting\n"
	.string "to the METORITE!$"

MtChimney_Text_MaxieIntro9:
    .string "This should put an end to TEAM AQUA!$"

MtChimney_Text_MaxieIntro10:
    .string "MAXIE: Not just yet!\p"
	.string "There's one more thing to take\n"
	.string "care of.$"

MtChimney_Text_MaxieIntro11:
    .string "This machine!\p"
	.string "It might've absorbed some of the\n"
	.string "energy just by being close to the\l"
	.string "METEORITE!$"

MtChimney_Text_MaxieIntro12:
    .string "There's no way my calculations\n"
	.string "were off!$"

MtChimney_Text_MaxieIntro13:
    .string "MAXIE: Fufufufu…\p"
	.string "This METEORITE isn't enough to make\n"
	.string "the volcano erupt!$"

MtChimney_Text_MaxieIntro14:
    .string "MAXIE: Not quite.\n"
	.string "On the contrary, however…\p"
	.string "This METEORITE combined with that\n"
	.string "MACHINE is too dangerous!\p"
	.string "If utilized by some dangerous people\n"
	.string "like yourself, the whole region\l"
	.string "could be destroyed!$"

MtChimney_Text_MaxieIntro15:
    .string "MAXIE: What?!\p"
	.string "No, this wasn't supposed to\n"
	.string "happen…!\p"
	.string "ARCHIE: {PLAYER}!$"

MtChimney_Text_MaxieIntro16:
    .string "MAXIE: No! Not yet!\p"
	.string "We still haven't confirmed it!$"

MtChimney_Text_MaxieIntro17:
    .string "I can't allow you to interfere now.\p"
	.string "Sometimes you have to take risks to\n"
	.string "achieve what you are after!\p"
	.string "You'll understand after I defeat\n"
	.string "you!$"

MtChimney_Text_MaxieIntro18:
    .string "No? What kind of logic is that?\p"
	.string "Certainly you must've just heard\n"
	.string "what I just said.\p"
	.string "Destroying this METEORITE will ensure\n"
	.string "the saftey of the region!\p"
	.string "I suppose you must be a member of\n"
	.string "TEAM AQUA after all.\p"
	.string "I'll teach you the consequences of\n"
	.string "meddling with TEAM MAGMA!$"

MtChimney_Text_MaxieDefeat: @ 822F5CF
	.string "What?!\p"
	.string "I, MAXIE, was caught off guard?!$"

MtChimney_Text_MaxieYouHaventSeenLastOfMagma: @ 822F5F7
	.string "MAXIE: But, enough.\n"
	.string "I will back off this time.\p"
	.string "But don't think that this is the last\n"
	.string "you've seen of TEAM MAGMA…\p"
    .string "Oh, and I suppose I'll have to\n"
	.string "entrust this to you…$"

MtChimney_Text_MaxieYouHaventSeenLastOfMagma2: @ 822F5F7
	.string "MAXIE: But, enough.\n"
	.string "I will back off this time.\p"
	.string "But don't think that this is the last\n"
	.string "you've seen of TEAM MAGMA…\p"
	.string "Go ahead and activate the MACHINE…$"

MtChimney_Text_TabithaIntro: @ 822F6AA
	.string "Hehehe!\p"
	.string "So you've come all the way here!\p"
	.string "But you're too late!\n"
	.string "I've already delivered the METEORITE\l"
	.string "from METEOR FALLS to the BOSS!$"

MtChimney_Text_TabithaDefeat: @ 822F72C
	.string "Hehehe…\p"
	.string "Even though I've lost, if our leader\n"
	.string "awakens that thing…$"

MtChimney_Text_TabithaPostBattle: @ 822F76D
	.string "BOSS, hurry!\n"
	.string "Execute the plan!\p"
	.string "Hehehe…$"

MtChimney_Text_Grunt2Intro: @ 822F7A2
	.string "We of TEAM MAGMA are working hard\n"
	.string "for everyone's sake.\p"
	.string "Like, if that thing's power made more\n"
	.string "land, there'd be more places to live.\p"
	.string "Everyone'd be happy!$"

MtChimney_Text_Grunt2Defeat: @ 822F83A
	.string "Hunh?\n"
	.string "What do you mean I lost?$"

MtChimney_Text_Grunt2PostBattle: @ 822F859
	.string "Our BOSS says, “It will make everyone\n"
	.string "happy.”\p"
	.string "But why does everyone keep getting\n"
	.string "in our way?$"

MtChimney_Text_Grunt1Intro: @ 822F8B6
	.string "If there were more land, I'd be able\n"
	.string "to get a big house of my own!\p"
	.string "I'm going to build it on hardened\n"
	.string "lava!$"

MtChimney_Text_Grunt1Defeat: @ 822F921
	.string "My dream of a big house…$"

MtChimney_Text_Grunt1PostBattle: @ 822F93A
	.string "A kid like you, you ought to be\n"
	.string "splashing about in the waves!$"

MtChimney_Text_TeamAquaAlwaysMessingWithPlans: @ 822F978
	.string "That annoying TEAM AQUA…\n"
	.string "They always mess with our plans!$"

MtChimney_Text_MeteoritesPackAmazingPower: @ 822F9B2
	.string "METEORITES pack amazing power!$"

MtChimney_Text_YouBetterNotMessWithUs: @ 822F9D1
	.string "You'd better not mess with us!\p"
	.string "We're trying to awaken that thing\n"
	.string "for the benefit of everyone!$"

MtChimney_Text_AquasNameSimilar: @ 822FA2F
	.string "We're TEAM MAGMA!\p"
	.string "They're TEAM AQUA!\p"
	.string "It totally annoys me that they'd\n"
	.string "use a name like ours!$"

MtChimney_Text_DouseThemInFire: @ 822FA8B
	.string "Yeah!\n"
	.string "Douse them in fire!$"

MtChimney_Text_KeepMakingMoreLand: @ 822FAA5
	.string "We're going to keep making more land!$"

MtChimney_Text_Bufoh: @ 822FACB
	.string "Bufoh!$"

MtChimney_Text_ArchieGoStopTeamMagma: @ 822FAD2 XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX
	.string "ARCHIE: Grr, {PLAYER}!\n"
	.string "I should've guessed you'd show up!\p"
	.string "See for yourself what the fanatics\n"
	.string "of TEAM MAGMA are up to!\p"
	.string "They're trying to use the stolen\n"
	.string "METEORITE in the volcano.\p"
	.string "Doing something like that will cause\n"
	.string "the volcano's eruption!$"

MtChimney_Text_ArchieIHaveMyHandsFull: @ 822FBC7
	.string "ARCHIE: Grrr…\p"
	.string "I want to stop that MAXIE,\n"
	.string "but I can't!\p"
	.string "Not when I have my hands full\n"
	.string "battling three opponents at once!$"

MtChimney_Text_ArchieThankYou: @ 822FC3D
	.string "ARCHIE: {PLAYER}!\p"
	.string "I suppose this must be quite\n"
	.string "confusing all things considered.\p"
	.string "However, TEAM MAGMA can't be trusted.\n"
	.string "You can't trust their words, keep\l"
	.string "that in mind if you encounter them.\p"
	.string "We will remain vigilant and keep up\n"
	.string "our pursuit of TEAM MAGMA.\p"
	.string "{PLAYER}, we shall meet again!$"

MtChimney_Text_MagmaOutnumbersUs: @ 822FD1F
	.string "Darn… TEAM MAGMA outnumbers us!\n"
	.string "We can't keep up with them!$"

MtChimney_Text_LessHabitatForWaterPokemon: @ 822FD5B
	.string "We can't let them expand the land!\n"
	.string "It'd be a disaster!\p"
	.string "We have to stop them!$"

MtChimney_Text_MagmasNameSimilar: @ 822FDA1
	.string "We're TEAM AQUA!\p"
	.string "They're TEAM MAGMA!\p"
	.string "It burns me up that they'd use such\n"
	.string "a confusing name!$"

MtChimney_Text_Bushaa: @ 822FDFC
	.string "Bushaa!$"

MtChimney_Text_LavaCookiesJust200: @ 822FE04
	.string "LAVA COOKIES are MT. CHIMNEY's local\n"
	.string "specialty.\p"
	.string "Try one. It's just ¥200.$"

MtChimney_Text_ThankYouDear: @ 822FE4D
	.string "Thank you, dear!$"

MtChimney_Text_YouveNotGotTheMoney: @ 822FE5E
	.string "Oh, dear. You can't buy a thing if\n"
	.string "you've not got the money.$"

MtChimney_Text_OhFineThen: @ 822FE9B
	.string "Oh, fine then.$"

MtChimney_Text_MachineMakesNoResponse: @ 822FFC0
	.string "This mysterious machine…\n"
	.string "It makes no response whatsoever.$"

MtChimney_Text_RouteSign: @ 822FFFA
	.string "{DOWN_ARROW} JAGGED PATH\n"
	.string "LAVARIDGE TOWN AHEAD$"

MtChimney_Text_ShelbyIntro: @ 823001D
	.string "I've been to the hot springs and\n"
	.string "refreshed my tired bones.\l"
	.string "Right now I'm feeling strong!$"

MtChimney_Text_ShelbyDefeat: @ 8230076
	.string "Oh, my goodness.\n"
	.string "Now, aren't you something!$"

MtChimney_Text_ShelbyPostBattle: @ 82300A2
	.string "Well, well, I've lost. I can't call\n"
	.string "myself an EXPERT now, can I?$"

MtChimney_Text_ShelbyRegister: @ 82300E3
	.string "Thank you, child. It was fun, as if\n"
	.string "I were battling my own grandchild.\p"
	.string "Please, come see me again for\n"
	.string "a rematch.$"

MtChimney_Text_ShelbyRematchIntro: @ 8230153
	.string "If you can mesh your heart with those\n"
	.string "of your POKéMON, why, you should be\l"
	.string "able to achieve great things.$"

MtChimney_Text_ShelbyRematchDefeat: @ 82301BB
	.string "Oh, my goodness.\n"
	.string "Now, aren't you something!$"

MtChimney_Text_ShelbyPostRematch: @ 82301E7
	.string "Perhaps your heart has become one\n"
	.string "with the hearts of your POKéMON.$"

MtChimney_Text_MelissaIntro: @ 823022A
	.string "I've got the fire in me, baby.\n"
	.string "I can't stand it! I have to battle!$"

MtChimney_Text_MelissaDefeat: @ 823026D
	.string "Ooh, that was a scorching-hot match!$"

MtChimney_Text_MelissaPostBattle: @ 8230292
	.string "The heat of MT. CHIMNEY warms\n"
	.string "me up, baby!$"

MtChimney_Text_SheilaIntro: @ 82302BD
	.string "I've finally made it to MT. CHIMNEY.\n"
	.string "I want to make my POKéMON battle!$"

MtChimney_Text_SheilaDefeat: @ 8230304
	.string "The way you battle…\n"
	.string "It's like a MT. CHIMNEY eruption!$"

MtChimney_Text_SheilaPostBattle: @ 823033A
	.string "Like I said, I've finally made it to\n"
	.string "MT. CHIMNEY. It would be a shame if\l"
	.string "I only do a little sightseeing…\p"
	.string "I want to get in some battles and buy\n"
	.string "COOKIES as souvenirs.$"

MtChimney_Text_ShirleyIntro: @ 82303DF
	.string "Since I bathed in the hot springs,\n"
	.string "I've been feeling great!\l"
	.string "I'm sure I'm going to win!$"

MtChimney_Text_ShirleyDefeat: @ 8230436
	.string "Yowch!\n"
	.string "I'm getting a chill out of the water.$"

MtChimney_Text_ShirleyPostBattle: @ 8230463
	.string "I'll have to take another dip in the\n"
	.string "hot springs. Want to join me?\p"
	.string "Just joking!$"

MtChimney_Text_SawyerIntro: @ 82304B3
	.string "This is one fine mountain! Plenty of\n"
	.string "hot people around for company!$"

MtChimney_Text_SawyerDefeat: @ 82304F7
	.string "Oh, you're a real firebrand, too!$"

MtChimney_Text_SawyerPostBattle: @ 8230519
	.string "I think I need a dip in LAVARIDGE\n"
	.string "HOT SPRING with the locals!$"

MtChimney_Text_SawyerRegister: @ 8230557
	.string "I like little fireballs like you.\n"
	.string "Let me register you in my POKéNAV.$"

MtChimney_Text_SawyerRematchIntro: @ 823059C
	.string "I'm happily surrounded by hot people\n"
	.string "around these parts. I won't lose!$"

MtChimney_Text_SawyerRematchDefeat: @ 82305E3
	.string "Gosh, you're still the same\n"
	.string "firebrand as before!$"

MtChimney_Text_SawyerPostRematch: @ 8230614
	.string "Actually, it really is hot here.\n"
	.string "I'm overdressed for these parts.$"

