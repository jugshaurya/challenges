mod = 1000000007

t = int(input())
while(t):
	n, a = [int(x) for x in input().split()]
	dp = [ -1, a, ]
	last = (a + pow(a, 6 ,mod)%mod);
	if(n==1) :
		print(a)
		t-=1
		continue
	if(n==2) :
		print(last)
		t-=1
		continue

	total = 6
	base = 2
	for i in range(3, n+1):
		power = pow(a, ((2*total)%mod*i)%mod,mod)
		power = power * pow(a,-1*total)
		power = power % mod
		power = power * pow(a, ((2*base)%mod*i)%mod, mod)
		power = power * pow(a,-1*base)
		power = power % mod
		total = (((total + base)%mod)*((2*i-1)%mod))%mod
		base = (total + base)%mod
		last = last + power
	print(int(last))
	t-=1

