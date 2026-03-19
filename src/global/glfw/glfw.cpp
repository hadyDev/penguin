#include<global/glfw/glfw.h>
#include<GLFW/glfw3.h>
#include<iostream>


namespace global::glfw{
    GLFWwindow* g_window;
    windowMode g_mode = windowMode::WINDOWED;
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
        
        if(g_mode == windowMode::WINDOWED){
            g_window = glfwCreateWindow(g_w, g_h, g_title, NULL, NULL);
        }else if(g_mode == windowMode::FULLSREEN){
            g_window = glfwCreateWindow(g_w, g_h, g_title, NULL, NULL);
        }

        if(g_window == NULL){
            std::cout<<"Glfw failed to create window"<<std::endl;
            return false;
        }
        glfwMakeContextCurrent(g_window);

        return true;
    }

    void begin(){
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