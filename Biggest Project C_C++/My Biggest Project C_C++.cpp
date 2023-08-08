#include<iostream>
#include<iomanip>
#include<Windows.h>
#include<conio.h>
#include<fstream>
#include<stdio.h>
using namespace std;

class person{
    protected:
        int id,failID;
        string name;
        string sex;
    public:
        void setId(int a){
            id=a;
        }
        void setName(string b){
            name=b;
        }
        void setSex(string c){
            sex=c;
        }
        int getId(){
            return id;
        }
        string getName(){
            return name;
        }
        string getSex(){
            return sex;
        }
        person(){
            this->id=0;
            this->name="Unknow";
            this->sex="Male";
        }
        void input(){
        	failID=1;
        do{	
		   system("cls");
		   if(failID==0){
		   cout<<"          wrong ID...."<<endl;
			}
		   cout<<"----------------------------"<<endl;
           cout<<"ID   = ";
           fflush(stdin);
           failID=scanf("%d",&id);
       }while(failID==0);
           cout<<"Name = ";
           fflush(stdin);
           getline(cin,name);
           cout<<"Sex  = ";
           cin>>sex; 
        }
        void output(){
            cout<<"||"<<setw(15)<<left<<id;
            cout<<"|"<<setw(15)<<left<<name;
            cout<<"|"<<setw(15)<<left<<sex;
        }

};
class student:public person{
    private:
        float math,physical,khmer;
        float failMath,failPhysical,failKhmer;
    public:
        void setMath(float d){
            math=d;
        }
        void setPhysical(float e){
            physical=e;
        }
        void setKhmer(float f){
            khmer=f;
        }
        float getMath(){
            return math;
        }
        float getPhysical(){
            return physical;
        }
        float getKhmer(){
            return khmer;
        }
        student(){
            this->math=0;
            this->physical=0;
            this->khmer=0;
        }
        void input(){
            person::input();
            failMath=1;
            do{
            if(failMath==0){
            cout<<"    wrong score math...."<<endl;
            cout<<"----------------------------"<<endl;
			}
            cout<<"Score Math     = ";
            fflush(stdin);
            failMath=scanf("%f",&math);
        }while(failMath==0);
        	failPhysical=1;
        	do{
        	if(failPhysical==0){
            cout<<"  wrong score physical...."<<endl;
            cout<<"----------------------------"<<endl;
			}
            cout<<"Score Physical = ";
            fflush(stdin);
            failPhysical=scanf("%f",&physical);
  		}while(failPhysical==0);
  			failKhmer=1;
  			do{
  			if(failKhmer==0){
            cout<<"    wrong score khmer...."<<endl;
            cout<<"----------------------------"<<endl;
			}
            cout<<"Score Khmer    = ";
            fflush(stdin);
            failKhmer=scanf("%f",&khmer);
   		}while(failKhmer==0);
        }
        void output(){
            person::output();
            cout<<"|"<<setw(15)<<left<<math;
            cout<<"|"<<setw(15)<<left<<physical;
            cout<<"|"<<setw(15)<<left<<khmer;
            cout<<"|"<<setw(15)<<left<<totalScore();
            cout<<"|"<<setw(15)<<left<<average();
            cout<<"|"<<setw(15)<<left<<getGrade();
            cout<<"|"<<setw(15)<<left<<getResult()<<"||"<<endl;
        }
        float totalScore(){
            return math+physical+khmer;
        }
        float average(){
           return totalScore()/3;

        }
        char getGrade(){
            char grade;
            if(totalScore()>=280){
                grade='A';
            }
            else if(totalScore()>=220){
                grade='B';
            }
            else if(totalScore()>=170){
                grade='C';
            }
            else if(totalScore()>=130){
                grade='D';
            }
            else if(totalScore()>=100){
                grade='E';
            }
            else if(totalScore()<100){
                grade='F';
            }
            return grade;
        }
        string getResult(){
            string result;
            if(average()>=33.33){
                result="Pass";
            }
            else if(average()<33.33){
                result="Fail";
            }
            return result;
        }
};


int main(){
system("cls");
int option,loop_forever,n,i,x,j,temp,sort_loop_forever,sort_option,z=1,failstring,failStudent=1;
int idchange,k=0,optionOutput=0;
student obj[200],sorttmp;
fstream file;
    do{
        again:
        again_and_again:
       	again_and_agains:
    cout<<"==============================================================================Student Menu========================================================================="<<endl;
   if(z==1){
	cout<<"1.Input Student"<<endl;
    cout<<"2.Output Student"<<endl;
    cout<<"3.Search student"<<endl;
    cout<<"4.Delete student"<<endl;
    cout<<"5.Update student"<<endl;
    cout<<"6.Sort Student"<<endl;
    cout<<"7.Exit"<<endl;
	}
	else{
	cout<<"1.Insert Student"<<endl;
    cout<<"2.Output Student"<<endl;
    cout<<"3.Search student"<<endl;
    cout<<"4.Delete student"<<endl;
    cout<<"5.Update student"<<endl;
    cout<<"6.Sort Student"<<endl;
    cout<<"7.Exit"<<endl;	
	}
	do{
    cout<<"______________________"<<endl;
    cout<<"Enter Option =  ";
    fflush(stdin);
    failstring=scanf("%d",&option);
    if(failstring==0){
    	system("cls");
    	cout<<"\n\n\n"<<endl;
   		cout<<"Error.....! (Please Enter Options 1->7)"<<endl;
    	goto again_and_again;
	}
}while(failstring==0);
switch(option){
    case 1:
if(z==1){
	optionOutput=1;
    cout<<"===========================================================================Input Student Info======================================================================="<<endl;    
    do{
   	if(failStudent==0){
   	system("cls");
    cout<<"  wrong input student...."<<endl;
    cout<<"----------------------------"<<endl;
	}
	cout<<"Enter Student = ";
	fflush(stdin);
	failStudent=scanf("%d",&n);
	}while(failStudent==0);
    for(i=0;i<n;i++){
   	z=2;
    cout<<"______________________________"<<endl; 
   // file.open("Project1.bin",ios::out|ios::app|ios::binary);
   // file.write((char*)&obj[i],sizeof(obj[i]));
    obj[i].input();
    }
}
else{
	optionOutput=1;
	cout<<"===========================================================================Insert Student Info======================================================================"<<endl;   
    n+=k; 
    do{
   	if(failStudent==0){
   	system("cls");
    cout<<"  wrong input student...."<<endl;
    cout<<"----------------------------"<<endl;
	}
	cout<<"Enter Student = ";
	fflush(stdin);
	failStudent=scanf("%d",&k);
	}while(failStudent==0);
    for(i=n;i<n+k;i++){
    cout<<"______________________________"<<endl;
    obj[i].input();
    }
}
  //  file.close();
    break;
    case 2:
    if(optionOutput==0){
    	system("cls");
    	cout<<"Please Input before Output...."<<endl;
	}
    if(optionOutput==1){
    cout<<"=========================================================================List all student info====================================================================="<<endl;
    cout<<"||      ID       |     Name      |      Sex      |     Math      |   Physical    |     Khmer     |  Total Score  |    Average    |     Grade     |    Result     ||"<<endl;
    cout<<"==================================================================================================================================================================="<<endl;
  //  file.open("Project1.bin",ios::in|ios::binary);
   // file.read((char*)&obj[i],sizeof(obj[i]));
  //  while(!file.eof()){
    for(i=0;i<n+k;i++){
    obj[i].output();
  //  file.read((char*)&obj[i],sizeof(obj[i]));
   
    } 
 //   }
 //   file.close();
}
    break;
    case 3:
    cout<<"============================================================================Search Student========================================================================="<<endl;
    cout<<"Enter ID = ";
    cin>>idchange;
    cout<<"==================================================================================================================================================================="<<endl;
    cout<<"||      ID       |     Name      |      Sex      |     Math      |   Physical    |     Khmer     |  Total Score  |    Average    |     Grade     |    Result     ||"<<endl;
    cout<<"==================================================================================================================================================================="<<endl;
    x=0;
    for(i=0;i<n+k;i++){
        if(idchange==obj[i].getId()){
            obj[i].output(); 
            x=1;              
        }
    }
        if(x==0){
    cout<<"                                                                           Search Not Found....!"<<endl;
    }
    break;
    case 4:
    cout<<"============================================================================Delete Student========================================================================="<<endl;    
    cout<<"Enter ID = ";
    cin>>idchange;
    cout<<"==================================================================================================================================================================="<<endl;
    cout<<"||      ID       |     Name      |      Sex      |     Math      |   Physical    |     Khmer     |  Total Score  |    Average    |     Grade     |    Result     ||"<<endl;
    cout<<"==================================================================================================================================================================="<<endl;
    x=0;
    for(i=0;i<n+k;i++){
        if(idchange==obj[i].getId()){
            obj[i].output();
    cout<<"                                                                        Delete succed....!"<<endl;
           for(j=i;j<n+k;j++){
            obj[j]=obj[j+1];
            n--;  
           x=1;  
           }
                      
        }
    }
    if(x==0){
    cout<<"                                                                       Delete Unsucced....!"<<endl;
    }
    break;
    case 5:
    cout<<"============================================================================Update Student========================================================================="<<endl;
    cout<<"Enter ID = ";
    cin>>idchange;
    x=0;
    for(i=0;i<n+k;i++){
        if(idchange==obj[i].getId()){
            obj[i].input();
    cout<<"                                                                       Update succed....!"<<endl;   
    x=1;  
    }  
    }               
    if(x==0){
    cout<<"                                                                      Update Unsucced....!"<<endl;
    }
    break;
    case 6:
    do{
    cout<<"==============================================================================Sort Student========================================================================="<<endl;
    cout<<"1.Sort Name(A-z)"<<endl;
    cout<<"2.Sort Grade"<<endl;
    cout<<"3.Back"<<endl;
    cout<<"4.Exit"<<endl;
    cout<<"Enter  = ";
    cin>>sort_option;
    switch(sort_option){
    case 1:
    cout<<"==========================================================================Sort Name of Student====================================================================="<<endl;
    cout<<"||      ID       |     Name      |      Sex      |     Math      |   Physical    |     Khmer     |  Total Score  |    Average    |     Grade     |    Result     ||"<<endl;
    cout<<"==================================================================================================================================================================="<<endl;
    for(i=0;i<n+k;i++){
        for(j=i;j<n+k;j++){
            if(obj[i].getName()>obj[j].getName()){
                sorttmp=obj[i];
                obj[i]=obj[j];
                obj[j]=sorttmp;

            }
        }
    }
    for(i=0;i<n+k;i++){
        obj[i].output();
    }
       break;
    case 2:
    cout<<"==========================================================================Sort Grade of Student===================================================================="<<endl;
    cout<<"||      ID       |     Name      |      Sex      |     Math      |   Physical    |     Khmer     |  Total Score  |    Average    |     Grade     |    Result     ||"<<endl;
    cout<<"==================================================================================================================================================================="<<endl;
      for(i=0;i<n+k;i++){
        for(j=i;j<n+k;j++){
            if(obj[i].getGrade()>obj[j].getGrade()){
                sorttmp=obj[i];
                obj[i]=obj[j];
                obj[j]=sorttmp;

            }
        }
    }
    for(i=0;i<n+k;i++){
        obj[i].output();
    }
       break;
    case 3:
    goto again;
    case 4:
    exit(0);
    }
    loop_forever++;
    }while(loop_forever);
    break;
    case 7:
    cout<<"                                                                        Thank you....!\3\3\3"<<endl;
    exit(0);
    break;
    default:
    system("cls");
    cout<<"\n\n\n"<<endl;
    cout<<"Error.....! (Please Enter Options 1->7)"<<endl;
    goto again_and_again;

}
    loop_forever++;                    
    }while(loop_forever);
getch();
return 0;
}
