#include <tagdefinitions-private-pch.h>
#include <macaque_field_type_override.h>

namespace blofeld
{

namespace macaque
{

	#define GLOBAL_TARGET_TRACKING_PARAMETERS_BLOCK_ID { 0x5C0DCDA7, 0x2D9244BA, 0x940BE4EB, 0x94D50B22 }
	TAG_BLOCK(
		global_target_tracking_parameters_block,
		"global_target_tracking_parameters_block",
		1,
		"s_target_tracking_parameters",
		GLOBAL_TARGET_TRACKING_PARAMETERS_BLOCK_ID)
	{
		{ _field_block, "tracking types#specify the kinds of targets this tracking system can lock on", &tracking_type_block },
		{ _field_real, "acquire time:s" },
		{ _field_real, "grace time:s" },
		{ _field_real, "decay time:s" },
		{ _field_tag_reference, "tracking sound", &global_sound_and_looping_sound_reference },
		{ _field_tag_reference, "locked sound", &global_sound_and_looping_sound_reference },
		{ _field_terminator }
	};

	#define TRACKING_TYPE_BLOCK_ID { 0x1E369AD6, 0x88C043A0, 0xAA0A675A, 0xE3762650 }
	TAG_BLOCK(
		tracking_type_block,
		"tracking_type_block",
		16,
		"string_id",
		TRACKING_TYPE_BLOCK_ID)
	{
		{ _field_string_id, "tracking type^" },
		{ _field_terminator }
	};

} // namespace macaque

} // namespace blofeld
