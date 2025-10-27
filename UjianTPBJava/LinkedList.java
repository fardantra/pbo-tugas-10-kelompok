package UjianTPBJava;

import java.util.Scanner;

public class LinkedList {
    private ElmtList First;

    public LinkedList() { First = null; }

    public ElmtList createElmt(Scanner input) {
        MahasiswaTPB mhs = new MahasiswaTPB();
        mhs.inputData(input);
        mhs.prosesData();

        ElmtList pBaru = new ElmtList();
        pBaru.setInfo(mhs);
        pBaru.next = null;
        return pBaru;
    }

    void insertFirst(ElmtList pBaru) {
        pBaru.next = First;
        First = pBaru;
    }

    void insertLast(ElmtList pBaru) {
        if (First == null) First = pBaru;
        else {
            ElmtList pBantu = First;
            while (pBantu.next != null) pBantu = pBantu.next;
            pBantu.next = pBaru;
        }
    }

    void insertAfter(ElmtList pBaru, String key) {
        ElmtList pCari = search(key);
        if (pCari == null) {
            System.out.println("Mahasiswa dengan NPM " + key + " tidak ditemukan.");
        } else {
            pBaru.next = pCari.next;
            pCari.next = pBaru;
            System.out.println("Data berhasil ditambahkan setelah NPM " + key + ".");
        }
    }

    void deleteFirst() {
        if (First == null) System.out.println("List kosong!");
        else {
            System.out.println("Data dengan NPM " + First.getInfo().getNPM() + " berhasil dihapus.");
            First = First.next;
        }
    }

    void deleteLast() {
        if (First == null) System.out.println("List kosong!");
        else if (First.next == null) {
            System.out.println("Data dengan NPM " + First.getInfo().getNPM() + " berhasil dihapus.");
            First = null;
        } else {
            ElmtList p = First;
            while (p.next.next != null) p = p.next;
            System.out.println("Data dengan NPM " + p.next.getInfo().getNPM() + " berhasil dihapus.");
            p.next = null;
        }
    }

    void deleteAfter(String key) {
        ElmtList pCari = search(key);
        if (pCari == null || pCari.next == null) {
            System.out.println("Tidak ditemukan data setelah NPM " + key + ".");
        } else {
            ElmtList pHapus = pCari.next;
            pCari.next = pHapus.next;
            System.out.println("Data setelah NPM " + key + " berhasil dihapus (NPM: " + pHapus.getInfo().getNPM() + ").");
        }
    }

    ElmtList search(String key) {
        ElmtList p = First;
        while (p != null) {
            if (p.getInfo().getNPM().equals(key)) return p;
            p = p.next;
        }
        return null;
    }

    void traversal() {
        if (First == null) {
            System.out.println("List kosong");
        } else {
            System.out.println("\n\n" + "=".repeat(85));
            System.out.println("\t\tDaftar Nilai Ujian dan Lama Ujian Lari Mahasiswa TPB");
            System.out.println("=".repeat(85));
            System.out.printf("%-4s %-14s %-14s %-6s %-10s %-10s %-12s %-10s%n",
                    "No", "NPM", "Nama", "HM", "Status", "Mulai", "Selesai", "Lama");
            System.out.println("-".repeat(85));

            ElmtList p = First;
            int i = 1;
            while (p != null) {
                MahasiswaTPB m = p.getInfo();
                System.out.printf("%-4d %-14s %-14s %-6s %-10s %-10s %-12s %-10s%n",
                        i++, m.getNPM(), m.getNama(), m.getHurufMutu(),
                        m.getStatusLulus(), m.getWaktuMulaiString(),
                        m.getWaktuSelesaiString(), m.getlamaDetikLariString());
                p = p.next;
            }
            System.out.println("=".repeat(85));
        }
    }
}