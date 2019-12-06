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
/// Eficiencia: O (m.(h².log m))
Set hechizosAprendidos(EscuelaDeMagia m) {
   Set hechizos = emptyS();
   vector <string> nombreMagos = magos(m);

   for (size_t i = 0; i < nombreMagos.size(); i++){         ///orden m, m = cant magos
        hechizos = unionS(hechizosDe(nombreMagos[i], m), hechizos);    ///orden h² * O(log m), h = cantidad de hechizos, m = cantidad magos (claves en map)
   }

   return hechizos;
}


/// Proposito: Indica si existe un mago que sabe todos los hechizos enseñados por la escuela.
/// Eficiencia: O(1)
bool hayUnExperto(EscuelaDeMagia m) {
   return leFaltanAprender(nombreMago(unEgresado(m)), m) == 0;
}

/// Proposito: Devuelve una maxheap con los magos que saben todos los hechizos dados por la escuela, quitándolos de la escuela.
/// Eficiencia: O(m.(log n + log n))
MaxHeap egresarExpertos(EscuelaDeMagia m) {

    MaxHeap temp = emptyH();

    while (hayUnExperto(m)){                ///orden m, m = cant magos
        insertH(unEgresado(m), temp);       ///orden log n
        quitarEgresado(m);                  ///orden log n

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

    cout << "test escuela vacia: ";

    EscuelaDeMagia edm = fundarEscuela();

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

    cout << "test escuela con magos: ";

    EscuelaDeMagia edm = fundarEscuela();

    //excercice
    registrar("Pepe", edm);
    registrar("Eva", edm);

    if (!estaVacia(edm)){
        cout << "OK" << endl;
    }else{
        lanzarExcepcion();
    }

    destruirEscuela(edm);
}

void testVectores(){

    ///Funciones testeadas: magos(EscuelaDeMagiaSt* m).

    cout << "test vectores: ";

    EscuelaDeMagia edm = fundarEscuela();
    registrar("Pepe", edm);
    registrar("Pablo", edm);


    if (magos(edm).at(0) == "Pepe" && magos(edm).at(1) == "Pablo"){
        cout << "OK" << endl;
    }else{
        lanzarExcepcion();
    }

    destruirEscuela(edm);
}

void testAprenderHechizos(){

    /// Funciones testeadas: enseniar(Hechizo h, Set h); hechizosDe(String s, EscuelaDeMagiaSt* m);
    ///hechizosAprendidos(EscuelaDeMagiaSt* m).

    cout << "test aprender hechizos: ";

    //setup
    EscuelaDeMagia edm = fundarEscuela();
    Hechizo h = crearHechizo("Patronus", 200);
    registrar("Pepe", edm);
    //excercice
    enseniar(h, "Pepe", edm);


    if (belongsS(h, hechizosAprendidos(edm))){
    //if (belongsS(h, hechizosDe("Pepe", edm))){
        cout << "OK" << endl;
    }
    else{
        lanzarExcepcion();
    }

    destruirEscuela(edm);

}

void testUnExperto(){

    cout << "test un experto: ";

    EscuelaDeMagia edm = fundarEscuela();

    registrar("Pepe", edm);
    registrar("Pedro", edm);

    enseniar(crearHechizo("Patronus", 200), "Pepe", edm);
    enseniar(crearHechizo("Lumos", 50), "Pepe", edm);
    enseniar(crearHechizo("Accio", 25), "Pepe", edm);

    enseniar(crearHechizo("Accio", 25), "Pedro", edm);  ///linea que rompe

    if (hayUnExperto(edm)) {

        if (nombreMago(unEgresado(edm)) == "Pepe"){

            cout << "OK" << endl;
        }

    }

    else{

        lanzarExcepcion();
    }

    destruirEscuela(edm);

}

void testQuitarExpertos(){

    cout << "test egresar mago: ";

    EscuelaDeMagia edm = fundarEscuela();

    registrar("Pepe", edm);
    registrar("Pedro", edm);

    enseniar(crearHechizo("Patronus", 200), "Pepe", edm);
    enseniar(crearHechizo("Lumos", 50), "Pepe", edm);
    enseniar(crearHechizo("Accio", 25), "Pepe", edm);

    enseniar(crearHechizo("Accio", 25), "Pedro", edm);


    quitarEgresado(edm);

    if (nombreMago(unEgresado(edm)) == "Pedro"){
        cout << "OK" << endl;
    }
    else{
        lanzarExcepcion();
    }

    destruirEscuela(edm);

}

void testCantidadHechizosRestantesRespectoEscuela(){

    cout << "test cantidad de hechizos mago - escuela: ";

    EscuelaDeMagia edm = fundarEscuela();

    registrar("Pepe", edm);
    enseniar(crearHechizo("h1", 100), "Pepe", edm);
    enseniar (crearHechizo("h2", 100), "Pepe", edm);

    registrar("Pedro", edm);
    enseniar(crearHechizo("h3", 100), "Pedro", edm);


    if (leFaltanAprender("Pepe", edm) == 1 && leFaltanAprender("Pedro", edm) == 2){
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
    testVectores();
    testAprenderHechizos();
    testUnExperto();
    testQuitarExpertos();
    testCantidadHechizosRestantesRespectoEscuela();

}


int main()
{
    /// Escribir algunas pruebas para las funciones de la interfaz
    /// de escuela de magia, y también las de usuario.

    bateriaTests();

}
