#include<iostream>
#include<cmath>

using namespace std;

struct singlePoint{
    int x;
    int y;
};

class points{
    public:
        struct singlePoint point1;
        struct singlePoint point2;
        struct singlePoint point3;
    
    points(int x1,int x2,int x3, int y1,int y2,int y3){
        point1.x = x1;
        point2.x = x2;
        point3.x = x3;

        point1.y = y1;
        point2.y = y2;
        point3.y = y3;
    }

    float calculateDistance(int x1, int y1,int x2,int y2){
                int sum_of_differences_squared, x_diff , y_diff;
        float distance;

        x_diff = x2 - x1;
        y_diff = y2 - y1;

        sum_of_differences_squared = (y_diff*y_diff) + (x_diff*x_diff);

        distance = sqrt(sum_of_differences_squared);

        return distance;
    }

    void calculateArea(){
        float firstSide,secondSide,thirdSide,area;
        firstSide = calculateDistance(point1.x,point1.y,point2.x,point2.y);
        secondSide = calculateDistance(point1.x,point1.y,point3.x,point3.y);
        thirdSide = calculateDistance(point2.x,point2.y,point3.x,point3.y);

        area = heron(firstSide,secondSide,thirdSide);
          cout << "The area is "<<area<<" units"<<endl;
    }

    float heron(float a,float b, float c){
        float sum,halfSum,area;
        sum = a + b + c;
        halfSum = sum/2;

        area = sqrt((halfSum)*(halfSum-a)*(halfSum-b)*(halfSum-c));

       return area;

    }
};

int main(){
    int x1,x2,x3,y1,y2,y3;
    cout << "Enter x1"<<endl;
    cin >> x1;
    cout << "Enter y1"<<endl;
    cin >> y1;
    cout << "Enter x2"<<endl;
    cin >> x2;
    cout << "Enter y2"<<endl;
    cin >> y2;
    cout << "Enter x3"<<endl;
    cin >> x3;
    cout << "Enter y3"<<endl;
    cin >> y3;

    points newPoints(x1,x2,x3,y1,y2,y3);
    newPoints.calculateArea();
}