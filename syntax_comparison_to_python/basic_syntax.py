import sys

# Prompt the user for the number of elements
try:
    n = int(input('How many numbers do you want to enter? '))
except ValueError:
    print('Invalid input. Please enter a positive integer.')
    sys.exit(1)

if n <= 0:
    print('Number of elements must be a positive integer.')
    sys.exit(1)

# Read the numbers into a list using a loop
numbers = []
for i in range(n):
    try:
        val = float(input(f'Enter number {i+1}: '))
    except ValueError:
        print('Invalid input.')
        sys.exit(1)
    numbers.append(val)

# Compute and display the maximum
print(f'The maximum number is: {max(numbers)}')

# Exit with a success status code
sys.exit(0)
