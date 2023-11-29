student=[]
n=int(input("Enter the number of students who attended the training : "))
for i in range(n):
    name=int(input("Enter the roll no of student : "))
    student.append(name)

print("students who attended the training are : ",student)
roll=int(input("Enter the roll"))

def search(student):
    flag = False
    count=0
    for i in student:
        if(i==roll):
            flag=True
            count+=1
            break
        count+=1
    if(flag==False):
        print("Roll no", roll, "didn't attend the program")
    else:
        print("Roll no", roll, "attended the program")
    print(count)


def sentinal(student,roll,n):
    count=0
    last = student[n-1]
    student[n-1] = roll
    i = 0
    while(student[i]!=roll):
        i+=1
        count+=1
    student[n-1] = last
    if((i<n-1) or (student[n-1] == roll)):
        print(roll," is present")
    else:
        print(roll," is not present" )
    print(count)
print('''      Enter 1 for Linear Search 
        Enter 2 for sentinal search''')
while(True):
    choice = int(input("Enter the choice : "))
    if(choice == 1):
        search(student)
    elif(choice == 2):
        sentinal(student, roll, n)
    else:
        print("Invalid Input")
