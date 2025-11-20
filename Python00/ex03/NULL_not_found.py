def NULL_not_found(object: any) -> int:
	if object == None:
		print(f"Nothing: {object} {type(object)}")
		return 0
	elif type(object) is float and object != object: #isinstance(object, float)
		print(f"Cheese: {object} {type(object)}")
		return 0
	elif type(object) is int and object == 0:
		print(f"Zero: {object} {type(object)}")
		return 0
	elif object == '':
		print(f"Empty: {object} {type(object)}")
		return 0
	elif object is False:
		print(f"Fake: {object} {type(object)}")
		return 0
	else:
		print("Type not Found")
		return 1