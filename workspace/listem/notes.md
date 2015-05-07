```
superClass 
    processDir(dirName, pattern, recursive)
        if dirName isn't readable
            print "Unreadable dir"
        else if dirName isn't a directory
            print "Not a valid directory"
        else if !recursive
            files = dirName.file()
            for each file f in files

grep extends superClass 

lineCount extends superClass

```

# Help Session

- Super class
    - Traverse files
- m.matches: looks for complete match // matching for files
- m.find: looks for substring // grep

