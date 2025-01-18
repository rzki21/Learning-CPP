#include <iostream>
#include <vector>
#include <string>
using namespace std;

// Struktur data teman-teman
struct Siswa {
    string nama;
    int jumlahTunggakan;
};

// Fungsi untuk menambahkan data siswa
void tambahSiswa(vector<Siswa> &daftarSiswa) {
    Siswa siswaBaru;
    cout << "Masukkan nama siswa: ";
    cin.ignore(); // Membersihkan buffer
    getline(cin, siswaBaru.nama);
    cout << "Masukkan jumlah tunggakan (Duit Rupiah Only): ";
    cin >> siswaBaru.jumlahTunggakan;
    daftarSiswa.push_back(siswaBaru);
    cout << "Data berhasil ditambahkan.\n";
}

// Fungsi untuk menampilkan semua data siswa
void tampilkanSiswa(const vector<Siswa> &daftarSiswa) {
    if (daftarSiswa.empty()) {
        cout << "Data siswa belum ada.\n";
        return;
    }
    cout << "Daftar siswa yang belum membayar kas kelas:\n";
    cout << "------------------------------------------\n";
    for (size_t i = 0; i < daftarSiswa.size(); i++) {
        cout << i + 1 << ". Nama: " << daftarSiswa[i].nama
             << ", Tunggakan: Rp" << daftarSiswa[i].jumlahTunggakan << endl;
    }
}

// Fungsi untuk mengupdate data siswa
void updateSiswa(vector<Siswa> &daftarSiswa) {
    if (daftarSiswa.empty()) {
        cout << "Tidak ada data siswa untuk diperbarui.\n";
        return;
    }
    int index;
    cout << "Masukkan nomor siswa yang ingin diupdate: ";
    cin >> index;
    if (index < 1 || index > daftarSiswa.size()) {
        cout << "Nomor siswa tidak valid.\n";
        return;
    }
    Siswa &siswa = daftarSiswa[index - 1];
    cout << "Masukkan nama baru untuk siswa: ";
    cin.ignore(); // Membersihkan buffer
    getline(cin, siswa.nama);
    cout << "Masukkan jumlah tunggakan baru (dalam rupiah): ";
    cin >> siswa.jumlahTunggakan;
    cout << "Data siswa berhasil diperbarui.\n";
}

// Fungsi untuk menghapus data siswa
void hapusSiswa(vector<Siswa> &daftarSiswa) {
    if (daftarSiswa.empty()) {
        cout << "Tidak ada data siswa untuk dihapus.\n";
        return;
    }
    int index;
    cout << "Masukkan nomor siswa yang ingin dihapus: ";
    cin >> index;
    if (index < 1 || index > daftarSiswa.size()) {
        cout << "Nomor siswa tidak valid.\n";
        return;
    }
    daftarSiswa.erase(daftarSiswa.begin() + index - 1);
    cout << "Data siswa berhasil dihapus.\n";
}

int main() {
    vector<Siswa> daftarSiswa;
    int pilihan;

    while (true) {
        cout << "\n=== Pengelolaan Kas Kelas XI TKJ 1 ===\n";
        cout << "1. Tambah Siswa\n";
        cout << "2. Tampilkan Data Siswa\n";
        cout << "3. Update Data Siswa\n";
        cout << "4. Hapus Data Siswa\n";
        cout << "5. Keluar\n";
        cout << "Pilih opsi: ";
        cin >> pilihan;

        switch (pilihan) {
            case 1:
                tambahSiswa(daftarSiswa);
                break;
            case 2:
                tampilkanSiswa(daftarSiswa);
                break;
            case 3:
                updateSiswa(daftarSiswa);
                break;
            case 4:
                hapusSiswa(daftarSiswa);
                break;
            case 5:
                cout << "Terima kasih telah menggunakan sistem ini.\n";
                return 0;
            default:
                cout << "Pilihan tidak ada. Silakan coba lagi gaes!\n";
        }
    }
}
