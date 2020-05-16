#include <blofeld-private-pch.h>

namespace blofeld
{

TAG_GROUP_FROM_BLOCK(controller_mapping, CONTROLLER_MAPPING_TAG, controller_mapping_block_block )

TAG_BLOCK_FROM_STRUCT(controller_mapping_block, 1, controller_mapping_struct_definition_struct_definition );

TAG_STRUCT(controller_mapping_struct_definition)
{
	FIELD( _field_long_integer, "auto zoom out ticks#set to 0 for instant unzoom on trigger release (trigger style) or 15 for toggle (thumbstick style)" ),
	FIELD( _field_explanation, "Start/Back" ),
	FIELD( _field_enum, "jump" ),
	FIELD( _field_enum, "switch weapon" ),
	FIELD( _field_enum, "contextual action" ),
	FIELD( _field_enum, "melee attack" ),
	FIELD( _field_enum, "equipment" ),
	FIELD( _field_enum, "throw grenade" ),
	FIELD( _field_enum, "primary fire" ),
	FIELD( _field_enum, "crouch" ),
	FIELD( _field_enum, "zoom-zoom scope" ),
	FIELD( _field_enum, "switch grenade prev" ),
	FIELD( _field_enum, "switch grenade next" ),
	FIELD( _field_enum, "secondary fire" ),
	FIELD( _field_enum, "tertiary fire" ),
	FIELD( _field_enum, "vehicle trick primary" ),
	FIELD( _field_enum, "vehicle trick secondary" ),
	FIELD( _field_enum, "secondary contextual action" ),
	FIELD( _field_enum, "radio message" ),
	FIELD( _field_skip, "start", 2 ),
	FIELD( _field_skip, "back", 2 ),
	FIELD( _field_enum, "lean left" ),
	FIELD( _field_enum, "lean right" ),
	FIELD( _field_enum, "night vision" ),
	FIELD( _field_enum, "accept" ),
	FIELD( _field_enum, "cancel" ),
	FIELD( _field_enum, "machinima lower weapon" ),
	FIELD( _field_enum, "machinima camera enable" ),
	FIELD( _field_enum, "machinima camera control" ),
	FIELD( _field_enum, "machinima camera debug" ),
	FIELD( _field_enum, "lift editor" ),
	FIELD( _field_enum, "drop editor" ),
	FIELD( _field_enum, "push to talk" ),
	FIELD( _field_enum, "cinematic skip" ),
	FIELD( _field_enum, "fireteam" ),
	FIELD( _field_enum, "regroup" ),
	FIELD( _field_enum, "activate minimap" ),
	FIELD( _field_enum, "requisition menu" ),
	FIELD( _field_enum, "loadout menu" ),
	FIELD( _field_enum, "hero assist#aka sprint" ),
	FIELD( _field_enum, "ordnance" ),
	FIELD( _field_enum, "skip killcam" ),
	FIELD( _field_enum, "mantis fire primary" ),
	FIELD( _field_enum, "mantis fire secondary" ),
	FIELD( _field_enum, "mantis melee attack" ),
	FIELD( _field_enum, "mantis crouch" ),
	FIELD( _field_terminator )
};

} // namespace blofeld

