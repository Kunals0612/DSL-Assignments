#Write a python program to compute following computation on matrix:
#a) Addition of two matrices b) Subtraction of two matrices
#c) Multiplication of two matrices d) Transpose of a matrix
n1=int(input("Enter the row of matrix1 : "))
m1=int(input("Enter the column of matrix1 : "))
print("Enter the value of matrix 1")
matrix1=[]
for i in range(n1):
    r=[]
    for j in range(m1):
        print("Enter the row",i+1,"and column",j+1)
        r.append(int(input()))
    matrix1.append(r)


#matrix 2
n2=int(input("Enter the row of matrix2 : "))
m2=int(input("Enter the column of matrix2 : "))
print("Enter the values for second matrix : ")
matrix2=[]
for i in range(n2):
    r=[]
    for j in range(m2):
        print("Enter the row",i+1,"and column",j+1)
        r.append(int(input()))
    matrix2.append(r)


print("The first matrix is : ")
#output 1
for i in range(n1):
    for j in range(m1):
        print(matrix1[i][j],end=" ")
    print()

print("The second matrix is : ")
#output 2
for i in range(n2):
    for j in range(m2):
        print(matrix2[i][j],end=" ")
    print()
#addition
def add(matrix1,matrix2,n1,n2,m1,m2):
    if(n1==n2 and m1==m2):
        print("Addition of given matrices are : ")
        for i in range(n1):
            for j in range(m1):
                print(matrix1[i][j]+matrix2[i][j],end=" ")
            print()
    else:
        print("Addition is not possible for these indices.....")

#substraction
def sub(matrix1,matrix2,n1,n2,m1,m2):
    if(n1==n2 and m1==m2):
        print("Substraction of given matrices are : ")
        for i in range(n1):
            for j in range(m1):
                print(matrix1[i][j]-matrix2[i][j],end=" ")
            print()
    else:
        print("subtraction is not possible for these indices....")
#multiplication
def cross(matrix1,matrix2,n1,n2,m1,m2):
    mul=[[0 for i in range(m2)]for j in range(n1)]
    print("multiplication of given matrices are : ")
    for i in range(n1):
        for j in range(m2):
            multi=0
            for k in range(n2):
                multi+=matrix1[i][k]*matrix2[k][j]
            mul[i][j]=multi
    for i in range(n1):
        for j in range(m2):
            print(mul[i][j],end=" ")
        print()
#transpose
def transpose(matrix1,n1,m1):
    print("Transpose of the matrix is : ")
    tran=[[0 for i in range(n1)] for j in range(m1)]
    for i in range(m1):
        for j in range(n1):
            tran[i][j]=matrix1[j][i]
    for i in range(m1):
        for j in range(n1):
           print(tran[i][j],end=" ")
        print()
while(True):
    print("-------------------------MENU BAR-------------------------")

    print('''  Enter 1 for Addition
               Enter 2 for Subtraction
               Enter 3 for Multiplication
               Enter 4 for Transpose''')
    choice=int(input("Enter your choice : "))
    if(choice == 1):
        add(matrix1, matrix2, n1, n2, m1, m2)
    elif(choice == 2):
        sub(matrix1, matrix2, n1, n2, m1, m2)
    elif(choice == 3):
        cross(matrix1, matrix2, n1, n2, m1, m2)
    elif(choice == 4):
        transpose(matrix1, n1, m1)
    else:
        print("Invalid Input")