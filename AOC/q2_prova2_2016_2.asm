#Questão 2 da prova 2 2016/2

.data
	arr:	.space 84
	
.include "utils.asm"

.text

	addi	$s0, $zero, 42	#armazena o 42
	la	$t0, arr	#ponteiro para array
	
	#for
	addi	$s1, $zero, 1	#i=1
	addi	$s2, $zero, 22	#armazena o 22
FOR1:	slt	$t7, $s1, $s2	#verifica se i < 22
	beq	$t7, $zero, END	#se for igual, termina o programa
	
	#corpo do for
	mul	$t1, $s0, $s1	#42 * i
	sw	$t1, 0($t0)	#armazena o resultado no array arr[i]
	addi	$t0, $t0, 4	#avança o ponteiro
	addi	$s1, $s1, 1	#i++
	
	j	FOR1		#reinicia o for
	
END: 	return0