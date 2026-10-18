package POO.atividadeExtraP1;

public class Teste {
    public static void main(String[] args) {
        Produto p1 = new Produto("bola", 20, 25.00);
        Produto p2 = new Produto("tênis", 10, 100.00);
        Loja l = new Loja(p1, p2);
        
        l.vender("bola", 10);
        l.vender("tênis", 3);
    
        l.repor("bola", 5);
    
        l.printEstoque();
        
    }
}
