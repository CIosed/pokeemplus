AbandonedShip_Rooms_1F_MapScripts:: @ 8237A92
	.byte 0

AbandonedShip_Rooms_1F_EventScript_Gentleman:: @ 8237A93
	msgbox AbandonedShip_Rooms_1F_Text_TakingALookAround, MSGBOX_NPC
	end

AbandonedShip_Rooms_1F_EventScript_Demetrius:: @ 8237A9C
	trainerbattle_single TRAINER_DEMETRIUS, AbandonedShip_Rooms_1F_Text_DemetriusIntro, AbandonedShip_Rooms_1F_Text_DemetriusDefeat
	msgbox AbandonedShip_Rooms_1F_Text_DemetriusPostBattle, MSGBOX_AUTOCLOSE
	end

AbandonedShip_Rooms_1F_EventScript_Thalia:: @ 8237AB3
	trainerbattle_single TRAINER_THALIA, AbandonedShip_Rooms_1F_Text_ThaliaIntro, AbandonedShip_Rooms_1F_Text_ThaliaDefeat
	msgbox AbandonedShip_Rooms_1F_Text_ThaliaPostBattle, MSGBOX_DEFAULT
	release
	end

AbandonedShip_Rooms_1F_Text_TakingALookAround: @ 8237B15
	.string "Ships of this sort are rare, so I'm\n"
	.string "taking a look around.\p"
	.string "Hmhm…\n"
	.string "There appear to be other cabins…$"

AbandonedShip_Rooms_1F_Text_ThaliaIntro: @ 8237B76
	.string "{COLOR RED}What on earth would compel you to\n"
	.string "come here? You must be curious!$"

AbandonedShip_Rooms_1F_Text_ThaliaDefeat: @ 8237BB8
	.string "Not just curious, but also strong…$"

AbandonedShip_Rooms_1F_Text_ThaliaPostBattle: @ 8237BDB
	.string "The man next door…\p"
	.string "He says he's just sightseeing,\n"
	.string "but I don't know about that.$"

AbandonedShip_Rooms_1F_Text_DemetriusIntro: @ 8237D0C
	.string "{COLOR BLUE}Waaah!\n"
	.string "I've been found! …Huh?$"

AbandonedShip_Rooms_1F_Text_DemetriusDefeat: @ 8237D2A
	.string "Oh, you're not my mom.$"

AbandonedShip_Rooms_1F_Text_DemetriusPostBattle: @ 8237D41
	.string "I'm in trouble with my mom, so I ran.\n"
	.string "Keep it a secret where I am!$"

