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