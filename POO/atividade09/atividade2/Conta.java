package POO.atividade09.atividade2;

public class Conta {

    private double saldo;

    public Conta(double saldoInicial) {
        this.saldo = saldoInicial;
    }

    public void depositar(double valor) {
        if (valor < 0) {
            throw new IllegalArgumentException("O depósito não pode ser negativo.");
        }

        saldo += valor;
    }

    public void sacar(double valor) throws SaldoInsuficienteException {
        if (valor > saldo) {
            throw new SaldoInsuficienteException("Saldo insuficiente para o saque.");
        }

        saldo -= valor;
    }

    public double getSaldo() {
        return saldo;
    }
}