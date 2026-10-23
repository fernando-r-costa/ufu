#media10.asm

#DESC: prog. para exemplificar lacos em asm


.data
	str1: .asciiz "tick "
	strcr: .asciiz "\n"

.text
	
		#laco 0-9
		#for(int i = 0; i<10; i++)
		#(1)INICIALIZACAO DO REG DE ITERACAO
		add		$s0, $zero, $zero	# i = s0 = 0
		#(2) TESTE DA CONDICAO LOGICA
FOR1:	slti	$t0, $s0, 10		# i < 10
		beq		$t0, $zero, SAI1
		#####corpo do for
		
		addi	$v0, $zero, 4
		la		$a0, str1
		syscall	
		
		addi	$v0, $zero, 1
		add		$a0, $zero, $s0
		syscall	
		
		addi	$v0, $zero, 4
		la		$a0, strcr
		syscall	
		####/corpo for
		#(3) INCREMENTO DO ITERADOR
		addi	$s0, $s0, 1		#i++
		#(4) RETORNO AO INICIO DO BLOCO DE REPETICAO
		j		FOR1
SAI1:
		
		#ler um numero
	
		#acumular um num
	
		
	#calcular a media
	
	


	#return 0
	addi	$v0, $zero, 10
	syscall