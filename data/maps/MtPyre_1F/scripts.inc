MtPyre_1F_MapScripts::
	map_script MAP_SCRIPT_ON_LOAD, MtPyre_1F_OnLoad
	.byte 0

MtPyre_1F_OnLoad:
	call_if_set FLAG_MT_PYRE_SHORTCUT_OPEN, MtPyre_1F_EventScript_OpenShortcut
	end

MtPyre_1F_EventScript_ShortcutButton::
	goto_if_set FLAG_MT_PYRE_SHORTCUT_OPEN, MtPyre_1F_EventScript_ButtonAlreadyPressed
	lockall
	msgbox MtPyre_1F_Text_ButtonPressed, MSGBOX_DEFAULT
	setflag FLAG_MT_PYRE_SHORTCUT_OPEN
	call MtPyre_1F_EventScript_OpenShortcut
	special DrawWholeMapView
	releaseall
	end

MtPyre_1F_EventScript_ButtonAlreadyPressed::
	lockall
	msgbox MtPyre_1F_Text_ButtonAlreadyPressed, MSGBOX_DEFAULT
	releaseall
	end

MtPyre_1F_Text_ButtonPressed:
	.string "Click!\l"
	.string "You pressed the button...\p"
	.string "A shortcut has opened.$"

MtPyre_1F_Text_ButtonAlreadyPressed:
	.string "The button has already been pressed!$"

MtPyre_1F_EventScript_OpenShortcut::
	setmetatile 13, 11, METATILE_Facility_MtPyreDarkFloor, FALSE
	setmetatile 13, 12, METATILE_Facility_MtPyreDarkFloor, FALSE
	setmetatile 14, 11, METATILE_Facility_MtPyreDarkFloor, FALSE
	setmetatile 14, 12, METATILE_Facility_MtPyreDarkFloor, FALSE
	return

MtPyre_1F_EventScript_CleanseTagWoman::
	lock
	faceplayer
	goto_if_set FLAG_RECEIVED_CLEANSE_TAG, MtPyre_1F_EventScript_ReceivedCleanseTag
	msgbox MtPyre_1F_Text_TakeThisForYourOwnGood, MSGBOX_DEFAULT
	giveitem ITEM_CLEANSE_TAG
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
	setflag FLAG_RECEIVED_CLEANSE_TAG
	release
	end

MtPyre_1F_EventScript_ReceivedCleanseTag::
	msgbox MtPyre_1F_Text_ExplainCleanseTag, MSGBOX_DEFAULT
	release
	end

MtPyre_1F_EventScript_PokefanF::
	msgbox MtPyre_1F_Text_ComeToPayRespects, MSGBOX_NPC
	end

MtPyre_1F_EventScript_Man::
	msgbox MtPyre_1F_Text_RestingPlaceOfZigzagoon, MSGBOX_NPC
	end

MtPyre_1F_Text_TakeThisForYourOwnGood:
	.string "All sorts of beings wander the slopes\n"
	.string "of MT. PYRE…\p"
	.string "There is no telling what may happen.\n"
	.string "Take this. It's for your own good.$"

MtPyre_1F_Text_ExplainCleanseTag:
	.string "Have a POKéMON hold that\n"
	.string "CLEANSE TAG.\p"
	.string "It will help ward off wild POKéMON.$"

MtPyre_1F_Text_ComeToPayRespects:
	.string "Did you come to pay your respect\n"
	.string "to the spirits of departed POKéMON?\p"
	.string "You must care for your POKéMON a lot.$"

MtPyre_1F_Text_RestingPlaceOfZigzagoon:
	.string "This is the final resting place of my\n"
	.string "ZIGZAGOON. I cherished it…$"

