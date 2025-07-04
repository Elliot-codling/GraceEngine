#pragma once
#include <GraceEngine/window.h>
//Define the runtime functions
namespace runtimeFunctions
{
    int start(graceEngine &window);
    int update(graceEngine &window);
    int fixedUpdate(graceEngine &window, const float &deltaTime);
    int end();
}
