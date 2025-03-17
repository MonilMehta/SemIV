def conversion(a,count):
    cur=len(a)
    if(cur!=count):
        q=''
        c=count-cur
        q="0"*c+a
        return q
    return a

def add(x,y):
    max_len=max(len(x),len(y))
    result=''
    carry=0
    for i in range(max_len-1,-1,-1):
        r=carry
        if(x[i]=='1'):
            r+=1
        if(y[i]=='1'):
            r+=1
        if(r%2==1):
            result="1"+result
        else:
            result="0"+result
        if r<2:
            carry=0
        else:
            carry=1

    return result

def twoscomplement(a):
    l=list(a)
    for i in range(len(l)):
        if l[i]=="1":
            l[i]='0'
        else:
            l[i]='1'
    b="0"*(len(l)-1)+"1"
    return add("".join(l),b)

def leftshift(ac,q):
    a,b="",""
    for i in range(0,len(ac)-1):
       a+=ac[i+1]
    a+=q[0]
    for i in range(0,len(q)-1):
       b+=q[i+1]
    return a,b

x=int(input())
y=int(input())

print(f'Q is {x}')
print(f'M is {y}')

a=bin(x).replace("0b","")
b=bin(y).replace("0b","")

if(len(a)>len(b)):
    count=len(a)+1
else:
    count=len(b)+1

Q=conversion(a,count-1)
M=conversion(b,count)
M2=twoscomplement(M)
AC="0"*(count)

while(count>1):
    AC,Q=leftshift(AC,Q)
    
    if AC[0]=='1':
        AC=add(AC,M)
    else:
        AC=add(AC,M2)
    Q+= '1' if AC[0]=='0' else '0'
    count-=1

print(f'Quotient is {int(AC,2)}')
print(f'Remainder is {int(Q,2)}')
    


