SlateportCity_ContestHall_MapScripts:: @ 815554B
	.byte 0

SlateportCity_ContestHall_EventScript_15554C:: @ 815554C
	msgbox SlateportCity_ContestHall_Text_17CB71, 2
	end

SlateportCity_ContestHall_EventScript_155555:: @ 8155555
	msgbox SlateportCity_ContestHall_Text_17CC80, 2
	end

SlateportCity_ContestHall_EventScript_15555E:: @ 815555E
	lock
	faceplayer
	goto_if_set FLAG_RECEIVED_TM41, SlateportCity_ContestHall_EventScript_155595
	msgbox SlateportCity_ContestHall_Text_17CCE2, 4
	giveitem_std ITEM_TM41_TORMENT
	compare VAR_RESULT, 0
	goto_if_eq SlateportCity_ContestHall_EventScript_1A029B
	setflag FLAG_RECEIVED_TM41
	msgbox SlateportCity_ContestHall_Text_17CE28, 4
	release
	end

SlateportCity_ContestHall_EventScript_155595:: @ 8155595
	msgbox SlateportCity_ContestHall_Text_17CE28, 4
	release
	end

SlateportCity_ContestHall_EventScript_15559F:: @ 815559F
	msgbox SlateportCity_ContestHall_Text_17CEF3, 2
	lockall
	applymovement 3, SlateportCity_ContestHall_Movement_1A083D
	waitmovement 0
	releaseall
	end

SlateportCity_ContestHall_EventScript_1555B4:: @ 81555B4
	msgbox SlateportCity_ContestHall_Text_17CFA7, 2
	lockall
	applymovement 4, SlateportCity_ContestHall_Movement_1A083D
	waitmovement 0
	releaseall
	end

SlateportCity_ContestHall_EventScript_1555C9:: @ 81555C9
	msgbox SlateportCity_ContestHall_Text_17D054, 2
	lockall
	applymovement 5, SlateportCity_ContestHall_Movement_1A083D
	waitmovement 0
	releaseall
	end

SlateportCity_ContestHall_EventScript_1555DE:: @ 81555DE
	msgbox SlateportCity_ContestHall_Text_17D07F, 2
	lockall
	applymovement 6, SlateportCity_ContestHall_Movement_1A083D
	waitmovement 0
	releaseall
	end

SlateportCity_ContestHall_EventScript_1555F3:: @ 81555F3
	msgbox SlateportCity_ContestHall_Text_17D0F9, 2
	lockall
	applymovement 7, SlateportCity_ContestHall_Movement_1A083D
	waitmovement 0
	releaseall
	end

SlateportCity_ContestHall_EventScript_155608:: @ 8155608
	msgbox SlateportCity_ContestHall_Text_17D222, 2
	lockall
	applymovement 8, SlateportCity_ContestHall_Movement_1A083D
	waitmovement 0
	releaseall
	end

SlateportCity_ContestHall_EventScript_15561D:: @ 815561D
	msgbox SlateportCity_ContestHall_Text_17D39A, 2
	lockall
	applymovement 9, SlateportCity_ContestHall_Movement_1A083D
	waitmovement 0
	releaseall
	end

SlateportCity_ContestHall_EventScript_155632:: @ 8155632
	msgbox SlateportCity_ContestHall_Text_17D3F0, 2
	lockall
	applymovement 10, SlateportCity_ContestHall_Movement_1A083D
	waitmovement 0
	releaseall
	end

SlateportCity_ContestHall_EventScript_155647:: @ 8155647
	msgbox SlateportCity_ContestHall_Text_17D300, 2
	lockall
	applymovement 12, SlateportCity_ContestHall_Movement_1A083D
	waitmovement 0
	releaseall
	end

SlateportCity_ContestHall_EventScript_15565C:: @ 815565C
	msgbox SlateportCity_ContestHall_Text_17D27F, 2
	lockall
	applymovement 11, SlateportCity_ContestHall_Movement_1A083D
	waitmovement 0
	releaseall
	end

SlateportCity_ContestHall_EventScript_155671:: @ 8155671
	msgbox SlateportCity_ContestHall_Text_17D447, 3
	end

SlateportCity_ContestHall_Text_17CB71:: @ 817CB71
	.string "Want a tasty little bit of advice\n"
	.string "for CONTESTS?\p"
	.string "Using a certain move after another\n"
	.string "certain kind of move sometimes gets\l"
	.string "you extra attention.\p"
	.string "If you know what you're doing, you\n"
	.string "can score big in appeal.\p"
	.string "Of course, your opponents might try\n"
	.string "disrupting your POKéMON's showing.$"

SlateportCity_ContestHall_Text_17CC80:: @ 817CC80
	.string "My papa, he's a CONTEST JUDGE.\p"
	.string "I wonder what I should be when I\n"
	.string "grow up, a JUDGE or a GYM LEADER?$"

SlateportCity_ContestHall_Text_17CCE2:: @ 817CCE2
	.string "Hey, man, I'm like majorly cheesed,\n"
	.string "you know. Like, you know, I just\l"
	.string "wanted to know why my POKéMON\l"
	.string "never won, you know, like, hey?\p"
	.string "So, like, I gave the JUDGE my two\n"
	.string "cents, you know, they're free.\p"
	.string "And he wouldn't hear me out, like, hey!\n"
	.string "So, like, total bummer, man!\p"
	.string "Hey, like, you! Zip it, you know?\n"
	.string "Just, you know, take this!$"

SlateportCity_ContestHall_Text_17CE28:: @ 817CE28
	.string "That's, like, TM41, you know?\n"
	.string "Hey, it's TORMENT, you hearing me?\p"
	.string "Like, it won't let the other guy\n"
	.string "use the same move twice in a row, see?\p"
	.string "Hey, now, you listen here, like,\n"
	.string "I'm not laying a torment on you!$"

SlateportCity_ContestHall_Text_17CEF3:: @ 817CEF3
	.string "MC: Oh, my, my!\n"
	.string "Now isn't that a dandy of a POKéMON?\p"
	.string "Please! Do step right up and take\n"
	.string "part in our splendid CONTESTS!\p"
	.string "You'll do well! I'm sure of it!\n"
	.string "My eyes have never failed me!$"

SlateportCity_ContestHall_Text_17CFA7:: @ 817CFA7
	.string "JUDGE: Well, hello there!\n"
	.string "I see that you're a TRAINER!\p"
	.string "Then, it just wouldn't do for you\n"
	.string "to miss a POKéMON CONTEST!\p"
	.string "Get a CONTEST PASS in VERDANTURF\n"
	.string "CITY and enter anytime!$"

SlateportCity_ContestHall_Text_17D054:: @ 817D054
	.string "It's appeal time!\n"
	.string "What should I lead with?$"

SlateportCity_ContestHall_Text_17D07F:: @ 817D07F
	.string "They didn't pay much attention to\n"
	.string "my POKéMON's appeal…\p"
	.string "Humph, that JUDGE, he doesn't know\n"
	.string "a good thing when he sees it.$"

SlateportCity_ContestHall_Text_17D0F9:: @ 817D0F9
	.string "Oh, hi! You must be a serious fan to get\n"
	.string "this close to the action.\p"
	.string "I'll reward your enthusiasm with this\n"
	.string "sage advice.\p"
	.string "If a move goes over really well,\n"
	.string "the audience will get excited.\p"
	.string "The POKéMON that makes its appeal\n"
	.string "right when everyone's excited…\p"
	.string "Well, you'd think something good has\n"
	.string "to happen!$"

SlateportCity_ContestHall_Text_17D222:: @ 817D222
	.string "I can't do this! I'm more freaked out\n"
	.string "than my POKéMON.\p"
	.string "I'm shivering and my heart is racing!$"

SlateportCity_ContestHall_Text_17D27F:: @ 817D27F
	.string "A battle and a CONTEST aren't the\n"
	.string "same, but they are alike, too.\p"
	.string "You need to work hard and believe\n"
	.string "in the POKéMON you've raised.$"

SlateportCity_ContestHall_Text_17D300:: @ 817D300
	.string "That POKéMON looks like it's on top\n"
	.string "of its game, huh?\p"
	.string "A POKéMON that does good in the\n"
	.string "secondary judging seems to be more\l"
	.string "relaxed when it's doing appeals.$"

SlateportCity_ContestHall_Text_17D39A:: @ 817D39A
	.string "Will you look at that sorry sight?\p"
	.string "Heh, my POKéMON's absolutely better\n"
	.string "than that lot!$"

SlateportCity_ContestHall_Text_17D3F0:: @ 817D3F0
	.string "Don't you get the urge to move with\n"
	.string "POKéMON if they're putting on an\l"
	.string "energetic appeal?$"

SlateportCity_ContestHall_Text_17D447:: @ 817D447
	.string "POKéMON CONTESTS\n"
	.string "HYPER RANK STAGE!$"
