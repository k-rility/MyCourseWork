cmake_minimum_required(VERSION 3.21)
project(CourseWork)

set(CMAKE_CXX_STANDARD 20)

set(CMAKE_INCLUDE_CURRENT_DIR ON)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(CMAKE_PREFIX_PATH /home/kirill/Qt/5.15.2/gcc_64/lib/cmake)

find_package(QT NAMES Qt5 COMPONENTS Widgets REQUIRED)
find_package(Qt${QT_VERSION_MAJOR} COMPONENTS Widgets REQUIRED)
find_package(Qt5Sql REQUIRED)

add_executable(CourseWork
        demo/main.cpp

        AuthWindow/authwindow.cpp
        AuthWindow/authwindow.hpp
        AuthWindow/authwindow.ui

        MainWindow/mainwindow.cpp
        MainWindow/mainwindow.hpp
        MainWindow/mainwindow.ui

        DataBase/db_interface.cpp
        DataBase/db_interface.hpp

        MainWindow/regular_customers.cpp
        MainWindow/regular_customers.hpp
        MainWindow/regular_customers.ui

        MainWindow/booking.cpp
        MainWindow/booking.hpp
        MainWindow/booking.ui

        MainWindow/window_base.cpp
        MainWindow/window_base.hpp
        )

target_link_libraries(CourseWork Qt5::Widgets Qt5::Core Qt5::Sql)

