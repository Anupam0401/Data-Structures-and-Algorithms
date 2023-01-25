# Write a program to print maximum and minimum elements of the input array A of size N. The only line of the input would contain a single integer N that represents the length of the array followed by the N elements of the input array A

def main():
    # YOUR CODE GOES HERE
    # Please take input and print output to standard input/output (stdin/stdout)
    # E.g. 'input()/raw_input()' for input & 'print' for output

    # Read the input
    # N = int(input())
    A = [int(x) for x in input().split()]
#n is the first element of the lsit
    n = A[0]
    # A = A[1:]
    
    # Find the maximum and minimum elements
    max = A[0]

    

if __name__ == '__main__':
    main()