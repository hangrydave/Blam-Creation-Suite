#pragma once

namespace blofeld
{

constexpr unsigned long MULTIPLAYER_OBJECT_TYPE_LIST_TAG = 'motl';

extern s_tag_group multiplayer_object_type_list_group;

extern s_tag_block_definition multiplayer_object_type_list_block_block;
extern s_tag_struct multiplayer_object_type_block_block_struct;
extern s_tag_block_definition multiplayer_object_type_block_block;
extern s_tag_block_definition multiplayer_weapon_collection_block_block;
extern s_tag_block_definition multiplayer_vehicle_collection_block_block;
extern s_tag_block_definition multiplayer_grenade_collection_block_block;
extern s_tag_block_definition multiplayer_equipment_collection_block_block;
extern s_tag_struct multiplayer_weapon_remap_table_block_block_struct;
extern s_tag_block_definition multiplayer_weapon_remap_table_block_block;
extern s_tag_struct multiplayer_weapon_remap_table_entry_block_block_struct;
extern s_tag_block_definition multiplayer_weapon_remap_table_entry_block_block;
extern s_tag_struct multiplayer_vehicle_remap_table_block_block_struct;
extern s_tag_block_definition multiplayer_vehicle_remap_table_block_block;
extern s_tag_struct multiplayer_vehicle_remap_table_entry_block_block_struct;
extern s_tag_block_definition multiplayer_vehicle_remap_table_entry_block_block;
extern s_tag_struct multiplayer_equipment_remap_table_block_block_struct;
extern s_tag_block_definition multiplayer_equipment_remap_table_block_block;
extern s_tag_struct multiplayer_equipment_remap_table_entry_block_block_struct;
extern s_tag_block_definition multiplayer_equipment_remap_table_entry_block_block;

extern s_tag_struct multiplayer_object_type_list_struct_definition_struct_definition; // tag group
extern s_tag_struct multiplayer_object_collection_struct_struct_definition;

} // namespace blofeld

