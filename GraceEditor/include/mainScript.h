#pragma once
#include <GraceEngine/window.h>
//Define the runtime functions
namespace runtimeFunctions
{
    int start(GraceEngine &window);
    int update(GraceEngine &window);
    int fixedUpdate(GraceEngine &window, const float &deltaTime);
    int end();
}
