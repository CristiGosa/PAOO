# Assuming main.cpp is the source file for your main executable
add_executable(circus main.cpp)

# Link your executable with the library
target_link_libraries(circus PRIVATE circus_library)