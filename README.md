# 42-shellWeDance
* Bash Shell 만들기 프로젝트

## 🚴‍♀️실행
```
> make
> ./minishell
```
- Now, you can use our `ShellWeDance`

## ⌨️ 사용할 수 있는 Command
### export
```
>> export ABC="DEF"
>> echo $ABC
DEF
```
### unset
- unset something after export
```
>> unset ABC // you have to export ABC before unset
>> echo $ABC
// you will see blank
```

### env
```
>> env
// you can see all enviroment values
```

### cd
```
>> mkdir something_new
>> cd something_new
>> vi test.c
// write c program and save
>> gcc test.c
>> ls
a.out   test.c
>> ./a.out
I love my minishell
>> cd ..
>> rm -rf something_new
```
```
>> cd // move to home directory
```

```
>> cd - // back to last location
```

### pwd
```
>> pwd
/Users/username/42-shellWeDance
```

### echo
```
>> echo ""''""''"hello"
hello
>> echo "''''"hello
hello
>> echo "hello'
ERROR: INVALID QUOTE PAIR
```

### exit
```
>> ./minishell
>> ./minishell
>> exit
>> exit
// still in our shell
```

## Builtin Commands 
* Find built in command
```
>> whereis ls
/bin/ls
>> cd /bin
>> ls -1F // show excute files one by one
[*
bash*
cat*
chmod*
cp*
csh*
dash*
date*
dd*
df*
echo*
ed*
expr*
hostname*
kill*
ksh*
launchctl*
link*
ln*
ls*
mkdir*
mv*
pax*
ps*
pwd*
rm*
rmdir*
sh*
sleep*
stty*
sync*
tcsh*
test*
unlink*
wait4path*
zsh*
```

### ls
```
>> ls
// you can see your current location's files and directories
```
* You can use Options(`ls -al`)
* You can test with Pipe(`ls -al | grep 'web'`)


## 그 외 기능
### HISTORY
* ⬆️(UP) & ⬇️(DOWN) : You can see previously entered commands

### SIGINT(^C)
* Terminal Interrupt character
```
>> hello // if you type ^C, just move to next line(you can't see anything)
>> // same result in empty line
>> 
```

### EOF(^D)
```
>> asdfasdf // if you type ^D, nothing happends
>> exit // type ^D in empty line, it exits the shell.
```

### SIGQUIT(^\)
```
>> cd // move to home directory
>> find . // will make endless output
(... endless output ...) // if you want to stop this process, type ^\
Quit: 3 // process will end with this sentence
>> 
```


