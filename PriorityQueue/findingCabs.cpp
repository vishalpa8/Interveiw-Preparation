#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;
typedef unsigned long long ll;
#define val(a) a.begin(),a.end()
#define sze(a) a.size()
#define fast_io ios_base::sync_with_stdio(0); cin.tie(0)

class Car{
    public:
        string id;
        int x,y;
        Car(string id, int x, int y){
            this->id = id;
            this->x = x;
            this->y = y;
        }

        int dist() const{
            return x*x + y*y;
        }
};

class CarCompare{
    public:
        bool operator()(const Car A, const Car B){
            return A.dist() < B.dist();
        }
};

void printNearestCars(vector<Car> cars, int k){
    priority_queue<Car,vector<Car>,CarCompare>max_heap(cars.begin(),cars.begin()+k);

    for(int i = k; i <(int)cars.size(); i++){
        auto car = cars[i];

        if(car.dist() < max_heap.top().dist()){
            max_heap.pop();
            max_heap.push(car);
        }

        vector<Car> output;
        while(!max_heap.empty()){
            output.push_back(max_heap.top());
            max_heap.pop();
        }

        reverse(output.begin(),output.end());

        for(auto car : output){
            cout << car.id << " ";
        }
    }
}



int main(){
    fast_io;
    int n,k;
    cin >> n >> k;

    string id;
    int x,y;

    vector<Car>cars;

    for(int i=0; i<n; i++){
        cin >> id >> x >> y;
        Car car(id,x,y);
        cars.push_back(car);
    }

    printNearestCars(cars,k);


    return 0;
}