#include <GraceEngine/runtime.h>

int windowWidth = 1280, windowHeight = 720;

int main()
{
    runtime runtimeWindow("SFML App", windowWidth, windowHeight);

    runtimeWindow.update();
    runtimeWindow.end();

    return 0;
}