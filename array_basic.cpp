#include <iostream>
#include <string>
using namespace std;
//jajal gae string
int main() {
    string kegiatan[10];
    int jumlahKegiatan = 0;
    int pilihan;

    while (true) {
        cout << "Halo Selamat Datang, silahkan pilih menu berikut ini\n";
        cout << "1. Input Kegiatan\n";
        cout << "2. Hapus Kegiatan\n";
        cout << "3. Lihat Kegiatan\n";
        cout << "Masukkan nomor menu ?: ";
        cin >> pilihan;

        // cek kondisi jika user salah input
        if (pilihan < 1 || pilihan > 3) {
            cout << "Pilihan tidak valid. Coba lagi! \n";
            continue;
        }

        // Input Kegiatan
        if (pilihan == 1) {
            if (jumlahKegiatan < 10) {
                cout << "Masukkan kegiatanmu: ";
                string kegiatanBaru;
                cin >> kegiatanBaru; // Membaca satu kata
                kegiatan[jumlahKegiatan] = kegiatanBaru;
                cout << kegiatanBaru << " berhasil ditambahkan ke list\n";
                jumlahKegiatan++;
            } else {
                cout << "Kegiatan mencapai batas maksimum!\n";
            }
        }
        // Hapus Kegiatan
        else if (pilihan == 2) {
            cout << "Kegiatanmu hari ini:\n";
            for (int i = 0; i < jumlahKegiatan; i++) {
                cout << i + 1 << ". " << kegiatan[i] << endl;
            }
            if (jumlahKegiatan > 0) {
                cout << "Hapus kegiatan nomor ? ";
                int hapus;
                cin >> hapus;
                if (hapus > 0 && hapus <= jumlahKegiatan) {
                    cout << kegiatan[hapus - 1] << " berhasil dihapus\n";
                    for (int i = hapus - 1; i < jumlahKegiatan - 1; i++) {
                        kegiatan[i] = kegiatan[i + 1];
                    }
                    jumlahKegiatan--;
                } else {
                    cout << "Nomor kegiatan tidak valid!\n";
                }
            } else {
                cout << "Tidak ada kegiatan untuk dihapus.\n";
            }
        }
        // Lihat Kegiatan
        else if (pilihan == 3) {
            cout << "Kegiatanmu hari ini adalah:\n";
            for (int i = 0; i < jumlahKegiatan; i++) {
                cout << i + 1 << ". " << kegiatan[i] << endl;
            }
            if (jumlahKegiatan == 0) {
                cout << "Tidak ada kegiatan yang dimasukkan.\n";
            }
        }
    }

    return 0;
}
