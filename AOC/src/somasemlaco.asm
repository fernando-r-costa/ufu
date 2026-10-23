

.data
	strCR: .asciiz "\n"
	str1: .asciiz "Digite um inteiro: "

.text

	#imprimir uma mensagem de leitura de inteiro
	addi	$v0, $zero, 4
	la		$a0, str1
	syscall
	
	#le o inteiro 1
	addi	$v0, $0, 5
	syscall
	
	#calcular menor
	add	$s0, $zero, $v0		#onde s0 = menor
	#calcular maior
	add	$s1, $zero, $v0		#onde s1 = maior
	#acumular para a media
	add	$s2, $zero, $v0		#onde s2 = acc
	
	#le o inteiro 2
	addi	$v0, $zero, 4
	la		$a0, str1
	syscall
	
	addi	$v0, $0, 5
	syscall
	
	#calcular menor
	slt	$t7, $v0, $s0
	beq $t7, $zero, SEG1
	add	$s0, $zero, $v0 #addi $s0, $v0, 0
SEG1:	
	#calcular maior
	slt	$t7, $s1, $v0
	beq $t7, $zero, SEG2
	add	$s1, $zero, $v0
SEG2:
	#calcular a media
	add	$s2, $s2, $v0

	#le o inteiro 3
	addi	$v0, $zero, 4
	la		$a0, str1
	syscall
	
	#le o inteiro 1
	addi	$v0, $0, 5
	syscall
	
	#calcular menor
	slt	$t7, $v0, $s0
	beq $t7, $zero, SEG3
	add	$s0, $zero, $v0 #addi $s0, $v0, 0
SEG3:	
	#calcular maior
	slt	$t7, $s1, $v0
	beq $t7, $zero, SEG4
	add	$s1, $zero, $v0
SEG4:
	#calcular a media
	add	$s2, $s2, $v0

#le o inteiro 4
	addi	$v0, $zero, 4
	la		$a0, str1
	syscall
	
	#le o inteiro 1
	addi	$v0, $0, 5
	syscall
	
	#calcular menor
	slt	$t7, $v0, $s0
	beq $t7, $zero, SEG5
	add	$s0, $zero, $v0 #addi $s0, $v0, 0
SEG5:	
	#calcular maior
	slt	$t7, $s1, $v0
	beq $t7, $zero, SEG6
	add	$s1, $zero, $v0
SEG6:
	#calcular a media
	add	$s2, $s2, $v0

#le o inteiro 5
	addi	$v0, $zero, 4
	la		$a0, str1
	syscall
	
	#le o inteiro 1
	addi	$v0, $0, 5
	syscall
	
	#calcular menor
	slt	$t7, $v0, $s0
	beq $t7, $zero, SEG7
	add	$s0, $zero, $v0 #addi $s0, $v0, 0
SEG7:	
	#calcular maior
	slt	$t7, $s1, $v0
	beq $t7, $zero, SEG8
	add	$s1, $zero, $v0
SEG8:
	#calcular a media
	add	$s2, $s2, $v0

	#calcular a media e mostrar mensagens
	div	$t1, $s2, 5
