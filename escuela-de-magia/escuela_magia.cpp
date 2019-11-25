#include "escuela_magia.h"
#include "../common/Common.h"

struct EscuelaDeMagiaSt {
   /// COMPLETAR
};

/// Prop�sito: Devuelve una escuela vac�a.
/// O(1)
EscuelaDeMagia fundarEscuela() {
   COMPLETAR(fundarEscuela);
}

/// Prop�sito: Indica si la escuela est� vac�a.
/// O(1)
bool estaVacia(EscuelaDeMagia m) {
   COMPLETAR(estaVacia);
}

/// Prop�sito: Incorpora un mago a la escuela (si ya existe no hace nada).
/// O(log m)
void registrar(string nombre, EscuelaDeMagia m) {
   COMPLETAR(registrar);
}

/// Prop�sito: Devuelve los nombres de los magos registrados en la escuela.
/// O(m)
vector<string> magos(EscuelaDeMagia m) {
   COMPLETAR(magos);
}

/// Prop�sito: Devuelve los hechizos que conoce un mago dado.
/// Precondici�n: Existe un mago con dicho nombre.
/// O(log m)
Set hechizosDe(string nombre, EscuelaDeMagia m) {
   COMPLETAR(hechizosDe);
}

/// Prop�sito: Dado un mago, indica la cantidad de hechizos que la escuela ha dado y �l no sabe.
/// Precondici�n: Existe un mago con dicho nombre.
/// O(log m)
int leFaltanAprender(string nombre, EscuelaDeMagia m) {
   COMPLETAR(leFaltanAprender);
}

/// Prop�sito: Devuelve el mago que m�s hechizos sabe.
/// Precondici�n: La escuela no est� vac�a.
/// O(log m)
Mago unEgresado(EscuelaDeMagia m) {
   COMPLETAR(unEgresado);
}

/// Prop�sito: Devuelve la escuela sin el mago que m�s sabe.
/// Precondici�n: La escuela no est� vac�a.
/// O(log m)
void quitarEgresado(EscuelaDeMagia m) {
   COMPLETAR(quitarEgresado);
}

/// Prop�sito: Ense�a un hechizo a un mago existente, y si el hechizo no existe en la escuela es incorporado a la misma.
/// O(m . log m + log h)
void enseniar(Hechizo h, string nombre, EscuelaDeMagia m) {
   COMPLETAR(enseniar);
}

/// Prop�sito: Libera toda la memoria creada por la escuela (incluye magos, pero no hechizos).
void destruirEscuela(EscuelaDeMagia m) {
   COMPLETAR(destruirEscuela);
}


