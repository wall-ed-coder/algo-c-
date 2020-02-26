#include<iostream>
#include<vector>
#include<queue>
using namespace std;


//бинарное возведение в степень
long long binary_pow(long long a, long long p){
  /*
  основана на том, что степень p может быть четной и мы может ускорять
  возведение в степени из-за делимости на два
  */
  if(p==0) return 1;
  if(p%2==0){
    long long b = binary_pow(a,p/2);
    return b*b;
  }
  else{
    return a*binary_pow(a,p-1);
  }
}


/*
алгоритм решето эратросфена
будем смотреть простые числа до числа 'a'
*/
vector<bool> sieve_arathrosfien(long long a){
  // a - до какого числа смотрим простые числа
  vector<bool> v(a+1,true);
  v[0]=v[1]=true;
  for(int i=2;i<a+1;i++){
    if(v[i]){
      for(int j=i+i;j<a+1;j+=i) v[j]=false;
    }
  }
  return v;
}


// алгоримт Евклида на нахождение НОД
int gcd(int a,int b){
  if(a==0) return b;
  return gcd(b%a,a);
}

// нахождение НОК
int lcm(int a,int b){
  return a*b/gcd(a,b);
}

// поиск в ширину
void bsf(vector< vector<int> > v,int find_min_to_v, int start=0){
  queue<int> q;
  q.push(start);
  vector<bool> used(v.size(),false);
  used[start]=true;
  vector<int> d(v.size());
  //массив длины путей, нужен для восстановления пути кратчайшего
  vector<int> p(v.size());//массив предков, нужен для восстановления пути кратчайшего
  p[start]=-1;
  while(!q.empty()){
    int vertex = q.front();
    q.pop();
    for(int i=0;i<v[vertex].size();i++){
      int new_vertex = v[vertex][i];
      if(!used[new_vertex]){
        q.push(new_vertex);
        used[new_vertex]=true;//new_vertex посещена
        d[new_vertex]=d[vertex]+1;// длина пути до new_vertex = длина пути до
        //ее предка +1
        p[new_vertex]=vertex;//предок новой вершины(new_vertex) - vertex
      }
    }
  }
  if (!used[find_min_to_v]) cout << "No path!";
  //вершина не связанная
  else {
    vector<int> path;
    for(int i=find_min_to_v; i!=-1; i=p[i]) path.push_back(i);
    reverse (path.begin(), path.end());// чтобы печатало от вершины,
    // которую надо найти
    cout << "Path: ";
    for (int i=0; i<path.size(); i++) cout << path[i] + 1 << " ";
  }
}

// обход в глубину
void _dfs(vector< vector<int> > v, vector<bool> &used,int vertex=0){
  for(int i=0;i<v[vertex].size();i++){
    if(!used[i]) {
      used[i]=true;
      _dfs(v,used,i);
    }
  }
}
void dfs(vector< vector<int> > v, int vertex=0){
  vector<bool> used(v.size(),false);
  used[vertex]=true;
  _dfs(v,used,vertex);
}



int main(){
  return 0;
}
