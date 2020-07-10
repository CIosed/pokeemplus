VermilionCityMart_MapScripts::
	.byte 0

VermilionMart_NPC_Talk1::
    msgbox VermilionMart_NPC_1, MSGBOX_NPC
	release
	end

VermilionMart_NPC_Talk2::
    msgbox VermilionMart_NPC_2, MSGBOX_NPC
	release
	end

VermilionMart_NPC_1:
    .string "I think Pokémon can be good or\n"
	.string "bad.\p"
	.string "It depends on the Trainer.$"

VermilionMart_NPC_2:
    .string "There are wicked people who will\n"
	.string "use Pokémon for criminal acts.\p"
	.string "Team Rocket traffics in rare\n"
	.string "Pokémon, for example.\p"
	.string "They also abandon Pokémon that\n"
	.string "they consider unpopular or useless.\p"
	.string "That's the sort of horrid people\n"
	.string "they are, Team Rocket.\l"
	.string "I heard they were defeated though.$"
