.equ LOCALID_WANDAS_BF, 1
.set LOCALID_BRINEY, 5
.set LOCALID_GRUNT, 6
.set LOCALID_PEEKO, 7
.equ LOCALID_WANDA, 10

RusturfTunnel_MapScripts:: @ 822CE27
	map_script MAP_SCRIPT_ON_TRANSITION, RusturfTunnel_OnTransition
	map_script MAP_SCRIPT_ON_FRAME_TABLE, RusturfTunnel_OnFrame
	.byte 0

RusturfTunnel_OnFrame: @ 822CE32
	map_script_2 VAR_RUSTURF_TUNNEL_STATE, 4, RusturfTunnel_EventScript_ClearTunnelScene
	map_script_2 VAR_RUSTURF_TUNNEL_STATE, 5, RusturfTunnel_EventScript_ClearTunnelScene
	.2byte 0

RusturfTunnel_OnTransition: @ 822CE44
	compare VAR_RUSTURF_TUNNEL_STATE, 2
	call_if_eq RusturfTunnel_EventScript_SetAquaGruntAndPeekoPos
	end

RusturfTunnel_EventScript_SetAquaGruntAndPeekoPos:: @ 822CE50
	setobjectxyperm LOCALID_PEEKO, 14, 5
	setobjectxyperm LOCALID_GRUNT, 14, 6
	return

RusturfTunnel_EventScript_Wanda:: @ 822CE5F
	lock
	faceplayer
	msgbox RusturfTunnel_Text_BoyfriendOnOtherSideOfRock, MSGBOX_DEFAULT
	closemessage
	applymovement VAR_LAST_TALKED, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

RusturfTunnel_EventScript_WandasBoyfriend:: @ 822CE76
	lock
	faceplayer
	goto_if_set FLAG_TEMP_1, RusturfTunnel_EventScript_AlreadySpokenTo
	setflag FLAG_TEMP_1
	msgbox RusturfTunnel_Text_WhyCantTheyKeepDigging, MSGBOX_DEFAULT
	closemessage
	applymovement VAR_LAST_TALKED, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

RusturfTunnel_EventScript_AlreadySpokenTo:: @ 822CE99
	msgbox RusturfTunnel_Text_ToGetToVerdanturf, MSGBOX_DEFAULT
	closemessage
	applymovement VAR_LAST_TALKED, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

RusturfTunnel_EventScript_ClearTunnelScene:: @ 822CEAE
	lockall
	compare VAR_TEMP_1, 1
	call_if_eq RusturfTunnel_EventScript_FaceWandasBoyfriend1
	compare VAR_TEMP_1, 2
	call_if_eq RusturfTunnel_EventScript_FaceWandasBoyfriend2
	compare VAR_TEMP_1, 3
	call_if_eq RusturfTunnel_EventScript_FaceWandasBoyfriend3
	call RusturfTunnel_EventScript_WandasBoyfriendNotice
	msgbox RusturfTunnel_Text_YouShatteredBoulderTakeHM, MSGBOX_DEFAULT
	compare VAR_TEMP_1, 2
	call_if_eq RusturfTunnel_EventScript_WandasBoyfriendApproachPlayer
	compare VAR_TEMP_1, 3
	call_if_eq RusturfTunnel_EventScript_WandasBoyfriendApproachPlayer
	giveitem ITEM_HM04
	setflag FLAG_RECEIVED_HM04
	msgbox RusturfTunnel_Text_ExplainStrength, MSGBOX_DEFAULT
	closemessage
	compare VAR_TEMP_1, 1
	call_if_eq RusturfTunnel_EventScript_BoyfriendApproachWanda1
	compare VAR_TEMP_1, 2
	call_if_eq RusturfTunnel_EventScript_BoyfriendApproachWanda2
	compare VAR_TEMP_1, 3
	call_if_eq RusturfTunnel_EventScript_BoyfriendApproachWanda3
	msgbox RusturfTunnel_Text_WandaReunion, MSGBOX_DEFAULT
	closemessage
	compare VAR_TEMP_1, 1
	call_if_eq RusturfTunnel_EventScript_WandaAndBoyfriendExit1
	compare VAR_TEMP_1, 2
	call_if_eq RusturfTunnel_EventScript_WandaAndBoyfriendExit
	compare VAR_TEMP_1, 3
	call_if_eq RusturfTunnel_EventScript_WandaAndBoyfriendExit
	call RusturfTunnel_EventScript_SetRusturfTunnelOpen
	releaseall
	end

RusturfTunnel_EventScript_BoyfriendApproachWanda1:: @ 822CF5D
	applymovement OBJ_EVENT_ID_PLAYER, RusturfTunnel_Movement_PlayerWatchBoyfriend1
	applymovement LOCALID_WANDAS_BF, RusturfTunnel_Movement_BoyfriendApproachWanda1
	waitmovement 0
	return

RusturfTunnel_EventScript_BoyfriendApproachWanda2:: @ 822CF6F
	applymovement OBJ_EVENT_ID_PLAYER, RusturfTunnel_Movement_PlayerWatchBoyfriend
	applymovement LOCALID_WANDAS_BF, RusturfTunnel_Movement_BoyfriendApproachWanda
	waitmovement 0
	applymovement LOCALID_WANDA, Common_Movement_WalkInPlaceFastestDown
	waitmovement 0
	return

RusturfTunnel_EventScript_BoyfriendApproachWanda3:: @ 822CF8B
	applymovement OBJ_EVENT_ID_PLAYER, RusturfTunnel_Movement_PlayerWatchBoyfriend
	applymovement LOCALID_WANDAS_BF, RusturfTunnel_Movement_BoyfriendApproachWanda
	waitmovement 0
	applymovement LOCALID_WANDA, Common_Movement_WalkInPlaceFastestDown
	waitmovement 0
	return

RusturfTunnel_EventScript_FaceWandasBoyfriend1:: @ 822CFA7
	applymovement LOCALID_WANDAS_BF, Common_Movement_WalkInPlaceFastestUp
	waitmovement 0
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFastestDown
	waitmovement 0
	return

RusturfTunnel_EventScript_FaceWandasBoyfriend2:: @ 822CFBC
	applymovement LOCALID_WANDAS_BF, RusturfTunnel_Movement_BoyfriendFaceRight
	waitmovement 0
	return

RusturfTunnel_EventScript_FaceWandasBoyfriend3:: @ 822CFC7
	return

RusturfTunnel_EventScript_WandasBoyfriendApproachPlayer:: @ 822CFC8
	closemessage
	applymovement LOCALID_WANDAS_BF, RusturfTunnel_Movement_WandasBoyfriendApproachPlayer
	waitmovement 0
	return

RusturfTunnel_EventScript_WandaAndBoyfriendExit1:: @ 822CFD4
	applymovement LOCALID_WANDA, RusturfTunnel_Movement_WandaExit1
	applymovement LOCALID_WANDAS_BF, RusturfTunnel_Movement_WandasBoyfriendExit1
	waitmovement 0
	return

RusturfTunnel_EventScript_WandaAndBoyfriendExit:: @ 822CFE6
	applymovement OBJ_EVENT_ID_PLAYER, RusturfTunnel_Movement_PlayerWatchWandaExit
	applymovement LOCALID_WANDA, RusturfTunnel_Movement_WandaExit
	applymovement LOCALID_WANDAS_BF, RusturfTunnel_Movement_WandasBoyfriendExit
	waitmovement 0
	return

RusturfTunnel_EventScript_WandasBoyfriendNotice:: @ 822CFFF
	playse SE_PIN
	applymovement LOCALID_WANDAS_BF, Common_Movement_ExclamationMark
	waitmovement 0
	applymovement LOCALID_WANDAS_BF, Common_Movement_Delay48
	waitmovement 0
	return

RusturfTunnel_Movement_WandaExit1: @ 822D017
	walk_right
	walk_right
	walk_right
	walk_right
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	step_end

RusturfTunnel_Movement_WandaExit: @ 822D023
	walk_right
	walk_right
	walk_right
	walk_right
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	step_end

RusturfTunnel_Movement_PlayerWatchWandaExit: @ 822D02F
	delay_8
	walk_in_place_fastest_up
	delay_16
	delay_16
	walk_in_place_fastest_right
	step_end

RusturfTunnel_Movement_Unused1: @ 822D035
	walk_left
	walk_in_place_fastest_right
	step_end

RusturfTunnel_Movement_Unused2: @ 822D038
	walk_down
	walk_in_place_fastest_up
	delay_8
	walk_in_place_fastest_right
	step_end

RusturfTunnel_Movement_Unused3: @ 822D03D
	walk_up
	walk_in_place_fastest_down
	delay_8
	walk_in_place_fastest_right
	step_end

RusturfTunnel_Movement_PlayerWatchBoyfriend1: @ 822D042
	walk_left
	walk_in_place_fastest_right
	step_end

RusturfTunnel_Movement_PlayerWatchBoyfriend: @ 822D045
	walk_right
	walk_in_place_fastest_left
	step_end

RusturfTunnel_Movement_BoyfriendFaceRight: @ 822D048
	walk_up
	walk_in_place_fastest_right
	step_end

RusturfTunnel_Movement_WandasBoyfriendExit1: @ 822D04B
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	step_end

RusturfTunnel_Movement_WandasBoyfriendExit: @ 822D058
	walk_up
	walk_right
	walk_right
	walk_right
	walk_right
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	step_end

RusturfTunnel_Movement_WandasBoyfriendApproachPlayer: @ 822D065
	walk_right
	step_end

RusturfTunnel_Movement_BoyfriendApproachWanda1: @ 822D067
	walk_in_place_fast_up
	walk_in_place_fast_up
	walk_fast_up
	walk_fast_right
	step_end

RusturfTunnel_Movement_BoyfriendApproachWanda: @ 822D06C
	walk_in_place_fast_right
	walk_in_place_fast_right
	walk_fast_right
	walk_in_place_fastest_up
	step_end

RusturfTunnel_EventScript_TunnelBlockagePos1:: @ 822D071
	setvar VAR_TEMP_1, 1
	end

RusturfTunnel_EventScript_TunnelBlockagePos2:: @ 822D077
	setvar VAR_TEMP_1, 2
	end

RusturfTunnel_EventScript_TunnelBlockagePos3:: @ 822D07D
	setvar VAR_TEMP_1, 3
	end

RusturfTunnel_EventScript_AquaGruntBackUp:: @ 822D083
	lockall
	msgbox RusturfTunnel_Text_ComeAndGetSome, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_GRUNT, RusturfTunnel_Movement_GruntAndPeekoBackUp
	applymovement LOCALID_PEEKO, RusturfTunnel_Movement_GruntAndPeekoBackUp
	waitmovement 0
	
	delay 20
	playse SE_PIN
	applymovement 11, WalkInPlaceLeftExlamation
	delay 40
	msgbox Wally_Talk_RusturfTunnel_1, MSGBOX_DEFAULT
	closemessage
	applymovement 11, Common_Movement_WalkInPlaceRight
	waitmovement 0
	call getplayerpos_RusturfTunnel
	msgbox Wally_Talk_RusturfTunnel_2, MSGBOX_DEFAULT
	playbgm MUS_ENCOUNTER_AQUA, 1
	msgbox RusturfTunnel_Text_GruntIntro, MSGBOX_DEFAULT
	closemessage
	applymovement 6, AquaGruntBattle
	waitmovement 0
	call DoubleTagBattle

DoubleTagBattle::
    choose_mons
    compare VAR_RESULT, 0
    goto_if_eq CancelParty
    multi_2_vs_1 TRAINER_GRUNT_RUSTURF_TUNNEL, RusturfTunnel_Text_GruntDefeat, TRAINER_WALLY_RUSTURF, TRAINER_BACK_PIC_WALLY
	specialvar VAR_RESULT, GetBattleOutcome
	compare VAR_RESULT, B_OUTCOME_LOST
	goto_if_eq RusturfTagLostBattle
    fadedefaultbgm
	msgbox RusturfTunnel_Text_GruntTakePackage, MSGBOX_DEFAULT
	giveitem ITEM_DEVON_GOODS
	closemessage
	playse SE_WALL_HIT
	applymovement 11, Common_Movement_WalkInPlaceDown
	applymovement OBJ_EVENT_ID_PLAYER, RusturfTunnel_Movement_PushPlayerAsideForGrunt
	applymovement LOCALID_GRUNT, RusturfTunnel_Movement_GruntEscape
	waitmovement 0
	playse SE_EXIT
	removeobject LOCALID_GRUNT
	delay 80
	playse SE_EXIT
	addobject LOCALID_BRINEY
	applymovement LOCALID_BRINEY, RusturfTunnel_Movement_BrineyApproachPeeko1
	applymovement OBJ_EVENT_ID_PLAYER, RusturfTunnel_Movement_PlayerMoveAsideForBriney
	applymovement LOCALID_PEEKO, WingullMove_RusturfTunnel
	waitmovement 0
	msgbox RusturfTunnel_Text_PeekoGladToSeeYouSafe, MSGBOX_DEFAULT
	applymovement LOCALID_BRINEY, Common_Movement_FacePlayer
	waitmovement 0
	msgbox RusturfTunnel_Text_ThankYouLetsGoHomePeeko
	applymovement 11, Common_Movement_WalkInPlaceDown
	waitmovement 0
	checkplayergender
	compare VAR_RESULT, MALE
	call_if_eq RusturfBoy
	compare VAR_RESULT, FEMALE
	call_if_eq RusturfGirl
	applymovement 5, Common_Movement_WalkInPlaceUp
	waitmovement 0
	msgbox RusturfTunnel_Text_ThankYouLetsGoHomePeeko2, MSGBOX_DEFAULT
	applymovement 5, Common_Movement_WalkInPlaceRight
	waitmovement 0
	msgbox RusturfTunnel_Text_ThankYouLetsGoHomePeeko3, MSGBOX_DEFAULT
	playmoncry SPECIES_WINGULL, 0
	waitbuttonpress
	waitmoncry
	closemessage
	applymovement OBJ_EVENT_ID_PLAYER, RusturfTunnel_Movement_PlayerWatchBrineyExit
	applymovement LOCALID_BRINEY, RusturfTunnel_Movement_BrineyExit
	applymovement LOCALID_PEEKO, RusturfTunnel_Movement_PeekoExit
	waitmovement 0
	playse SE_EXIT
	delay 25
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceRight
	applymovement 11, Common_Movement_WalkInPlaceLeft
	waitmovement 0
	msgbox Wally_Talk_RusturfTunnel_4, MSGBOX_DEFAULT
	applymovement 11, Common_Movement_WalkInPlaceRight
	delay 25
	msgbox Wally_Talk_RusturfTunnel_5, MSGBOX_DEFAULT
	applymovement 11, Common_Movement_WalkInPlaceLeft
	waitmovement 0
	delay 25
	msgbox Wally_Talk_RusturfTunnel_6, MSGBOX_DEFAULT
	playse SE_PIN
	applymovement 11, Common_Movement_ExclamationMark
	waitmovement 0
	delay 40
	msgbox Wally_Talk_RusturfTunnel_7, MSGBOX_DEFAULT
	closemessage
	applymovement OBJ_EVENT_ID_PLAYER, RusturfTunnel_Movement_PlayerObserveWallyLeaving
	applymovement 11, RusturfTunnel_Movement_WallyLeaveCave
	waitmovement 0
	delay 30
	playse SE_EXIT
	removeobject 11
	removeobject LOCALID_BRINEY
	removeobject LOCALID_PEEKO
	copyobjectxytoperm LOCALID_GRUNT
	copyobjectxytoperm LOCALID_PEEKO
	setvar VAR_RUSTURF_TUNNEL_STATE, 3
	clearflag FLAG_DEVON_GOODS_STOLEN
	setflag FLAG_RECOVERED_DEVON_GOODS
	setvar VAR_RUSTBORO_CITY_STATE, 4
	setvar VAR_BRINEY_HOUSE_STATE, 1
	setflag FLAG_HIDE_ROUTE_116_MR_BRINEY
	release
	end

RusturfTagLostBattle::
	special Script_FadeOutMapMusic
	waitstate
	fadescreen 1
	special SetCB2WhiteOut
	waitstate
	end

CancelParty:
    msgbox DontRun, MSGBOX_DEFAULT
	closemessage
	call DoubleTagBattle

RusturfBoy:
	msgbox Wally_Talk_RusturfTunnel_3_BOY, MSGBOX_DEFAULT
	return
	
RusturfGirl:
	msgbox Wally_Talk_RusturfTunnel_3_GIRL, MSGBOX_DEFAULT
	return

getplayerpos_RusturfTunnel::
    getplayerxy VAR_TEMP_0, VAR_TEMP_1
    compare VAR_TEMP_1, 5
    goto_if_le PlayerLocatedUp_RusturfTunnel
    compare VAR_TEMP_1, 6
    goto_if_le PlayerLocatedBot_RusturfTunnel
	
PlayerLocatedUp_RusturfTunnel:
    applymovement OBJ_EVENT_ID_PLAYER, WalkFromUp_RusturfTunnel
    waitmovement 0
    return

PlayerLocatedBot_RusturfTunnel:
    applymovement OBJ_EVENT_ID_PLAYER, WalkFromBot_RusturfTunnel
    waitmovement 0
    return
	
RusturfTunnel_Movement_GruntAndPeekoBackUp: @ 822D0AB
	lock_facing_direction
	walk_right
	unlock_facing_direction
	step_end

RusturfTunnel_EventScript_Peeko:: @ 822D0AF
	lock
	faceplayer
	waitse
	playmoncry SPECIES_WINGULL, 0
	msgbox RusturfTunnel_Text_Peeko, MSGBOX_DEFAULT
	waitmoncry
	release
	end

WalkInPlaceLeftExlamation:
    walk_in_place_fast_left
	emote_exclamation_mark
	step_end

RusturfTunnel_Movement_PushPlayerAsideForGrunt: @ 822D178
	face_down
	lock_facing_direction
	walk_fast_left
	face_down
	walk_fast_up
	unlock_facing_direction
	walk_in_place_fastest_left
	step_end

RusturfTunnel_Movement_PlayerObserveWallyLeaving:
    delay_16
	delay_16
	walk_in_place_fast_down
    delay_16
	delay_16
	walk_in_place_fast_left
	step_end
	
RusturfTunnel_Movement_WallyLeaveCave:
	walk_down
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	step_end

RusturfTunnel_Movement_PlayerMoveAsideForBriney: @ 822D17E
    delay_16
	delay_16
	delay_16
	delay_16
	delay_16
	delay_16
	walk_in_place_fast_down
	step_end

WingullMove_RusturfTunnel:
    delay_16
	delay_16
	delay_16
	delay_16
	delay_16
	delay_16
	delay_16
	delay_16
	jump_in_place_left
	jump_in_place_left
	walk_fast_left
	walk_fast_down
	walk_fast_left
	walk_fast_left
	walk_fast_left
	step_end

AquaGruntBattle:
    walk_fast_left
	walk_fast_left
	walk_fast_left
	step_end
	
WalkFromUp_RusturfTunnel:
    walk_down
	walk_right
	step_end

WalkFromBot_RusturfTunnel:
	walk_right
	step_end

RusturfTunnel_Movement_GruntEscape: @ 822D181
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_down
	walk_fast_down
	walk_fast_down
	walk_fast_down
	walk_fast_down
	step_end

RusturfTunnel_Movement_BrineyApproachPeeko1: @ 822D18B
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	step_end

RusturfTunnel_Movement_BrineyExit: @ 822D193
	walk_left
	walk_left
	walk_left
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

RusturfTunnel_Movement_PlayerWatchBrineyExit: @ 822D19F
	delay_16
	delay_8
	delay_4
	walk_in_place_fastest_left
	step_end

RusturfTunnel_Movement_BrineyApproachPeeko2: @ 822D1A4
    delay_16
	delay_16
	delay_16
	delay_16
	delay_16
	delay_16
	delay_16
	delay_16
	jump_in_place_left
	jump_in_place_left
	walk_fast_left
	walk_fast_down
	walk_fast_left
	walk_fast_left
	walk_fast_left
	step_end

RusturfTunnel_Movement_PeekoExit: @ 822D1A7
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	step_end

RusturfTunnel_EventScript_Mike:: @ 822D1B1
	trainerbattle_single TRAINER_MIKE_2, RusturfTunnel_Text_MikeIntro, RusturfTunnel_Text_MikeDefeat
	msgbox RusturfTunnel_Text_MikePostBattle, MSGBOX_AUTOCLOSE
	end

Wally_Talk_RusturfTunnel_1:
    .string "{COLOR BLUE}Wally: {PLAYER}!$"
	
Wally_Talk_RusturfTunnel_2:
    .string "{COLOR BLUE}That looks like him, over there!$"
	
Wally_Talk_RusturfTunnel_3_BOY:
    .string "{COLOR BLUE}Wally: This is {PLAYER}!\n"
	.string "He's a very talanted trainer.\p"
	.string "I wouldn't been able to save\n"
	.string "Peeko if it weren't for him!$"

Wally_Talk_RusturfTunnel_3_GIRL:
    .string "{COLOR BLUE}Wally: This is {PLAYER}!\n"
	.string "She's a very talanted trainer.\p"
	.string "I wouldn't been able to save\n"
	.string "Peeko if it weren't for her!$"

Wally_Talk_RusturfTunnel_4:
    .string "{COLOR BLUE}WALLY: Wasn't that something…\n"
	.string "I'm still shaking!\p"
	.string "If it weren't for you…\n"
	.string "I would've left Peeko with that man.\p"
	.string "But you gave me courage today\n"
	.string "{PLAYER}!\l"
	.string "Thank you…\p"
	.string "A-anyways… This tunnel connects\n"
	.string "Route 116 together with Verdanturf.\p"
	.string "I figured I could take a shortcut…$"

Wally_Talk_RusturfTunnel_5:
	.string "{COLOR BLUE}But it seems the path is blocked\n"
	.string "by some boulders.$"

Wally_Talk_RusturfTunnel_6:
	.string "{COLOR BLUE}Looks like I have to go the long\n"
	.string "way around!$"

Wally_Talk_RusturfTunnel_7:
	.string "{COLOR BLUE}Oh! I just remembered!\p"
	.string "I heard somewhere that the\n"
	.string "wild Whismur was getting upset\l"
	.string "by heavy machinery here lately.\p"
	.string "I hope the battle didn't disturb\n"
	.string "them!\p"
	.string "We'd better leave for now.\n"
	.string "I wouldn't want to upset them.\p"
	.string "See you later, {PLAYER}!$"

RusturfTunnel_Text_ComeAndGetSome: @ 822D1C8
	.string "{COLOR BLUE}???: What, are you coming?\n"
	.string "Come and get some, then!$"

RusturfTunnel_Text_Peeko: @ 822D1F7
	.string "PEEKO: Pii pihyoh!$"

RusturfTunnel_Text_GruntIntro: @ 822D20A
	.string "{COLOR BLUE}???: Grah, keelhaul it all!\p"
	.string "This hostage Pokémon turned out to\n"
	.string "be worthless!\p"
	.string "And to think I made a getaway…\n"
	.string "In this tunnel to nowhere!\p"
	.string "Hey! You two!\n"
	.string "So you want to battle me?\p"
	.string "Two against one?\n"
	.string "You're not playing fair!\p"
	.string "No matter, I shall crush you both!$"

RusturfTunnel_Text_GruntDefeat: @ 822D2B0
	.string "Urrrggh! My career in crime comes\n"
	.string "to a dead end!$"

RusturfTunnel_Text_GruntTakePackage: @ 822D2E1
	.string "{COLOR BLUE}???: This is plain not right…\p"
	.string "The BOSS told me this would be a\n"
	.string "slick-and-easy job to pull.\p"
	.string "All I had to do was steal some\n"
	.string "package from DEVON.\p"
	.string "Tch!\p"
	.string "You want it back that badly, take it!$"

RusturfTunnel_Text_PeekoGladToSeeYouSafe: @ 822D395
	.string "{COLOR BLUE}MR. BRINEY: PEEKO!\n"
	.string "Am I glad to see you're safe!$"

RusturfTunnel_Text_ThankYouLetsGoHomePeeko: @ 822D3BA
	.string "{COLOR BLUE}PEEKO owes her life to you!\p"
	.string "They call me MR. BRINEY.\n"
	.string "And, you are?$"

RusturfTunnel_Text_ThankYouLetsGoHomePeeko2: @ 822D3BA
	.string "{COLOR BLUE}MR. BRINEY: Ah, so you are {PLAYER}{KUN}!\n"
	.string "I sincerely thank you both!\p"
	.string "Now, if there's anything that troubles\n"
	.string "you, don't hesitate to tell me!\p"
	.string "You can usually find me in my cottage\n"
	.string "by the sea near PETALBURG WOODS.$"

RusturfTunnel_Text_ThankYouLetsGoHomePeeko3: @ 822D3BA
	.string "{COLOR BLUE}Come, PEEKO, we should make our\n"
	.string "way home.\p"
	.string "{COLOR DARK_GREY}PEEKO: Pihyoh!$"

RusturfTunnel_Text_WhyCantTheyKeepDigging: @ 822D510
	.string "… …\p"
	.string "Why can't they keep digging?\n"
	.string "Is the bedrock too hard?\p"
	.string "My beloved awaits me in VERDANTURF\n"
	.string "TOWN just beyond here…\p"
	.string "If RUSTBORO and VERDANTURF were\n"
	.string "joined by this tunnel, I could\l"
	.string "visit her every day…\p"
	.string "But this…\n"
	.string "What am I to do?$"

RusturfTunnel_Text_ToGetToVerdanturf: @ 822D5F3
	.string "To get from RUSTBORO to VERDANTURF,\n"
	.string "you need to go to DEWFORD, then pass\l"
	.string "through SLATEPORT and MAUVILLE…$"

RusturfTunnel_Text_YouShatteredBoulderTakeHM: @ 822D65C
	.string "{COLOR BLUE}Wow! You shattered that boulder\n"
	.string "blocking the way.\p"
	.string "To show you how much I appreciate\n"
	.string "it, I'd like you to have this HM.$"

RusturfTunnel_Text_ExplainStrength: @ 822D6D2
	.string "{COLOR BLUE}That HM contains STRENGTH.\p"
	.string "If a muscular POKéMON were to learn\n"
	.string "that, it would be able to move even\l"
	.string "large boulders.$"

RusturfTunnel_Text_WandaReunion: @ 822D745
	.string "{COLOR BLUE}WANDA!\n"
	.string "Now I can see you anytime!\p"
	.string "{COLOR RED}WANDA: That's… wonderful.\p"
	.string "Please, take some rest at my home.$"

RusturfTunnel_Text_BoyfriendOnOtherSideOfRock: @ 822D7A3
	.string "On the other side of this rock…\n"
	.string "My boyfriend is there.\p"
	.string "He… He's not just digging the tunnel\n"
	.string "to come see me.\p"
	.string "He works his hands raw and rough\n"
	.string "for the benefit of everyone.$"

RusturfTunnel_Text_MikeIntro: @ 822D84D
	.string "What do you call a wild man up in\n"
	.string "the mountains?\l"
	.string "A mountain man, right?\p"
	.string "So why don't they call a POKéMON in\n"
	.string "the mountains a mountain POKéMON?$"

RusturfTunnel_Text_MikeDefeat: @ 822D8DB
	.string "My POKéMON…\n"
	.string "Ran out of power…$"

RusturfTunnel_Text_MikePostBattle: @ 822D8F9
	.string "They halted development here to\n"
	.string "protect POKéMON, right?\l"
	.string "There's a feel-good story!$"

DontRun:
    .string "{COLOR DARK_GREY}You have to choose a\n"
	.string "team to battle with!$"
