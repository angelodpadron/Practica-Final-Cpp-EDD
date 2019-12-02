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
   assocM(nombre, crearMago(nombre), m ->magos);    //insercion en map
   insertH(crearMago(nombre), m ->heap);            //insercion en heap
}

/// Propósito: Devuelve los nombres de los magos registrados en la escuela.
/// O(m)
vector<string> magos(EscuelaDeMagia m) {
   domM(m ->magos);
}

/// Propósito: Devuelve los hechizos que conoce un mago dado.
/// Precondición: Existe un mago con dicho nombre.
/// O(log m)
Set hechizosDe(string nombre, EscuelaDeMagia m) {
   hechizosDe(nombre, m);
}

/// Propósito: Dado un mago, indica la cantidad de hechizos que la escuela ha dado y él no sabe.
/// Precondición: Existe un mago con dicho nombre.
/// O(log m)
int leFaltanAprender(string nombre, EscuelaDeMagia m) {
   return sizeS(m ->hechizos) - sizeS(hechizosDe(nombre, m));
}

/// Propósito: Devuelve el mago que más hechizos sabe.
/// Precondición: La escuela no está vacía.
/// O(log m)
Mago unEgresado(EscuelaDeMagia m) {
   maxH(m ->heap);
}

/// Propósito: Devuelve la escuela sin el mago que más sabe.
/// Precondición: La escuela no está vacía.
/// O(log m)
void quitarEgresado(EscuelaDeMagia m) {
   deleteM(nombreMago(maxH(m ->heap)), m ->magos);     //remover mago que mas sabe del map
   deleteMax(m ->heap);     //remover mago que mas sabe del heap

}

/// Propósito: Enseña un hechizo a un mago existente, y si el hechizo no existe en la escuela es incorporado a la misma.
/// O(m . log m + log h)
void enseniar(Hechizo h, string nombre, EscuelaDeMagia m) {
   aprenderHechizo(h, lookupM(nombre, m ->magos));
}

/// Propósito: Libera toda la memoria creada por la escuela (incluye magos, pero no hechizos).
void destruirEscuela(EscuelaDeMagia m) {
   destroyS(m ->hechizos);
   destroyM(m ->magos);
   destroyH(m ->heap);

   delete m;
}


