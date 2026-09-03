#include <stdio.h>
#include <string.h>

#define TARGET 200
#define DIGITS "9876543210"
#define OPERATORS_COUNT 3

const char operators[] = "+-";

int calculate(const char *expression)
{
    int result = 0;
    int number = 0;
    char operation = '+';

    for (int i = 0; expression[i] != '\0'; i++)
    {
        char c = expression[i];

        if (c >= '0' && c <= '9')
        {
            number = number * 10 + (c - '0');
        }
        else
        {
            if (operation == '+')
                result += number;
            else
                result -= number;

            operation = c;
            number = 0;
        }
    }

    if (operation == '+')
        result += number;
    else
        result -= number;

    return result;
}

void find_solutions(void)
{
    char expression[20];

    for (int mask = 0; mask < 19683; mask++)
    {
        int value = mask;

        int position = 0;

        expression[position++] = DIGITS[0];

        for (int i = 1; i < 10; i++)
        {
            int choice = value % OPERATORS_COUNT;
            value /= OPERATORS_COUNT;

            if (choice == 0)
            {
                // Ничего не добавляем.
            }
            else
            {
                expression[position++] = operators[choice - 1];
            }

            expression[position++] = DIGITS[i];
        }

        expression[position] = '\0';

        if (calculate(expression) == TARGET)
        {
            printf("%s = %d\n", expression, TARGET);
        }
    }
}

int main(void)
{
    find_solutions();

    return 0;
}
