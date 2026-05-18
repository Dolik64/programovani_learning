// Základní třída Animal
class Animal {
    String name;

    // Konstruktor základní třídy
    public Animal(String name) {
        this.name = name;
    }

    // Metoda základní třídy
    public void makeSound() {
        System.out.println("Some generic animal sound");
    }

    // Getter pro jméno
    public String getName() {
        return name;
    }
}

// Podtřída Dog dědí z třídy Animal
class Dog extends Animal {
    String breed;

    // Konstruktor podtřídy
    public Dog(String name, String breed) {
        super(name); // Volání konstruktoru nadřazené třídy
        this.breed = breed;
    }

    // Přepsání metody makeSound
    @Override
    public void makeSound() {
        super.makeSound(); // Volání metody nadřazené třídy
        System.out.println("Woof Woof");
    }

    // Getter pro plemeno
    public String getBreed() {
        return breed;
    }

    // Metoda, která zobrazuje informace o psovi
    public void displayInfo() {
        System.out.println("Name: " + super.getName()); // Použití super pro přístup k metodě nadřazené třídy
        System.out.println("Breed: " + breed);
    }
}

// Hlavní třída
public class Main {
    public static void main(String[] args) {
        Dog dog = new Dog("Buddy", "Golden Retriever");
        dog.makeSound(); // Volání přepsané metody makeSound
        dog.displayInfo(); // Zobrazení informací o psovi
    }
}
