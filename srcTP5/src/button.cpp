#include "button.h"

button::button(Command *command){
    this->c = command;
}

void button::press(){
    c->execute();
}