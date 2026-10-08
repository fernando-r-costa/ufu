public class Organizador extends Participante {

    public Organizador(String nome, Evento evento) {
        super(nome, evento);
    }

    @Override
    public String getCertificado() {
        return getNome() + " auxiliou na organização do evento: " + getEvento().getNome();
    }

}
