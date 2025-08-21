
#Add the sample source files
file(GLOB_RECURSE ALTechSample_SRC
    "src/*.cpp"
    "src/*.c"
)

#Add the sample header files
file(GLOB_RECURSE ALTechSample_HEADER
    "src/*.hpp"
    "src/*.h"
)

#Create the sample executable and link it with ALTech
add_executable(ALTechSample ${ALTechSample_SRC} ${ALTechSample_HEADER})
target_link_libraries(ALTechSample PRIVATE AluminumTech)

#Add some debug arguments
set_target_properties(ALTechSample PROPERTIES 
    VS_DEBUGGER_COMMAND "ALTechSample.exe"
    VS_DEBUGGER_COMMAND_ARGUMENTS "TEST ARG1 ARG2")

#Copy the ALTech DLL to the build folder
if(ALTECH_SHARED_BUILD)

    add_custom_command(TARGET ALTechSample POST_BUILD
        COMMAND ${CMAKE_COMMAND} -E copy_if_different
            $<TARGET_FILE:AluminumTech>
            $<TARGET_FILE_DIR:ALTechSample>
        COMMENT "Copying engine DLL file to the build folder"
    )
endif()
