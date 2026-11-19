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