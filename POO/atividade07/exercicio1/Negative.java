package POO.atividade07.exercicio1;

public class Negative extends Expression {
    private final Expression expression;

    public Negative(Expression expression) {
        this.expression = expression;
    }

    public int evaluate() {
        return -this.expression.evaluate();
    }

    public String toString() {
        return String.format(" (-%s) ", this.expression);
    }
}
