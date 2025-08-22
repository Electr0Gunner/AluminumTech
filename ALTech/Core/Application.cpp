#include "Application.hpp"

#include "Log.hpp"

namespace ALTech
{
    Application::Application(const ApplicationInitData& data)
    {
        ALTECH_LOG_INFO("Started ALTech : %s", data.name.c_str());
    }
    
    Application::~Application()
    {
        ALTECH_LOG_INFO("Shutting down ALTech");
    }
} // namespace ALTech
