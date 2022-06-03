#include <iostream>
#include "Entry.h"
#include "Database.h"
#include "StringData.h"
#include "IntegerData.h"
#include "StringDataException.h"
#include "IntegerDataException.h"

using namespace std;

int main() {
	Database d;
	Entry* e1 = (Entry*)new StringData("Student", "Alexandru");
	Entry* e2 = (Entry*)new IntegerData("NotaEngleza", "10");
	(d += e1) += (new StringData("Facultate", "FII"));
	(d += e2) += (new IntegerData("NotaPOO", "9"));
	d.Print();
	for (Entry* e : d) {
		try {
			e->Subtract(5);
		}
		catch (StringDataException& e1) {
			cout << e1.what() << "\n";
		}
		catch (IntegerDataException& e2) {
			cout << e2.what() << "\n";
		}
	}
	d.Print();
	d -= "NotaEngleza";
	d.Print();
	for (auto e : d) {
		e->Add("1");
	}
	d.Print();
	return 0;
}