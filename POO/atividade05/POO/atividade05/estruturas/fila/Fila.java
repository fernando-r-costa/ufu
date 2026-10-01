package POO.atividade05.estruturas.fila;

public class Fila {
    private int[] elementos;
    private int finalFila;
    private int tamanho;

    public Fila(int tamanho) {
        this.tamanho = tamanho;
        this.elementos = new int[tamanho];
        this.finalFila = -1;
    }
    
}