#!/bin/bash

cat /etc/passwd | grep -v '#' | sed -n 'n;p' | awk -F':' '{print $1}' | rev | sort -r | grep -w "[FT_LINE1-FT_LINE2]" | tr '\n' ',' | sed 's/,/, /g' | sed 's/, $/./' | tr -d '\n'
