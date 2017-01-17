#/usr/bin/env python

# get user input
user_in = input("Type something: ")

# repeat until a 'q' appears
while user_in.find("q") == -1:
  # determine whether this is a single character or a string
  if len(user_in) < 1:
    print("  Empty")
  elif len(user_in) < 2:
    print("  Character")
  else:
    print("  String")

  # print each character
  for i in range(len(user_in)):
    print("    user_in[" + str(i) + "] = " + user_in[i])

  # print each character using built-in iterator
  for char in user_in:
    print("    " + char)

  # request another input
  user_in = input("Type something: ")

# notify that the loop has ended
print("Quit")
