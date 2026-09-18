#include <iostream>
using namespace std;

int panjangString(char str[]) {
    int i = 0;
    while (str[i] != '\0') {
        i++;
    }
    return i;
}

int nilaiHuruf(char c) {
    return (c - 'A') + 1;
}

char hurufDariNilai(int nilai) {
    return (char)((nilai - 1) + 'A');
}

void enkripsi(char pesan[], char hasil[]) {
    int panjang = panjangString(pesan);

    hasil[0] = pesan[0];

    for (int i = 1; i < panjang; i++) {
        int nilaiSekarang   = nilaiHuruf(pesan[i]);
        int nilaiSebelumnya = nilaiHuruf(pesan[i - 1]); 
        int nilaiBaru       = nilaiSekarang + nilaiSebelumnya;

        while (nilaiBaru > 26) {
            nilaiBaru = nilaiBaru - 26;
        }

        hasil[i] = hurufDariNilai(nilaiBaru);
    }

    hasil[panjang] = '\0';
}

int main() {
    const int MAKS = 1000;
    char pesan[MAKS];
    char hasil[MAKS];

    cout << "=== Alien-In-The-Middle ===" << endl;
    cout << "Masukkan pesan (huruf kapital, tanpa spasi): ";
    cin >> pesan;

    enkripsi(pesan, hasil);

    cout << "\nPesan asli    : " << pesan << endl;
    cout << "Pesan tersandi: " << hasil << endl;

    return 0;
}
