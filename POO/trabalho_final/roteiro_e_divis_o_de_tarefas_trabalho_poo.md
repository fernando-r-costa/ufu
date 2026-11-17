# ROTEIRO PASSO A PASSO E DIVISÃO DE TAREFAS
## Trabalho Final de Programação Orientada a Objetos – Sistema de Locação de Eventos

---

## 1. ARQUITETURA E ESTRUTURA DE PACOTES (≥ 10 Classes)

Para atender a todos os requisitos de POO e organização exigidos pelo professor, o projeto está estruturado em quatro pacotes distintos:

### Pacote `model` (Entidades e Regras de Domínio)
1. **`Equipamento`** (Classe abstrata base: atributos comuns como código, descrição, valor diária, disponibilidade, e o método abstrato `calcularDiaria`).
2. **`EquipamentoSom`** (Herda de `Equipamento`: atributos específicos como potência em watts e quantidade de canais de áudio).
3. **`EquipamentoIluminacao`** (Herda de `Equipamento`: atributos específicos como tipo de iluminação e potência em watts).
4. **`EquipamentoProjecao`** (Herda de `Equipamento`: atributos específicos como resolução e luminosidade em lúmens).
5. **`Cliente`** (Atributos: identificação/CPF, nome, telefone e e-mail).
6. **`Locacao`** (Atributos: ID da locação, cliente, lista de equipamentos, quantidade de dias, status ativa/devolvida e cálculo do valor total).

### Pacote `exception` (Tratamento de Erros)
7. **`EquipamentoIndisponivelException`** (Exceção customizada lançada quando um item já se encontra alugado).
8. **`EquipamentoDuplicadoException`** (Exceção customizada lançada ao tentar inserir o mesmo equipamento duas vezes na mesma locação).
9. **`EntidadeNaoEncontradaException`** (Exceção customizada para buscas inválidas de códigos de equipamentos ou clientes).

### Pacote `service` (Regras de Negócio e Gerenciamento em Memória)
10. **`SistemaLocacao`** (Controla os `ArrayList` de equipamentos, clientes e histórico de locações, aplicando as regras de negócio sem utilizar atributos ou métodos estáticos).

### Pacote `ui` (Interface com o Usuário)
11. **`Main`** (Classe executável contendo o método `main` e um menu interativo via console utilizando `Scanner` e tratamento de exceções com blocos `try-catch`).

---

## 2. O CORAÇÃO DO POLIMORFISMO (Cálculo de Diárias)

Na classe abstrata `Equipamento`, o contrato polimórfico é definido como:
```java
public abstract double calcularDiaria(int quantidadeDias);
```

As regras de sobrescrita (`@Override`) em cada subclasse são:
- **Som:** `valorDiaria * quantidadeDias`
- **Iluminação:** `(valorDiaria * quantidadeDias) * 1.10` (Acréscimo obrigatório de 10%)
- **Projeção:** `valorDiaria * quantidadeDias` (Aplicando desconto de 10% se `quantidadeDias >= 5`)

---

## 3. DIVISÃO DE TAREFAS PARA A DUPLA

Para otimizar o tempo e permitir o desenvolvimento paralelo sem conflitos de código, dividimos as responsabilidades em duas frentes equivalentes:

### **Integrante A: Camada de Modelos e Exceções (`model` e `exception`)**
* **Foco:** Estruturação das entidades, aplicação rigída de herança, encapsulamento e polimorfismo, além das exceções personalizadas.
* **Passo a passo das tarefas:**
  1. Criar as três classes de exceção no pacote `exception` estendendo `RuntimeException`.
  2. Implementar a classe abstrata `Equipamento` com getters, setters e o método abstrato `calcularDiaria`.
  3. Criar as subclasses `EquipamentoSom`, `EquipamentoIluminacao` e `EquipamentoProjecao`, implementando em cada uma o cálculo polimórfico específico.
  4. Criar a classe `Cliente` com construtor e encapsulamento adequado.
  5. Criar a classe `Locacao`, associando um `Cliente`, uma `ArrayList<Equipamento>` e somando o valor total chamando o método polimórfico de cada equipamento.

### **Integrante B: Camada de Serviço e Interface (`service` e `ui`)**
* **Foco:** Gerenciamento das coleções em memória, validações das regras de negócio e interface textual para o usuário.
* **Passo a passo das tarefas:**
  1. Criar a classe `SistemaLocacao` no pacote `service` contendo as listas (`ArrayList`) para armazenar equipamentos, clientes e locações.
  2. Implementar os métodos de cadastro, listagens, busca por código e verificação de disponibilidade.
  3. Implementar o registro de locação garantindo o lançamento das exceções personalizadas (caso o item esteja indisponível ou duplicado) e o registro da devolução (liberando os equipamentos).
  4. Criar a classe `Main` no pacote `ui` contendo o loop do menu em console, capturando entradas via `Scanner` e envolvendo as chamadas em blocos `try-catch` para exibir mensagens amigáveis.

---

## 4. CRONOGRAMA DE INTEGRAÇÃO RÁPIDA

1. **Alinhamento Inicial (15 min):** A dupla revisa os nomes exatos das classes e a assinatura do método `calcularDiaria` para garantir total compatibilidade.
2. **Desenvolvimento Paralelo:** Integrante A desenvolve o pacote `model` e `exception`; Integrante B desenvolve o `service` e o `ui`.
3. **Integração (20 min):** Unir os pacotes no projeto, ajustar chamadas de métodos e realizar os testes práticos de validação de regras (como alugar o mesmo item duas vezes e verificar se a exceção dispara corretamente).