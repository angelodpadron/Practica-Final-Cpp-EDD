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

    Node* actual = s -> first;
    while (actual != NULL && !mismoHechizo(actual -> elem, h)){
        actual = actual -> next;
    }

    return actual != NULL;


}

/// Proposito: agrega un hechizo al conjunto
/// Costo: O(h), h = cantidad de hechizos
void addS(Hechizo h, Set s) {
    if (! belongsS(h, s)){

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

    Node * anterior = NULL;
    Node* n = s->first;
    while (n != NULL &&(!mismoHechizo(n->elem, h))){

        anterior = n;
        n = n->next;
    }
    if(anterior == NULL){

        delete s->first ;
        s->size = 0;
        s->first = NULL;
    }
    else{
        n = n->next;
        anterior->next = n;
        s->size--;
    }
}


/// Proposito: borra toda la memoria consumida por el conjunto (pero no la de los hechizos)
/// Costo: O(n)
void destroyS(Set s) {

    Node * actual  = s -> first;

    while (actual!= NULL){
        Node * aux = actual -> next;
        delete actual;
        actual = aux;
    }

    delete s ;
}

/// Proposito: retorna un nuevo conjunto que es la union entre ambos (no modifica estos conjuntos)
/// Costo: O(h^2), h = cantidad de hechizos
Set unionS(Set s1, Set s2) {

    Set join = emptyS();

    Node* n1 = s1 -> first;
    Node* n2 = s2 -> first;

    //elementos de primer set a join
    while (n1 != NULL){
        addS(n1 -> elem, join);
        n1 = n1 -> next;
    }

    //elementos de primer set a join
    while (n2 != NULL){
        addS(n2 -> elem, join);
        n2 = n2 -> next;
    }

    return join;
}
