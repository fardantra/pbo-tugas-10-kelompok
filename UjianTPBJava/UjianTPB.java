package UjianTPBJava;
/*
 * Nama         : Jovianie, Fardan, Newten
 * NPM          : 140810240010, 140810240084, 140810240090
 * Nama Program : Ujian TPB Java (Linked List)
 * Tanggal      : 27 Oktober 2025 
 */


import java.util.Scanner;

public class UjianTPB {
    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);
        LinkedList ujianTPB = new LinkedList();
        int pilihan;

        do {
            System.out.println("\n=== Menu Ujian Lari TPB ===");
            System.out.println("1. Tambah data mahasiswa");
            System.out.println("2. Hapus data mahasiswa");
            System.out.println("3. Cari mahasiswa");
            System.out.println("4. Tampilkan semua data");
            System.out.println("0. Keluar");
            System.out.print("Masukkan pilihan: ");
            pilihan = input.nextInt();

            switch (pilihan) {
                case 1:
                    System.out.println("1. Insert First");
                    System.out.println("2. Insert Last");
                    System.out.println("3. Insert After (berdasarkan NPM)");
                    System.out.print("Pilih metode: ");
                    int metode = input.nextInt();
                    ElmtList pBaru = ujianTPB.createElmt(input);
                    if (metode == 1) ujianTPB.insertFirst(pBaru);
                    else if (metode == 2) ujianTPB.insertLast(pBaru);
                    else if (metode == 3) {
                        System.out.print("Masukkan NPM mahasiswa yang ingin ditambah setelahnya: ");
                        String keyAfter = input.next();
                        ujianTPB.insertAfter(pBaru, keyAfter);
                    }
                    ujianTPB.traversal();
                    break;

                case 2:
                    System.out.println("1. Delete First");
                    System.out.println("2. Delete Last");
                    System.out.println("3. Delete After (berdasarkan NPM)");
                    System.out.print("Pilih metode: ");
                    int hapus = input.nextInt();
                    if (hapus == 1) ujianTPB.deleteFirst();
                    else if (hapus == 2) ujianTPB.deleteLast();
                    else if (hapus == 3) {
                        System.out.print("Masukkan NPM mahasiswa sebelum data yang ingin dihapus: ");
                        String keyHapus = input.next();
                        ujianTPB.deleteAfter(keyHapus);
                    }
                    ujianTPB.traversal();
                    break;

                case 3:
                    System.out.print("Masukkan NPM yang dicari: ");
                    String key = input.next();
                    ElmtList hasil = ujianTPB.search(key);
                    if (hasil != null) {
                        System.out.println("\nData ditemukan:");
                        System.out.println("=".repeat(85));
                        System.out.printf("%-4s %-14s %-14s %-6s %-10s %-10s %-12s %-10s%n",
                                "No", "NPM", "Nama", "HM", "Status", "Mulai", "Selesai", "Lama");
                        System.out.println("-".repeat(85));
                        MahasiswaTPB m = hasil.getInfo();
                        System.out.printf("%-4d %-14s %-14s %-6s %-10s %-10s %-12s %-10s%n",
                                1, m.getNPM(), m.getNama(), m.getHurufMutu(),
                                m.getStatusLulus(), m.getWaktuMulaiString(),
                                m.getWaktuSelesaiString(), m.getlamaDetikLariString());
                        System.out.println("=".repeat(85));
                    } else {
                        System.out.println("Mahasiswa dengan NPM " + key + " tidak ditemukan.");
                    }
                    break;

                case 4:
                    ujianTPB.traversal();
                    break;

                case 0:
                    System.out.println("Keluar dari program...");
                    break;

                default:
                    System.out.println("Pilihan tidak valid!");
            }

        } while (pilihan != 0);
        input.close();
    }
}
