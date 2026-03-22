#include<global/global.h>
#include<global/glfw/glfw.h>
#include<iostream>

namespace global{

    
    bool init(windowMode mode){
        std::cout<<"Global init\n";

        glfw::init(mode);

        return true;
    }
    
    void begin(){

        glfw::begin();
    
    }
    
    void end(){
    
        glfw::end();
    }
    
    void cleanUp(){
        std::cout<<"Global cleanUp\n";

        glfw::cleanUp();
    }   

    //get

    bool get_windowIsOpen(){
        return glfw::get_windowIsOpen();
    }
}