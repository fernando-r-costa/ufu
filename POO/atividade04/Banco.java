package POO.atividade04;

public class Banco {
    //Dados do Banco
    ContaCorrente[] contas;
    int totalContas;

    //Construtor
    public Banco() {
        this.contas = new ContaCorrente[100];
        this.totalContas = 0;
    }

    //Métodos
    public void setConta(ContaCorrente novaConta) {
        if(totalContas < contas.length) {
            contas[totalContas] = novaConta;
            totalContas++;
        }
    }

    public ContaCorrente getContaCorrente(String nome) {
        for (int i = 0; i < totalContas; i++) {
            if (contas[i].getTitular().getNomeCliente().equalsIgnoreCase(nome)) {
                return contas[i];
            }
        }
        return null;
    }
}
