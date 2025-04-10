import sys;
input=lambda:sys.stdin.readline()
n,k=map(int,input().split())
a=list(map(int,input().split()))
x=[-1 for i in range(0,256)]
flag=[0 for i in range(0,256)]
s=1
ans=[]
for i in a:
    if(x[i]!=-1):
        for j in range(x[i],i+1):
            flag[i]=1
        ans.append(x[i])
        continue
    if(flag[i]==0):
        flag1=0
        for j in range(i,max(-1,i-k),-1):
            if(flag[j]==1):
                flag1=1
                for w in range(j+1,i+1):
                    x[w]=j+1
                    flag[w]=1
                for w in range(i+1,min(256,j+1+k)):
                    if(flag[w]==1):
                        break
                    x[w]=j+1

                break
        if(flag1==0):
            for w in range(max(0,i-k+1),i+1):
                x[w]=max(0,i-k+1)
                flag[w]=1
            for w in range(i+1,min(256,max(0,i-k+1)+k)):
                if(flag[w]==1):
                    break
                x[w]=max(0,i-k+1)
        
    ans.append(x[i])
print(' '.join(map(str,ans)))
