#!/bin/bash

echo "Enter the basic salary:"
read basic_salary

# Calculate DA (40% of basic salary)
da=$(echo "scale=2; $basic_salary * 0.4" | bc)

# Calculate HRA (20% of basic salary)
hra=$(echo "scale=2; $basic_salary * 0.2" | bc)

# Calculate gross salary (basic salary + DA + HRA)
gross_salary=$(echo "scale=2; $basic_salary + $da + $hra" | bc)

echo "Basic Salary: $basic_salary"
echo "DA (40%): $da"
echo "HRA (20%): $hra"
echo "Gross Salary: $gross_salary"
