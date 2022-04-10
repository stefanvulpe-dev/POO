#include <iostream>
#include "Calculator.h"
#include "Operation.h"
#include "Adunare.h"
#include "Scadere.h"
#include "Inmultire.h"
#include "Impartire.h"

using namespace std; 

int main()
{
    Calculator c; 

    c += new Adunare();
    c += new Scadere(); 
    c += new Adunare(); 
    c += new Inmultire(); 
    c += new Impartire();

    cout << "Numarul de operatii suportate: " << (int)c << endl; 

    c.Compute(20, 10);

    if (c["Scadere"]) {
        cout << "Operatia de scadere este suportata de calculator.\n";
    }

    c -= "Scadere"; 
    c -= "Impartire";

    c.Compute(15, 6); 

    cout << "Numarul de operatii suportate: " << (int)c << endl;

    return 0;
}
