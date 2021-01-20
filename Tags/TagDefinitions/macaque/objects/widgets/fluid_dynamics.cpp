#include <tagdefinitions-private-pch.h>
#include <macaque_field_type_override.h>

namespace blofeld
{

namespace macaque
{

	TAG_GROUP(
		fluid_dynamics_group,
		FLUID_DYNAMICS_TAG,
		nullptr,
		INVALID_TAG,
		fluid_dynamics_block );

	TAG_BLOCK_FROM_STRUCT(
		fluid_dynamics_block,
		"fluid_dynamics_block",
		1,
		fluid_dynamics_struct_definition);

	#define FLUID_DYNAMICS_SQUIRTER_BLOCK_ID { 0x7414343E, 0x3222489C, 0xB4903432, 0x7654EB15 }
	TAG_BLOCK(
		fluid_dynamics_squirter_block,
		"fluid_dynamics_squirter_block",
		MAXIMUM_SQUIRTERS_PER_FLUID_DYNAMICS,
		"fluid_dynamics_squirter",
		FLUID_DYNAMICS_SQUIRTER_BLOCK_ID)
	{
		{ _field_point_2d, "grid location" },
		{ _field_skip, "JKISKKJS", 48 },
		{ _field_real, "squirt scale" },
		{ _field_terminator }
	};

	#define FLUID_DYNAMICS_INFLOW_BLOCK_ID { 0x74143430, 0x32224891, 0xB4903432, 0x7654EB13 }
	TAG_BLOCK(
		fluid_dynamics_inflow_block,
		"fluid_dynamics_inflow_block",
		MAXIMUM_INFLOWS_PER_FLUID_DYNAMICS,
		"fluid_dynamics_inflow",
		FLUID_DYNAMICS_INFLOW_BLOCK_ID)
	{
		{ _field_point_2d, "grid location" },
		{ _field_real, "inflow rate#particles/sec" },
		{ _field_real, "inflow angle#degrees" },
		{ _field_real, "inflow velocity scale" },
		{ _field_terminator }
	};

	#define FLUID_DYNAMICS_OUTFLOW_BLOCK_ID { 0x7414343A, 0x3222489B, 0xB490343C, 0x7654EB1D }
	TAG_BLOCK(
		fluid_dynamics_outflow_block,
		"fluid_dynamics_outflow_block",
		MAXIMUM_OUTFLOWS_PER_FLUID_DYNAMICS,
		"fluid_dynamics_outflow",
		FLUID_DYNAMICS_OUTFLOW_BLOCK_ID)
	{
		{ _field_point_2d, "grid location" },
		{ _field_terminator }
	};

	#define FLUID_DYNAMICS_OBSTACLE_BLOCK_ID { 0x7414341E, 0x3222482C, 0xB4903442, 0x7654EB55 }
	TAG_BLOCK(
		fluid_dynamics_obstacle_block,
		"fluid_dynamics_obstacle_block",
		MAXIMUM_OBSTACLES_PER_FLUID_DYNAMICS,
		"fluid_dynamics_obstacle",
		FLUID_DYNAMICS_OBSTACLE_BLOCK_ID)
	{
		{ _field_point_2d, "2x2 grid location" },
		{ _field_terminator }
	};

	#define FLUID_DYNAMICS_STRUCT_DEFINITION_ID { 0x3414341E, 0x3222482C, 0x14903442, 0x0654EB55 }
	TAG_STRUCT(
		fluid_dynamics_struct_definition,
		"fluid_dynamics_struct_definition",
		"fluid_dynamics_definition",
		FLUID_DYNAMICS_STRUCT_DEFINITION_ID)
	{
		{ _field_long_flags, "flags", &fluid_dynamics_flags },
		{ _field_string_id, "marker attachment name" },
		{ _field_real, "diffusion rate#0.0000001->0.0000100" },
		{ _field_real, "viscosity#0.0000001->0.0060000" },
		{ _field_pad, "FIRWW", 40 },
		{ _field_short_integer, "number grid cells width#grid cells across" },
		{ _field_short_integer, "update rate#game updates per velocity field update" },
		{ _field_real, "particle gravity multiplier" },
		{ _field_real, "grid cell width#world units" },
		{ _field_real, "grid cell height#world units" },
		{ _field_short_integer, "maximum particles per cell#0 is no max. teleports ># away randomly" },
		{ _field_pad, "SKT", 2 },
		{ _field_pad, "DBNFAM", 76 },
		{ _field_short_integer, "number of tracers" },
		{ _field_pad, "FQ", 2 },
		{ _field_real_bounds, "tracer time multipier range" },
		{ _field_real, "tracer max velocity influence scale#1-32" },
		{ _field_pad, "NYUBJV", 36 },
		{ _field_short_integer, "number of particles#should = number of particles in the effect" },
		{ _field_short_integer, "particle collision rate#game updates per collision update" },
		{ _field_real, "particle collision radius#world units" },
		{ _field_real, "particle movement multiplier#0.001-5.0" },
		{ _field_real, "particle force to center of grid scale#0.001-5.0" },
		{ _field_real, "particle drag coeff#0-1" },
		{ _field_real, "maximum particle velocity(disabled)" },
		{ _field_pad, "DNF", 28 },
		{ _field_block, "particle effects", &particle_system_definition_block_new_block },
		{ _field_pad, "ZJSKRR", 20 },
		{ _field_block, "squirters", &fluid_dynamics_squirter_block },
		{ _field_block, "inflow", &fluid_dynamics_inflow_block },
		{ _field_block, "outflow", &fluid_dynamics_outflow_block },
		{ _field_block, "obstacles", &fluid_dynamics_obstacle_block },
		{ _field_explanation, "Cylinder map", "" },
		{ _field_struct, "cylindrical radius", &g_single_scalar_function_evaluation_struct },
		{ _field_terminator }
	};

	#define G_SINGLE_SCALAR_FUNCTION_EVALUATION_STRUCT_ID { 0xE5DD9E47, 0x3ECF4316, 0xA03E0324, 0x62F7B19C }
	TAG_STRUCT(
		g_single_scalar_function_evaluation_struct,
		"g_single_scalar_function_evaluation_struct",
		"s_single_scalar_function_definition",
		G_SINGLE_SCALAR_FUNCTION_EVALUATION_STRUCT_ID)
	{
		{ _field_real, "input" },
		FIELD_CUSTOM(nullptr, 0),
		{ _field_struct, "scalar", &mapping_function },
		{ _field_pad, "LOHRT", 16 },
		{ _field_terminator }
	};

	STRINGS(fluid_dynamics_flags)
	{
		"use tracers",
		"use density diffuse",
		"wrap particles width",
		"wrap particles height",
		"flat horizontal",
		"flat vertical(default)",
		"cylindrical horizontal",
		"cylindrical vertical",
		"approximate volume",
		"random particle placement",
		"tracer jump around"
	};
	STRING_LIST(fluid_dynamics_flags, fluid_dynamics_flags_strings, _countof(fluid_dynamics_flags_strings));

} // namespace macaque

} // namespace blofeld
