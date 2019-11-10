#include "set.h"
#include "../common/Common.h"

struct Node {
   Hechizo elem; // el elemento que este nodo almacena
   Node* next; // siguiente nodo de la cadena de punteros
};

struct SetSt {
   int size; // cantidad de elementos del conjunto
   Node* first; // puntero al primer elemento
};

/**
  Invariantes de representacion:
    - size es la cantidad de nodos
    - no hay nodos con hechizos repetidos
**/

/// Proposito: retorna un conjunto de hechizos vacio
/// Costo: O(1)
Set emptyS() {
   COMPLETAR(emptyS);
}

/// Proposito: retorna la cantidad de hechizos
/// Costo: O(1)
int sizeS(Set s) {
   COMPLETAR(sizeS);
}

/// Proposito: indica si el hechizo pertenece al conjunto
/// Costo: O(h), h = cantidad de hechizos
bool belongsS(Hechizo h, Set s) {
   COMPLETAR(belongsS);
}

/// Proposito: agrega un hechizo al conjunto
/// Costo: O(h), h = cantidad de hechizos
void addS(Hechizo h, Set s) {
   COMPLETAR(addS);
}

/// Proposito: borra un hechizo del conjunto (si no existe no hace nada)
/// Costo: O(h), h = cantidad de hechizos
void removeS(Hechizo h, Set s) {
   COMPLETAR(removeS);
}

/// Proposito: borra toda la memoria consumida por el conjunto (pero no la de los hechizos)
/// Costo: O(n)
void destroyS(Set s) {
   COMPLETAR(destroyS);
}

/// Proposito: retorna un nuevo conjunto que es la union entre ambos (no modifica estos conjuntos)
/// Costo: O(h^2), h = cantidad de hechizos
Set unionS(Set s1, Set s2) {
   COMPLETAR(unionS);
}
