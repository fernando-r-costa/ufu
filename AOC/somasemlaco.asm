

.data
	
	strcCR:	.asciiz "\n"
	str1:	.asciiz "Digite um inteiro: "
	str2:	.asciiz "Menor: "
	str3:	.asciiz "Maior: "
	str4:	.asciiz "Média: "

.text

	#imprimir uma mensagem de leitura de inteiro
	addi	$v0, $zero, 4
	la	$a0, str1
	syscall
	
	#lê o inteiro 1
	addi, 	$v0, $zero, 5
	syscall
	
	#calcula menor
	add	$s0, $zero, $v0	#s0 = menor
	
	#calcula maior
	add	$s1, $zero, $v0	#s1 = maior
	
	#acumular para a media
	add	$s2, $zero, $v0	#s2 = acc
	
	#imprimir uma mensagem de leitura de inteiro
	addi	$v0, $zero, 4
	la	$a0, str1
	syscall
	
	#lê o inteiro 2
	addi	$v0, $zero, 5
	syscall
	
	#calcula menor
	slt	$t7, $v0, $s0
	beq	$t7, $zero, SEG1
	add	$s0, $zero, $v0
SEG1:
	#calcula maior
	slt	$t7, $s1, $v0
	beq	$t7, $zero, SEG2
	add	$s1, $zero, $v0
SEG2:

	#acumular a média
	add $s2, $s2, $v0
	
	#imprimir uma mensagem de leitura de inteiro
	addi	$v0, $zero, 4
	la	$a0, str1
	syscall
	
	#lê o inteiro 3
	addi	$v0, $zero, 5
	syscall
	
	#calcula menor
	slt	$t7, $v0, $s0
	beq	$t7, $zero, SEG3
	add	$s0, $zero, $v0
SEG3:
	#calcula maior
	slt	$t7, $s1, $v0
	beq	$t7, $zero, SEG4
	add	$s1, $zero, $v0
SEG4:

	#acumular a média
	add $s2, $s2, $v0
	
	#imprimir uma mensagem de leitura de inteiro
	addi	$v0, $zero, 4
	la	$a0, str1
	syscall
	
	#lê o inteiro 4
	addi	$v0, $zero, 5
	syscall
	
	#calcula menor
	slt	$t7, $v0, $s0
	beq	$t7, $zero, SEG5
	add	$s0, $zero, $v0
SEG5:
	#calcula maior
	slt	$t7, $s1, $v0
	beq	$t7, $zero, SEG6
	add	$s1, $zero, $v0
SEG6:

	#acumular a média
	add $s2, $s2, $v0
	
	#imprimir uma mensagem de leitura de inteiro
	addi	$v0, $zero, 4
	la	$a0, str1
	syscall
	
	#lê o inteiro 5
	addi	$v0, $zero, 5
	syscall
	
	#calcula menor
	slt	$t7, $v0, $s0
	beq	$t7, $zero, SEG7
	add	$s0, $zero, $v0
SEG7:
	#calcula maior
	slt	$t7, $s1, $v0
	beq	$t7, $zero, SEG8
	add	$s1, $zero, $v0
SEG8:

	#acumular a média
	add $s2, $s2, $v0
	
	#calcular a media
	div $t1, $s2, 5
	
	#mostrar mensagens
	addi	$v0, $zero, 4
	la	$a0, str2
	syscall
	addi	$v0, $zero, 1
	la	$a0, ($s0)
	syscall
	addi	$v0, $zero, 4
	la	$a0, strcCR
	syscall
	addi	$v0, $zero, 4
	la	$a0, str3
	syscall
	addi	$v0, $zero, 1
	la	$a0, ($s1)
	syscall
	addi	$v0, $zero, 4
	la	$a0, strcCR
	syscall
	addi	$v0, $zero, 4
	la	$a0, str4
	syscall
	addi	$v0, $zero, 1
	la	$a0, ($t1)
	syscall