#include<iostream>
#include<global/global.h>

int main(){
    global::init(windowMode::FULLSREEN);

    while(!global::get_windowIsOpen()){
        global::begin();
        global::end();
    }
    global::cleanUp();
    return 0;
}