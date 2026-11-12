# Tarefa 08 - Agenda com GUI

Aluno: Fernando Rodrigues Costa - 12521BCC029

## Contato.java

```java
package POO.atividade08;

public class Contato {
    String nome;
    String telefone;
    String endereco;

    public Contato(String nome, String telefone, String endereco) {
        this.nome = nome;
        this.telefone = telefone;
        this.endereco = endereco;
    }

}
```

## AgendaGUI.java

```java
package POO.atividade08;

import javax.swing.*;
import java.util.ArrayList;
import java.awt.GridLayout;

public class AgendaGUI {
    JFrame janela = new JFrame("Agenda Telefônica");

    JTextField campoNome = new JTextField(18);
    JTextField campoTelefone = new JTextField(18);
    JTextField campoEndereco = new JTextField(18);

    JButton botaoCadastrar = new JButton("Cadastrar");

    JPanel painel = new JPanel(new GridLayout(4, 2, 5, 5));

    public AgendaGUI() {
        janela.setSize(400, 220);
        janela.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);

        painel.add(new JLabel("Nome: "));
        painel.add(campoNome);

        painel.add(new JLabel("Telefone: "));
        painel.add(campoTelefone);

        painel.add(new JLabel("Endereço: "));
        painel.add(campoEndereco);

        painel.add(new JLabel(" "));
        painel.add(botaoCadastrar);

        JPanel painelExterno = new JPanel();
        painelExterno.add(painel);
        janela.add(painelExterno);
        janela.setLocationRelativeTo(null);

        botaoCadastrar.addActionListener(e -> {
            String nome = campoNome.getText();
            String telefone = campoTelefone.getText();
            String endereco = campoEndereco.getText();

            Contato contato = new Contato(nome, telefone, endereco);
            contatos.add(contato);

            System.out.println("Agenda de contatos: ");
            for (Contato c : contatos) {
                System.out.println(c.nome + " - " + c.telefone + " - " + c.endereco);
            }
        });

        janela.setVisible(true);

    }

    ArrayList<Contato> contatos = new ArrayList<>();

    public static void main(String[] args) {
        new AgendaGUI();
    }

}
```

## Execução

[INSERIR PRINT DA EXECUÇÃO]
