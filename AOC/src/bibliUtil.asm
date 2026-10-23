#bibliUtil.asm
#contem funcoes muito usadas

.text

#a0 - numero de elementos no array
#a1 - ponteiro para a primeira posicao do array
#DESC: retorna o maior elemento do array
MAX:	
		#(PASSO 3) - salva contexto
		sw	$a0, 0($sp)		
		sw	$a1, -4($sp)
		sw	$a2, -8($sp)
		sw	$a3, -12($sp)
		sw	$s0, -16($sp)
		sw	$s1, -20($sp)
		sw	$s2, -24($sp)
		sw	$s3, -28($sp)
		sw	$s4, -32($sp)
		sw	$s5, -36($sp)
		sw	$s6, -40($sp)
		sw	$s7, -44($sp)
		sw	$ra, -48($sp)
		addi	$sp, $sp, -52	
		#carrega v[0] para s0 -- ma
		lw		$s0, 0($a1)
		
		addi	$s7, $zero, 1	#s7 = i
FF1:	slt		$t0, $s7, $a0	# i < n
		beq		$t0, $zero, SFF1
		#corpo do for
		addi	$a1, $a1, 4		#v++ aponta para a prox pos do array
		lw		$t7, 0($a1)
		slt		$t1, $s0, $t7
		beq		$t1, $zero, SIF1
		#corpo do if
		add		$s0, $t7, $zero		#ma <- v[i]
		#/corpo do if
SIF1: 	#/corpo do for
		addi	$s7, $s7, 1
		j 		FF1
SFF1:   #(PASSO 4) atribui o valor d retorno
		add		$v0, $zero, $s0
		
		#(PASSO 5) restaura o contexto
		addi	$sp, $sp, 52
		lw	$a0, 0($sp)		
		lw	$a1, -4($sp)
		lw	$a2, -8($sp)
		lw	$a3, -12($sp)
		lw	$s0, -16($sp)
		lw	$s1, -20($sp)
		lw	$s2, -24($sp)
		lw	$s3, -28($sp)
		lw	$s4, -32($sp)
		lw	$s5, -36($sp)
		lw	$s6, -40($sp)
		lw	$s7, -44($sp)
		lw	$ra, -48($sp)
		
		#(PASSO 6) retornar da funcao
		jr		$ra				 		 		 				 		 		 	
