package UjianTPBJava;

public class ElmtList {
    private MahasiswaTPB mhs;
    ElmtList next;

    public ElmtList() {
        this.mhs = new MahasiswaTPB();
        next = null;
    }
    public void setInfo(MahasiswaTPB info) { this.mhs = info; }
    public MahasiswaTPB getInfo() { return this.mhs; }
}

