#include "runtime/include/runtime.h"

static int windowWidth = 1280, windowHeight = 720;

int main()
{
    // Create Runtime, as well as the width and height
    Runtime runtimeWindow("SFML App", windowWidth, windowHeight);

    // Update runtime and end runtime once complete
    runtimeWindow.update();
    runtimeWindow.end();

    return 0;
}