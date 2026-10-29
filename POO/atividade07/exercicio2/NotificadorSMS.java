package POO.atividade07.exercicio2;

public class NotificadorSMS implements Notificador {
    @Override
    public void enviar(String mensagem) {
        System.out.println("Enviando SMS: " + mensagem);
    }
}
