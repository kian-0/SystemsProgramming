Project 1

Due September 22, 2024 at 1159PM EST.

Due October 1, 2024 at 600PM EST.

Due October 4, 2024 at 11:59 PM EST.

 

You will implement, using C, pass 1 of an assembler for the machine architecture described in the SIC System Programmer's guide provided as a reference for this course.  Your project will accept 1 command-line argument, which is a file that contains a SIC assembler program. Project 1 will create and output a symbol table as a result of analyzing the input SIC assembly file.

Remember that to generate SIC object code, we must make two passes through the assembly file. Pass one generates the symbol table and pass two uses the symbol table and op codes to generate the object file.   You will be doing pass two via Project 2. Think about this in your design.

There are some validation checks which should be done during pass one. You should carefully consider the SIC assembly file input errors that can and should be discovered during pass one, and when encountered in the source file,  generate an appropriate error message and stop the assembly process. 

For example: if an error is found with the input assembly file, you should stop the process of creating the symbol table and output the following:

ASSEMBLY ERROR:

<The contents of the source line of assembly which contains the error><CrLf>

Line <line #> <Description of Error Encountered><CrLf>

If the SIC assembly file is valid, then Project 1 should output, its symbol table. For each symbol, there should be one line of output: the symbol name followed by a <tab> character, the hexadecimal address of the symbol, and a <CrLf>.

----- Example ---- 

COPY	START	1000
FIRST	STL	RETADR
CLOOP	JSUB	RDREC
	LDA	LENGTH
	COMP	ZERO
	JEQ	ENDFIL
	JSUB	WRREC
	J	CLOOP
ENDFIL	LDA	EOF
	STA	BUFFER
	LDA	THREE
	STA	LENGTH
	JSUB	WRREC
	LDL	RETADR
	RSUB
EOF	BYTE	C'EOF'
THREE	WORD	3
ZERO	WORD	0
RETADR	RESW	1
LENGTH	RESW	1
BUFFER	RESB	4096
RDREC	LDX	ZERO
	LDA	ZERO
RLOOP	TD	INPUT
	JEQ	RLOOP
	RD	INPUT
	COMP	ZERO
	JEQ	EXIT
	STCH	BUFFER,X
	TIX	MAXLEN
	JLT	RLOOP
EXIT	STX	LENGTH
	RSUB
INPUT	BYTE	X'F1'
MAXLEN	WORD	4096
WRREC	LDX	ZERO
WLOOP	TD	OUTPUT
	JEQ	WLOOP
	LDCH	BUFFER,X
	WD	OUTPUT
	TIX	LENGTH
	JLT	WLOOP
	RSUB
OUTPUT	BYTE	X'05'
	END	FIRST
The correct output for this input file would be:

COPY   1000

FIRST 1000

CLOOP 1003

ENDFIL  1015

EOF    102A

THREE 102D

ZERO 1030

RETADR 1033

LENGTH 1036

BUFFER 1039

RDREC 2039

RLOOP 203F

EXIT 2057

INPUT 205D

MAXLEN 205E

WRREC 2061

WLOOP 2064

OUTPUT 2079

 

I will build your project by typing make.  I will then run your project by typing project1 <filename>

where <filename> is the name of a SIC assembler file.

the turnin code for this project is:  System_Software_Project1_Fall_2024_MW

 

You need to shar your .c,  .h and makefile and turnin the sharfile to me. 

Example:

shar *.c *.h makefile documentation.txt > project1_shar

turnin project1_shar System_Software_Project1_Fall_2024_MW
 

Additionally, I expect you to include a documentation.txt file in your sharfile. documentation.txt should contain approximately two paragraphs. Please let me know what, if anything, is incomplete (any specifications you did not complete), a description of your symbol table implementation.  

References:

1. The SIC System Programmer's Reference

2. The SIC Assembly Language Specification
