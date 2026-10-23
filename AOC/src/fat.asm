

.include "utils.asm"
.data


.text
	addi	$s0, $zero, 5	#n = 5
	
	#passo1 argumentos
	add		$a0, $zero, $s0
	#passo2
	jal		FAT
	add		$s0,$v0, $zero
	printIntR($s0)
	
	return0
	
FAT:
	#passo 3 salvar o contexto
	push_context
	
	#corpo da funcao
	
	addi	$v0, $zero, 1 # retorno padrao caso n =1
	addi	$t0, $zero, 1
	beq		$t0, $a0, SF1 
	
	#coloca em a0 = n-1
	add		$s0, $a0, $zero #salva n em s0
	addi	$a0, $a0, -1
	jal		FAT
	#passo 4 valor de retorno
	mul		$v0, $s0, $v0

SF1:	
	#passo 5 restaurar o contexto
	pop_context
	
	#passo 6 retorno
	jr $ra