package POO.atividade02;

public class Main {
    public static void main(String[] args) {
        
        // Cria 2 contas correntes diferentes
        ContaCorrente contaComum = new ContaCorrente();
        contaComum.setNomeCliente("José");
        contaComum.setEspecial(false);

        ContaCorrente contaEspecial = new ContaCorrente();
        contaEspecial.setNomeCliente("Fernando");
        contaEspecial.setEspecial(true);

        // Depósitos
        System.out.println("--- Depósitos ---");
        contaComum.depositar(100.00);
        System.out.println("Depósito de R$ 100,00 realizado na conta de " + contaComum.getNomeCliente());
        contaEspecial.depositar(100.00);
        System.out.println("Depósito de R$ 100,00 realizado na conta de " + contaEspecial.getNomeCliente());

        // Retirada (Testando a regra do saldo negativo)
        System.out.println("\n--- Retirada ---");
        // Conta comum falha
        boolean sacaComum = contaComum.retirar(150.00);
        System.out.println("Retirada de R$ 150,00 na conta de " + contaComum.getNomeCliente() + ": " + (sacaComum ? "Sucesso" : "Negada"));
        
        // Conta especial consegue negativar
        boolean sacaEspecial = contaEspecial.retirar(150.00);
        System.out.println("Retirada de R$ 150,00 na conta de " + contaEspecial.getNomeCliente() + ": " + (sacaEspecial ? "Sucesso" : "Negada"));
        System.out.println("O saldo da conta de " + contaEspecial.getNomeCliente() + " é de: " + contaEspecial.getSaldo());

        // Transferência (Testando a regra do saldo negativo)
        System.out.println("\n--- Transferência ---");
        // Conta comum tenta falha
        boolean transfereComum = contaComum.transferir(200.00, contaEspecial);
        System.out.println("Transferir R$ 200,00 da conta de " + contaComum.getNomeCliente() + ": " + (transfereComum ? "Sucesso" : "Negada"));

        // Conta especial transfere
        boolean transfereEspecial = contaEspecial.transferir(100.00, contaComum);
        System.out.println("Transferir R$ 100,00 da conta de " + contaEspecial.getNomeCliente() + ": " + (transfereEspecial ? "Sucesso" : "Negada"));

        System.out.println("\n--- Saldos Finais ---");
        System.out.println("Saldo da conta de " + contaComum.getNomeCliente() + ": R$ " + contaComum.getSaldo());
        System.out.println("Saldo da conta de " + contaEspecial.getNomeCliente() + ": R$ " + contaEspecial.getSaldo());
    }
}