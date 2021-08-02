# Find Qt Core, Gui & Widgets
find_package(QT NAMES Qt6 Qt5 COMPONENTS Core REQUIRED)
find_package(Qt${QT_VERSION_MAJOR} COMPONENTS Widgets Gui Core)
# Create a static lib project to contain all the classes
add_library(WindowLib STATIC window.cpp window.h)
# Add an alias to the library to avoid typos
add_library(WindowLib::WindowLib ALIAS WindowLib)
# Better version of set(CMAKE_INCLUDE_CURRENT_DIR ON)
target_include_directories(WindowLib PUBLIC $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}>)
# Link the static lib to to Qt Core, Gui & Widgets
target_link_libraries(WindowLib PUBLIC Qt${QT_VERSION_MAJOR}::Core Qt${QT_VERSION_MAJOR}::Gui Qt${QT_VERSION_MAJOR}::Widgets)
# Better version of
# set(CMAKE_AUTOUIC ON)
# set(CMAKE_AUTOMOC ON)
# set(CMAKE_AUTORCC ON)
# set(CMAKE_CXX_STANDARD 11)
# set(CMAKE_CXX_STANDARD_REQUIRED ON)
set_target_properties(WindowLib PROPERTIES
    AUTOMOC ON
    AUTOUIC ON
    AUTORCC ON
    CXX_STANDARD 11
    CXX_STANDARD_REQUIRED ON
)
# add the real executable with only the main.cpp
add_executable(WindowExe main.cpp)
# link to the static library
target_link_libraries(WindowExe PUBLIC WindowLib::WindowLib)
set_target_properties(WindowExe PROPERTIES
    WIN32_EXECUTABLE TRUE
    MACOSX_BUNDLE TRUE
    CXX_STANDARD 11
    CXX_STANDARD_REQUIRED ON
)
