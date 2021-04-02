#include <string>
using namespace std;
class PasswordCheck
{
private:
    string password = "password";
public:
    string getAccountPassword(){return password;}
    
    bool isPassCorrect(string passToCheck){
        if(password == passToCheck){
            return true;
        }
        else{
            return false;
        }
    }
};

