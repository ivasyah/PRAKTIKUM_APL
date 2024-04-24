#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <limits>

struct Barang {
    std::string nama;
    float harga;
    int stok;
};

bool compareByNama(const Barang &a, const Barang &b) {
    return a.nama < b.nama;
}

bool compareByHarga(const Barang &a, const Barang &b) {
    return a.harga < b.harga;
}

// Fungsi untuk menambah barang
void tambah_barang(std::vector<Barang>* gudang_barang) {
    Barang barang;
    while (true) {
        std::cout << "Masukkan nama barang: ";
        std::cin.ignore(); 
        std::getline(std::cin, barang.nama);

        std::cout << "Masukkan harga barang: ";
        if (!(std::cin >> barang.harga)) {
            std::cout << "Input harga tidak valid. Harap masukkan angka.\n";
            std::cin.clear(); 
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); 
            continue;
        }

        std::cout << "Masukkan stok barang: ";
        if (!(std::cin >> barang.stok)) {
            std::cout << "Input stok tidak valid. Harap masukkan angka.\n";
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); 
            continue;
        }

        gudang_barang->push_back(barang);
        std::cout << "Barang berhasil ditambahkan ke gudang." << std::endl;
        break;
    }
}

// Fungsi untuk menampilkan semua barang
void tampilkan_barang(const std::vector<Barang>* gudang_barang) {
    std::cout << "Daftar Barang di Gudang:" << std::endl;
    for (size_t i = 0; i < gudang_barang->size(); ++i) {
        std::cout << i + 1 << ". Nama: " << (*gudang_barang)[i].nama << ", Harga: " << (*gudang_barang)[i].harga << ", Stok: " << (*gudang_barang)[i].stok << std::endl;
    }
}

// Fungsi untuk memperbarui barang
void ubah_barang(std::vector<Barang>* gudang_barang) {
    tampilkan_barang(gudang_barang);
    int indeks_barang;
    std::cout << "Pilih nomor barang yang ingin diubah: ";
    std::cin >> indeks_barang;
    if (indeks_barang > 0 && indeks_barang <= gudang_barang->size()) {
        std::cout << "Masukkan nama barang baru: ";
        std::cin.ignore(); 
        std::getline(std::cin, (*gudang_barang)[indeks_barang - 1].nama);
        std::cout << "Masukkan harga barang baru: ";
        std::cin >> (*gudang_barang)[indeks_barang - 1].harga;
        std::cout << "Masukkan stok barang baru: ";
        std::cin >> (*gudang_barang)[indeks_barang - 1].stok;
        std::cout << "Data barang berhasil diubah." << std::endl;
    } else {
        std::cout << "Nomor barang tidak valid." << std::endl;
    }
}

// Fungsi untuk menghapus barang
void hapus_barang(std::vector<Barang>* gudang_barang) {
    tampilkan_barang(gudang_barang);
    int indeks_barang;
    std::cout << "Pilih nomor barang yang ingin dihapus: ";
    std::cin >> indeks_barang;
    if (indeks_barang > 0 && indeks_barang <= gudang_barang->size()) {
        gudang_barang->erase(gudang_barang->begin() + indeks_barang - 1);
        std::cout << "Barang berhasil dihapus dari gudang." << std::endl;
    } else {
        std::cout << "Nomor barang tidak valid." << std::endl;
    }
}

// Fungsi untuk menghitung total harga barang
float total_harga(const std::vector<Barang>* gudang_barang, int indeks = 0) {
    float total = 0;
    if (indeks < gudang_barang->size()) {
        total += (*gudang_barang)[indeks].harga;
        total += total_harga(gudang_barang, indeks + 1);
    }
    return total;
}

// Fungsi untuk pencarian biner pada kumpulan data yang terurut secara ascending berdasarkan nama
int binary_search_by_name(const std::vector<Barang>& gudang_barang, const std::string& target) {
    int left = 0;
    int right = gudang_barang.size() - 1;

    while (left <= right) {
        int mid = left + (right - left) / 2;

        if (gudang_barang[mid].nama == target) {
            return mid;
        } else if (gudang_barang[mid].nama < target) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }

    return -1; // Jika tidak ditemukan
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
        std::cout << "5. Menghitung Total Harga Barang" << std::endl;
        std::cout << "6. Sorting Barang (Nama - Ascending, Harga - Ascending)" << std::endl;
        std::cout << "7. Cari Barang (Berdasarkan Nama)" << std::endl;
        std::cout << "8. Logout" << std::endl;
        std::cout << "Pilih opsi (1/2/3/4/5/6/7/8): ";
        std::cin >> pilihan;
        if (pilihan == "1") {
            tambah_barang(&gudang_barang);
        } else if (pilihan == "2") {
            ubah_barang(&gudang_barang);
        } else if (pilihan == "3") {
            hapus_barang(&gudang_barang);
        } else if (pilihan == "4") {
            tampilkan_barang(&gudang_barang);       
        } else if (pilihan == "5") {
            float total_harga_barang = total_harga(&gudang_barang);
            std::cout << "Total harga barang di gudang: " << total_harga_barang << std::endl;
        } else if (pilihan == "6") {
            // Sorting berdasarkan nama secara ascending
            std::sort(gudang_barang.begin(), gudang_barang.end(), compareByNama);
            std::cout << "Daftar Barang di Gudang setelah sorting berdasarkan nama secara ascending:" << std::endl;
            tampilkan_barang(&gudang_barang);

            // Sorting berdasarkan harga secara ascending
            std::sort(gudang_barang.begin(), gudang_barang.end(), compareByHarga);
            std::cout << "\nDaftar Barang di Gudang setelah sorting berdasarkan harga secara ascending:" << std::endl;
            tampilkan_barang(&gudang_barang);
        } else if (pilihan == "7") {
            std::string nama_barang;
            std::cout << "Masukkan nama barang yang ingin dicari: ";
            std::cin.ignore();
            std::getline(std::cin, nama_barang);

            std::sort(gudang_barang.begin(), gudang_barang.end(), compareByNama);
            int index = binary_search_by_name(gudang_barang, nama_barang);

            if (index != -1) {
                std::cout << "Barang ditemukan pada indeks " << index + 1 << " di gudang." << std::endl;
            } else {
                std::cout << "Barang tidak ditemukan di gudang." << std::endl;
            }
        } else if (pilihan == "8") {
            break;
        } else {
            std::cout << "Opsi tidak valid." << std::endl;
        }
    }
}
