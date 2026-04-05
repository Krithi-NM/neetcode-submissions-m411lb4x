class Solution {
    vector<int> toposort(int V, vector<int> adj[], vector<int>& present) {
        vector<int> indegree(V,0);
        for(int i=0;i<V;i++){
            for(auto it:adj[i]){
                indegree[it]++;
            }
        }
        queue<int> q;
        for(int i=0;i<V;i++){
            if(present[i] && indegree[i]==0){
                q.push(i);
            }
        }
        vector<int> topo;
        while(!q.empty()){
            int node=q.front();
            q.pop();
            topo.push_back(node);
            for(auto it:adj[node]){
                indegree[it]--;
                if(indegree[it]==0){
                    q.push(it);
                }
            }
        }
        return topo;
    }
public:
    string foreignDictionary(vector<string>& words){
        int N=words.size();
        int K=26;
        vector<int> adj[K];
        vector<int> present(26,0);

        for(auto word:words){
            for(char c:word){
                present[c-'a']=1;
            }
        }

        for(int i=0;i<N-1;i++){
            string s1=words[i];
            string s2=words[i+1];
            int len=min(s1.size(),s2.size());
            bool found=false;
            for(int j=0;j<len;j++){
                if(s1[j]!=s2[j]){
                    adj[s1[j]-'a'].push_back(s2[j]-'a');
                    found=true;
                    break;
                }
            }
            if(!found && s1.size()>s2.size()) return "";
        }

        vector<int> topo=toposort(K,adj,present);

        int countPresent=0;
        for(int i=0;i<26;i++){
            if(present[i]) countPresent++;
        }

        if(topo.size()<countPresent) return "";

        string ans="";
        for(auto it:topo){
            ans+=char(it+'a');
        }
        return ans;
    }
};


// class Solution {
//     vector<int>toposort(int v,vector<int>adj[]){
//         int indegree[v]={0};
//         for(int i=0;i<v;i++){
//             for(auto it:adj[i]){
//                 indegree[it]++;
//             }
//         }
//         queue<int>q;
//         for(int i=0;i<v;i++){
//             if(indegree[i]==0){
//                 q.push(i);
//             }
//         }
//         vector<int>topo;
//         while(!q.empty()){
//             int node=q.front();
//             q.pop();
//             topo.push_back(node);

//             for(auto it:adj[node]){
//                 indegree[it]--;
//                 if(indegree[it]==0)q.push(it);
//             }
//         }
//         return topo;
//     }
// public:
//     string foreignDictionary(vector<string>& words,int N,int k) {
//         vector<int>adj[k];
//         for(int i=0;i<N-1;i++){
//             string s1=words[i];
//             string s2=words[i+1];
//             int len=min(s1.size(),s2.size());
//             for(int ptr=0;ptr<len;ptr++)
//             if(s1[ptr]!=s2[ptr]){
//                 adj[s1[ptr]-'a'].push_back(s2[ptr]-'a');
//                 found = true;
//                 break;
//             }
//         }
//          if(!found && s1.size() > s2.size()){
//                 return "";
//             }
//         }

//         vector<int>topo=toposort(k,adj);
//         if(topo.size() < k) return "";
//         string ans="";
//         for(auto it:topo){
//             ans=ans+char(it+'a');
//         }
//         return ans;
//     }
// };
