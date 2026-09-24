package POO.atividade04;

public class Cliente {
    // Dados do cliente
    String nomeCliente;
    String endereco;

    //Construtor
    public Cliente(String nomeCliente, String endereco) {
        this.nomeCliente = nomeCliente;
        this.endereco = endereco;
    }

    // Métodos dos dados do cliente
    String getNomeCliente() {
        return nomeCliente;
    }

    void setNomeCliente(String nomeCliente) {
        this.nomeCliente = nomeCliente;
    }

    String getEndereco() {
        return endereco;
    }

    void setEndereco(String endereco) {
        this.endereco = endereco;
    }

}
