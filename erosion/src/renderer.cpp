#include "renderer.hpp"

namespace Renderer {
    void init() {
        // GLFW Init and configure
        glfwInit();
        glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
        glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
        glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
        #ifdef MACOSX
            glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
        #endif
    }

    void destroy() {
        glfwTerminate();
    }

    Window::Window(const char* p_title)
    :vsync(false), wireframe(false), shouldClose(false) {
        title = p_title;
        // GLFW Window creation
        glfwWindow = glfwCreateWindow(500, 500, title, NULL, NULL);
        if (glfwWindow == NULL) {
            Log::err("Failed to create GLFW window");
            glfwTerminate();
        }
        glfwMakeContextCurrent(glfwWindow);

        // GLFW callbacks
        glfwSetFramebufferSizeCallback(glfwWindow, framebuffer_size_callback);

        // GLAD Load opengl function pointers
        if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) {
            Log::err("Failed to initialize GLAD");
        }
        glEnable(GL_DEPTH_TEST);
    }

    void Window::update_callback() {
        glfwMakeContextCurrent(glfwWindow);

        // Check close event
        if (glfwWindowShouldClose(glfwWindow)) {
            shouldClose = true;
        }
        
        // Update VSYNC
        if (vsync)
            glfwSwapInterval(0);
        else
            glfwSwapInterval(-1);

        // Update window size
        glfwGetWindowSize(glfwWindow, &size.x, &size.y);

        // Update wireframe mode
        if (wireframe)
            glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
        else
            glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);

        glfwSwapBuffers(glfwWindow);
        glfwPollEvents();
    }

    void Window::clear(math::vec4<float> p_color) {
        glClearColor(p_color.r, p_color.g, p_color.b, p_color.a);
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    }

    void Window::captureCursor() {
        glfwSetInputMode(glfwWindow, GLFW_CURSOR, GLFW_CURSOR_DISABLED);
    }

    Window::~Window() {
        glfwDestroyWindow(glfwWindow);
    }
};

// GLFW Window resize callback
// ---------------------------------------------------------
void framebuffer_size_callback(GLFWwindow* window, int width, int height) {
    glfwMakeContextCurrent(window);
    glViewport(0, 0, width, height);
}
