#include <iostream>
#include <fstream>
using namespace std;

int main() {
    int arr[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    ofstream out("datos.bin", ios::binary);
    if (!out) { cout << "Error escritura.\n"; return 1; }
    out.write(reinterpret_cast<char*>(arr), sizeof(arr));
    out.close();

    int arr2[10];
    ifstream in("datos.bin", ios::binary);
    if (!in) { cout << "Error lectura.\n"; return 1; }
    in.read(reinterpret_cast<char*>(arr2), sizeof(arr2));
    in.close();

    for (int i = 0; i < 10; i++)
        cout << arr2[i] << " ";
    cout << endl;
    return 0;
}