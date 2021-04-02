#include <string>
using namespace std;

// Classe qui stock le nom d'utilisateur et permet de vérifier si le nom entré est correct
class UsernameCheck
{
private:
    string username = "admin";
public:

    string getUserName(){
        return username;
    }
    /// Regarde si la variable entré est le nom utilisateur
    /// \param nameToCheck nom utilisateur a vérifié
    /// \return un bool qui indique si est correct ou non
    bool isUserCorrect(string nameToCheck){
        if(username == nameToCheck){
            return true;
        }
        else{
            return false;
        }
    }
};

