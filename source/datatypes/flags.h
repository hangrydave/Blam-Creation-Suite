#pragma once

#include <cseries/cseries.h>

/* ---------- classes */

template <
	typename t_enum,
	typename t_storage,
	const long k_number_of_bits = sizeof(t_storage) * 8>
class c_flags_no_init
{
	static_assert(__is_enum(t_enum));
	static_assert(k_number_of_bits <= sizeof(t_storage) * 8);

protected:
	t_storage m_stored;

public:
	void clear()
	{
		m_stored = 0;
	}

	bool test(t_enum bit) const
	{
		return (m_stored & FLAG(static_cast<t_storage>(bit))) != 0;
	}

	void set(t_enum bit, bool value)
	{
		t_storage flag = FLAG(static_cast<t_storage>(bit));

		if (value)
			m_stored |= flag;
		else
			m_stored &= ~flag;
	}

	bool valid() const
	{
		auto total_bits = sizeof(t_storage) * k_uint8_bits;

		for (auto current_bit = k_number_of_bits;
			current_bit < total_bits;
			current_bit++)
		{
			if (TEST_BIT(m_stored, current_bit))
				return false;
		}

		return true;
	}

	t_storage get_unsafe() const
	{
		return m_stored;
	}
};

template <
	typename t_enum,
	typename t_storage,
	const long k_number_of_bits = sizeof(t_storage) * 8>
class c_flags :
	public c_flags_no_init<t_enum, t_storage, k_number_of_bits>
{
	using t_base = c_flags_no_init<t_enum, t_storage, k_number_of_bits>;
	using t_this = c_flags<t_enum, t_storage, k_number_of_bits>;

protected:
	using t_base::m_stored;

public:
	c_flags()
	{
		m_stored = reinterpret_cast<t_storage>(0);
	}

    c_flags(const t_storage &value)
    {
        m_stored = value;
    }
};
