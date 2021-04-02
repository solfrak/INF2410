#define CATCH_CONFIG_MAIN
#include "catch.h"
#include "Student.h"
#include "facade.h"

// Quelques tests de l'implémentation du patron façade.
SCENARIO("Test Facade pour login"){

    facade f;
 
    REQUIRE(f.login("admin", "password") == "Bienvenue admin\n");
    REQUIRE(f.login("test", "test") == "Nous n'avons aucun utilisateur avec cet identifiant\n");
    REQUIRE(f.login("admin", "1234") == "Désolé, il s'agit du mauvais mot de passe\n");
}

// Quelques tests de l'implémentation du patron décorateur.
SCENARIO("Test Decorateur"){
    
    Student* student = new DecorateurObjectif("nouvel objectif", new BaseStudent("Will"));
    Student* student2 = new DecorateurObjectif("et doit suivre le rythme", new DecorateurObjectif("doit jouer juste", new BaseStudent("Samuel")));

    REQUIRE(student->printStudent() == "Will nouvel objectif");
    REQUIRE(student2->printStudent() == "Samuel doit jouer juste et doit suivre le rythme");
    REQUIRE(student2->fonctionnalite1() ==  "Samuel joue un morceau");
}


SCENARIO("Test de sous-composante du systeme"){
    PasswordCheck p;
    REQUIRE(p.getAccountPassword() == "password");
    REQUIRE(p.isPassCorrect("password") == true);
    REQUIRE(p.isPassCorrect("autre chose") == false);


    UsernameCheck u;
    REQUIRE(u.getUserName() == "admin");
    REQUIRE(u.isUserCorrect("admin") == true);
    REQUIRE(u.isUserCorrect("autre chose") == false);

    BaseStudent b("test");
    REQUIRE(b.fonctionnalite1() == "test ne fait aucune action");
    REQUIRE(b.printStudent() == b.name_);

}