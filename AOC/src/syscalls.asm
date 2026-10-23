#programa q exemplifica a entrada e saida padrao
# DDA 18/09/26

.data

	str1: .asciiz "String de exemplo!"
.text

	#le um inteiro
	addi	$v0, $zero, 5
	syscall
	#imprimir o inteiro lido
	add		$a0, $v0, $zero
	addi	$v0, $zero, 1
	syscall
	
	#impressao de strings
	addi	$v0, $zero, 4
	la		$a0, str1
	syscall
	
	

