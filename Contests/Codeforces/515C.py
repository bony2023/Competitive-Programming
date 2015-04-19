Fact=[]
L=[]

def initFact():
    Fact.append(1)
    for i in xrange(1, 10):
        Fact.append(Fact[i-1]*i)
        
def parse(L, res):
    ret=0;
    for i in L:
        ret*=10
        ret+=i
    if res[0]<ret:
        res[0]=ret
        
def search(curr, target, res):
    if curr==target:
        parse(L, res)
        return
    i=9
    while i>=2:
        if curr*Fact[int(i)]<=target:
            L.append(i)
            search(curr*Fact[int(i)], target, res)
            L.pop()
        i-=1
        
def init(ans):
    ans.append('')
    ans.append('')
    for i in xrange(2, 10):
        res=[0]
        search(1, Fact[int(i)], res)
        ans.append(res[0]);

n=raw_input()
s=str(raw_input())
initFact()
ans=[]
init(ans)
res=str()
for c in s:
    res=res+str(ans[int(c)])
res=sorted(res, reverse=True)
final=str()
for c in res:
    final=final+c
print final