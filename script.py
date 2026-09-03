from itertools import product


DIGITS = "9876543210"
TARGET = 200


def calculate(expression):
    numbers = []
    operators = []

    number = ""

    for char in expression:
        if char in "+-":
            numbers.append(int(number))
            operators.append(char)
            number = ""
        else:
            number += char

    numbers.append(int(number))

    result = numbers[0]

    for operator, number in zip(operators, numbers[1:]):
        if operator == "+":
            result += number
        else:
            result -= number

    return result


def find_solution():
    for operators in product(["+", "-", ""], repeat=9):
        expression = DIGITS[0]

        for digit, operator in zip(DIGITS[1:], operators):
            expression += operator + digit

        if calculate(expression) == TARGET:
            print(f"{expression} = {TARGET}")


if __name__ == "__main__":
    find_solution()