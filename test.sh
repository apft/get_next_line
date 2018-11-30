#!/bin/sh

HEADER="get_next_line.h"
BAK=".bak"

if [[ $# -eq 1 ]]; then
	BUFF_SIZE="$1"
fi

printf "copy header file\n"
printf "change BUFF_SIZE to $BUFF_SIZE\n"
BUFF_SIZE_LINE=`grep -n define.BUFFER_SIZE $HEADER| cut -d\: -f1`
sed -i $BAK -E "s/define BUFF_SIZE [0-9]*/define BUFF_SIZE $BUFF_SIZE/" $HEADER

printf "reset header file\n"
mv $HEADER$BAK $HEADER

