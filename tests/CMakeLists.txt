# Find Qt Test
find_package(QT NAMES Qt6 Qt5 COMPONENTS Core REQUIRED)
find_package(Qt${QT_VERSION_MAJOR} COMPONENTS Test)
# Add the test executable
add_executable(WindowTest tst_window.cpp)
# Link the test to the static library and Qt Test
target_link_libraries(WindowTest PUBLIC WindowLib::WindowLib Qt${QT_VERSION_MAJOR}::Test)
set_target_properties(WindowTest PROPERTIES
    AUTOMOC ON
    AUTOUIC ON
    AUTORCC ON
    CXX_STANDARD 11
    CXX_STANDARD_REQUIRED ON
)
