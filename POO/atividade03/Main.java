package POO.atividade03;

public class Main {
    public static void main(String[] args) {
        
        // Cliente Comum
        Cliente cli1 = new Cliente();
        cli1.setNomeCliente("José");
        cli1.setEndereco("Rua das Flores, 123");

        ContaCorrente contaComum = new ContaCorrente();
        contaComum.setTitular(cli1);
        contaComum.setEspecial(false);

        // Cliente Especial
        Cliente cli2 = new Cliente();
        cli2.setNomeCliente("Fernando");
        cli2.setEndereco("Avenida Principal, 456");

        ContaCorrente contaEspecial = new ContaCorrente();
        contaEspecial.setTitular(cli2);
        contaEspecial.setEspecial(true);

        // Depósitos
        contaComum.depositar(100.00);
        contaEspecial.depositar(100.00);

        // Retiradas
        contaComum.retirar(150.00);
        contaEspecial.retirar(150.00);

        // Transferência do Fernando para o José
        contaEspecial.transferir(100.00, contaComum);

        // Extratos Finais
        contaComum.emitirExtrato();
        contaEspecial.emitirExtrato();
    }
}