import sys

try:
	ac = len(sys.argv)

	if ac < 2:
		sys.exit(0)


	if ac > 2:
		raise AssertionError("more than one arguments is provided")

	try:
		num = int(sys.argv[1])
	except ValueError:
		raise AssertionError("argument is not an integer")

	if num%2 != 0:
		print("I'm Odd.")
	else:
		print("I'm Even.")

except AssertionError as e:
	print(f"AssertionError: {e}")
