#include <string>

// Interface classe student
class Student{
    private:
    public:
        std::string name_;
        Student(std::string name): name_(name){}
        virtual ~Student(){}
        /// fonction qui indique le nom de la personne et autre chose dépendament de ces décorateurs
        ///\return un string
        virtual std::string printStudent() const = 0;
        
        /// fonctionnalité disponible à l'étudiant dépandemment de ces décorateurs
        ///\return un string
        virtual std::string fonctionnalite1() const = 0;
};

// Classe Utilisateur de base. Utilisé pour créer un objet étudiant dans le program
class BaseStudent: public Student{
    public:
        BaseStudent(std::string n): Student(n){}
        std::string printStudent() const override{
            return name_;
        }
        std::string fonctionnalite1() const override{
            return name_ + " ne fait aucune action";
        }
};

// Classe décorateur qui sert de base pour tout les decorateurs dérivés
class Decorator: public Student{
    protected:
        Student* user_;
    public:
        Decorator(Student* user): user_(user), Student(user->name_){
        }
};

// Classe décorateur qui permet d'ajouter des objectifs personnalisé à un étudiant de base.
class DecorateurObjectif: public Decorator{
    private:
    std::string o;
    public:
        DecorateurObjectif(std::string objectif, Student* user): Decorator(user), o(objectif){
        }
        std::string printStudent() const override{
            return this->user_->printStudent() +" " +  o;
        }

        std::string fonctionnalite1() const override{
            return user_->name_ + " joue un morceau";
        }
};