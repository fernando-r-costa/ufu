#demonstra o funcionamento de lw e sw


.data
	x:		.space 4
	#int x;
	#....
	#x = 12;

.include "utils.asm"
.text
		
		#coloca o 12 num reg temp
		addi	$t0, $zero, 12
		la		$t1, x
		sw $t0, 0($t1)

