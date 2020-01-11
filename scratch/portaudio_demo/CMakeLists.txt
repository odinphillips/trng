cmake_minimum_required(VERSION 3.5)

# portaudio demonstration app
add_executable(demo main.c)
target_link_libraries(demo portaudio_static)
#target_include_directories(demo PUBLIC ${PROJECT_SOURCE_DIR}/3rdParty/portaudio/include)

