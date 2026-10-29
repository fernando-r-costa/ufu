package POO.atividade07.exercicio1;

public class Main {
    public static void main(String[] args) {

        Expression soma =
            new Addition(
                new Constant(8),
                new Constant(3)
            );

        Expression multiplicacao =
            new Multiplication(
                new Constant(7),
                new Constant(4)
            );

        Expression negativo =
            new Negative(multiplicacao);

        Expression expressao =
            new Subtraction(soma, negativo);

        System.out.println(expressao);
        System.out.println("Resultado: " + expressao.evaluate());
    }
}
