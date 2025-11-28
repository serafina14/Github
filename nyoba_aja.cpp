#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

int main() {
    string username, buahDicari, pelanggan, beliBuah;
    int pw, pilihMenu, tmbhBuah, total, ditemukan = 0, jumlahBuah = 10;
    char tambahan, pilihan;
    float berat;

    // Daftar buah dan harga
    string buah[20] = {"Apel", "Jeruk", "Anggur", "Durian", "Alpukat", "Nanas", "Nangka", "Melon", "Semangka", "Manggis"};
    int harga[20] = {35000, 28000, 62000, 83000, 35000, 27000, 25000, 28000, 55000, 73000};

    // ---------------- LOGIN ----------------
    do {
        cout << "====== LOGIN SISTEM TOKO BUAH MAKMUR ======" << endl;
        cout << "Username: "; cin >> username;
        cout << "Password: "; cin >> pw;

        system("cls"); // hapus layar (khusus Windows)

        if (username != "tokobuah" || pw != 107) {
            cout << "Login gagal! Silakan coba lagi." << endl << endl;
        }

    } while (username != "tokobuah" || pw != 107);

    // ---------------- MENU UTAMA ----------------
    do {
        cout << "==============================================" << endl;
        cout << "Selamat Datang di Sistem Manajemen Toko Buah" << endl;
        cout << "==============================================" << endl;
        cout << "1. List buah" << endl;
        cout << "2. Tambah buah" << endl;
        cout << "3. Cari buah" << endl;
        cout << "4. Jual buah" << endl;
        cout << "5. Keluar" << endl;
        cout << "Pilih menu: ";
        cin >> pilihMenu;

        system("cls");

        // -------- MENU 1: LIST BUAH --------
        if (pilihMenu == 1) {
            cout << "=========== DAFTAR BUAH ===========" << endl;
            cout << "No\tNama Buah\tHarga/kg" << endl;
            cout << "-----------------------------------" << endl;

            for (int i = 0; i < jumlahBuah; i++) {
                cout << i + 1 << "\t" << buah[i] << "\t\tRp." << harga[i] << endl;
            }
            cout << "===================================" << endl;
        }

        // -------- MENU 2: TAMBAH BUAH --------
        else if (pilihMenu == 2) {
            cout << "Mau menambahkan berapa buah?: ";
            cin >> tmbhBuah;

            for (int i = 0; i < tmbhBuah; i++) {
                if (jumlahBuah < 20) {
                    cout << "Nama buah ke-" << jumlahBuah + 1 << ": ";
                    cin >> buah[jumlahBuah];
                    cout << "Harga/kg untuk " << buah[jumlahBuah] << ": Rp.";
                    cin >> harga[jumlahBuah];
                    jumlahBuah++;
                } else {
                    cout << "Kapasitas penuh, tidak bisa menambah lagi." << endl;
                    break;
                }
            }
            j
            cout << "Buah berhasil ditambahkan!" << endl;
        }

        // -------- MENU 3: CARI BUAH --------
        else if (pilihMenu == 3) {
            cout << "Masukkan nama buah yang dicari: ";
            cin >> buahDicari;

            ditemukan = 0; // reset status

            for (int i = 0; i < jumlahBuah; i++) {
                if (buah[i] == buahDicari) {
                    cout << "Buah ditemukan!" << endl;
                    cout << "Nama: " << buah[i] << endl;
                    cout << "Harga/kg: Rp." << harga[i] << endl;
                    ditemukan = 1;
                    break; // sudah ketemu, keluar dari loop
                }
            }

            // ❌ kamu dulu tulis `if (ditemukan = 0)` → itu salah karena pakai tanda `=`
            // ✅ yang benar: `if (ditemukan == 0)`
            if (ditemukan == 0) {
                cout << "Buah tidak ditemukan!" << endl;
            }
        }

        // -------- MENU 4: JUAL BUAH --------
        else if (pilihMenu == 4) {
            cin.ignore(); // buang newline sisa input sebelumnya
            cout << "Masukkan nama lengkap pembeli: ";
            getline(cin, pelanggan);

            total = 0; // total harga belanja

            do {
                cout << "Nama buah yang dibeli: ";
                cin >> beliBuah;

                int ketemu = -1;
                for (int i = 0; i < jumlahBuah; i++) {
                    if (buah[i] == beliBuah) {
                        ketemu = i;
                        break;
                    }
                }

                if (ketemu == -1) {
                    cout << "Buah tidak ditemukan!" << endl;
                } else {
                    cout << "Jumlah (Kg): ";
                    cin >> berat;
                    total += harga[ketemu] * berat;
                }

                cout << "Tambah beli buah lain? (y/n): ";
                cin >> tambahan;

            } while (tambahan == 'y');

            cout << endl;
            cout << "-----------------------------------" << endl;
            cout << "Nama pelanggan : " << pelanggan << endl;
            cout << "Total belanja  : Rp." << total << endl;
            cout << "-----------------------------------" << endl;
        }

        // -------- MENU 5: KELUAR --------
        else if (pilihMenu == 5) {
            cout << "Terima kasih telah menggunakan sistem toko buah!" << endl;
            break;
        }

        // -------- MENU TIDAK VALID --------
        else {
            cout << "Menu tidak valid!" << endl;
        }

        cout << endl << "Kembali ke menu utama? (y/n): ";
        cin >> pilihan;
        system("cls");


    } while (pilihan == 'y');

    return 0;
}
