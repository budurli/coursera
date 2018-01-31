def fibonacci(number):
    a = b = 1
    for _ in range(number):
        yield a
        a, b = b, a + b

for i in fibonacci(10):
    print(i)