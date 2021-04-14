#include <string>
using namespace std;

// Classe qui stock et qui vérifie si le mot de passe entré est correct
class PasswordCheck
{
private:
    string password = "password";
public:
    string getAccountPassword(){return password;}
    
    /// Regarde si la variable entré est le mot de passe
    /// \param passToCheck nom utilisateur a vérifié
    /// \return un bool qui indique si est correct ou non
    bool isPassCorrect(string passToCheck){
        if(password == passToCheck){
            return true;
        }
        else{
            return false;
        }
    }
};

