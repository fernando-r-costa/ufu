package POO.atividade05.estruturas.fila;

public class Fila {
    private int[] elementos;
    private int fimFila;
    private int tamanho;

    public Fila(int tamanho) {
        this.tamanho = tamanho;
        this.elementos = new int[tamanho];
        this.fimFila = -1;
    }

    public boolean isEmpty() {
        return  fimFila == -1;
    }

    public boolean isFull() {
        return fimFila == tamanho - 1;
    }

    public void enfileirar(int info) {
        if (isFull()) {
            System.out.println("Erro: fila cheia!");
        } else {
            fimFila++;
            elementos[fimFila] = info;
            System.out.println(info + " colocado na fila.");
        }
    }

    public int desenfileirar() {
        if (isEmpty()) {
            System.out.println(("Erro: fila vazia!"));
            return -1;
        } else {
            int infoRemovida = elementos[0];

            for (int i = 0; i < fimFila; i++) {
                elementos[i] = elementos[i + 1];
            }

            fimFila--;
            System.out.println(infoRemovida + " retirado da fila.");

            return infoRemovida;
        }
    }

    public void printFila() {
        if (isEmpty()) {
            System.out.println("Fila vazia!");
        } else {
            System.out.println("Fila atual: ");

            for (int i = 0; i <= fimFila; i++) {
                System.out.println(elementos[i]);
            }
        }
    }
    
}