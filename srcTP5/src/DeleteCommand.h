#ifndef DELETECOMMAND
#define DELETECOMMAND

#include "Command.h"
#include <string>

class DeleteCommand: public Command
{
private:
    std::string com = "supprime la partition";
public:
    void execute() const override;
};

#endif
