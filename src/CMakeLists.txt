file(GLOB bunGL_src CONFIGURE_DEPENDS
        "*/*.cpp"
        "*.cpp"
)

add_library(bunGL ${bunGL_src}
        Utils/FileUtils.h
        Utils/FileUtils.h
        Shaders/ShaderBuilder.hpp
        Utils/ObjParser.hpp)

target_include_directories(bunGL
        PRIVATE .
)

target_link_libraries(ServerOpenGLRenderer
        PRIVATE bunGL
)