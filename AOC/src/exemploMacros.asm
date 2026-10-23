

.include "utils.asm"

.data

str1: .asciiz "String de teste!"


.text

	printStr(str1)
	#newLine
	printInt(67)	