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