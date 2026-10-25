# neurolens_core: pure C++20, no Qt.
add_library(neurolens_core STATIC
    src/data/linear.cpp
    src/data/spiral.cpp
)
add_library(neurolens::core ALIAS neurolens_core)

# Public headers are included 
target_include_directories(neurolens_core PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include)
target_compile_features(neurolens_core PUBLIC cxx_std_20)
