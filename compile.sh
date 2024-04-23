#!/bin/bash

ARG="1 2 0 3 5 4 7 8 6 9"

# echo "--------------"
# echo "checker_MAC:"
# echo "--------------"
# ./push_swap $ARG | ./checker_MAC $ARG
# echo -e "\n"

# echo "--------------"
# echo "checker_linux:"
# echo "--------------"
# ./push_swap $ARG | ./checker_linux $ARG
# echo -e "\n"

# echo "--------------"
# echo "bonus_checker:"
# echo "--------------"
# ./push_swap $ARG | ./checker $ARG
# echo -e "\n"

echo "--------"
echo "command:"
echo "--------"
./push_swap $ARG
echo -e "\n"


echo "--------------"
echo "command count:"
echo "--------------"
./push_swap $ARG | wc -l
echo -e "\n"

echo "------"
echo "leaks:"
echo "------"
if [ "$(uname)" = "Darwin" ]; then
    leaks -atExit -- ./push_swap $ARG > /dev/null 2>&1
    if [ $? -eq 0 ]; then
        echo "no leak"
    else
        leaks -atExit -- ./push_swap $ARG
    fi
elif [ "$(uname)" = "Linux" ]; then
	# 2>&1 is used to redirect stderr to stdout so that we can grep on it
   	if valgrind ./push_swap $ARG 2>&1 | grep -q "All heap blocks were freed -- no leaks are possible"; then
        echo "no leak"
    else
        valgrind ./push_swap $ARG
    fi
fi
