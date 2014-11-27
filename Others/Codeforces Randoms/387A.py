tmp=input().split(':')
currhr=int(tmp[0]); currmin=int(tmp[1])
tmp=input().split(':')
takenhr=int(tmp[0]); takenmin=int(tmp[1])

if currmin<takenmin:
    currmin+=60
    currhr-=1
    
tmp=int(currhr-takenhr+24)%24
s=""

if tmp<=9:
    s='0'

s=s+str(tmp)
    
s=s+':'
tmp=int(currmin-takenmin)

if tmp<=9:
    s=s+'0'
    
s=s+str(tmp)
print(s)