public class VnejsiTrida {
    private String jmeno;

    public VnejsiTrida(String jmeno) {
        this.jmeno = jmeno;
    }

    public String getJmeno() {
        return jmeno;
    }

    public class VnitrniTrida {
        private String prijmeni;

        public VnitrniTrida(String prijmeni) {
            this.prijmeni = prijmeni;
        }

        public String getPrijmeni() {
            return prijmeni;
        }
    }

    public static void main(String[] args) {
        // Vytvoření instance vnější třídy
        VnejsiTrida vnejsiObjekt = new VnejsiTrida("Jan");

        // Vytvoření instance vnitřní třídy
        VnejsiTrida.VnitrniTrida vnitrniObjekt = vnejsiObjekt.new VnitrniTrida("Novak");

        // Použití metod vnější a vnitřní třídy
        String jmeno = vnejsiObjekt.getJmeno();
        String prijmeni = vnitrniObjekt.getPrijmeni();

        System.out.println("Jméno: " + jmeno + ", Příjmení: " + prijmeni);
    }
}
