import math

def calculate_lcm(num1, num2):
    gcd = math.gcd(num1, num2)
    lcm = (num1 * num2) // gcd
    return lcm

def calculate_gcd(num1, num2):
    gcd = math.gcd(num1, num2)
    return gcd

def calculate_sum(num1, num2):
    return num1 + num2

def calculate_difference(num1, num2):
    return num1 - num2

def calculate_product(num1, num2):
    return num1 * num2

def calculate_quotient(num1, num2):
    if num2 == 0:
        return "Cannot divide by zero!"
    return num1 / num2

# Example usage for LCM, GCD, sum, difference, product, and quotient calculation:
num1 = float(input("Enter the first number: "))
num2 = float(input("Enter the second number: "))

lcm_result = calculate_lcm(int(num1), int(num2))
gcd_result = calculate_gcd(int(num1), int(num2))
sum_result = calculate_sum(num1, num2)
difference_result = calculate_difference(num1, num2)
product_result = calculate_product(num1, num2)
quotient_result = calculate_quotient(num1, num2)

print(f"The Least Common Multiple of {int(num1)} and {int(num2)} is: {lcm_result}")
print(f"The Greatest Common Factor of {int(num1)} and {int(num2)} is: {gcd_result}")
print(f"The Sum of {num1} and {num2} is: {sum_result}")
print(f"The Difference of {num1} and {num2} is: {difference_result}")
print(f"The Product of {num1} and {num2} is: {product_result}")
print(f"The Quotient of {num1} and {num2} is: {quotient_result}")