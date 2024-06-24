# Имя исполняемого файла
TARGET = viewer.a

# Компилятор и флаги
CC = g++
CFLAGS = -std=c++11 -Wall -Werror -Wextra

# Исходные файлы
SRC = Back/fileReaderPlus.cc

# Объектные файлы
OBJS = $(SRC:.cc=.o)

# Определение системы сборки
OS=$(shell uname -s)

# Правила
all: clean $(TARGET) test

install: uninstall
	mkdir -p build
	cd build/ && qmake ../Front/Front.pro && make

uninstall:
	rm -rf build

run:
ifeq ($(OS), Linux)
	./build/Front
else
	./build/Front.app/Contents/MacOS/Front
endif

dist:
	tar cvzf dist_calc_qt.tgz build/

dvi:
	open ../README_RUS.md

clean: cleantest
	rm -rf *.o
	rm -rf *.a
	rm -rf */*.o
	rm -rf */*.a

cleantest:
	rm -rf *.gcda
	rm -rf *.gcno
	rm -rf *.info
	rm -rf test
	rm -rf tests
	rm -rf report

$(TARGET): $(OBJS)
	ar rcs $@ $^

test: cleantest $(TARGET)
	$(CC) $(CFLAGS) -I/usr/local/include -L/usr/local/lib $(SRC) ./testDir/test.cc -o test -lgtest -lgtest_main -pthread
	./test

gcov_report: cleantest $(TARGET)
	$(CC) $(CFLAGS) -fprofile-arcs -ftest-coverage $(SRC) ./testDir/test.cc -o tests -lgtest -lgtest_main -pthread
	./tests
	lcov -t "stest" -o s21_test.info --no-external -c -d .
	genhtml -o report s21_test.info
	open ./report/index.html

clang-format:
	clang-format --style=Google -i */*.cc */*.h

code_style:
	clang-format --style=Google -n */*.cc */*.h
