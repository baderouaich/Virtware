#pragma once

#if defined(_MSC_VER)
	/// _CRT_SECURE_NO_WARNINGS Disable Clang warnings
	#ifndef _CRT_SECURE_NO_WARNINGS
		#define _CRT_SECURE_NO_WARNINGS
	#endif
	#ifndef NOMINMAX
		// On Windows, a header file defines two macros min and max which may result in 
		// conflicts with their counterparts in the standard library and therefore in errors during compilation.
		#define NOMINMAX
	#endif
	#ifndef WIN32_LEAN_AND_MEAN
		#define WIN32_LEAN_AND_MEAN
	#endif
#endif
#include <Windows.h>




/// Resolve which function signature macro will be used. Note that this only
/// is resolved when the (pre)compiler starts, so the syntax highlighting
/// could mark the wrong one in your editor!
#if defined(__GNUC__) || (defined(__MWERKS__) && (__MWERKS__ >= 0x3000)) || (defined(__ICC) && (__ICC >= 600)) || defined(__ghs__)
	#define VIRTWARE_CURRENT_FUNCTION __PRETTY_FUNCTION__
#elif defined(__DMC__) && (__DMC__ >= 0x810)
	#define VIRTWARE_CURRENT_FUNCTION __PRETTY_FUNCTION__
#elif defined(__FUNCSIG__)
	#define VIRTWARE_CURRENT_FUNCTION __FUNCSIG__
#elif (defined(__INTEL_COMPILER) && (__INTEL_COMPILER >= 600)) || (defined(__IBMCPP__) && (__IBMCPP__ >= 500))
	#define VIRTWARE_CURRENT_FUNCTION __FUNCTION__
#elif defined(__BORLANDC__) && (__BORLANDC__ >= 0x550)
	#define VIRTWARE_CURRENT_FUNCTION __FUNC__
#elif defined(__STDC_VERSION__) && (__STDC_VERSION__ >= 199901)
	#define VIRTWARE_CURRENT_FUNCTION __func__
#elif defined(__cplusplus) && (__cplusplus >= 201103)
	#define VIRTWARE_CURRENT_FUNCTION __func__
#elif defined(_MSC_VER)
	#define VIRTWARE_CURRENT_FUNCTION __FUNCTION__
#else
	#define VIRTWARE_CURRENT_FUNCTION "<unknown function>"
#endif
///




/// Prevent class copying or moving
#define VIRTWARE_NON_COPYABLE(Class)              \
    Class& operator=(const Class& obj) = delete;  \
    Class(const Class& obj) = delete;
#define VIRTWARE_NON_MOVEABLE(Class)              \
    Class& operator=(Class&& obj) = delete;       
///

/// Makes a class static, which will prevent creating instances from it and only use it as Class::Func()..
#define VIRTWARE_STATIC_CLASS(Class) \
		public: \
			VIRTWARE_NON_COPYABLE(Class) \
			VIRTWARE_NON_MOVEABLE(Class) \
			Class() = delete; \
			~Class() = delete; \
		private:
///


/// Implements bitwise operators for enum classes
#define VIRTWARE_ENUM_CLASS_BITWISE_OPERATORS(_enum, _type) \
	friend inline constexpr _enum operator~ (const _enum i) noexcept { return static_cast<_enum>(~static_cast<const _type>(i)); }  \
	friend inline constexpr _enum operator| (const _enum a, const _enum b) noexcept { return static_cast<_enum>(static_cast<const _type>(a) | static_cast<const _type>(b)); } \
	friend inline constexpr  bool operator& (const _enum a, const _enum b) noexcept { return static_cast<bool>(static_cast<const _type>(a) & static_cast<const _type>(b)); } \
	friend inline constexpr _enum operator^ (const _enum a, const _enum b) noexcept { return static_cast<_enum>(static_cast<const _type>(a) ^ static_cast<const _type>(b)); } \
	friend inline constexpr _enum operator|= (_enum & a, const _enum b) noexcept { return (_enum&)((_type&)(a) |= (const _type)(b)); } \
	friend inline constexpr _enum operator&= (_enum & a, const _enum b) noexcept { return (_enum&)((_type&)(a) &= (const _type)(b)); } \
	friend inline constexpr _enum operator^= (_enum & a, const _enum b) noexcept { return (_enum&)((_type&)(a) ^= (const _type)(b)); }
///
