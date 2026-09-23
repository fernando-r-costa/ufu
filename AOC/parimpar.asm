#desc: testa se um num. lido do teclado eh par ou impar

.data

	l1:	.asciiz "digite um numero: "
	lcr:	.asciiz "/n"
	lpar:	.asciiz "o num lido eh par"
	limpar:	.asciiz "o num lido eh impar"

.text
	
	#mostrar a msg para ler inteiro
	addi	$v0, $zero, 4
	la	$a0, l1
	syscall
	
	#ler um inteiro
	addi	$v0, $zero, 5	#li $vo, 5
	syscall
	
	add	$s0, $v0, $zero	#move o num para s0
	
	#testa se eh par ou impar
	andi	$t1, $s0, 0x01
	beq	$t1, $zero, PAR
	
	#o num eh impar
	addi	$v0, $zero, 4
	la	$a0, limpar
	syscall
	j	SAI
	
PAR:
	addi	$v0, $zero, 4
	la	$a0, lpar
	syscall
SAI: