#pragma once

namespace blofeld
{

constexpr unsigned long SOUNDBANK_TAG = 'sbnk';

extern s_tag_struct soundbank_block_struct;
extern s_tag_block_definition soundbank_block;
extern s_tag_group soundbank_group;
constexpr unsigned long SOUND_GLOBAL_PROPAGATION_TAG = 'sgp!';

extern s_tag_struct sound_global_propagation_block_struct;
extern s_tag_block_definition sound_global_propagation_block;
extern s_tag_group sound_global_propagation_group;
constexpr unsigned long SOUND_TAG = 'snd!';

extern s_tag_struct sound_block_struct;
extern s_tag_block_definition sound_block;
extern s_tag_group sound_group;
constexpr unsigned long SOUND_OLD_TAG = 'sndo';

extern s_tag_struct sound_old_block_struct;
extern s_tag_block_definition sound_old_block;
extern s_tag_group sound_old_group;
constexpr unsigned long SOUND2_TAG = 'sndx';

extern s_tag_struct sound2_block_struct;
extern s_tag_block_definition sound2_block;
extern s_tag_group sound2_group;
constexpr unsigned long SOUND_MIX_TAG = 'snmx';

extern s_tag_struct sound_mix_block_struct;
extern s_tag_block_definition sound_mix_block;
extern s_tag_group sound_mix_group;
constexpr unsigned long SOUND_DIALOGUE_CONSTANTS_TAG = 'spk!';

extern s_tag_group sound_dialogue_constants_group;

extern s_tag_block_definition sound_dialogue_constants_block_block;
extern s_tag_struct sound_globals_block_block_struct;
extern s_tag_block_definition sound_globals_block_block;
extern s_tag_struct StreamingPackBlock_block_struct;
extern s_tag_block_definition StreamingPackBlock_block;
extern s_tag_struct campaign_unspatialized_sounds_block_block_struct;
extern s_tag_block_definition campaign_unspatialized_sounds_block_block;
extern s_tag_struct SoundBankBlock_block_struct;
extern s_tag_block_definition SoundBankBlock_block;
extern s_tag_block_definition soundLipSyncInfoBlock_block;
extern s_tag_block_definition deterministicSpeechEventBlock_block;
extern s_tag_struct facial_animation_language_block_block_struct;
extern s_tag_block_definition facial_animation_language_block_block;
extern s_tag_struct sound_promotion_rule_block_block_struct;
extern s_tag_block_definition sound_promotion_rule_block_block;
extern s_tag_struct sound_promotion_runtime_timer_block_block_struct;
extern s_tag_block_definition sound_promotion_runtime_timer_block_block;
extern s_tag_struct sound_pitch_range_block_block_struct;
extern s_tag_block_definition sound_pitch_range_block_block;
extern s_tag_struct sound_permutations_block_block_struct;
extern s_tag_block_definition sound_permutations_block_block;
extern s_tag_struct sound_permutation_languages_block_block_struct;
extern s_tag_block_definition sound_permutation_languages_block_block;
extern s_tag_struct sound_permutation_chunk_block_block_struct;
extern s_tag_block_definition sound_permutation_chunk_block_block;
extern s_tag_struct sound_platform_sound_playback_block_block_struct;
extern s_tag_block_definition sound_platform_sound_playback_block_block;
extern s_tag_struct sound_extra_info_block_block_struct;
extern s_tag_block_definition sound_extra_info_block_block;
extern s_tag_struct sound_definition_language_permutation_info_block_block_struct;
extern s_tag_block_definition sound_definition_language_permutation_info_block_block;
extern s_tag_struct sound_permutation_raw_info_block_block_struct;
extern s_tag_block_definition sound_permutation_raw_info_block_block;
extern s_tag_struct sound_permutation_marker_block_block_struct;
extern s_tag_block_definition sound_permutation_marker_block_block;
extern s_tag_struct sound_xma2_seek_table_block_block_struct;
extern s_tag_block_definition sound_xma2_seek_table_block_block;
extern s_tag_block_definition sound_pitch_range_distances_block_block;

extern s_tag_struct sound_dialogue_constants_struct_definition_struct_definition; // tag group
extern s_tag_struct soundLipSyncInfoBlock_struct_struct_definition;
extern s_tag_struct deterministicSpeechEventBlock_struct_struct_definition;
extern s_tag_struct sound_distance_parameters_struct_struct_definition;
extern s_tag_struct sound_propagation_definition_struct_struct_definition;
extern s_tag_struct sound_playback_parameters_struct_struct_definition;
extern s_tag_struct sound_scale_modifiers_struct_struct_definition;
extern s_tag_struct sound_promotion_parameters_struct_struct_definition;
extern s_tag_struct sound_transmission_definition_struct_struct_definition;
extern s_tag_struct sound_stereo_mix_struct_struct_definition;
extern s_tag_struct sound_surround_mix_struct_struct_definition;
extern s_tag_struct sound_global_mix_struct_struct_definition;
extern s_tag_struct sound_center_mix_struct_struct_definition;

} // namespace blofeld

