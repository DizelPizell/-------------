package main

import (
	"fmt"
	"strconv"
	"strings"
)

const (
	digits = "9876543210"
	target = 200
)

func calculate(expression string) int {
	var numbers []int
	var operators []rune

	var number strings.Builder

	for _, char := range expression {
		if char == '+' || char == '-' {
			value, _ := strconv.Atoi(number.String())
			numbers = append(numbers, value)
			operators = append(operators, char)
			number.Reset()
		} else {
			number.WriteRune(char)
		}
	}

	value, _ := strconv.Atoi(number.String())
	numbers = append(numbers, value)

	result := numbers[0]

	for i, operator := range operators {
		if operator == '+' {
			result += numbers[i+1]
		} else {
			result -= numbers[i+1]
		}
	}

	return result
}

func findSolutions() {
	operators := []string{"+", "-", ""}

	for mask := 0; mask < 19683; mask++ {
		temp := mask
		var expression strings.Builder

		expression.WriteByte(digits[0])

		for i := 1; i < len(digits); i++ {
			operator := operators[temp%3]
			temp /= 3

			expression.WriteString(operator)
			expression.WriteByte(digits[i])
		}

		result := calculate(expression.String())

		if result == target {
			fmt.Printf("%s = %d\n", expression.String(), target)
		}
	}
}

func main() {
	findSolutions()
}
