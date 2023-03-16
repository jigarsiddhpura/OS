from functools import reduce
from statistics import mean

arrTime = [0,1,2,3,4]
burstTime = [4,3,1,2,5]
ganttC = [0]
dict = {}

for a,b in list(zip(arrTime,burstTime)):
    dict[a] = b

dict = sorted(dict.items())
compTime = burstTime[0] 
sum = 0

for key,value in dict:
    ganttC.append(sum+value)
    sum += value

turnAroundTime = [x-y for x,y in zip(ganttC[1:] , sorted(arrTime))]
weightingTime = [x-y for x,y in zip(turnAroundTime , burstTime)]

avgWT = mean(weightingTime)
avgTAT = mean(turnAroundTime)

print(avgTAT,avgWT)









