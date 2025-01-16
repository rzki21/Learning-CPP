
#include <iostream>
#include <vector>
#include <string>

using namespace std;

// Class
class Buku {
public:
    
    string judul;
    string pengarang;
    int tahunTerbit;

    Buku(string judul, string pengarang, int tahunTerbit) {
        this->judul = judul;
        this->pengarang = pengarang;
        this->tahunTerbit = tahunTerbit;
    }

    void tampilkanBuku() const {
        cout << "Judul: " << judul << endl;
        cout << "Pengarang: " << pengarang << endl;
        cout << "Tahun Terbit: " << tahunTerbit << endl;
    }
};

// Untuk mengelola koleksi buku
class Perpustakaan {
private:
    vector<Buku> koleksiBuku;

public:
    // Tambah Buku
    void tambahBuku(const Buku &buku) {
        koleksiBuku.push_back(buku);
    }

    // Menampilkan 
    void tampilkanSemuaBuku() const {
        if (koleksiBuku.empty()) {
            cout << "Tidak ada buku di perpustakaan." << endl;
            return;
        }

        cout << "Daftar Buku di Perpustakaan:" << endl;
        for (const auto &buku : koleksiBuku) {
            buku.tampilkanBuku();
            cout << "----------------------------" << endl;
        }
    }
};

// First Func
int main() {
    
    Perpustakaan perpustakaan;

    Buku buku1("Belajar C++", "Muhammad Rizki", 2021);
    Buku buku2("Dasar OOP", "JoeSanny", 2020);
    Buku buku3("Pemrograman Lanjut", "Jane Smith", 2022);

    perpustakaan.tambahBuku(buku1);
    perpustakaan.tambahBuku(buku2);
    perpustakaan.tambahBuku(buku3);

    perpustakaan.tampilkanSemuaBuku();

    return 0;
}
