#include <string>
#include <iostream>
class parent{
    public:
    parent(){}
    virtual ~parent(){}
    virtual std::string print() = 0;
};

class child: public parent{
    public:
    int nom;
    child(int i): parent(), nom(i){
    }
    ~child(){}
    std::string print() override{
        return "test";
    }
    std::string newFunction(){
        return "wow";
    }
};

int main(){
    parent* test = new child(50);
    child* test2 = (child*) test;
    std::cout<< test2->nom << test2->newFunction();
}
