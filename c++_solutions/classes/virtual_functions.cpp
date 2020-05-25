class Person{
    public:
    string name;
    int age;
    virtual void getdata(){
      cin>>name>>age;
  }
  virtual void putdata(){
      cout<<name<<" "<<age;
  }
};
class Professor:public Person{
        public:
    Professor(){
            this->cur_id=++id;
        }
    static int id;    
    int publications;
    int cur_id;
    void getdata(){
        cin>>name>>age>>publications;
    }
    void putdata(){
        cout<<name<<" "<<age<<" "<<publications<<" "<<cur_id<<endl;
    }
};
int Professor::id=0;
class Student:public Person{
    public:
        Student(){
            this->cur_id=++id;
        }
     int marks[6];
     int cur_id;
     static int id;   
    void getdata(){
        cin>>name>>age;
        for(int i=0;i<6;i++){
            cin>>marks[i];
        } 
    }
    void putdata(){
        int sum=0;
        for(int i=0;i<6;i++){
            sum=sum+marks[i];
        }
        cout<<name<<" "<<age<<" "<<sum<<" "<<cur_id<<endl;
    }
};
int Student::id=0;