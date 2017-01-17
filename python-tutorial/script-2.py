#!/usr/bin/env python

####################
# Define functions #
####################

# define the input query
def get_input():
  return input("Type something: ")

# determine whether this is a single character or a string
def check_length(string):
  if len(user_in) < 1:
    print("  Empty")
  elif len(user_in) < 2:
    print("  Character")
  else:
    print("  String")

################
# Begin script #
################

# get user input
user_in = get_input()

# repeat until a 'q' appears
while user_in.find("q") == -1:
  # check the length
  check_length(user_in)

  # request another input
  user_in = get_input()

print("Quit")
