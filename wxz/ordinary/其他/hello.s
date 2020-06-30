   1              		.file	"hello.c"
   2              		.text
   3              	.Ltext0:
   4              		.section	.rodata
   5              	.LC0:
   6 0000 48656C6C 		.string	"Hello World"
   6      6F20576F 
   6      726C6400 
   7              		.text
   8              		.globl	main
  10              	main:
  11              	.LFB0:
  12              		.file 1 "hello.c"
   1:hello.c       **** #include <stdio.h>
   2:hello.c       **** int main(int argc,char* argv[])
   3:hello.c       **** {
  13              		.loc 1 3 0
  14              		.cfi_startproc
  15 0000 55       		pushq	%rbp
  16              		.cfi_def_cfa_offset 16
  17              		.cfi_offset 6, -16
  18 0001 4889E5   		movq	%rsp, %rbp
  19              		.cfi_def_cfa_register 6
  20 0004 897DDC   		movl	%edi, -36(%rbp)
  21 0007 488975D0 		movq	%rsi, -48(%rbp)
   4:hello.c       **** 	char* p="Hello World";
  22              		.loc 1 4 0
  23 000b 488D0500 		leaq	.LC0(%rip), %rax
  23      000000
  24 0012 488945F8 		movq	%rax, -8(%rbp)
   5:hello.c       **** 	char q[]="Hello World";
  25              		.loc 1 5 0
  26 0016 48B84865 		movabsq	$8022916924116329800, %rax
  26      6C6C6F20 
  26      576F
  27 0020 488945EC 		movq	%rax, -20(%rbp)
  28 0024 C745F472 		movl	$6581362, -12(%rbp)
  28      6C6400
  29 002b B8000000 		movl	$0, %eax
  29      00
   6:hello.c       **** }
  30              		.loc 1 6 0
  31 0030 5D       		popq	%rbp
  32              		.cfi_def_cfa 7, 8
  33 0031 C3       		ret
  34              		.cfi_endproc
  35              	.LFE0:
  37              	.Letext0:
  38              		.file 2 "/usr/lib/gcc/x86_64-linux-gnu/6/include/stddef.h"
  39              		.file 3 "/usr/include/x86_64-linux-gnu/bits/types.h"
  40              		.file 4 "/usr/include/libio.h"
  41              		.file 5 "/usr/include/stdio.h"
  42              		.file 6 "/usr/include/x86_64-linux-gnu/bits/sys_errlist.h"
