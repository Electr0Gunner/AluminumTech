#pragma once

#include "Core.hpp"

#include <string>

namespace ALTech
{
    struct CommandLineArguments
    {
        int count = 0;
        char** args = nullptr;

        char* operator [](int index) const
        {
            return args[index];
        }
    };

    //Initialisation data for the app (Title Name, Command Arguments)
    struct ApplicationInitData
    {
        std::string name = "ALTech Application";
        CommandLineArguments cmd_arguments;
    };
    

    class ALTECH_API Application
    {
    private:
        /* data */
    public:
        Application(const ApplicationInitData& init_data);
        ~Application();
    };

    // To be defined in the game source code
    Application* CreateApplication(CommandLineArguments arguments);
    
} // namespace ALTech
