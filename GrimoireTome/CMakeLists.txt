cmake_minimum_required(VERSION 3.16)

project(GrimoireTome VERSION 0.1 LANGUAGES CXX)

# This is a different, more direct way to tell CMake where to find Qt.
# It points directly to the folder containing the "Qt6Config.cmake" file.
set(Qt6_DIR "C:/Qt/6.9.1/msvc2022_x64/lib/cmake/Qt6")

# This command should now succeed because we told it exactly where to look.
find_package(Qt6 REQUIRED COMPONENTS Widgets Network)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(PROJECT_SOURCES
    main.cpp
    mainwindow.cpp
    mainwindow.h
    mainwindow.ui
    addspelldialog.cpp
    addspelldialog.h
    addspelldialog.ui
    Grimoire.cpp
    Grimoire.h
    Page.cpp
    Page.h
    Spell.cpp
    spell.h
    json.hpp
    resources.qrc
)

qt_add_executable(GrimoireTome
    WIN32
    ${PROJECT_SOURCES}
)

target_link_libraries(GrimoireTome PRIVATE
    Qt::Widgets
    Qt::Network
)

qt_finalize_executable(GrimoireTome)
