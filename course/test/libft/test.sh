gcc -Wall -Wextra -Werror -g libft_ouput.c libft/* -o output
gcc -Wall -Wextra -Werror -g libft_expect.c -o expect
./output > output.txt
./expect > expect.txt
diff --color expect.txt output.txt