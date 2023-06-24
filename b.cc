#include<iostream>
using namespace std;
const int X_MAX = 40;
const int Y_MAX = 60;

char graphics[X_MAX/2][Y_MAX];

inline void set_bit(int x,int y){
     graphics[(x)/8][y] |= (0x80>>((x)%8));
}

int main(){
	int loc;
	void print_graphics(void);
    for(loc=0;loc<X_MAX;++loc)
    	set_bit(loc,loc);
    print_graphics();
	return 0;
}

void print_graphics(void){
	int x,y,bit;

	for(y=0;y<Y_MAX;++y){

		for(x=0;x<X_MAX/8;++x){
            
            for(bit=0x80;bit>0;bit=(bit>>1)){
            	if((graphics[x][y] & bit) != 0)
            		cout << "X";
            	else
            		cout << ".";
            }
		}
		cout<<"\n";
	}
}
