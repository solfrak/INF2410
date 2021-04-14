#include <string>
#include "PasswordCheck.h"
#include "UsernameCheck.h"
using namespace std;

//Classe facade qui simplifie l'utilisation du logiciel en donnant accès à des fonctions déjà implémenté
class facade
{
private:
    PasswordCheck p;
    UsernameCheck u;
public:

    /// fonction qui permet à un utilisateur de se connnecter
    ///\param string nom d'utilisateur
    ///\param string mot de passe
    ///\return string statut de connection
    string login(string, string);

};
