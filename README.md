# Project 4 - Option 1

Due for Project Presentations

 

You will implement, using C, pass 1 & 2 of an assembler for the machine architecture described in the SIC/XE System Programmer's guide provided as reference for this course.  Your project will accept 1 command-line argument, which is a file that contains a SIC/XE assembler program. Project 4 will create and output an object file in the format described in the SIC Object File Format document. 

Remember that to generate SIC object code, we will need to make two passes through the assembly file. Pass one generates the symbol table and pass two uses the symbol table and op codes to generate the object file.   

There are some validation checks which should be done during pass two (checks  which really cannot be done during pass one). You should carefully consider the errors in the SIC assembly file input that can and should be discovered during pass two and when encountered in the source file,  generate an appropriate error message and stop the assembly process. There are errors which pass two should be able to detect and report (all of which should HALT the assembly process and generate an error message). 

For example: if an error is found with the input assembly file, you should stop the process of creating the symbol table and output the following:

## ASSEMBLY ERROR:

The contents of the source line of assembly which contains the error>CrLf>

Line line #> Description of Error Encountered>CrLf>

If the SIC/XE assembly file is valid, then project 4 should create and write the appropriate object file

I will build you project by typing make.  I will then run your project by typing project4 filename>

where filename> is the name of a SIC assembler source code file.

If assembly is completed with no errors, the object file that is created should be the name of the input file with .obj added to the end of the filename.

the turnin code for this project is:  System_Software_Fall2024_Project4

 

You need to shar your .c and makefile and documentation.txt  and turnin the sharfile to me. 

Additionally, I expect you to include a documentation.txt file in your sharfile. Discuss your design choices. What errors in the SIC/XE assembly source can you detect?

 

## Caveats:

 

1. If the SIC/XE program assembles correctly, I should see NO output to the screen from pass2. The object file should be created using the naming convention in the project specification.

2. If the SIC/XE program has an error that prevents assembly, the object file should NOT be created. Additionally, I should only see an error message output to the screen with the error that occurred.

 

## References:

1. The SIC/XE System Programmer's Reference

2. The SIC/XE Assembly Language Specification

3. The SIC Object File Format Specification (SCOFF)

 

## Extra-Credit Opportunities

1. Handle the EXTDEF and EXTREF assembler directives. (You will have to make some changes to your symbol table implementation to handle this)

2. Implement relocation records for the object file using the relocation format specified. (See SCOFF Document for more details). This includes D, R, and M records