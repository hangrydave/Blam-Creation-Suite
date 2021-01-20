#include <tagdefinitions-private-pch.h>
#include <macaque_field_type_override.h>

namespace blofeld
{

namespace macaque
{

	TAG_GROUP(
		medal_challenge_aggregator_list_group,
		MEDAL_CHALLENGE_AGGREGATOR_LIST_TAG,
		nullptr,
		INVALID_TAG,
		medal_challenge_aggregator_list_block );

	TAG_GROUP(
		medal_commendation_aggregator_list_group,
		MEDAL_COMMENDATION_AGGREGATOR_LIST_TAG,
		nullptr,
		INVALID_TAG,
		medal_commendation_aggregator_list_block );

	TAG_BLOCK_FROM_STRUCT(
		medal_challenge_aggregator_list_block,
		"medal_challenge_aggregator_list_block",
		1,
		medal_challenge_aggregator_list_struct_definition);

	TAG_BLOCK_FROM_STRUCT(
		medal_commendation_aggregator_list_block,
		"medal_commendation_aggregator_list_block",
		1,
		medal_commendation_aggregator_list_struct_definition);

	#define MEDALCHALLENGEAGGREGATOR_ID { 0x7B61FBDD, 0x349748E5, 0xA23985CC, 0x7C3DA8CA }
	TAG_BLOCK(
		medalChallengeAggregator_block,
		"medalChallengeAggregator",
		MedalChallengeAggregator::k_medalChallengeAggregatorMaxCount,
		"MedalChallengeAggregator",
		MEDALCHALLENGEAGGREGATOR_ID)
	{
		{ _field_string_id, "challenge to increment^" },
		{ _field_struct, "medals", &medalAggregator },
		{ _field_terminator }
	};

	#define MEDALAGGREGATORENTRY_ID { 0x6EBDB42C, 0xCEA840C2, 0x9264DA6F, 0x99C58621 }
	TAG_BLOCK(
		medalAggregatorEntry_block,
		"medalAggregatorEntry",
		MedalAggregatorEntry::k_medalAggregatorEntryMaxCount,
		"MedalAggregatorEntry",
		MEDALAGGREGATORENTRY_ID)
	{
		{ _field_string_id, "medal name^" },
		{ _field_terminator }
	};

	#define MEDALCOMMENDATIONAGGREGATOR_ID { 0x96CA56CE, 0x70B54D2A, 0x81BF7588, 0xAB4B56E0 }
	TAG_BLOCK(
		medalCommendationAggregator_block,
		"medalCommendationAggregator",
		MedalCommendationAggregator::k_medalCommendationAggregatorMaxCount,
		"MedalCommendationAggregator",
		MEDALCOMMENDATIONAGGREGATOR_ID)
	{
		{ _field_string_id, "commendation to award^" },
		{ _field_struct, "medals", &medalAggregator },
		{ _field_terminator }
	};

	#define MEDAL_CHALLENGE_AGGREGATOR_LIST_STRUCT_DEFINITION_ID { 0xD03365AC, 0xF68547BA, 0x9555A47C, 0x88C2D660 }
	TAG_STRUCT(
		medal_challenge_aggregator_list_struct_definition,
		"medal_challenge_aggregator_list_struct_definition",
		"MedalChallengeAggregatorList",
		MEDAL_CHALLENGE_AGGREGATOR_LIST_STRUCT_DEFINITION_ID)
	{
		{ _field_block, "lists", &medalChallengeAggregator_block },
		{ _field_terminator }
	};

	#define MEDAL_COMMENDATION_AGGREGATOR_LIST_STRUCT_DEFINITION_ID { 0x358B415E, 0xA96F4B51, 0xA64F35A0, 0xB280D9B1 }
	TAG_STRUCT(
		medal_commendation_aggregator_list_struct_definition,
		"medal_commendation_aggregator_list_struct_definition",
		"MedalCommendationAggregatorList",
		MEDAL_COMMENDATION_AGGREGATOR_LIST_STRUCT_DEFINITION_ID)
	{
		{ _field_block, "lists", &medalCommendationAggregator_block },
		{ _field_terminator }
	};

	#define MEDALAGGREGATOR_ID { 0x76FDA036, 0x899340B2, 0xB8B3DAAE, 0x0F99E191 }
	TAG_STRUCT(
		medalAggregator,
		"medalAggregator",
		"MedalAggregator",
		MEDALAGGREGATOR_ID)
	{
		{ _field_string_id, "display name^" },
		FIELD_CUSTOM("allowed game modes", _custom_field_function_group_begin),
		{ _field_struct, "allowed game modes", &game_mode_flags_struct },
		FIELD_CUSTOM(nullptr, _custom_field_function_group_end),
		{ _field_block, "contributing medals", &medalAggregatorEntry_block },
		{ _field_terminator }
	};

} // namespace macaque

} // namespace blofeld
