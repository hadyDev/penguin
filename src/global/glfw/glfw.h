#pragma once 
#include<types/penguinEnums.h>

namespace global::glfw{
    bool init(windowMode mode);
    void begin();
    void end();
    void cleanUp();

    //get
    bool get_windowIsOpen();
};