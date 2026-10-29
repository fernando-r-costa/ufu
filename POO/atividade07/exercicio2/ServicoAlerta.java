package POO.atividade07.exercicio2;

public class ServicoAlerta {
    private Notificador notificador;

    public ServicoAlerta(Notificador notificador) {
        this.notificador = notificador;
    }

    public void alertaCritico(String mensagem) {
        notificador.enviar("Alerta Crítico: " + mensagem);
    }
}
