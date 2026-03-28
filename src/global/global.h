#pragma once 
#include"enums/penguinEnums.h"

namespace global{
    bool init(windowMode mode);
    void begin();
    void end();
    void cleanUp();

    //get
    bool get_windowIsOpen();
};