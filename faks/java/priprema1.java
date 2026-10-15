// inputi se ne checkaju i program ce bacit exception ako krivi input uneses,
// u pripremi doc ne pise da se treba handleat

public static final String POZICIJA_VRATAR = "VRATAR";
public static final String POZICIJA_BRANIC = "BRANIC";
public static final String POZICIJA_VEZNJAK = "VEZNJAK";
public static final String POZICIJA_NAPADAC = "NAPADAC";


public class Osoba {
    private String ime;
    private String prezime;
    private int godinaRodenja;

    public String getIme() {
        return ime;
    }

    public void setIme(String ime) {
        this.ime = ime;
    }

    public String getPrezime() {
        return prezime;
    }

    public void setPrezime(String prezime) {
        this.prezime = prezime;
    }

    public int getGodinaRodenja() {
        return godinaRodenja;
    }

    public void setGodinaRodenja(int godinaRodenja) {
        this.godinaRodenja = godinaRodenja;
    }

}

public class Igrac extends Osoba {
    private int brojDresa;
    private String pozicija;

    public Igrac(String ime, String prezime, int godinaRodenja, int brojDresa, String pozicija) {
        this.setIme(ime);
        this.setPrezime(prezime);
        this.setGodinaRodenja(godinaRodenja);
        this.brojDresa = brojDresa;
        this.pozicija = pozicija;
    }

    public int getBrojDresa() {
        return brojDresa;
    }

    public void setBrojDresa(int brojDresa) {
        this.brojDresa = brojDresa;
    }

    public String getPozicija() {
        return pozicija;
    }

    public void setPozicija(String pozicija) {
        this.pozicija = pozicija;
    }
}

public class Trener extends Osoba {
    private int godineIskustva;

    public Trener(String ime, String prezime, int godinaRodenja, int godineIskustva) {
        this.setIme(ime);
        this.setPrezime(prezime);
        this.setGodinaRodenja(godinaRodenja);
        this.godineIskustva = godineIskustva;
    }

    public int getGodineIskustva() {
        return godineIskustva;
    }

    public void setGodineIskustva(int godineIskustva) {
        this.godineIskustva = godineIskustva;
    }
}

public class Stadion {
    public String getNaziv() {
        return naziv;
    }

    private String naziv;
    private String grad;
    private Integer kapacitet;
    private Integer godinaIzgradnje;
    private Boolean natkriven;

    public Stadion(String naziv, String grad, Integer kapacitet, Integer godinaIzgradnje, Boolean natkriven) {
        this.naziv = naziv;
        this.grad = grad;
        this.kapacitet = kapacitet;
        this.godinaIzgradnje = godinaIzgradnje;
        this.natkriven = natkriven;
    }
}

public class NogometniKlub {
    private String naziv;
    private String grad;
    private int godinaOsnovanja;
    private Stadion stadion;
    private Trener trener;
    private Igrac[] igraci;

    public NogometniKlub() {
        // uzas kod al sta ces
        Scanner s = new Scanner(System.in);

        IO.print("Naziv kluba: ");
        this.naziv = s.nextLine();
        IO.print("Grad: ");
        this.grad = s.nextLine();

        IO.print("Godina osnivanja: ");
        this.godinaOsnovanja = s.nextInt();
        s.nextLine(); // burn

        IO.print("\n"); // divide

        // stadion input
        IO.print("Naziv stadiona: ");
        String stdnaziv = s.nextLine();

        IO.print("Grad stadiona: ");
        String stdgrad = s.nextLine();

        IO.print("Kapacitet: ");
        int stdkapacitet = s.nextInt();

        IO.print("Godina izgradnje: ");
        int stdgod = s.nextInt();

        IO.print("Je li stadion natkriven: ");
        Boolean natkr = s.nextBoolean();
        s.nextLine(); // burn

        this.stadion = new Stadion(stdnaziv, stdgrad, stdkapacitet, stdgod, natkr);
        IO.print("\n"); // divide

        // trener input
        IO.print("Ime trenera: ");
        String trenerIme = s.nextLine();

        IO.print("Prezime trenera: ");
        String trenerPrezime = s.nextLine();

        IO.print("Godina rodenja: ");
        int trenerGodinaRodenja = s.nextInt();
        s.nextLine(); // burn

        IO.print("Godine iskustva: ");
        int trenerGodineIskustva = s.nextInt();
        s.nextLine(); // burn


        this.trener = new Trener(trenerIme, trenerPrezime, trenerGodinaRodenja, trenerGodineIskustva);
        IO.print("\n"); // divide

        // igraci
        this.unesiIgrace();
    }

    public void unesiIgrace() {
        Scanner s = new Scanner(System.in);
        IO.print("Koliko igraca zelite unijeti: ");
        int brojIgraca = s.nextInt();
        s.nextLine(); // burn

        this.igraci = new Igrac[brojIgraca];
        for (int i = 0; i < brojIgraca; i++) {
            IO.print("--- IGRAC %d ---\n".formatted(i +1));
            IO.print("Ime: ");
            String igracIme = s.nextLine();

            IO.print("Prezime: ");
            String igracPrezime = s.nextLine();

            IO.print("Godina rodenja: ");
            int igracGodinaRodenja = s.nextInt();

            IO.print("Broj dresa: ");
            int brojDresa = s.nextInt();
            s.nextLine(); // burn

            IO.print("Pozicija: ");
            String poz = s.nextLine();

            this.igraci[i] = new Igrac(igracIme, igracPrezime, igracGodinaRodenja, brojDresa, poz);
        }
    }

    public void getOpis() {
        IO.print("===== %s =====\n".formatted(this.naziv));
        IO.print("Grad: %s\nGodina osnivanja: %d\nTrener: %s\nStadion: %s\n".formatted(this.grad, this.godinaOsnovanja, this.trener.getIme(),this.stadion.getNaziv()));
    }

    public String getNaziv() {
        return naziv;
    }
}

void main() {
    NogometniKlub[] kluboviArray;
    Scanner s = new Scanner(System.in);
    IO.print("Koliko nogometnih klubova zelite unijeti: ");
    int brojKlubova = s.nextInt();
    kluboviArray = new NogometniKlub[brojKlubova];
    for (int i = 0; i < brojKlubova; i++) {
        IO.println("===== UNOS KLUBA %d =====".formatted(i + 1));
        kluboviArray[i] = new NogometniKlub();
    }
    while (true) {
        IO.println("====== NOGOMETNI KLUBOVI ======");
        IO.print("\n1 - Pretrazi klub\n0 - Zavrsi program\nOdabir: ");
        int option = s.nextInt();
        s.nextLine(); // burn
        if (option == 1) {
            IO.print("Unesite naziv kluba: ");
            String nazivK = s.nextLine();

            NogometniKlub foundclub = null;
            for (NogometniKlub nk : kluboviArray) {
                if (nk.getNaziv().equalsIgnoreCase(nazivK)) {
                    foundclub = nk;
                }
            }
            if (foundclub != null) {
                foundclub.getOpis();
            } else {
                IO.println("Nema kluba s tim nazivom.");
            }
        } else {
            break;
        }
    }
}
