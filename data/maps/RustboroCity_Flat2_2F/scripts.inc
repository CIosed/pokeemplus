RustboroCity_Flat2_2F_MapScripts:: @ 8215FD7
	.byte 0

RustboroCity_Flat2_2F_EventScript_OldMan:: @ 8215FD8
	msgbox RustboroCity_Flat2_2F_Text_DevonWasTinyInOldDays, MSGBOX_NPC
	end

RustboroCity_Flat2_2F_EventScript_NinjaBoy:: @ 8215FE1
	lock
	faceplayer
	goto_if_set FLAG_RECEIVED_PREMIER_BALL_RUSTBORO, RustboroCity_Flat2_2F_EventScript_GavePremierBall
	msgbox RustboroCity_Flat2_2F_Text_MyDaddyMadeThisYouCanHaveIt, MSGBOX_DEFAULT
	giveitem ITEM_PREMIER_BALL
	compare VAR_RESULT, FALSE
	goto_if_eq Common_EventScript_ShowBagIsFull
	setflag FLAG_RECEIVED_PREMIER_BALL_RUSTBORO
	release
	end

RustboroCity_Flat2_2F_EventScript_GavePremierBall:: @ 8216010
	msgbox RustboroCity_Flat2_2F_Text_GoingToWorkAtDevonToo, MSGBOX_DEFAULT
	release
	end

RustboroCity_Flat2_2F_Text_DevonWasTinyInOldDays: @ 821601A
	.string "Way back in the old days, DEVON\n"
	.string "was just a teeny, tiny company.$"

RustboroCity_Flat2_2F_Text_MyDaddyMadeThisYouCanHaveIt: @ 821605A
	.string "My daddy's working at the\n"
	.string "CORPORATION.\p"
	.string "My daddy made this! But I can't use\n"
	.string "it, so you can have it.$"

RustboroCity_Flat2_2F_Text_GoingToWorkAtDevonToo: @ 82160BD
	.string "My daddy's working at the\n"
	.string "CORPORATION.\p"
	.string "When I grow up, I'm going to\n"
	.string "work for DEVON, too.$"

