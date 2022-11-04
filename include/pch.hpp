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

#include <xtd/xtd.h>
