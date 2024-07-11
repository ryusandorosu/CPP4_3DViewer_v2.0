# Имя статической библиотеки
TARGET = viewer.a

# Компилятор и флаги
CC = g++
CFLAGS = -std=c++17 -Wall -Werror -Wextra
COMPILE = $(CC) $(CFLAGS)

# Исходные файлы
SRC = Back/fileReaderPlus.cc
TST = testDir/test.cc

# Объектные файлы
OBJS = *.o

# Определение системы сборки
OS=$(shell uname -s)

# Правила
all: clean install run

install: uninstall
	mkdir -p build
	cd Front/ && cmake CMakeLists.txt && make

uninstall:
	rm -rf build dist_calc_qt.tgz

run:
ifeq ($(OS), Linux)
	./build/3DViewer
else
	./build/3DViewer.app/Contents/MacOS/3DViewer
endif

dist:
	mkdir temp_arch
	cp -r Back Controller Front testDir Makefile temp_arch
	tar cvzf dist_calc_qt.tgz temp_arch/
	rm -rf temp_arch

dvi:
	open ../README_RUS.md

clean: cleantest
	rm -rf *.o */*.o
	rm -rf *.a */*.a
	rm -rf */Makefile */resources/*/Makefile
	rm -rf */*.conf
	rm -rf */.qt
	rm -rf */*.cmake */resources/*/*.cmake
	rm -rf */*_autogen */resources/*/*_autogen
	rm -rf */CMakeFiles */resources/*/CMakeFiles
	rm -rf */CMakeCache.txt
	rm -rf */resources/*/*.dylib
	rm -rf temp_arch

cleantest:
	rm -rf *.gcda
	rm -rf *.gcno
	rm -rf *.info
	rm -rf test
	rm -rf tests
	rm -rf report

$(TARGET):
	$(COMPILE) -c $(SRC)
	ar rcs $(TARGET) $(OBJS)
	rm -rf $(OBJS)

test: cleantest $(TARGET)
	$(COMPILE) -I/usr/local/include -L/usr/local/lib $(SRC) ./$(TST) -o test -lgtest -lgtest_main -pthread
	./test

gcov_report: cleantest $(TARGET)
	$(COMPILE) -fprofile-arcs -ftest-coverage $(SRC) ./$(TST) -o tests -lgtest -lgtest_main -pthread
	./tests
	lcov -t "tests" -o s21_test.info --no-external -c -d . --ignore-errors inconsistent,format,usage
	genhtml -o report s21_test.info
	open ./report/index.html
	make cleantest

clang-format:
	clang-format --style=Google -i */*.cc */*.h

code_style:
	clang-format --style=Google -n */*.cc */*.h
