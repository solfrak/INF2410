#define CATCH_CONFIG_MAIN
#include "catch.h"
#include "Decorateur.h"


TEST_CASE("Test decorateur pour professeur"){
    User* teacher = new DecorateurTeacher(new BaseUser("Samuel"));
    
    REQUIRE(teacher->printUser() == "Samuel est un professeur");
    REQUIRE(teacher->ajouterChanson() == "une chanson est ete ajoute par Samuel");
}

TEST_CASE("Test decorateur pour etudiant"){
    DecorateurStudent* student = new DecorateurStudent(new BaseUser("Will"));
    
    REQUIRE(student->printUser() == "Will est un etudiant");
    REQUIRE(student->jouerChanson() == "Will joue une chanson");
}