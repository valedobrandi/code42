PROJECT_DIR = ..
LIBFT_DIR = $(PROJECT_DIR)/libft
INCLUDE_DIRS = -I$(PROJECT_DIR)/include -I$(LIBFT_DIR)

SRC_OBJS = $(filter-out $(PROJECT_DIR)/obj/main.o, $(wildcard $(PROJECT_DIR)/obj/*.o)) $(LIBFT_DIR)/libft.a

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
test_quote_error \
test_token_validate

# Default target builds both
all: $(TESTS)

# Rules
test_quote_error: src/quote_error_test.c
	$(CC) $(CFLAGS) $(INCLUDE_DIRS) $(CRITERION_INC) -o $@ $^ $(SRC_OBJS) $(CRITERION_LIB) $(LBS)

test_parse_prompt: src/parse_prompt_test.c
	$(CC) $(CFLAGS) $(INCLUDE_DIRS) $(CRITERION_INC) -o $@ $^ $(SRC_OBJS) $(CRITERION_LIB) $(LBS)

test_token_list: src/token_list_test.c src/helpers.c
	$(CC) $(CFLAGS) $(INCLUDE_DIRS) $(CRITERION_INC) -o $@ $^ $(SRC_OBJS) $(CRITERION_LIB) $(LBS)

test_pipeline: src/pipeline_test.c src/helpers.c
	$(CC) $(CFLAGS) $(INCLUDE_DIRS) $(CRITERION_INC) -o $@ $^ $(SRC_OBJS) $(CRITERION_LIB) $(LBS)

test_token_validate: src/token_validation_test.c src/helpers.c
	$(CC) $(CFLAGS) $(INCLUDE_DIRS) $(CRITERION_INC) -o $@ $^ $(SRC_OBJS) $(CRITERION_LIB) $(LBS)

# Run targets
all: all
	@for test in $(TESTS); do \
		echo "🔧 Running $$test..."; \
		LD_LIBRARY_PATH=$(CRITERION_ROOT)/build/src:$$LD_LIBRARY_PATH ./$$test; \
	done

# Run individual tests
quote: test_quote_error
	@echo "🔧 Running command tests..."
	@LD_LIBRARY_PATH=$(CRITERION_ROOT)/build/src:$LD_LIBRARY_PATH ./test_quote_error

parse: test_parse_prompt
	@echo "🔧 Running parse prompt tests..."
	@LD_LIBRARY_PATH=$(CRITERION_ROOT)/build/src:$LD_LIBRARY_PATH ./test_parse_prompt

token: test_token_list
	@echo "🔧 Running token list tests..."
	@LD_LIBRARY_PATH=$(CRITERION_ROOT)/build/src:$LD_LIBRARY_PATH ./test_token_list

pipeline: test_pipeline
	@echo "🔧 Running pipeline tests..."
	@LD_LIBRARY_PATH=$(CRITERION_ROOT)/build/src:$LD_LIBRARY_PATH ./test_pipeline

commands: test_commands
	@echo "🔧 Running command tests..."
	@LD_LIBRARY_PATH=$(CRITERION_ROOT)/build/src:$LD_LIBRARY_PATH ./test_commands

token-validate: test_token_validate
	@echo "🔧 Running token_validate tests..."
	@LD_LIBRARY_PATH=$(CRITERION_ROOT)/build/src:$LD_LIBRARY_PATH ./test_token_validate

# Clean rule
clean:
	rm -f test_parse_prompt test_token_list test_pipeline test_commands test_token_validate

fclean: clean

re: fclean all
