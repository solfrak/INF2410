#ifndef COPYCOMMAND
#define COPYCOMMAND

#include "Command.h"
#include <string>

class CopyCommand: public Command
{
private:
    std::string com = "copier la partition";
public:
    void execute() const override;
};

#endif