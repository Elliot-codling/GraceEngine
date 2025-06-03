#pragma once
#include <GraceEngine/window.h>
//Define the runtime functions
namespace runtimeFunctions {
    graceEngine* start();
    int update(graceEngine &window);
    int fixedUpdate(float &deltaTime);
    int end();
}
