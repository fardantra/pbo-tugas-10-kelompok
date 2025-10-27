package UjianTPBJava;

import java.time.DateTimeException;
import java.time.LocalTime;
import java.time.format.DateTimeFormatter;
import java.util.Scanner;

public class MahasiswaTPB {
    private String nama, NPM, statusLulus;
    private char hurufMutu;
    private Waktu waktuMulai, waktuSelesai;
    private int lamaDetikLari;

    public MahasiswaTPB() {}

    public void inputData(Scanner input) {
        System.out.print("Masukkan nama: ");
        this.nama = input.next();
        System.out.print("Masukkan NPM: ");
        this.NPM = input.next();

        System.out.print("Masukkan waktu mulai (HH:mm:ss): ");
        String mulaiStr = input.next();
        System.out.print("Masukkan waktu selesai (HH:mm:ss): ");
        String selesaiStr = input.next();

        DateTimeFormatter formatter = DateTimeFormatter.ofPattern("HH:mm:ss");
        this.waktuMulai = new Waktu();
        this.waktuSelesai = new Waktu();

        try {
            LocalTime timeMulai = LocalTime.parse(mulaiStr, formatter);
            LocalTime timeSelesai = LocalTime.parse(selesaiStr, formatter);

            this.waktuMulai.setJam(timeMulai.getHour());
            this.waktuMulai.setMenit(timeMulai.getMinute());
            this.waktuMulai.setDetik(timeMulai.getSecond());

            this.waktuSelesai.setJam(timeSelesai.getHour());
            this.waktuSelesai.setMenit(timeSelesai.getMinute());
            this.waktuSelesai.setDetik(timeSelesai.getSecond());
        } catch (DateTimeException e) {
            System.out.println("Format waktu tidak valid: " + e.getMessage());
        }
    }

    public void prosesData() {
        int totalMulai = waktuMulai.hitungTotalDetik();
        int totalSelesai = waktuSelesai.hitungTotalDetik();
        lamaDetikLari = totalSelesai - totalMulai;

        if (lamaDetikLari < 450) {
            hurufMutu = 'A'; statusLulus = "Lulus";
        } else if (lamaDetikLari < 750) {
            hurufMutu = 'B'; statusLulus = "Lulus";
        } else if (lamaDetikLari < 1800) {
            hurufMutu = 'C'; statusLulus = "Lulus";
        } else {
            hurufMutu = 'D'; statusLulus = "Gagal";
        }
    }

    public String getNama() { return nama; }
    public String getNPM() { return NPM; }
    public char getHurufMutu() { return hurufMutu; }
    public String getStatusLulus() { return statusLulus; }

    public String getWaktuMulaiString() {
        return String.format("%02d:%02d:%02d", waktuMulai.getjam(), waktuMulai.getmenit(), waktuMulai.getDetik());
    }
    public String getWaktuSelesaiString() {
        return String.format("%02d:%02d:%02d", waktuSelesai.getjam(), waktuSelesai.getmenit(), waktuSelesai.getDetik());
    }
    public String getlamaDetikLariString() {
        int jam = lamaDetikLari / 3600;
        int menit = (lamaDetikLari % 3600) / 60;
        int detik = lamaDetikLari % 60;
        return String.format("%02d:%02d:%02d", jam, menit, detik);
    }
}