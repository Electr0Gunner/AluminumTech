#pragma once

#include "Application.hpp"

#ifdef ALTECH_PLATFORM_WINDOWS

extern ALTech::Application* ALTech::CreateApplication(CommandLineArguments arguments);

int main(int argc, char** argv)
{
    auto app = ALTech::CreateApplication({argc, argv});

    delete app;
    return 0;
}

#endif