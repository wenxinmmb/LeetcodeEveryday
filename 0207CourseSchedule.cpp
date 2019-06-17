// https://leetcode.com/problems/course-schedule/
//Topological Sort
class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        if(numCourses == 0 ||prerequisites.size() == 0)
            return true;
        vector<vector<int>> Adja(numCourses, vector<int>());
        vector<bool> looped( numCourses, false);
        vector<bool> cur_looped( numCourses, false);
        stack<int> cur;
        for(auto pre: prerequisites){
            Adja[pre[0]].push_back(pre[1]);
        }
        
        vector<int> cur_list;
        vector<int> res;
        int i;
        while(true){
            for( i = 0; i < numCourses; i++){
                if(!looped[i])
                    break;
            }
            if(i == numCourses)
                return true;
            cur.push(i);
            cur_looped = vector<bool>(numCourses, false);
            
            while(!cur.empty()){
                cur_list = Adja[cur.top()]; 
                if(cur_list.size() == 0){
                    cur_looped[cur.top()] = true;
                    looped[cur.top()] = true;
                    res.push_back(cur.top());
                    cur.pop();
                }
                else if(cur_looped[cur.top()])
                {
                    res.push_back(cur.top());
                    cur.pop();
                }
                else
                {
                    cur_looped[cur.top()] = true;
                    looped[cur.top()] = true;
                    for(auto tem: cur_list){
                        if(cur_looped[tem] && find(res.begin(), res.end(), tem) == res.end())
                            return false;
                        if(!looped[tem])
                            cur.push(tem);
                    }

                }
            }
        }
    }
};


//Better Solution
class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        if(numCourses==0)return true;
    vector<vector<int>> graph(numCourses);
        vector<int> indegree(numCourses);
        for(int i=0;i<prerequisites.size();i++)
        {
             graph[prerequisites[i][0]].push_back(prerequisites[i][1]);
             indegree[prerequisites[i][1]]++;
        }
       stack<int>st; int count=0;
                           for(int i=0;i<indegree.size();i++)
                              {
                                  if(indegree[i]==0)
                                      {st.push(i);
                                       count++;
                                      }
                              }
                             
                            while(!st.empty())
                              {
                                 int course=st.top();
                                
                                 st.pop();
        for(auto it=graph[course].begin();it!=graph[course].end();it++)
         {
               indegree[*it]--;
               if(indegree[*it]==0)
               {
                   st.push(*it);
                   count++;
               }
          }
                                  
     }  
                              if(count==numCourses)return true;
                              return false;
    }
};