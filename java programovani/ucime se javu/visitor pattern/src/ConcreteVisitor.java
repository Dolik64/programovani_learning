class ConcreteVisitor implements Visitor {
    @Override
    public void visit(ElementA element) {
        System.out.println("Visiting ElementA");
        element.operationA();
    }

    @Override
    public void visit(ElementB element) {
        System.out.println("Visiting ElementB");
        element.operationB();
    }
}

