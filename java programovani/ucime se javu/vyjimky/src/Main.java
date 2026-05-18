public class Main {
    public static void main(String[] args) {
        // Operace dělení
        try {
            int result = divide(10, 0);
            System.out.println("Division Result: " + result);
        } catch (ArithmeticException e) {
            System.out.println("Cannot divide by zero!");
        } finally {
            System.out.println("Division operation completed.");
        }

        // Operace s polem
        try {
            int[] numbers = {1, 2, 3};
            System.out.println("Accessing element: " + numbers[10]);
        } catch (ArrayIndexOutOfBoundsException e) {
            System.out.println("Array index is out of bounds!");
        } finally {
            System.out.println("Array access operation completed.");
        }

        // Operace se soubory
        try {
            java.io.FileReader file = new java.io.FileReader("nonexistentfile.txt");
        } catch (java.io.FileNotFoundException e) {
            System.out.println("File not found!");
        } finally {
            System.out.println("File operation completed.");
        }
    }

    // Metoda pro dělení dvou čísel
    public static int divide(int a, int b) {
        return a / b;
    }
}

//kontrolovane vyjimky    kontrolovany behem kompilace
//nekontrolovane vyjimky     nekontrolovany behem kompilace
//errory     problemy s pameti, ktere nelze odchytnout