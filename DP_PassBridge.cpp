// dynamic programming for fun 

// if there n people need to pass the bridge, only pass bridge with the only 1 torchlight, 
// at maximum 2 people can pass the bridge each time, if two people pass bridge, time spent is the one with larger time to pass bridge
// get the minimum time for n people to pass the bridge. 

// working on dynamic programming problem, dealt with analysis the optimal substructure

// the optimal structure is opt[i]= min{ opt[i-1] + a[1] + a[i], opt[i-2]+a[1] + a[i] + 2*a[2]}; 
