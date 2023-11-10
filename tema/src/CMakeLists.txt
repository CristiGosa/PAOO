# Assuming circus.cpp is the source file corresponding to circus.hpp
add_library(circus_library circus.cpp)

# Optionally, specify the C++ standard for this library
target_compile_features(circus_library PUBLIC cxx_std_11)