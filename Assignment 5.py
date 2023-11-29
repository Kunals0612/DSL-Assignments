def bubblesort(student):
    n = len(student)
    count = 0
    for i in range(n):
        count += 1
        flag = False
        for j in range(n - i - 1):
            if (student[j] < student[j + 1]):
                student[j], student[j + 1] = student[j + 1], student[j]
                flag = True
        print("Pass",i+1,": ",student)
        if (flag == False):
            break
    print(count)


def selectionsort(student):
    count = 0
    n = len(student)
    for i in range(n - 1):
        count += 1
        min_idx = i
        for j in range(i + 1, n):
            if (student[j] > student[min_idx]):
                min_idx = j
        if (min_idx != i):
            student[i], student[min_idx] = student[min_idx], student[i]
        print("Pass", i + 1, ": ", student)
    print(count)

def insertionsort(student):
    n = len(student)
    for i in range(1,n):
        key = student[i]
        j = i-1
        while j>=0 and key > student[j]:
            student[j+1] = student[j]
            j-=1
        student[j+1] = key
        print("Pass", i + 1, ": ", student)
# def shellsort(student):
#     n = len(student)




if __name__ == "__main__":
    student = []
    num = int(input("Enter the total numbers of student : "))
    for i in range(num):
        print("Enter the marks of", i + 1, "th student : ", end=" ")
        x = float(input())
        student.append(x)
    # (bubblesort(student))
    # print("sorted list by percentage bubble : ", student)
    print('''Enter 1 for bubble sort
             Enter 2 for selection sort
             Enter 3 for insertion sort''')
    choice = int(input("Enter the choice : "))
    if (choice == 1):
        bubblesort(student)

        print("Top five students are : ",student[:5])

    elif (choice == 2):
        selectionsort(student)

        print("Top five students are : ", student[:5])
    elif (choice == 3):
        insertionsort(student)
    else:
        print("Invalid choice")