#include <iostream>

using namespace std;

void displayMenu() {
    cout << "\n--- KALKULATOR SEDERHANA ---" << endl;
    cout << "1. Penjumlahan" << endl;
    cout << "2. Pengurangan" << endl;
    cout << "3. Perkalian" << endl;
    cout << "4. Pembagian" << endl;
    cout << "5. Keluar" << endl;
    cout << "Pilih operasi (1-5): ";
}

int main() {
    int choice;
    double num1, num2, result;

    while (true) {
        displayMenu();
        cin >> choice;

        if (choice == 5) {
            cout << "Terima kasih telah menggunakan kalkulator!" << endl;
            break;
        }

        cout << "Masukkan angka pertama: ";
        cin >> num1;
        cout << "Masukkan angka kedua: ";
        cin >> num2;

        switch (choice) {
            case 1:
                result = num1 + num2;
                cout << "Hasil penjumlahan: " << result << endl;
                break;
            case 2:
                result = num1 - num2;
                cout << "Hasil pengurangan: " << result << endl;
                break;
            case 3:
                result = num1 * num2;
                cout << "Hasil perkalian: " << result << endl;
                break;
            case 4:
                if (num2 != 0) {
                    result = num1 / num2;
                    cout << "Hasil pembagian: " << result << endl;
                } else {
                    cout << "Kesalahan: Pembagian dengan nol tidak diperbolehkan." << endl;
                }
                break;
            default:
                cout << "Pilihan tidak valid. Silakan coba lagi." << endl;
        }
    }

    return 0;
}
