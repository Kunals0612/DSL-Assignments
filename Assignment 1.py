se, cricket, badminton, football = [], [], [], []
n = int(input("Enter no. of students: "))
for i in range(n):
    name = input("Enter name of the person: ")
    se.append(name)
    choice1 = input("Does person play cricket? y-Yes ,n-No ")
    if choice1 == 'y':
        cricket.append(name)
    choice2 = input("Does person play badminton? y-Yes ,n-No ")
    if choice2 == 'y':
        badminton.append(name)
    choice3 = input("Does person play football? y-Yes ,n-No ")
    if choice3 == 'y':
        football.append(name)
print("Student list = ", se)
print("Students playing cricket =", cricket)
print("Students playing badminton =", badminton)
print("Students playing football =", football)

def intersection(cricket,badminton):
    inter=[]
    for i in cricket:
        if i in badminton:
            inter.append(i)
    return inter


def union(cricket,badminton):
    uni=[]
    uni=cricket.copy()
    for i in badminton:
        if i not in cricket:
            uni.append(i)
    return uni
def symdiff(cricket,badminton):
    x=union(cricket,badminton)
    y=intersection(cricket,badminton)
    sym=[]
    for i in x:
        if i not in y:
            sym.append(i)
    return sym
def cth(se,cricket,badminton):
    x=union(cricket,badminton)
    z=[]
    for i in se:
        if i not in x:
            z.append(i)
    return (z)

def dth(cricket,badminton,football):
    x=union(cricket,football)
    y=[]
    for i in x:
        if i not in badminton:
            y.append(i)
    return (y)


print('''Enter 1 for students who play both cricket and badminton
         Enter 2 for students who play either cricket or badminton but not both
         Enter 3 for students who play neither cricket nor badminton
         Enter 4 for students who play cricket and football but not badminton''')
while(True):
    choice=int(input("Enter the choice : "))
    if(choice == 1):
        print("Students who play both cricket and badminton : ", intersection(cricket, badminton))
    elif(choice == 2):
        print("student who play either cricket or badminton but not both : ", symdiff(cricket, badminton))
    elif (choice == 3):
        print("Who playes neither cricket nor badminton : ", cth(se, cricket, badminton))
    elif(choice == 4):
        print("Who play cricket and football but not badminton : ",dth(cricket,badminton,football))
    else:
        print("Invalid Input")