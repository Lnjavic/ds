#include<iostream>
#include<cmath>

using namespace std;

struct singlePoint{
   int x;
   int y;
};

class myPoints{
    public:
      struct singlePoint start_point;
      struct singlePoint end_point;

      myPoints(int x1,int y1,int x2,int y2){
        start_point.x = x1;
        start_point.y = y1;

        end_point.x = x2;
        end_point.y = y2;
      }

      void calculateDistance(){
        int sum_of_differences_squared, x_diff , y_diff;
        float distance;

        x_diff = end_point.x - start_point.x;
        y_diff = end_point.y - start_point.y;

        sum_of_differences_squared = (y_diff*y_diff) + (x_diff*x_diff);

        distance = sqrt(sum_of_differences_squared);

    cout<<"Distance between points ("<<start_point.x<<","<<start_point.y<<") and ("<<end_point.x<<","<<end_point.y<<") is "<<distance<<" Units"<<endl;
      }

      void calculateMidPoint(){
        int sumOfX,sumOfY;
        float halfY,halfX;

        sumOfX = start_point.x + end_point.x;
        sumOfY = start_point.y + end_point.y;

        halfX = sumOfX/2;  halfY = sumOfY/2;

        cout << "The midpoint is ("<<halfX<<","<<halfY<<")"<<endl;
      }
};

int main(){
    int x1,x2,y1,y2;

    cout << "Enter x1"<<endl;
    cin >> x1;
    cout << "Enter y1"<<endl;
    cin >> y1;
    cout << "Enter x2"<<endl;
    cin >> x2;
    cout << "Enter y2"<<endl;
    cin >> y2;

    myPoints newPoints(x1,y1,x2,y2);

    newPoints.calculateMidPoint();

    return 0;
}
