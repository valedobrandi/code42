#!/bin/bash

echo "--> nan/nanf/+inf/+inff/-inf/-inff"
./convert nan
./convert nanf
./convert +inf
./convert +inff
./convert -inf
./convert -inff

echo "--> 0 42 -42 2147483647 -2147483648"
for val in 0 42 -42 2147483647 -2147483648; do
    ./convert "$val"
done
echo "--> 3.14 2.718f -0.001 1e10 -1e-10"
for val in 3.14 2.718f -0.001 1e10 -1e-10; do
    ./convert "$val"
done
echo "--> a z "!" 9"
for val in a z "!" 9; do
    ./convert "$val"
done
echo "--> 65 127 31"
for val in 65 127 31; do
    ./convert "$val"
done

for val in hello 42abc 12..3 "" "." f --1; do
    ./convert "$val"
done

./convert 340282346638528859811704183484516925440.0f
./convert -340282346638528859811704183484516925440.0f
./convert 99999999999999999999999999999999999999999999999999999
