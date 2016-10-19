#!/bin/bash

curl -s https://raw.githubusercontent.com/mledoze/countries/master/countries.json | \
	grep 'capital\|cca2' | \
	sed 's/^.*"capital": //' |
	sed 's/^.*"cca2": //' |
	{
	out=""
	while read -r code
	do
		read -r capitale

		if [[ $capitale == *"\u"* ]]
		then
			continue
		fi

		if [[ $capitale == *"\"\""* ]]
		then
			continue
		fi

		code=$(echo $code | tr -d \'\",\')
		capitale=$(echo $capitale | tr -d \'\",\')

		line="$code,$capitale"$'\n'
		out+="$line"
	done
	echo "$out" | grep -v '^$'
	} > capitales.txt

