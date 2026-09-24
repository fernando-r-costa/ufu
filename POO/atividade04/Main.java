package POO.atividade04;

import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        Banco banco = new Banco();

        // Cliente Comum
        Cliente cli1 = new Cliente("José", "Rua das Flores, 123");
        ContaCorrente contaJose = new ContaCorrente(cli1, false);

        // Cliente Especial
        Cliente cli2 = new Cliente("Fernando", "Avenida Principal, 456");
        ContaCorrente contaFernando = new ContaCorrente(cli2, true);

        banco.setConta(contaJose);
        banco.setConta(contaFernando);

        // Interface com o usuário
        System.out.println("=== BEM-VINDO AO BANCO ===");
        
        boolean menuAtivo = true;
        while (menuAtivo) {
            System.out.println("Digite seu nome para acessar a sua conta: ");
            String nome = scanner.next();
            
            ContaCorrente contaAtual = banco.getContaCorrente(nome);
            
            if (contaAtual == null) {
                System.out.println("Conta não encontrada!");
                continue;
            }

            int opcao = -1;
    
            System.out.println("\nOlá, " + contaAtual.getTitular().getNomeCliente());
            while (opcao != 0) {
                System.out.println("\n=== MENU ===");
                System.out.println("1 - Depositar");
                System.out.println("2 - Sacar");
                System.out.println("3 - Transferir");
                System.out.println("4 - Emitir Extrato");
                System.out.println("0 - Sair");
                System.out.println("\nDigite sua escolha: ");
                opcao = scanner.nextInt();

                if (opcao == 1) {
                    System.out.print("Digite o valor do depósito: R$ ");
                    double valor = scanner.nextDouble();
                    contaAtual.depositar(valor);
                    System.out.println("Depósito realizado com sucesso!");

                } else if (opcao == 2) {
                    System.out.print("Digite o valor do saque: R$ ");
                    double valor = scanner.nextDouble();
                    boolean realizado = contaAtual.retirar(valor);
                    System.out.println(realizado ? "Saque aprovado!" : "Saldo insuficiente.");

                } else if (opcao == 3) {
                    System.out.print("Digite o nome do favorecido: ");
                    String nomeContaDestino = scanner.next();

                    ContaCorrente contaDestino = banco.getContaCorrente(nomeContaDestino);

                    if (contaDestino == null) {
                        System.out.println("Conta de destino não encontrada.");
                    } else {
                        System.out.print("Digite o valor da transferência: R$ ");
                        double valor = scanner.nextDouble();
                        boolean realizado = contaAtual.transferir(valor, contaDestino);
                        System.out.println(realizado ? "Transferência enviada com sucesso!" : "Saldo insuficiente.");
                    }

                } else if (opcao == 4) {
                    contaAtual.emitirExtrato();
                
                } else if (opcao == 0) {
                    menuAtivo = false;
                    break;
                    
                } else if (opcao != 0) {
                    System.out.println("Opção inválida. Tente novamente.");
                }
            }
        }

        scanner.close();
        System.out.println("Sistema encerrado. Obrigado!");
    } 
    
}