#programa q exemplifica a entrada e saída padrão
#18/09/26

.data

	str1: .asciiz "String de exemplo!"

.text

	#lê um inteiro
	addi $v0, $zero, 5
	syscall

	#imprimir o inteiro lido
	add $a0, $v0, $zero
	addi $v0, $zero, 1
	syscall
    
	#impressão de strings
	addi    $v0, $zero, 4
	la      $a0, str1
	syscall
    
    
    