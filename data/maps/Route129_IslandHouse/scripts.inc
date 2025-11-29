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
	msgbox Route129_IslandHouse_Text_placeholder, MSGBOX_DEFAULT
	release
	end

Route129_IslandHouse_Text_placeholder:
	.string "I've been expecting you,\n"
	.string "{PLAYER}.$"
