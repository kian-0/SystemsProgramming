# Project 2

Due Oct 21, 2024 at 2359 EST.

 
You will implement, using C, pass 2 of an assembler for the machine architecture described in the SIC System Programmer's guide provided as reference for this course.  Your project will accept 1 command-line argument, which is a file that contains a SIC assembler program. Project 2 will create and output an object file in the format described in the SIC Object File Format document. 

Remember that to generate SIC object code, we must make two passes through the assembly file. Pass one generates the symbol table and pass two uses the symbol table and op codes to generate the object file.   

There are some validation checks which should be done during pass two (checks which really cannot be done during pass one). You should carefully consider the errors in the SIC assembly file input that can and should be discovered during pass two and when encountered in the source file,  generate an appropriate error message and stop the assembly process. There are additional errors that pass two should be able to detect and report (all of which should HALT the assembly process and generate an error message) which could not be checked during pass 1. 

For example: if an error is found with the input assembly file, you should stop the process of creating the symbol table and output the following:

### Assembly error format:

(The contents of the source line of assembly which contains the error>(CrLf>

Line (line #> (Description of Error Encountered>(CrLf>

If the SIC assembly file is valid, then Project 2 should create and write the appropriate object file

----------------------------------------------------------------------------------------------------------------------

### Grading:
I will build your project by typing make.  I will then run your project by typing project2 (filename>

where (filename> is the name of a SIC assembler source code file.

If assembly is completed with no errors, the object file that is created should be the name of the input file with .obj added to the end of the filename. For example:

project2 test1.sic

If is assembly finishes with no errors should create a file called test1.sic.obj

You should NOT create the.obj file if assembly fails due to an error.

the turnin code for this project is:  System_Software_Project2_Fall2024_MW

You need to shar your .c and makefile and documentation.txt  and turnin the sharfile to me. 

Additionally, I expect you to include a documentation.txt file in your sharfile. Discuss your design choices. What errors in the SIC assembly source are you able to detect?

----------------------------------------------------------------------------------------------------------------------

### Caveats:
1. If the SIC program assembles correctly, I should see NO output to the screen from pass2. The object file should be created using the naming convention in the project specification.

2. If the SIC program has an error which prevents assembly, the object file should NOT be created. Additionally, I should only see an error message output to the screen with the error that occurred.

3. If the user includes a command-line option of --pass1only, your project 2 should stop after pass 1 and print the symbol table.

References:

1. The SIC System Programmer's Reference

2. The SIC Assembly Language Specification

3. The SIC Object File Format Specification (SCOFF)
