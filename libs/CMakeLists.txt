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

FetchContent_MakeAvailable(
        glm
        glfw
        glad
)

target_link_libraries(ServerOpenGLRenderer
        PRIVATE glm::glm
        PRIVATE glfw
        PRIVATE glad
)

target_link_libraries(bunGL
        PRIVATE glm::glm
        PRIVATE glfw
        PRIVATE glad
)
