package POO.atividade05.estruturas.pilha;

public class Pilha {
    private int[] elementos;
    private int topo;
    private int tamanho;

    public Pilha(int tamanho) {
        this.tamanho = tamanho;
        this.elementos = new int[tamanho];
        this.topo = -1;
    }
    
    public boolean isEmpty() {
        return topo == -1;
    }

    public boolean isFull() {
        return topo == tamanho - 1;
    }

    public void empilhar(int info) {
        if (isFull()) {
            System.out.println("Erro: pilha cheia!");
        } else {
            topo++;
            elementos[topo] = info;
            System.out.println(info + " colocado na pilha.");
        }
    }

    public int desempilhar() {
        if (isEmpty()) {
            System.out.println(("Erro: pilha vazia!"));
            return -1;
        } else {
            int infoRemovida = elementos[topo];

            topo--;
            System.out.println(infoRemovida + " retirado da pilha.");

            return infoRemovida;
        }
    }

    public void printPilha() {
        if (isEmpty()) {
            System.out.println("Pilha vazia!");
        } else {
            System.out.println("Pilha atual: ");

            for (int i = topo; i >= 0; i--) {
                System.out.println(elementos[i]);
            }
        }
    }
}