include(FetchContent)

FetchContent_Declare(
        glm
        GIT_REPOSITORY https://github.com/g-truc/glm.git
)

FetchContent_Declare(
        glfw
        GIT_REPOSITORY https://github.com/glfw/glfw.git
)

FetchContent_Declare(
        glad
        GIT_REPOSITORY https://github.com/ValtoLibraries/GLAD.git
)

FetchContent_Declare(
        cil
        GIT_REPOSITORY https://gitlab.com/gameengine3/cppimageloader.git
        GIT_TAG 68100019eed8117218d2110f7b22358b3324e462
)


FetchContent_MakeAvailable(
        glm
        glfw
        glad
        cil
)

target_link_libraries(ServerOpenGLRenderer
        PRIVATE glm::glm
        PRIVATE glfw
        PRIVATE glad
        PRIVATE CPPImageLoader
)

target_link_libraries(bunGL
        PRIVATE glm::glm
        PRIVATE glfw
        PRIVATE glad
        PRIVATE CPPImageLoader
)
