#!/bin/bash

# ask user for name

echo Hi. What is your name?

read your_name

echo Nice to meet you $your_name

out="Nice to meet you $your_name"

echo $out

read -p 'Username: ' uservar
read -sp 'Password: ' passvar

echo Thanks $uservar for you password $passvar
