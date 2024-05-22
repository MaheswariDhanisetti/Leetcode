class Solution {
public:
    int strStr(string h, string n) {
        int n1=h.size(),n2=n.size();
        if(n2>n1){
            return -1;
        }
        for(int i=0;i<=(n1-n2);i++){
            if(h[i]==n[0]){
                int j;
                for(j=i;j<i+n2;j++){
                    if(h[j]!=n[j-i]){
                        break;
                    }
                }
                if(j==i+n2){return i;}
            }
        }
        return -1;
    }
};
