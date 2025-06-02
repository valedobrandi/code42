PROJECT_DIR = ..
LIBFT_DIR = $(PROJECT_DIR)/libft
INCLUDE_DIRS = -I$(PROJECT_DIR)/include -I$(LIBFT_DIR)

SRC_OBJS = \
    $(PROJECT_DIR)/obj/parse_prompt.o \
    $(PROJECT_DIR)/obj/print_prompt.o \
    $(PROJECT_DIR)/obj/quote_error.o \
    $(PROJECT_DIR)/obj/tokenize.o \
    $(PROJECT_DIR)/obj/signals.o \
	$(PROJECT_DIR)/obj/build_pipeline.o \
	$(PROJECT_DIR)/obj/validate_token.o \
	$(PROJECT_DIR)/obj/execute_command.o \
	$(PROJECT_DIR)/obj/builtin_echo.o \
	$(PROJECT_DIR)/obj/builtin_pwd.o \
	$(PROJECT_DIR)/obj/builtin_cd.o \
	$(PROJECT_DIR)/obj/free_array.o \
    $(LIBFT_DIR)/libft.a

CC = cc
CFLAGS = -Wall -Wextra -Werror

CRITERION_ROOT = $(HOME)/libs/Criterion
CRITERION_INC = -I$(CRITERION_ROOT)/include
CRITERION_LIB = -L$(CRITERION_ROOT)/build/src -lcriterion

LBS = -lreadline -lncurses

TESTS =	\
test_parse_prompt \
test_token_list \
test_pipeline \
test_commands

# Default target builds both
all: $(TESTS)

# Rules
test_parse_prompt: parse_prompt_test.c
	$(CC) $(CFLAGS) $(INCLUDE_DIRS) $(CRITERION_INC) -o $@ $^ $(SRC_OBJS) $(CRITERION_LIB) $(LBS)

test_token_list: token_list_test.c helpers.c
	$(CC) $(CFLAGS) $(INCLUDE_DIRS) $(CRITERION_INC) -o $@ $^ $(SRC_OBJS) $(CRITERION_LIB) $(LBS)

test_pipeline: token_list_test.c helpers.c
	$(CC) $(CFLAGS) $(INCLUDE_DIRS) $(CRITERION_INC) -o $@ $^ $(SRC_OBJS) $(CRITERION_LIB) $(LBS)

test_commands: execute_command_test.c helpers.c
	$(CC) $(CFLAGS) $(INCLUDE_DIRS) $(CRITERION_INC) -o $@ $^ $(SRC_OBJS) $(CRITERION_LIB) $(LBS)

# Run targets
run: all
	@for test in $(TESTS); do \
		echo "🔧 Running $$test..."; \
		LD_LIBRARY_PATH=$(CRITERION_ROOT)/build/src:$$LD_LIBRARY_PATH ./$$test; \
	done

# Run individual tests
run-parse: test_parse_prompt
	@echo "🔧 Running parse prompt tests..."
	@LD_LIBRARY_PATH=$(CRITERION_ROOT)/build/src:$LD_LIBRARY_PATH ./test_parse_prompt

run-token: test_token_list
	@echo "🔧 Running token list tests..."
	@LD_LIBRARY_PATH=$(CRITERION_ROOT)/build/src:$LD_LIBRARY_PATH ./test_token_list

run-pipeline: test_pipeline
	@echo "🔧 Running pipeline tests..."
	@LD_LIBRARY_PATH=$(CRITERION_ROOT)/build/src:$LD_LIBRARY_PATH ./test_pipeline

run-commands: test_commands
	@echo "🔧 Running command tests..."
	@LD_LIBRARY_PATH=$(CRITERION_ROOT)/build/src:$LD_LIBRARY_PATH ./test_commands

# Clean rule
clean:
	rm -f test_parse_prompt test_token_list test_pipeline test_commands

fclean: clean

re: fclean all
