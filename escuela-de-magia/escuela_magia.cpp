#include "escuela_magia.h"
#include "../common/Common.h"

struct EscuelaDeMagiaSt {
   Set hechizos;
   Map magos;
   MaxHeap heap;
};

/// Propósito: Devuelve una escuela vacía.
/// O(1)
EscuelaDeMagia fundarEscuela() {
   EscuelaDeMagia edm = new EscuelaDeMagiaSt;
   edm ->hechizos = emptyS();
   edm ->magos = emptyM();
   edm ->heap = emptyH();

   return edm;
}

/// Propósito: Indica si la escuela está vacía.
/// O(1)
bool estaVacia(EscuelaDeMagia m) {
   return isEmptyH(m ->heap);
}

/// Propósito: Incorpora un mago a la escuela (si ya existe no hace nada).
/// O(log m)
void registrar(string nombre, EscuelaDeMagia m) {

    Mago mago = crearMago(nombre);

    assocM(nombre, mago, m ->magos);
    insertH(mago, m ->heap);


}

/// Propósito: Devuelve los nombres de los magos registrados en la escuela.
/// O(m)
vector<string> magos(EscuelaDeMagia m) {
   return domM(m ->magos);
}

/// Propósito: Devuelve los hechizos que conoce un mago dado.
/// Precondición: Existe un mago con dicho nombre.
/// O(log m)
Set hechizosDe(string nombre, EscuelaDeMagia m) {
   return hechizosMago(lookupM(nombre, m ->magos));
}

/// Propósito: Dado un mago, indica la cantidad de hechizos que la escuela ha dado y él no sabe.
/// Precondición: Existe un mago con dicho nombre.
/// O(log m)
int leFaltanAprender(string nombre, EscuelaDeMagia m) {
   return sizeS(m ->hechizos) - sizeS(hechizosDe(nombre, m));   ///NOTA: el orden utilizando sizeS es O(1)
}

/// Propósito: Devuelve el mago que más hechizos sabe.
/// Precondición: La escuela no está vacía.
/// O(log m)
Mago unEgresado(EscuelaDeMagia m) {
   return maxH(m ->heap);
}

/// Propósito: Devuelve la escuela sin el mago que más sabe.
/// Precondición: La escuela no está vacía.
/// O(log m)
void quitarEgresado(EscuelaDeMagia m) {
   deleteM(nombreMago(maxH(m ->heap)), m ->magos);     //remover mago que mas sabe del map
   deleteMax(m ->heap);                               //remover mago que mas sabe del heap

}

/// Propósito: Enseña un hechizo a un mago existente, y si el hechizo no existe en la escuela es incorporado a la misma.
/// O(m . log m + log h)
void enseniar(Hechizo h, string nombre, EscuelaDeMagia m) {
    aprenderHechizo(h, lookupM(nombre, m ->magos)); ///orden en este punto: n.log n
    addS(h, m ->hechizos);
    //ACUTALIZAR HEAP
    insertH(lookupM(nombre, m ->magos), m ->heap);
}

/// Propósito: Libera toda la memoria creada por la escuela (incluye magos, pero no hechizos).
void destruirEscuela(EscuelaDeMagia m) {
   destroyS(m ->hechizos);
   destroyM(m ->magos);
   destroyH(m ->heap);

   delete m;
}


