#include <iostream>

using namespace std;

int main() {
    int startAddress, endAddress, specialAddress;
    cin >> startAddress >> endAddress >> specialAddress;

    for (int i = endAddress; i >= startAddress; i--) {
        if (i % 2 == 0 && i % 3 == 0) {
            if (i == specialAddress) {
                break;
            }
            cout << i << " ";
        }
    }

    cout << endl;
    return 0;
}
