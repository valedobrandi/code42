make -C ../libft re
make -C ../libft clean
gcc -I../libft  -Wall -Wextra -Werror libft_output.c -L../libft -lft -o output
gcc -Wall -Wextra -Werror -g libft_expect.c -o expect
./output | cat -e > output.txt
./expect | cat -e > expect.txt
clear
diff --color output.txt expect.txt
diff -y --color output.txt expect.txt > test
rm output.txt
rm expect.txt