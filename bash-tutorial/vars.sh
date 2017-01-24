#!/bin/bash

a=Hello
b=World

echo $a $b
echo

dir=/home-1/class-2@jhu.edu

ls $dir

# single quotes are literal
c='Hello World'
echo $c

# double quotes substitute variables
d="Big $c"
echo $d

# no quotes read next word only

echo

# save contents of command in variable
e=$(ls $dir | wc -l)
echo $e
