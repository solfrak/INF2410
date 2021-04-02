#include <string>
#include <iostream>

//Classe Utilisateur: il s'agit de la structure pour la classe utilisateur de base
class Student{
    private:
    public:
        std::string name_;
        Student(){}
        Student(std::string name): name_(name){}
        virtual ~Student(){}
        virtual std::string printUser() const = 0;
};

//Classe Utilisateur de base. Il s'agit de la classe commune à 
//tout les autres type d'utilisateur (Professeur et Étudiant)
class BaseStudent: public Student{
    public:
        BaseStudent(std::string n): Student(n){}
        std::string printUser() const override{
            return "";
        }
};

//Classe décorateur
class Decorator: public Student{
    protected:
        Student* user_;
    public:
        Decorator(Student* user): user_(user){
        }
};

class DecorateurTeacher: public Decorator{
    public:
        DecorateurTeacher(Student* user): Decorator(user){
        }
        std::string printUser() const override{
            return user_->name_ + " est un professeur";
        }
        std::string ajouterChanson(){
            return "une chanson est ete ajoute par "  + user_->name_;
        }
};

class DecorateurStudent: public Decorator{
    public:
        DecorateurStudent(Student* user): Decorator(user){
        }
        std::string printUser() const override{
            return user_->name_ + " est un etudiant";
        }

        std::string jouerChanson(){
            return user_->name_ + " joue une chanson";
        }
};

