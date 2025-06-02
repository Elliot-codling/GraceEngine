// Runtime code that controls what scripts are executed and when
#include "../../GraceEditor/include/main.h"
#include <sstream>
class runtime : public debugHandler
{
public:
    runtime() = default;
    ~runtime() = default;

    void printErrorInfo(const std::string &content) { debugHandler::printErrorInfo(content); }
};

int main(){
    try {
        //When the project starts
        graceEngine* window = runtimeFunctions::start();
        //Game loop
        while (window->isRunning()) {
            runtimeFunctions::logic(*window);
        }

        //Destroy objects
        runtimeFunctions::end();
    }

    catch (const std::exception &e) {
        runtime execute;

        std::ostringstream oss;
        oss << "Program terminated. Exception thrown: " << e.what();
        execute.printErrorInfo(oss.str());
    }
    return 0;
}