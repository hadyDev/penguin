#include<glad/glad.h>
#include<GLFW/glfw3.h>
#include<global/glfw/glfw.h>
#include<iostream>


namespace global::glfw{
    GLFWwindow* g_window;
    windowMode g_mode = windowMode::WINDOWED;
    GLFWmonitor* g_monitor;
    const GLFWvidmode* g_vid;
    int g_w = 800;
    int g_h = 600;
    const char* g_title = "penguin";

    bool init(windowMode mode){
        g_mode = mode;

        glfwInit();
        glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
        glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
        glfwWindowHint(GLFW_OPENGL_CORE_PROFILE, GLFW_OPENGL_PROFILE);
        glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GLFW_TRUE);

        g_monitor = glfwGetPrimaryMonitor();
        g_vid = glfwGetVideoMode(g_monitor);
        glfwWindowHint(GLFW_RED_BITS, g_vid->redBits);
        glfwWindowHint(GLFW_GREEN_BITS, g_vid->greenBits);
        glfwWindowHint(GLFW_BLUE_BITS, g_vid->blueBits);
        glfwWindowHint(GLFW_REFRESH_RATE, g_vid->refreshRate);
        glfwWindowHint(GLFW_DECORATED, GLFW_FALSE);
        
        if(g_mode == windowMode::WINDOWED){
            g_window = glfwCreateWindow(g_w, g_h, g_title, NULL, NULL);
        }else if(g_mode == windowMode::FULLSREEN){
            g_window = glfwCreateWindow(g_vid->width, g_vid->height, g_title, g_monitor, NULL);
        }

        if(g_window == NULL){
            std::cout<<"Glfw failed to create window\n";
            return false;
        }
        glfwMakeContextCurrent(g_window);

        if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
        {
            std::cout << "Failed to initialize GLAD\n";
            return false;
        }

        glClearColor(0,0,0,1);

        return true;
    }

    void begin(){
        glClear(GL_COLOR_BUFFER_BIT);
        glfwSwapBuffers(g_window);
    }

    void end(){
        glfwPollEvents();
    }

    void cleanUp(){
        glfwDestroyWindow(g_window);
    }

    //get
    bool get_windowIsOpen(){
        return glfwWindowShouldClose(g_window);
    }
};