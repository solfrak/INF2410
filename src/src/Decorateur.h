#include <string>
#include <iostream>


class User{
    private:
    public:
        std::string name_;
        User(){}
        User(std::string name): name_(name){}
        virtual ~User(){}
        virtual std::string printUser() const = 0;
};

class ConcreteUser: public User{
    public:
        ConcreteUser(std::string n): User(n){}
        std::string printUser() const override{
            return "";
        }
};

class Decorator: public User{
    protected:
        User* user_;
    public:
        Decorator(User* user): user_(user){
        }
        std::string printUser() const override{
            return this->user_->printUser();
        }
};

class DecorateurTeacher: public Decorator{
    public:
        DecorateurTeacher(User* user): Decorator(user){
        }
        std::string printUser() const override{
            return "this is a teacher " + user_->name_;
        }
};

class DecorateurStudent: public Decorator{
    public:
        DecorateurStudent(User* user): Decorator(user){
        }
        std::string printUser() const override{
            return "this is a student " + user_->name_;
        }
};