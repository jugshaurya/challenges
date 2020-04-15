n,m = [int(x) for x in input().split()]

# inputs
chefs = {}
countries = {}
# O(n)
for i in range(n):
	name, country = [x for x in input().split()]
	chefs[name] = country
	if(country in countries):
		countries[country] += 1
	else:
		countries[country] = 1
# O(m)
votes = {}
for i in range(m):
	name = input()
	if(name in votes):
		votes[name] += 1
	else:
		votes[name] = 1

# O(n)
# max
maxVotes = -1e9
maxCountries = -1e9
for ele in votes:
	maxVotes = max(maxVotes, votes[ele])
# O(m)
for ele in countries:
	maxCountries = max(maxCountries, countries[ele])


# max elements
max_voters = []
max_countries = []
for ele in votes:
	if(votes[ele] == maxVotes):
		max_voters.append(ele)

for ele in countries:
	if(countries[ele] == maxCountries):
		max_countries.append(ele)

l = sorted(max_voters)
m = sorted(max_countries)

print(m[0])
print(l[0])