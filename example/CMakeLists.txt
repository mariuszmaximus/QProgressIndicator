
set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(QT NAMES Qt6 Qt5 REQUIRED COMPONENTS Widgets)
find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS Widgets)

add_executable(ProgressIndicator_example 
    Example.cpp
    Example.h
    main.cpp
)

target_link_libraries(ProgressIndicator_example PUBLIC Qt${QT_VERSION_MAJOR}::Widgets ProgressIndicator)
