#include <string>
class Student{
    private:
    public:
        std::string name_;
        Student(){}
        Student(std::string name): name_(name){}
        virtual ~Student(){}
        virtual std::string printStudent() const = 0;
        virtual std::string fonctionnalite1() const = 0;
};

//Classe Utilisateur de base. Il s'agit de la classe commune à 
//tout les autres type d'utilisateur (Professeur et Étudiant)
class BaseStudent: public Student{
    public:
        BaseStudent(std::string n): Student(n){}
        std::string printStudent() const override{
            return name_;
        }
        std::string fonctionnalite1() const override{
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


class DecorateurObjectif: public Decorator{
    private:
    std::string o;
    public:
        DecorateurObjectif(std::string objectif, Student* user): Decorator(user), o(objectif){
        }
        std::string printStudent() const override{
            return user_->printStudent() +" " +  o;
        }
        std::string fonctionnalite1() const override{
            return user_->name_ + " joue une chanson";
        }
};