package POO.atividade04;

public class ContaCorrente {
    // Dados da conta corrente
    Cliente titular;
    double saldo;
    boolean especial;

    //Construtor
    public ContaCorrente(Cliente titular, boolean especial) {
        this.titular = titular;
        this.especial = especial;
        this.saldo = 0.0;
        this.extrato = new String[100];
        this.contador = 0;
    }

    // Extrato
    String[] extrato;
    int contador;

    // Métodos dos dados da conta corrente
    Cliente getTitular() {
        return titular;
    }

    void setTitular(Cliente titular) {
        this.titular = titular;
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
    void registraExtrato(String info) {
        if (contador < 100) {
            extrato[contador] = info;
            contador++;
        }
    }

    void depositar(double valor) {
        if (valor > 0) {
            saldo = saldo + valor;
            registraExtrato("Depósito: + R$ " + valor);
        }
    }

    boolean retirar(double valor) {
        if (especial == true || saldo >= valor) {
            saldo = saldo - valor;
            registraExtrato("Retirada: - R$ " + valor);
            return true;
        }
        return false;
    }

    boolean transferir(double valor, ContaCorrente contaDestino) {
        if (especial == true || saldo >= valor) {
            saldo = saldo - valor;
            contaDestino.depositar(valor);
            registraExtrato("Transferência para a conta de " + contaDestino.titular.nomeCliente + ": - R$ " + valor);
            return true;
        }
        return false;
    }

    void emitirExtrato() {
        System.out.println("\n=== EXTRATO ===");
        System.out.println("Cliente: " + titular.getNomeCliente());
        System.out.println("Endereço: " + titular.getEndereco());
        System.out.println("------------------------");
        
        for (int i = 0; i < contador; i++) {
            System.out.println(extrato[i]);
        }
        
        System.out.println("------------------------");
        System.out.println("Saldo atual: R$ " + saldo);
        System.out.println("========================\n");
    }
    
}
