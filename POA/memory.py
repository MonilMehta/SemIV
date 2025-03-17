def firstFit(blockSize, m, processSize, n): 
	allocation = [-1] * n 
	for i in range(n): 
		for j in range(m): 
			if blockSize[j] >= processSize[i]: 
				allocation[i] = j  #first fit for the process
				blockSize[j] -= processSize[i] #update block size
				break

	print(" Process No. Process Size	 Block no.") 
	for i in range(n): 
		print(" ", i + 1, "		 ", processSize[i], "		 ", end = " ") 
		if allocation[i] != -1: 
			print(allocation[i] + 1)
			sum=0
			sum=sum+processSize[i]
			percent=sum*100/1700
		else: 
			print("Not Allocated") 
	print("utilization: ", percent)
			

def worstFit(blockSize, m, processSize, n): 

	allocation = [-1] * n 
	for i in range(n): 
		wstIdx = -1
		for j in range(m): 
			if blockSize[j] >= processSize[i]: 
				if wstIdx == -1: 
					wstIdx = j #first fit for the process
				elif blockSize[wstIdx] < blockSize[j]: #worst fit for the process, acc to block size
					wstIdx = j 
		if wstIdx != -1:  
			allocation[i] = wstIdx 
			blockSize[wstIdx] -= processSize[i] #update block size

	print("Process No. Process Size Block no.") 
	for i in range(n): 
		print(i + 1, "		 ", 
			processSize[i], end = "	 ") 
		if allocation[i] != -1: 
			print(allocation[i] + 1)
			sum=0
			sum=sum+processSize[i]
			percent=sum*100/1700
		else: 
			print("Not Allocated") 
	print("utilization: ", percent)
			

def bestFit(blockSize, m, processSize, n): 
    allocation = [-1] * n  
    for i in range(n): 
        bestIdx = -1
        for j in range(m): 
            if blockSize[j] >= processSize[i]: 
                if bestIdx == -1:  
                    bestIdx = j  #first fit for the process
                elif blockSize[bestIdx] > blockSize[j]: #worst fit for the process, acc to block size 
                    bestIdx = j  
        if bestIdx != -1: 
            allocation[i] = bestIdx   
            blockSize[bestIdx] -= processSize[i] #update block size
  
    print("Process No. Process Size     Block no.") 
    for i in range(n): 
        print(i + 1, "         ", processSize[i],  
                                end = "         ")  
        if allocation[i] != -1:  
            print(allocation[i] + 1)
            sum=0
            sum=sum+processSize[i]
            percent=sum*100/1700  
        else: 
            print("Not Allocated")
    print("utilization: ", percent)
  

# Driver code 
if __name__ == '__main__': 
	blockSize = [100, 500, 200, 300, 600] 
	blockSize1 = [100, 500, 200, 300, 600]
	blockSize2 = [100, 500, 200, 300, 600]
	processSize = [] 
	for i in range(4):
		processSize.append(int(input("Enter Process Size")))
	m = len(blockSize) 
	n = len(processSize) 
print(blockSize)
worstFit(blockSize, m, processSize, n) 
print(blockSize)
bestFit(blockSize1, m, processSize, n) 
print(blockSize)
firstFit(blockSize2, m, processSize, n) 
