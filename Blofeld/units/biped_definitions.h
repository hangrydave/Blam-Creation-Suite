#pragma once

namespace blofeld
{

constexpr unsigned long BIPED_TAG = 'bipd';

extern s_tag_group biped_group;

extern s_tag_block_definition biped_block_block;
extern s_tag_struct biped_camera_height_block_block_struct;
extern s_tag_block_definition biped_camera_height_block_block;
extern s_tag_struct biped_wall_proximity_block_block_struct;
extern s_tag_block_definition biped_wall_proximity_block_block;
extern s_tag_struct biped_movement_gate_block_block_struct;
extern s_tag_block_definition biped_movement_gate_block_block;
extern s_tag_struct contact_point_block_block_struct;
extern s_tag_block_definition contact_point_block_block;
extern s_tag_struct biped_grab_object_animation_set_block_block_struct;
extern s_tag_block_definition biped_grab_object_animation_set_block_block;
extern s_tag_struct BipedSoundRTPCBlock_block_struct;
extern s_tag_block_definition BipedSoundRTPCBlock_block;
extern s_tag_struct BipedSoundSweetenerBlock_block_struct;
extern s_tag_block_definition BipedSoundSweetenerBlock_block;
extern s_tag_struct BipedAimingJointFixupBlock_block_struct;
extern s_tag_block_definition BipedAimingJointFixupBlock_block;

extern s_tag_struct biped_group_struct_definition; // tag group
extern s_tag_struct biped_leaping_data_struct_struct_definition;
extern s_tag_struct biped_vaulting_data_struct_struct_definition;
extern s_tag_struct biped_grab_biped_data_struct_struct_definition;
extern s_tag_struct biped_grab_object_data_struct_struct_definition;
extern s_tag_struct biped_ground_fitting_data_struct_struct_definition;
extern s_tag_struct BipedMovementHipLeaningStruct_struct_definition;

} // namespace blofeld

