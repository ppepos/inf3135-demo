#!/bin/bash

for f in `ls tests/*in`
do
	out_file=$(echo $f | sed 's/in/out/')
	cat tests/header.c.part $f tests/footer.c.part > tests/temp.c
	gcc -o tests/temp tests/temp.c

	./tests/temp > tests/temp.out

	diff tests/temp.out $out_file #1>/dev/null
	if [[ $? == "0" ]]; then
		echo "$f : OK"
	else
		echo "$f : FAILED"
	fi

	rm tests/temp tests/temp.c tests/temp.out
done
