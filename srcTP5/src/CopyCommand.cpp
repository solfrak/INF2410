#include "CopyCommand.h"
#include <iostream>
void CopyCommand::execute() const {
    std::cout << "l'application execute la commande " + com;
}
