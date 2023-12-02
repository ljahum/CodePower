cardPoints =[1,2,3,4,5,6,1]

k = 3



n = len(cardPoints)

wide = n-k
minValue = sum(cardPoints[:wide])
tmp = minValue
for i in range(0,k):
    print(i+wide,i)
    print(cardPoints[wide+i],cardPoints[i])
    tmp = tmp +(cardPoints[wide+i]-cardPoints[i])
    minValue = min(tmp,minValue)
    

ans = sum(cardPoints)-minValue
print(ans)
    
