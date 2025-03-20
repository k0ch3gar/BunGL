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
        Updatable.h
        Events/EventMediator.cpp
        Events/EventMediator.h
        Events/IMediator.h
        Properties/Rotatable.h
        Properties/Rotatable.cpp
        Properties/Scalable.cpp
        Properties/Scalable.h
        Properties/Light/Light.h
        Buffers/Storable.hpp
        Properties/BasicSceneObject.cpp
        Properties/BasicSceneObject.h
        Shaders/Uniforms/IUniform.h
        Shaders/Uniforms/Uniformable.hpp
        Shaders/Uniforms/Mat4Uniformable.hpp
        Shaders/Uniforms/Vec3Uniformable.hpp
        Shaders/Uniforms/UniformManager.hpp
        Shaders/Uniforms/IntUniformable.hpp
        Utils/TextureData.h
        Properties/Attachable.cpp
        Properties/Attachable.h
        Properties/IAttachable.h
        Buffers/Interfaces/IBind.h
        Buffers/Interfaces/BindBufferObject.hpp
)

target_include_directories(bunGL
        PRIVATE .
)

target_link_libraries(ServerOpenGLRenderer
        PRIVATE bunGL
)