#include<iostream>
#include<fstream>
#include<dirent.h>
#include<bits/stdc++.h>
#include<sys/stat.h>
#include<string.h>
using namespace std;

struct param{
                            int number_of_vehicles;
                            string vehicles[10];
                            string fname;
                     };

class drivers{
public:
	int driver_allowance;
	string driver_name;
	string vehicle_assigned = "";
	int number_of_divers = 19;
	int driver_no;

	
};


class vehicle{
public:
	string driver;
	int expected_daily_income;
	string type;
	int number_of_vehicles;
	int revenue;
   };

class bus: public vehicle{
public:
	int fare;
	int sitting_capacity;
	int number_of_trips;
	string vehicles[8] = {"KBC102Z","KDE456Y","KCT989P","KAC102G","KTT788U","KPG888V","KJK667L","KLO900Y"};
	bus(){
		number_of_vehicles = 8;
		fare = 150;
		sitting_capacity = 50;
		type = "bus";
	}

       void readRevenue(){
              struct dirent * d;
                     DIR * dir;
                     dir = opendir("revenues");

                     if(dir == NULL){
                            return;
                     }
                            int total = 0;

                     while((d = readdir(dir)) != NULL){
                            //cout<<d->d_name<<endl;
                            char filename[15];
                            sprintf(filename,"revenues/%s",d->d_name);
                            FILE * ptr;
                            ptr = fopen(filename,"r");

                            if(ptr == NULL){
                                   cout<<"null"<<endl;
                                   return;
                            }
                            char c;
                            int sum = 0;
                            char rev[10];
                            while(fgets(rev,10,ptr)){
                                   //cout<<rev;
                                   sscanf(rev,"%d",&sum);
                            //cout<<start<<endl;
                            total = total+sum;


                            }

                            
                     }

                     cout <<total<<endl;
       }

       void enterRevenue(){
              int no;
              string date;
              cout <<"Enter VEHICLE NUMBER"<<endl;
              cout<<"........................................................."<<endl;
              for(int counter = 0; counter<number_of_vehicles;counter++){
                     cout<<counter+1<<"]. "<<vehicles[counter]<<endl;
              }
              cin >> no;
              if(no > number_of_vehicles){
                     cout<<"Invalid choice"<<endl;
                     return;
              }
              cout<<"Enter number of trips made\n";
              cin >> number_of_trips;
              revenue = number_of_trips * fare * sitting_capacity;
              cout << "Enter date [dd/mm/yyyy]"<<endl;
              cin >> date;

                     struct dirent * d;
                     DIR * dir;
                     dir = opendir("rvs");

                     if(dir == NULL){
                            int check = mkdir("rvs",0777);
                     }

                     dir = opendir("rvs");
                     closedir(dir);

                     dir = opendir("revenues");

                     if(dir == NULL){
                            int check = mkdir("revenues",0777);
                     }

                     dir = opendir("revenues");
                     int recordno = -2;
                     while((d = readdir(dir)) != NULL){
                            recordno++;
                     }

                     cout<<recordno<<endl;
                     closedir(dir);

                     ofstream writeRvs("rvs/"+vehicles[no]+".txt",writeRvs.app);

                     writeRvs<<revenue<<endl;

                     writeRvs.close();

                     ofstream writeRevenue("revenues/"+vehicles[no-1]+".txt",writeRevenue.app);
                     writeRevenue<<recordno<<"          "<<date<<"           "<<vehicles[no]<<"          "<<revenue<<endl;
                     writeRevenue.close();
       }
};

class truck_pickup: public vehicle{
public:
	int fuel_consumption;
	int cost;
	int distance_covered;
       int driver_allowance;
       int fuel_price = 160;
       int price_of_fuel_consumed;

};

class pickup: public truck_pickup{
public:
       string vehicles[4] = {"KBB123B","KCC123E","KAA123A","KDD123D"};
	pickup(){
		number_of_vehicles = 4;
		fuel_consumption = 11;//kms per one litre of fuel
		type = "pickup";
              driver_allowance = 1000;

	}

       void readRevenue(){
              struct dirent * d;
                     DIR * dir;
                     dir = opendir("revenues");

                     if(dir == NULL){
                            return;
                     }
                            int total = 0;

                     while((d = readdir(dir)) != NULL){
                            //cout<<d->d_name<<endl;
                            char filename[15];
                            sprintf(filename,"revenues/%s",d->d_name);
                            FILE * ptr;
                            ptr = fopen(filename,"r");

                            if(ptr == NULL){
                                   cout<<"null"<<endl;
                                   return;
                            }
                            char c;
                            int sum = 0;
                            char rev[10];
                            while(fgets(rev,10,ptr)){
                                   //cout<<rev;
                                   sscanf(rev,"%d",&sum);
                            //cout<<start<<endl;
                            total = total+sum;


                            }

                            
                     }

                     cout <<total<<endl;
       }

       void enterRevenue(){
              int no;
              string date;
              cout <<"Enter VEHICLE NUMBER"<<endl;
              cout<<"........................................................."<<endl;
              for(int counter = 0; counter<number_of_vehicles;counter++){
                     cout<<counter+1<<"]. "<<vehicles[counter]<<endl;
              }
              cin >> no;
              
              if(no > number_of_vehicles){
                     cout<<"Invalid choice"<<endl;
                     return;
              }

              cout<<"Enter distance covered in KM\n";
              cin >> distance_covered;
              price_of_fuel_consumed = (distance_covered/fuel_consumption)*fuel_price;

              cout << "Enter date [dd/mm/yyyy]"<<endl;
              cin >> date;
              cout << "Enter revenue"<<endl;
              cin >> revenue;

                     struct dirent * d;
                     DIR * dir;
                     dir = opendir("rvs");

                     if(dir == NULL){
                            int check = mkdir("rvs",0777);
                     }

                     dir = opendir("rvs");
                     closedir(dir);

                     dir = opendir("revenues");

                     if(dir == NULL){
                            int check = mkdir("revenues",0777);
                     }

                     dir = opendir("revenues");
                     int recordno = -2;
                     while((d = readdir(dir)) != NULL){
                            recordno++;
                     }

                     cout<<recordno<<endl;
                     closedir(dir);

                     ofstream writeRvs("rvs/"+vehicles[no]+".txt",writeRvs.app);

                     writeRvs<<revenue<<endl;

                     writeRvs.close();

                     ofstream writeRevenue("revenues/"+vehicles[no-1]+".txt",writeRevenue.app);
                     writeRevenue<<recordno<<"          "<<date<<"           "<<vehicles[no]<<"          "<<revenue-(price_of_fuel_consumed+driver_allowance)<<endl;
                     writeRevenue.close();
       }

};

class truck: public truck_pickup{
public:

       string vehicles[7] = {"KEE123E","KFF123F","KGG123G","KHH123H","KJJ123J","KKK123K","KLL123L"};
	truck(){
		number_of_vehicles = 7;
		fuel_consumption = 8;//kms per 1 litre of fuel
		type = "truck";
              driver_allowance = 4000;
	}

       void readRevenue(){
              struct dirent * d;
                     DIR * dir;
                     dir = opendir("revenues");

                     if(dir == NULL){
                            return;
                     }
                            int total = 0;

                     while((d = readdir(dir)) != NULL){
                            //cout<<d->d_name<<endl;
                            char filename[15];
                            sprintf(filename,"revenues/%s",d->d_name);
                            FILE * ptr;
                            ptr = fopen(filename,"r");

                            if(ptr == NULL){
                                   cout<<"null"<<endl;
                                   return;
                            }
                            char c;
                            int sum = 0;
                            char rev[10];
                            while(fgets(rev,10,ptr)){
                                   //cout<<rev;
                                   sscanf(rev,"%d",&sum);
                            //cout<<start<<endl;
                            total = total+sum;


                            }

                            
                     }

                     cout <<total<<endl;
       }

       void enterRevenue(){
              int no;
              string date;
              cout <<"Enter VEHICLE NUMBER"<<endl;
              cout<<"........................................................."<<endl;
              for(int counter = 0; counter<number_of_vehicles;counter++){
                     cout<<counter+1<<"]. "<<vehicles[counter]<<endl;
              }
              cin >> no;
              
              if(no > number_of_vehicles){
                     cout<<"Invalid choice"<<endl;
                     return;
              }
              cout<<"Enter distance covered in KM\n";
              cin >> distance_covered;
              price_of_fuel_consumed = (distance_covered/fuel_consumption)*fuel_price;
              cout << "Enter date [dd/mm/yyyy]"<<endl;
              cin >> date;
              cout << "Enter revenue"<<endl;
              cin >> revenue;

                     struct dirent * d;
                     DIR * dir;
                     dir = opendir("rvs");

                     if(dir == NULL){
                            int check = mkdir("rvs",0777);
                     }

                     dir = opendir("rvs");
                     closedir(dir);

                     dir = opendir("revenues");

                     if(dir == NULL){
                            int check = mkdir("revenues",0777);
                     }

                     dir = opendir("revenues");
                     int recordno = -2;
                     while((d = readdir(dir)) != NULL){
                            recordno++;
                     }

                     cout<<recordno<<endl;
                     closedir(dir);

                     ofstream writeRvs("rvs/"+vehicles[no]+".txt",writeRvs.app);

                     writeRvs<<revenue<<endl;

                     writeRvs.close();

                     ofstream writeRevenue("revenues/"+vehicles[no-1]+".txt",writeRevenue.app);
                     writeRevenue<<recordno<<"          "<<date<<"           "<<vehicles[no]<<"          "<<(revenue- price_of_fuel_consumed + driver_allowance) <<endl;
                     writeRevenue.close();
       }


};

class driver: public drivers{
public:
	driver(string name,int type){
		int id = 1;
			ifstream driversfile("drivers.txt");
			string text;
			if(!getline(driversfile,text)){
				driversfile.close();
				ofstream driversfile("drivers.txt");
				driversfile.close();
			}
			ifstream temp("drivers.txt");
			while(getline(temp,text)){
				id++;
			}
			temp.close();

       driver_name = name;
       driver_no = id;

       int x = type;

      /* if(type == "bus"){
       	x = 1;
       }else if(type == "truck"){
       	x=2;
       }else if(type == "pickup"){
       	x=3;
       }*/

       allocate_vehicle(x);




       ofstream write_driver("drivers.txt",write_driver.app);

       write_driver<<driver_no<<"         "<<driver_name<<"    "<<vehicle_assigned<<endl;

       cout<<endl<<driver_name<<" has been allocated vehicle "<<vehicle_assigned<<endl; 


	}


	void allocate_vehicle(int type){
		if(type == 1){
                     bus bu;
       		
                     struct param * argbus = new param;
                     argbus->number_of_vehicles = 8;
                     argbus->fname = "allocatedbuses.txt";
                     for(int i = 0;i<8;i++){
                      argbus->vehicles[i] = bu.vehicles[i];
                     }
       		assignv(argbus);
              }
              else if(type == 2){
       	      
                     truck tr;

                     struct param * argtr = new param;
                     argtr->number_of_vehicles = tr.number_of_vehicles;
                     argtr->fname = "allocatedTrucks.txt";
                     for(int i = 0;i<7;i++){
                     argtr->vehicles[i] = tr.vehicles[i];
                     }
                     assignv(argtr);
              }else if(type == 3){
                     pickup pic;
                     

                     struct param * argpic = new param;
                     argpic->number_of_vehicles = pic.number_of_vehicles;
                     argpic->fname = "allocatedPickups.txt";
                     for(int i = 0;i<4;i++){
                     argpic->vehicles[i] = pic.vehicles[i];
                     }
                     assignv(argpic);
       	}
	}

	void assignv(param * b){
		int vehicleNumber = 0;
		string readString;
       		ifstream allocatedvehicles(b->fname);
       		if(!getline(allocatedvehicles,readString)){
       			allocatedvehicles.close();
       			ofstream allocated_vehicles(b->fname);
       			allocated_vehicles.close();

       		}

       		ifstream readvehicles(b->fname);
       		int temp_vehicles[b->number_of_vehicles];
       		for(int count = 0;count<b->number_of_vehicles;count++){
       			temp_vehicles[count] = 1;
       		}

       		while(getline(readvehicles,readString)){
       			int check = 0;
       			for(int i=0;i<b->number_of_vehicles-1;i++){
       				string t = readString.erase(7);
       				//cout<<t<<" ";
       				if(t == b->vehicles[i]){
       					check = 1;
       				}
       			}

       			if(check == 1){
       				temp_vehicles[vehicleNumber] = 0;
       			}else{
       				temp_vehicles[vehicleNumber] = 1;
       			}

       			vehicleNumber++;
       		}

       		readvehicles.close();


       		ofstream writevehicles(b->fname,writevehicles.app);

       		for(int j=0;j<=b->number_of_vehicles;j++){
       			if(j >= b->number_of_vehicles-1){
       				vehicle_assigned = "";
       				break;
       				return;
       			}

       			if(temp_vehicles[j] == 1){
       					vehicle_assigned = b->vehicles[j];
       			//cout<<j<<b->vehicles[j]<<endl;
       			break;
       			}
       		}

       		if(vehicle_assigned != ""){
       			writevehicles<<vehicle_assigned<<endl;
       		}else{
       			cout<<"NO VEHICLE LEFT TO ALLOCATE"<<endl;
       		}
	}
};

int readFiles(){
       struct dirent * d;
                     DIR * dir;
                     DIR * amounts;
                     int total;
                     cout<<"RECORD NO.   DATE     VEHICLE        REVENUE[ksh]\n";
                     cout<<".......................................................\n";
             dir = opendir("revenues");
             amounts = opendir("rvs");
                     while((d = readdir(dir)) != NULL){
                            char filename[15];
                            sprintf(filename,"revenues/%s",d->d_name);
                            FILE * ptr;
                            ptr = fopen(filename,"r");

                            if(ptr == NULL){
                                   cout<<"null"<<endl;
                                   return 0;
                            }
                            char rev[10];
                            while(fgets(rev,10,ptr)){
                                   cout<<rev;
                            }
                     }

                     closedir(dir);

                     while((d = readdir(amounts)) != NULL){
                            char filename[15];
                            sprintf(filename,"rvs/%s",d->d_name);
                            FILE * ptr;
                            ptr = fopen(filename,"r");

                            if(ptr == NULL){
                                   cout<<"null"<<endl;
                                   return 0;
                            }
                            int sum;
                            char rev[10];
                            while(fgets(rev,10,ptr)){
                                     sscanf(rev,"%d",&sum);
                            total = total+sum;
                            }
                            fclose(ptr);
                     }

                     return total;
}

int main(){
       int choice;
       cout <<"\nSELECT AN OPTION\n";
       cout<<"................................................................."<<endl;
       cout<<"1]. REGISTER A NEW DRIVER\n2]. SHOW ALL DRIVERS\n3]. ENTER REVENUE GENERATED BY A VEHICLE\n4]. SHOW GENERATED REVENUES\n5]. EXIT\n";
       cin >> choice;
       string line,fname,lname;
       ifstream showalldrivers("drivers.txt");
       if(choice == 1){
                     int vno;
                     cout<<"Enter First Name\n";
                     cin >> fname;
                     cout<<"Enter lastname\n";
                     cin >> lname;
                     cout << "Select vehicle Type [int]\n 1 for Bus\n 2 for truck\n 3 for pickup\n";
                     cin >> vno;
                     driver newdriver(fname+" "+lname,vno);
                     main();
       }

              if(choice == 2){
                     cout<<"NO           NAME          VEHICLE"<<endl;
                     cout<<"...................................."<<endl;
                     while(getline(showalldrivers,line)){
                            cout<<line<<endl;
                     }
                     showalldrivers.close();
                     main();
       }

       if(choice == 3){
              int dec;
              cout << "Select vehicle[int]\n 1] for Bus\n 2] for truck\n 3] for pickup\n";
              cout<<".....................................................................\n";
              cin >> dec;
              if(dec == 1){
                     bus b;
                     b.enterRevenue();
              }else if(dec == 2){
                     truck t;
                     t.enterRevenue();
              }else if(dec == 3){
                     pickup p;
                      p.enterRevenue();
              }
              main();
       }

       if(choice == 4){
             int outTotal = readFiles();

                     cout<<"\nTotal REVENUE = "<<outTotal<<endl;  
                     main();
       }

	return 0;
}