class Solution {
    int Father[100005];
    int FindFather(int x)
    {
        if (Father[x]!=x)
            Father[x] = FindFather(Father[x]);
        return Father[x];
    }
    
    void Union(int x, int y)
    {
        x = Father[x];
        y = Father[y];
        if (x<y) Father[y] = x;
        else Father[x] = y;
    }     
public:
    vector<int>Eratosthenes(int n)
    {
        auto q=vector<int>(n+1,0);
        
        for (int i=2; i<=sqrt(n); i++)
        {
            if (q[i]==0)
            {
                int j=i*2;
                while (j<n)
                {
                    q[j]=1;
                    j+=i;
                }
            }
        }
        vector<int>primes;
        for (int i=2; i<=n; i++)
        {
            if (q[i]==0)
                primes.push_back(i);                
        }
        return primes;
    }

    bool gcdSort(vector<int>& nums) 
    {
        for (int i=0; i<100005; i++) Father[i] = i;
        
        vector<int>primes = Eratosthenes(100001);
                
        for (int i=0; i<nums.size(); i++)
        {
            int x = nums[i];
            for (auto p: primes)
            {                
                if (p > x) break;
                if (x%p==0)
                {                    
                    if (FindFather(nums[i])!=FindFather(p))                        
                        Union(nums[i],p);                        
                    while (x%p==0) x/=p;
                }
            }
        }
        
        auto nums1 = nums;
        sort(nums1.begin(), nums1.end());
                                
        for (int i=1; i<nums.size(); i++)
        {
            if (FindFather(nums[i]) != FindFather(nums1[i]))
                return false;
        }
        return true;
    }
};
