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

    MaxHeap temp = emptyH();

    while (hayUnExperto(m)){
        insertH(unEgresado(m), temp);
        quitarEgresado(m);

    }

    return temp;
}

/*OTROS*/

void lanzarExcepcion(){
    throw "test fallo";
}


/*TESTS*/

void testEscuelaVacia(){

    ///Funciones testeadas: fundarEscuela(); estaVacia(EscuelaDeMagiaSt* m); destruirEscuela(EscuelaDeMagiaSt* m)

    EscuelaDeMagia edm = fundarEscuela();
    cout << "test escuela vacia: ";

    if (estaVacia(edm)){
        cout << "OK" << endl;
    }
    else {
        lanzarExcepcion();
    }

    destruirEscuela(edm);
}

void testRegistrarMago(){

    ///Funciones testeadas: registrar(String s, EscuelaDeMagiaSt* m).

    EscuelaDeMagia edm = fundarEscuela();
    cout << "test escuela con magos: ";

    //excercice
    registrar("Pepe", edm);     //nombres 100% ingleses
    registrar ("Carlos", edm);

    if (!estaVacia(edm)){
        cout << "OK" << endl;
    }else{
        lanzarExcepcion();
    }

    destruirEscuela(edm);
}

void testVectores(){

    ///Funciones testeadas: magos(EscuelaDeMagiaSt* m).

    EscuelaDeMagia edm = fundarEscuela();
    registrar("Pepe", edm);

    cout << "test vectores: ";

    if (magos(edm).at(0) == "Pepe"){
        cout << "OK" << endl;
    }else{
        lanzarExcepcion();
    }

    destruirEscuela(edm);
}

void testAprenderHechizos(){

    /// Funciones testeadas: enseniar(Hechizo h, Set h); hechizosDe(String s, EscuelaDeMagiaSt* m).

    //setup
    EscuelaDeMagia edm = fundarEscuela();
    Hechizo h = crearHechizo("Patronus", 200);
    registrar("Pepe", edm);
    //excercice
    enseniar(h, "Pepe", edm);

    cout << "test set hechizos: ";

    if (belongsS(h, hechizosDe("Pepe", edm))){
        cout << "OK" << endl;
    }
    else{
        lanzarExcepcion();
    }

    destruirEscuela(edm);

}

void testUnEgresado(){

    EscuelaDeMagia edm = fundarEscuela();

    registrar("Pepe", edm);
    registrar("Pedro", edm);

    enseniar(crearHechizo("Patronus", 200), "Pepe", edm);
    enseniar(crearHechizo("Lumos", 50), "Pepe", edm);
    enseniar(crearHechizo("Accio", 25), "Pedro", edm);

    cout << "test un egresado: ";

    if (nombreMago(unEgresado(edm)) == "Pepe"){

        cout << "OK" << endl;
    }
    else{
        lanzarExcepcion();
    }

    destruirEscuela(edm);

}


void bateriaTests(){

    testEscuelaVacia();
    testRegistrarMago();
    //testVectores();
    //testAprenderHechizos();
    //testUnEgresado();

}


int main()
{
    /// Escribir algunas pruebas para las funciones de la interfaz
    /// de escuela de magia, y también las de usuario.

    bateriaTests();

}
