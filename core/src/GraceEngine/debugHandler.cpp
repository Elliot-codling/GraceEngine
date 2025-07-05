#include <GraceEngine/debugHandler.h>
#include <sstream>
#include <chrono>
#include <iomanip>

// Get the date and time to put at the start of a debug message
std::string DebugHandler::getTimeAndDate()
{
    // Get current time with high resolution
    auto now = std::chrono::system_clock::now();

    // Convert to time_t for calendar time (seconds)
    auto in_time_t = std::chrono::system_clock::to_time_t(now);

    // Extract milliseconds
    auto milliseconds = std::chrono::duration_cast<std::chrono::milliseconds>(
        now.time_since_epoch()) % 1000;

    // Format date and time
    std::tm buf = *std::localtime(&in_time_t);
    std::ostringstream output;
    output << "[" << std::put_time(&buf, "%d/%m/%Y") << "] ";
    output << "[" << std::put_time(&buf, "%H:%M:%S")
        << "." << std::setfill('0') << std::setw(3) << milliseconds.count() << "] [";

    return output.str();
}
