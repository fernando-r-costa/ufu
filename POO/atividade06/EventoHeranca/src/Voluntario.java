public class Voluntario extends Participante{
    private String atividade;

    public Voluntario(String nome, Evento evento, String atividade) {
        super(nome, evento);
        this.atividade = atividade;
    }

    @Override
    public String getCertificado() {
        return super.getCertificado() + "\nNa atividade de: " + atividade;
    }
    
}
