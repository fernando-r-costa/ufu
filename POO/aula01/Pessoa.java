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
}