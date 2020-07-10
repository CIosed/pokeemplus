VermilionCityHouse4_MapScripts::
	.byte 0

VermilionCity_PokemonFanClub_Pikachu::
	waitse
	playmoncry SPECIES_PIKACHU, 0
	msgbox FanClub_PikachuText, MSGBOX_NPC
	waitmoncry
	release
	end

VermilionCity_PokemonFanClub_Seel::
	waitse
	playmoncry SPECIES_SEEL, 0
	msgbox FanClub_SeelText, MSGBOX_NPC
	waitmoncry
	release
	end

VermilionCity_PokemonFanClub_NPC_1::
	checkflag FLAG_TEMP_1
	goto_if_eq NPC1_FlagSet
	msgbox NPC1_Talk1, MSGBOX_NPC
	applymovement 4, Common_Movement_WalkInPlaceDown
	waitmovement 0
	setflag FLAG_TEMP_2
	release
	end

NPC1_FlagSet::
	msgbox NPC1_Talk2, MSGBOX_NPC
	applymovement 4, Common_Movement_WalkInPlaceDown
	waitmovement 0
	clearflag FLAG_TEMP_1
	release
	end

VermilionCity_PokemonFanClub_NPC_2::
	checkflag FLAG_TEMP_2
	goto_if_eq NPC2_FlagSet
	msgbox NPC2_Talk1, MSGBOX_NPC
	closemessage
	applymovement 3, Common_Movement_WalkInPlaceDown
	waitmovement 0
	setflag FLAG_TEMP_1
	release
	end

NPC2_FlagSet::
	msgbox NPC2_Talk2, MSGBOX_NPC
	applymovement 3, Common_Movement_WalkInPlaceDown
	waitmovement 0
	clearflag FLAG_TEMP_2
	release
	end

VermilionCity_PokemonFanClub_NPC_3::
	msgbox NPC3_Talk1, MSGBOX_NPC
	release
	end

FanClub_PikachuText::
    .string "Pikachu: Chu! Pikachu!$"

FanClub_SeelText::
    .string "Seel: Kyuoo!$"

NPC1_Talk1::
    .string "I just adore my Seel!\n"
    .string "It's so lovable!\p"
    .string "It squeals, “Kyuuuh,” when I\n"
    .string "hug it!$"

NPC1_Talk2::
    .string "Oh, dear!\p"
    .string "My Seel is far more attractive.\n"
    .string "By double, I would say.$"

NPC2_Talk1::
    .string "Won't you admire my Pikachu's\n"
    .string "adorable tail?$"

NPC2_Talk2::
    .string "Humph!\p"
    .string "My Pikachu is twice as cute as\n"
    .string "that one!$"

NPC3_Talk1:
    .string "Our Chairman really does adore his\n"
    .string "Pokémon.\p"
    .string "But the person who is most liked by\n"
    .string "Pokémon is Daisy, I think.$"
