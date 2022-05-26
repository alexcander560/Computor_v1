DEFAULT="\033[0m"
REVERS="\033[7m"
RED="\033[31m"
GREEN="\033[32m"
YELLOW="\033[33m"
PURPLE="\033[35m"

IFS=$'\x10'

declare -i count=0

# Функция запускает нужный тест
run_test()
{
	count=count+1
	printf "$YELLOW========== Test $count ====================$DEFAULT\n"
	printf "$PURPLE$1$DEFAULT\n"
	printf "$GREEN$2$DEFAULT\n"
	./computor_v1 $1
	printf "$YELLOW======================================$DEFAULT\n"
}

make

printf "$RED============ TEST SUBJECT ============$DEFAULT\n"

run_test "5 * X^0 + 4 * X^1 - 9.3 * X^2 = 1 * X^0" "-0.475131, 0.905239"
run_test "5 * X^0 + 4 * X^1 = 4 * X^0" "-0.25"
run_test "8 * X^0 - 6 * X^1 + 0 * X^2 - 5.6 * X^3 = 3 * X^0" "high degree"
run_test "42 * X^0 = 42 * X^0" "any number"
run_test "42 * X^0 = 0" "no solution"

printf "$RED============ NOT CORRECT =============$DEFAULT\n"

run_test "5 * X^0 + 4 * X^1 - 9.3 * X^2 = 1 * X^0 = 0" "not correct"
run_test "5 * X^0 + 4 * X^1   4 * X^0" "not correct"
run_test "8 * X^0 - 6 * X^1 + 0 * X!2 - 5.6 * X^3 = 3 * X^0" "not correct"
run_test "42 * Y^0 = 42 * Y^0" "not correct"
run_test "42 * X^0 = null" "not correct"

printf "$RED============== TEST MY ===============$DEFAULT\n"

run_test "12 * X^0 + 7 * X^1 + 1 * X^2 = 0" "-3, -4"
run_test "2 * X^0 + 4 * X^1 + 2 * X^2 = 0" "-1"
run_test "15 * X^0 + 14 * X^1 + 13 * X^2 = 0" "-0.538462+0.929465i, -0.538462-0.929465i"

run_test "20 * X^0 + 10 * X^1 = 0" "-2"
run_test "-2 * X^0 + 0 * X^1 + 10 * X^2 = 0" "0.447214, -0.447214"
run_test "0 * X^0 + 3 * X^1 + 10 * X^2 = 0" "0, -0.3"

run_test "1 * X^0 = 0" "no solution"
run_test "0 * X^0 + 0 * X^1 + 169 * X^2 = 0" "0"
run_test "0 * X^0 + 21 * X^1 = 0" "0"

run_test "0 * X^0 = 0 * X^0" "any number"

printf "$RED======== TEST MY(right part) =========$DEFAULT\n"

run_test "0 = 12 * X^0 + 7 * X^1 + 1 * X^2" "-3, -4"
run_test "0 = 2 * X^0 + 4 * X^1 + 2 * X^2" "-1"
run_test "0 = 15 * X^0 + 14 * X^1 + 13 * X^2" "-0.538462+0.929465i, -0.538462-0.929465i"

run_test "0 = 20 * X^0 + 10 * X^1" "-2"
run_test "0 = -2 * X^0 + 0 * X^1 + 10 * X^2" "0.447214, -0.447214"
run_test "0 = 0 * X^0 + 3 * X^1 + 10 * X^2" "0, -0.3"

run_test "0 = 1 * X^0" "no solution"
run_test "0 = 0 * X^0 + 0 * X^1 + 169 * X^2" "0"
run_test "0 = 0 * X^0 + 21 * X^1" "0"

run_test "0 = 0 * X^0" "any number"

printf "$RED======== TEST MY(interesting) ========$DEFAULT\n"

run_test "2 * X^0 + 0 * X^1 + 10 * X^2 = 0" "0.447214i, -0.447214i"
run_test "2 * X^0 + 0 * X^1 + 10 * X^2 + 42 * X^3 = 0 * X^0 + 0 * X^1 + 0 * X^2 + 42 * X^3" "0.447214i, -0.447214i"
run_test "2 * X^0 + 0 * X^1 + 10 * X^2 + 42 * X^3 + 142 * X^4 + 142 * X^5 + 142 * X^6 + 142 * X^7 = \
0 * X^0 + 0 * X^1 + 0 * X^2 + 42 * X^3 + 142 * X^4 + 142 * X^5 + 142 * X^6 + 142 * X^7" "0.447214i, -0.447214i"
run_test "42 * X^0 + 142 * X^1 + 7 * X^2 = 21 * X^0 + 100 * X^1 - 93 * X^2" "-0.21 + 0.4073i, -0.21 - 0.4073i"
run_test "21 * X^0 = -21 * X^0" "no solution"