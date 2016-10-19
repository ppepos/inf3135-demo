#!/bin/bash

curl -s https://raw.githubusercontent.com/mledoze/countries/master/countries.json | \
	grep capital | \
	grep -v \"\" | \
	grep -v \\u | \
	sed 's/^.*: \"//' |
	sed 's/\",//' > capitales.txt
