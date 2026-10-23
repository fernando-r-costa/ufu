#while.asm

#exemplifica como criar um while


.data
	str1: .asciiz "tick "
	strcr: .asciiz "\n" 


.text

		#c = s0 = 0
		add		$s0, $0, $0
		
WH1:	addi	$at, $zero, 10
		beq		$s0, $at, SAI1 
	
		#corpo do while
		#le um char
		addi	$v0, $zero, 12
		syscall
		add		$s0, $zero, $v0
		
		beq 	$s0, $at, SAI2
		#imprime mensagem
		addi	$v0, $zero, 4
		la		$a0, str1
		syscall	
		
		addi	$v0, $zero, 11
		add		$a0, $zero, $s0
		syscall	
		
		addi	$v0, $zero, 4
		la		$a0, strcr
		syscall		
		#/corpo do while
SAI2:	j	WH1
SAI1: