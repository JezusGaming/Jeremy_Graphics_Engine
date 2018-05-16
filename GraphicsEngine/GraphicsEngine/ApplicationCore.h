#pragma once
#include <iostream>
#include <chrono>

#include <glm\glm.hpp>
#include <glm\ext.hpp>

#include "../dependencies/glcore//gl_core_4_5.h"
#include "glfw3.h"

#include "Gizmos.h"

using ullong = unsigned long long;
using nanosecond = std::chrono::nanoseconds;
// Expected use: seconds = nanoseconds * NANO_TO_SECONDS
static const double NANO_TO_SECONDS = 0.000000001;
// Expected use: nanoseconds = seconds * NANO_IN_SECONDS
static const ullong NANO_IN_SECONDS = 1000000000ULL;

namespace my
{
	using clock = std::chrono::high_resolution_clock;
	using time = std::chrono::time_point<clock>;
}