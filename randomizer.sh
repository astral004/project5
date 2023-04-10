#!/bin/bash
if [[ ($2 =~ ^[A-Za-z]+[\.][A-Za-z0-9]+@(northeastern\.edu)) && ($1 =~ ^[00]{1}[0-9]{7}) ]]
then
	nuid=$((10#$1))
	sc1=$(( $nuid % 19))
	echo -e "Thanks, your email is: $2, \nand your 9 programs to work with are:"
	for (( c=1; c<10; c++ ))
	do
	        increment=$(( $c))
	        code=$(($(($sc1 + $increment)) % 19))
	        code=$(printf %02d $code)
	        echo "$c. codeN11$code.c"
	done

	sc2=$(( $nuid % 3))
	echo -e "Your Part 4 Program is:"
	if [[ $sc2 -eq 0 ]]
	then
	echo "Buffer Overflow"
	fi
	if [[ $sc2 -eq 1 ]]
	then
	echo "Undefined Behavior"
	fi
	if [[ $sc2 -eq 2 ]]
	then
	echo "Memory Leak"
	fi

else
	echo "These credentials are incorrect."
fi
