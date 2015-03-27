# CS 236 
# Project #1 - Lexical Analyzer Pseudo Code

## main.cpp

- Check for parameter
    - If parameter doesn't exist, print error, exit
- Call printTokens() on the file name
- Exit

## analyzer.cpp

### printTokens(file\_name)

- Make sure file provided is a valid file
    - If parameter isn't a valid file, print error, exit
- Read file into a string
- Iterate through all characters, decide which token is which
    - Once decided, print output, consume token length from string
