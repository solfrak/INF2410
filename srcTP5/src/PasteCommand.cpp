#include "PasteCommand.h"
#include <iostream>

void PasteCommand::execute() const {
    std::cout << "l'application execute la commande " + com;
}
