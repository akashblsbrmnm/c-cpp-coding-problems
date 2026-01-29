#include <iostream>

class Logger {
    public:
        void log(const std::string& message) {
            std::cout << "[LOG]: " << message << std::endl;
        }

        static Logger& getInstance() {
            static Logger instance;
            return instance;
        }

        Logger(const Logger&) = delete; // “You are not allowed to create a Logger from another Logger”
        Logger& operator=(const Logger&) = delete; // “You are not allowed to assign one Logger to another Logger”

    private:
         Logger() {
            std::cout << "Logger initialized." << std::endl;
        }

        ~Logger() {
            std::cout << "Logger destroyed." << std::endl;
        }
};

int main() {
    Logger& logger1 = Logger::getInstance();
    Logger& logger2 = Logger::getInstance();
    logger1.log("This is a singleton logger example.");
    logger2.log("Logger instance is the same across calls.");
    std::cout << (&logger1 == &logger2) << std::endl;
    return 0;
}
