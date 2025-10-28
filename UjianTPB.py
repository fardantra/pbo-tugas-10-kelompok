"""
Nama         : Jovianie, Fardan, Newten
NPM          : 140810240010, 140810240084, 140810240090
Nama Program : Ujian TPB Python (Linked List)
Tanggal      : 27 Oktober 2025 
"""

class Waktu:
    def __init__(self, jam=0, menit=0, detik=0):
        self.jam = jam
        self.menit = menit
        self.detik = detik
    
    def set_jam(self, jam):
        self.jam = jam
    
    def set_menit(self, menit):
        self.menit = menit
    
    def set_detik(self, detik):
        self.detik = detik
    
    def get_jam(self):
        return self.jam
    
    def get_menit(self):
        return self.menit
    
    def get_detik(self):
        return self.detik
    
    def hitung_total_detik(self):
        return self.jam * 3600 + self.menit * 60 + self.detik


class MahasiswaTPB:
    def __init__(self):
        self.nama = ""
        self.NPM = ""
        self.status_lulus = ""
        self.huruf_mutu = ' '
        self.waktu_mulai = Waktu()
        self.waktu_selesai = Waktu()
        self.lama_detik_lari = 0
    
    def input_data(self):
        self.nama = input("Masukkan nama: ")
        self.NPM = input("Masukkan NPM: ")
        
        mulai_str = input("Masukkan waktu mulai (HH:mm:ss): ")
        selesai_str = input("Masukkan waktu selesai (HH:mm:ss): ")
        
        self.waktu_mulai = Waktu()
        self.waktu_selesai = Waktu()
        
        try:
            jam_mulai, menit_mulai, detik_mulai = map(int, mulai_str.split(':'))
            jam_selesai, menit_selesai, detik_selesai = map(int, selesai_str.split(':'))
            
            self.waktu_mulai.set_jam(jam_mulai)
            self.waktu_mulai.set_menit(menit_mulai)
            self.waktu_mulai.set_detik(detik_mulai)
            
            self.waktu_selesai.set_jam(jam_selesai)
            self.waktu_selesai.set_menit(menit_selesai)
            self.waktu_selesai.set_detik(detik_selesai)
        except:
            print("Format waktu tidak valid")
    
    def proses_data(self):
        total_mulai = self.waktu_mulai.hitung_total_detik()
        total_selesai = self.waktu_selesai.hitung_total_detik()
        self.lama_detik_lari = total_selesai - total_mulai
        
        if self.lama_detik_lari < 450:
            self.huruf_mutu = 'A'
            self.status_lulus = "Lulus"
        elif self.lama_detik_lari < 750:
            self.huruf_mutu = 'B'
            self.status_lulus = "Lulus"
        elif self.lama_detik_lari < 1800:
            self.huruf_mutu = 'C'
            self.status_lulus = "Lulus"
        else:
            self.huruf_mutu = 'D'
            self.status_lulus = "Gagal"
    
    def get_nama(self):
        return self.nama
    
    def get_NPM(self):
        return self.NPM
    
    def get_huruf_mutu(self):
        return self.huruf_mutu
    
    def get_status_lulus(self):
        return self.status_lulus
    
    def get_waktu_mulai_string(self):
        return f"{self.waktu_mulai.get_jam():02d}:{self.waktu_mulai.get_menit():02d}:{self.waktu_mulai.get_detik():02d}"
    
    def get_waktu_selesai_string(self):
        return f"{self.waktu_selesai.get_jam():02d}:{self.waktu_selesai.get_menit():02d}:{self.waktu_selesai.get_detik():02d}"
    
    def get_lama_detik_lari_string(self):
        jam = self.lama_detik_lari // 3600
        menit = (self.lama_detik_lari % 3600) // 60
        detik = self.lama_detik_lari % 60
        return f"{jam:02d}:{menit:02d}:{detik:02d}"


class ElmtList:
    def __init__(self):
        self.mhs = MahasiswaTPB()
        self.next = None
    
    def set_info(self, info):
        self.mhs = info
    
    def get_info(self):
        return self.mhs


class LinkedList:
    def __init__(self):
        self.First = None
    
    def create_elmt(self):
        mhs = MahasiswaTPB()
        mhs.input_data()
        mhs.proses_data()
        
        p_baru = ElmtList()
        p_baru.set_info(mhs)
        p_baru.next = None
        return p_baru
    
    def insert_first(self, p_baru):
        p_baru.next = self.First
        self.First = p_baru
    
    def insert_last(self, p_baru):
        if self.First is None:
            self.First = p_baru
        else:
            p_bantu = self.First
            while p_bantu.next is not None:
                p_bantu = p_bantu.next
            p_bantu.next = p_baru
    
    def insert_after(self, p_baru, key):
        p_cari = self.search(key)
        if p_cari is None:
            print(f"Mahasiswa dengan NPM {key} tidak ditemukan.")
        else:
            p_baru.next = p_cari.next
            p_cari.next = p_baru
            print(f"Data berhasil ditambahkan setelah NPM {key}.")
    
    def delete_first(self):
        if self.First is None:
            print("List kosong!")
        else:
            print(f"Data dengan NPM {self.First.get_info().get_NPM()} berhasil dihapus.")
            self.First = self.First.next
    
    def delete_last(self):
        if self.First is None:
            print("List kosong!")
        elif self.First.next is None:
            print(f"Data dengan NPM {self.First.get_info().get_NPM()} berhasil dihapus.")
            self.First = None
        else:
            p = self.First
            while p.next.next is not None:
                p = p.next
            print(f"Data dengan NPM {p.next.get_info().get_NPM()} berhasil dihapus.")
            p.next = None
    
    def delete_after(self, key):
        p_cari = self.search(key)
        if p_cari is None or p_cari.next is None:
            print(f"Tidak ditemukan data setelah NPM {key}.")
        else:
            p_hapus = p_cari.next
            p_cari.next = p_hapus.next
            print(f"Data setelah NPM {key} berhasil dihapus (NPM: {p_hapus.get_info().get_NPM()}).")
    
    def search(self, key):
        p = self.First
        while p is not None:
            if p.get_info().get_NPM() == key:
                return p
            p = p.next
        return None
    
    def traversal(self):
        if self.First is None:
            print("List kosong")
        else:
            print("\n\n" + "=" * 85)
            print("\t\tDaftar Nilai Ujian dan Lama Ujian Lari Mahasiswa TPB")
            print("=" * 85)
            print(f"{'No':<4}{'NPM':<14}{'Nama':<14}{'HM':<6}{'Status':<10}{'Mulai':<10}{'Selesai':<12}{'Lama':<10}")
            print("-" * 85)
            
            p = self.First
            i = 1
            while p is not None:
                m = p.get_info()
                print(f"{i:<4}{m.get_NPM():<14}{m.get_nama():<14}{m.get_huruf_mutu():<6}{m.get_status_lulus():<10}{m.get_waktu_mulai_string():<10}{m.get_waktu_selesai_string():<12}{m.get_lama_detik_lari_string():<10}")
                p = p.next
                i += 1
            print("=" * 85)


def main():
    ujian_TPB = LinkedList()
    
    while True:
        print("\n=== Menu Ujian Lari TPB ===")
        print("1. Tambah data mahasiswa")
        print("2. Hapus data mahasiswa")
        print("3. Cari mahasiswa")
        print("4. Tampilkan semua data")
        print("0. Keluar")
        pilihan = input("Masukkan pilihan: ")
        
        if pilihan == '1':
            print("1. Insert First")
            print("2. Insert Last")
            print("3. Insert After (berdasarkan NPM)")
            metode = input("Pilih metode: ")
            p_baru = ujian_TPB.create_elmt()
            if metode == '1':
                ujian_TPB.insert_first(p_baru)
            elif metode == '2':
                ujian_TPB.insert_last(p_baru)
            elif metode == '3':
                key_after = input("Masukkan NPM mahasiswa yang ingin ditambah setelahnya: ")
                ujian_TPB.insert_after(p_baru, key_after)
            ujian_TPB.traversal()
        
        elif pilihan == '2':
            print("1. Delete First")
            print("2. Delete Last")
            print("3. Delete After (berdasarkan NPM)")
            hapus = input("Pilih metode: ")
            if hapus == '1':
                ujian_TPB.delete_first()
            elif hapus == '2':
                ujian_TPB.delete_last()
            elif hapus == '3':
                key_hapus = input("Masukkan NPM mahasiswa sebelum data yang ingin dihapus: ")
                ujian_TPB.delete_after(key_hapus)
            ujian_TPB.traversal()
        
        elif pilihan == '3':
            key = input("Masukkan NPM yang dicari: ")
            hasil = ujian_TPB.search(key)
            if hasil is not None:
                print("\nData ditemukan:")
                print("=" * 85)
                print(f"{'No':<4}{'NPM':<14}{'Nama':<14}{'HM':<6}{'Status':<10}{'Mulai':<10}{'Selesai':<12}{'Lama':<10}")
                print("-" * 85)
                m = hasil.get_info()
                print(f"{1:<4}{m.get_NPM():<14}{m.get_nama():<14}{m.get_huruf_mutu():<6}{m.get_status_lulus():<10}{m.get_waktu_mulai_string():<10}{m.get_waktu_selesai_string():<12}{m.get_lama_detik_lari_string():<10}")
                print("=" * 85)
            else:
                print(f"Mahasiswa dengan NPM {key} tidak ditemukan.")
        
        elif pilihan == '4':
            ujian_TPB.traversal()
        
        elif pilihan == '0':
            print("Keluar dari program")
            break
        
        else:
            print("Pilihan tidak valid!")


if __name__ == "__main__":
    main()