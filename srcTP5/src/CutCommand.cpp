#include "CutCommand.h"
#include <iostream>

void CutCommand::execute() const {
    com1->execute();
    std::cout << " et ";
    com2->execute();
}
