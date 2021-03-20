MtPyre_6F_MapScripts:: @ 8231D3A
	.byte 0

MtPyre_6F_EventScript_Valerie:: @ 8231D3B
	trainerbattle_single TRAINER_VALERIE, MtPyre_6F_Text_ValerieIntro, MtPyre_6F_Text_ValerieDefeat
	msgbox MtPyre_6F_Text_ValeriePostBattle, MSGBOX_DEFAULT
	release
	end

MtPyre_6F_EventScript_Cedric:: @ 8231D9D
	trainerbattle_single TRAINER_CEDRIC, MtPyre_6F_Text_CedricIntro, MtPyre_6F_Text_CedricDefeat
	msgbox MtPyre_6F_Text_CedricPostBattle, MSGBOX_AUTOCLOSE
	end

MtPyre_6F_Text_ValerieIntro: @ 8231DB4
	.string "{COLOR RED}When I'm here…\n"
	.string "A curious power flows into me…$"

MtPyre_6F_Text_ValerieDefeat: @ 8231DE2
	.string "The power is ebbing away…$"

MtPyre_6F_Text_ValeriePostBattle: @ 8231DFC
	.string "Perhaps the power is from the spirits\n"
	.string "of POKéMON in fitful sleep here…$"

MtPyre_6F_Text_CedricIntro: @ 8231F11
	.string "{COLOR BLUE}Have you lost your bearings?\n"
	.string "Have no fear for I am here!$"

MtPyre_6F_Text_CedricDefeat: @ 8231F4A
	.string "Weren't you lost?$"

MtPyre_6F_Text_CedricPostBattle: @ 8231F5C
	.string "I had this feeling that a lost\n"
	.string "TRAINER would be panicked and\l"
	.string "easy to beat.\p"
	.string "It's dirty and I won't try it again…$"

