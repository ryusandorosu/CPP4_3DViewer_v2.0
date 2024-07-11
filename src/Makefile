# Имя статической библиотеки
TARGET = viewer.a

# Компилятор и флаги
CC = g++
CFLAGS = -std=c++17 -Wall -Werror -Wextra
COMPILE = $(CC) $(CFLAGS)

# Исходные файлы
SRC = Back/parser.cc
TST = TestDir/test.cc

# Объектные файлы
OBJS = *.o

# Определение системы сборки
OS = $(shell uname -s)

# Правила
all: clean install run

install: uninstall
	mkdir -p build
	cd Front/ && cmake CMakeLists.txt && make

uninstall:
	rm -rf build 3dviewer2_dist.tgz

run:
ifeq ($(OS), Linux)
	./build/3DViewer
else
	./build/3DViewer.app/Contents/MacOS/3DViewer
endif

dist:
	mkdir 3dviewer2_dist
	cp -r Back Controller Front TestDir Makefile 3dviewer2_dist
	tar cvzf 3dviewer2_dist.tgz 3dviewer2_dist/
	rm -rf 3dviewer2_dist

dvi:
	open ../README_RUS.md

clean: cleantest
	rm -rf *.o */*.o
	rm -rf *.a */*.a
	rm -rf *.obj
	rm -rf */resources/*/*.so
	rm -rf */Makefile */resources/*/Makefile
	rm -rf */*.conf
	rm -rf */.qt
	rm -rf */*.cmake */resources/*/*.cmake
	rm -rf */*_autogen */resources/*/*_autogen
	rm -rf */CMakeFiles */resources/*/CMakeFiles
	rm -rf */CMakeCache.txt
	rm -rf */resources/*/*.dylib
	rm -rf 3dviewer2_dist

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
ifeq ($(OS), Linux)
	lcov -t "tests" -o s21_test.info --no-external -c -d .
else
	lcov -t "tests" -o s21_test.info --no-external -c -d . --ignore-errors inconsistent,format,usage
endif
	genhtml -o report s21_test.info
	open ./report/index.html
	make cleantest

clang-format:
	clang-format --style=Google -i */*.cc */*/*.cc */*.h */*/*.h

code_style:
	clang-format --style=Google -n */*.cc */*/*.cc */*.h */*/*.h
