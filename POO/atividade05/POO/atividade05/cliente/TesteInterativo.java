package POO.atividade05.cliente;

import POO.atividade05.estruturas.pilha.Pilha;
import java.util.Scanner;

public class TesteInterativo {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        System.out.println("--- Teste interativo da Pilha ---");

        System.out.println("Digite o tamanho da pilha: ");
        int tamanho = scanner.nextInt();

        Pilha pilha = new Pilha(tamanho);
        int opcao = -1;

        while (opcao != 0) {
            System.out.println("\n--- MENU ---");
            System.out.println("1 - Empilhar info");
            System.out.println("2 - Desempilhar info");
            System.out.println("3 - Mostrar Pilha");
            System.out.println("0 - Sair");
            System.out.print("\nSua escolha: ");
            opcao = scanner.nextInt();

            if (opcao == 1) {
                System.out.println("Digite o número: ");
                int info = scanner.nextInt();
                pilha.empilhar(info);
            } else if (opcao == 2) {
                pilha.desempilhar();
            } else if (opcao == 3) {
                pilha.printPilha();
            } else if (opcao == 0) {
                System.out.println("Saindo...");
            } else {
                System.out.println("Opção inválida.");
            }
        }
        scanner.close();
    }
}