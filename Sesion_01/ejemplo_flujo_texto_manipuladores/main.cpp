#include <iostream>
#include <iomanip>
using namespace std;

int main() {
    double a = 3.14159, b = 2.71828;
    cout << fixed << setprecision(2);
    cout << setw(10) << "Valor A" << setw(10) << "Valor B" << endl;
    cout << setw(10) << a << setw(10) << b << endl;
    return 0;
}