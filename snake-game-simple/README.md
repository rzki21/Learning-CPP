#Snake Game - C++ (ncurses)

Ini adalah versi modifikasi dari game Snake klasik, originial code nya bisa di akses di sini https://www.instructables.com/C-Snake-Game-Simple/. 
Di sini saya menambahkan beberapa fitur game yang sebelumnya belum ada di code originalnya.

## Fitur Game

- Level & Kecepatan Meningkat**  
  Setiap kali main, jika skor mencapai 50, level akan naik dan kecepatan si ular akan bertambah.

- Bisa Menyimpan High Score**  
  Hasil score akan di simpan di file `highscore.txt`, secara otomatis berapapun hasil score nya.

- **Game Over**  
  Game bakal berakhir jika ular nabrak tembok atau tubuhnya sendiri.

-  **Warna**  
  - Kepala ular berwarna hijau.
  - Ekor ular berwarna kuning.
  - Buah berwarna merah.
  - NOTE: Dari kode originalnya belum ada warna jadi saya tambahin aja sekalian belajar gimana add warna di CPP 

## Cara Compile & Jalankan

### 1. Install ncurses
Pastikan ncurses terinstal di sistem kamu
### 2. Compile
g++ -o snake game.cpp -lncurses
### 3. Setelah Melakukan Langkah Di atas akan muncul file
file `snake ` bisa kalian jalankan dengan command ./snake
###SELAMAT BERMAIN!








Thanks to https://www.instructables.com/member/Circuitalist/

