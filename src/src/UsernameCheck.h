#include <string>
using namespace std;
class UsernameCheck
{
private:
    string username = "admin";
public:
    string getUserName(){
        return username;
    }
    bool isUserCorrect(string nameToCheck){
        if(username == nameToCheck){
            return true;
        }
        else{
            return false;
        }
    }
};

