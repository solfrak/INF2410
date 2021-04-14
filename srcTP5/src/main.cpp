#define CATCH_CONFIG_RUNNER
#include "catch.h"
#include "Command.h"
#include "CopyCommand.h"
#include <string>
#include <iostream>
#include <sstream>
#include "button.h"
#include "PasteCommand.h"
#include "CutCommand.h"

#include "Mediator.h"


void runCommand() {
    button copyButton = button(new CopyCommand());
    button pasteButton = button(new PasteCommand());
    button cutButton = button(new CutCommand());

    std::cout << "Appuyer sur:\nc: pour copier\nv: pour coller\nx: pour couper\n";
    char input;
    std::cin >> input;
    
    switch (input)
    {
    case 'c':
        copyButton.press();
        break;
    
    case 'v':
        pasteButton.press();
        break;
    
    case 'x':
        cutButton.press();
        break;

    default:
        std::cout << "Entre invalide!";
        break;
    }

}

void runMediator() {
    Professeur *c1 = new Professeur();
    Student *c2 = new Student();
    DataBase *c3 = new DataBase();
    ConcreteMediator *mediator = new ConcreteMediator(c1, c2, c3);

    std::cout << "Appuyer sur:\n p: pour envoyer les notes en tant que professeur\n s: pour recevoir les notes en tant qu'étudiant\n";
    char input;
    std::cin >> input;
    
    
    switch (input)
    {
    case 'p':
        c1->EnvoyerNote();
        break;
    case 's':
        c2->voirNote();
    }
}

void runTest() {
    Catch::Session().run();

}

    // button cutButton = button(new CutCommand());
TEST_CASE("Test command copy"){
    std::stringstream buffer;
    std::streambuf* prevcoutbuf = std::cout.rdbuf(buffer.rdbuf());
    
    button copyButton = button(new CopyCommand());
    

    copyButton.press();
    REQUIRE(buffer.str() == "l'application execute la commande copier la partition");
  
    std::cout.rdbuf(prevcoutbuf);    
}
TEST_CASE("Test command paste"){
    std::stringstream buffer;
    std::streambuf* prevcoutbuf = std::cout.rdbuf(buffer.rdbuf());
    
    button pasteButton = button(new PasteCommand());

    pasteButton.press();
    REQUIRE(buffer.str() == "l'application execute la commande colle la partition");

    std::cout.rdbuf(prevcoutbuf);    
}
TEST_CASE("Test command cut"){
    std::stringstream buffer;
    std::streambuf* prevcoutbuf = std::cout.rdbuf(buffer.rdbuf());
    
    button cutButton = button(new CutCommand());

    cutButton.press();
    REQUIRE(buffer.str() == "l'application execute la commande copier la partition et l'application execute la commande supprime la partition");

    std::cout.rdbuf(prevcoutbuf);    
}
TEST_CASE("Test mediator prof"){
    std::stringstream buffer;
    std::streambuf* prevcoutbuf = std::cout.rdbuf(buffer.rdbuf());

    Professeur *c1 = new Professeur();
    Student *c2 = new Student();
    DataBase *c3 = new DataBase();
    ConcreteMediator *mediator = new ConcreteMediator(c1, c2, c3);

    c1->EnvoyerNote();
    REQUIRE(buffer.str() == "Le professeur envoie des notes.\nLe mediateur reagie à l'action du prof et enregitre les notes dans la base de données.\n");

    std::cout.rdbuf(prevcoutbuf);  
}
TEST_CASE("Test mediator student"){
    std::stringstream buffer;
    std::streambuf* prevcoutbuf = std::cout.rdbuf(buffer.rdbuf());

    Professeur *c1 = new Professeur();
    Student *c2 = new Student();
    DataBase *c3 = new DataBase();
    ConcreteMediator *mediator = new ConcreteMediator(c1, c2, c3);

    c2->voirNote();
    REQUIRE(buffer.str() == "L'étudiant veut voir ses notes.\nLe médiateur réagie à l'action de l'étudiant et va cherche les notes dans la base de données.\n");

    std::cout.rdbuf(prevcoutbuf);  
}
   


int main(){
    while(true){
        std::cout << "\n\nAppuyer sur:\n1: Pour executer le patron command\n2: Pour executer le patron mediateur\n3: Pour executer les tests automatises\n4: Pour fermer le programme\n";
        int input;
        std::cin >> input;

        switch (input)
        {
        case 1:
            runCommand();
            break;

        case 2:
            runMediator();
            break;

        case 3:
            runTest();
            break;

        case 4:
            return 0;
            break;

        default:
            std::cout << "Entre invalide!";
            break;
        }
    }
}