#pragma once
#include "Utility/debugbreak.h"



#ifdef REAL_ENABLE_ASSERTS
  #define REAL_ASSERT(x, ...) {if(!(x)) {REAL_ERROR("Assertion Failed: {0}", __VA_ARGS__); debug_break();} }
  #define REAL_CORE_ASSERT(x, ...) {if(!(x)) {REAL_CORE_ERROR("Assertion Failed: {0}", __VA_ARGS__); debug_break();} }
#else
  #define REAL_ASSERT(x, ...)
  #define REAL_CORE_ASSERT(x, ...)
#endif



#define BIT(x) (1 << x)
