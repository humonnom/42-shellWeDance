cp ../minishell .
./minishell > res_minishell.txt
echo $@ | cat test_echo.txt | bash > res_bash.txt
diff res_minishell.txt res_bash.txt > result.txt

