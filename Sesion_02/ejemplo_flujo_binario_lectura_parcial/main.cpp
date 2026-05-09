#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

bool leerPrimerosNBytes(const string& nombre, int n, vector<char>& buffer) {
    ifstream f(nombre, ios::binary);
    if (!f) return false;
    buffer.resize(n);
    f.read(buffer.data(), n);
    if (f.gcount() < n) {
        buffer.resize(f.gcount());
        return false;
    }
    return true;
}

void crearArchivoBinarioEjemplo() {
    ofstream f("ejemplo.bin", ios::binary);
    if (f) {
        // Escribe 20 bytes: números 0..19 como caracteres
        for (int i = 0; i < 20; ++i) {
            char c = static_cast<char>(i);
            f.write(&c, 1);
        }
        f.close();
        cout << "[Info] Se creo ejemplo.bin con 20 bytes (0..19).\n";
    }
}

int main() {
    // Crear archivo binario de prueba
    crearArchivoBinarioEjemplo();

    // Probar la función original
    vector<char> buffer;
    bool exito = leerPrimerosNBytes("ejemplo.bin", 10, buffer); // se leen 10 bytes
    if (exito) {
        cout << "Se leyeron " << buffer.size() << " bytes correctamente.\n";
        cout << "Contenido (valores numericos): ";
        for (unsigned char c : buffer)
            cout << static_cast<int>(c) << " ";
        cout << endl;
    } else {
        cout << "No se pudo leer la cantidad solicitada. Se leyeron " << buffer.size() << " bytes.\n";
        // En este caso también mostramos lo que se alcanzó a leer
        cout << "Contenido parcial: ";
        for (unsigned char c : buffer)
            cout << static_cast<int>(c) << " ";
        cout << endl;
    }
    return 0;
}