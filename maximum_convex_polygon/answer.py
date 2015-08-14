#!/usr/bin/env python

rawInput=raw_input()
splitNum=rawInput.split(';')

def compute_k(point1,point2):
    return float(point1[1]-point2[1])/float(point1[0]-point2[0])

points=[]
for i in range(len(splitNum)):
    if i==0:
        Num=int(splitNum[0])
    else:
        x,y=splitNum[i].split(',')
        points.append([int(x),int(y)])

# max_point and min_point

max_point = points[0]
min_point = points[0]
for i in range(1,len(points)):
    if points[i][0] > max_point[0]:
        max_point = points[i]

    if points[i][0] < min_point[0]:
        min_point = points[i]
print min_point, max_point

resultPoints = []

tempPoint=min_point

def get_index(temp_k, kAndLocation):
    for i in range(len(kAndLocation)):
        if temp_k == kAndLocation[i][1]:
            return kAndLocation[i][0]
resultPoints.append(tempPoint)
while True:
    tempAllK=[]
    tempAllKAndLocation=[]
    if tempPoint == max_point:
        break

    for i in range(len(points)):
        if points[i] == tempPoint or points[i][0] <= tempPoint[0]:
            continue
        else:
            temp_k = compute_k(points[i],tempPoint)
            tempAllK.append(temp_k)
            tempAllKAndLocation.append([i, temp_k])
    tempAllK.sort()
    next_index = get_index(tempAllK[-1], tempAllKAndLocation)
    tempPoint = points[next_index]
    resultPoints.append(tempPoint)
    print next_index
    print tempPoint
#    print tempAllKAndLocation
#    print tempAllK
#    break
#print Num, points

while True:
    tempAllK=[]
    tempAllKAndLocation=[]

    for i in range(len(points)):
        if points[i] == tempPoint or points[i][0] >= tempPoint[0]:
            continue
        else:
            temp_k = compute_k(points[i],tempPoint)
            tempAllK.append(temp_k)
            tempAllKAndLocation.append([i, temp_k])
    tempAllK.sort()
    next_index = get_index(tempAllK[-1], tempAllKAndLocation)
    tempPoint = points[next_index]
    if tempPoint == min_point:
        break
    resultPoints.append(tempPoint)
    print next_index
    print tempPoint

print resultPoints
