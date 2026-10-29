package POO.atividade07.exercicio2;

public class NotificadorEmail implements Notificador {
    @Override
    public void enviar(String mensagem) {
        System.out.println("Enviando e-mail: " + mensagem);
    }
}
