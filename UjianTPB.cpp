/*
 * Nama         : Jovianie, Fardan, Newten
 * NPM          : 140810240010, 140810240084, 140810240090
 * Nama Program : Ujian TPB C++ (Linked List)
 * Tanggal      : 27 Oktober 2025 
 */

#include <iostream>
#include <iomanip>
#include <string>
#include <sstream>
using namespace std;

class Waktu {
private:
    int jam, menit, detik;

public:
    Waktu() {
        jam = 0;
        menit = 0;
        detik = 0;
    }
    
    Waktu(int jam, int menit, int detik) {
        this->jam = jam;
        this->menit = menit;
        this->detik = detik;
    }

    void setJam(int jam) { this->jam = jam; }
    void setMenit(int menit) { this->menit = menit; }
    void setDetik(int detik) { this->detik = detik; }

    int getjam() { return this->jam; }
    int getmenit() { return this->menit; }
    int getDetik() { return this->detik; }

    int hitungTotalDetik() {
        return this->jam * 3600 + this->menit * 60 + this->detik;
    }
};

class MahasiswaTPB {
private:
    string nama, NPM, statusLulus;
    char hurufMutu;
    Waktu waktuMulai, waktuSelesai;
    int lamaDetikLari;

public:
    MahasiswaTPB() {
        nama = "";
        NPM = "";
        statusLulus = "";
        hurufMutu = ' ';
        lamaDetikLari = 0;
    }

    void inputData() {
        cout << "Masukkan nama: ";
        cin >> this->nama;
        cout << "Masukkan NPM: ";
        cin >> this->NPM;

        string mulaiStr, selesaiStr;
        cout << "Masukkan waktu mulai (HH:mm:ss): ";
        cin >> mulaiStr;
        cout << "Masukkan waktu selesai (HH:mm:ss): ";
        cin >> selesaiStr;

        this->waktuMulai = Waktu();
        this->waktuSelesai = Waktu();

        try {
            int jamMulai, menitMulai, detikMulai;
            int jamSelesai, menitSelesai, detikSelesai;
            
            sscanf(mulaiStr.c_str(), "%d:%d:%d", &jamMulai, &menitMulai, &detikMulai);
            sscanf(selesaiStr.c_str(), "%d:%d:%d", &jamSelesai, &menitSelesai, &detikSelesai);

            this->waktuMulai.setJam(jamMulai);
            this->waktuMulai.setMenit(menitMulai);
            this->waktuMulai.setDetik(detikMulai);

            this->waktuSelesai.setJam(jamSelesai);
            this->waktuSelesai.setMenit(menitSelesai);
            this->waktuSelesai.setDetik(detikSelesai);
        } catch (...) {
            cout << "Format waktu tidak valid" << endl;
        }
    }

    void prosesData() {
        int totalMulai = waktuMulai.hitungTotalDetik();
        int totalSelesai = waktuSelesai.hitungTotalDetik();
        lamaDetikLari = totalSelesai - totalMulai;

        if (lamaDetikLari < 450) {
            hurufMutu = 'A'; 
            statusLulus = "Lulus";
        } else if (lamaDetikLari < 750) {
            hurufMutu = 'B'; 
            statusLulus = "Lulus";
        } else if (lamaDetikLari < 1800) {
            hurufMutu = 'C'; 
            statusLulus = "Lulus";
        } else {
            hurufMutu = 'D'; 
            statusLulus = "Gagal";
        }
    }

    string getNama() { return nama; }
    string getNPM() { return NPM; }
    char getHurufMutu() { return hurufMutu; }
    string getStatusLulus() { return statusLulus; }

    string getWaktuMulaiString() {
        stringstream ss;
        ss << setfill('0') << setw(2) << waktuMulai.getjam() << ":" 
           << setw(2) << waktuMulai.getmenit() << ":" 
           << setw(2) << waktuMulai.getDetik();
        return ss.str();
    }

    string getWaktuSelesaiString() {
        stringstream ss;
        ss << setfill('0') << setw(2) << waktuSelesai.getjam() << ":" 
           << setw(2) << waktuSelesai.getmenit() << ":" 
           << setw(2) << waktuSelesai.getDetik();
        return ss.str();
    }

    string getlamaDetikLariString() {
        int jam = lamaDetikLari / 3600;
        int menit = (lamaDetikLari % 3600) / 60;
        int detik = lamaDetikLari % 60;
        stringstream ss;
        ss << setfill('0') << setw(2) << jam << ":" 
           << setw(2) << menit << ":" 
           << setw(2) << detik;
        return ss.str();
    }
};

class ElmtList {
private:
    MahasiswaTPB mhs;

public:
    ElmtList* next;

    ElmtList() {
        this->mhs = MahasiswaTPB();
        next = NULL;
    }

    void setInfo(MahasiswaTPB info) { this->mhs = info; }
    MahasiswaTPB getInfo() { return this->mhs; }
};

class LinkedList {
private:
    ElmtList* First;

public:
    LinkedList() { First = NULL; }

    ElmtList* createElmt() {
        MahasiswaTPB mhs = MahasiswaTPB();
        mhs.inputData();
        mhs.prosesData();

        ElmtList* pBaru = new ElmtList();
        pBaru->setInfo(mhs);
        pBaru->next = NULL;
        return pBaru;
    }

    void insertFirst(ElmtList* pBaru) {
        pBaru->next = First;
        First = pBaru;
    }

    void insertLast(ElmtList* pBaru) {
        if (First == NULL) {
            First = pBaru;
        } else {
            ElmtList* pBantu = First;
            while (pBantu->next != NULL) {
                pBantu = pBantu->next;
            }
            pBantu->next = pBaru;
        }
    }

    void insertAfter(ElmtList* pBaru, string key) {
        ElmtList* pCari = search(key);
        if (pCari == NULL) {
            cout << "Mahasiswa dengan NPM " << key << " tidak ditemukan." << endl;
        } else {
            pBaru->next = pCari->next;
            pCari->next = pBaru;
            cout << "Data berhasil ditambahkan setelah NPM " << key << "." << endl;
        }
    }

    void deleteFirst() {
        if (First == NULL) {
            cout << "List kosong!" << endl;
        } else {
            cout << "Data dengan NPM " << First->getInfo().getNPM() << " berhasil dihapus." << endl;
            First = First->next;
        }
    }

    void deleteLast() {
        if (First == NULL) {
            cout << "List kosong!" << endl;
        } else if (First->next == NULL) {
            cout << "Data dengan NPM " << First->getInfo().getNPM() << " berhasil dihapus." << endl;
            First = NULL;
        } else {
            ElmtList* p = First;
            while (p->next->next != NULL) {
                p = p->next;
            }
            cout << "Data dengan NPM " << p->next->getInfo().getNPM() << " berhasil dihapus." << endl;
            p->next = NULL;
        }
    }

    void deleteAfter(string key) {
        ElmtList* pCari = search(key);
        if (pCari == NULL || pCari->next == NULL) {
            cout << "Tidak ditemukan data setelah NPM " << key << "." << endl;
        } else {
            ElmtList* pHapus = pCari->next;
            pCari->next = pHapus->next;
            cout << "Data setelah NPM " << key << " berhasil dihapus (NPM: " << pHapus->getInfo().getNPM() << ")." << endl;
        }
    }

    ElmtList* search(string key) {
        ElmtList* p = First;
        while (p != NULL) {
            if (p->getInfo().getNPM() == key) {
                return p;
            }
            p = p->next;
        }
        return NULL;
    }

    void traversal() {
        if (First == NULL) {
            cout << "List kosong" << endl;
        } else {
            cout << "\n\n" << string(85, '=') << endl;
            cout << "\t\tDaftar Nilai Ujian dan Lama Ujian Lari Mahasiswa TPB" << endl;
            cout << string(85, '=') << endl;
            cout << left << setw(4) << "No" << setw(14) << "NPM" << setw(14) << "Nama" 
                 << setw(6) << "HM" << setw(10) << "Status" << setw(10) << "Mulai" 
                 << setw(12) << "Selesai" << setw(10) << "Lama" << endl;
            cout << string(85, '-') << endl;

            ElmtList* p = First;
            int i = 1;
            while (p != NULL) {
                MahasiswaTPB m = p->getInfo();
                cout << left << setw(4) << i++ << setw(14) << m.getNPM() 
                     << setw(14) << m.getNama() << setw(6) << m.getHurufMutu()
                     << setw(10) << m.getStatusLulus() << setw(10) << m.getWaktuMulaiString()
                     << setw(12) << m.getWaktuSelesaiString() << setw(10) << m.getlamaDetikLariString() << endl;
                p = p->next;
            }
            cout << string(85, '=') << endl;
        }
    }
};

int main() {
    LinkedList ujianTPB = LinkedList();
    int pilihan;

    do {
        cout << "\n=== Menu Ujian Lari TPB ===" << endl;
        cout << "1. Tambah data mahasiswa" << endl;
        cout << "2. Hapus data mahasiswa" << endl;
        cout << "3. Cari mahasiswa" << endl;
        cout << "4. Tampilkan semua data" << endl;
        cout << "0. Keluar" << endl;
        cout << "Masukkan pilihan: ";
        cin >> pilihan;

        switch (pilihan) {
            case 1: {
                cout << "1. Insert First" << endl;
                cout << "2. Insert Last" << endl;
                cout << "3. Insert After (berdasarkan NPM)" << endl;
                cout << "Pilih metode: ";
                int metode;
                cin >> metode;
                ElmtList* pBaru = ujianTPB.createElmt();
                if (metode == 1) {
                    ujianTPB.insertFirst(pBaru);
                } else if (metode == 2) {
                    ujianTPB.insertLast(pBaru);
                } else if (metode == 3) {
                    cout << "Masukkan NPM mahasiswa yang ingin ditambah setelahnya: ";
                    string keyAfter;
                    cin >> keyAfter;
                    ujianTPB.insertAfter(pBaru, keyAfter);
                }
                ujianTPB.traversal();
                break;
            }

            case 2: {
                cout << "1. Delete First" << endl;
                cout << "2. Delete Last" << endl;
                cout << "3. Delete After (berdasarkan NPM)" << endl;
                cout << "Pilih metode: ";
                int hapus;
                cin >> hapus;
                if (hapus == 1) {
                    ujianTPB.deleteFirst();
                } else if (hapus == 2) {
                    ujianTPB.deleteLast();
                } else if (hapus == 3) {
                    cout << "Masukkan NPM mahasiswa sebelum data yang ingin dihapus: ";
                    string keyHapus;
                    cin >> keyHapus;
                    ujianTPB.deleteAfter(keyHapus);
                }
                ujianTPB.traversal();
                break;
            }

            case 3: {
                cout << "Masukkan NPM yang dicari: ";
                string key;
                cin >> key;
                ElmtList* hasil = ujianTPB.search(key);
                if (hasil != NULL) {
                    cout << "\nData ditemukan:" << endl;
                    cout << string(85, '=') << endl;
                    cout << left << setw(4) << "No" << setw(14) << "NPM" << setw(14) << "Nama" 
                         << setw(6) << "HM" << setw(10) << "Status" << setw(10) << "Mulai" 
                         << setw(12) << "Selesai" << setw(10) << "Lama" << endl;
                    cout << string(85, '-') << endl;
                    MahasiswaTPB m = hasil->getInfo();
                    cout << left << setw(4) << 1 << setw(14) << m.getNPM() 
                         << setw(14) << m.getNama() << setw(6) << m.getHurufMutu()
                         << setw(10) << m.getStatusLulus() << setw(10) << m.getWaktuMulaiString()
                         << setw(12) << m.getWaktuSelesaiString() << setw(10) << m.getlamaDetikLariString() << endl;
                    cout << string(85, '=') << endl;
                } else {
                    cout << "Mahasiswa dengan NPM " << key << " tidak ditemukan." << endl;
                }
                break;
            }

            case 4:
                ujianTPB.traversal();
                break;

            case 0:
                cout << "Keluar dari program" << endl;
                break;

            default:
                cout << "Pilihan tidak valid!" << endl;
        }

    } while (pilihan != 0);

    return 0;
}