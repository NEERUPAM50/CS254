import random

def generate_testcases(filename, num_testcases, max_array_size, max_element_value):
    with open(filename, 'w') as file:
        file.write(str(num_testcases) + '\n')
        
        for _ in range(num_testcases):
            n = random.randint(1, max_array_size)
            array = [random.randint(-max_element_value, max_element_value) for _ in range(n)]
            
            file.write(str(n) + '\n')
            file.write(' '.join(map(str, array)) + '\n')

# Example usage:
generate_testcases("input2.txt", num_testcases=10000, max_array_size=10, max_element_value=100)
