#include <iostream>
#include <cstdlib>
#include <vector>
#include "../hechizo/hechizo.h"
#include "../mago/mago.h"
#include "../set/set.h"
#include "../map/map.h"
#include "../maxheap/maxheap.h"
#include "escuela_magia.h"
#include "../common/Common.h"

using namespace std;

/// Proposito: Retorna todos los hechizos aprendidos por los magos.
/// Eficiencia: ?
Set hechizosAprendidos(EscuelaDeMagia m) {
   return hechizosMago(unEgresado(m));
}

/// Proposito: Indica si existe un mago que sabe todos los hechizos enseñados por la escuela.
/// Eficiencia: ?
bool hayUnExperto(EscuelaDeMagia m) {
   return leFaltanAprender(nombreMago(unEgresado(m)), m) == 0;
}

/// Proposito: Devuelve una maxheap con los magos que saben todos los hechizos dados por la escuela, quitándolos de la escuela.
/// Eficiencia: ?
MaxHeap egresarExpertos(EscuelaDeMagia m) {
    if (hayUnExperto(m)){



    }


}

int main()
{
    /// Escribir algunas pruebas para las funciones de la interfaz
    /// de escuela de magia, y también las de usuario.
    COMPLETAR(main);
    return 0;
}
