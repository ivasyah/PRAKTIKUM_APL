#include <iostream>
#include <vector>
#include <string>

// Struktur untuk data barang
struct Barang {
    std::string nama;
    float harga;
    int stok;
};

// Fungsi untuk menambahkan barang
void tambah_barang(std::vector<Barang>& gudang_barang) {
    Barang barang;
    std::cout << "Masukkan nama barang: ";
    std::cin >> barang.nama;
    std::cout << "Masukkan harga barang: ";
    std::cin >> barang.harga;
    std::cout << "Masukkan stok barang: ";
    std::cin >> barang.stok;
    gudang_barang.push_back(barang);
    std::cout << "Barang berhasil ditambahkan ke gudang." << std::endl;
}

// Fungsi untuk menampilkan semua barang
void tampilkan_barang(const std::vector<Barang>& gudang_barang) {
    std::cout << "Daftar Barang di Gudang:" << std::endl;
    for (size_t i = 0; i < gudang_barang.size(); ++i) {
        std::cout << i + 1 << ". Nama: " << gudang_barang[i].nama << ", Harga: " << gudang_barang[i].harga << ", Stok: " << gudang_barang[i].stok << std::endl;
    }
}

// Fungsi untuk memperbarui barang
void ubah_barang(std::vector<Barang>& gudang_barang) {
    tampilkan_barang(gudang_barang);
    int indeks_barang;
    std::cout << "Pilih nomor barang yang ingin diubah: ";
    std::cin >> indeks_barang;
    if (indeks_barang > 0 && indeks_barang <= gudang_barang.size()) {
        std::cout << "Masukkan nama barang baru: ";
        std::cin >> gudang_barang[indeks_barang - 1].nama;
        std::cout << "Masukkan harga barang baru: ";
        std::cin >> gudang_barang[indeks_barang - 1].harga;
        std::cout << "Masukkan stok barang baru: ";
        std::cin >> gudang_barang[indeks_barang - 1].stok;
        std::cout << "Data barang berhasil diubah." << std::endl;
    } else {
        std::cout << "Nomor barang tidak valid." << std::endl;
    }
}

// Fungsi untuk menghapus barang
void hapus_barang(std::vector<Barang>& gudang_barang) {
    tampilkan_barang(gudang_barang);
    int indeks_barang;
    std::cout << "Pilih nomor barang yang ingin dihapus: ";
    std::cin >> indeks_barang;
    if (indeks_barang > 0 && indeks_barang <= gudang_barang.size()) {
        gudang_barang.erase(gudang_barang.begin() + indeks_barang - 1);
        std::cout << "Barang berhasil dihapus dari gudang." << std::endl;
    } else {
        std::cout << "Nomor barang tidak valid." << std::endl;
    }
}

int main() {
    std::vector<Barang> gudang_barang;

    std::string nama, nim;
    int count = 0;

    while (count < 3) {
        std::cout << "Masukkan Nama: ";
        std::getline(std::cin, nama);
        std::cout << "Masukkan NIM: ";
        std::getline(std::cin, nim);

        if (nama == "irvan tampan" && nim == "2309106070") {
            std::cout << "Login Berhasil! Selamat datang, Irvan Tampan.\n";
            break;
        } else {
            count++;
            std::cout << "Login Gagal! Silakan coba lagi.\n";
        }
    }

    if (count == 3) {
        std::cout << "Anda telah salah login sebanyak 3 kali. Program berhenti.\n";
        return 0;
    }

    std::string pilihan;
    while (true) {
        std::cout << "\nMenu Admin:" << std::endl;
        std::cout << "1. Tambah Barang" << std::endl;
        std::cout << "2. Ubah Barang" << std::endl;
        std::cout << "3. Hapus Barang" << std::endl;
        std::cout << "4. Tampilkan Barang" << std::endl;
        std::cout << "5. Logout" << std::endl;
        std::cout << "Pilih opsi (1/2/3/4/5): ";
        std::cin >> pilihan;
        if (pilihan == "1") {
            tambah_barang(gudang_barang);
        } else if (pilihan == "2") {
            ubah_barang(gudang_barang);
        } else if (pilihan == "3") {
            hapus_barang(gudang_barang);
        } else if (pilihan == "4") {
            tampilkan_barang(gudang_barang);
        } else if (pilihan == "5") {
            break;
        } else {
            std::cout << "Opsi tidak valid." << std::endl;
        }
    }

    return 0;
}