set(SOURCE triangle.cpp)
set(INCLUDE triangle.hpp)

set(SHADERS)
set(ASSETS)

add_executable(triangle triangle.cpp application.cpp)
target_include_directories(triangle PRIVATE "../subprojects/DiligentEngine/DiligentCore")
target_link_libraries(triangle
  PRIVATE
  Diligent-GraphicsEngineInterface
  SDL2::SDL2main SDL2::SDL2
  )
