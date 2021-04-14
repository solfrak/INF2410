#ifndef BUTTON
#define BUTTON

#include "Command.h"
class button
{
private:
    Command *c;
public:
    button(Command *command);
    void press();
    
};

#endif