#include "facade.h"

string facade::login(string username, string password){
    if(u.isUserCorrect(username) && p.isPassCorrect(password)){
        return "Bienvenue " + username + '\n';
    }
    else if(u.isUserCorrect(username) && !p.isPassCorrect(password)){
        return "Désolé, il s'agit du mauvais mot de passe\n";
    }
    else{
        return "Nous n'avons aucun utilisateur avec cet identifiant\n";
    }
}