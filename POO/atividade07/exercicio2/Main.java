package POO.atividade07.exercicio2;

public class Main {
    public static void main(String[] args) {
        ServicoAlerta alertaEmail =
            new ServicoAlerta(new NotificadorEmail());
        ServicoAlerta alertaSMS =
            new ServicoAlerta(new NotificadorSMS());
        ServicoAlerta alertaPush =
            new ServicoAlerta(new NotificadorPush());

        alertaEmail.alertaCritico("Falha no servidor principal.");
        alertaSMS.alertaCritico("Acesso suspeito detectado.");
        alertaPush.alertaCritico("Nova atualização disponível.");
    }
}
