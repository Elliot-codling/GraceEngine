// Runtime code that controls what scripts are executed and when
#include "../include/main.h"
#include <sstream>
#include <csignal>

//Access to the debug handler
class runtime : public debugHandler
{
public:
    runtime() = default;
    ~runtime() = default;

    void printErrorInfo(const std::string &content) { debugHandler::printErrorInfo(content); }
};

void signalHandler(int sigNum) {
    runtime execute;
    //Output error if there is one
    std::ostringstream oss;

    switch (sigNum) {
        case SIGSEGV:
            oss << "Segmentation fault." << std::endl;
            break;
        case SIGFPE:
            oss << "Floating point exception." << std::endl;
            break;
        case SIGABRT:
            oss << "Abnormal termination." << std::endl;
            break;
        case SIGILL:
            oss << "Illegal instruction." << std::endl;
            break;
        case SIGTERM:
            oss << "Termination signal." << std::endl;
            break;
        case SIGINT:
            oss << "Interrupt signal." << std::endl;
            break;
        default:
            oss << "Unknown signal." << std::endl;
    }

    execute.printErrorInfo(oss.str());
    std::exit(sigNum);
}

//Start program
int main(){
    //Create signal handlers
    std::signal(SIGSEGV, signalHandler);
    std::signal(SIGFPE, signalHandler);
    std::signal(SIGABRT, signalHandler);
    std::signal(SIGILL, signalHandler);
    std::signal(SIGTERM, signalHandler);
    std::signal(SIGINT, signalHandler);

    //Set up variables for fixed update
    //runs once per 16.666ms (updates at 60fps)
    float fixedTime = 1.f / 60.f;
    float timeSinceLastUpdate = 0.f;
    float deltaTime = 0.f;
    sf::Clock clock;
    sf::Time timeElapsed;


    //When the project starts
    graceEngine* window = runtimeFunctions::start();
    //Game loop
    while (window->isRunning()) {
        timeElapsed = clock.restart();
        timeSinceLastUpdate += timeElapsed.asSeconds();

        switch (timeSinceLastUpdate >= fixedTime) {
            case true:
                deltaTime = timeSinceLastUpdate / fixedTime;
                runtimeFunctions::fixedUpdate(deltaTime);
                timeSinceLastUpdate = 0;
                break;
            case false:
                runtimeFunctions::update(*window);
                break;
        }
    }

    //Destroy objects
    runtimeFunctions::end();
    return 0;
}