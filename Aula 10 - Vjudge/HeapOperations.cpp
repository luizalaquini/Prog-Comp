#include <iostream>
#include <queue>
#include <algorithm>
#include <bits/stdc++.h>
using namespace std;

priority_queue<int,vector<int>,greater<int> > q;
set<int> s;
set<int>::iterator it;

const int maxn=100005;
const int maxm=3200005;
const int inf=0x3f3f3f3f;

struct note {
    char s[15];
    int nums;
} vec[maxm],as[maxn];

char a[15];

int main() {
    ios::sync_with_stdio(false);
    int n,num,t;

    scanf("%d",&n);

    while(!q.empty()){
        q.pop();
    }

    s.clear();
    int top=0;

    for(int i=0; i<n; ++i) {
        scanf("%s",as[i].s);
        if(as[i].s[0]=='i') { ///insert
            scanf("%d",&as[i].nums);
        } else if(as[i].s[0]=='g') { ///getMin
            scanf("%d",&as[i].nums);
        }
    }

    for(int i=0; i<n; ++i) {
        strcpy(a,as[i].s);
        if(a[0]=='i') { ///insert
            num=as[i].nums;
            q.push(num);
            s.insert(num);
            strcpy(vec[top].s,a);
            vec[top++].nums=num;
        } else if(a[0]=='g') { ///getMin
            num=as[i].nums;
            if(q.size()==0) {
                strcpy(vec[top].s,"insert");
                vec[top++].nums=num;
                strcpy(vec[top].s,"getMin");
                vec[top++].nums=num;
                q.push(num);
                s.insert(num);
            } else if(s.find(num)!=s.end()) {
                while(true) {
                    t=q.top();
                    if(t==num) {
                        strcpy(vec[top].s,a);
                        vec[top++].nums=t;
                        break;
                    } else {
                        strcpy(vec[top].s,"removeMin");
                        vec[top++].nums=inf;
                        q.pop();
                        s.erase(t);
                    }
                }
            } else {
                while(true) {
                    if(q.size()==0) {
                        strcpy(vec[top].s,"insert");
                        vec[top++].nums=num;
                        strcpy(vec[top].s,"getMin");
                        vec[top++].nums=num;
                        q.push(num);
                        s.insert(num);
                        break;
                    }
                    t=q.top();
                    if(t>num) {
                        strcpy(vec[top].s,"insert");
                        vec[top++].nums=num;
                        strcpy(vec[top].s,"getMin");
                        vec[top++].nums=num;
                        q.push(num);
                        s.insert(num);
                        break;
                    } else {
                        strcpy(vec[top].s,"removeMin");
                        vec[top++].nums=inf;
                        q.pop();
                        s.erase(t);
                    }
                }
            }
        } else { ///removeMin
            if(q.size()==0) {
                q.push(1);
                s.insert(1);
                strcpy(vec[top].s,"insert");
                vec[top++].nums=1;
            }
            num=q.top();
            q.pop();
            s.erase(num);
            strcpy(vec[top].s,"removeMin");
            vec[top++].nums=inf;
        }
    }

    printf("%d\n",top);

    for(int i=0; i<top; ++i) {
        printf("%s",vec[i].s);
        if(vec[i].nums^inf)printf(" %d\n",vec[i].nums);
        else putchar(10);
    }

    return 0;
}