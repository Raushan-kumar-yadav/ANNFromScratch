cmake_minimum_required(VERSION 3.16)

project(ANNFromScratch VERSION 1.0.0 LANGUAGES CXX)

# Set min of cpp verstion 17
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Auto code genration for qt
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)

# find library on system 
find_package(Qt6 REQUIRED COMPONENTS Widgets Quick)

add_subdirectory(app)
add_subdirectory(core)
add_subdirectory(ui)