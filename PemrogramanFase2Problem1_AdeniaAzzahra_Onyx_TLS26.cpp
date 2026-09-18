#include <iostream>
using namespace std;

void tampilkanEliminasi(int nomor) {
    cout << nomor << " ";
}

int ubahK(int K, int nomor) {
    if (nomor % 2 == 0) {
        K = K + 2;
    } else {
        K = K - 1;

        if (K < 2) {
            K = 2;
        }
    }

    return K;
}

int main() {
    int N, K;
    int astronaut[1000];

    cout << "=== The Last Astronaut ===" << endl;
    cout << "Masukkan jumlah astronaut: ";
    cin >> N;

    cout << "Masukkan nilai K: ";
    cin >> K;

    for (int i = 0; i < N; i++) {
        astronaut[i] = i + 1;
    }

    int jumlah = N;
    int index = 0;

    cout << "\nUrutan astronaut yang dieliminasi: ";

    while (jumlah > 1) {

        index = (index + K - 1) % jumlah;

        int tereliminasi = astronaut[index];

        tampilkanEliminasi(tereliminasi);

        K = ubahK(K, tereliminasi);

        for (int i = index; i < jumlah - 1; i++) {
            astronaut[i] = astronaut[i + 1];
        }

        jumlah--;

        if (index == jumlah) {
            index = 0;
        }
    }

    cout << "\n\nAstronaut terakhir yang bertahan: "
         << astronaut[0] << endl;

    return 0;
}
