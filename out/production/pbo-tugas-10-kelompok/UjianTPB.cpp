/*
 * Nama         : Jovianie, Fardan, Newten
 * NPM          : 140810240010, 140810240084, 140810240090
 * Nama Program : Ujian TPB C++ (Array)
 * Tanggal      : 24 September 2025 
 */

#include <iostream>
#include <string>
#include <iomanip>
#include <cstdlib>
using namespace std;

class Waktu {
private:
    int lamaJam;
    int lamaMenit;
    int totalMenit;

public:
    Waktu() {
        lamaJam = 0;
        lamaMenit = 0;
        totalMenit = 0;
    }

    Waktu(int lamaJam, int lamaMenit) {
        this->lamaJam = lamaJam;
        this->lamaMenit = lamaMenit;
        this->totalMenit = 0;
    }

    void setLamaJam(int lamaJam) {
        this->lamaJam = lamaJam;
    }

    void setLamaMenit(int lamaMenit) {
        this->lamaMenit = lamaMenit;
    }

    void setTotalMenit(int totalMenit) {
        this->totalMenit = totalMenit;
    }

    int getLamaJam() {
        return this->lamaJam;
    }

    int getLamaMenit() {
        return this->lamaMenit;
    }

    int getTotalMenit() {
        return this->totalMenit;
    }

    int hitungTotalMenit() {
        this->totalMenit = this->lamaJam * 60 + this->lamaMenit;
        return this->totalMenit;
    }
};

class MahasiswaTPB {
private:
    string nama;
    string NPM;
    char hurufMutu;
    string statusLulus;
    Waktu waktuMulai;
    Waktu waktuSelesai;
    int lamaLari;

public:
    MahasiswaTPB() {
        nama = "";
        NPM = "";
        hurufMutu = ' ';
        statusLulus = "";
        lamaLari = 0;
    }

    MahasiswaTPB(string nama, string NPM, Waktu waktuMulai, Waktu waktuSelesai) {
        this->nama = nama;
        this->NPM = NPM;
        this->waktuMulai = waktuMulai;
        this->waktuSelesai = waktuSelesai;
        this->hurufMutu = ' ';
        this->statusLulus = "";
        this->lamaLari = 0;
    }

    void setNama(string nama) {
        this->nama = nama;
    }

    void setNPM(string NPM) {
        this->NPM = NPM;
    }

    void setHurufMutu(char hurufMutu) {
        this->hurufMutu = hurufMutu;
    }

    void setStatusLulus(string statusLulus) {
        this->statusLulus = statusLulus;
    }

    void setWaktuMulai(Waktu waktuMulai) {
        this->waktuMulai = waktuMulai;
    }

    void setWaktuSelesai(Waktu waktuSelesai) {
        this->waktuSelesai = waktuSelesai;
    }

    string getNama() {
        return this->nama;
    }

    string getNPM() {
        return this->NPM;
    }

    char getHurufMutu() {
        return this->hurufMutu;
    }

    string getStatusLulus() {
        return this->statusLulus;
    }

    Waktu getWaktuMulai() {
        return this->waktuMulai;
    }

    Waktu getWaktuSelesai() {
        return this->waktuSelesai;
    }

    int getLamaLari() {
        return this->lamaLari;
    }

    void inputData() {
        int jamMulai, menitMulai, jamSelesai, menitSelesai;
        
        cout << "Masukkan nama: ";
        cin >> this->nama;
        cout << "Masukkan NPM: ";
        cin >> this->NPM;

        cout << "Masukkan jam mulai: ";
        cin >> jamMulai;
        cout << "Masukkan menit mulai: ";
        cin >> menitMulai;

        cout << "Masukkan jam selesai: ";
        cin >> jamSelesai;
        cout << "Masukkan menit selesai: ";
        cin >> menitSelesai;

        this->waktuMulai = Waktu();
        this->waktuSelesai = Waktu();

        if (jamMulai >= 0 && jamMulai < 24) {
            this->waktuMulai.setLamaJam(jamMulai);
        } else {
            cout << "Waktu tidak valid!";
            exit(0);
        }

        if (menitMulai >= 0 && menitMulai < 60) {
            this->waktuMulai.setLamaMenit(menitMulai);
        } else {
            cout << "Waktu tidak valid!";
            exit(0);
        }

        if (jamSelesai >= 0 && jamSelesai < 24) {
            this->waktuSelesai.setLamaJam(jamSelesai);
        } else {
            cout << "Waktu tidak valid!";
            exit(0);
        }

        if (menitSelesai >= 0 && menitSelesai < 60) {
            this->waktuSelesai.setLamaMenit(menitSelesai);
        } else {
            cout << "Waktu tidak valid!";
            exit(0);
        }
    }

    void prosesData() {
        int totalMenitMulai;
        int totalMenitSelesai;

        this->waktuMulai.hitungTotalMenit();
        this->waktuSelesai.hitungTotalMenit();

        totalMenitMulai = this->waktuMulai.getTotalMenit();
        totalMenitSelesai = this->waktuSelesai.getTotalMenit();

        this->lamaLari = totalMenitSelesai - totalMenitMulai;

        if (this->lamaLari >= 0 && this->lamaLari < 7.5) {
            this->hurufMutu = 'A';
            this->statusLulus = "Lulus";
        } else if (this->lamaLari >= 7.5 && this->lamaLari < 12.5) {
            this->hurufMutu = 'B';
            this->statusLulus = "Lulus";
        } else if (this->lamaLari >= 12.5 && this->lamaLari < 30) {
            this->hurufMutu = 'C';
            this->statusLulus = "Lulus";
        } else if (this->lamaLari >= 30) {
            this->hurufMutu = 'D';
            this->statusLulus = "Gagal";
        } else {
            this->hurufMutu = 'X';
            this->statusLulus = "Gagal";
        }
    }

    void outputData() {
        cout << "Nama: " << this->nama << endl;
        cout << "NPM: " << this->NPM << endl;
        cout << "Huruf Mutu: " << this->hurufMutu << endl;
        cout << "Status Lulus: " << this->statusLulus << endl;
        cout << "Jam Mulai: " << setfill('0') << setw(2) << this->waktuMulai.getLamaJam() 
             << ":" << setfill('0') << setw(2) << this->waktuMulai.getLamaMenit() << endl;
        cout << "Jam Selesai: " << setfill('0') << setw(2) << this->waktuSelesai.getLamaJam() 
             << ":" << setfill('0') << setw(2) << this->waktuSelesai.getLamaMenit() << endl;
        cout << "Lama Lari: " << this->lamaLari << " menit";
    }

    string getWaktuMulaiString() {
        char buffer[10];
        sprintf(buffer, "%02d:%02d:%02d", this->waktuMulai.getLamaJam(), this->waktuMulai.getLamaMenit(), 0);
        return string(buffer);
    }
    
    string getWaktuSelesaiString() {
        char buffer[10];
        sprintf(buffer, "%02d:%02d:%02d", this->waktuSelesai.getLamaJam(), this->waktuSelesai.getLamaMenit(), 0);
        return string(buffer);
    }
    
    string getLamaLariString() {
        int jam = this->lamaLari / 60;
        int menit = this->lamaLari % 60;
        char buffer[10];
        sprintf(buffer, "%02d:%02d:%02d", jam, menit, 0);
        return string(buffer);
    }
};

int main() {
    int jumlahMahasiswa;
    
    cout << "Masukkan jumlah mahasiswa: ";
    cin >> jumlahMahasiswa;
    
    MahasiswaTPB* mahasiswaArray = new MahasiswaTPB[jumlahMahasiswa];
    
    for (int i = 0; i < jumlahMahasiswa; i++) {
        cout << "\n=== Data Mahasiswa ke-" << (i + 1) << " ===" << endl;
        mahasiswaArray[i] = MahasiswaTPB();
        mahasiswaArray[i].inputData();
        mahasiswaArray[i].prosesData();
    }

    cout << "\n\n" << string(85, '=') << endl;
    cout << "\t\tDaftar Nilai Ujian dan Lama Ujian Lari Mahasiswa TPB" << endl;
    cout << string(85, '=') << endl;
    
    cout << left << setw(4) << "No" << left << setw(8) << "\tNPM" << left << setw(12) << "  Nama" 
         << left << setw(4) << "  HM" << left << setw(8) << "  Status" << left << setw(10) << "  Mulai" 
         << left << setw(10) << "  Selesai" << left << setw(10) << "  Lama" << endl;
    cout << string(85, '-') << endl;

    for (int i = 0; i < jumlahMahasiswa; i++) {
        cout << left << setw(4) << (i + 1) << left << setw(8) << mahasiswaArray[i].getNPM() 
             << left << setw(12) << mahasiswaArray[i].getNama() << left << setw(4) << mahasiswaArray[i].getHurufMutu() 
             << left << setw(8) << mahasiswaArray[i].getStatusLulus() << left << setw(10) << mahasiswaArray[i].getWaktuMulaiString() 
             << left << setw(10) << mahasiswaArray[i].getWaktuSelesaiString() << left << setw(10) << mahasiswaArray[i].getLamaLariString() << endl;
    }
    cout << string(85, '=') << endl;
    
    delete[] mahasiswaArray;
    return 0;
}