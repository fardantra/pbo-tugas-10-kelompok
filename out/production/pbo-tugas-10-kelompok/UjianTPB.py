# Nama         : Jovianie, Fardan, Newten
# NPM          : 140810240010, 140810240084, 140810240090
# Nama Program : Ujian TPB Python (Array)
# Tanggal      : 24 September 2025

import sys

class Waktu:
    def __init__(self, lama_jam=0, lama_menit=0):
        self.lama_jam = lama_jam
        self.lama_menit = lama_menit
        self.total_menit = 0

    def set_lama_jam(self, lama_jam):
        self.lama_jam = lama_jam

    def set_lama_menit(self, lama_menit):
        self.lama_menit = lama_menit

    def set_total_menit(self, total_menit):
        self.total_menit = total_menit

    def get_lama_jam(self):
        return self.lama_jam

    def get_lama_menit(self):
        return self.lama_menit

    def get_total_menit(self):
        return self.total_menit

    def hitung_total_menit(self):
        self.total_menit = self.lama_jam * 60 + self.lama_menit
        return self.total_menit


class MahasiswaTPB:
    def __init__(self, nama="", npm="", waktu_mulai=None, waktu_selesai=None):
        self.nama = nama
        self.npm = npm
        self.huruf_mutu = ''
        self.status_lulus = ""
        self.waktu_mulai = waktu_mulai
        self.waktu_selesai = waktu_selesai
        self.lama_lari = 0

    def set_nama(self, nama):
        self.nama = nama

    def set_npm(self, npm):
        self.npm = npm

    def set_huruf_mutu(self, huruf_mutu):
        self.huruf_mutu = huruf_mutu

    def set_status_lulus(self, status_lulus):
        self.status_lulus = status_lulus

    def set_waktu_mulai(self, waktu_mulai):
        self.waktu_mulai = waktu_mulai

    def set_waktu_selesai(self, waktu_selesai):
        self.waktu_selesai = waktu_selesai

    def get_nama(self):
        return self.nama

    def get_npm(self):
        return self.npm

    def get_huruf_mutu(self):
        return self.huruf_mutu

    def get_status_lulus(self):
        return self.status_lulus

    def get_waktu_mulai(self):
        return self.waktu_mulai

    def get_waktu_selesai(self):
        return self.waktu_selesai

    def get_lama_lari(self):
        return self.lama_lari

    def input_data(self):
        self.nama = input("Masukkan nama: ")
        self.npm = input("Masukkan NPM: ")

        jam_mulai = int(input("Masukkan jam mulai: "))
        menit_mulai = int(input("Masukkan menit mulai: "))

        jam_selesai = int(input("Masukkan jam selesai: "))
        menit_selesai = int(input("Masukkan menit selesai: "))

        self.waktu_mulai = Waktu()
        self.waktu_selesai = Waktu()

        if 0 <= jam_mulai < 24:
            self.waktu_mulai.set_lama_jam(jam_mulai)
        else:
            print("Waktu tidak valid!", end="")
            sys.exit(0)

        if 0 <= menit_mulai < 60:
            self.waktu_mulai.set_lama_menit(menit_mulai)
        else:
            print("Waktu tidak valid!", end="")
            sys.exit(0)

        if 0 <= jam_selesai < 24:
            self.waktu_selesai.set_lama_jam(jam_selesai)
        else:
            print("Waktu tidak valid!", end="")
            sys.exit(0)

        if 0 <= menit_selesai < 60:
            self.waktu_selesai.set_lama_menit(menit_selesai)
        else:
            print("Waktu tidak valid!", end="")
            sys.exit(0)

    def proses_data(self):
        self.waktu_mulai.hitung_total_menit()
        self.waktu_selesai.hitung_total_menit()

        total_menit_mulai = self.waktu_mulai.get_total_menit()
        total_menit_selesai = self.waktu_selesai.get_total_menit()

        self.lama_lari = total_menit_selesai - total_menit_mulai

        if 0 <= self.lama_lari < 7.5:
            self.huruf_mutu = 'A'
            self.status_lulus = "Lulus"
        elif 7.5 <= self.lama_lari < 12.5:
            self.huruf_mutu = 'B'
            self.status_lulus = "Lulus"
        elif 12.5 <= self.lama_lari < 30:
            self.huruf_mutu = 'C'
            self.status_lulus = "Lulus"
        elif self.lama_lari >= 30:
            self.huruf_mutu = 'D'
            self.status_lulus = "Gagal"
        else:
            self.huruf_mutu = 'X'
            self.status_lulus = "Gagal"

    def output_data(self):
        print(f"Nama: {self.nama}")
        print(f"NPM: {self.npm}")
        print(f"Huruf Mutu: {self.huruf_mutu}")
        print(f"Status Lulus: {self.status_lulus}")
        print(f"Jam Mulai: {self.waktu_mulai.get_lama_jam():02d}:{self.waktu_mulai.get_lama_menit():02d}")
        print(f"Jam Selesai: {self.waktu_selesai.get_lama_jam():02d}:{self.waktu_selesai.get_lama_menit():02d}")
        print(f"Lama Lari: {self.lama_lari} menit", end="")

    def get_waktu_mulai_string(self):
        return f"{self.waktu_mulai.get_lama_jam():02d}:{self.waktu_mulai.get_lama_menit():02d}:{0:02d}"

    def get_waktu_selesai_string(self):
        return f"{self.waktu_selesai.get_lama_jam():02d}:{self.waktu_selesai.get_lama_menit():02d}:{0:02d}"

    def get_lama_lari_string(self):
        jam = self.lama_lari // 60
        menit = self.lama_lari % 60
        return f"{jam:02d}:{menit:02d}:{0:02d}"


def main():
    jumlah_mahasiswa = int(input("Masukkan jumlah mahasiswa: "))
    
    mahasiswa_array = []
    
    for i in range(jumlah_mahasiswa):
        print(f"\n=== Data Mahasiswa ke-{i + 1} ===")
        mahasiswa = MahasiswaTPB()
        mahasiswa.input_data()
        mahasiswa.proses_data()
        mahasiswa_array.append(mahasiswa)

    print("\n\n" + "=" * 85)
    print("\t\tDaftar Nilai Ujian dan Lama Ujian Lari Mahasiswa TPB")
    print("=" * 85)
    print(f"{'No':<4} {'\tNPM':<8} {'  Nama':<12} {'  HM':<4} {'  Status':<8} {'  Mulai':<10} {'  Selesai':<10} {'  Lama':<10}")
    print("-" * 85)

    for i in range(jumlah_mahasiswa):
        print(f"{i + 1:<4} {mahasiswa_array[i].get_npm():<8} {mahasiswa_array[i].get_nama():<12} {mahasiswa_array[i].get_huruf_mutu():<4} {mahasiswa_array[i].get_status_lulus():<8} {mahasiswa_array[i].get_waktu_mulai_string():<10} {mahasiswa_array[i].get_waktu_selesai_string():<10} {mahasiswa_array[i].get_lama_lari_string():<10}")
    
    print("=" * 85)


if __name__ == "__main__":
    main()