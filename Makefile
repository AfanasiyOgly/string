CC = gcc
CFLAGS = -Wall -Wextra -I. -fprofile-arcs -ftest-coverage
LDFLAGS = `pkg-config --cflags --libs check`
TARGET = test_all
TEST_DIR = test
SRC_DIR = function
SRC_TEST = $(shell find $(TEST_DIR) -name "test*.c")
SRC_LIB = $(shell find $(SRC_DIR) -name "s21_*.c")
OBJ_TEST = $(SRC_TEST:$(TEST_DIR)/%.c=build/%.o)
OBJ_LIB = $(SRC_LIB:$(SRC_DIR)/%.c=build/%.o)
OBJ_MAIN = build/main.o
LIB_SRC = $(wildcard $(SRC_DIR)/s21_*.c)
LIB_OBJ = $(LIB_SRC:$(SRC_DIR)/%.c=build/%.o)
# Создание каталога build, если он еще не существует

all: build $(TARGET) lib

build:
	mkdir -p build


$(TARGET): $(OBJ_TEST) $(OBJ_LIB) $(OBJ_MAIN)
	$(CC) $(CFLAGS) -o $@ $^ $(LDFLAGS)

build/%.o: $(TEST_DIR)/%.c
	$(CC) $(CFLAGS) -c $< -o $@

build/%.o: $(SRC_DIR)/%.c
	$(CC) $(CFLAGS) -c $< -o $@

build/main.o: main.c
	$(CC) $(CFLAGS) -c $< -o $@

gcov_report: test
	lcov --capture --directory . --output-file coverage.info
	lcov --remove coverage.info '*/test/*' '*/function/*' --output-file coverage.info
	genhtml coverage.info --output-directory out

s21_string.a: $(LIB_OBJ)
	ar rcs $@ $^

lib: s21_string.a

test:	 test_all
	./test_all

clean:
	rm -rf build
	rm -f $(TARGET) s21_string.a coverage.info *.gcda *.gcno

.PHONY: all build clean

