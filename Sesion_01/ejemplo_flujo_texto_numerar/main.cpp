#include <iostream>
#include <fstream>
#include <string>
using namespace std;


// Función para crear un archivo datos.txt de ejemplo si no existe
void crearArchivoDatos() {
    ifstream prueba("datos.txt");
    if (prueba) {
        prueba.close();
        return; // ya existe
    }
    ofstream crear("datos.txt");
    if (crear) {
        crear << "Primera línea de ejemplo.\n";
        crear << "Segunda línea de ejemplo.\n";
        crear << "Tercera línea de ejemplo.\n";
        crear.close();
        cout << "[Info] Se creo datos.txt con lineas de ejemplo.\n";
    }
}

int main() {
    // Asegurar que el archivo fuente existe
    crearArchivoDatos();

    ofstream salida("numerado.txt");
    ifstream entrada("datos.txt");
    if (!entrada) {
        cout << "No se pudo abrir datos.txt\n";
        return 1;
    }
    string linea;
    int n = 1;
    while (getline(entrada, linea)) {
        salida << n++ << ". " << linea << endl;
    }
    entrada.close();
    salida.close();
    cout << "Archivo numerado.txt generado.\n";
    return 0;
}