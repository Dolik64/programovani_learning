public class DemoClass {

    // 1. Metoda s návratovým typem void (provádí akci, ale nic nevrací)
    public void printMessage() {
        System.out.println("Toto je zpráva.");
    }

    // 2. Metoda s návratovým typem int (vrací celé číslo)
    public int add(int a, int b) {
        return a + b;
    }

    // 3. Metoda s návratovým typem String (vrací řetězec)
    public String getGreeting(String name) {
        return "Ahoj, " + name + "!";
    }

    // 4. Metoda s návratovým typem boolean (vrací pravdivostní hodnotu)
    public boolean isEven(int number) {
        return number % 2 == 0;
    }

    // 5. Metoda s návratovým typem double (vrací desetinné číslo)
    public double multiply(double a, double b) {
        return a * b;
    }

    // 6. Metoda, která nebere žádné parametry a vrací řetězec
    public String getDefaultGreeting() {
        return "Ahoj, světe!";
    }

    // 7. Metoda, která bere pole a vrací největší prvek
    public int getMax(int[] numbers) {
        int max = numbers[0];
        for (int number : numbers) {
            if (number > max) {
                max = number;
            }
        }
        return max;
    }

    public static void main(String[] args) {
        DemoClass demo = new DemoClass();

        // Volání metody s void návratovým typem
        demo.printMessage();

        // Volání metody s návratovým typem int
        int sum = demo.add(5, 3);
        System.out.println("Součet: " + sum);

        // Volání metody s návratovým typem String
        String greeting = demo.getGreeting("Honza");
        System.out.println(greeting);

        // Volání metody s návratovým typem boolean
        boolean isEven = demo.isEven(4);
        System.out.println("Číslo 4 je sudé: " + isEven);

        // Volání metody s návratovým typem double
        double product = demo.multiply(2.5, 4.0);
        System.out.println("Součin: " + product);

        // Volání metody, která nebere žádné parametry
        String defaultGreeting = demo.getDefaultGreeting();
        System.out.println(defaultGreeting);

        // Volání metody, která bere pole a vrací největší prvek
        int[] numbers = {1, 2, 3, 4, 5};
        int maxNumber = demo.getMax(numbers);
        System.out.println("Největší číslo: " + maxNumber);
    }
}
