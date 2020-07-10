CeruleanCityBikeShop_MapScripts::
	.byte 0

CeruleanBikeShop_NPC_Talk1::
    msgbox CeruleanBikeShop_NPC_1, MSGBOX_NPC
	release
	end

CeruleanBikeShop_NPC_Talk2::
    msgbox CeruleanBikeShop_NPC_2, MSGBOX_NPC
	release
	end

CeruleanBikeShop_NPC_1::
    .string "A plain city bike is good enough\n"
    .string "for me.\p"
    .string "After all, you can't put a shopping\n"
    .string "basket on a mountain bike.$"

CeruleanBikeShop_NPC_2::
    .string "These bikes are cool, but they're\n"
    .string "way expensive!$"
