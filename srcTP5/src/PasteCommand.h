#ifndef PASTECOMMAND
#define PASTECOMMAND

#include "Command.h"
#include <string>

class PasteCommand: public Command
{
private:
    std::string com = "colle la partition";
public:
    void execute() const override;
};

#endif