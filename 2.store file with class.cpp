#include <iostream>
#include <fstream>
#include <cstring>
#include <iomanip>
using namespace std;
class student {
  private:
   int id;
   char name[30];
   float average;
  public:
   student(int id=0, const char name[]="null",float average=0.0)
   : id(id),average(average)
   {
     strcpy(this->name,name);
   }
   char *getName(){
    return this->name;
   }
   int getID(){
    return this->id;
   }
   float getaverage()const {return average;}
   void print(){
     cout<<setw(12)<<left <<fixed<<setprecision(2)<<id;
     cout<<setw(12)<<left<<name;
     cout<<setw(12)<<left<<average;
   }
   friend ostream &operator<<(ostream &output, const student &obj)
   {
      output<<setw(12)<<left <<fixed<<setprecision(2)<<obj.id;
      output<<setw(12)<<left<<obj.name;
      output<<setw(12)<<left<<obj.average<<endl;
    return output;  
   }
   friend istream &operator>>(istream &input,student &obj){
     cout <<"enter student id ="; 
     input>>obj.id; 
     input.sync();
     cout <<"enter student name:";
     input.getline(obj.name,20);
     cout <<"enter student average="; 
     input>>obj.average;
        return input;     
   }
   static void header(){
    cout<<setw(12)<<left<<"ID";
    cout<<setw(12)<<left<<"NAME";
    cout<<setw(12)<<left<<"AVERAGE"<<endl;
    cout <<string(40,'-') <<endl;
   }
};
//===========================================================================

//writefile or input
void writefile(const char *filename){
  ofstream wf(filename,ios::binary|ios::out);
  student mys[200];
  int i; char c;
  int n;
  cout<<"Enter Student : ";
  cin>>n;
  for(i=0;i<n;i++){
    cin>>mys[i];
    wf.write((char *)&mys[i],sizeof(mys[i]));
  }
  wf.close();
}

//readFile or output
void readfile(const char *filename){
  ifstream rf(filename,ios::binary|ios::in);
  student mys;
  student::header();
  while(rf.read((char*)&mys,sizeof(student))){
    // rf.seekg(1*sizeof(student),ios::beg);
    cout <<mys;
  }
  cout <<string(40,'-') <<endl;
  rf.close();
}

//sizefile
long filesize(const char *filename){
  ifstream rf(filename, ios::binary|ios::in);
  if(!rf){
    cout <<"error: file not found" <<endl;
    exit(0);
  }
  rf.seekg(0,ios::end);
  long fsize=rf.tellg();
  rf.close();
  return fsize;
}

//insert student to file
void insertfile(const char *oldfilename)
{
  const string newfilename="tmpbinaryfile.bin";
  ifstream rf(oldfilename, ios::binary|ios::in);
  ofstream wf(newfilename, ios::binary|ios::out);
  int people;
  student mys[200];
  int n=filesize(oldfilename)/sizeof(int);
  student mys2;
  while(rf.read((char*)&mys2,sizeof(student))){
    wf.write((char *)&mys2,sizeof(mys2));
  }
  cout<<"Enter Student : ";
  cin>>people;
  for(int i=0;i<people;i++){
    cin>>mys[i];
    wf.write((char *)&mys[i],sizeof(mys[i]));
  }
  
  rf.close();
  wf.close();
  remove(oldfilename);
  rename(newfilename.c_str(), oldfilename);
}

//update file by name
void updatefile(const char *oldfilename){
   const string newfilename="tmpbinaryfile.bin";
  ifstream rf(oldfilename, ios::binary|ios::in);
  ofstream wf(newfilename, ios::binary|ios::out);
  string people;
  student mys[200];
  int i=0,n=0;
  student mys2;
  bool b=true;
  while(rf.read((char*)&mys2,sizeof(student))){
    mys[i]=mys2;
    i++;
    n++;
  }
  while(1){
  cout<<"Update Student"<<endl;
  cout<<"Enter Name : ";
  cin.ignore();
  cin>>people;
  for(int i=0;i<n;i++){
    if(mys[i].getName()==people){
      cin>>mys[i];
      b=false;
    }
  }
  if(b){
    system("cls");
    cout<<"Wrong Name can't access..."<<endl;
  }
  else{
    break;
  }
  }

  for(i=0;i<n;i++){
    wf.write((char *)&mys[i],sizeof(mys[i]));
  }
  rf.close();
  wf.close();
  remove(oldfilename);
  rename(newfilename.c_str(), oldfilename);
}

//delete file by name
void deletefile(const char *oldfilename){
   const string newfilename="tmpbinaryfile.bin";
  ifstream rf(oldfilename, ios::binary|ios::in);
  ofstream wf(newfilename, ios::binary|ios::out);
  string people;
  student mys[200];
  int i=0,n=0,j;
  student mys2;
  while(rf.read((char*)&mys2,sizeof(student))){
    mys[i]=mys2;
    i++;
    n++;
  }
  cout<<"Delete Student"<<endl;
  cout<<"Enter Name : ";
  cin>>people;
  for(int i=0;i<n;i++){
    if(mys[i].getName()==people){
      for(j=i;j<n;j++){
        mys[j]=mys[j+1];
      }
      n--;
    }
  }
  for(i=0;i<n;i++){
    wf.write((char *)&mys[i],sizeof(mys[i]));
  }
  rf.close();
  wf.close();
  remove(oldfilename);
  rename(newfilename.c_str(), oldfilename);
}

//Search file by name
void searchfile(const char *filename){
  ifstream rf(filename, ios::binary|ios::in);
  string people;
  student mys[200];
  int i=0,n=0,j;
  student mys2;
  while(rf.read((char*)&mys2,sizeof(student))){
    mys[i]=mys2;
    i++;
    n++;
  }
  cout<<"Search Student"<<endl;
  cout<<"Enter Name : ";
  cin>>people;
  for(int i=0;i<n;i++){
    if(mys[i].getName()==people){
      student::header();
      cout<<mys[i];
      cout <<string(40,'-') <<endl;
    }
  }
  rf.close();
}

//Sort file by ID one to N
void sortFileIdOneToN(const char *oldfilename){
  const string newfilename="tmpbinaryfile.bin";
  ifstream rf(oldfilename, ios::binary|ios::in);
  ofstream wf(newfilename, ios::binary|ios::out);
  student mys[200];
  int i=0,n=0,j;
  student mys2,temp;
  while(rf.read((char*)&mys2,sizeof(student))){
    mys[i]=mys2;
    i++;
    n++;
  }
  for(int i=0;i<n;i++){
    for(j=i;j<n;j++){
      if(mys[i].getID()>mys[j].getID()){
        temp=mys[i];
        mys[i]=mys[j];
        mys[j]=temp;
      }
    }
  }
  student::header();
  for(int i=0;i<n;i++){
  cout<<mys[i];
  wf.write((char *)&mys[i],sizeof(mys[i]));
  }
  cout <<string(40,'-') <<endl;
  rf.close();
  wf.close();
  remove(oldfilename);
  rename(newfilename.c_str(), oldfilename);
}

//Sort file by ID N to one
void sortFileIdNToOne(const char *oldfilename){
  const string newfilename="tmpbinaryfile.bin";
  ifstream rf(oldfilename, ios::binary|ios::in);
  ofstream wf(newfilename, ios::binary|ios::out);
  student mys[200];
  int i=0,n=0,j;
  student mys2,temp;
  while(rf.read((char*)&mys2,sizeof(student))){
    mys[i]=mys2;
    i++;
    n++;
  }
  for(int i=0;i<n;i++){
    for(j=i;j<n;j++){
      if(mys[i].getID()<mys[j].getID()){
        temp=mys[i];
        mys[i]=mys[j];
        mys[j]=temp;
      }
    }
  }
  student::header();
  for(int i=0;i<n;i++){
  cout<<mys[i];
  wf.write((char *)&mys[i],sizeof(mys[i]));
  }
  cout <<string(40,'-') <<endl;
  rf.close();
  wf.close();
  remove(oldfilename);
  rename(newfilename.c_str(), oldfilename);
}

//Sort file Name A to Z
void sortFileNameAtoZ(const char *oldfilename){
  const string newfilename="tmpbinaryfile.bin";
  ifstream rf(oldfilename, ios::binary|ios::in);
  ofstream wf(newfilename, ios::binary|ios::out);
  student mys[200];
  int i=0,n=0,j;
  student mys2,temp;
  while(rf.read((char*)&mys2,sizeof(student))){
    mys[i]=mys2;
    i++;
    n++;
  }
  string name1;
  string name2;
  for(int i=0;i<n;i++){
    for(j=i;j<n;j++){
      name1=mys[i].getName();
      name2=mys[j].getName();
      if(name1>name2){
        temp=mys[i];
        mys[i]=mys[j];
        mys[j]=temp;
      }
    }
  }
  student::header();
  for(int i=0;i<n;i++){
  cout<<mys[i];
  wf.write((char *)&mys[i],sizeof(mys[i]));
  }
  cout <<string(40,'-') <<endl;
  rf.close();
  wf.close();
  remove(oldfilename);
  rename(newfilename.c_str(), oldfilename);
}


//Sort file Name Z to A
void sortFileNameZtoA(const char *oldfilename){
  const string newfilename="tmpbinaryfile.bin";
  ifstream rf(oldfilename, ios::binary|ios::in);
  ofstream wf(newfilename, ios::binary|ios::out);
  student mys[200];
  int i=0,n=0,j;
  student mys2,temp;
  while(rf.read((char*)&mys2,sizeof(student))){
    mys[i]=mys2;
    i++;
    n++;
  }
  string name1;
  string name2;
  for(int i=0;i<n;i++){
    for(j=i;j<n;j++){
      name1=mys[i].getName();
      name2=mys[j].getName();
      if(name1<name2){
        temp=mys[i];
        mys[i]=mys[j];
        mys[j]=temp;
      }
    }
  }
  student::header();
  for(int i=0;i<n;i++){
  cout<<mys[i];
  wf.write((char *)&mys[i],sizeof(mys[i]));
  }
  cout <<string(40,'-') <<endl;
  rf.close();
  wf.close();
  remove(oldfilename);
  rename(newfilename.c_str(), oldfilename);
}

//Sort file by average one to N
void sortFileaverageOnetoN(const char *oldfilename){
  const string newfilename="tmpbinaryfile.bin";
  ifstream rf(oldfilename, ios::binary|ios::in);
  ofstream wf(newfilename, ios::binary|ios::out);
  student mys[200];
  int i=0,n=0,j;
  student mys2,temp;
  while(rf.read((char*)&mys2,sizeof(student))){
    mys[i]=mys2;
    i++;
    n++;
  }
  for(int i=0;i<n;i++){
    for(j=i;j<n;j++){
      if(mys[i].getaverage()>mys[j].getaverage()){
        temp=mys[i];
        mys[i]=mys[j];
        mys[j]=temp;
      }
    }
  }
  student::header();
  for(int i=0;i<n;i++){
  cout<<mys[i];
  wf.write((char *)&mys[i],sizeof(mys[i]));
  }
  cout <<string(40,'-') <<endl;
  rf.close();
  wf.close();
  remove(oldfilename);
  rename(newfilename.c_str(), oldfilename);
}

//Sort file by average N to one
void sortFileaverageNtoOne(const char *oldfilename){
  const string newfilename="tmpbinaryfile.bin";
  ifstream rf(oldfilename, ios::binary|ios::in);
  ofstream wf(newfilename, ios::binary|ios::out);
  student mys[200];
  int i=0,n=0,j;
  student mys2,temp;
  while(rf.read((char*)&mys2,sizeof(student))){
    mys[i]=mys2;
    i++;
    n++;
  }
  for(int i=0;i<n;i++){
    for(j=i;j<n;j++){
      if(mys[i].getaverage()<mys[j].getaverage()){
        temp=mys[i];
        mys[i]=mys[j];
        mys[j]=temp;
      }
    }
  }
  student::header();
  for(int i=0;i<n;i++){
  cout<<mys[i];
  wf.write((char *)&mys[i],sizeof(mys[i]));
  }
  cout <<string(40,'-') <<endl;
  rf.close();
  wf.close();
  remove(oldfilename);
  rename(newfilename.c_str(), oldfilename);
}

//High Student from file
void hightstudentfile(const char *filename){
  ifstream rf(filename, ios::binary|ios::in);
  student mys[200];
  int i=0,n=0,j;
  float max_average;
  student mys2,max_student_average;
  while(rf.read((char*)&mys2,sizeof(student))){
    mys[i]=mys2;
    i++;
    n++;
  }
  max_average=mys[0].getaverage();
  max_student_average=mys[0];
  for(i=0;i<n;i++){
    if(max_average<mys[i].getaverage()){
      max_average=mys[i].getaverage();
      max_student_average=mys[i];
    }
  }
  student::header();
  cout<<max_student_average;
  cout <<string(40,'-') <<endl;
  rf.close();
}

//Low Student from file
void lowstudentfile(const char *filename){
  ifstream rf(filename, ios::binary|ios::in);
  student mys[200];
  int i=0,n=0,j;
  float min_average;
  student mys2,min_student_average;
  while(rf.read((char*)&mys2,sizeof(student))){
    mys[i]=mys2;
    i++;
    n++;
  }
  min_average=mys[0].getaverage();
  min_student_average=mys[0];
  for(i=0;i<n;i++){
    if(min_average>mys[i].getaverage()){
      min_average=mys[i].getaverage();
      min_student_average=mys[i];
    }
  }
  student::header();
  cout<<min_student_average;
  cout <<string(40,'-') <<endl;
  rf.close();
}

//reverse
void reversefile(const char *filename){
  ifstream rf(filename,ios::binary|ios::in);
  student mys;
  student mys1[200];
  int n=0,i=0;
  while(rf.read((char*)&mys,sizeof(student))){
    mys1[i]=mys;
    n++;
    i++;
  }
  student::header();
  for(int i=n-1;i>=0;i--){
    cout<<mys1[i];
  }
  cout <<string(40,'-') <<endl;
  rf.close();
}

//count student
void countStudentfromfile(const char *filename){
  ifstream rf(filename,ios::binary|ios::in);
  student mys;
  int n=0;
  while(rf.read((char*)&mys,sizeof(student))){
    n++;
  }
  cout <<string(40,'-') <<endl;
  cout<<"Have "<<n<<" Students"<<endl;
  cout <<string(40,'-') <<endl;
  rf.close();
}

//Show Duplicate student
void showDuplicateStudentfromfile(const char *filename){
  ifstream rf(filename,ios::binary|ios::in);
  student mys;
  student mys2[200];
  int n=1,i=0,j;
  while(rf.read((char*)&mys,sizeof(student))){
    mys2[i]=mys;
    i++;
    n++;
  }
  student::header();
  string name2,name1;
  for(i=0;i<n;i++){
    for(j=i+1;j<n;j++){
         name1=mys2[i].getName();
         name2=mys2[j].getName();
      if(name1==name2){
        cout<<mys2[i];
      }
    }
  }
  cout <<string(40,'-') <<endl;
  rf.close();
}

//remove Duplicate
void removeDuplicateStudentfromfile(const char *oldfilename){
  const string newfilename="tmpbinaryfile.bin";
  ifstream rf(oldfilename, ios::binary|ios::in);
  ofstream wf(newfilename, ios::binary|ios::out);
  student mys;
  student mys2[200];
  int n=0,i=0,j,k=0;
  while(rf.read((char*)&mys,sizeof(student))){
    mys2[i]=mys;
    i++;
    n++;
  }
  string name2,name1;
  for(i=0;i<n;i++){
    for(j=i+1;j<n;){
         name1=mys2[i].getName();
         name2=mys2[j].getName();
      if(name1==name2){
        for(k=j;k<n;k++){
          mys2[k]=mys2[k+1];
          n--;
        }
      }
      else{
        j++;
      }
    }
  }
student::header();
for(i=0;i<n;i++){
cout<<mys2[i];
wf.write((char *)&mys2[i],sizeof(mys2[i]));
}
cout <<string(40,'-') <<endl;
rf.close();
wf.close();
remove(oldfilename);
rename(newfilename.c_str(), oldfilename);
}

//check file
void checkFile(const char *filename){
  ifstream rf(filename,ios::binary|ios::in);
  student mys;
  int n=filesize(filename)/sizeof(student);
  if(n!=0){
    cout<<"File : "<<"( "<<filename<<" )"<<" is using right now..."<<endl;
  }
}

//reset student from file
void resetStudentfromfile(const char *filename){
  remove(filename);
}

void menu(){
  cout <<"=====student file=======" <<endl;
  cout <<"[1]  Input student to file" <<endl;
  cout <<"[2]  Output student to file" <<endl;
  cout <<"[3]  Insert student to file " <<endl;
  cout <<"[4]  Update student to file " <<endl;
  cout <<"[5]  Delete student to file " <<endl;
  cout <<"[6]  Search student from file " <<endl;
  cout <<"[7]  Sort student from file " <<endl;
  cout <<"[8]  High Average student from file " <<endl;
  cout <<"[9]  Low Average student from file " <<endl;
  cout <<"[10] Reverse student from file " <<endl;
  cout <<"[11] Count Student from file " <<endl;
  cout <<"[12] Show Duplicate student from file " <<endl;
  cout <<"[13] Remove Duplicate student from file " <<endl;
  cout <<"[14] Check file " <<endl;
  cout <<"[15] Reset Data in file " <<endl;
  cout <<"[16] exit " <<endl;
  cout <<"========================" <<endl;
  
}
void menuSort(){
  cout <<"=====Sort student file=======" <<endl;
  cout <<"[1]  Sort ID students (1 to N)" <<endl;
  cout <<"[2]  Sort ID students (N to 1)" <<endl;
  cout <<"[3]  Sort Name students (A-Z) " <<endl;
  cout <<"[4]  Sort Name students (Z-A)" <<endl;
  cout <<"[5]  Sort Average students (1 to N)" <<endl;
  cout <<"[6]  Sort Average students (N to 1)" <<endl;
  cout <<"[7]  Back" <<endl;
  cout <<"[8]  Exit" <<endl;
  cout <<"========================" <<endl;
  
}
int main()
{  const char *filename="mystudent.bin";
  int key;
while(1){
   menu(); 
   cout <<"select : ";
   cin>>key;
   switch(key){
    case 1:
      writefile(filename);
    break;
    case 2:
      readfile(filename);
    break;
    case 3:
      insertfile(filename);
    break;
    case 4:
      updatefile(filename);
    break;
    case 5:
      deletefile(filename);
    break;
    case 6:
      searchfile(filename);
    break;
    case 7:
    do{
      menuSort();
      cout <<"select : ";
      cin>>key;
          switch(key){
            case 1:
              sortFileIdOneToN(filename);
            break;
            case 2:
              sortFileIdNToOne(filename);
            break;
            case 3:
              sortFileNameAtoZ(filename);
            break;
            case 4:
              sortFileNameZtoA(filename);
            break;
            case 5:
              sortFileaverageOnetoN(filename);
            break;
            case 6:
              sortFileaverageNtoOne(filename);
            break;
            case 7:
            break;
            case 8:
              exit(0);
            break;
            default:
            system("cls");
            cout<<"Pel Enter merl Option pg bro..."<<endl;
            break;
          }
    }while(key!=7);
    break;
    case 8:
      hightstudentfile(filename);
    break;
    case 9:
      lowstudentfile(filename);
    break;
    case 10:
      reversefile(filename);
    break;
    case 11:
      countStudentfromfile(filename);
    break;
    case 12:
      showDuplicateStudentfromfile(filename);
    break;
    case 13:
      removeDuplicateStudentfromfile(filename);
    break;
    case 14:
      checkFile(filename);
    break;
    case 15:
      resetStudentfromfile(filename);
    break;
    case 16:
      exit(0);
      default:
      system("cls");
      cout<<"Pel Enter merl Option pg bro..."<<endl;
      break;
   }
}
  return 0;
}