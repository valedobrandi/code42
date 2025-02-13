#!/bin/bash

cc -c ft_putchar.c ft_strlen.c
ar rcs libmylib.a ft_putchar.o ft_strlen.o 

echo "Static library created"
