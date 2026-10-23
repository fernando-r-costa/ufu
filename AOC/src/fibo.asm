#fibo.asm
# DDA 30/09/2026

.include "utils.asm"

.data
	str1: .asciiz	"Digite o indice de fibonacci a ser calculado: "
	str2: .asciiz	"O numero "
	str3: .asciiz   " nao é um indice valido de fibonacci" 
	str4: .asciiz   "O num. de Fibonacci na posicao "
	str5: .asciiz   " é igual a "
.text
	#init algumas vars
	addi	$s0, $zero, 1	#antnt
	addi	$s1, $zero, 1	#ant
	
	#le o n 
TA:	printStr(str1)
	readInt
	add	$s7, $zero, $v0		#move o int lido para s7
	
	#testa se n <=0 eq n < 1	 
	slti	$t0, $s7, 1
	beq		$t0, $zero, CONTINUE1
	#corpo do if
	printStr(str2)
	printIntR($s7)
	printStr(str3)
	newLine
	j	TA
	#return0
	#/corpo do if

CONTINUE1:
	#testa se n == 1 ou 2
	slti	$t0, $s7, 3
	beq		$t0, $zero, CONTINUE2
	#corpo do if
	printStr(str4)
	printIntR($s7)
	printStr(str5)
	printInt(1)
	#/corpo do if
	
CONTINUE2:

	return0	