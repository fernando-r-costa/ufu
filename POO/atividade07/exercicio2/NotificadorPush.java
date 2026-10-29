package POO.atividade07.exercicio2;

public class NotificadorPush implements Notificador {
    @Override
    public void enviar(String mensagem) {
        System.out.println("Enviando push notification: " + mensagem);
    }
}
