#pragma once

struct nicename("Collision Model") group('coll') s_collision_model_definition
{
	struct nicename("Materials") s_material_block_definition;
	struct nicename("Regions") s_region_block_definition;
	struct nicename("Pathfinding Spheres") s_pathfinding_sphere_block_definition;
	struct nicename("Nodes") s_node_block_definition;

	int32_t nicename("Collision Model Checksum") collision_model_checksum; 
	Undefined32 __unknown; 
	Undefined32 __unknown2; 
	Undefined32 __unknown3; 
	int32_t nicename("Flags") flags; 
	s_tag_block_definition<s_material_block_definition> nicename("Materials") materials_block; 
	s_tag_block_definition<s_region_block_definition> nicename("Regions") regions_block; 
	Undefined32 __unknown4; 
	Undefined32 __unknown5; 
	Undefined32 __unknown6; 
	s_tag_block_definition<s_pathfinding_sphere_block_definition> nicename("Pathfinding Spheres") pathfinding_spheres_block; 
	s_tag_block_definition<s_node_block_definition> nicename("Nodes") nodes_block; 
	Undefined32 __unknown7; 

	struct nicename("material") s_material_block_definition
	{
		string_id nicename("Name") name; 
	};

	struct nicename("region") s_region_block_definition
	{
		struct nicename("Permutations") s_permutation_block_definition;

		string_id nicename("Name") name; 
		s_tag_block_definition<s_permutation_block_definition> nicename("Permutations") permutations_block; 

		struct nicename("permutation") s_permutation_block_definition
		{
			struct nicename("BSPs") s_bsp_block_definition;
			struct nicename("BSP Physics") s_bsp_physic_block_definition;
			struct nicename("BSP MOPP Codes") s_bsp_mopp_code_block_definition;

			string_id nicename("Name") name; 
			s_tag_block_definition<s_bsp_block_definition> nicename("BSPs") bsps_block; 
			s_tag_block_definition<s_bsp_physic_block_definition> nicename("BSP Physics") bsp_physics_block; 
			s_tag_block_definition<s_bsp_mopp_code_block_definition> nicename("BSP MOPP Codes") bsp_mopp_codes_block; 

			struct nicename("bsp") s_bsp_block_definition
			{
				struct nicename("BSP 3D Nodes") s_bsp_3d_node_block_definition;
				struct s_unknown_block_definition;
				struct nicename("Planes") s_plane_block_definition;
				struct nicename("Leaves") s_leaf_block_definition;
				struct nicename("BSP 2D References") s_bsp_2d_reference_block_definition;
				struct nicename("BSP 2D Nodes") s_bsp_2d_node_block_definition;
				struct nicename("Surfaces") s_surface_block_definition;
				struct nicename("Edges") s_edge_block_definition;
				struct nicename("Vertices") s_vertex_block_definition;

				int16_t nicename("Node Index") node_index; 
				int16_t __unknown; 
				s_tag_block_definition<s_bsp_3d_node_block_definition> nicename("BSP 3D Nodes") bsp_3d_nodes_block; 
				s_tag_block_definition<s_unknown_block_definition> __unknown2_block; 
				s_tag_block_definition<s_plane_block_definition> nicename("Planes") planes_block; 
				s_tag_block_definition<s_leaf_block_definition> nicename("Leaves") leaves_block; 
				s_tag_block_definition<s_bsp_2d_reference_block_definition> nicename("BSP 2D References") bsp_2d_references_block; 
				s_tag_block_definition<s_bsp_2d_node_block_definition> nicename("BSP 2D Nodes") bsp_2d_nodes_block; 
				s_tag_block_definition<s_surface_block_definition> nicename("Surfaces") surfaces_block; 
				s_tag_block_definition<s_edge_block_definition> nicename("Edges") edges_block; 
				s_tag_block_definition<s_vertex_block_definition> nicename("Vertices") vertices_block; 

				struct nicename("bsp_3d_node") s_bsp_3d_node_block_definition
				{
					uint8_t __unknown; 
					int16_t nicename("Second Child") second_child; 
					uint8_t __unknown2; 
					int16_t nicename("First Child") first_child; 
					int16_t nicename("Plane") plane; 
				};

				struct s_unknown_block_definition
				{
					Undefined32 __unknown; 
					Undefined32 __unknown2; 
					Undefined32 __unknown3; 
					Undefined32 __unknown4; 
					Undefined32 __unknown5; 
					Undefined32 __unknown6; 
					Undefined32 __unknown7; 
					Undefined32 __unknown8; 
					Undefined32 __unknown9; 
					Undefined32 __unknown10; 
					Undefined32 __unknown11; 
					Undefined32 __unknown12; 
					Undefined32 __unknown13; 
					Undefined32 __unknown14; 
					Undefined32 __unknown15; 
					Undefined32 __unknown16; 
					Undefined32 __unknown17; 
					Undefined32 __unknown18; 
					Undefined32 __unknown19; 
					Undefined32 __unknown20; 
					Undefined32 __unknown21; 
					Undefined32 __unknown22; 
					Undefined32 __unknown23; 
					Undefined32 __unknown24; 
					Undefined32 __unknown25; 
					Undefined32 __unknown26; 
					Undefined32 __unknown27; 
					Undefined32 __unknown28; 
					Undefined32 __unknown29; 
					Undefined32 __unknown30; 
					Undefined32 __unknown31; 
					Undefined32 __unknown32; 
				};

				struct nicename("plane") s_plane_block_definition
				{
					float nicename("Plane i") plane_i; 
					float nicename("Plane j") plane_j; 
					float nicename("Plane k") plane_k; 
					float nicename("Plane d") plane_d; 
				};

				struct nicename("leaf") s_leaf_block_definition
				{
					int16_t nicename("Flags") flags; 
					int16_t nicename("BSP 2D Reference Count") bsp_2d_reference_count; 
					int16_t __unknown; 
					int16_t nicename("First BSP 2D Reference") first_bsp_2d_reference; 
				};

				struct nicename("bsp_2d_reference") s_bsp_2d_reference_block_definition
				{
					int16_t nicename("Plane") plane; 
					int16_t nicename("BSP 2D Node") bsp_2d_node; 
				};

				struct nicename("bsp_2d_node") s_bsp_2d_node_block_definition
				{
					float nicename("Plane i") plane_i; 
					float nicename("Plane j") plane_j; 
					float nicename("Plane d") plane_d; 
					int16_t nicename("Left Child") left_child; 
					int16_t nicename("Right Child") right_child; 
				};

				struct nicename("surface") s_surface_block_definition
				{
					int16_t nicename("Plane") plane; 
					int16_t nicename("First Edge") first_edge; 
					int16_t nicename("Material") material; 
					int16_t __unknown; 
					int16_t nicename("Breakable Surface") breakable_surface; 
					int16_t __unknown2; 
				};

				struct nicename("edge") s_edge_block_definition
				{
					int16_t nicename("Start Vertex") start_vertex; 
					int16_t nicename("End Vertex") end_vertex; 
					int16_t nicename("Forward Edge") forward_edge; 
					int16_t nicename("Reverse Edge") reverse_edge; 
					int16_t nicename("Left Surface") left_surface; 
					int16_t nicename("Right Surface") right_surface; 
				};

				struct nicename("vertex") s_vertex_block_definition
				{
					Undefined32 __point_x; 
					Undefined32 __point_y; 
					Undefined32 __point_z; 
					int16_t nicename("First Edge") first_edge; 
					int16_t __unknown; 
				};
			};

			struct nicename("bsp_physic") s_bsp_physic_block_definition
			{
				int32_t __unknown; 
				Undefined32 __unknown2; 
				int16_t nicename("Size") size; 
				int16_t nicename("Count") count; 
				int32_t nicename("Offset") offset; 
				Undefined32 __unknown3; 
				Undefined32 __unknown4; 
				Undefined32 __unknown5; 
				Undefined32 __unknown6; 
				Undefined32 __unknown7; 
				Undefined32 __unknown8; 
				Undefined32 __unknown9; 
				Undefined32 __unknown10; 
				Undefined32 __unknown11; 
				Undefined32 __unknown12; 
				Undefined32 __unknown13; 
				Undefined32 __unknown14; 
				Undefined32 __unknown15; 
				Undefined32 __unknown16; 
				Undefined32 __unknown17; 
				Undefined32 __unknown18; 
				unsigned int nicename("Model") model; 
				Undefined32 __unknown19; 
				Undefined32 __unknown20; 
				Undefined32 __unknown21; 
				Undefined32 __unknown22; 
				Undefined32 __unknown23; 
				Undefined32 __unknown24; 
				Undefined32 __unknown25; 
				Undefined32 __unknown26; 
				Undefined32 __unknown27; 
				Undefined32 __unknown28; 
				Undefined32 __unknown29; 
				int32_t __unknown30; 
				Undefined32 __unknown31; 
				int16_t nicename("Size") size2; 
				int16_t nicename("Count") count2; 
				int32_t nicename("Offset") offset2; 
				Undefined32 __unknown32; 
				Undefined32 __unknown33; 
				Undefined32 __unknown34; 
				Undefined32 __unknown35; 
				Undefined32 __unknown36; 
				Undefined32 __unknown37; 
				Undefined32 __unknown38; 
				Undefined32 __unknown39; 
				Undefined32 __unknown40; 
				Undefined32 __unknown41; 
				int32_t nicename("MOPP Data Count") mopp_data_count; 
				Undefined32 __unknown42; 
				float nicename("MOPP Offset x") mopp_offset_x; 
				float nicename("MOPP Offset y") mopp_offset_y; 
				float nicename("MOPP Offset z") mopp_offset_z; 
				float nicename("MOPP Offset Scale") mopp_offset_scale; 
				Undefined32 __unknown43; 
				Undefined32 __unknown44; 
				Undefined32 __unknown45; 
				Undefined32 __unknown46; 
				Undefined32 __unknown47; 
				Undefined32 __unknown48; 
				Undefined32 __unknown49; 
				Undefined32 __unknown50; 
				Undefined32 __unknown51; 
				Undefined32 __unknown52; 
				Undefined32 __unknown53; 
				Undefined32 __unknown54; 
			};

			struct nicename("bsp_mopp_code") s_bsp_mopp_code_block_definition
			{
				struct nicename("Data") s_datum_block_definition;

				int32_t __unknown; 
				Undefined32 __unknown2; 
				int16_t nicename("Size") size; 
				int16_t nicename("Count") count; 
				int32_t nicename("Offset") offset; 
				Undefined32 __unknown3; 
				Undefined32 __unknown4; 
				Undefined32 __unknown5; 
				Undefined32 __unknown6; 
				float nicename("Offset x") offset_x; 
				float nicename("Offset y") offset_y; 
				float nicename("Offset z") offset_z; 
				float nicename("Offset Scale") offset_scale; 
				Undefined32 __unknown7; 
				Undefined32 __unknown8; 
				int32_t nicename("Data Size") data_size; 
				uint32_t nicename("Data Capacity") data_capacity; 
				Undefined32 __unknown9; 
				Undefined32 __unknown10; 
				Undefined32 __unknown11; 
				Undefined32 __unknown12; 
				s_tag_block_definition<s_datum_block_definition> nicename("Data") data_block; 
				Undefined32 __unknown13; 

				struct nicename("datum") s_datum_block_definition
				{
					uint8_t nicename("Data Byte") data_byte; 
				};
			};
		};
	};

	struct nicename("pathfinding_sphere") s_pathfinding_sphere_block_definition
	{
		int16_t nicename("Node") node; 
		uint16_t nicename("Flags") flags; 
		float nicename("Center x") center_x; 
		float nicename("Center y") center_y; 
		float nicename("Center z") center_z; 
		float nicename("Radius") radius; 
	};

	struct nicename("node") s_node_block_definition
	{
		string_id nicename("Name") name; 
		int16_t __unknown; 
		int16_t nicename("Parent Node") parent_node; 
		int16_t nicename("Next Sibling Node") next_sibling_node; 
		int16_t nicename("First Child Node") first_child_node; 
	};
};