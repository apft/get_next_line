#!/bin/sh

HEADER="get_next_line.h"
BAK=".bak"

FILE=ideas.txt

run_test()
{
	#printf "copy header file\n"
	#printf "change BUFF_SIZE to $BUFF_SIZE\n"
	BUFF_SIZE_LINE=`grep -n define.BUFFER_SIZE $HEADER| cut -d\: -f1`
	sed -i $BAK -E "s/define BUFF_SIZE [0-9]*/define BUFF_SIZE $BUFF_SIZE/" $HEADER

	#printf "compilation...\n"
	gcc -Wall -Wextra -Werror -o gnl.out libft.a main.c get_next_line.c

	if [[ $? -eq 0 ]]; then
		./gnl.out $FILE > tmp
		diff tmp $FILE > diff_${BUFF_SIZE}
		[[ $# -eq 0 ]] && [[ -s diff_${BUFF_SIZE} ]] && echo ${BUFF_SIZE} && cat diff_${BUFF_SIZE}
	fi
	#printf "reset header file\n"
	mv $HEADER$BAK $HEADER
}

if [[ $# -eq 1 ]]; then
	BUFF_SIZE="$1"
	run_test "quiet"
else
	for BUFF_SIZE in {1..250} 999 100000 10000000; do
		run_test
	done
fi

printf "\n\n" > tst && ./gnl.out tst > tst_diff && diff tst tst_diff
