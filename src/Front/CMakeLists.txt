cmake_minimum_required(VERSION 3.5)

project(3DViewer VERSION 0.1 LANGUAGES CXX)

set(CMAKE_INCLUDE_CURRENT_DIR ON)
set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(QT NAMES Qt6 Qt5 REQUIRED COMPONENTS Widgets OpenGL)
find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS Widgets OpenGL)

if(${QT_VERSION_MAJOR} GREATER_EQUAL 6)
    find_package(Qt6 REQUIRED COMPONENTS OpenGLWidgets)
endif()

# Platform-specific libraries
if(APPLE)
    message("Building for macOS")
    find_library(COCOA_LIBRARY Cocoa)
    find_library(OpenGL_LIBRARY OpenGL)
    find_library(GLUT_LIBRARY GLUT)
    set(PLATFORM_LIBS ${COCOA_LIBRARY} ${OpenGL_LIBRARY} ${GLUT_LIBRARY})
elseif(UNIX)
    message("Building for Linux")
    find_package(OpenGL REQUIRED)
    find_library(GLU_LIBRARY GLU)
    if(NOT GLU_LIBRARY)
        message(FATAL_ERROR "GLU library not found.")
    endif()
    set(PLATFORM_LIBS OpenGL::GL ${GLU_LIBRARY})
endif()

# Output directory for the built executable
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/../build)

# Source files
set(PROJECT_SOURCES
        ../Back/parser.cc
        ../Controller/controller.cc
        main.cc
        GLView/glview.cc
        GLView/file_opening.cc
        GLView/transformation.cc
        MainWindow/mainwindow.cc
        MainWindow/defaults.cc
        MainWindow/settings.cc
        MainWindow/setup.cc
        MainWindow/ui_bonuses.cc
        MainWindow/ui_buttons.cc
        MainWindow/ui_comboboxes.cc
        MainWindow/ui_sliders.cc
        )

# Header files
set(PROJECT_HEADERS
        ../Back/parser.h
        ../Back/matrix_transformation.h
        ../Back/model_facade.h
        ../Controller/controller.h
        observer.h
        GLView/glview.h
        MainWindow/mainwindow.h
        )

# UI files
set(PROJECT_FORMS
        MainWindow/mainwindow.ui
        )

# Add executable
if(${QT_VERSION_MAJOR} GREATER_EQUAL 6)
    qt_add_executable(3DViewer
            MANUAL_FINALIZATION
            ${PROJECT_SOURCES}
            ${PROJECT_HEADERS}
            ${PROJECT_FORMS}
            )
else()
    add_executable(3DViewer
            ${PROJECT_SOURCES}
            ${PROJECT_HEADERS}
            ${PROJECT_FORMS}
            )
endif()

# Include and link QtGifImage library
add_subdirectory(resources/QtGifImage)
target_link_libraries(3DViewer PRIVATE Qt${QT_VERSION_MAJOR}::Widgets Qt${QT_VERSION_MAJOR}::OpenGL QtGifImage ${PLATFORM_LIBS})

if(${QT_VERSION_MAJOR} GREATER_EQUAL 6)
    target_link_libraries(3DViewer PRIVATE Qt${QT_VERSION_MAJOR}::OpenGLWidgets)
    qt_finalize_executable(3DViewer)
endif()

set_target_properties(3DViewer PROPERTIES
        MACOSX_BUNDLE_GUI_IDENTIFIER my.example.com
        MACOSX_BUNDLE_BUNDLE_VERSION ${PROJECT_VERSION}
        MACOSX_BUNDLE_SHORT_VERSION_STRING ${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR}
        MACOSX_BUNDLE TRUE
        WIN32_EXECUTABLE TRUE
        )

# Platform-specific settings
if(UNIX AND NOT APPLE)
    target_link_libraries(3DViewer PRIVATE ${PLATFORM_LIBS})
elseif(APPLE)
    target_link_libraries(3DViewer PRIVATE "-framework OpenGL" "-framework GLUT")
endif()
