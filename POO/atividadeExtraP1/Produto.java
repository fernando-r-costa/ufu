package POO.atividadeExtraP1;

public class Produto {
    String descricao;
    int qtd;
    double preco;
    
    public Produto(String descricao, int quantidade, double preco) {
        this.descricao = descricao;
        this.qtd = quantidade;
        this.preco = preco;
    }

    public double vender(int q) {
        qtd -= q;
        return q * preco;
    }

    public void repor(int q) {
        qtd += q;
    }
}
