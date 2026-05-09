#include <iostream>
#include <fstream>
using namespace std;

struct Registro {
    int id;
    double valor;
};

int main() {
    Registro r = {100, 3.14};
    ofstream out("reg.bin", ios::binary);
    out.write(reinterpret_cast<char*>(&r), sizeof(r));
    out.close();

    Registro r2;
    ifstream in("reg.bin", ios::binary);
    in.read(reinterpret_cast<char*>(&r2), sizeof(r2));
    in.close();
    cout << "id=" << r2.id << " valor=" << r2.valor << endl;
    return 0;
}