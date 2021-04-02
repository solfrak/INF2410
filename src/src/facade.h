#include <string>
#include "PasswordCheck.h"
#include "UsernameCheck.h"
using namespace std;

class facade
{
private:
    PasswordCheck p;
    UsernameCheck u;
public:
    string login(string, string);

};
