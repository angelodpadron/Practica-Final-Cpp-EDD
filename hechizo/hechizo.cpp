#include "hechizo.h"
#include "../common/Common.h"

struct HechizoSt {
   string nombre;
   int poder;
};

/// Proposito: crea un hechizo dado un nombre y un poder
Hechizo crearHechizo(string nombre, int poder) {
   COMPLETAR(crearHechizo);
}

/// Proposito: retorna el nombre del hechizo
string nombreHechizo(Hechizo h) {
   COMPLETAR(nombreHechizo);
}

/// Proposito: retorna el poder de un hechizo
int poderHechizo(Hechizo h) {
   COMPLETAR(poderHechizo);
}

/// Proposito: indica si un hechizo tiene el mismo nombre que otro
/// Costo: O(1)
bool mismoHechizo(Hechizo h1, Hechizo h2) {
   COMPLETAR(mismoHechizo);
}

/// Proposito: indica si el primer hechizo es mas poderoso que el otro
/// Costo: O(1)
bool masPoderoso(Hechizo h1, Hechizo h2) {
   COMPLETAR(masPoderoso);
}

void printHechizo(Hechizo h) {
   cout << "Hechizo: {" << endl;
   cout << "  nombre: " << h->nombre << endl;
   cout << "  poder: " << h->poder << endl;
   cout << "}" << h->poder << endl;
}

/// Proposito: libera la memoria
void destroyHechizo(Hechizo h) {
   COMPLETAR(destroyHechizo);
}

