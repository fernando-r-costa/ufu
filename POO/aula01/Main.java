public class Main {
	public static void main(String[] args) {
		
		Pessoa p = new Pessoa();

		p.nome = "Fernando";
		p.peso = 78.0;
		p.altura = 1.70;

		System.out.println("O IMC de " + p.nome + " é: " + p.calcularIMC());

	}
}
