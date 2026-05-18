public class Main {
    public static void main(String[] args) {
        Element[] elements = new Element[] { new ElementA(), new ElementB() };
        Visitor visitor = new ConcreteVisitor();

        for (Element element : elements) {
            element.accept(visitor);
        }
    }
}
