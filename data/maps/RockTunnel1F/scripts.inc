RockTunnel1F_MapScripts::
	.byte 0

RockTunnel_NPC_Talk1::
    msgbox RockTunnelNPC_1, MSGBOX_NPC
	applymovement 3, Common_Movement_WalkInPlaceDown
	waitmovement 0
	release
	end

RockTunnel_NPC_Talk2::
    msgbox RockTunnelNPC_2, MSGBOX_NPC
	release
	end

RockTunnel_NPC_Talk3::
    msgbox RockTunnelNPC_3, MSGBOX_NPC
	release
	end

RockTunnel_Machop_Talk1::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_MACHOP, 0
	msgbox RockTunnelMachop1, MSGBOX_DEFAULT
	waitmoncry
	msgbox RockTunnelMachop2, MSGBOX_DEFAULT
	release
	end

RockTunnelMachop1:
    .string "Machop: Guoh! Gogogoh!$"

RockTunnelMachop2:
    .string "The Machop is moving the rocks.$"

RockTunnelNPC_1:
    .string "Hey, pal!\n"
	.string "You want to go through?\p"
	.string "Well you're in tough luck!\n"
	.string "A Rock Slide recently hit in here.\p"
	.string "Me and the boys are trying to make\n"
	.string "a way through!$"

RockTunnelNPC_2:
    .string "Bah! Stupid Rock Slide!\n"
	.string "Luckily our Pokémon can help.$"

RockTunnelNPC_3:
    .string "I wonder what caused this mess?$"
