class NumArray {
public:
    int n;
    vector<int> fenwick;
    vector<int> arr;
    NumArray(vector<int>& nums) {
        n=nums.size();
        arr=nums;
        fenwick.resize(n+1,0);
        for(int i=1;i<=n;i++){
            build(i,arr[i-1]);
        }
    }
    void build(int idx,int val){
        while(idx <=n){
            fenwick[idx] += val;
            idx+=(idx & (-idx)); 
        }
    }
    void update(int index, int val) {
        int dif=val-arr[index];
        int j=index+1;
        while(j<=n){
            fenwick[j] +=dif;
            j += (j & (-j));
        }
        arr[index]=val;
    }
    int sum(int idx){
        int s=0;
        int j=idx+1;
        while(j>0){
            s+=fenwick[j];
            j-=(j &(-j));
        }
        return s;
    }
    int sumRange(int left, int right) {
        return sum(right)-sum(left-1);
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(index,val);
 * int param_2 = obj->sumRange(left,right);
 */