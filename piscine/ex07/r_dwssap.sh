#!/bin/bash
grep -v '^#' /etc/passwd | awk 'NR % 2 == 0' | cut -d: -f1 | rev | sort -r | sed -n -e  "${FT_LINE1},${FT_LINE2}p" | awk '{printf "%s, ", $0}' | sed 's/, $/./' 
