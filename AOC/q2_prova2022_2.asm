#Questão 2 da prova 2022/2

.include "utils.asm"

.data
	str1:	.asciiz "Digite um número inteiro: "
	str2:	.asciiz "O valor de Y é: "

.text
	
WH1:	printStr(str1)	#macro imprime string 1

	#ler inteiro
	#addi	$v0, $zero, 5
	#syscall
	readInt
	
	#testa se é zero	
	beq	$v0, $zero, SAI1
	add	$s0, $zero, $v0
	
	#calcula a equação
	#calcula x.x
	mul	$t1, $s0, $s0
	#calculo 42.x
	addi	$t7, $zero, 42
	mul	$t2, $s0, $t7
	#somatório da equação
	add	$t0, $t1, $t2
	addi	$t0, $t0, -42
	
	printStr(str2) #macro imprime string 2
	printIntR($t0) #macro imprime o inteiro resultante da equação
	newLine
	
	j	WH1
	
SAI1:	return0 #macro que finaliza o programa
