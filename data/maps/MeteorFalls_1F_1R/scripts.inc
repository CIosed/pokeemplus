.set LOCALID_MAGMA_GRUNT_1, 5
.set LOCALID_MAGMA_GRUNT_2, 6
.set LOCALID_ARCHIE, 7
.set LOCALID_AQUA_GRUNT_1, 8
.set LOCALID_AQUA_GRUNT_2, 9

MeteorFalls_1F_1R_MapScripts:: @ 822BD2A
	map_script MAP_SCRIPT_ON_LOAD, MeteorFalls_1F_1R_OnLoad
	.byte 0

MeteorFalls_1F_1R_OnLoad: @ 822BD30
	call_if_set FLAG_SYS_GAME_CLEAR, MeteorFalls_1F_1R_EventScript_OpenStevensCave
	call Common_EventScript_SetupRivalGfxId
	end

MeteorFalls_1F_1R_EventScript_OpenStevensCave:: @ 822BD3A
	setmetatile 4, 1, METATILE_MeteorFalls_CaveEntrance_Top, 1
	setmetatile 3, 2, METATILE_MeteorFalls_CaveEntrance_Left, 1
	setmetatile 4, 2, METATILE_MeteorFalls_CaveEntrance_Bottom, 0
	setmetatile 5, 2, METATILE_MeteorFalls_CaveEntrance_Right, 1
	return

MeteorFallsRivalIntro::
	goto_if_set FLAG_METEOR_FALLS_RIVAL_CHECK, MeteorFallsRivalBattle
	setflag FLAG_METEOR_FALLS_RIVAL_CHECK
	lock
	faceplayer
	delay 10
	playse SE_PIN
	applymovement 11, Common_Movement_ExclamationMark
	waitmovement 0
	msgbox RivalString_1, MSGBOX_DEFAULT
	closemessage
	call GetPlayerpos_MeteorFalls
	applymovement 11, Common_Movement_WalkInPlaceDown
	waitmovement 0
	special SpawnCameraObject
	applymovement OBJ_EVENT_ID_CAMERA, move_camera1_Meteor_Falls
	waitmovement 0
	msgbox RivalString_2, MSGBOX_DEFAULT
	applymovement 11, Common_Movement_FacePlayer
	waitmovement 0
	msgbox RivalString_3, MSGBOX_DEFAULT
	closemessage
	applymovement 11, Common_Movement_WalkInPlaceDown
	applymovement OBJ_EVENT_ID_CAMERA, move_camera2_Meteor_Falls
	waitmovement 0
	special RemoveCameraObject
	closemessage
	release
    end
	
MeteorFallsRivalBattle:
    playbgm MUS_ENCOUNTER_MAGMA, 1
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_FaceDown
	waitmovement 0
	delay 30
	applymovement 5, Common_Movement_WalkInPlaceDown
	waitmovement 0
	msgbox MeteorFalls_1F_1R_Text_WithThisMeteorite, MSGBOX_DEFAULT
	closemessage
	applymovement 5, Common_Movement_WalkInPlaceFastestUp
	applymovement 6, Common_Movement_WalkInPlaceFastestUp
	waitmovement 0
	playse SE_PIN
	applymovement 5, Common_Movement_ExclamationMark
	waitmovement 0
	applymovement 5, Common_Movement_Delay48
	waitmovement 0
	msgbox MeteorFalls_1F_1R_Text_DontExpectMercyFromMagma, MSGBOX_DEFAULT
	closemessage
	call GetPlayerpos_MeteorFalls_2
	delay 30
    call TagBattleStart

TagBattleStart:
    choose_mons
    compare VAR_RESULT, 0
    goto_if_eq CancelParty
	checkplayergender
	compare VAR_RESULT, MALE
	call_if_eq RivalFemale1_MeteorFalls
	compare VAR_RESULT, FEMALE
	call_if_eq RivalMale1_MeteorFalls

TagBattleWon:
	specialvar VAR_RESULT, GetBattleOutcome
	compare VAR_RESULT, B_OUTCOME_LOST
	goto_if_eq RusturfTagLostBattle
    fadedefaultbgm
    msgbox MeteorFalls_1F_1R_Text_HoldItRightThereMagma, MSGBOX_DEFAULT
	closemessage
	applymovement 11, Common_Movement_WalkInPlaceFastestLeft
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFastestLeft
	applymovement 5, Common_Movement_WalkInPlaceFastestLeft
	applymovement 6, Common_Movement_WalkInPlaceFastestLeft
	waitmovement 0
	addobject 7
	addobject 8
	addobject 9
	playbgm MUS_ENCOUNTER_AQUA, 0
	applymovement 7, MeteorFalls_1F_1R_Movement_ArchieArrive
	applymovement 8, MeteorFalls_1F_1R_Movement_AquaGrunt1Arrive
	applymovement 9, MeteorFalls_1F_1R_Movement_AquaGrunt2Arrive
	waitmovement 0
	applymovement 5, Common_Movement_WalkInPlaceFastestLeft
	applymovement 6, Common_Movement_WalkInPlaceFastestLeft
	waitmovement 0
	msgbox MeteorFalls_1F_1R_Text_BeSeeingYouTeamAqua, MSGBOX_DEFAULT
	closemessage
	applymovement OBJ_EVENT_ID_PLAYER, MeteorFalls_1F_1R_Movement_PushPlayerOutOfWay
	applymovement 11, Common_Movement_WalkInPlaceRight
	applymovement 5, MeteorFalls_1F_1R_Movement_MagmaGrunt1Exit
	applymovement 6, MeteorFalls_1F_1R_Movement_MagmaGrunt1Exit
	waitmovement 0
	removeobject 5
	removeobject 6
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceDown
	applymovement 11, Common_Movement_WalkInPlaceDown
	waitmovement 0
	call GetPlayerpos_MeteorFalls_3
	msgbox MeteorFalls_1F_1R_Text_ArchieSeenYouBefore, MSGBOX_DEFAULT
	closemessage
	applymovement 8, MeteorFalls_1F_1R_Movement_AquaGrunt1ApproachArchie
	applymovement 9, MeteorFalls_1F_1R_Movement_AquaGrunt2ApproachArchie
	waitmovement 0
	msgbox MeteorFalls_1F_1R_Text_BossWeShouldChaseMagma, MSGBOX_DEFAULT
	applymovement 7, Common_Movement_WalkInPlaceFastestDown
	waitmovement 0
	msgbox MeteorFalls_1F_1R_Text_ArchieYesNoTellingWhatMagmaWillDo, MSGBOX_DEFAULT
	applymovement 7, Common_Movement_WalkInPlaceUp
	waitmovement 0
	msgbox MeteorFalls_1F_1R_Text_ArchieFarewell, MSGBOX_DEFAULT
	closemessage
	applymovement 7, MeteorFalls_1F_1R_Movement_ArchieExit
	applymovement 8, MeteorFalls_1F_1R_Movement_AquaGrunt1Exit
	applymovement 9, MeteorFalls_1F_1R_Movement_AquaGrunt2Exit
	waitmovement 0
	playbgm MUS_CAVE_OF_ORIGIN, 1
	removeobject 7
	removeobject 8
	removeobject 9
	setflag FLAG_HIDE_ROUTE_112_TEAM_MAGMA
	setflag FLAG_MET_ARCHIE_METEOR_FALLS
	setflag FLAG_HIDE_FALLARBOR_TOWN_BATTLE_TENT_SCOTT
	setflag FLAG_MET_PROF_COZMO
	setvar VAR_METEOR_FALLS_STATE, 1
	applymovement 10, CozmoWalk1
	waitmovement 0
	msgbox MeteorFalls_1F_1R_Text_MeetProfCozmo, MSGBOX_DEFAULT
	applymovement 11, Common_Movement_WalkInPlaceDown
    waitmovement 0
    checkplayergender
	compare VAR_RESULT, MALE
	call_if_eq RivalFemale2_MeteorFalls
	compare VAR_RESULT, FEMALE
	call_if_eq RivalMale2_MeteorFalls
    playse SE_PIN
	applymovement 10, Common_Movement_ExclamationMark
	waitmovement 0
    delay 30
	applymovement 10, Common_Movement_WalkInPlaceUp
    waitmovement 0
	msgbox CozmoString_1, MSGBOX_DEFAULT
	applymovement 11, Common_Movement_WalkInPlaceDown
    waitmovement 0
	checkplayergender
	compare VAR_RESULT, MALE
	call_if_eq RivalFemale3_MeteorFalls
	compare VAR_RESULT, FEMALE
	call_if_eq RivalMale3_MeteorFalls
	applymovement 10, Common_Movement_WalkInPlaceUp
    waitmovement 0
	msgbox CozmoString_2, MSGBOX_DEFAULT
	applymovement 11, Common_Movement_WalkInPlaceDown
    waitmovement 0
	checkplayergender
	compare VAR_RESULT, MALE
	call_if_eq RivalFemale4_MeteorFalls
	compare VAR_RESULT, FEMALE
	call_if_eq RivalMale4_MeteorFalls
	applymovement 10, Common_Movement_WalkInPlaceUp
    waitmovement 0
	msgbox CozmoString_3, MSGBOX_DEFAULT
	giveitem ITEM_FULL_RESTORE
	compare VAR_RESULT, 0
	call_if_eq GraniteCave_StevensRoom_EventScript_BagFull
	msgbox CozmoString_4, MSGBOX_DEFAULT
	closemessage
	call Common_EventScript_OutOfCenterPartyHeal
	applymovement 10, CozmoWalk2
    waitmovement 0
	call GetPlayerpos_MeteorFalls_4
	checkplayergender
	compare VAR_RESULT, MALE
	call_if_eq RivalFemale5_MeteorFalls
	compare VAR_RESULT, FEMALE
	call_if_eq RivalMale5_MeteorFalls
	fadescreen 1
	closemessage
	removeobject 11
	delay 30
	fadescreen 0
	releaseall
	end

RivalFemale1_MeteorFalls:
	switch VAR_STARTER_MON
	case 0, RivalFireMay
	case 1, RivalWaterMay
	case 2, RivalGrassMay
	return

RivalMale1_MeteorFalls:
	switch VAR_STARTER_MON
	case 0, RivalFireBrendan
	case 1, RivalWaterBrendan
	case 2, RivalGrassBrendan
	return

RivalFireMay:
    multi_2_vs_2 TRAINER_MAGMA_GRUNT_METEORFALLS_1, MeteorFallsGrunt1_DefeatString, TRAINER_MAGMA_GRUNT_METEORFALLS_2, MeteorFallsGrunt2_DefeatString, TRAINER_MAY_METEORFALLS_1, TRAINER_BACK_PIC_MAY
	call TagBattleWon

RivalWaterMay:
    multi_2_vs_2 TRAINER_MAGMA_GRUNT_METEORFALLS_1, MeteorFallsGrunt1_DefeatString, TRAINER_MAGMA_GRUNT_METEORFALLS_2, MeteorFallsGrunt2_DefeatString, TRAINER_MAY_METEORFALLS_3, TRAINER_BACK_PIC_MAY
	call TagBattleWon

RivalGrassMay:
    multi_2_vs_2 TRAINER_MAGMA_GRUNT_METEORFALLS_1, MeteorFallsGrunt1_DefeatString, TRAINER_MAGMA_GRUNT_METEORFALLS_2, MeteorFallsGrunt2_DefeatString, TRAINER_MAY_METEORFALLS_2, TRAINER_BACK_PIC_MAY
	call TagBattleWon

RivalFireBrendan:
    multi_2_vs_2 TRAINER_MAGMA_GRUNT_METEORFALLS_1, MeteorFallsGrunt1_DefeatString, TRAINER_MAGMA_GRUNT_METEORFALLS_2, MeteorFallsGrunt2_DefeatString, TRAINER_BRENDAN_METEORFALLS_1, TRAINER_BACK_PIC_BRENDAN
	call TagBattleWon

RivalWaterBrendan:
    multi_2_vs_2 TRAINER_MAGMA_GRUNT_METEORFALLS_1, MeteorFallsGrunt1_DefeatString, TRAINER_MAGMA_GRUNT_METEORFALLS_2, MeteorFallsGrunt2_DefeatString, TRAINER_BRENDAN_METEORFALLS_3, TRAINER_BACK_PIC_BRENDAN
	call TagBattleWon

RivalGrassBrendan:
    multi_2_vs_2 TRAINER_MAGMA_GRUNT_METEORFALLS_1, MeteorFallsGrunt1_DefeatString, TRAINER_MAGMA_GRUNT_METEORFALLS_2, MeteorFallsGrunt2_DefeatString, TRAINER_BRENDAN_METEORFALLS_2, TRAINER_BACK_PIC_BRENDAN
	call TagBattleWon

GetPlayerpos_MeteorFalls:
    getplayerxy VAR_TEMP_0, VAR_TEMP_1
	compare VAR_TEMP_0, 13
	goto_if_le PlayerLocatedSides_MeteorFalls
	compare VAR_TEMP_0, 14
	goto_if_eq PlayerLocatedMid_MeteorFalls
	compare VAR_TEMP_0, 15
	goto_if_ge PlayerLocatedSides_MeteorFalls
	return

GetPlayerpos_MeteorFalls_2:
	getplayerxy VAR_TEMP_0, VAR_TEMP_1
	compare VAR_TEMP_0, 13
	goto_if_le PlayerLocatedLeft_MeteorFalls
	compare VAR_TEMP_0, 14
	goto_if_eq PlayerLocatedMid_MeteorFalls_2
	compare VAR_TEMP_0, 15
	goto_if_ge PlayerLocatedRight_MeteorFalls
	return

GetPlayerpos_MeteorFalls_3:
	getplayerxy VAR_TEMP_0, VAR_TEMP_1
	compare VAR_TEMP_0, 13
	goto_if_le PlayerLocatedLeft_MeteorFalls_4
	compare VAR_TEMP_0, 14
	goto_if_eq PlayerLocatedMid_MeteorFalls_4
	compare VAR_TEMP_0, 15
	goto_if_ge PlayerLocatedRight_MeteorFalls_4
	return

GetPlayerpos_MeteorFalls_4: 
	getplayerxy VAR_TEMP_0, VAR_TEMP_1
	compare VAR_TEMP_0, 13
	goto_if_le PlayerLocatedLeft_MeteorFalls_5
	compare VAR_TEMP_0, 14
	goto_if_eq PlayerLocatedMid_MeteorFalls_5
	compare VAR_TEMP_0, 15
	goto_if_ge PlayerLocatedRight_MeteorFalls_6
	return

RivalFemale2_MeteorFalls:
    msgbox RivalString_4, MSGBOX_DEFAULT
	return

RivalMale2_MeteorFalls:
    msgbox RivalString_5, MSGBOX_DEFAULT
	return    

RivalFemale3_MeteorFalls:
    msgbox RivalString_6, MSGBOX_DEFAULT
	return

RivalMale3_MeteorFalls:
    msgbox RivalString_7, MSGBOX_DEFAULT
	return    

RivalFemale4_MeteorFalls:
    msgbox RivalString_8, MSGBOX_DEFAULT
	return

RivalMale4_MeteorFalls:
    msgbox RivalString_9, MSGBOX_DEFAULT
	return    

RivalFemale5_MeteorFalls:
    msgbox RivalString_10, MSGBOX_DEFAULT
	return

RivalMale5_MeteorFalls:
    msgbox RivalString_11, MSGBOX_DEFAULT
	return  

MeteorFalls_1F_1R_Movement_MagmaGruntApproachPlayer: @ 822BEC0
	walk_right
	walk_right
	walk_in_place_fastest_up
	step_end

MeteorFalls_1F_1R_Movement_MagmaGrunt1Exit: @ 822BEC4
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	step_end

MeteorFalls_1F_1R_Movement_MagmaGrunt2Exit: @ 822BECE
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	step_end

MeteorFalls_1F_1R_Movement_ArchieArrive: @ 822BED9
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	step_end

MeteorFalls_1F_1R_Movement_AquaGrunt1Arrive: @ 822BEE0
	delay_16
	delay_16
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	step_end

MeteorFalls_1F_1R_Movement_AquaGrunt2Arrive: @ 822BEE8
	delay_16
	delay_16
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	step_end

MeteorFalls_1F_1R_Movement_ArchieExit: @ 822BEF0
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	step_end

MeteorFalls_1F_1R_Movement_ArchieApproachPlayer: @ 822BEF8
	walk_right
	walk_right
	walk_up
	walk_up
	walk_in_place_fastest_left
	step_end

MeteorFalls_1F_1R_Movement_AquaGrunt1Exit: @ 822BEFE
	walk_up
	walk_up
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	step_end

MeteorFalls_1F_1R_Movement_AquaGrunt1ApproachArchie: @ 822BF08
	walk_right
	walk_right
	walk_right
	walk_in_place_fastest_up
	step_end

MeteorFalls_1F_1R_Movement_AquaGrunt2Exit: @ 822BF0D
	delay_16
	delay_8
	walk_up
	walk_up
	walk_up
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	step_end

MeteorFalls_1F_1R_Movement_AquaGrunt2ApproachArchie: @ 822BF18
	walk_right
	walk_right
	walk_right
	walk_in_place_fastest_up
	step_end

MeteorFalls_1F_1R_Movement_PushPlayerOutOfWay: @ 822BF1D
	walk_in_place_fastest_down
	delay_4
	walk_in_place_fastest_right
	step_end

PlayerLocatedSides_MeteorFalls:
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceDown
	waitmovement 0
	return

PlayerLocatedMid_MeteorFalls:
    closemessage
	applymovement OBJ_EVENT_ID_PLAYER, WalkFromMid_MeteorFalls
	waitmovement 0
	return

PlayerLocatedLeft_MeteorFalls:
	applymovement 5, MagmaGruntMove1_Mid2
	applymovement OBJ_EVENT_ID_PLAYER, RivalMove_Mid3
	applymovement 11, RivalMove_Mid3
	applymovement 6, MagmaGruntMove2_Mid2
	waitmovement 0
	return

PlayerLocatedMid_MeteorFalls_2:
	applymovement 5, MagmaGruntMove1_Mid2
	applymovement 11, RivalMove_Mid2
	applymovement 6, MagmaGruntMove2_Mid2
	waitmovement 0
	return

PlayerLocatedRight_MeteorFalls:
	applymovement 5, MagmaGruntMove1_Mid3
	applymovement OBJ_EVENT_ID_PLAYER, RivalMove_Mid3
	applymovement 11, RivalMove_Mid3
	applymovement 6, MagmaGruntMove2_Mid2
	waitmovement 0
	return

PlayerLocatedLeft_MeteorFalls_4:
	applymovement 7, ArchieLeft
	waitmovement 0
	return

PlayerLocatedMid_MeteorFalls_4:
	applymovement 7, ArchieMid
	waitmovement 0
	return

PlayerLocatedRight_MeteorFalls_4:
	applymovement 7, ArchieRight
	waitmovement 0
	return

PlayerLocatedRight_MeteorFalls_6:
    applymovement 11, Common_Movement_FacePlayer
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceRight
	waitmovement 0
	return

PlayerLocatedLeft_MeteorFalls_5:
    applymovement 11, Common_Movement_WalkInPlaceLeft
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceRight
	waitmovement 0
	return

PlayerLocatedMid_MeteorFalls_5:
    applymovement 11, Common_Movement_WalkInPlaceRight
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceLeft
	waitmovement 0
	return

CozmoWalk1:
   walk_up
   walk_up
   walk_right
   walk_up
   walk_up
   walk_up
   step_end

CozmoWalk2:
   walk_down
   walk_down
   walk_down
   walk_left
   walk_down
   walk_down
   step_end

ArchieLeft:
    walk_right
	walk_right
	walk_up
	walk_up
	walk_left
    walk_in_place_up
	step_end

ArchieMid:
    walk_right
	walk_right
    walk_up
	walk_up
	step_end

ArchieRight:
    walk_right
	walk_right
	walk_up
	walk_up
	walk_right
    walk_in_place_up
	step_end

MagmaGruntMove1_Mid2:
	walk_right
	walk_right
	walk_up
	walk_up
	walk_left
	walk_in_place_up
	step_end

MagmaGruntMove2_Mid2:
	delay_16
	delay_16
	delay_16
	delay_8
	walk_up
	walk_up
	walk_up
	step_end

RivalMove_Mid2:
	delay_16
	delay_16
    walk_left
	walk_up
	walk_in_place_down
	step_end

MagmaGruntMove1_Mid3:
	walk_right
	walk_right
	walk_up
	walk_up
	walk_right
	walk_in_place_up
	step_end

RivalMove_Mid3:
	delay_16
	delay_16
	delay_16
    lock_facing_direction
	walk_up
	step_end

move_camera1_Meteor_Falls:
	walk_down
	walk_down
	walk_diag_southwest
	walk_diag_southwest
	step_end

move_camera2_Meteor_Falls:
	walk_diag_northeast
	walk_diag_northeast
	walk_up
	walk_up
	step_end

WalkFromMid_MeteorFalls:
	walk_right
	walk_down
	step_end

MagmaGruntMove1:
	walk_right
	walk_right
	walk_up
	step_end

MagmaGruntMove2:
	delay_16
	delay_16
	walk_up
	step_end

PleaseSelectPkmn:
    .string "We have to help the\n"
	.string "PROFESSOR {PLAYER}!$"

RivalString_1:
    .string "{PLAYER}!\n"
	.string "What good timing!$"

RivalString_2:
    .string "Those guys are trying to hurt the\n"
	.string "PROFESSOR!\l"
	.string "Let's take them on together!$"

RivalString_3:
	.string "{PLAYER}, make yourself prepared!$"

MeteorFallsGrunt1_DefeatString:
    .string "Hehehe…\p"
	.string "Regardless of this outcome, I still\n"
	.string "have what I came for.$"

MeteorFallsGrunt2_DefeatString:
    .string "Heh…$"

MeteorFalls_1F_1R_EventScript_ProfCozmo:: @ 822BF25
	lock
	faceplayer
	goto_if_set FLAG_MET_PROF_COZMO, MeteorFalls_1F_1R_EventScript_MetCozmo
	msgbox MeteorFalls_1F_1R_Text_MeetProfCozmo, MSGBOX_DEFAULT
	release
	end

MeteorFalls_1F_1R_EventScript_MetCozmo:: @ 822BF3D
	msgbox MeteorFalls_1F_1R_Text_WhatsTeamMagmaDoingAtMtChimney, MSGBOX_DEFAULT
	release
	end

MeteorFalls_1F_1R_Text_WithThisMeteorite: @ 822BF47
	.string "{COLOR BLUE}Hehehe!\p"
	.string "With this METEORITE, that thing in\n"
	.string "the volcano will…$"

MeteorFalls_1F_1R_Text_DontExpectMercyFromMagma: @ 822BF84
	.string "{COLOR BLUE}Heh?\p"
	.string "I don't know who you are, but if you\n"
	.string "get in the way of TEAM MAGMA, don't\l"
	.string "expect any mercy!$"

MeteorFalls_1F_1R_Text_HoldItRightThereMagma: @ 822BFE4
	.string "{COLOR BLUE}Hold it right there, TEAM MAGMA!\p"
	.string "You're badly mistaken if you think you\n"
	.string "can have your way with the world!$"

MeteorFalls_1F_1R_Text_BeSeeingYouTeamAqua: @ 822C04E
	.string "{COLOR BLUE}Hehehe!\n"
	.string "Even TEAM AQUA joins us!\p"
	.string "But it's too much trouble to deal\n"
	.string "with you all…\p"
	.string "Heh, it doesn't matter!\p"
	.string "We've got the METEORITE, so off to\n"
	.string "our next destination we go!\p"
	.string "Hehehe! Be seeing you, you TEAM\n"
	.string "AQUA dingbats!$"

MeteorFalls_1F_1R_Text_ArchieSeenYouBefore: @ 822C11C
	.string "{COLOR BLUE}ARCHIE: Didn't I see you before?\n"
	.string "At SLATEPORT's MUSEUM?\p"
	.string "… … … … … …\n"
	.string "… … … … … …\p"
	.string "Ah, so your name is {PLAYER}.\p"
	.string "At the time, I thought you were one\n"
	.string "of TEAM MAGMA's goons.\p"
	.string "Humph…\n"
	.string "You're one odd kid.\p"
	.string "TEAM MAGMA is a dangerous group of\n"
	.string "total fanatics.\p"
	.string "They engage in destruction, claiming\n"
	.string "to expand the land mass.\p"
	.string "We, TEAM AQUA, have to stop them\n"
	.string "at all costs!$"

MeteorFalls_1F_1R_Text_BossWeShouldChaseMagma: @ 822C268
	.string "{COLOR BLUE}BOSS, we should give chase to\n"
	.string "TEAM MAGMA…$"

MeteorFalls_1F_1R_Text_ArchieYesNoTellingWhatMagmaWillDo: @ 822C292
	.string "{COLOR BLUE}ARCHIE: Yes, yes, we must!\n"
	.string "We've got to hurry.\p"
	.string "There's no telling what TEAM MAGMA\n"
	.string "will do!$"

MeteorFalls_1F_1R_Text_ArchieFarewell: @ 822C2FC
	.string "{COLOR BLUE}ARCHIE: {PLAYER}, you should keep\n"
	.string "an eye out for TEAM MAGMA, too.\p"
	.string "Farewell!$"

MeteorFalls_1F_1R_Text_MeetProfCozmo: @ 822C342
	.string "{COLOR BLUE}I… I'm COZMO…\n"
	.string "I'm a PROFESSOR…\p"
	.string "TEAM MAGMA asked me to guide them\n"
	.string "to METEOR FALLS…\p"
	.string "But they tricked me.\n"
	.string "They even took my METEORITE away…\p"
	.string "And then another similar bunch,\n"
	.string "TEAM AQUA showed up.\p"
	.string "After that…\n"
	.string "I don't understand any of it.\p"
	.string "But that TEAM MAGMA…\p"
	.string "What are they going to do with that\n"
	.string "METEORITE at MT. CHIMNEY?$"

MeteorFalls_1F_1R_Text_WhatsTeamMagmaDoingAtMtChimney: @ 822C47D
	.string "{COLOR BLUE}PROF. COZMO: But that TEAM MAGMA…\p"
	.string "What are they going to do with that\n"
	.string "METEORITE at MT. CHIMNEY?$"

RivalString_4:
    .string "MAY: No need to worry, didn't they\n"
	.string "mention something about a volcano?$"

RivalString_5:
    .string "BRENDAN: It's fine, what was that\n"
	.string "about a volcano they mentioned?$"

CozmoString_1:
    .string "{COLOR BLUE}PROF. COZMO: How observant!\p"
	.string "I must've been to nervous\n"
	.string "to have noticed!\p"
	.string "I must make my way there\n"
	.string "at once!$"

RivalString_6:
    .string "MAY: W-Wait!\n"
	.string "It's close to LAVARIDGE, right?\p"
	.string "We intend to stop by there, so\n"
	.string "while we are there, we can stop\l"
	.string "by and look for your METEORITE!$"

RivalString_7:
    .string "BRENDAN: H-Hold up!\n"
	.string "It's not far from LAVARIDGE, right?\p"
	.string "We are headed there next so we\n"
	.string "can look for your rock there!$"

CozmoString_2:
    .string "{COLOR BLUE}PROF. COZMO: You would do that for\n"
	.string "me?\p"
	.string "Those people seemed rather strong!\n"
	.string "I'm certain they'll be plenty more\l"
	.string "over there…$"

RivalString_8:
    .string "MAY: It'll be fine, we'll get that\n"
	.string "METEORITE back!$"

RivalString_9:
    .string "BRENDAN: Don't worry.\p"
	.string "It'll be back to you in no time.$"

RivalString_10:
    .string "MAY: Your POKÉMON are looking strong\n"
    .string "as ever, {PLAYER}!\l"
	.string "It was fun battling along side you!\p"
	.string "We should hurry over to ROUTE 112\n"
	.string "now.\p"
	.string "See you later!$"
	
RivalString_11:
    .string "BRENDAN: Your POKÉMON aren't looking to\n"
	.string "shabby, looks like you are training\l"
	.string "them well!\p"
	.string "Let us waste no more time, ROUTE 112\n"
	.string "here we come!$"

CozmoString_3:
    .string "{COLOR BLUE}PROF. COZMO: T-Thank you, really!\p"
	.string "Prehaps it's not much, but…\p"
	.string "Please, take this!$"

CozmoString_4:
    .string "{COLOR BLUE}You two are to nice!\n"
	.string "I'll stay here for a bit.\p"
	.string "If you are passing in FALLARBOR\n"
	.string "TOWN, my house is located there,\l"
	.string "next to the POKÉMART.\p"
	.string "Don't be shy to knock.\p"
	.string "And before you leave, allow me to\n"
	.string "heal your POKÉMON!$"
