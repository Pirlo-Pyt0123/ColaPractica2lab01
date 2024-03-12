#include <iostream>
#include "Cola.h"

using namespace std;

int main() {
	Cola<string> cola(6);
	cola.encolar("Pirlo");
	cola.encolar("Atzel");
	cola.encolar("Mendez");
	cola.encolar("Diego");
	cola.encolar("Franco");
	cola.encolar("Ramiro");

	cola.imprimir();

	string aux = cola.desencolar();

	cola.imprimir();

	return 0;
}