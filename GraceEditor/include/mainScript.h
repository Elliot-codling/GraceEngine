#pragma once
#include <GraceEngine/window.h>
// Define the runtime functions
namespace runtimeFunctions
{
    int start(GraceEngine &window);
    int update(GraceEngine &window, float deltaTime);
    int fixedUpdate(GraceEngine &window, float deltaTime);
    int end();
}

inline auto create = Create();