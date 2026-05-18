// Definice generické třídy Box
class Box<T> {
    private T value;

    public void set(T value) {
        this.value = value;
    }

    public T get() {
        return this.value;
    }
}

public class Main {
    public static void main(String[] args) {
        // Vytvoření instancí generické třídy Box pro různé typy
        Box<Integer> integerBox = new Box<>();
        Box<String> stringBox = new Box<>();

        // Nastavení hodnot do Boxů
        integerBox.set(123);
        stringBox.set("Hello, Generics!");

        // Získání a tisk hodnot z Boxů
        Integer integerValue = integerBox.get();
        String stringValue = stringBox.get();

        System.out.println("Integer value: " + integerValue);
        System.out.println("String value: " + stringValue);
    }
}
