student=[]
n=int(input("Enter the number of students who attended the training : "))
for i in range(n):
    name=int(input("Enter the roll no of student : "))
    student.append(name)

print("students who attended the training are : ",student)


def binary(student, roll):
    student.sort()
    count = 0
    lo = 0
    hi=len(student)-1
    while(lo <= hi):
        count+=1
        mid = (hi+lo)//2
        if (student[mid] == roll):
            return ("Attended the program", count)
        elif (student[mid] < roll):
            lo = mid+1
        else:
            hi = mid-1
    return("Not attended", count)

#print(binary(student, roll))

def fibo(student, roll):
    student.sort()
    n = len(student)
    fib1 = 1
    fib2 = 0
    count = 0
    fibm = fib1 + fib2

    while(fibm < n):
        fib2 = fib1
        fib1 = fibm
        fibm = fib1 + fib2

    offset = -1
    while(fibm > 1):
        count+=1
        i = min(offset+fib2, n-1)
        if(student[i] > roll):
            fibm = fib2
            fib1 = fib1 - fib2
            fib2 = fibm - fib1
        elif(student[i] < roll):
            fibm = fib1
            fib1 = fib2
            fib2 = fibm - fib1
            offset = i+1
        else:
            return ("Attended the program",count)
    #if (fib1 and student[n - 1] == roll):
        #return ("Attended the program", count)


    return ("Not Attended" , count)

#print(fibo(student,roll))

print('''        Enter 1 for Binary Search 
        Enter 2 for Fibonacci search''')

while(True):
    choice = int(input("Enter the choice "))
    roll = int(input("Enter the roll"))
    if(choice == 1):
        print(binary(student, roll))
    elif(choice == 2):
        print(fibo(student, roll))
    else:
        print("Invalid choice")