#!/bin/bash

function print_hello {
  echo HELLO!
}

let a=30/2

echo $a

b=$((5+10))

echo $b

c="hello"
d="hello"

if [ $a -eq $b ]
then
  echo equal
else
  echo not equal
fi

if [ $a -gt $b ]
then
  echo a greater than b
else
  echo a not greater than b
fi

print_hello
