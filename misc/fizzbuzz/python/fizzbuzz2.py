for i in range(1,101):
    buzz = (not i % 5) * "Buzz"
    fizz = (not i % 3) * "Fizz"

    if fizz or buzz:
        print fizz+buzz
    else:
        print i
