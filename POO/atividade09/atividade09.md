# Tarefa 09 - Tratamento de Exceções
Aluno: Fernando Rodrigues Costa - 12521BCC029

## Atividade 1 - Validação de Pilha

### PilhaVaziaException.java

```java
package POO.atividade09.atividade1;

public class PilhaVaziaException extends Exception {

    public PilhaVaziaException() {
        super();
    }
}
```

### Pilha.java

```java
package POO.atividade09.atividade1;

import java.util.ArrayList;

public class Pilha {

    private ArrayList<Integer> itens = new ArrayList<>();

    public void push(int valor) {
        itens.add(valor);
    }

    public int pop() throws PilhaVaziaException {
        if (empty()) {
            throw new PilhaVaziaException();
        }

        return itens.remove(itens.size() - 1);
    }

    public int top() throws PilhaVaziaException {
        if (empty()) {
            throw new PilhaVaziaException();
        }

        return itens.get(itens.size() - 1);
    }

    public boolean empty() {
        return itens.isEmpty();
    }
}
```

### TestePilha.java

```java
package POO.atividade09.atividade1;

public class TestePilha {

    public static void main(String[] args) {
        Pilha pilha = new Pilha();

        pilha.push(10);
        pilha.push(20);

        try {
            System.out.println("Topo da pilha: " + pilha.top());
            System.out.println("Removido da pilha: " + pilha.pop());
            System.out.println("Removido da pilha: " + pilha.pop());
            System.out.println("Removido da pilha: " + pilha.pop());
        } catch (PilhaVaziaException e) {
            System.out.println("Erro: pilha vazia, não foi possível remover o item.");
        }
    }
}
```

## Execução

[INSERIR PRINT DA PILHA VAZIA]

## Atividade 2 - Conta Bancária

### SaldoInsuficienteException.java

```java
package POO.atividade09.atividade2;

public class SaldoInsuficienteException extends Exception {

    public SaldoInsuficienteException(String mensagem) {
        super(mensagem);
    }
}
```

### Conta.java

```java
package POO.atividade09.atividade2;

public class Conta {

    private double saldo;

    public Conta(double saldoInicial) {
        this.saldo = saldoInicial;
    }

    public void depositar(double valor) {
        if (valor < 0) {
            throw new IllegalArgumentException("O depósito não pode ser negativo.");
        }

        saldo += valor;
    }

    public void sacar(double valor) throws SaldoInsuficienteException {
        if (valor > saldo) {
            throw new SaldoInsuficienteException("Saldo insuficiente para o saque.");
        }

        saldo -= valor;
    }

    public double getSaldo() {
        return saldo;
    }
}
```

### ProgramaConta.java

```java
package POO.atividade09.atividade2;

import java.util.Scanner;

public class ProgramaConta {

    public static void main(String[] args) {

        Scanner scanner = new Scanner(System.in);
        Conta conta = new Conta(1000.00);

        System.out.println("Saldo inicial: R$ " + conta.getSaldo());

        System.out.print("Digite o valor do depósito: ");
        double deposito = scanner.nextDouble();

        try {
            conta.depositar(deposito);
            System.out.println("Depósito realizado com sucesso.");
        } catch (IllegalArgumentException e) {
            System.out.println("Erro: " + e.getMessage());
        }

        System.out.print("Digite o valor do saque: ");
        double saque = scanner.nextDouble();

        try {
            conta.sacar(saque);
            System.out.println("Saque realizado com sucesso.");
        } catch (SaldoInsuficienteException e) {
            System.out.println("Erro: " + e.getMessage());
        }

        System.out.println("Saldo final: R$ " + conta.getSaldo());

        scanner.close();
    }
}
```

## Execuções

[INSERIR PRINT DAS OPERAÇÕES VÁLIDAS]

[INSERIR PRINT DO DEPÓSITO NEGATIVO]

[INSERIR PRINT DO SALDO INSUFICIENTE]
