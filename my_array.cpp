#include"my_array.hpp"
#include<string>

void test1()
{
    my_array<int>p(5);
    my_array<int>q(5);

    for (int i = 0; i < 5; i++)
    {
        q.push_back(1);
    }
    
    my_array<int>n(q);


    n = q;

    for (int i = 0; i < 5; i++)
    {
        cout << n[i] <<" ";
    }
    cout << endl;
    n.pop_out();
    cout << n.r_capacity() << endl;
    cout << n.r_size() << endl;
}

class person
{
public:
    int age;
    string name;

    person(int mage = 0, string mname = " "):age(mage),name(mname){}
    ~person(){}
};


void test2()
{


    my_array<person>person_array(100);

    person a(1,"a");
    person b(2,"b");
    person c(3,"c");

    person_array.push_back(a);
    person_array.push_back(b);     
    person_array.push_back(c);

    for (int i = 0; i < person_array.r_size(); i++)
    {
        cout << person_array[i].age << " " << person_array[i].name <<" "<< endl;
    }
    cout << person_array.r_capacity() << " " << person_array.r_size() << endl;

}

int main()
{
    //test1();  
    test2();
    return 0;
}
