#include "input.h"
#include <iostream>
#include <sstream>
using namespace std;

ParsedTurn readTurn()
{
    cout << "Vvedi znak (+ - * / %) i chislo cherez probel: ";

    string line;
    getline(cin, line);
    stringstream ss(line);

    ParsedTurn turn;
    ss >> turn.op >> turn.value;
    turn.valid = !ss.fail();

    // Otdelnaya proverka: esli posle znaka operatsii sleduet eshche odin znak
    // (naprimer "--5"), eto ne oshibka parsinga chisla, no eto ne to, chto
    // imeetsya v vidu igrokom - lovim otdelno.
    if (turn.valid)
    {
        stringstream check(line);
        char opCheck, nextChar;
        check >> opCheck >> nextChar;
        if (nextChar == '-' || nextChar == '+')
        {
            turn.valid = false;
        }
    }

    if (!turn.valid)
    {
        cout << "Neverny vvod! Hod propushchen.\n\n";
    }

    return turn;
}