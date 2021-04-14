#ifndef CUTCOMMAND
#define CUTCOMMAND
#include "Command.h"
#include "CopyCommand.h"
#include "DeleteCommand.h"
#include <string>

class CutCommand: public Command
{
private:
    Command *com1 = new CopyCommand();
    Command *com2 = new DeleteCommand();
public:
    void execute() const override;
};

#endif 