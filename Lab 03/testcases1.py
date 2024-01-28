import random

def generate_testcase(file_path, num_testcases):
    with open(file_path, 'w') as file:
        file.write(f"{num_testcases}\n")

        for _ in range(num_testcases):
            rows_A = random.randint(1, 5)  # Random number of rows for matrix A (1 to 5)
            cols_A = random.randint(1, 5)  # Random number of columns for matrix A (1 to 5)

            rows_B = cols_A  # Number of rows for matrix B is equal to the number of columns in A
            cols_B = random.randint(1, 5)  # Random number of columns for matrix B (1 to 5)

            file.write(f"{rows_A} {cols_A} {rows_B} {cols_B}\n")

            # Write elements of matrix A
            for _ in range(rows_A):
                row_elements = ' '.join(str(random.randint(1, 10)) for _ in range(cols_A))
                file.write(f"{row_elements}\n")

            # Write elements of matrix B
            for _ in range(rows_B):
                row_elements = ' '.join(str(random.randint(1, 10)) for _ in range(cols_B))
                file.write(f"{row_elements}\n")

if __name__ == "__main__":
    num_testcases = 100  # Change this to the desired number of test cases
    generate_testcase("input1.txt", num_testcases)
