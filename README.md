# 🎓 UFU - Códigos de Disciplinas

Repositório central para armazenamento, organização e versionamento de trabalhos práticos, listas de exercícios e códigos desenvolvidos durante o curso de Ciência da Computação na Universidade Federal de Uberlândia (UFU).

## 📚 Disciplinas

Este repositório está organizado em diretórios modulares, abrangendo as seguintes matérias:

- **PP (Programação Procedimental):** Fundamentos de programação e lógica estruturada em `C`.
- **AED1 (Algoritmos e Estruturas de Dados 1):** Estruturas lineares, como listas, pilhas e filas, além de alocação dinâmica em `C`.
- **PF (Programação Funcional):** Paradigma funcional, recursão, funções de ordem superior e imutabilidade utilizando `Haskell`.
- **SD (Sistemas Digitais):** Fundamentos de circuitos digitais, portas lógicas, álgebra booleana e sistemas combinacionais e sequenciais.
- **AED2 (Algoritmos e Estruturas de Dados 2):** Estruturas não lineares, árvores, grafos e algoritmos de ordenação e busca utilizando `C`.
- **AOC (Arquitetura e Organização de Computadores):** Arquitetura de processadores, memória, representação de dados e programação de baixo nível, incluindo `Assembly`.
- **POO (Programação Orientada a Objetos):** Modelagem orientada a objetos, classes, encapsulamento, herança, polimorfismo e interfaces utilizando `Java`.

## 🗂️ Estrutura do Repositório

```text
ufu/
├── AED1/          # Algoritmos e Estruturas de Dados 1
├── AED2/          # Algoritmos e Estruturas de Dados 2
├── AOC/           # Arquitetura e Organização de Computadores
├── PF/            # Programação Funcional
├── POO/           # Programação Orientada a Objetos
├── PP/            # Programação Procedimental
└── SD/            # Sistemas Digitais
```

## 🚀 Como Executar

As instruções de compilação e execução variam de acordo com a linguagem utilizada em cada disciplina.

### C — PP, AED1 e AED2

Compilação:

```bash
gcc main.c -o programa
```

Execução:

```bash
./programa
```

Para habilitar avisos adicionais do compilador:

```bash
gcc -Wall -Wextra -pedantic main.c -o programa
```

### Java — POO

Compilação:

```bash
javac Arquivo.java
```

Execução:

```bash
java Arquivo
```

### Haskell — PF

Compilação:

```bash
ghc arquivo.hs -o programa
```

Execução:

```bash
./programa
```

Também é possível utilizar o interpretador interativo:

```bash
ghci arquivo.hs
```

### Assembly — AOC

A forma de montagem e execução dependerá da arquitetura, montador e ferramentas adotadas durante a disciplina.

As instruções específicas serão adicionadas ao diretório `AOC/` conforme o conteúdo da disciplina avançar.

## 🔍 Análise de Memória em C

Para verificar vazamentos de memória com o Valgrind:

```bash
valgrind --leak-check=full ./programa
```

Para uma análise mais detalhada:

```bash
valgrind --leak-check=full --show-leak-kinds=all ./programa
```

## 🛠️ Ambiente de Desenvolvimento

O repositório pode ser utilizado através do **GitHub Codespaces**, permitindo compilar e executar os códigos em ambiente Linux sem depender da configuração local da máquina.

Ferramentas utilizadas ao longo das disciplinas:

- GCC
- GHC / GHCi
- Java Development Kit (JDK)
- Valgrind
- Ferramentas de Assembly definidas durante AOC

## 👨‍💻 Autor

**Fernando Costa**  
Estudante de Ciência da Computação — Universidade Federal de Uberlândia (UFU)