#include <iostream>
#include <fstream>
using namespace std;

// Función para crear un archivo numeros.txt de ejemplo si no existe
void crearArchivoNumeros() {
    ifstream prueba("numeros.txt");
    if (prueba) {
        prueba.close();
        return; // ya existe
    }
    ofstream crear("numeros.txt");
    if (crear) {
        crear << "10.5\n20.3\n30.1\n40.7\n50.0\n";
        crear.close();
        cout << "[Info] Se creo numeros.txt con datos de ejemplo.\n";
    }
}

int main() {
    // Asegurar que el archivo existe
    crearArchivoNumeros();
    ifstream f("numeros.txt");
    if (!f) {
        cout << "Error abriendo archivo.\n";
        return 1;
    }
    double suma = 0;
    int count = 0;
    double x;
    while (f >> x) {
        suma += x;
        count++;
    }
    if (f.eof())
        cout << "Lectura completa.\n";
    if (f.fail() && !f.eof())
        cout << "Fallo de lectura (formato?).\n";
    f.close();
    if (count > 0)
        cout << "Promedio: " << suma / count << endl;
    return 0;
}