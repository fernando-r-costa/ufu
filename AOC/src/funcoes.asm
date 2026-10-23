#exemplificar o funcionamento de funcoes em assembly
#DDA 07.10.26




.data
	ma:		.space		4
	arr:	.space		40
	a:		.space		4
	str1:	.asciiz		"digite um num: "
	str2:	.asciiz		"o maior num. lido foi "
.include "utils.asm"	 
.text
		
		la		$s7, arr			#ponteiro para o inicio do arr
		
		add		$s0, $s0, $zero		# i = 0
F1:		slti	$t0, $s0, 10
		beq		$t0, $zero, SF1
		#corpo do for
		printStr(str1)
		readInt
		sw		$v0, ($s7)
		addi	$s7, $s7, 4	#arit pont arr++
		#/corpo do for
		addi	$s0, $s0, 1		# i++
		j		F1
SF1:	#(PASSO 1) definir os argumentos
		addi	$a0, $zero, 10	# n = 10
		la		$a1, arr		# *arr == arr[0]
		#(PASSO 2) chamar a funcao
		jal		MAX
		#(PASSO 7)recuperar o valor de retorno
		add		$s6, $v0, $zero


		return0

.include "bibliUtil.asm"
