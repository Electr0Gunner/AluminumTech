#include <ALTech.hpp>

#include <stdio.h>

class SampleApp : public ALTech::Application
{
public:
    SampleApp(const ALTech::ApplicationInitData& init_data) : ALTech::Application(init_data)
    {
        printf("ALTech");
    }

    ~SampleApp()
    {

    }

};

ALTech::Application* ALTech::CreateApplication(ALTech::CommandLineArguments arguments)
{
    ALTech::ApplicationInitData data;
    data.name = "ALTech Sample";
    data.cmd_arguments = arguments;
    return new SampleApp(data);
}