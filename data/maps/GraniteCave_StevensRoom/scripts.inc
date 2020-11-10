.set LOCALID_STEVEN, 1

GraniteCave_StevensRoom_MapScripts:: @ 822DC7A
	map_script MAP_SCRIPT_ON_FRAME_TABLE, GraniteCave_StevensRoom_MapScript2
	.byte 0

GraniteCave_StevensRoom_MapScript2:
	map_script_2 VAR_STEVEN_GRANITE_CAVE, 0, GraniteCave_StevensRoom_MapScript1
	.2byte 0


GraniteCave_StevensRoom_MapScript1::
	lock
	faceplayer
	delay 15
	special SpawnCameraObject
	applymovement OBJ_EVENT_ID_CAMERA, move_camera1
	waitmovement 0
	delay 20
	msgbox text_1, MSGBOX_DEFAULT
	closemessage
	delay 20
	applymovement OBJ_EVENT_ID_PLAYER, move_player1
	waitmovement 0
	delay 20
	playse SE_PIN
	applymovement LOCALID_STEVEN, Common_Movement_QuestionMark
	msgbox text_2, MSGBOX_DEFAULT
	applymovement LOCALID_STEVEN, step_dfast
	delay 20
	msgbox GraniteCave_StevensRoom_Text_ImStevenLetterForMe, MSGBOX_DEFAULT
	applymovement OBJ_EVENT_ID_PLAYER, move_player2
	waitmovement 0
	setvar VAR_0x8004, ITEM_LETTER
	call Common_EventScript_PlayerHandedOverTheItem
	setflag FLAG_DELIVERED_STEVEN_LETTER
	msgbox GraniteCave_StevensRoom_Text_ThankYouTakeThis, MSGBOX_DEFAULT
	giveitem ITEM_TM47
	compare VAR_RESULT, 0
	call_if_eq GraniteCave_StevensRoom_EventScript_BagFull
	msgbox GraniteCave_StevensRoom_Text_CouldBecomeChampionLetsRegister, MSGBOX_DEFAULT
	closemessage
	delay 30
	playfanfare MUS_REGISTER_MATCH_CALL
	msgbox GraniteCave_StevensRoom_Text_RegisteredSteven, MSGBOX_DEFAULT
	waitfanfare
	closemessage
	delay 30
	setflag FLAG_REGISTERED_STEVEN_POKENAV
	msgbox GraniteCave_StevensRoom_Text_IveGotToHurryAlong, MSGBOX_DEFAULT
	closemessage
	applymovement OBJ_EVENT_ID_CAMERA, move_camera2
	applymovement LOCALID_STEVEN, GraniteCave_StevensRoom_Movement_StevenExitSouth
	waitmovement 0
	special RemoveCameraObject
	playse SE_EXIT
	removeobject LOCALID_STEVEN
	setvar VAR_STEVEN_GRANITE_CAVE, 1
	end

GraniteCave_StevensRoom_MuralText::
	msgbox Tablet_Text, MSGBOX_SIGN
	end

GraniteCave_StevensRoom_EventScript_BagFull::
	msgbox GraniteCave_StevensRoom_Text_OhBagIsFull, MSGBOX_DEFAULT
	return

step_dfast:
    walk_in_place_fast_down
	step_end
	
move_camera1:
 	walk_slow_up
	walk_slow_up
	walk_slow_up
	walk_slow_up
	walk_slow_up
	walk_slow_up
	step_end
	
move_camera2:
 	walk_slow_down
	step_end
	
move_player1:
	walk_up
	walk_up
	walk_up
	walk_up
	step_end
	
move_player2:
	walk_up
	step_end
	
GraniteCave_StevensRoom_Movement_StevenExitSouth:
	walk_right
	walk_down
	walk_down
	walk_left
	walk_down
	walk_down
	walk_down
	walk_down
	delay_8
	step_end

text_1:
    .string "{COLOR BLUE}???: Hmm…\p"
	.string "So these are the super-ancient\n"
	.string "Pokémon…$"
	
text_2:
    .string "{COLOR BLUE}Hm?$"
	
GraniteCave_StevensRoom_Text_ImStevenLetterForMe:
    .string "{COLOR BLUE}Your are…?\p"
	.string "… … … … … …\n"
	.string "… … … … … …\p"
	.string "Ah, I see.\p"
	.string "It's a pleasure, {PLAYER}.\p"
	.string "My name is STEVEN.\p"
	.string "I'm interested in rare stones,\n"
	.string "so I travel here and there.\p"
	.string "Today my journey brought me\n"
	.string "here, what about you?\p"
	.string "… … … … … …\n"
	.string "… … … … … …\p"
	.string "Oh?\n"
	.string "A LETTER for me?$"

GraniteCave_StevensRoom_Text_ThankYouTakeThis:
	.string "{COLOR BLUE}STEVEN: Why, thank you.\p"
	.string "You went through all this trouble to\n"
	.string "deliver that. I need to thank you.\p"
	.string "Let me see…\n"
	.string "I'll give you this TM.\p"
	.string "It contains my favorite move,\n"
	.string "STEEL WING.$"

GraniteCave_StevensRoom_Text_CouldBecomeChampionLetsRegister:
	.string "{COLOR BLUE}STEVEN: Your POKÉMON appear quite\n"
	.string "capable.\p"
	.string "Looking at you all together…\p"
	.string "I think you have in you what it takes\n"
	.string "to reach very far with your goals.\p"
	.string "Provided you keep training, that is.\p"
	.string "I know, since we've gotten to know\n"
	.string "each other, let's register one\l"
	.string "another in our POKÉNAVS.\p"
	.string "… … … … … …$"

GraniteCave_StevensRoom_Text_RegisteredSteven:
	.string "Registered STEVEN\n"
	.string "in the POKÉNAV.$"

GraniteCave_StevensRoom_Text_IveGotToHurryAlong:
	.string "{COLOR BLUE}Good luck to you.\n"
	.string "I must be going now.$"

GraniteCave_StevensRoom_Text_OhBagIsFull:
	.string "{COLOR BLUE}Oh, your BAG is full…\n"
	.string "That's too bad, then.$"

Tablet_Text:
    .string "A strange mural on the wall\n"
	.string "overhangs your view.$"
