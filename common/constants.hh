#pragma once

#define VIEW_SOLUTIONS 0

#ifdef OGL_CORE
#define PROFILE GLFW_OPENGL_CORE_PROFILE
#else
#define PROFILE GLFW_OPENGL_COMPAT_PROFILE
#endif

#ifndef M_PI
#define M_PI 3.1415926535897932384626433832795
#endif
