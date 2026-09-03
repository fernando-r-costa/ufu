# 🎓 UFU - Códigos de Disciplinas

Repositório central para armazenamento, organização e versionamento de trabalhos práticos, listas de exercícios e códigos desenvolvidos durante o curso de Ciência da Computação na Universidade Federal de Uberlândia (UFU).

## 📚 Disciplinas

Este repositório está organizado em diretórios modulares, abrangendo as seguintes matérias:

* **PP (Programação Procedimental):** Fundamentos de programação e lógica estruturada em `C`.
* **AED1 (Algoritmos e Estruturas de Dados 1):** Estruturas lineares (listas, pilhas, filas) e alocação dinâmica em `C`.
* **PF (Programação Funcional):** Paradigma funcional, recursão e imutabilidade utilizando `Haskell`.
* **SD (Sistemas Digitais):** Fundamentos de circuitos, portas lógicas e álgebra booleana.
* **AED2 (Algoritmos e Estruturas de Dados 2):** Estruturas não-lineares (árvores, grafos) e ordenação avançada.
* **AOC (Arquitetura e Organização de Computadores):** Interação com hardware e programação de baixo nível em `Assembly`.
* **POO (Programação Orientada a Objetos):** Modelagem de classes, herança e polimorfismo em `Java`.

## 🗂️ Estrutura do Repositório

```text
ufu/
├── AED1/          # Algoritmos e Estruturas de Dados 1
├── AED2/          # Algoritmos e Estruturas de Dados 2
├── AOC/           # Arquitetura e Org. de Computadores
├── PF/            # Programação Funcional
├── POO/           # Programação Orientada a Objetos
├── PP/            # Programação Procedimental
└── SD/            # Sistemas Digitais
```

## 🚀 Como Executar

As instruções de compilação variam de acordo com a linguagem de cada diretório. Exemplos básicos de execução no terminal:

**C (PP, AED1, AED2):**
```bash
gcc main.c -o programa
./programa
```

**Java (POO):**
```bash
javac Arquivo.java
java Arquivo
```

**Haskell (PF):**
```bash
ghc arquivo.hs
./arquivo
```

**Análise de Memória (Valgrind em C):**
```bash
valgrind --leak-check=full ./programa
```

## 👨‍💻 Autor

* **Fernando Costa** - Estudante de Ciência da Computação (UFU)
