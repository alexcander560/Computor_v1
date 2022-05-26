DEFAULT="\033[0m"
REVERS="\033[7m"
RED="\033[31m"
GREEN="\033[32m"
YELLOW="\033[33m"
PURPLE="\033[35m"

IFS=$'\x10'

# Функция запускает нужный тест
run_test()
{
	clang++	-Wall -Wextra -Werror $1 -o test_prog
	./test_prog
	rm -rf test_prog
}

run_test "5 * X^0 + 4 * X^1 - 9.3 * X^2 = 1 * X^0"