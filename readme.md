For using the lexer, put the raw source code file in tests folder say tests/file.cs 
then do 
1) make clean
2) make 
3) ./a.out tests/file.cs

You will see a output file in the same folder, with the name file_output.lang which has lexer output(tokens). There are some sample
test files and their outputs available for reference. 