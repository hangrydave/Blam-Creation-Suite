#include "blamboozlelib-private-pch.h"

c_h5_tag_field_tag_reference_64::c_h5_tag_field_tag_reference_64(const char* halo5_forge_data, const s_h5_tag_field_definition* field_definition) :
	c_h5_tag_field(halo5_forge_data, field_definition)
{
	tag_reference_definition = reinterpret_cast<const s_h5_tag_reference_definition*>(h5_aa_to_pointer(halo5_forge_data, field_definition->definition_address));

}