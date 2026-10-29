# Tarefa 7 - Interfaces e Polimorfismo
Aluno: Fernando Rodrigues Costa - 12521BCC029

## Exercício 1 - Expressões

### Expression.java

```java
package POO.atividade07.exercicio1;

public abstract class Expression {
    public abstract int evaluate();
}
```

### Constant.java

```java
package POO.atividade07.exercicio1;

public class Constant extends Expression {
    private int value;

    public Constant(int value) {
        this.value = value;
    }

    public int evaluate() {
        return this.value;
    }

    public String toString() {
        return String.format(" %d ", this.value);
    }
}
```

### Addition.java

```java
package POO.atividade07.exercicio1;

public class Addition extends Expression {
    private final Expression left;
    private final Expression right;

    public Addition(Expression left, Expression right) {
        this.left = left;
        this.right = right;
    }

    public int evaluate() {
        return this.left.evaluate() +
               this.right.evaluate();
    }

    public String toString() {
        return String.format(" (%s + %s) ",
                             this.left, this.right);
    }
}
```

### Subtraction.java

```java
package POO.atividade07.exercicio1;

public class Subtraction extends Expression {
    private final Expression left;
    private final Expression right;

    public Subtraction(Expression left, Expression right) {
        this.left = left;
        this.right = right;
    }

    public int evaluate() {
        return this.left.evaluate() - this.right.evaluate();
    }

    public String toString() {
        return String.format(" (%s - %s) ", this.left, this.right);
    }
}
```

### Multiplication.java

```java
package POO.atividade07.exercicio1;

public class Multiplication extends Expression {
    private final Expression left;
    private final Expression right;

    public Multiplication(Expression left, Expression right) {
        this.left = left;
        this.right = right;
    }

    public int evaluate() {
        return this.left.evaluate() * this.right.evaluate();
    }

    public String toString() {
        return String.format(" (%s * %s) ", this.left, this.right);
    }
}
```

### Division.java

```java
package POO.atividade07.exercicio1;

public class Division extends Expression {
    private final Expression left;
    private final Expression right;

    public Division(Expression left, Expression right) {
        this.left = left;
        this.right = right;
    }

    public int evaluate() {
        return this.left.evaluate() / this.right.evaluate();
    }

    public String toString() {
        return String.format(" (%s / %s) ", this.left, this.right);
    }
}
```

### Negative.java

```java
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
```

### Main.java

```java
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
```

## Execução

[INSERIR PRINT DA EXECUÇÃO DO EXERCÍCIO 1]

## Exercício 2 - Notificações

### Notificador.java

```java
package POO.atividade07.exercicio2;

public interface Notificador {
    void enviar(String mensagem);
}
```

### NotificadorEmail.java

```java
package POO.atividade07.exercicio2;

public class NotificadorEmail implements Notificador {
    @Override
    public void enviar(String mensagem) {
        System.out.println("Enviando e-mail: " + mensagem);
    }
}
```

### NotificadorSMS.java

```java
package POO.atividade07.exercicio2;

public class NotificadorSMS implements Notificador {
    @Override
    public void enviar(String mensagem) {
        System.out.println("Enviando SMS: " + mensagem);
    }
}
```

### NotificadorPush.java

```java
package POO.atividade07.exercicio2;

public class NotificadorPush implements Notificador {
    @Override
    public void enviar(String mensagem) {
        System.out.println("Enviando push notification: " + mensagem);
    }
}
```

### ServicoAlerta.java

```java
package POO.atividade07.exercicio2;

public class ServicoAlerta {
    private Notificador notificador;

    public ServicoAlerta(Notificador notificador) {
        this.notificador = notificador;
    }

    public void alertaCritico(String mensagem) {
        notificador.enviar("Alerta Crítico: " + mensagem);
    }
}
```

### Main.java

```java
package POO.atividade07.exercicio2;

public class Main {
    public static void main(String[] args) {
        ServicoAlerta alertaEmail =
            new ServicoAlerta(new NotificadorEmail());
        ServicoAlerta alertaSMS =
            new ServicoAlerta(new NotificadorSMS());
        ServicoAlerta alertaPush =
            new ServicoAlerta(new NotificadorPush());

        alertaEmail.alertaCritico("Falha no servidor principal.");
        alertaSMS.alertaCritico("Acesso suspeito detectado.");
        alertaPush.alertaCritico("Nova atualização disponível.");
    }
}
```

## Execução

[INSERIR PRINT DA EXECUÇÃO DO EXERCÍCIO 2]
