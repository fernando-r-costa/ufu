#utils.asm
#
#DESC: define um monte de macros comumente utilizadas em 
#diversos programas
#
#DDA 30.09.26

.macro printStr (%str)
	addi	$v0, $zero, 4
	la		$a0, %str
	syscall
	#newLine
.end_macro

.macro newLine
	addi	$v0, $zero, 4
	la		$a0, CR
	syscall	
.end_macro

.macro printInt(%z)
	addi	$v0, $zero, 1
	addi	$a0, $zero, %z
	syscall
.end_macro

.macro printIntR(%r)
	addi	$v0, $zero, 1
	add		$a0, $zero, %r
	syscall
.end_macro

.macro	readInt
	addi	$v0, $zero, 5
	syscall
.end_macro


.macro	return0
	li	$v0, 10
	syscall
.end_macro

.data 
CR:    .asciiz    "\n"


