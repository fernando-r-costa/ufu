package POO.atividadeExtraP1;

public class Loja {
    Produto[] produtos = new Produto[2];

    public Loja(Produto p1, Produto p2) {
        produtos[0] = p1;
        produtos[1] = p2;
    }

    public Produto getProduto(String descricao) {
        for(int i = 0; i < produtos.length; i++) {
            if (produtos[i].descricao.equals(descricao)) {
                return produtos[i];
            }
        }
        
        return null;
    }

    public double vender(String descricao, int qtd) {
        Produto p = getProduto(descricao);
        return p.vender(qtd);
    }

    public void repor(String descricao, int qtd) {
        Produto p = getProduto(descricao);
        p.repor(qtd);
    }

    public int estoque(String descricao) {
        Produto p = getProduto(descricao);
        return p.qtd;
    }

    public void printPrecos() {
        for(int i = 0; i < produtos.length; i++) {
            Produto p = produtos[i];
            System.out.println(p.descricao + " - Valor: " + p.preco);            
        }
    }

    public void printEstoque() {
        for(int i = 0; i < produtos.length; i++) {
            Produto p = produtos[i];
            System.out.println(p.descricao + " - Quantidade: " + p.qtd);            
        }
    }
}
