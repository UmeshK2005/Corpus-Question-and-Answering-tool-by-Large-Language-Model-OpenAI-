#include <assert.h>
#include <sstream>
#include "qna_tool.h"

using namespace std;

char separatorss[] = {' ', '.', ',', '-', ':', '!', 39, 34, '(', ')', '?', '[', ']', ';', '@'};

bool isseparator(char c) {
    for (char ch:separatorss) {
        if (ch == c) {
            return true;
        }
    }
    return false;
}
int m_ans(string word,int n){
  //cout<<"dfn"<<n<<endl;
   vector<char>v;
   for(int i=0;i<n;i++){
    char c=tolower(word[i]);
   // a.push_back(c);
 //   cout<<c<<" "<<word[i]<<endl;
    if (i==0){
      if ((c=='a')or (c=='e') or (c=='i') or (c=='o') or (c=='u')){
        v.push_back('V');
      }
      else{
        v.push_back('C');
      }
    }
    else{//if (c=='y'){cout<<v[v.size()-1]<<"hi"<<endl;}
      //cout<<c<<endl;
      char x=v[v.size()-1];
      if ((c=='a')or (c=='e') or (c=='i') or (c=='o') or (c=='u') or ((c=='y' and x=='C'))){
   //     cout<<"hii"<<endl;
        v.push_back('V');
      }
      else{//cout<<"fsd"<<endl;
        v.push_back('C');
      }
    }
  }
  //cout<<"rex"<<endl;
 // for (int i=0;i<n;i++){
  //  cout<<v[i]<<" ";
  //}
  //cout<<endl;
 // cout<<"hi"<<endl;
 vector<char>v2;
 if(v.size()==0){return 0;}
 char k=v[0];
 v2.push_back(k);
 for(int i=1;i<n;i++){
   
   char c=v[i];
 //  cout<<c<<" "<<k<<i<<endl;
   if (c!=k){
     v2.push_back(c);
     k=c;
   }
   else{
     continue;
   }
 }
 int m=0;
 if (v2[0]=='C'){
   if (v2[v2.size()-1]=='V'){m=(v2.size()-2)/2;}
   else{
     m=(v2.size()-1)/2;
   }
 }
 else{
   if (v2[v2.size()-1]=='V'){m=(v2.size()-1)/2;}
   else{
     m=(v2.size()-2)/2;
   }
 }
 return m;
}






string port_stem(string word){

  int n=word.size();
//  cout<<m_ans(word,n)<<endl;
  vector<char>v;
  vector<char>a;
  bool vowel=false;
  for(int i=0;i<n;i++){
    char c=tolower(word[i]);
    a.push_back(c);
    if (i==0){
      if ((c=='a')or (c=='e') or (c=='i') or (c=='o') or (c=='u')){
        vowel=true;
        v.push_back('V');
      }
      else{
        v.push_back('C');
      }
    }
    else{//if (c=='y'){cout<<v[v.size()-1]<<"hi"<<endl;}
      if ((c=='a')or (c=='e') or (c=='i') or (c=='o') or (c=='u') or ((c=='y' and v[v.size()-1]=='C'))){
   //     cout<<"hii"<<endl;
        vowel=true;
        v.push_back('V');
      }
      else{
        v.push_back('C');
      }
    }
  }
 // cout<<"hi"<<endl;
//Conditions starts here :- 
  n=word.size();
  int n1=n;
  
  if((n>=4) and (a[n-1]=='s') and (a[n-2]=='e') and (a[n-3]=='s') and (a[n-4]=='s')){
    a[n-1]='*';
    a[n-2]='*';
    n=n-2;
  }
  if((n>=3) and (a[n-1])=='s' and(a[n-2]=='e')and (a[n-3]=='i')){
    a[n-1]='*';
    a[n-2]='*';
    n=n-2;
  }
  if((n>=1)and (a[n-1]=='s')){
    a[n-1]='*';
    n=n-1;
  }
 // cout<<m_ans(word,n-3)<<endl;
  if((n>=3)and (m_ans(word,n-3)>0) and (a[n-1]=='d')and (a[n-2]=='e')and (a[n-3]=='e')){
    a[n-1]='*';
    n-=1;
  }
  
  bool x=false;
  if((n>=2) and (vowel==true) and (a[n-1]=='d')and (a[n-2]=='e')){
    a[n-1]='*';
    a[n-2]='*';
    n=n-2;
    x=true;
  }
  if((n>=3)and(vowel==true) and (a[n-1]=='g')and (a[n-2]=='n')and (a[n-3]=='i')){
    
    a[n-1]='*';
    a[n-2]='*';
    a[n-3]='*';
    n=n-3;
    x=true;
  }
  
  if((x==true)and (n>=2)and ((a[n-1]=='t')or (a[n-1]=='l') or(a[n-1]=='z'))and((a[n-2]=='a')or(a[n-2]=='b')or(a[n-2]=='i'))){
    if(n==n1){
      n+=1 ;
      n1+=1 ;
      a.push_back('e');
    }
    else{
      n+=1;
      a[n-1]='e';
    }
  }
  if((x==true)and(n>=2)and((a[n-1]!='l')or(a[n-1]!='s')or(a[n-1]!='z')or(a[n-1]!='a')or(a[n-1]!='e')or(a[n-1]!='i')or(a[n-1]!='o')or(a[n-1]!='u'))and(a[n-1]==a[n-2])){
    a[n-1]='*';
    n-=1;
  }
  if((x==true)and(n>=3)and(m_ans(word,n)==1)and(v[n-1]=='C')and(v[n-2]=='V')and(v[n-3]=='C')and((a[n-1]!='w')or(a[n-1]!='x')or(a[n-1]!='y'))){
    if(n==n1){
      n+=1 ;
      n1+=1 ;
      a.push_back('e');
    }
    else{
      n+=1;
      a[n-1]='e';
    }
  }
  if((n>=1)and(vowel==true)and(a[n-1]=='y')){
    a[n-1]='i';
  }
////step 2 

  

  if((n>=7)and(m_ans(word,n-7)>0)and(a[n-7]=='a')and(a[n-6]=='t')and(a[n-5]=='i')and(a[n-4]=='o')and(a[n-3]=='n')and(a[n-2]=='a')and(a[n-1]=='l')){
    a[n-5]='e';
    a[n-4]='*';
    a[n-3]='*';
    a[n-2]='*';
    a[n-1]='*';
    n=n-4;
  }
 
  if((n>=6)and(m_ans(word,n-6)>0)and(a[n-6]=='t')and(a[n-5]=='i')and(a[n-4]=='o')and(a[n-3]=='n')and(a[n-2]=='a')and(a[n-1]=='l')){
    a[n-2]='*';
    a[n-1]='*';
    n=n-2;
  } 
 
  if((n>=4)and(m_ans(word,n-4)>0)and(a[n-4]=='e')and(a[n-3]=='n')and(a[n-2]=='c')and(a[n-1]=='i')){
    
    a[n-1]='e';
  }
  
  if((n>=4)and(m_ans(word,n-4)>0)and(a[n-4]=='a')and(a[n-3]=='n')and(a[n-2]=='c')and(a[n-1]=='i')){
    
    a[n-1]='e';
  }
  if((n>=4)and(m_ans(word,n-4)>0)and(a[n-4]=='i')and(a[n-3]=='z')and(a[n-2]=='e')and(a[n-1]=='r')){
    
    a[n-1]='*';
    n-=1;
  }
  if((n>=4)and(m_ans(word,n-4)>0)and(a[n-4]=='a')and(a[n-3]=='b')and(a[n-2]=='l')and(a[n-1]=='i')){
    
    a[n-1]='e';
  }
  if((n>=4)and(m_ans(word,n-4)>0)and(a[n-4]=='a')and(a[n-3]=='l')and(a[n-2]=='l')and(a[n-1]=='i')){
    a[n-2]='*';
    a[n-1]='*';
    n-=2;
  }
 // cout<<"hi"<<endl;
  //cout<<m_ans(word,n-5)<<endl;
  if((n>=5)and(m_ans(word,n-5)>0)and(a[n-5]=='e')and(a[n-4]=='n')and(a[n-3]=='t')and(a[n-2]=='l')and(a[n-1]=='i')){
    
    a[n-2]='*';
    a[n-1]='*';
    n-=2;
  }
 // cout<<"jdjdw"<<endl;
  if((n>=3)and(m_ans(word,n-3)>0)and(a[n-3]=='e')and(a[n-2]=='l')and(a[n-1]=='i')){
    a[n-2]='*';
    a[n-1]='*';
    n-=2;
  }
  if((n>=5)and(m_ans(word,n-5)>0)and(a[n-5]=='o')and(a[n-4]=='u')and(a[n-3]=='s')and(a[n-2]=='l')and(a[n-1]=='i')){
    a[n-2]='*';
    a[n-1]='*';
    n-=2;
  }
  if((n>=7)and(m_ans(word,n-7)>0)and(a[n-7]=='i')and(a[n-6]=='z')and(a[n-5]=='a')and(a[n-4]=='t')and(a[n-3]=='i')and(a[n-2]=='o')and(a[n-1]=='n')){
    a[n-5]='e';
    a[n-4]='*';
    a[n-3]='*';
    a[n-2]='*';
    a[n-1]='*';
    n=n-4;
  }
  if((n>=5)and(m_ans(word,n-5)>0)and(a[n-5]=='a')and(a[n-4]=='t')and(a[n-3]=='i')and(a[n-2]=='o')and(a[n-1]=='n')){
    a[n-3]='e';
    a[n-2]='*';
    a[n-1]='*';
    n-=2;
  }
  if((n>=4)and(m_ans(word,n-4)>0)and(a[n-4]=='a')and(a[n-3]=='t')and(a[n-2]=='o')and(a[n-1]=='r')){
    
    a[n-2]='e';
    a[n-1]='*';
    n-=1;
  }
  if((n>=5)and(m_ans(word,n-5)>0)and(a[n-5]=='a')and(a[n-4]=='l')and(a[n-3]=='i')and(a[n-2]=='s')and(a[n-1]=='m')){
    a[n-3]='*';
    a[n-2]='*';
    a[n-1]='*';
    n-=3;
  }
  if((n>=7)and(m_ans(word,n-7)>0)and(a[n-7]=='i')and(a[n-6]=='v')and(a[n-5]=='e')and(a[n-4]=='n')and(a[n-3]=='e')and(a[n-2]=='s')and(a[n-1]=='s')){
  
    a[n-4]='*';
    a[n-3]='*';
    a[n-2]='*';
    a[n-1]='*';
    n=n-4;
  }
  if((n>=7)and(m_ans(word,n-7)>0)and(a[n-7]=='f')and(a[n-6]=='u')and(a[n-5]=='l')and(a[n-4]=='n')and(a[n-3]=='e')and(a[n-2]=='s')and(a[n-1]=='s')){
   // a[n-5]='e';
    a[n-4]='*';
    a[n-3]='*';
    a[n-2]='*';
    a[n-1]='*';
    n=n-4;
  }
  if((n>=7)and(m_ans(word,n-7)>0)and(a[n-7]=='o')and(a[n-6]=='u')and(a[n-5]=='s')and(a[n-4]=='n')and(a[n-3]=='e')and(a[n-2]=='s')and(a[n-1]=='s')){
   // a[n-5]='e';
    a[n-4]='*';
    a[n-3]='*';
    a[n-2]='*';
    a[n-1]='*';
    n=n-4;
  }
  if((n>=5)and(m_ans(word,n-5)>0)and(a[n-5]=='a')and(a[n-4]=='l')and(a[n-3]=='i')and(a[n-2]=='t')and(a[n-1]=='i')){
    a[n-3]='*';
    a[n-2]='*';
    a[n-1]='*';
    n-=3;
  }
  if((n>=5)and(m_ans(word,n-5)>0)and(a[n-5]=='i')and(a[n-4]=='v')and(a[n-3]=='i')and(a[n-2]=='t')and(a[n-1]=='i')){
    a[n-3]='*';
    a[n-2]='*';
    a[n-1]='*';
    n-=3;
  }
  if((n>=6)and(m_ans(word,n-6)>0)and(a[n-6]=='b')and(a[n-5]=='i')and(a[n-4]=='l')and(a[n-3]=='i')and(a[n-2]=='t')and(a[n-1]=='i')){
    a[n-3]='e';
    a[n-2]='*';
    a[n-1]='*';
    n-=2;
  }
//////////////////step 3 
  
  if((n>=5)and(m_ans(word,n-5)>0)and(a[n-5]=='i')and(a[n-4]=='c')and(a[n-3]=='a')and(a[n-2]=='t')and(a[n-1]=='e')){
    a[n-3]='*';
    a[n-2]='*';
    a[n-1]='*';
    n-=3;
  }
  if((n>=5)and(m_ans(word,n-5)>0)and(a[n-5]=='a')and(a[n-4]=='t')and(a[n-3]=='i')and(a[n-2]=='v')and(a[n-1]=='e')){
    a[n-5]='*';
    a[n-4]='*';
    a[n-3]='*';
    a[n-2]='*';
    a[n-1]='*';
    n-=5;
  }
  if((n>=5)and(m_ans(word,n-5)>0)and(a[n-5]=='a')and(a[n-4]=='l')and(a[n-3]=='i')and(a[n-2]=='z')and(a[n-1]=='e')){
    a[n-3]='*';
    a[n-2]='*';
    a[n-1]='*';
    n-=3;
  }
  if((n>=5)and(m_ans(word,n-5)>0)and(a[n-5]=='i')and(a[n-4]=='c')and(a[n-3]=='i')and(a[n-2]=='t')and(a[n-1]=='i')){
    a[n-3]='*';
    a[n-2]='*';
    a[n-1]='*';
    n-=3;
  }
  if((n>=4)and(m_ans(word,n-4)>0)and(a[n-4]=='i')and(a[n-3]=='c')and(a[n-2]=='a')and(a[n-1]=='l')){
    
    a[n-2]='*';
    a[n-1]='*';
    n-=2;
  }
  if((n>=3)and(m_ans(word,n-3)>0)and(a[n-3]=='f')and(a[n-2]=='u')and(a[n-1]=='l')){
    a[n-3]='*';
    a[n-2]='*';
    a[n-1]='*';
    n-=3;
  }
  if((n>=4)and(m_ans(word,n-4)>0)and(a[n-4]=='n')and(a[n-3]=='e')and(a[n-2]=='s')and(a[n-1]=='s')){
    a[n-4]='*';
    a[n-3]='*';
    a[n-2]='*';
    a[n-1]='*';
    n-=4;
  }
  
 ///////////step 4 
 
 if((n>=2)and(m_ans(word,n-2)>1)and(a[n-2]=='a')and(a[n-1]=='l')){
   a[n-2]='*';
   a[n-1]='*';
   n-=2;
 }
 if((n>=4)and(m_ans(word,n-4)>1)and(a[n-4]=='a')and(a[n-3]=='n')and(a[n-2]=='c')and(a[n-1]=='e')){
   a[n-4]='*';
    a[n-3]='*';
    a[n-2]='*';
    a[n-1]='*';
    n-=4;
 }
 if((n>=4)and(m_ans(word,n-4)>1)and(a[n-4]=='e')and(a[n-3]=='n')and(a[n-2]=='c')and(a[n-1]=='e')){
   a[n-4]='*';
    a[n-3]='*';
    a[n-2]='*';
    a[n-1]='*';
    n-=4;
 }
 if((n>=2)and(m_ans(word,n-2)>1)and(a[n-2]=='e')and(a[n-1]=='r')){
   a[n-2]='*';
   a[n-1]='*';
   n-=2;
 }
 if((n>=2)and(m_ans(word,n-2)>1)and(a[n-2]=='i')and(a[n-1]=='c')){
   a[n-2]='*';
   a[n-1]='*';
   n-=2;
 }
 if((n>=4)and(m_ans(word,n-4)>1)and(a[n-4]=='a')and(a[n-3]=='b')and(a[n-2]=='l')and(a[n-1]=='e')){
   a[n-4]='*';
    a[n-3]='*';
    a[n-2]='*';
    a[n-1]='*';
    n-=4;
 }
 if((n>=4)and(m_ans(word,n-4)>1)and(a[n-4]=='i')and(a[n-3]=='b')and(a[n-2]=='l')and(a[n-1]=='e')){
   a[n-4]='*';
    a[n-3]='*';
    a[n-2]='*';
    a[n-1]='*';
    n-=4;
 }
 if((n>=3)and(m_ans(word,n-3)>1)and(a[n-3]=='a')and(a[n-2]=='n')and(a[n-1]=='t')){
    a[n-3]='*';
    a[n-2]='*';
    a[n-1]='*';
    n-=3;
  }
  if((n>=5)and(m_ans(word,n-5)>1)and(a[n-5]=='e')and(a[n-4]=='m')and(a[n-3]=='e')and(a[n-2]=='n')and(a[n-1]=='t')){
   a[n-5]='*';
   a[n-4]='*';
    a[n-3]='*';
    a[n-2]='*';
    a[n-1]='*';
    n-=5;
 }
 if((n>=4)and(m_ans(word,n-4)>1)and(a[n-4]=='m')and(a[n-3]=='e')and(a[n-2]=='n')and(a[n-1]=='t')){
   a[n-4]='*';
    a[n-3]='*';
    a[n-2]='*';
    a[n-1]='*';
    n-=4;
 }
 if((n>=3)and(m_ans(word,n-3)>1)and(a[n-3]=='e')and(a[n-2]=='n')and(a[n-1]=='t')){
    a[n-3]='*';
    a[n-2]='*';
    a[n-1]='*';
    n-=3;
  }
  if((n>=4)and(m_ans(word,n-3)>1)and((a[n-4]=='s')or(a[n-4]=='t'))and(a[n-3]=='i')and(a[n-2]=='o')and(a[n-1]=='n')){
  // a[n-4]='*';
    a[n-3]='*';
    a[n-2]='*';
    a[n-1]='*';
    n-=3;
 }
  if((n>=2)and(m_ans(word,n-2)>1)and(a[n-2]=='o')and(a[n-1]=='u')){
   a[n-2]='*';
   a[n-1]='*';
   n-=2;
 }
  if((n>=3)and(m_ans(word,n-3)>1)and(a[n-3]=='i')and(a[n-2]=='s')and(a[n-1]=='m')){
    a[n-3]='*';
    a[n-2]='*';
    a[n-1]='*';
    n-=3;
  }
  if((n>=3)and(m_ans(word,n-3)>1)and(a[n-3]=='a')and(a[n-2]=='t')and(a[n-1]=='e')){
    a[n-3]='*';
    a[n-2]='*';
    a[n-1]='*';
    n-=3;
  }
  if((n>=3)and(m_ans(word,n-3)>1)and(a[n-3]=='i')and(a[n-2]=='t')and(a[n-1]=='i')){
    a[n-3]='*';
    a[n-2]='*';
    a[n-1]='*';
    n-=3;
  }
  if((n>=3)and(m_ans(word,n-3)>1)and(a[n-3]=='o')and(a[n-2]=='u')and(a[n-1]=='s')){
    a[n-3]='*';
    a[n-2]='*';
    a[n-1]='*';
    n-=3;
  }
  if((n>=3)and(m_ans(word,n-3)>1)and(a[n-3]=='i')and(a[n-2]=='v')and(a[n-1]=='e')){
    a[n-3]='*';
    a[n-2]='*';
    a[n-1]='*';
    n-=3;
  }
  if((n>=3)and(m_ans(word,n-3)>1)and(a[n-3]=='i')and(a[n-2]=='z')and(a[n-1]=='e')){
    a[n-3]='*';
    a[n-2]='*';
    a[n-1]='*';
    n-=3;
  }
  if((n>=1)and(m_ans(word,n-1)>1)and(a[n-1]=='e')){
    a[n-1]='*';
    n-=1;
  }
  if((n>=3)and(m_ans(word,n)==1)and(v[n-1]=='C')and(v[n-2]=='V')and(v[n-3]=='C')and(a[n-1]='e')){
    a[n-1]='*';
    n-=1;
    
  }
  if((x==true)and(n>=2)and((a[n-1]!='l')or(a[n-1]!='a')or(a[n-1]!='e')or(a[n-1]!='i')or(a[n-1]!='o')or(a[n-1]!='u'))and(a[n-1]==a[n-2])){
    a[n-1]='*';
    n-=1;
  }
 
  string s="";
 //cout<<m<<endl;
 for (int i=0;i<a.size();i++){
   if(a[i]!='*'){
    s=s+a[i];}
   // cout<<a[i]<<" ";
  }
  //cout<<endl;
 
 return s;
}

class maxheap {
public:
    std::vector<std::pair<Dict*, double>> heap;
    std::vector<std::pair<Diction*, double>> heap2;

    void maxHeapify(long long index) {
        long long left = 2*index+ 1;
        long long right = 2*index+ 2;
        long long largest = index;

        if (left<heap.size() && heap[left].second>heap[largest].second) {
            largest = left;
        }

        if (right<heap.size() && heap[right].second>heap[largest].second) {
            largest = right;
        }

        if (largest != index) {
            std::swap(heap[index], heap[largest]);
            maxHeapify(largest);
        }
    }

    void maxHeapify2(long long index) {
        long long left = 2*index+ 1;
        long long right = 2*index+ 2;
        long long largest = index;

        if (left<heap2.size() && heap2[left].second>heap2[largest].second) {
            largest = left;
        }

        if (right<heap2.size() && heap2[right].second>heap2[largest].second) {
            largest = right;
        }

        if (largest != index) {
            std::swap(heap2[index], heap2[largest]);
            maxHeapify2(largest);
        }
    }

    void deleteMax() {
        if (heap.empty()) {
            return;
        }
        heap[0] = heap.back();
        heap.pop_back();

        maxHeapify(0);
    }

    void deleteMax2() {
        if (heap2.empty()) {
            return;
        }
        heap2[0] = heap2.back();
        heap2.pop_back();

        maxHeapify2(0);
    }


    void insertPara(Dict* paragraph, double score) {
        heap.push_back(std::make_pair(paragraph, score));
        long long idx = heap.size() - 1;
        while (idx > 0) {
            long long parent = (idx - 1) / 2;
            if (heap[idx].second > heap[parent].second) {
                std::swap(heap[idx], heap[parent]);
                idx = parent;
            }
            else {
                break;
            }
        }
    }

    void insertPara_2(Diction* paragraph, double score) {
        heap2.push_back(std::make_pair(paragraph, score));
        long long idx = heap2.size() - 1;
        while (idx > 0) {
            long long parent = (idx - 1) / 2;
            if (heap2[idx].second > heap2[parent].second) {
                std::swap(heap2[idx], heap2[parent]);
                idx = parent;
            }
            else {
                break;
            }
        }
    }

    Node* getTopk(long long k) {

        Node* topk = new Node(heap[0].first->bk, heap[0].first->pag, heap[0].first->par, -1, -1);
        Node* curr = topk;
        topk->left = nullptr;

        deleteMax();
        
        for (long long i = 0; i < k-1 && i < heap.size(); i++) {
            Node* temp = new Node(heap[0].first->bk, heap[0].first->pag, heap[0].first->par, -1, -1);
            temp->left = curr;
            curr->right = temp;
            curr = curr->right;
            deleteMax();
        }
        curr->right = nullptr;
        return topk;
    }

    Node* getTopk_2(long long k) {

        Node* topk = new Node(heap2[0].first->bk, heap2[0].first->pag, heap2[0].first->par, -1, -1);
        Node* curr = topk;
        topk->left = nullptr;

        deleteMax2();
        
        for (long long i = 0; i < k-1 && i < heap2.size(); i++) {
            Node* temp = new Node(heap2[0].first->bk, heap2[0].first->pag, heap2[0].first->par, -1, -1);
            temp->left = curr;
            curr->right = temp;
            curr = curr->right;
            deleteMax2();
        }
        curr->right = nullptr;
        return topk;
    }
};

Diction::Diction() {
    root = new TrieNode();
}

Diction::~Diction() {
    delete root;
}

void Diction::insertintrie(string word) {
    TrieNode* node=root;
    for(auto ch : word)
    {
        if (node->find(ch)==-1)
        {
            TrieNode* new_node=new TrieNode();
            new_node->key=ch;
            node->children.push_back(new_node);
        }
        node=node->children[node->find(ch)];
    }
    node->endOfWord=true;
    node->count++;
}

void Diction::insert_sentence(int book_code, int page, int paragraph, int sentence_no, string sentence) {
    string word;
    for (char c:sentence) {
        if (isseparator(c)) {
            if (!word.empty()) {
                Diction::insertintrie(port_stem(word));
                word.clear();
            }
        }
        else {
            word += tolower(c);
        }
    }

    if (!word.empty()) {
        Diction::insertintrie(port_stem(word));
    }
    return;
}

long long Diction::get_word_count(string word) {
    TrieNode* node=root;
    for(auto ch : word)
    {
        int flag = node->find(ch);
        if(flag==-1)
        {
            return 0;
        }
        node=node->children[flag];
    }
    return node->count;
}


QNA_tool::QNA_tool(){
    // Implement your function here  
    result = nullptr;
}

QNA_tool::~QNA_tool(){
    // Implement your function here  
    Node* head = result;
    while (head != nullptr) {
        Node* temp = head;
        head = head->right;
        delete temp;
    }

    for (int i = 0; i < size; i++) {
        delete made[i];
    }

    for (int i = 0; i < siz; i++) {
        delete made2[i];
    }
}

void QNA_tool::insert_sentence(int book_code, int page, int paragraph, int sentence_no, string sentence){
    // Implement your function here  
    dic.insert_sentence(book_code, page, paragraph, sentence_no, sentence);


    bool found = false;
    long long n=0;
    if(size-50 > 0){
        n = size-50;
    }
    for (long long i = size; i>n; i--) {
        if (made[i-1]->bk == book_code && made[i-1]->pag == page && made[i-1]->par == paragraph) {
            made[i-1]->insert_sentence(book_code, page, paragraph, sentence_no, sentence);
            found = true;
            break;
        }
    }

    if (found != true) {
        Dict* p = new Dict();
        made.push_back(p);
        size++;
        made[size-1]->bk = book_code;
        
        made[size-1]->pag = page;
        made[size-1]->par = paragraph;
        made[size-1]->insert_sentence(book_code, page, paragraph, sentence_no, sentence);
        found = true;
    }
    return;
}

void QNA_tool::insert_sentence_2(int book_code, int page, int paragraph, int sentence_no, string sentence){

    bool found = false;
    long long n=0;
    if(siz-50 > 0){
        n = siz-50;
    }
    for (long long i = siz; i>n; i--) {
        if (made2[i-1]->bk == book_code && made2[i-1]->pag == page && made2[i-1]->par == paragraph) {
            made2[i-1]->insert_sentence(book_code, page, paragraph, sentence_no, sentence);
            found = true;
            break;
        }
    }

    if (found != true) {
        Diction* p = new Diction();
        made2.push_back(p);
        siz++;
        made2[siz-1]->bk = book_code;
        
        made2[siz-1]->pag = page;
        made2[siz-1]->par = paragraph; 
        made2[siz-1]->insert_sentence(book_code, page, paragraph, sentence_no, sentence);
        found = true;
    }
    return;
}

double QNA_tool::scorer(string myword) {
    long long tcount = 0;
    fstream file;
    file.open("unigram_freq.csv",ios::in);
    if(file.is_open()){
        string line;
        while(getline(file,line)){
            string s;
            long long i;
            for(i=0;i<line.size();i++){
                if(line[i]==','){
                    break;
                }else{
                    s = s+line[i];
                }
            }string d;
            
            if(s == myword){
                if(i < line.size()){
                    tcount = stol(line.substr(i+1,line.size()-i));
                }
                
            }
        }
    }

    file.close();

    long long x = dic.get_word_count(myword);
    double n = (double)(x+1)/(tcount+1);

    return n;
}

double QNA_tool::scorer2(string myword) {
    long long tcount = 0;
    fstream file;
    file.open("unigram_freq.csv",ios::in);
    if(file.is_open()){
        string line;
        while(getline(file,line)){
            string s;
            long long i;
            for(i=0;i<line.size();i++){
                if(line[i]==','){
                    break;
                }else{
                    s = s+line[i];
                }
            }string d;
            
            if(s == myword){
                if(i < line.size()){
                    tcount = stol(line.substr(i+1,line.size()-i));
                }
                
            }
        }
    }

    file.close();

    long long x = dic.get_word_count(myword);
    double n = (double)10000/((x+1)*(tcount+1));

    return n;
}

double inverse_rsqrt0(double number) {
    const double th = 1.5F;
    double x2 = number * 0.5F;
    double y = number;
    long i = *reinterpret_cast<long*>(&y);
    i = 0x5fe6eb50c7b537a9 - (i >> 1);
    y = *reinterpret_cast<double*>(&i);
    y = y * (th - (x2 * y * y));

    return y;
}

double QNA_tool::scorer3(string myword) {

    long long x = dic.get_word_count(myword);
    double n = 1.0/static_cast<double>(x);

    return n;
}

double QNA_tool::get_para_score(string query, Dict* gg, vector<pair<string,double>> keyword) {
    double pscore = 0;

    long long n = keyword.size();
    for (long long i = 0; i<n; i++) {
        long long wc = gg->get_word_count(keyword[i].first);
        pscore += wc*keyword[i].second;
    }
    
    return pscore;
}

double QNA_tool::get_para_score_2(string query, Diction* gg, vector<pair<string,double>> keyword) {
    double pscore = 0;

    long long n = keyword.size();
    for (long long i = 0; i<n; i++) {
        long long wc = gg->get_word_count(keyword[i].first);
        pscore += wc*keyword[i].second;
    }
    
    return pscore;
}

double QNA_tool::get_para_score_3(string query, Diction* gg, vector<pair<string,double>> keyword, vector<pair<string,double>> queeryy) {
    double pscore = 0;

    double nume=0;
    double t12=0;
    double t22=0;

    long long n = keyword.size();
    for (long long i = 0; i<n; i++) {
        long long wc = gg->get_word_count(keyword[i].first);
        double a=wc*keyword[i].second;
        double b=queeryy[i].second;
        nume=nume+a*b;
        t12=t12+a*a;
        t22=t22+b*b;
    }

    pscore = nume*inverse_rsqrt0(t12)*inverse_rsqrt0(t22);
}

Node* QNA_tool::get_top_k_para(string question, int k) {
    // Implement your function here
    maxheap ansheap;
    vector<pair<string,double>> keywords;

    string word;
    for (char c:question) {
        if (isseparator(c)) {
            if (!word.empty()) {
                double sc = scorer(word);
                keywords.push_back(make_pair(word, sc));
                word.clear();
            }
        }
        else {
            word += tolower(c);
        }
    }

    if (!word.empty()) {
        double sc = scorer(word);
        keywords.push_back(make_pair(word, sc));
    }

    for (long long i = 0; i < size; i++) {
        ansheap.insertPara(made[i], get_para_score(question, made[i], keywords));
    }
    result = ansheap.getTopk(k);
    
    return result;
}



Node* QNA_tool::get_top_k_para_3(string question, int k) {
    maxheap ansheap;
    Dict keyword_count;
    vector<pair<string,double>> keywords;
    vector<pair<string,double>> queery;

    keyword_count.insert_sentence(-1, -1, -1, -1, question);

    string word;
    for (char c:question) {
        if (isseparator(c)) {
            if (!word.empty()) {
                double sc = scorer3(word);
                keywords.push_back(make_pair(word, sc));
                queery.push_back(make_pair(word, keyword_count.get_word_count(word)));
                word.clear();
            }
        }
        else {
            word += tolower(c);
        }
    }

    if (!word.empty()) {
        double sc = scorer3(word);
        keywords.push_back(make_pair(word, sc));
        queery.push_back(make_pair(word, keyword_count.get_word_count(word)));
    }


    for (long long i = 0; i < siz; i++) {
        ansheap.insertPara_2(made2[i], get_para_score_3(question, made2[i], keywords, queery));
    }
    result = ansheap.getTopk_2(k);
    
    return result;

}


Node* QNA_tool::get_top_k_para_2(string question, int k) {
    maxheap ansheap;
    vector<pair<string,double>> keywords;

    string word;
    for (char c:question) {
        if (isseparator(c)) {
            if (!word.empty()) {
                double sc = scorer2(word);
                keywords.push_back(make_pair(word, sc));
                word.clear();
            }
        }
        else {
            word += tolower(c);
        }
    }

    if (!word.empty()) {
        double sc = scorer2(word);
        keywords.push_back(make_pair(word, sc));
    }

    for (long long i = 0; i < siz; i++) {
        ansheap.insertPara_2(made2[i], get_para_score_2(question, made2[i], keywords));
    }
    result = ansheap.getTopk_2(k);
    
    return result;
}


void QNA_tool::query(string question, string filename){
    // Implement your function here  
    int n=100;
    Dict excluded;
    fstream file;
    file.open("unigram_freq.csv",ios::in);

    if(file.is_open()){
        string line;
        int counter=0;
        while(getline(file,line)){
            if(counter ==0){
                counter++;
            }else{
                string s;
                int i=0;
                while(line[i]!=','){
                    s = s+line[i];
                    i++;
                }
                counter++;
                if(counter < n){
                    excluded.insert_sentence(-1, -1, -1, -1, s);
                }else{
                    break;
                }
                
            }
        }
        file.close();
    }
    cout<<question<<endl;
    string question2;
    string word;
    for (char c:question) {
        if (isseparator(c)) {
            if (!word.empty()) {
                if(excluded.get_word_count(word) < 1) {
                    question2 += word + " ";
                }
                word.clear();
            }
        }
        else {
            word += tolower(c);
        }
    }

    if (!word.empty()) {
        if(excluded.get_word_count(word) < 1) {
            question2 += word + " ";
        }
    }

    cout<<question2<<endl;
    


    for(int i = 1; i <= num_boo; i++){

        std::cout << "Inserting book " << i << std::endl;

        std::string filena = "/Users/gandharvachhipa/Documents/Assign7f/MK Gandhi/mahatma-gandhi-collected-works-volume-";
        filena += to_string(i);
        filena += ".txt";

        std::ifstream inputFi(filena);

        if (!inputFi.is_open()) {
            std::cerr << "Error: Unable to open the input file mahatma-gandhi." << std::endl;
        }

        std::string tuples;
        std::string sentences;


        while (std::getline(inputFi, tuples, ')') && std::getline(inputFi, sentences)) {
            // Get a line in the sentence
            tuples += ')';

            std::vector<int> metadata;    
            std::istringstream iss(tuples);

            // Temporary variables for parsing
            std::string token;

            // Ignore the first character (the opening parenthesis)
            iss.ignore(1);

            // Parse and convert the elements to integers
            while (std::getline(iss, token, ',')) {
                // Trim leading and trailing white spaces
                size_t start = token.find_first_not_of(" ");
                size_t end = token.find_last_not_of(" ");
                if (start != std::string::npos && end != std::string::npos) {
                    token = token.substr(start, end - start + 1);
                }
                
                // Check if the element is a number or a string
                if (token[0] == '\'') {
                    // Remove the single quotes and convert to integer
                    int num = std::stoi(token.substr(1, token.length() - 2));
                    metadata.push_back(num);
                } else {
                    // Convert the element to integer
                    int num = std::stoi(token);
                    metadata.push_back(num);
                }
            }

            // Now we have the string in sentence
            // And the other info in metadata
            // Add to the dictionary

            // Insert in the qna_tool
            insert_sentence_2(metadata[0], metadata[1], metadata[2], metadata[3], sentences);
        }

        inputFi.close();

    }
    int k = 5;
    Node* selected = get_top_k_para_2(question, k);
    query_llm(filename, selected, k, "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", question);

    std::cout << "Q: " << question << std::endl;
    std::cout << "A: " << "Studying COL106 :)" << std::endl;
    return;
}

std::string QNA_tool::get_paragraph(int book_code, int page, int paragraph){

    cout << "Book_code: " << book_code << " Page: " << page << " Paragraph: " << paragraph << endl;
    
    std::string filename = "/Users/gandharvachhipa/Documents/Assign7f/MK Gandhi/mahatma-gandhi-collected-works-volume-";
    filename += to_string(book_code);
    filename += ".txt";

    std::ifstream inputFile(filename);

    std::string tuple;
    std::string sentence;

    if (!inputFile.is_open()) {
        std::cerr << "Error: Unable to open the input file " << filename << "." << std::endl;
        exit(1);
    }

    std::string res = "";

    while (std::getline(inputFile, tuple, ')') && std::getline(inputFile, sentence)) {
        // Get a line in the sentence
        tuple += ')';

        int metadata[5];
        std::istringstream iss(tuple);

        // Temporary variables for parsing
        std::string token;

        // Ignore the first character (the opening parenthesis)
        iss.ignore(1);

        // Parse and convert the elements to integers
        int idx = 0;
        while (std::getline(iss, token, ',')) {
            // Trim leading and trailing white spaces
            size_t start = token.find_first_not_of(" ");
            size_t end = token.find_last_not_of(" ");
            if (start != std::string::npos && end != std::string::npos) {
                token = token.substr(start, end - start + 1);
            }
            
            // Check if the element is a number or a string
            if (token[0] == '\'') {
                // Remove the single quotes and convert to integer
                int num = std::stoi(token.substr(1, token.length() - 2));
                metadata[idx] = num;
            } else {
                // Convert the element to integer
                int num = std::stoi(token);
                metadata[idx] = num;
            }
            idx++;
        }

        if(
            (metadata[0] == book_code) &&
            (metadata[1] == page) &&
            (metadata[2] == paragraph)
        ){
            res += sentence;
        }
    }

    inputFile.close();
    return res;
}

void QNA_tool::query_llm(string filename, Node* root, int k, string API_KEY, string question){

    // first write the k paragraphs into different files

    Node* traverse = root;
    int num_paragraph = 0;

    while(num_paragraph < k){
        assert(traverse != nullptr);
        string p_file = "paragraph_";
        p_file += to_string(num_paragraph);
        p_file += ".txt";
        // delete the file if it exists
        remove(p_file.c_str());
        ofstream outfile(p_file);
        string paragraph = get_paragraph(traverse->book_code, traverse->page, traverse->paragraph);
        assert(paragraph != "$I$N$V$A$L$I$D$");
        outfile << paragraph;
        outfile.close();
        traverse = traverse->right;
        num_paragraph++;
    }

    // write the query to query.txt
    ofstream outfile("query.txt");
    outfile << "These are the excerpts from Mahatma Gandhi's books.\nOn the basis of this, ";
    outfile << question;
    // You can add anything here - show all your creativity and skills of using ChatGPT
    outfile.close();
 
    // you do not need to necessarily provide k paragraphs - can configure yourself

    // python3 <filename> API_KEY num_paragraphs query.txt
    string command = "python3 ";
    command += filename;
    command += " ";
    command += API_KEY;
    command += " ";
    command += to_string(k);
    command += " ";
    command += "query.txt";

    system(command.c_str());
    return;
}
