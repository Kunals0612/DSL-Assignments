def longest():
    n = input("Enter the string : ")
    words = n.split(" ")
    max = 0
    for i in words:
        if(len(i) >= max):
            max = len(i)
    for i in words:
        if(len(i)==max):
            print(i)

def occurance():
    n = input("Enter the string : ")
    words=n.split(" ")
    x=input("Enter the word whose frequency is to be checked : ")
    count=0
    for i in words:
        if(i==x):
            count+=1
    print(count)

def palindrom():
    n=input("Enter the string for palindrom : ")
    if(n==n[::-1]):
        print("yes it is palindrom")
    else:
        print("It is not palindrom")
def substring():
    n=input("Enter the string : ")
    m=input("Enter the substring : ")
    words=n.split(" ")
    print(n.find(m))
def frequency():
    n=input("Enter the string : ")
    m=input("Enter the character : ")
    count = 0
    for i in range(len(n)):
        if (n[i] == m):
            count += 1
    print(count)
s="MENU BAR"
print(s.ljust(100,"-"))

print('''Enter 1 for word with longest length 
         Enter 2 for frequency of characters 
         Enter 3 for palindrome
         Enter 4 to print first occured index of substring in given string
         Enter 5 to check number of occurence of word  ''')
while(True):
    c = int(input("Enter your Choice : "))
    if(c==1):
        longest()
    elif(c==2):
        frequency()
    elif(c==3):
        palindrom()
    elif(c==4):
        substring()
    elif(c==5):
        occurance()
    else:
        print("Invalid Input Please follow instructions of menubar ")
