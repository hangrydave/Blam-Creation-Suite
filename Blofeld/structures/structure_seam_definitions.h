#pragma once

namespace blofeld
{

constexpr unsigned long STRUCTURE_SEAMS_TAG = 'stse';

extern s_tag_group structure_seams_group;

extern s_tag_block_definition structure_seams_block_block;
extern s_tag_struct structure_seam_mapping_block_block_struct;
extern s_tag_block_definition structure_seam_mapping_block_block;
extern s_tag_struct structure_seam_edge_mapping_block_block_struct;
extern s_tag_block_definition structure_seam_edge_mapping_block_block;
extern s_tag_struct structure_seam_cluster_mapping_block_block_struct;
extern s_tag_block_definition structure_seam_cluster_mapping_block_block;
extern s_tag_struct structure_seam_block_block_struct;
extern s_tag_block_definition structure_seam_block_block;
extern s_tag_struct structure_seam_original_vertex_block_block_struct;
extern s_tag_block_definition structure_seam_original_vertex_block_block;
extern s_tag_struct structure_seam_original_vertex_plane_normals_block_block_struct;
extern s_tag_block_definition structure_seam_original_vertex_plane_normals_block_block;
extern s_tag_struct structure_seam_final_planes_block_block_struct;
extern s_tag_block_definition structure_seam_final_planes_block_block;
extern s_tag_struct structure_seam_final_points_block_block_struct;
extern s_tag_block_definition structure_seam_final_points_block_block;
extern s_tag_struct structure_seam_final_triangles_block_block_struct;
extern s_tag_block_definition structure_seam_final_triangles_block_block;
extern s_tag_struct structure_seam_final_edges_block_block_struct;
extern s_tag_block_definition structure_seam_final_edges_block_block;

extern s_tag_struct structure_seams_struct_definition_struct_definition; // tag group
extern s_tag_struct structure_seam_identifier_struct_struct_definition;
extern s_tag_struct structure_seam_original_geometry_struct_struct_definition;
extern s_tag_struct structure_seam_final_geometry_struct_struct_definition;

} // namespace blofeld

