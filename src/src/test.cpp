#define CATCH_CONFIG_MAIN
#include "catch.h"
#include "Decorateur.h"


TEST_CASE("I don't know what i'm doing"){
    User* teacher = new DecorateurTeacher(new ConcreteUser("Samuel"));
    User* student = new DecorateurStudent(new ConcreteUser("Will"));

    REQUIRE(teacher->printUser() == "this is a teacher Samuel");
    REQUIRE(student->printUser() == "this is a student Will");
}