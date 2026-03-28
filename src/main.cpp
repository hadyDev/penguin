#include<iostream>
#include<global/global.h>

int main(){
    global::init(windowMode::WINDOWED);

    while(!global::get_windowIsOpen()){
        global::begin();
        global::end();
    }
    global::cleanUp();
    return 0;
}