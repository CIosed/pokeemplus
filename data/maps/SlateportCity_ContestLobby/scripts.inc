SlateportCity_ContestLobby_MapScripts:: @ 8155411
	map_script 3, SlateportCity_ContestLobby_MapScript1_155417
	.byte 0

SlateportCity_ContestLobby_MapScript1_155417:: @ 8155417
	call SlateportCity_ContestLobby_EventScript_1AE188 
	end

SlateportCity_ContestLobby_EventScript_15541D:: @ 815541D
	setvar VAR_0x800B, 7
	setvar VAR_CONTEST_RANK, 2
	call SlateportCity_ContestLobby_EventScript_1A4E92
	call SlateportCity_ContestLobby_EventScript_155448
	special SetContestTrainerGfxIds
	call SlateportCity_ContestLobby_EventScript_15FBDB
	setvar VAR_CONTEST_LOCATION, 3
	warp MAP_LINK_CONTEST_ROOM1, 255, 7, 5
	waitstate
	end

SlateportCity_ContestLobby_EventScript_155448:: @ 8155448
	lockall
	applymovement 1, SlateportCity_ContestLobby_Movement_1554CC
	waitmovement 0
	playse SE_HASHI
	setmetatile 4, 2, METATILE_Contest_WallShadow, 1
	setmetatile 4, 3, METATILE_Contest_FloorShadow, 1
	special DrawWholeMapView
	applymovement 1, SlateportCity_ContestLobby_Movement_1554CF
	waitmovement 0
	playse SE_HASHI
	setmetatile 4, 2, METATILE_Contest_CounterFlap_Top, 1
	setmetatile 4, 3, METATILE_Contest_CounterFlap_Bottom, 1
	special DrawWholeMapView
	delay 20
	applymovement 1, SlateportCity_ContestLobby_Movement_1554DC
	waitmovement 0
	applymovement 255, SlateportCity_ContestLobby_Movement_1554CA
	waitmovement 0
	msgbox SlateportCity_ContestLobby_Text_1A6832, 4
	closemessage
	applymovement 1, SlateportCity_ContestLobby_Movement_1554D3
	applymovement 255, SlateportCity_ContestLobby_Movement_1554C0
	waitmovement 0
	releaseall
	return

SlateportCity_ContestLobby_Movement_1554C0:: @ 81554C0
	walk_left
	walk_left
	walk_left
	walk_left
	walk_up
	walk_up
	walk_up
	delay_8
	set_invisible
	step_end

SlateportCity_ContestLobby_Movement_1554CA:: @ 81554CA
	walk_in_place_fastest_left
	step_end

SlateportCity_ContestLobby_Movement_1554CC:: @ 81554CC
	walk_left
	walk_in_place_fastest_down
	step_end

SlateportCity_ContestLobby_Movement_1554CF:: @ 81554CF
	walk_down
	walk_down
	walk_in_place_fastest_up
	step_end

SlateportCity_ContestLobby_Movement_1554D3:: @ 81554D3
	walk_left
	walk_left
	walk_left
	walk_up
	walk_up
	walk_up
	delay_8
	set_invisible
	step_end

SlateportCity_ContestLobby_Movement_1554DC:: @ 81554DC
	walk_in_place_fastest_right
	step_end

SlateportCity_ContestLobby_EventScript_1554DE:: @ 81554DE
	msgbox SlateportCity_ContestLobby_Text_17C937, 2
	end

SlateportCity_ContestLobby_EventScript_1554E7:: @ 81554E7
	msgbox SlateportCity_ContestLobby_Text_17C9D5, 2
	end

SlateportCity_ContestLobby_EventScript_1554F0:: @ 81554F0
	msgbox SlateportCity_ContestLobby_Text_17CAEC, 2
	end

SlateportCity_ContestLobby_EventScript_1554F9:: @ 81554F9
	lockall
	goto_if_set FLAG_RECEIVED_POKEBLOCK_CASE, SlateportCity_ContestLobby_EventScript_155526
	applymovement 7, SlateportCity_ContestLobby_Movement_1A0839
	waitmovement 0
	msgbox SlateportCity_ContestLobby_Text_17CA67, 4
	giveitem_std ITEM_POKEBLOCK_CASE
	setflag FLAG_RECEIVED_POKEBLOCK_CASE
	releaseall
	end

SlateportCity_ContestLobby_EventScript_155526:: @ 8155526
	msgbox SlateportCity_ContestLobby_Text_17CA88, 2
	end

SlateportCity_ContestLobby_EventScript_15552F:: @ 815552F
	lockall
	fadescreen 1
	drawcontestwinner 3
	releaseall
	end

SlateportCity_ContestLobby_EventScript_155536:: @ 8155536
	msgbox SlateportCity_ContestLobby_Text_1B7225, 2
	end

LilycoveCity_ContestLobby_EventScript_15908D:: @ 815908D
SlateportCity_ContestLobby_EventScript_15908D:: @ 815908D
	lockall
	special ShowBerryBlenderRecordWindow
	waitbuttonpress
	special RemoveRecordsWindow
	releaseall
	end

//new shit
	
FallarborTown_ContestLobby_EventScript_1AE0B6:: @ 81AE0B6
LilycoveCity_ContestLobby_EventScript_1AE0B6:: @ 81AE0B6
SlateportCity_ContestLobby_EventScript_1AE0B6:: @ 81AE0B6
VerdanturfTown_ContestLobby_EventScript_1AE0B6:: @ 81AE0B6
	lock
	faceplayer
	goto_if_set FLAG_TEMP_2, FallarborTown_ContestLobby_EventScript_1AE17E
	setvar VAR_0x8005, 6
	special InterviewBefore
	compare VAR_RESULT, 1
	goto_if_eq FallarborTown_ContestLobby_EventScript_1AE17E
	copyvar VAR_0x8009, VAR_0x8006
	msgbox FallarborTown_ContestLobby_Text_1A6F7C, MSGBOX_YESNO
	compare VAR_RESULT, YES
	goto_if_eq FallarborTown_ContestLobby_EventScript_1AE0F8
	compare VAR_RESULT, NO
	goto_if_eq FallarborTown_ContestLobby_EventScript_1AE12D
	end
	
FallarborTown_ContestLobby_EventScript_1AE188:: @ 81AE188
LilycoveCity_ContestLobby_EventScript_1AE188:: @ 81AE188
SlateportCity_ContestLobby_EventScript_1AE188:: @ 81AE188
VerdanturfTown_ContestLobby_EventScript_1AE188:: @ 81AE188
	compare VAR_LINK_CONTEST_ROOM_STATE, 2
	goto_if_ne FallarborTown_ContestLobby_EventScript_1AE1FE
	setvar VAR_0x8005, 6
	special InterviewBefore
	compare VAR_RESULT, 1
	goto_if_eq FallarborTown_ContestLobby_EventScript_1AE1FE
	switch VAR_CONTEST_LOCATION
	case 0, FallarborTown_ContestLobby_EventScript_1AE1FE
	case 2, FallarborTown_ContestLobby_EventScript_1AE1EE
	case 1, FallarborTown_ContestLobby_EventScript_1AE1F2
	case 3, FallarborTown_ContestLobby_EventScript_1AE1F6
	case 4, FallarborTown_ContestLobby_EventScript_1AE1FA
	case 5, FallarborTown_ContestLobby_EventScript_1AE1FE
	end
	
SlateportCity_ContestLobby_Movement_1A0839::
	face_player
	step_end

@ 81A083B
	face_away_player
	step_end
	
	
FallarborTown_ContestLobby_EventScript_1A4E92:: @ 81A4E92
LilycoveCity_ContestLobby_EventScript_1A4E92:: @ 81A4E92
SlateportCity_ContestLobby_EventScript_1A4E92:: @ 81A4E92
VerdanturfTown_ContestLobby_EventScript_1A4E92:: @ 81A4E92
	lock
	faceplayer
	checkitem ITEM_CONTEST_PASS, 1
	compare VAR_RESULT, 0
	call_if_eq FallarborTown_ContestLobby_EventScript_1A4EDD
	compare VAR_CONTEST_PRIZE_PICKUP, 0
	goto_if_ne FallarborTown_ContestLobby_EventScript_1A4F4E
	goto_if_set FLAG_TEMP_1, FallarborTown_ContestLobby_EventScript_1A4F8F
	bufferstdstring 0, VAR_0x800B
	msgbox FallarborTown_ContestLobby_Text_1A5DFC, 4
	checkitem ITEM_CONTEST_PASS, 1
	compare VAR_RESULT, 0
	goto_if_eq FallarborTown_ContestLobby_EventScript_1A4EE1
	setflag FLAG_TEMP_1
	goto FallarborTown_ContestLobby_EventScript_1A4F8F
	end

FallarborTown_ContestLobby_EventScript_15FBDB:: @ 815FBDB
LilycoveCity_ContestLobby_EventScript_15FBDB:: @ 815FBDB
SlateportCity_ContestLobby_EventScript_15FBDB:: @ 815FBDB
VerdanturfTown_ContestLobby_EventScript_15FBDB:: @ 815FBDB
	checkplayergender
	compare VAR_RESULT, 0
	goto_if_eq FallarborTown_ContestLobby_EventScript_15FBF3
	compare VAR_RESULT, 1
	goto_if_eq FallarborTown_ContestLobby_EventScript_15FBF9
	return
	
FallarborTown_ContestLobby_Text_1A6832:: @ 81A6832
LilycoveCity_ContestLobby_Text_1A6832:: @ 81A6832
SlateportCity_ContestLobby_Text_1A6832:: @ 81A6832
VerdanturfTown_ContestLobby_Text_1A6832:: @ 81A6832
	.string "Please come in through here.\n"
	.string "Good luck!$"
	
SlateportCity_ContestLobby_Text_17C937:: @ 817C937
	.string "I want to raise a POKéMON that's\n"
	.string "the ultimate in “great” for both\l"
	.string "battles and CONTESTS.\p"
	.string "It's vexing, trying to figure out\n"
	.string "which moves I should make it learn.$"
	
SlateportCity_ContestLobby_Text_17C9D5:: @ 817C9D5
	.string "Do any of your friends have any\n"
	.string "BERRIES?\p"
	.string "You can use that BERRY BLENDER and\n"
	.string "make {POKEBLOCK}S with your friends!\p"
	.string "You should try it - it's a lot of fun!$"

SlateportCity_ContestLobby_Text_17CA67:: @ 817CA67
	.string "I have two, so you can have one!$"

SlateportCity_ContestLobby_Text_17CA88:: @ 817CA88
	.string "Make {POKEBLOCK}S and put them in there.\p"
	.string "When you make a {POKEBLOCK}, everyone\n"
	.string "has to put in a different BERRY.$"

SlateportCity_ContestLobby_Text_17CAEC:: @ 817CAEC
	.string "If you win a CONTEST, they put up a\n"
	.string "poster of your POKéMON on the wall.\p"
	.string "It will have a portrait of your\n"
	.string "POKéMON and both your names.$"
	
//SlateportCity_ContestLobby_Text_1B7225:: @ 81B7225
//	.string "Let's get blending already!$"
	
	

	
//new new shit
FallarborTown_ContestLobby_EventScript_1AE17E:: @ 81AE17E
	msgbox FallarborTown_ContestLobby_Text_1A72A8, 4
	release
	end
	
FallarborTown_ContestLobby_Text_1A6F7C:: @ 81A6F7C
	.string "Oh, hello! You were in a POKéMON CONTEST,\n"
	.string "weren't you?\l"
	.string "It's easy to tell from your POKéMON.\p"
	.string "I'm a reporter. I'm working on a story\n"
	.string "on POKéMON CONTESTS.\p"
	.string "If I may, would you be willing to answer\n"
	.string "a few questions?$"
	
FallarborTown_ContestLobby_EventScript_1AE0F8:: @ 81AE0F8
	msgbox FallarborTown_ContestLobby_Text_1A704E, 4
	setvar VAR_0x8004, 11
	copyvar VAR_0x8005, VAR_0x8009
	setvar VAR_0x8006, 0
	call FallarborTown_ContestLobby_EventScript_1A00F3
	lock
	faceplayer
	compare VAR_RESULT, 1
	goto_if_eq FallarborTown_ContestLobby_EventScript_1AE137
	compare VAR_RESULT, 0
	goto_if_eq FallarborTown_ContestLobby_EventScript_1AE12D
	end
	
FallarborTown_ContestLobby_EventScript_1AE12D:: @ 81AE12D
	msgbox FallarborTown_ContestLobby_Text_1A7256, 4
	release
	end
	
FallarborTown_ContestLobby_EventScript_1AE1EE:: @ 81AE1EE
	clearflag FLAG_HIDE_CONTEST_REPORTER_FALLARBOR
	return

FallarborTown_ContestLobby_EventScript_1AE1F2:: @ 81AE1F2
	clearflag FLAG_HIDE_CONTEST_REPORTER_VERDANTURF
	return

FallarborTown_ContestLobby_EventScript_1AE1F6:: @ 81AE1F6
	clearflag FLAG_HIDE_CONTEST_REPORTER_SLATEPORT
	return

FallarborTown_ContestLobby_EventScript_1AE1FA:: @ 81AE1FA
	clearflag FLAG_HIDE_CONTEST_REPORTER_LILYCOVE
	return

FallarborTown_ContestLobby_EventScript_1AE1FE:: @ 81AE1FE
	return
	
FallarborTown_ContestLobby_EventScript_1A4EDD:: @ 81A4EDD
	clearflag FLAG_TEMP_1
	return

FallarborTown_ContestLobby_EventScript_1A4F4E:: @ 81A4F4E
	msgbox FallarborTown_ContestLobby_Text_1A685A, 4
	switch VAR_CONTEST_PRIZE_PICKUP
	case 4, FallarborTown_ContestLobby_EventScript_1A4F67
	end
	
FallarborTown_ContestLobby_EventScript_1A4F8F:: @ 81A4F8F
	message FallarborTown_ContestLobby_Text_1A5E46
	waitmessage
	multichoice 0, 0, 2, 0
	switch VAR_RESULT
	case 0, FallarborTown_ContestLobby_EventScript_1A5097
	case 1, FallarborTown_ContestLobby_EventScript_1A4FCC
	case 2, FallarborTown_ContestLobby_EventScript_1A503E
	case 127, FallarborTown_ContestLobby_EventScript_1A503E
	end

FallarborTown_ContestLobby_Text_1A5DFC:: @ 81A5DFC
	.string "Hello, there!\p"
	.string "We're accepting registrations for\n"
	.string "{STR_VAR_1} Rank POKéMON CONTESTS.$"
	
FallarborTown_ContestLobby_EventScript_1A4EE1:: @ 81A4EE1
	compare VAR_CONTEST_RANK, 0
	goto_if_eq FallarborTown_ContestLobby_EventScript_1A4EF6
	msgbox FallarborTown_ContestLobby_Text_1A6340, 4
	releaseall
	end
	
FallarborTown_ContestLobby_EventScript_15FBF3:: @ 815FBF3
	setvar VAR_OBJ_GFX_ID_3, EVENT_OBJ_GFX_BRENDAN_NORMAL
	return
	
FallarborTown_ContestLobby_EventScript_15FBF9:: @ 815FBF9
	setvar VAR_OBJ_GFX_ID_3, EVENT_OBJ_GFX_MAY_NORMAL
	return



//new new new shit
FallarborTown_ContestLobby_Text_1A72A8:: @ 81A72A8
	.string "I'll be looking forward to your next\n"
	.string "POKéMON CONTEST.$"

FallarborTown_ContestLobby_Text_1A704E:: @ 81A704E
	.string "Oh, you will?\n"
	.string "Thank you.\p"
	.string "Briefly, how would you describe the\n"
	.string "CONTEST you just entered?$"

FallarborTown_ContestLobby_EventScript_1A00F3:: @ 81A00F3
	fadescreen 1
	special ShowEasyChatScreen
	fadescreen 0
	return
	
FallarborTown_ContestLobby_EventScript_1AE137:: @ 81AE137
	setvar VAR_0x8004, 24
	special SetContestCategoryStringVarForInterview
	msgbox FallarborTown_ContestLobby_Text_1A70A5, 4
	setvar VAR_0x8004, 11
	copyvar VAR_0x8005, VAR_0x8009
	setvar VAR_0x8006, 1
	call FallarborTown_ContestLobby_EventScript_1A00F3
	lock
	faceplayer
	compare VAR_RESULT, 0
	goto_if_eq FallarborTown_ContestLobby_EventScript_1AE12D
	msgbox FallarborTown_ContestLobby_Text_1A7153, 4
	setflag FLAG_TEMP_2
	setvar VAR_0x8005, 6
	goto FallarborTown_ContestLobby_EventScript_1ADE46
	end
	
FallarborTown_ContestLobby_Text_1A7256:: @ 81A7256
	.string "Oh, too bad…\p"
	.string "Well, if you come across a good story,\n"
	.string "please do share it with me.$"
	
FallarborTown_ContestLobby_Text_1A685A:: @ 81A685A
	.string "Congratulations! Your POKéMON is the\n"
	.string "CONTEST winner!\p"
	.string "We have your prize right here.\n"
	.string "Please, right this way!$"
	
FallarborTown_ContestLobby_EventScript_1A4F67:: @ 81A4F67
	giveitem_std ITEM_LUXURY_BALL
	compare VAR_RESULT, 0
	goto_if_eq FallarborTown_ContestLobby_EventScript_1A4F86
	setvar VAR_CONTEST_PRIZE_PICKUP, 0
	closemessage
	release
	end
	
FallarborTown_ContestLobby_Text_1A5E46:: @ 81A5E46
	.string "Would you like to enter your POKéMON\n"
	.string "in our CONTESTS?$"
	
FallarborTown_ContestLobby_EventScript_1A5097:: @ 81A5097
	message FallarborTown_ContestLobby_Text_1A6623
	waitmessage
	multichoice 0, 0, 4, 0
	switch VAR_RESULT
	case 5, FallarborTown_ContestLobby_EventScript_1A503E
	case 127, FallarborTown_ContestLobby_EventScript_1A503E
	copyvar VAR_CONTEST_CATEGORY, VAR_RESULT
	goto FallarborTown_ContestLobby_EventScript_1A5048
	end
	
FallarborTown_ContestLobby_EventScript_1A4FCC:: @ 81A4FCC
	message FallarborTown_ContestLobby_Text_1A5E7C
	waitmessage
	multichoice 0, 0, 3, 0
	switch VAR_RESULT
	case 0, FallarborTown_ContestLobby_EventScript_1A5014
	case 1, FallarborTown_ContestLobby_EventScript_1A5022
	case 2, FallarborTown_ContestLobby_EventScript_1A5030
	case 3, FallarborTown_ContestLobby_EventScript_1A4F8F
	case 127, FallarborTown_ContestLobby_EventScript_1A4F8F
	end
	
FallarborTown_ContestLobby_EventScript_1A503E:: @ 81A503E
	msgbox FallarborTown_ContestLobby_Text_188559, 4
	release
	end
	
FallarborTown_ContestLobby_EventScript_1A4EF6:: @ 81A4EF6
	msgbox FallarborTown_ContestLobby_Text_1A64F4, MSGBOX_YESNO
	compare VAR_RESULT, YES
	goto_if_eq FallarborTown_ContestLobby_EventScript_1A4F13
	msgbox FallarborTown_ContestLobby_Text_1A65EA, 4
	releaseall
	end
	
FallarborTown_ContestLobby_Text_1A6340:: @ 81A6340
	.string "Anyone with a CONTEST PASS may enter.\p"
	.string "You may obtain a CONTEST PASS at the\n"
	.string "NORMAL RANK CONTEST HALL in\l"
	.string "VERDANTURF TOWN free of charge.\p"
	.string "Please obtain a CONTEST PASS and\n"
	.string "come again.$"
	
	
	
//new new new new shit
FallarborTown_ContestLobby_Text_1A70A5:: @ 81A70A5
	.string "Ah, I see.\n"
	.string "That's a very edifying comment.\p"
	.string "You get a good feel for what the\n"
	.string "CONTEST was like.\p"
	.string "I've got one last question.\p"
	.string "When you hear the word “{STR_VAR_2},”\n"
	.string "what image do you get?$"
	
FallarborTown_ContestLobby_Text_1A7153:: @ 81A7153
	.string "I see!\p"
	.string "So that's how you imagine the concept\n"
	.string "of “{STR_VAR_2}” to be.\p"
	.string "Thank you!\n"
	.string "You've given me some good ideas.\p"
	.string "I think I can write a good story on\n"
	.string "POKéMON CONTESTS now.\p"
	.string "Maybe, just maybe, this story will even\n"
	.string "make it to television.\l"
	.string "I hope you'll look forward to it!$"
	
FallarborTown_ContestLobby_EventScript_1ADE46:: @ 81ADE46
	special InterviewAfter
	incrementgamestat GAME_STAT_GOT_INTERVIEWED
	release
	end
	
FallarborTown_ContestLobby_EventScript_1A4F86:: @ 81A4F86
	msgbox FallarborTown_ContestLobby_Text_1A68C6, 2
	end
	
FallarborTown_ContestLobby_EventScript_1A5048:: @ 81A5048
	msgbox FallarborTown_ContestLobby_Text_1A6319, 4
	choosecontestmon
	compare VAR_0x8004, 255
	goto_if_eq FallarborTown_ContestLobby_EventScript_1A5097
	special sub_80F7F30
	compare VAR_RESULT, 0
	goto_if_eq FallarborTown_ContestLobby_EventScript_1A50C8
	compare VAR_RESULT, 1
	goto_if_eq FallarborTown_ContestLobby_EventScript_1A50D7
	compare VAR_RESULT, 2
	goto_if_eq FallarborTown_ContestLobby_EventScript_1A50FB
	compare VAR_RESULT, 3
	goto_if_eq FallarborTown_ContestLobby_EventScript_1A511F
	compare VAR_RESULT, 4
	goto_if_eq FallarborTown_ContestLobby_EventScript_1A512E
	end
	
FallarborTown_ContestLobby_Text_1A6623:: @ 81A6623
	.string "Which CONTEST would you like to enter?$"
	
FallarborTown_ContestLobby_Text_1A5E7C:: @ 81A5E7C
	.string "Which topic would you like?$"
	
FallarborTown_ContestLobby_EventScript_1A5014:: @ 81A5014
	msgbox FallarborTown_ContestLobby_Text_1A5E98, 4
	goto FallarborTown_ContestLobby_EventScript_1A4FCC
	end
	
FallarborTown_ContestLobby_EventScript_1A5022:: @ 81A5022
	msgbox FallarborTown_ContestLobby_Text_1A609B, 4
	goto FallarborTown_ContestLobby_EventScript_1A4FCC
	end
	
FallarborTown_ContestLobby_EventScript_1A5030:: @ 81A5030
	msgbox FallarborTown_ContestLobby_Text_1A613F, 4
	goto FallarborTown_ContestLobby_EventScript_1A4FCC
	end

FallarborTown_ContestLobby_Text_188559:: @ 8188559
	.string "We hope you will participate another\n"
	.string "time.$"
	
FallarborTown_ContestLobby_Text_1A64F4:: @ 81A64F4
	.string "Anyone with a CONTEST PASS may enter.\p"
	.string "If you don't have one, I can issue one\n"
	.string "for you right now.\p"
	.string "Would you like me to issue you a\n"
	.string "CONTEST PASS?$"

FallarborTown_ContestLobby_EventScript_1A4F13:: @ 81A4F13
	goto_if_set FLAG_RECEIVED_CONTEST_PASS, FallarborTown_ContestLobby_EventScript_1A4F44
	msgbox FallarborTown_ContestLobby_Text_1A6583, 4
	giveitem_std ITEM_CONTEST_PASS
	setflag FLAG_RECEIVED_CONTEST_PASS
	setflag FLAG_TEMP_1
	msgbox FallarborTown_ContestLobby_Text_1A5E98, 4
	goto FallarborTown_ContestLobby_EventScript_1A4F8F
	end
	
FallarborTown_ContestLobby_Text_1A65EA:: @ 81A65EA
	.string "Please visit whenever you would like\n"
	.string "to enter a CONTEST.$"
	
	
	
//new new new new new shit
FallarborTown_ContestLobby_Text_1A68C6:: @ 81A68C6
	.string "Please come back for your prize\n"
	.string "later on.$"
	
FallarborTown_ContestLobby_Text_1A6319:: @ 81A6319
	.string "Which POKéMON would you like to enter?$"
	
FallarborTown_ContestLobby_EventScript_1A50C8:: @ 81A50C8
	msgbox FallarborTown_ContestLobby_Text_1A664A, 4
	goto FallarborTown_ContestLobby_EventScript_1A5048
	release
	end

FallarborTown_ContestLobby_EventScript_1A50D7:: @ 81A50D7
	msgbox FallarborTown_ContestLobby_Text_1A67A3, MSGBOX_YESNO
	switch VAR_RESULT
	case NO, FallarborTown_ContestLobby_EventScript_1A5048
	case YES, FallarborTown_ContestLobby_EventScript_1A513D
	end

FallarborTown_ContestLobby_EventScript_1A50FB:: @ 81A50FB
	msgbox FallarborTown_ContestLobby_Text_1A6724, MSGBOX_YESNO
	switch VAR_RESULT
	case NO, FallarborTown_ContestLobby_EventScript_1A5048
	case YES, FallarborTown_ContestLobby_EventScript_1A513D
	end

FallarborTown_ContestLobby_EventScript_1A511F:: @ 81A511F
	msgbox FallarborTown_ContestLobby_Text_1A669F, 4
	goto FallarborTown_ContestLobby_EventScript_1A5048
	release
	end

FallarborTown_ContestLobby_EventScript_1A512E:: @ 81A512E
	msgbox FallarborTown_ContestLobby_Text_1A66DC, 4
	goto FallarborTown_ContestLobby_EventScript_1A5048
	release
	
FallarborTown_ContestLobby_Text_1A5E98:: @ 81A5E98
	.string "A POKéMON CONTEST involves four\n"
	.string "TRAINERS entering one POKéMON each\l"
	.string "in competitive judging.\p"
	.string "A CONTEST has two stages of judging,\n"
	.string "primary and secondary.\p"
	.string "Primary judging is a popularity poll\n"
	.string "involving the audience.\p"
	.string "Secondary judging features appeals\n"
	.string "by the POKéMON using their moves.\p"
	.string "Plan appeals carefully to earn the\n"
	.string "most attention of the JUDGE and\l"
	.string "excite the audience.\l"
	.string "Do your best to stand out.\p"
	.string "The primary and secondary scores are\n"
	.string "added at the end.\p"
	.string "The POKéMON garnering the highest\n"
	.string "score is declared the winner.$"




// new * 6 shit
FallarborTown_ContestLobby_Text_1A664A:: @ 81A664A
LilycoveCity_ContestLobby_Text_1A664A:: @ 81A664A
	.string "I'm terribly sorry, but your POKéMON\n"
	.string "is not qualified to compete at this\l"
	.string "Rank yet…$"
	
FallarborTown_ContestLobby_Text_1A67A3:: @ 81A67A3
LilycoveCity_ContestLobby_Text_1A67A3:: @ 81A67A3
	.string "Is that your CONTEST POKéMON?$"

FallarborTown_ContestLobby_EventScript_1A513D:: @ 81A513D
	msgbox FallarborTown_ContestLobby_Text_1A67C1, 4
	closemessage
	releaseall
	setvar VAR_LINK_CONTEST_ROOM_STATE, 1
	return
	
FallarborTown_ContestLobby_Text_1A6724:: @ 81A6724
	.string "Oh, but that RIBBON…\p"
	.string "Your POKéMON has won this CONTEST\n"
	.string "before, hasn't it?\p"
	.string "Would you like to enter it in this\n"
	.string "CONTEST anyway?$"
	
FallarborTown_ContestLobby_Text_1A669F:: @ 81A669F
LilycoveCity_ContestLobby_Text_1A669F:: @ 81A669F
	.string "I'm sorry, but an EGG cannot take part\n"
	.string "in a POKéMON CONTEST.$"
	
FallarborTown_ContestLobby_Text_1A66DC:: @ 81A66DC
LilycoveCity_ContestLobby_Text_1A66DC:: @ 81A66DC
	.string "Your POKéMON appears to be in no\n"
	.string "condition to take part in a CONTEST…$"
	
	
	
// new * 7 shit
FallarborTown_ContestLobby_Text_1A67C1:: @ 81A67C1
	.string "Okay, your POKéMON will be entered\n"
	.string "in this CONTEST.\p"
	.string "Your POKéMON is Entry No. 4.\n"
	.string "The CONTEST will begin shortly.$"

FallarborTown_ContestLobby_Text_1A609B:: @ 81A609B
	.string "There are five kinds of CONTESTS.\p"
	.string "COOL, BEAUTY, CUTE, SMART, and\n"
	.string "TOUGH are the five categories.\p"
	.string "Choose the CONTEST that is right for\n"
	.string "the POKéMON you plan to enter.$"
	
FallarborTown_ContestLobby_Text_1A613F:: @ 81A613F
	.string "There are four ranks of POKéMON\n"
	.string "CONTESTS.\p"
	.string "NORMAL, SUPER, HYPER and MASTER\n"
	.string "are the four ranks.\p"
	.string "In the NORMAL Rank, any POKéMON may\n"
	.string "enter.\p"
	.string "Any POKéMON that won a NORMAL Rank\n"
	.string "CONTEST may move up the SUPER Rank in\l"
	.string "the same category.\p"
	.string "In the same way, a SUPER Rank winner\n"
	.string "can move up to the HYPER Rank, and a\l"
	.string "HYPER Rank winner can advance to the\l"
	.string "MASTER Rank in the same category.\p"
	.string "A POKéMON that won in the MASTER Rank\n"
	.string "may compete in the MASTER Rank as\l"
	.string "often as its TRAINER wants.$"
	
FallarborTown_ContestLobby_EventScript_1A4F44:: @ 81A4F44
	msgbox FallarborTown_ContestLobby_Text_1A6590, 4
	releaseall
	end
	
FallarborTown_ContestLobby_Text_1A6590:: @ 81A6590
	.string "Oh?\p"
	.string "We've already issued you a CONTEST\n"
	.string "PASS, {PLAYER}.\p"
	.string "Please come back with your CONTEST\n"
	.string "PASS.$"
	
FallarborTown_ContestLobby_Text_1A6583:: @ 81A6583
	.string "Here you go!$"
	
	
fag:: @ 81554F9
	giveitem_std ITEM_POKEBLOCK_CASE
	setflag FLAG_HIDE_CONTEST_REPORTER_FALLARBOR
	setflag FLAG_HIDE_CONTEST_REPORTER_VERDANTURF
	setflag FLAG_HIDE_CONTEST_REPORTER_SLATEPORT
	setflag FLAG_HIDE_CONTEST_REPORTER_LILYCOVE
	releaseall
	end
	
taintedisafag:: @ 81554F9
	giveitem_std ITEM_CONTEST_PASS
	setflag FLAG_RECEIVED_CONTEST_PASS   
	releaseall
	end