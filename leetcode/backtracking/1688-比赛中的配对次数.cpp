#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
using namespace std;

int numberOfMatches(int n) {
    if(n==0 || n==1){
        return 0;
    } 
    if(n%2==0){
        return n/2 + numberOfMatches(n/2);
    }else{
        return (n-1)/2 + numberOfMatches((n-1)/2+1);
    }
}
int main(){
    cout<<numberOfMatches(14)<<endl;
    return 0;
}