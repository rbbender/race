message("Using Dear ImGui")
add_subdirectory(imgui)

# Generic test that uses conan libs
add_executable(race main.cpp)
target_link_libraries(
  race
  PRIVATE project_options
          project_warnings
          CONAN_PKG::docopt.cpp
          CONAN_PKG::fmt
          CONAN_PKG::spdlog)
