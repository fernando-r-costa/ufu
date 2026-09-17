package POO.atividade02;

public class ContaCorrente {

    // Dados da conta corrente
    String nomeCliente;
    double saldo;
    boolean especial;

    // Métodos dos dados da conta corrente
    String getNomeCliente() {
        return nomeCliente;
    }

    void setNomeCliente(String nomeCliente) {
        this.nomeCliente = nomeCliente;
    }

    double getSaldo() {
        return saldo;
    }

    void setSaldo(double saldo) {
        this.saldo = saldo;
    }

    boolean isEspecial() {
        return especial;
    }

    void setEspecial(boolean especial) {
        this.especial = especial;
    }

    // Métodos das ações na conta corrente
    void depositar(double valor) {
        if (valor > 0) {
            saldo = saldo + valor;
        }
    }

    boolean retirar(double valor) {
        if (especial == true || saldo >= valor) {
            saldo = saldo - valor;
            return true;
        }
        return false;
    }

    boolean transferir(double valor, ContaCorrente contaDestino) {
        if (especial == true || saldo >= valor) {
            saldo = saldo - valor;
            contaDestino.depositar(valor);
            return true;
        }
        return false;
    }
    
}
