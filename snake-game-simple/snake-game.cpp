#include <iostream>  // Input/output dasar
#include <fstream>   // Untuk operasi file (high score)
#include <ctime>     // Untuk srand()
#include <unistd.h>  // Untuk usleep() dan fungsi input khusus Mac/Linux
#include <termios.h> // Untuk konfigurasi terminal input
#include <fcntl.h>   // Untuk input non-blocking
#include <algorithm> // Untuk std::max

// Fungsi kbhit() dan getch() untuk Mac/Linux (pengganti Windows) Karena saya menggunakan macbook 2017
#ifndef _WIN32
int kbhit() {
    struct termios oldt, newt;
    int ch;
    int oldf;
    tcgetattr(STDIN_FILENO, &oldt); newt = oldt;
    newt.c_lflag &= ~(ICANON | ECHO);
    tcsetattr(STDIN_FILENO, TCSANOW, &newt);
    oldf = fcntl(STDIN_FILENO, F_GETFL, 0);
    fcntl(STDIN_FILENO, F_SETFL, oldf | O_NONBLOCK);
    ch = getchar();
    tcsetattr(STDIN_FILENO, TCSANOW, &oldt);
    fcntl(STDIN_FILENO, F_SETFL, oldf);
    if (ch != EOF) { ungetc(ch, stdin); return 1; }
    return 0;
}
int getch() {
    struct termios oldt, newt;
    int ch;
    tcgetattr(STDIN_FILENO, &oldt); newt = oldt;
    newt.c_lflag &= ~(ICANON | ECHO);
    tcsetattr(STDIN_FILENO, TCSANOW, &newt);
    ch = getchar();
    tcsetattr(STDIN_FILENO, TCSANOW, &oldt);
    return ch;
}
#define _kbhit kbhit
#define _getch getch
#endif

using namespace std;

// --- Variabel Global ---
bool gameover;
const int width = 20;
const int height = 17;
int x, y, fruitX, fruitY, score;
int tailX[100], tailY[100]; // Koordinat ekor ular
int nTail; // Panjang ekor
enum eDirecton {STOP = 0, LEFT, RIGHT, UP, DOWN}; // Kontrol arah
eDirecton dir;

// --- Fitur Tambahan ---
int currentLevel;
int gameSpeedDelay; // Penundaan kecepatan (ms)
const int INITIAL_SPEED_DELAY = 150;
const int SPEED_DECREMENT_PER_LEVEL = 20;
const int SCORE_FOR_NEXT_LEVEL = 50;

// --- Prototipe Fungsi ---
void Setup();
void Draw();
void Input();
void Logic();
void SaveHighScore(int currentScore);
int LoadHighScore();

// --- Kode Warna ANSI untuk Terminal (Mac/Linux) ---
#define RESET_COLOR "\033[0m"
#define GREEN_COLOR "\033[32m"
#define YELLOW_COLOR "\033[33m"
#define RED_COLOR "\033[31m"
#define WHITE_COLOR "\033[37m"

// --- Fungsi Setup ---
void Setup() {
    gameover = false;
    dir = STOP;
    x = width / 2;
    y = height / 2;
    srand(static_cast<unsigned int>(time(0))); // Inisialisasi random
    fruitX = rand() % width;
    fruitY = rand() % height;
    score = 0;
    nTail = 0;
    currentLevel = 1;
    gameSpeedDelay = INITIAL_SPEED_DELAY;

    system("clear"); // Bersihkan layar
    cout << "Selamat datang di Game Ular!" << endl;
    cout << "High Score: " << LoadHighScore() << endl;
    cout << "Tekan tombol apa saja untuk mulai..." << endl;
    _getch();
}

// --- Fungsi Draw ---
void Draw() {
    system("clear"); // Bersihkan layar

    // Tembok atas
    cout << WHITE_COLOR;
    for(int i = 0; i < width + 2; i++) cout << "#";
    cout << endl;

    // Area game
    for (int i = 0; i < height ; i++) {
        for (int j = 0; j < width; j++) {
            if (j == 0) cout << "#"; // Tembok kiri

            if (i == y && j == x) { // Kepala ular
                cout << GREEN_COLOR << "@" << RESET_COLOR;
            } else if (i == fruitY && j == fruitX ) { // Buah
                cout << RED_COLOR << "%" << RESET_COLOR;
            } else { // Ekor ular atau ruang kosong
                bool printTail = false;
                for (int k = 0; k < nTail ; k++) {
                    if (tailX[k] == j && tailY[k] == i) {
                        cout << YELLOW_COLOR << "*" << RESET_COLOR;
                        printTail = true;
                    }
                }
                if (!printTail) cout << " ";
            }
            if (j == width - 1) cout << "#"; // Tembok kanan
        }
        cout << endl;
    }

    // Tembok bawah
    cout << WHITE_COLOR;
    for (int i = 0; i < width + 2; i++) cout << "#";
    cout << endl << RESET_COLOR;

    // Tampilkan Skor & Level
    cout << "Skor: " << score << " | Level: " << currentLevel << endl;
}

// --- Fungsi Input ---
void Input () {
    if (_kbhit()) {
        switch (_getch()) {
            case 'a': if (dir != RIGHT) dir = LEFT; break;
            case 'd': if (dir != LEFT) dir = RIGHT; break;
            case 'w': if (dir != DOWN) dir = UP; break;
            case 's': if (dir != UP) dir = DOWN; break;
            case 'x': gameover = true; break;
        }
    }
}

// --- Fungsi Logic ---
void Logic() {
    // Update posisi ekor
    int prevX = tailX[0], prevY = tailY[0];
    tailX[0] = x; tailY[0] = y;
    for(int i = 1; i < nTail ; i++) {
        int prev2X = tailX[i], prev2Y = tailY[i];
        tailX[i] = prevX; tailY[i] = prevY;
        prevX = prev2X; prevY = prev2Y;
    }

    // Gerakkan kepala ular
    switch (dir) {
        case LEFT: x--; break;
        case RIGHT: x++; break;
        case UP: y--; break;
        case DOWN: y++; break;
        default: break;
    }

    // Game Over: nabrak tembok atau diri sendiri
    if (x < 0 || x >= width || y < 0 || y >= height) gameover = true;
    for (int i =0; i< nTail ;i++)
        if (tailX[i] == x && tailY[i] == y) gameover = true;

    // Kalo makan buah
    if (x == fruitX && y == fruitY) {
        score += 10;
        fruitX = rand() % width; fruitY = rand() % height;
        nTail ++; // Panjangkan ekor

        // Naik level & percepat
        if (score > 0 && score % SCORE_FOR_NEXT_LEVEL == 0) {
            currentLevel++;
            gameSpeedDelay = std::max(10, gameSpeedDelay - SPEED_DECREMENT_PER_LEVEL);
        }
    }
}

// --- Fungsi High Score ---
void SaveHighScore(int currentScore) {
    int oldHighScore = LoadHighScore();
    if (currentScore > oldHighScore) {
        ofstream outFile("highscore.txt");
        if (outFile.is_open()) {
            outFile << currentScore;
            outFile.close();
            cout << "High Score Baru: " << currentScore << "!" << endl;
        } else {
            cerr << "Error: Gagal membuka highscore.txt." << endl;
        }
    }
}

int LoadHighScore() {
    int highScore = 0;
    ifstream inFile("highscore.txt");
    if (inFile.is_open()) {
        inFile >> highScore;
        inFile.close();
    }
    return highScore;
}

// --- Main Game Loop ---
int main() {
    Setup();

    while (!gameover) {
        Draw();
        Input();
        Logic();
        usleep(gameSpeedDelay * 1000); // Kontrol kecepatan (mikrodetik)
    }

    // Layar Game Over
    system("clear");
    cout << "GAME OVER!" << endl;
    cout << "Skor Akhir: " << score << endl;
    SaveHighScore(score);
    cout << "Tekan tombol apa saja untuk keluar..." << endl;
    _getch();

    return 0;
}
