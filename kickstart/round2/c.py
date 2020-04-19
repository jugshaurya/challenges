import sys
sys.setrecursionlimit(11000)
t = int(input())
tc = t
while t:
	s = input()
	st = []
	for ele in s:
		if(ele == ")"):
			local = []
			while(st[-1]!="("):
				local.append(st.pop())
			st.pop()
			val = ord(st.pop()) - ord('0')
			# local = "".join(local)*val
			ans = []
			for i in range(val):
				for ele in local:
					ans.append(ele)
			local = "".join(ans)
			st.append(local)
		else:
			st.append(ele)
	f = ""
	while(len(st)>0):
		f += st.pop()
    
	reversedd = f[::-1]
	x = 1
	y = 1
	for ele in reversedd:
		if(ele=="S"):
			y+=1
		elif(ele=="N"):
			y-=1
		elif(ele=="E"):
			x+=1
		else:
			x-=1

	if(x<=0):
		x = 1000000000 + x
	if(y<=0):
		y = 1000000000 + y
	
	print("Case #", tc-t+1, ":",sep="",end=" ")
	print(x, y)

	t-=1

