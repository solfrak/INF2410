#define CATCH_CONFIG_MAIN
#include "catch.h"
#include "Student.h"
#include "facade.h"

SCENARIO("Test Facade pour login"){
    facade f;
 
    REQUIRE(f.login("admin", "password") == "Bienvenue admin\n");
 
    REQUIRE(f.login("test", "test") == "Nous n'avons aucun utilisateur avec cet identifiant\n");
   
    REQUIRE(f.login("admin", "1234") == "Désolé, il s'agit du mauvais mot de passe\n");
}
SCENARIO("Test Decorateur"){
    
    Student* student = new DecorateurObjectif("nouvel objectif", new BaseStudent("Will"));
    Student* student2 = new DecorateurObjectif("et doit suivre le rythme", new DecorateurObjectif("doit jouer juste", new BaseStudent("Samuel")));
    
    REQUIRE(student->printStudent() == "Will nouvel objectif");
    REQUIRE(student2->printStudent() == "Samuel doit jouer juste et doit suivre le rythme");
    REQUIRE(student2->fonctionnalite1() ==  "Samuel joue une chanson");
    
}