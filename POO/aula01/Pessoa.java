public class Pessoa {
    
    // Atributos de pessoa
    String nome;
    double peso;
    double altura;

    // Métodos para pessoa
    public double calcularIMC() {
        
        double imc = peso / (altura * altura);
        
        return imc; 
    }

    // Compara IMCs
    public Pessoa compararIMC(Pessoa outraP) {

        double imc1 = this.calcularIMC();
        double imc2 = outraP.calcularIMC();

        if (imc1 < imc2) {
            return outraP;
        } else {
            return this;
        }
    }
}