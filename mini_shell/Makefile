# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bde-albu <bde-albu@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/05/27 09:25:09 by bde-albu          #+#    #+#              #
#    Updated: 2025/06/20 15:12:52 by bde-albu         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


NAME = minishell

CFLAGS = -Wall -Wextra -Werror -g3
CC = cc

SRC_DR = src
OBJ_DR = obj

SRC = \
main.c \
signals.c \
echoctl.c \
print_prompt.c \
quote_error.c \
parse_prompt.c \
builtin_echo.c \
builtin_pwd.c \
builtin_cd.c \
builtin_export.c \
builtin_unset.c \
builtin_env.c \
builtin_exit.c \
free_array.c \
free_token_list.c \
print_env.c \
copy_env_list.c \
allocate_env.c \
update_env_list.c \
linkedList_to_arr.c \
execute_command.c \
token.c \
validate_token.c \
append_variable.c \
append_quote.c \
read_env.c \
initiate_env_list.c \
free_pipeline.c \
free_env_list.c \
redirection.c \
get_next_line.c \
get_next_line_utils.c \
convert_env_list_to_envp.c \
get_path.c \
exec_pipeline.c \
exec_builtin.c \
expand_system_return.c \
build_command.c \
build_pipeline.c \
pipeline_utils.c \
wait_children_process_exit.c \
exec_command.c \
builtins_cmd.c \
is_path.c \
execute_redirects.c \
validate_path.c \
execute_execve.c \
child_pipeline_process.c \
apply_redirections.c \
pipe_handle.c \
validate_parse.c \
validate_directions.c

OBJ = $(SRC:.c=.o)

DEPS = include/minishell.h
PARSE_DPES = include/parsedef.h

LIBFT_DR = libft
LIBFT_A = $(LIBFT_DR)/libft.a

INCLUDES = -I$(LIBFT_DR) -Iinclude

LBS = -lreadline -lncurses

SRC_FILES = $(addprefix $(SRC_DR)/, $(SRC))
OBJ_FILES = $(addprefix $(OBJ_DR)/, $(OBJ))

all: $(OBJ_DR) $(LIBFT_A) $(NAME)

$(OBJ_DR):
	mkdir -p $(OBJ_DR)

$(LIBFT_A):
	- $(MAKE) -C $(LIBFT_DR)

$(NAME): $(OBJ_FILES)
	$(CC) $(CFLAGS) $(OBJ_FILES) $(LIBFT_A) -o $(NAME) $(LBS) $(INCLUDES)

# SRC
$(OBJ_DR)/main.o: $(SRC_DR)/main.c $(DEPS)
	$(CC) $(CFLAGS) $(INCLUDES) -c $(SRC_DR)/main.c -o $(OBJ_DR)/main.o

$(OBJ_DR)/print_prompt.o: $(SRC_DR)/print_prompt.c $(DEPS)
	$(CC) $(CFLAGS) $(INCLUDES) -c $(SRC_DR)/print_prompt.c -o $(OBJ_DR)/print_prompt.o

# signal
$(OBJ_DR)/signals.o: $(SRC_DR)/signal/signals.c $(DEPS)
	$(CC) $(CFLAGS) $(INCLUDES) -c $(SRC_DR)/signal/signals.c -o $(OBJ_DR)/signals.o

$(OBJ_DR)/echoctl.o: $(SRC_DR)/signal/echoctl.c $(DEPS)
	$(CC) $(CFLAGS) $(INCLUDES) -c $(SRC_DR)/signal/echoctl.c -o $(OBJ_DR)/echoctl.o

# Parse
$(OBJ_DR)/parse_prompt.o: $(SRC_DR)/parse/parse_prompt.c $(DEPS) $(PARSE_DPES)
	$(CC) $(CFLAGS) $(INCLUDES) -c $(SRC_DR)/parse/parse_prompt.c -o $(OBJ_DR)/parse_prompt.o

$(OBJ_DR)/quote_error.o: $(SRC_DR)/parse/quote_error.c $(DEPS) $(PARSE_DPES)
	$(CC) $(CFLAGS) $(INCLUDES) -c $(SRC_DR)/parse/quote_error.c -o $(OBJ_DR)/quote_error.o

$(OBJ_DR)/pipe_handle.o: $(SRC_DR)/parse/pipe_handle.c $(DEPS) $(PARSE_DPES)
	$(CC) $(CFLAGS) $(INCLUDES) -c $(SRC_DR)/parse/pipe_handle.c -o $(OBJ_DR)/pipe_handle.o

$(OBJ_DR)/validate_parse.o: $(SRC_DR)/parse/validate_parse.c $(DEPS) $(PARSE_DPES)
	$(CC) $(CFLAGS) $(INCLUDES) -c $(SRC_DR)/parse/validate_parse.c -o $(OBJ_DR)/validate_parse.o

# Token
$(OBJ_DR)/validate_token.o: $(SRC_DR)/token/validate_token.c $(DEPS) $(PARSE_DPES)
	$(CC) $(CFLAGS) $(INCLUDES) -c $(SRC_DR)/token/validate_token.c -o $(OBJ_DR)/validate_token.o

$(OBJ_DR)/token.o: $(SRC_DR)/token/token.c $(DEPS) $(PARSE_DPES)
	$(CC) $(CFLAGS) $(INCLUDES) -c $(SRC_DR)/token/token.c -o $(OBJ_DR)/token.o

$(OBJ_DR)/append_variable.o: $(SRC_DR)/token/append_variable.c $(DEPS) $(PARSE_DPES)
	$(CC) $(CFLAGS) $(INCLUDES) -c $(SRC_DR)/token/append_variable.c -o $(OBJ_DR)/append_variable.o

$(OBJ_DR)/append_quote.o: $(SRC_DR)/token/append_quote.c $(DEPS) $(PARSE_DPES)
	$(CC) $(CFLAGS) $(INCLUDES) -c $(SRC_DR)/token/append_quote.c -o $(OBJ_DR)/append_quote.o

$(OBJ_DR)/validate_directions.o: $(SRC_DR)/token/validate_directions.c $(DEPS) $(PARSE_DPES)
	$(CC) $(CFLAGS) $(INCLUDES) -c $(SRC_DR)/token/validate_directions.c -o $(OBJ_DR)/validate_directions.o

# Pipeline
$(OBJ_DR)/build_pipeline.o: $(SRC_DR)/pipeline/build_pipeline.c $(DEPS) $(PARSE_DPES)
	$(CC) $(CFLAGS) $(INCLUDES) -c $(SRC_DR)/pipeline/build_pipeline.c -o $(OBJ_DR)/build_pipeline.o

$(OBJ_DR)/build_command.o: $(SRC_DR)/pipeline/build_command.c $(DEPS) $(PARSE_DPES)
	$(CC) $(CFLAGS) $(INCLUDES) -c $(SRC_DR)/pipeline/build_command.c -o $(OBJ_DR)/build_command.o

$(OBJ_DR)/pipeline_utils.o: $(SRC_DR)/pipeline/pipeline_utils.c $(DEPS) $(PARSE_DPES)
	$(CC) $(CFLAGS) $(INCLUDES) -c $(SRC_DR)/pipeline/pipeline_utils.c -o $(OBJ_DR)/pipeline_utils.o

# Builtin
$(OBJ_DR)/builtin_echo.o: $(SRC_DR)/built_in/builtin_echo.c $(DEPS) $(PARSE_DPES)
	$(CC) $(CFLAGS) $(INCLUDES) -c $(SRC_DR)/built_in/builtin_echo.c -o $(OBJ_DR)/builtin_echo.o

$(OBJ_DR)/builtin_pwd.o: $(SRC_DR)/built_in/builtin_pwd.c $(DEPS) $(PARSE_DPES)
	$(CC) $(CFLAGS) $(INCLUDES) -c $(SRC_DR)/built_in/builtin_pwd.c -o $(OBJ_DR)/builtin_pwd.o

$(OBJ_DR)/builtin_cd.o: $(SRC_DR)/built_in/builtin_cd.c $(DEPS) $(PARSE_DPES)
	$(CC) $(CFLAGS) $(INCLUDES) -c $(SRC_DR)/built_in/builtin_cd.c -o $(OBJ_DR)/builtin_cd.o

$(OBJ_DR)/builtin_export.o: $(SRC_DR)/built_in/builtin_export.c $(DEPS) $(PARSE_DPES)
	$(CC) $(CFLAGS) $(INCLUDES) -c $(SRC_DR)/built_in/builtin_export.c -o $(OBJ_DR)/builtin_export.o

$(OBJ_DR)/builtin_unset.o: $(SRC_DR)/built_in/builtin_unset.c $(DEPS) $(PARSE_DPES)
	$(CC) $(CFLAGS) $(INCLUDES) -c $(SRC_DR)/built_in/builtin_unset.c -o $(OBJ_DR)/builtin_unset.o

$(OBJ_DR)/builtin_env.o: $(SRC_DR)/built_in/builtin_env.c $(DEPS) $(PARSE_DPES)
	$(CC) $(CFLAGS) $(INCLUDES) -c $(SRC_DR)/built_in/builtin_env.c -o $(OBJ_DR)/builtin_env.o

$(OBJ_DR)/builtin_exit.o: $(SRC_DR)/built_in/builtin_exit.c $(DEPS) $(PARSE_DPES)
	$(CC) $(CFLAGS) $(INCLUDES) -c $(SRC_DR)/built_in/builtin_exit.c -o $(OBJ_DR)/builtin_exit.o

# Execute
$(OBJ_DR)/execute_command.o: $(SRC_DR)/execute/execute_command.c $(DEPS) $(PARSE_DPES)
	$(CC) $(CFLAGS) $(INCLUDES) -c $(SRC_DR)/execute/execute_command.c -o $(OBJ_DR)/execute_command.o

$(OBJ_DR)/execute_redirects.o: $(SRC_DR)/execute/execute_redirects.c $(DEPS) $(PARSE_DPES)
	$(CC) $(CFLAGS) $(INCLUDES) -c $(SRC_DR)/execute/execute_redirects.c -o $(OBJ_DR)/execute_redirects.o

$(OBJ_DR)/validate_path.o: $(SRC_DR)/execute/validate_path.c $(DEPS) $(PARSE_DPES)
	$(CC) $(CFLAGS) $(INCLUDES) -c $(SRC_DR)/execute/validate_path.c -o $(OBJ_DR)/validate_path.o

$(OBJ_DR)/execute_execve.o: $(SRC_DR)/execute/execute_execve.c $(DEPS) $(PARSE_DPES)
	$(CC) $(CFLAGS) $(INCLUDES) -c $(SRC_DR)/execute/execute_execve.c -o $(OBJ_DR)/execute_execve.o

# Helper
$(OBJ_DR)/free_array.o: $(SRC_DR)/helper/free_array.c $(DEPS) $(PARSE_DPES)
	$(CC) $(CFLAGS) $(INCLUDES) -c $(SRC_DR)/helper/free_array.c -o $(OBJ_DR)/free_array.o

$(OBJ_DR)/free_token_list.o: $(SRC_DR)/helper/free_token_list.c $(DEPS) $(PARSE_DPES)
	$(CC) $(CFLAGS) $(INCLUDES) -c $(SRC_DR)/helper/free_token_list.c -o $(OBJ_DR)/free_token_list.o

$(OBJ_DR)/free_pipeline.o: $(SRC_DR)/helper/free_pipeline.c $(DEPS) $(PARSE_DPES)
	$(CC) $(CFLAGS) $(INCLUDES) -c $(SRC_DR)/helper/free_pipeline.c -o $(OBJ_DR)/free_pipeline.o

$(OBJ_DR)/free_env_list.o: $(SRC_DR)/helper/free_env_list.c $(DEPS) $(PARSE_DPES)
	$(CC) $(CFLAGS) $(INCLUDES) -c $(SRC_DR)/helper/free_env_list.c -o $(OBJ_DR)/free_env_list.o

$(OBJ_DR)/print_env.o: $(SRC_DR)/helper/print_env.c $(DEPS) $(PARSE_DPES)
	$(CC) $(CFLAGS) $(INCLUDES) -c $(SRC_DR)/helper/print_env.c -o $(OBJ_DR)/print_env.o

$(OBJ_DR)/copy_env_list.o: $(SRC_DR)/helper/copy_env_list.c $(DEPS) $(PARSE_DPES)
	$(CC) $(CFLAGS) $(INCLUDES) -c $(SRC_DR)/helper/copy_env_list.c -o $(OBJ_DR)/copy_env_list.o

$(OBJ_DR)/update_env_list.o: $(SRC_DR)/helper/update_env_list.c $(DEPS) $(PARSE_DPES)
	$(CC) $(CFLAGS) $(INCLUDES) -c $(SRC_DR)/helper/update_env_list.c -o $(OBJ_DR)/update_env_list.o

$(OBJ_DR)/linkedList_to_arr.o: $(SRC_DR)/helper/linkedList_to_arr.c $(DEPS) $(PARSE_DPES)
	$(CC) $(CFLAGS) $(INCLUDES) -c $(SRC_DR)/helper/linkedList_to_arr.c -o $(OBJ_DR)/linkedList_to_arr.o

$(OBJ_DR)/is_path.o: $(SRC_DR)/helper/is_path.c $(DEPS) $(PARSE_DPES)
	$(CC) $(CFLAGS) $(INCLUDES) -c $(SRC_DR)/helper/is_path.c -o $(OBJ_DR)/is_path.o

# Env
$(OBJ_DR)/read_env.o: $(SRC_DR)/env/read_env.c $(DEPS) $(PARSE_DPES)
	$(CC) $(CFLAGS) $(INCLUDES) -c $(SRC_DR)/env/read_env.c -o $(OBJ_DR)/read_env.o

$(OBJ_DR)/initiate_env_list.o: $(SRC_DR)/env/initiate_env_list.c $(DEPS) $(PARSE_DPES)
	$(CC) $(CFLAGS) $(INCLUDES) -c $(SRC_DR)/env/initiate_env_list.c -o $(OBJ_DR)/initiate_env_list.o

$(OBJ_DR)/allocate_env.o: $(SRC_DR)/env/allocate_env.c $(DEPS) $(PARSE_DPES)
	$(CC) $(CFLAGS) $(INCLUDES) -c $(SRC_DR)/env/allocate_env.c -o $(OBJ_DR)/allocate_env.o

$(OBJ_DR)/expand_system_return.o: $(SRC_DR)/env/expand_system_return.c $(DEPS) $(PARSE_DPES)
	$(CC) $(CFLAGS) $(INCLUDES) -c $(SRC_DR)/env/expand_system_return.c -o $(OBJ_DR)/expand_system_return.o

#gnl
$(OBJ_DR)/get_next_line.o: $(SRC_DR)/gnl/get_next_line.c $(DEPS)
	$(CC) $(CFLAGS) $(INCLUDES) -c $(SRC_DR)/gnl/get_next_line.c -o $(OBJ_DR)/get_next_line.o

$(OBJ_DR)/get_next_line_utils.o: $(SRC_DR)/gnl/get_next_line_utils.c $(DEPS)
	$(CC) $(CFLAGS) $(INCLUDES) -c $(SRC_DR)/gnl/get_next_line_utils.c -o $(OBJ_DR)/get_next_line_utils.o

# redir
$(OBJ_DR)/redirection.o: $(SRC_DR)/redir/redirection.c $(DEPS)
	$(CC) $(CFLAGS) $(INCLUDES) -c $(SRC_DR)/redir/redirection.c -o $(OBJ_DR)/redirection.o

$(OBJ_DR)/convert_env_list_to_envp.o: $(SRC_DR)/redir/convert_env_list_to_envp.c $(DEPS)
	$(CC) $(CFLAGS) $(INCLUDES) -c $(SRC_DR)/redir/convert_env_list_to_envp.c -o $(OBJ_DR)/convert_env_list_to_envp.o

$(OBJ_DR)/get_path.o: $(SRC_DR)/redir/get_path.c $(DEPS)
	$(CC) $(CFLAGS) $(INCLUDES) -c $(SRC_DR)/redir/get_path.c -o $(OBJ_DR)/get_path.o

$(OBJ_DR)/apply_redirections.o: $(SRC_DR)/redir/apply_redirections.c $(DEPS)
	$(CC) $(CFLAGS) $(INCLUDES) -c $(SRC_DR)/redir/apply_redirections.c -o $(OBJ_DR)/apply_redirections.o
# exec_pipelone

$(OBJ_DR)/exec_pipeline.o: $(SRC_DR)/exec_pipeline/exec_pipeline.c $(DEPS)
	$(CC) $(CFLAGS) $(INCLUDES) -c $(SRC_DR)/exec_pipeline/exec_pipeline.c -o $(OBJ_DR)/exec_pipeline.o

$(OBJ_DR)/exec_builtin.o: $(SRC_DR)/exec_pipeline/exec_builtin.c $(DEPS)
	$(CC) $(CFLAGS) $(INCLUDES) -c $(SRC_DR)/exec_pipeline/exec_builtin.c -o $(OBJ_DR)/exec_builtin.o

$(OBJ_DR)/wait_children_process_exit.o: $(SRC_DR)/exec_pipeline/wait_children_process_exit.c $(DEPS)
	$(CC) $(CFLAGS) $(INCLUDES) -c $(SRC_DR)/exec_pipeline/wait_children_process_exit.c -o $(OBJ_DR)/wait_children_process_exit.o

$(OBJ_DR)/child_pipeline_process.o: $(SRC_DR)/exec_pipeline/child_pipeline_process.c $(DEPS)
	$(CC) $(CFLAGS) $(INCLUDES) -c $(SRC_DR)/exec_pipeline/child_pipeline_process.c -o $(OBJ_DR)/child_pipeline_process.o

# exec_command
$(OBJ_DR)/exec_command.o: $(SRC_DR)/exec_command/exec_command.c $(DEPS)
	$(CC) $(CFLAGS) $(INCLUDES) -c $(SRC_DR)/exec_command/exec_command.c -o $(OBJ_DR)/exec_command.o

$(OBJ_DR)/builtins_cmd.o: $(SRC_DR)/exec_command/builtins_cmd.c $(DEPS)
	$(CC) $(CFLAGS) $(INCLUDES) -c $(SRC_DR)/exec_command/builtins_cmd.c -o $(OBJ_DR)/builtins_cmd.o

clean:
	rm -rf $(OBJ_DR)
	$(MAKE) -C $(LIBFT_DR) clean

fclean: clean
	rm -f $(NAME)
	$(MAKE) -C $(LIBFT_DR) fclean

re: fclean all

.PHONY: all clean fclean re
