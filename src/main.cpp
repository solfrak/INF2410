#include <iostream>
#include <string>

class User
{
private:
    std::string firstName;
    std::string lastName;
    int id;
    

public:
    User(){};
    virtual void printUser();
    ~User(){};
};


class DecorateurUser : public User
{
private:
    User& user_;
public:
    DecorateurUser(User& user);
    virtual void printUser();
    ~DecorateurUser();
};
DecorateurUser::DecorateurUser(User& decorateur): user_(decorateur){

}

void DecorateurUser::printUser(){
    user_.printUser();
}

class Teacher : public DecorateurUser
{
private:
    /* data */
public:
    Teacher(User& decorateur);
    virtual void printUser();
    ~Teacher();
};

Teacher::Teacher(User& decorateur): DecorateurUser(decorateur){

}

void Teacher::printUser(){
    std::cout << "This user is a teacher";
}


int main(){
    User* simpleTest = new User();
    User* test = new Teacher(*simpleTest);
    test->printUser();
    return 0;
}