  #include <iostream>
    #include <vector>

    using namespace std; 

    vector<int> initVec(){
        vector<int> vec; 
        vec.push_back(10); 
        vec.push_back(1); 
        vec.push_back(5);
        vec.push_back(3);
        vec.push_back(4);   
        return vec; 
    }
 
    bool isSubsetSum(vector<int> vec, int n, int sum){
        if (sum == 0) return true; 
        if (n==0 && sum != 0) return false;
        if (vec[n-1] > sum) return isSubsetSum(vec, n-1, sum); 
        return isSubsetSum(vec, n-1, sum) || isSubsetSum(vec, n-1, sum-vec[n-1]); 
    } 

    int main(int argc, char** argv)
    {
        cout << "start " << endl; 
        vector<int> vec = initVec();
        cout << "isSubsetSum:  " << isSubsetSum(vec, 4, 1) << endl; 
        return 0; 
    }  