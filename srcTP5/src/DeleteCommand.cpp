#include "DeleteCommand.h"
#include <iostream>

void DeleteCommand::execute() const {
    std::cout << "l'application execute la commande " + com;
}
