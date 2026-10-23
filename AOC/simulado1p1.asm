
.include "utils.asm"

.data
    vet:  .space 20
    str1: .asciiz "Digite um numero inteiro: "
    str2: .asciiz "A soma dos positivos eh: "

.text
MAIN:
    la   $s0, vet

    # FOR para ler 5 numeros
    addi $t0, $zero, 0
    addi $t1, $zero, 5

FOR1:
    beq  $t0, $t1, SAI1

    printStr(str1)
    readInt

    sw   $v0, 0($s0)
    addi $s0, $s0, 4
    addi $t0, $t0, 1
    j    FOR1

SAI1:
    # Passa os argumentos
    la   $a0, vet
    addi $a1, $zero, 5

    # Chama a funcao
    jal  SOMA_POSITIVOS

    # Guarda o retorno antes das macros
    add  $s2, $zero, $v0

    # Imprime o resultado
    printStr(str2)
    printIntR($s2)
    newLine

    return0


# FUNCAO SOMA_POSITIVOS
# a0 = endereco inicial do vetor
# a1 = quantidade de elementos
# v0 = soma dos positivos

SOMA_POSITIVOS:
    # Reserva espaco na pilha
    addi $sp, $sp, -8

    # Salva contexto
    sw   $s0, 0($sp)
    sw   $s1, 4($sp)

    # Inicializa variaveis
    add  $s0, $zero, $a0
    add  $s1, $zero, $zero
    addi $t0, $zero, 0

FOR2:
    beq  $t0, $a1, SAI2

    # Le elemento do vetor
    lw   $t2, 0($s0)

    # Testa se elemento > 0
    slt  $t3, $zero, $t2
    beq  $t3, $zero, PROX

    # Acumula numero positivo
    add  $s1, $s1, $t2

PROX:
    # Proximo elemento
    addi $s0, $s0, 4
    addi $t0, $t0, 1
    j    FOR2

SAI2:
    # Retorna a soma
    add  $v0, $zero, $s1

    # Restaura contexto
    lw   $s0, 0($sp)
    lw   $s1, 4($sp)

    # Libera a pilha
    addi $sp, $sp, 8

    # Retorna ao MAIN
    jr   $ra
