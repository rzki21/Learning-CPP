#include <iostream>
#include <ctime>

using namespace std;

// Fungsi menghitung usia berdasarkan tanggal lahir
int hitungUsia(int hariLahir, int bulanLahir, int tahunLahir) {
    // Ambil tanggal saat ini
    time_t waktuSekarang = time(0);
    tm* waktuLokal = localtime(&waktuSekarang);

    int hariSekarang = waktuLokal->tm_mday;
    int bulanSekarang = waktuLokal->tm_mon + 1;
    int tahunSekarang = waktuLokal->tm_year + 1900;

    // Hitung usia
    int usia = tahunSekarang - tahunLahir;

    // Koreksi usia jika belum melewati hari dan bulan ulang tahun
    if (bulanSekarang < bulanLahir || (bulanSekarang == bulanLahir && hariSekarang < hariLahir)) {
        usia--;
    }

    return usia;
}

int main() {
    int hari, bulan, tahun;

    // Input data tanggal lahir pengguna
    cout << "Masukkan tanggal lahir Anda (1-31): ";
    cin >> hari;
    cout << "Masukkan bulan lahir Anda (1-12): ";
    cin >> bulan;
    cout << "Masukkan tahun lahir Anda: ";
    cin >> tahun;

   
    if (hari < 1 || hari > 31 || bulan < 1 || bulan > 12 || tahun < 1) {
        cout << "Data yang Anda masukkan tidak valid. Mohon periksa kembali.\n";
        return 1;
    }

    // Penghitungan Usia Ketika Selesai Mengisi Apa Yang Perlu Diinput
    int usia = hitungUsia(hari, bulan, tahun);
    cout << "Saat ini, usia Anda adalah " << usia << " tahun.\n";

    return 0;
}
