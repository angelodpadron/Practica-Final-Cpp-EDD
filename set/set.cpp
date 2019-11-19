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

   Set s = new SetSt;
   s -> size = 0;
   s -> first = NULL;

   return s;
}

/// Proposito: retorna la cantidad de hechizos
/// Costo: O(1)
int sizeS(Set s) {

   return s -> size;
}

/// Proposito: indica si el hechizo pertenece al conjunto
/// Costo: O(h), h = cantidad de hechizos
bool belongsS(Hechizo h, Set s) {

    if (s == NULL){
        cout << "Error, coleccion nula. /n";
        exit(1);
    }

    Set temporal = s;

    while (temporal -> first != NULL){
        if (temporal -> first -> elem == h){
            return true;
        }
        temporal -> first = temporal -> first -> next;
    }

   return false;
}

/// Proposito: agrega un hechizo al conjunto
/// Costo: O(h), h = cantidad de hechizos
void addS(Hechizo h, Set s) {
    if (! belongsS(h, s)){

    /*
    if (belongsS(h, s)){
        cout << "El hechizo ya existe en la colección. /n";
        exit(1);
    }
    */

        Node* n = new Node;
        n -> elem = h;
        n -> next = s -> first;
        s -> first = n;
        s -> size++;
    }
}

/// Proposito: borra un hechizo del conjunto (si no existe no hace nada)
/// Costo: O(h), h = cantidad de hechizos
void removeS(Hechizo h, Set s) {

    if (belongsS(h,s)){

    /*
    if (! belongsS(h,s)){
        cout << "El hechizo no existe en la colección. /n";
        exit(1);
    }
    */

        Set temporalS = s;
        Node* temporalN = temporalS -> first;

        while (temporalS -> first != NULL && temporalS -> first -> elem != h){
            temporalS -> first = temporalS -> first -> next;
            temporalN = temporalS -> first;
        }

        s -> first = temporalN -> next;
        s -> size--;

        delete temporalN;
        return;
    }
}

/// Proposito: borra toda la memoria consumida por el conjunto (pero no la de los hechizos)
/// Costo: O(n)
void destroyS(Set s) {
   //COMPLETAR(destroyS);
}

/// Proposito: retorna un nuevo conjunto que es la union entre ambos (no modifica estos conjuntos)
/// Costo: O(h^2), h = cantidad de hechizos
Set unionS(Set s1, Set s2) {
   //COMPLETAR(unionS);
}
