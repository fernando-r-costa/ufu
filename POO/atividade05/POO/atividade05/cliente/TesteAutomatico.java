package POO.atividade05.cliente;

import POO.atividade05.estruturas.fila.Fila;
import POO.atividade05.estruturas.pilha.Pilha;

public class TesteAutomatico {
    public static void main(String[] args) {
        System.out.println("--- Testes automáticos ---\n");

        System.out.println("--- Teste Fila ---");
        Fila fila = new Fila(3);
        fila.enfileirar(10);
        fila.enfileirar(15);
        fila.enfileirar(20);
        fila.printFila();
        fila.enfileirar(30);
        fila.desenfileirar();
        fila.printFila();

        System.out.println("--- Teste Pilha ---");
        Pilha pilha = new Pilha(3);
        pilha.empilhar(10);
        pilha.empilhar(15);
        pilha.empilhar(20);
        pilha.printPilha();
        pilha.empilhar(30);
        pilha.desempilhar();
        pilha.printPilha();

    }
}