#pragma once

template<BuildVersion buildVersion, typename T, size_t offset>
class BasicData : public DataReferenceBase
{
public:
	BasicData(const BasicData&) = delete;
	BasicData()
		: DataReferenceBase(buildVersion, sizeof(T), offset, nullptr)
	{

	}

	T* ptr() const
	{
		T* ptr = reinterpret_cast<T*>(m_pPtr);
		return ptr;
	}

	volatile T* volatile_ptr() const
	{
		return static_cast<volatile T*>(ptr());
	}

	T& PointerReference() const
	{
		return *ptr();
	}

	T* operator->()
	{
		return ptr();
	}

	T const* operator->() const
	{
		return ptr();
	}

	operator T& () const
	{
		return PointerReference();
	}

	operator bool() const
	{
		T& r = PointerReference();
		return (bool)r;
	}
};