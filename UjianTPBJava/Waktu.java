package UjianTPBJava;

public class Waktu {
    private int jam, menit, detik;

    public Waktu() {}
    public Waktu(int jam, int menit, int detik) {
        this.jam = jam;
        this.menit = menit;
        this.detik = detik;
    }

    public void setJam(int jam) { this.jam = jam; }
    public void setMenit(int menit) { this.menit = menit; }
    public void setDetik(int detik) { this.detik = detik; }

    public int getjam() { return this.jam; }
    public int getmenit() { return this.menit; }
    public int getDetik() { return this.detik; }

    public int hitungTotalDetik() {
        return this.jam * 3600 + this.menit * 60 + this.detik;
    }
}


