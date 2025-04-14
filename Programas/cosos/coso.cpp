#import <iostream>
using namespace std;
int main(){
	int a[3][3]={{1,2,3},
				 {4,5,6},
				 {7,8,9}};
	int i;
	for(i=0; i<3; i++){
		cout<<a[i][i]<<", "<<a[i][i-1]<<", "<<a[i][i-2]<<", ";
	}
	for(i=0; i<3; i++){
		cout<<a[i][i]<<", "<<a[i][i-1]<<", "<<a[i][i-2]<<", ";
	}
}
