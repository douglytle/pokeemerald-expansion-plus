Route129_IslandHouse_MapScripts::
	map_script MAP_SCRIPT_ON_LOAD, Route129_IslandHouse_OnLoad
	.byte 0

Route129_IslandHouse_OnLoad:
	call_if_set FLAG_TWIN_ISLAND_GATE_OPEN, Route129_IslandHouse_EventScript_OpenGate
	end

Route129_IslandHouse_EventScript_GateButton::
	goto_if_set FLAG_TWIN_ISLAND_GATE_OPEN, Route129_IslandHouse_EventScript_ButtonAlreadyPressed
	lockall
	msgbox Route129_IslandHouse_Text_ButtonPressed, MSGBOX_DEFAULT
	setflag FLAG_TWIN_ISLAND_GATE_OPEN
	call Route129_IslandHouse_EventScript_OpenGate
	special DrawWholeMapView
	releaseall
	end

Route129_IslandHouse_EventScript_ButtonAlreadyPressed::
	lockall
	msgbox Route129_IslandHouse_Text_ButtonAlreadyPressed, MSGBOX_DEFAULT
	releaseall
	end

Route129_IslandHouse_Text_ButtonPressed:
	.string "Click!\l"
	.string "You pressed the button...\p"
	.string "The wall slid back, revealing a secret\n"
	.string "passage!$"

Route129_IslandHouse_Text_ButtonAlreadyPressed:
	.string "The button has already been pressed!$"

Route129_IslandHouse_EventScript_OpenGate::
	setmetatile 13, 3, METATILE_GenericBuilding_WALL_MID, TRUE
	setmetatile 13, 4, METATILE_GenericBuilding_WALL_BOTTOM, TRUE
	setmetatile 13, 5, 0x3FE, FALSE
	setmetatile 13, 6, METATILE_GenericBuilding_WALL_COVERED, FALSE
	setmetatile 14, 5, METATILE_GenericBuilding_LIGHT_GREEN_FLOOR, FALSE
	return

Route129_IslandHouse_EventScript_Maniac::
	lock
	faceplayer
	call_if_unset FLAG_MET_ISLAND_MANIAC, Route129_IslandHouse_EventScript_MeetManiac
	goto_if_unset FLAG_RECEIVED_ZERAORA, Route129_IslandHouse_EventScript_TakeZeraora
	msgbox Route129_IslandHouse_Text_LeaveNow, MSGBOX_DEFAULT
	release
	end

Route129_IslandHouse_Text_LeaveNow:
	.string "What are you still doing here?\n"
	.string "Please take good care of that POKéMON.$"

Route129_IslandHouse_EventScript_MeetManiac::
	msgbox Route129_IslandHouse_Text_MeetManiac, MSGBOX_DEFAULT
	setflag FLAG_MET_ISLAND_MANIAC
	return

Route129_IslandHouse_Text_MeetManiac:
	.string "Oh, you must be a strong TRAINER\n"
	.string "to have traveled here through the\l"
	.string "cave at WEST TWIN ISLAND.\p"
	.string "I found this weak POKéMON outside\n"
	.string "in the yard with my PIKACHU,\l"
	.string "so I brought it in to keep it safe.\p"
	.string "I don't know how it got here, but I\n"
	.string "fear it can't survive in this place.$"

Route129_IslandHouse_EventScript_TakeZeraora::
	msgbox Route129_IslandHouse_Text_TakeZeraora, MSGBOX_DEFAULT
	getpartysize
	compare VAR_RESULT, 6
	goto_if_eq Route129_IslandHouse_EventScript_PartyIsFull
	setflag FLAG_RECEIVED_ZERAORA
	givemon SPECIES_ZERAORA, 1, ITEM_SHUCA_BERRY
	playfanfare MUS_EVOLVED
	msgbox Route129_IslandHouse_Text_ReceivedZeraora MSGBOX_DEFAULT
	waitfanfare
	bufferspeciesname STR_VAR_1, SPECIES_ZERAORA
	msgbox gText_NicknameThisPokemon, MSGBOX_YESNO
	call Common_EventScript_GetGiftMonPartySlot
	call Common_EventScript_NameReceivedPartyMon
	release
	end

Route129_IslandHouse_Text_TakeZeraora:
	.string "Please, won't you take this POKéMON\n"
	.string "and raise it properly?$"

Route129_IslandHouse_EventScript_PartyIsFull:
	msgbox Route129_IslandHouse_Text_PartyIsFull, MSGBOX_DEFAULT
	release
	end

Route129_IslandHouse_Text_PartyIsFull:
	.string "Ah, your party is full.\n"
	.string "Please come back with more space.$"

Route129_IslandHouse_Text_ReceivedZeraora:
	.string "{PLAYER} received Zeraora!$"
