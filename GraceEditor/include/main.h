#pragma once
#include "../../GraceEngine/include/window.h"
//Define the runtime functions
namespace runtimeFunctions {
    graceEngine* start();
    int logic(graceEngine &window);
    int end();
}
