file(GLOB bunGL_src CONFIGURE_DEPENDS
        "*/*.cpp"
        "*.cpp"
)

add_library(bunGL ${bunGL_src}
        Buffers/VertexAttributesBuffer.hpp
        Buffers/VAOBuilder.hpp
        Scene/Scene.cpp
        Scene/Scene.h
        Buffers/ShaderStorageBuffer.hpp
        Buffers/TextureBuffer.hpp
        Buffers/TextureData.h
        Properties/Illuminant.cpp
        Properties/Illuminant.h
        IUpdate.h)

target_include_directories(bunGL
        PRIVATE .
)

target_link_libraries(ServerOpenGLRenderer
        PRIVATE bunGL
)