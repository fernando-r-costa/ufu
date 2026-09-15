public class Main {
	public static void main(String[] args) {
		
		Pessoa p = new Pessoa();
		p.nome = "Fernando";
		p.peso = 78.0;
		p.altura = 1.70;

		Pessoa p2 = new Pessoa();
		p2.nome = "José";
		p2.peso = 98.0;
		p2.altura = 1.90;

		System.out.println("O IMC de " + p.nome + " é: " + p.calcularIMC());
		System.out.println("O IMC de " + p2.nome + " é: " + p2.calcularIMC());

		Pessoa maisObesa = p.compararIMC(p2);
		System.out.println("A pessoa mais obesa é: " + maisObesa.nome);
	}
}
